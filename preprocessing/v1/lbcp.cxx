/* ------------------------------------------------------------------------
 *description:	This is a simple compiler for LBlue processor.
 *						a.	reading each line from file, using vector<string>.
 * 							converting upper characters to lower characters
 *
 *						b.	set flag using class classkw 
 * 
 * 						c.	handling each type of instruction.
 * 							for lw...
 * 							storing instruction with vector<string>;
 * 						d.	writing file *.lb
 * 
 * date:				Sat Apr 18 09:57:34 CST 2015
 *	 
 * author:			DJW
 * 
 * compiler:		g++4.8
 * 
 * editor:			kate 3.14.6
 * 
 * revision:		Sat Apr 18 09:57:34 CST 2015, originally written (no 
 *						error handling)
 * 
 * ---------------------------------------------------------------------
 * 
 */
 
#include "lbcp.h"
//member function of classkw
//default constructor
classkw::classkw()
	:kw(""), tp(undef)
	{}
	
classkw::classkw(string& s1,  acode ac)
	:kw(s1), tp(ac)
{}

classkw::classkw(const string& s1,   const acode ac)
	:kw(s1), tp(ac)
{}

//member function of class ins.
//default contructor
// ins::ins()
// {
// 	vins.push_back("");
// 	vins.push_back("");
// 	vins.push_back("");
// 	vins.push_back("");
// 	vins.push_back("");
// 	tp = utp;
// }
// 
// ins::ins(string&  op, string& rd, string& rs, string& rt,
// 		string& imm, ins_type itype)
// {
// 	vins.push_back(op);
// 	vins.push_back(rd);
// 	vins.push_back(rs);
// 	vins.push_back(rt);
// 	vins.push_back(imm);
// 	tp = itype;
// }
// 
// ins::ins(const string&  op, const string& rd, const  string& rs,
// 		 const string& rt, const string& imm, const ins_type itype)
// {
// 	vins.push_back(op);
// 	vins.push_back(rd);
// 	vins.push_back(rs);
// 	vins.push_back(rt);
// 	vins.push_back(imm);
// 	tp = itype;
// }
// 

