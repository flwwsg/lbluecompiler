/*
 * -----------------------------------------------------------------------
 * description:	This program used for processing machine code 
 * 						from preprocessed assembly code, for more about
 * 						preprocessed assembly code see preprocessed.lb.
 * 						
 * 						steps:
 * 						a. storing preprocessed assembly code using 
							vector<spins>, and set acode flag.
 * 						b. reading op, rd, rs, rt, using class pins
 * 						c. converting  rd, rs, rt to 0 ~ F.
 * 						d. storing machine code using vector<string>,
 *						e. writing file *.hex
 * 
 * date:				Sat Apr 18 20:16:02 CST 2015
 * 
 * author:			DJW
 * 
 * revision:		Sat Apr 18 20:16:02 CST 2015, originally written by DJW
 * --------------------------------------------------------------------
 */

#include"../headers/process.h"

//member function of pins.
pins::pins(string&  op, string& rd, string& rs, string& rt,
		string& imm, acode ac )
{
	vpins.push_back(op);
	vpins.push_back(rd);
	vpins.push_back(rs);
	vpins.push_back(rt);
	vpins.push_back(imm);
	set_acode(ac);
}


//member function of spins
//default constructor
spins::spins(string& ss, pins::acode aa)
	:sp(ss), tp(aa)
	{}

spins::spins(const string& ss, pins::acode aa)
	:sp(ss), tp(aa)
	{}
	
//member function of rdst
rdst::rdst(const string& r1, const string& h1)
{
	rr = r1;
	hex = h1;
}

//helper function

//acode table for step a.
void init_acode_tbl (vector<spins>& sptbl)
{
	sptbl.push_back(*(new spins("80", pins::lw)));
	sptbl.push_back(*(new spins("81", pins::sw)));
	sptbl.push_back(*(new spins("82", pins::beq)));
	sptbl.push_back(*(new spins("83", pins::bne)));
	sptbl.push_back(*(new spins("C0", pins::jmp)));
	sptbl.push_back(*(new spins("01", pins::add)));
	sptbl.push_back(*(new spins("02", pins::sub)));
	sptbl.push_back(*(new spins("10", pins::lband)));
	sptbl.push_back(*(new spins("11", pins::lbor)));
	sptbl.push_back(*(new spins("12", pins::lbxor)));
	sptbl.push_back(*(new spins("13", pins::lbnor)));
	sptbl.push_back(*(new spins("20", pins::slt)));
	sptbl.push_back(*(new spins("90", pins::addi)));
	sptbl.push_back(*(new spins("91", pins::andi)));
	sptbl.push_back(*(new spins("92", pins::ori)));
	sptbl.push_back(*(new spins("93", pins::xori)));
	sptbl.push_back(*(new spins("94", pins::slti)));
	sptbl.push_back(*(new spins("F0", pins::pause)));
// 	sptbl.push_back(*(new spins("93", pins::lbnot)));
// 	sptbl.push_back(*(new spins("02", pins::neg)));
// 	sptbl.push_back(*(new spins("90", pins::subi)));
}

//table for step c.
void init_rdst_tbl(vector<rdst>& rtbl)
{
	rtbl.push_back(*(new rdst("r0", "0")));
	rtbl.push_back(*(new rdst("r1", "1")));
	rtbl.push_back(*(new rdst("r2", "2")));
	rtbl.push_back(*(new rdst("r3", "3")));
	rtbl.push_back(*(new rdst("r4", "4")));
	rtbl.push_back(*(new rdst("r5", "5")));
	rtbl.push_back(*(new rdst("r6", "6")));
	rtbl.push_back(*(new rdst("r7", "7")));
	rtbl.push_back(*(new rdst("r8", "8")));
	rtbl.push_back(*(new rdst("r9", "9")));
	rtbl.push_back(*(new rdst("r10", "A")));
	rtbl.push_back(*(new rdst("r11", "B")));
	rtbl.push_back(*(new rdst("r12", "C")));
	rtbl.push_back(*(new rdst("r13", "D")));
	rtbl.push_back(*(new rdst("r14", "E")));
	rtbl.push_back(*(new rdst("r15", "F")));
}

pins::acode find_kw (string& ss, vector<spins>& sptbl)
{
	int i = 0;
	while(sptbl[i].sp != ss){
		++i;
	}
	
	return sptbl[i].tp;
		
}

 inline string find_rdst(string ss, vector<rdst>& rtbl)
{
	int i = 0;
	while (rtbl[i].rr != ss)
		++i;
	
	return rtbl[i].hex;
}

//step a
//set acode flag
void setacode (istream& ifs, vector<spins>& sptbl, vector<spins>& ssp)
{
	string s, op;
	pins::acode aa;
	
	while(getline(ifs, s)){
		istringstream iss(s);
		iss>>op;
		aa = find_kw(op, sptbl);
		
		spins tmp(s, aa);
		ssp.push_back(tmp);
	}
}

