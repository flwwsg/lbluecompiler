/* ------------------------------------------------------------------------
 *description:	This is a simple compiler for LBlue processor.
 *						a.	reading each line from file, using vector<string>.
 * 							converting upper characters to lower characters
 *						b.	set flag using class classkw 
 * 						c.	handling each type of instruction.
 * 							storing instruction with vector<string>;
 * 						d.	writing file *.lb
 * 
 * date:				Sat Apr 18 09:57:34 CST 2015
 * version:		0.2
 * author:			DJW
 * compiler:		g++4.8
 * editor:			kate 3.14.6, tabwidth = 4
 * revision:		Sat Apr 18 09:57:34 CST 2015, originally written (no 
 *						error handling)
 *						
 * 						Sun Apr 19 19:31:18 CST 2015 , supporting sw.
 * ---------------------------------------------------------------------
 * 
 */
 
#include "lbcp.h"
#include"handling_lsw.cxx"
#include"handling_itp.cxx"


//helper function 
//initial classkw table.
void init_kwtbl (vector<classkw>& vkw)
{
	vkw.push_back(*(new classkw( "lw", "80", classkw:: lw, 3)));
	vkw.push_back(*(new classkw("sw", "81", classkw:: sw, 3)));
	vkw.push_back(*(new classkw("beq", "82", classkw:: beq, 3)));
	vkw.push_back(*(new classkw("bne", "83", classkw:: bne, 3)));
	vkw.push_back(*(new classkw("jmp", "C0", classkw:: jmp, 3)));
	vkw.push_back(*(new classkw("add", "01", classkw:: add, 3)));
	vkw.push_back(*(new classkw("sub", "02", classkw:: sub, 3)));
	vkw.push_back(*(new classkw("and", "10", classkw:: lband, 3)));
	vkw.push_back(*(new classkw("or", "11", classkw:: lbor, 3)));
	vkw.push_back(*(new classkw("xor", "12", classkw::lbxor, 3)));
	vkw.push_back(*(new classkw("nor", "13", classkw:: lbnor, 3)));
	vkw.push_back(*(new classkw("slt", "20", classkw:: slt, 3)));
	vkw.push_back(*(new classkw("addi", "90", classkw:: addi, 4)));
	vkw.push_back(*(new classkw("andi", "91", classkw:: andi, 4)));
	vkw.push_back(*(new classkw("ori", "92", classkw:: ori, 4)));
	vkw.push_back(*(new classkw("xori", "93", classkw:: xori, 4)));
	vkw.push_back(*(new classkw("slti", "94", classkw:: slti, 4)));
	vkw.push_back(*(new classkw("pause", "F0", classkw:: pause, 3)));
	vkw.push_back(*(new classkw("not", "93", classkw:: lbnot, 4)));
	
	vkw.push_back(*(new classkw("neg", "02", classkw:: neg, 3)));           
														//2'scomment code
	
	vkw.push_back(*(new classkw("subi", "90", classkw:: subi,  4)));
}


//step a, reading file.
void reading_ppins(vector<classkw>& sins, ifstream& ifs)
{
	string ss, tmp, hex("00");
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
			sins.push_back(*(new classkw (tmp,  hex, classkw::undef, 3)));
		tmp = "";
	}
}

//step b, setting flag
//determining classkw or not, if so, return none -1,  or return  -1
int  find_kw(string  ss, vector<classkw>& vkwtbl)
{
	for(int i = 0; i < vkwtbl.size(); ++i){
		if(vkwtbl[i].kw == ss)
			return i;
		
	}
	
	return -1;
}

void set_flag (vector<classkw>& vkw,  vector<classkw>& vkwtbl)
{
	string tmp;
	int res = 0;
	for(int i = 0; i < vkw.size(); ++i){
		istringstream iss(vkw[i].kw);
		iss>>tmp;
		res = find_kw(tmp, vkwtbl);
		
		if(res != -1){
			vkw[i].hex = vkwtbl[res].hex;
			vkw[i].tp = vkwtbl[res].tp;
			vkw[i].nimm = vkwtbl[res].nimm;
			
		}			
		else
			error("no such instruction", vkw[i].kw);
	}
}


//step c, handling each instruction,  if done , return 0, or return -1;
void handling_ins(vector<classkw>& vkw)
{
	int res = 0;
	for(int i = 0; i < vkw.size(); ++i){
		
		switch(vkw[i].tp){
			case classkw::lw: 
			case classkw::sw: 
												{
												res  = 	handling_lsw(vkw[i]);
													break;
												}
// 			
			case classkw::beq:
			case classkw::bne:
			case classkw::addi:
			case classkw::andi:
			case classkw::ori:
			case classkw::xori:
			case classkw::slti:
												{
												res  = 	handling_itp(vkw[i]);
													break;
												}
												
			default:					
												{
													vkw[i].kw = "00000000";
													break;
												}
		}
		
		if (res)
			error("Wrong format at ", vkw[i].kw);
	}
}