//helper function 
//initial classkw table.
// void init_kwtbl (vector<classkw>& vkw)
// {
// 	vkw.push_back(*(new classkw( "lw", "80", classkw:: lw)));
// 	vkw.push_back(*(new classkw("sw", "81", classkw:: sw)));
// 	vkw.push_back(*(new classkw("beq", "82", classkw:: beq)));
// 	vkw.push_back(*(new classkw("bne", "83", classkw:: bne)));
// 	vkw.push_back(*(new classkw("jmp", "C0", classkw:: jmp)));
// 	vkw.push_back(*(new classkw("add", "01", classkw:: add)));
// 	vkw.push_back(*(new classkw("sub", "02", classkw:: sub)));
// 	vkw.push_back(*(new classkw("and", "10", classkw:: lband)));
// 	vkw.push_back(*(new classkw("or", "11", classkw:: lbor)));
// 	vkw.push_back(*(new classkw("xor", "12", classkw::lbxor)));
// 	vkw.push_back(*(new classkw("nor", "13", classkw:: lbnor)));
// 	vkw.push_back(*(new classkw("slt", "20", classkw:: slt)));
// 	vkw.push_back(*(new classkw("addi", "90", classkw:: addi)));
// 	vkw.push_back(*(new classkw("andi", "91", classkw:: andi)));
// 	vkw.push_back(*(new classkw("ori", "92", classkw:: ori)));
// 	vkw.push_back(*(new classkw("xori", "93", classkw:: xori)));
// 	vkw.push_back(*(new classkw("slti", "94", classkw:: slti)));
// 	vkw.push_back(*(new classkw("pause", "F0", classkw:: pause)));
// 	vkw.push_back(*(new classkw("not", "93", classkw:: lbnot)));
// 	
// 	vkw.push_back(*(new classkw("neg", "02", classkw:: neg)));           
// 														//2'scomment code
// 	
// 	vkw.push_back(*(new classkw("subi", "90", classkw:: subi)));
// }
// 
//initial classkw table.
void init_kwtbl (vector<classkw>& vkwtbl)
{
	vkwtbl.push_back(*(new classkw( "lw", classkw:: lw)));
	vkwtbl.push_back(*(new classkw("sw", classkw:: sw)));
	vkwtbl.push_back(*(new classkw("beq", classkw:: beq)));
	vkwtbl.push_back(*(new classkw("bne", classkw:: bne)));
	vkwtbl.push_back(*(new classkw("jmp", classkw:: jmp)));
	vkwtbl.push_back(*(new classkw("add", classkw:: add)));
	vkwtbl.push_back(*(new classkw("sub", classkw:: sub)));
	vkwtbl.push_back(*(new classkw("and", classkw:: lband)));
	vkwtbl.push_back(*(new classkw("or", classkw:: lbor)));
	vkwtbl.push_back(*(new classkw("xor", classkw::lbxor)));
	vkwtbl.push_back(*(new classkw("nor", classkw:: lbnor)));
	vkwtbl.push_back(*(new classkw("slt", classkw:: slt)));
	vkwtbl.push_back(*(new classkw("addi", classkw:: addi)));
	vkwtbl.push_back(*(new classkw("andi", classkw:: andi)));
	vkwtbl.push_back(*(new classkw("ori", classkw:: ori)));
	vkwtbl.push_back(*(new classkw("xori", classkw:: xori)));
	vkwtbl.push_back(*(new classkw("slti", classkw:: slti)));
	vkwtbl.push_back(*(new classkw("pause", classkw:: pause)));
	vkwtbl.push_back(*(new classkw("not", classkw:: lbnot)));
	
	vkwtbl.push_back(*(new classkw("neg", classkw:: neg)));           
														//2'scomment code
	
	vkwtbl.push_back(*(new classkw("subi", classkw:: subi)));
}
// 
// 
// int read_itp(string& s1, vector<ins>&i1)
// {
// 	istringstream iss(s1);
// 	string op, rd, rs, rt, imm;
// 	char ch;
// 	char comma1, comma2, sharp, semic ;
// 	
// 	iss>>op;
// 	if(op == "jmp"){
// 		iss>>sharp;//>>imm>>semic;
// 		rd = "0";
// 		rs = "0";
// 		rt = "0";
// 		while(iss>>ch){
// 			if(ch != ';')
// 				imm += ch;
// 			else
// 				semic += ch;
// 		}
// // 			if()
// // 		}
// // 		imm>>semic;
// 	}
// 	else{
// 		iss>>rd>>comma1>>rs>>comma2>>sharp>>imm>>semic;
// 		rt = "0";
// 	}
// 	
// 	if((semic != ';') | (sharp != '#')){
// 		ins i2("00", "0", "0", "0", imm, ins::utp );
// 		i1.push_back(i2);
// 		return -1;
// 	}
// 	
// 	ins i2(op, rd, rs, rt, imm, ins::itp);
// 	i1.push_back(i2);
// 	
// 	return 0;
//}

//step a, reading file.
void reading_ppins(vector<classkw>& sins, ifstream& ifs)
{
	string ss, tmp;
	char ch;
	while (getline(ifs, ss)){
		istringstream iss(ss);
		while(iss.get(ch)){
			 ch = tolower(ch);
			if(ch != ';')
				tmp += ch;
			else
				break;
		}
		if(tmp != "")
			sins.push_back(*(new classkw (tmp, classkw::undef)));
		tmp = "";
	}
}

//step b, setting flag
//determining classkw or not, if so, return its acode, or return undef
classkw::acode find_kw(string& ss, vector<classkw>& vkwtbl)
{
	for(int i = 0; i < vkwtbl.size(); ++i){
		if(vkwtbl[i].kw == ss)
			return vkwtbl[i].tp;
	}
	
	return classkw::undef;
}

void set_flag (vector<classkw>& vkw,  vector<classkw>& vkwtbl)
{
	classkw::acode ac;
	string tmp;
	for(int i = 0; i < vkw.size(); ++i){
		istringstream iss(vkw[i].kw);
		iss>>tmp;
		ac = find_kw(tmp, vkwtbl);
		vkw[i].tp = ac;
	}
}