//step b
void reading_ins(vector<spins>& spp, vector<pins>& pp)
{
// 	istringstream iss;
	string op("00"), rd("0"), rs("0"), rt("0"), imm("000");
	
	for(int i = 0; i < spp.size(); ++i){
		istringstream iss(spp[i].sp);
		switch(spp[i].tp){
			case pins::lw:	
										{
											iss>>op>>rd>>rs>>imm;
											rt = "0";
											pp.push_back(*(new pins(op, rd, rs, 
														rt, imm, spp[i].tp)));   
              
											break;
										}
										
			case pins::sw:
			case pins::beq:
			case pins::bne:
			case pins::jmp:
										{
											iss>>op>>rs>>rt>>imm;
											rd = "0";
											pp.push_back(*(new pins(op, rd, rs, 
													rt, imm, spp[i].tp)));
											break;
										}
										
			case pins::add:
			case pins::sub:
			case pins::lband:
			case pins::lbor:
			case pins::lbxor:
			case pins::lbnor:
			case pins::slt:
// 			case pins::neg:								//2's comment code
										{
											iss>>op>>rd>>rs>>rt;
											imm = "000";
											pp.push_back(*(new pins(op, rd, rs, 
													rt, imm, spp[i].tp)));
											break;
										}
										
			case pins::addi:
			case pins::andi:
			case pins::ori:
			case pins::xori:
			case pins::slti:
// 			case pins::subi:
// 			case pins::lbnot:
										{
											iss>>op>>rd>>rs>>imm;
											rt = "0";
											pp.push_back(*(new pins(op, rd, rs, 
													rt, imm, spp[i].tp)));
											break;
										}
										
			case pins::pause:
										{
											iss>>op>>rs>>rt;
											rd = "0";
											imm = "000";
											pp.push_back(*(new pins(op, rd, rs, 
													rt, imm, spp[i].tp)));
											break;
										}
										
			default :
										{
											op = "00";
											rd = "0";
											rs = "0";
											rt = "0";
											imm = "000";
											pp.push_back(*(new pins(op, rd, rs, 
													rt, imm, spp[i].tp)));
											break;
										}
		}
	}
}

//step c
void replacing_ins(vector<rdst>& regtbl, vector<pins>& ppins)
{
	string ss("0");
	for(int i = 0; i < ppins.size(); ++i){
		ss= "0";
		
		if(ppins[i][pins::rd] != "0")
			ss = find_rdst(ppins[i][pins::rd], regtbl);
		ppins[i].set_field(pins::rd, ss);
		ss = "0";
		
		if(ppins[i][pins::rs] != "0")
			ss = find_rdst(ppins[i][pins::rs], regtbl);
		
		ppins[i].set_field(pins::rs, ss);
		ss = "0";
		
		if(ppins[i][pins::rt] != "0")
			ss = find_rdst(ppins[i][pins::rt], regtbl);
		ppins[i].set_field(pins::rt, ss);
	}
}

//step d

void storing_ins(vector<string>& ssins, vector<pins>& ppins)
{
	string ss;
	for(int i = 0; i < ppins.size(); ++i){
		ss = "";
		switch(ppins[i].get_ac()){
			case pins::lw:
			case pins::sw:
			case pins::beq:
			case pins::bne:
			case pins::jmp:
			//
			case pins::add:
			case pins::sub:
			case pins::lband:
			case pins::lbor:
			case pins::lbxor:
			case pins::lbnor:
			case pins::slt:
// 			case pins::neg:
			
			//
			case pins::pause:
									{
										ss +=  ppins[i][pins::op] ;
										ss +=  ppins[i][pins::rd] ;
										ss +=  ppins[i][pins::rs];
										ss +=  ppins[i][pins::rt]; 
										ss +=  ppins[i][pins::imm] ;
												
										ssins.push_back(ss);
										break;
									}
									
			case pins::addi:
// 			case pins::subi:
			case pins::andi:
			case pins::ori:
			case pins::xori:
			case pins::slti:
// 			case pins::lbnot:
									{
										ss += ppins[i][pins::op] ;
										ss	+= ppins[i][pins::rd] ;
										ss	+= ppins[i][pins::rs] ;
										ss	+= ppins[i][pins::imm] ;
												
										ssins.push_back(ss);
										break;
									}
									
			default:		
								{
									ss = "00000000";
									ssins.push_back(ss);
									break;
								}
				
		}
	}
}

//step e
void writing_ins(vector<string>& ssins, ofstream& ofs)
{
	int i = 0;
	while(i < ssins.size())
		ofs<<ssins[i++]<<endl;
	ofs.close();
}