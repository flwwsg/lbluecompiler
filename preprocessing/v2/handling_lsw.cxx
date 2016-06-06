/* ------------------------------------------------------------------------
 *description:	This is a part of simple compiler for LBlue processor, which
 * 						performing step c.
 * 						c.	handling lw and sw instruction.
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
 */
#include"handling.h"

int  handling_lsw(classkw& slsw)
{
	string op, r1, r2, imm;
	string tmp;
	int res = 0;
	char sharp;
	
	istringstream iss(slsw.kw);
	
	//op
	iss>>op;
	op = slsw.hex;
	
	//r1
	res  = find_rdst(iss, r1, ',');
	if(res)
		return -1;
	
	iss>>sharp;
	
	if(sharp == '#'){
		 find_imm3(iss, imm);
		slsw.kw = op + " "+r1+" "+"r0"+" "+imm;
			return 0;
	}
	
	//r2
	else	if(sharp == 'r'){
		iss.unget();
		res = find_rdst(iss, r2, '(');
		if(res)
			return -1;
	}
	else
		return -1;
	
	 find_imm3(iss, imm);
	
	iss>>sharp;
	if(sharp == ')'){
		slsw.kw  =  op+' '+r1+' '+r2+ ' ' + imm;
		return 0;
	}
	else
		return -1;
}