//step c, handling lw,  if done , return 0, or return -1;
int  handling_lw(string slw, string& ssins)
{
	string op, rd, rs, imm;
	char comma, sharp, s9, s0;     ///s9 for '(', s0 for ')'
	char c1, n1, n2, n3;
	
	ssins = "";
	istringstream iss(slw);
	
	//op
	iss>>op;
	op = "80";
	
	//rd
	iss>>c1>>n1>>n2>>comma;         //r14, or r0,
	
	if(c1 == 'r' & n2 == ','){
		rd  = {c1, n1};
		iss.unget();
	}
	else if(comma == ',')
		rd = {c1, n1, n2};
	
	//rs
	iss>>sharp;
	
	if(sharp == '#'){
		iss>>n1>>n2>>n3;
		imm = {n1, n2, n3};
		
		ssins = op+' '+rd+' '+"r0"+ ' ' + imm;
		return 0;
	}
	else	if(sharp == 'r')
		iss>>n1>>n2>>s9;
	else
		return -1;
	
	//else error handling
	
	if(n2 == '('){
		rs = {sharp, n1};
		iss>>n2>>n3;
		imm = {s9, n2, n3};
	}
	else if(s9 == '('){
		rs = {sharp, n1, n2};
		iss>>n1>>n2>>n3;
		imm = {n1, n2, n3};
	}
	else 
		return -1;
	//else error handling
	
	//iss>>s0, if (s0 != ')'), error handling.
	
	ssins =  op+' '+rd+' '+rs+ ' ' + imm;
	return 0;
}

//step c, handling sw, if done, return 0, or return -1;
int  handling_sw(string ssw, string& ssins)
{
	string op, rd, rs, imm;
	char comma, sharp, s9, s0;     ///s9 for '(', s0 for ')'
	char c1, n1, n2, n3;
	
	ssins = "";
	istringstream iss(ssw);
	
	//op
	iss>>op;
	op = "81";
	
	//rd
	iss>>c1>>n1>>n2>>comma;         //r14, or r0,
	
	if(c1 == 'r' & n2 == ','){
		rd  = {c1, n1};
		iss.unget();
	}
	else if(comma == ',')
		rd = {c1, n1, n2};
	
	//rs
	iss>>sharp;
	
	if(sharp == '#'){
		iss>>n1>>n2>>n3;
		imm = {n1, n2, n3};
		
		ssins = op+' '+rd+' '+"r0"+ ' ' + imm;
		return 0;
	}
	else	if(sharp == 'r')
		iss>>n1>>n2>>s9;
	else
		return -1;
	
	//else error handling
	
	if(n2 == '('){
		rs = {sharp, n1};
		iss>>n2>>n3;
		imm = {s9, n2, n3};
	}
	else if(s9 == '('){
		rs = {sharp, n1, n2};
		iss>>n1>>n2>>n3;
		imm = {n1, n2, n3};
	}
	else 
		return -1;
	//else error handling
	
	//iss>>s0, if (s0 != ')'), error handling.
	
	ssins =  op+' '+rd+' '+rs+ ' ' + imm;
	return 0;
}

//step c, handling each instruction,  if done , return 0, or return -1;
void handling_ins(vector<classkw>& vkw, vector<string>& sins)
{
// 	string op, rd, rs, rt, imm;
	string tmp;
	int res = 0;
// 	char ch;
	for(int i = 0; i < vkw.size(); ++i){
		tmp = "";
		istringstream iss(vkw[i].kw);
		
		switch(vkw[i].tp){
			case classkw::lw: 
												{
										res  = 	handling_lw(vkw[i].kw, tmp);
										sins.push_back(tmp);
													break;
												}
			
			case classkw::sw: 
												{
										res  = 	handling_sw(vkw[i].kw, tmp);
										sins.push_back(tmp);
													break;
												}
			
			default:					
												{
													tmp = "00000000";
													sins.push_back(tmp);
													break;
												}
		}
	}
}