/* ------------------------------------------------------------------------
 *description:	This is a part of simple compiler for LBlue processor, which
 * 						performing step c.
 * 
 * 						c.	handling instructions like ins r1, r2, r3;
 * 
 * date:				Sat Apr 18 09:57:34 CST 2015
 * version:		0.2
 * author:			DJW
 * compiler:		g++4.8
 * editor:			kate 3.14.6, tabwidth = 4
 * revision:		Sun Apr 19 21:25:35 CST 2015 originally written (no 
 *						error handling)
 * ---------------------------------------------------------------------
 */
#include"handling.h"

int  handling_rtp(classkw& itpins)
{
	string op, r1, r2, imm;
	string tmp;
	int res = 0;
	char sharp;
	
	istringstream iss(itpins.kw);
	
	//op
	iss>>op;
	op = itpins.hex;
	
	//r1
	res  = find_rdst(iss, r1, ',');
	if(res)
		return -1;

	//r2	
	res  = find_rdst(iss, r2, ',');
	if(res)
		return -1;
	
	iss>>sharp;
	if(sharp == '#'){
		if(itpins.nimm == 3){
			find_imm3(iss, imm);
			itpins.kw = op + " "+r1+" "+ r2 + " " + imm;
			return 0;
		}
		else{
			find_imm4(iss, imm);
			itpins.kw = op + " "+r1+" "+r2+" "+ imm;
			return 0;
		}
	}
	else
		return -1;
	
}
