/*------------------------------------------------------------------------
 *description:	This is a simple compiler for LBlue processor.
 *						define class 
 * date:				Sat Apr 18 09:57:34 CST 2015
 *	 
 * version:		0.3
 * 
 * author:			DJW
 * 
 * revision:		Sat Apr 18 09:57:34 CST 2015, originally written
 * 						Sun Apr 19 19:31:18 CST 2015, supporting sw.
 * 						Mon Apr 20 00:05:29 CST 2015, adding terminator.
 *
 * ---------------------------------------------------------------------
 */

#ifndef lbh
#define lbh
#include "std_lb.h"

//keyword class
struct  classkw{
		enum acode{
		lw = 0, sw, beq, bne, jmp, add, sub, 
		lband, lbor, lbxor, lbnor, slt, 
		addi, andi, ori, xori, slti, pause,
		lbnot, neg, subi, mov,undef	
	};
	
	classkw();
	classkw(string& s1 , string& s2,  acode ac,  int n);
	classkw(const string& s1 ,const  string& s2,  acode ac,  int const  n);
	
	string kw;
	string hex;
	acode tp;
	int nimm;
};

///helper function
void init_kwtbl (vector<classkw>& vkw);

//step a
void reading_ppins(vector<classkw>& sins, ifstream& ifs);

//step b
int  find_kw(string  ss, vector<classkw>& vkwtbl);
void set_flag (vector<classkw>& vkw,  vector<classkw>& vkwtbl);

//step c
void handling_ins(vector<classkw>& vkw);


void pplbcp(vector<string>& ppins);

#endif