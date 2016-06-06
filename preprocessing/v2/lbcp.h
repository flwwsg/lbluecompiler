/*------------------------------------------------------------------------
 *description:	This is a simple compiler for LBlue processor.
 *						define class 
 * date:				Sat Apr 18 09:57:34 CST 2015
 *	 
 * version:		0.2
 * 
 * author:			DJW
 * 
 * revision:		Sat Apr 18 09:57:34 CST 2015, originally written
 * 						Sun Apr 19 19:31:18 CST 2015, supporting sw.
 *
 * ---------------------------------------------------------------------
 */

 
#include "std_lb.h"

//keyword class
struct  classkw{
		enum acode{
		lw = 0, sw, beq, bne, jmp, add, sub, 
		lband, lbor, lbxor, lbnor, slt, 
		addi, andi, ori, xori, slti, pause,
		lbnot, neg, subi, undef	
	};
	
	classkw();
	classkw(string& s1 , string& s2,  acode ac,  int n);
	classkw(const string& s1 ,const  string& s2,  acode ac,  int const  n);
	
	string kw;
	string hex;
	acode tp;
	int nimm;
};

//member function of classkw
//default constructor
classkw::classkw()
	:kw(""), hex("00"), tp(undef), nimm(3)
	{}
	
classkw::classkw(string& s1 , string& s2,  acode ac,  int n)
	:kw(s1), hex(s2), tp(ac), nimm(n)
	{}

classkw::classkw(const string& s1 ,const  string& s2,  acode ac,  int const n)
	:kw(s1), hex(s2), tp(ac), nimm(n)
	{}