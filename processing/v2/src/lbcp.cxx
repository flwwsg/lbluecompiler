/* ------------------------------------------------------------------------
 *description:	This is a simple compiler for LBlue processor.
 *						a. reading each line from file
 * 						b. verifying each keyword
 * 						c. set ins_type.
 * 						d. specifying each reading function. 
 * 							1. op code
 * 							2. rd, rs, rt, imm
 * 						e. storing each instrucion, using vector<ins>
 * 						e. printing instructions.
 * 
 * date:				Sat Apr 18 09:57:34 CST 2015
 *	 
 * author:			DJW
 * 
 * revision:		Sat Apr 18 09:57:34 CST 2015, originally written DJW
 * ---------------------------------------------------------------------
 * 
 */
 
#include "../headers/lbcp.h"

//member function of class ins.
//default contructor
ins::ins()
{
	vins.push_back("");
	vins.push_back("");
	vins.push_back("");
	vins.push_back("");
	vins.push_back("");
	tp = utp;
}

ins::ins(string&  op, string& rd, string& rs, string& rt,
		string& imm, ins_type itype)
{
	vins.push_back(op);
	vins.push_back(rd);
	vins.push_back(rs);
	vins.push_back(rt);
	vins.push_back(imm);
	tp = itype;
}

ins::ins(const string&  op, const string& rd, const  string& rs,
		 const string& rt, const string& imm, const ins_type itype)
{
	vins.push_back(op);
	vins.push_back(rd);
	vins.push_back(rs);
	vins.push_back(rt);
	vins.push_back(imm);
	tp = itype;
}

//default constructor
keyword::keyword()
	:kw(""), hex(""), tp(utp)
	{}
	
keyword::keyword(string& s1,  string& s2,  ins_type itp1 = utp)
	:kw(s1), hex(s2),  tp(itp1)
{}

keyword::keyword(const string& s1,  const string& s2, ins_type itp1 = utp)
	:kw(s1), hex(s2), tp(itp1)
{}

//helper function 
//initial keyword table.
void init_keyword (vector<keyword>& v1)
{
	v1.push_back(*(new keyword( "lw", "80", keyword:: itp)));
	v1.push_back(*(new keyword("sw", "81", keyword:: itp)));
	v1.push_back(*(new keyword("beq", "82", keyword:: itp)));
	v1.push_back(*(new keyword("bne", "83", keyword:: itp)));
	v1.push_back(*(new keyword("jmp", "C0", keyword:: jtp)));
	v1.push_back(*(new keyword("add", "01", keyword:: rtp)));
	v1.push_back(*(new keyword("sub", "02", keyword:: rtp)));
	v1.push_back(*(new keyword("and", "10", keyword:: rtp)));
	v1.push_back(*(new keyword("or", "11", keyword:: rtp)));
	v1.push_back(*(new keyword("xor", "12", keyword:: rtp)));
	v1.push_back(*(new keyword("slt", "20", keyword:: rtp)));
	v1.push_back(*(new keyword("addi", "90", keyword:: itp)));
	v1.push_back(*(new keyword("andi", "91", keyword:: itp)));
	v1.push_back(*(new keyword("ori", "92", keyword:: itp)));
	v1.push_back(*(new keyword("xori", "93", keyword:: itp)));
	v1.push_back(*(new keyword("slti", "94", keyword:: itp)));
	v1.push_back(*(new keyword("nor", "13", keyword:: rtp)));
	v1.push_back(*(new keyword("not", "93", keyword:: itp)));
	
	v1.push_back(*(new keyword("neg", "02", keyword:: rtp)));           
														//2'scomment code
	
	v1.push_back(*(new keyword("subi", "90", keyword:: itp)));
	v1.push_back(*(new keyword("pause", "F0", keyword:: stp)));
}

//determining keyword or not, if so, return its hex code, or return "00"
string  find_kw(const string& ss, vector<keyword>& vk1)
{
	for(int i = 0; i < vk1.size(); ++i){
		if(vk1[i].kw == ss)
			return vk1[i].hex;
	}
	
	return "00";
}

int read_itp(string& s1, vector<ins>&i1)
{
	istringstream iss(s1);
	string op, rd, rs, rt, imm;
	char ch;
	char comma1, comma2, sharp, semic ;
	
	iss>>op;
	if(op == "jmp"){
		iss>>sharp;//>>imm>>semic;
		rd = "0";
		rs = "0";
		rt = "0";
		while(iss>>ch){
			if(ch != ';')
				imm += ch;
			else
				semic += ch;
		}
// 			if()
// 		}
// 		imm>>semic;
	}
	else{
		iss>>rd>>comma1>>rs>>comma2>>sharp>>imm>>semic;
		rt = "0";
	}
	
	if((semic != ';') | (sharp != '#')){
		ins i2("00", "0", "0", "0", imm, ins::utp );
		i1.push_back(i2);
		return -1;
	}
	
	ins i2(op, rd, rs, rt, imm, ins::itp);
	i1.push_back(i2);
	
	return 0;
}