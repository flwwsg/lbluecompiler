/* ------------------------------------------------------------------------
 *description:	This is a part of simple compiler for LBlue processor, which
 * 						performing step c.
 * 
 * 						c.	handling instructions pause;
 * 
 * date:				Sat Apr 18 09:57:34 CST 2015
 * version:		0.3
 * author:			DJW
 * compiler:		g++4.8
 * editor:			kate 3.14.6, tabwidth = 4
 * revision:		Sun Apr 19 21:25:35 CST 2015 originally written (no 
 *						error handling)
 *						Mon Apr 20 10:03:14 CST 2015
 * ---------------------------------------------------------------------
 */
#include "../headers/handling.h"
#include"handling.cxx"

int  handling_pause(classkw& rtpins)
{
	string op, r1, r2;
	int res = 0;
	char tmp;
	
	istringstream iss(rtpins.kw);
	
	//op
	iss>>op;
	op = rtpins.hex;
	
	iss>>tmp;
	if(tmp !=';'){
	iss.unget();	
	//r1
	res  = find_rdst(iss, r1, ',');
	if(res)
		return -1;

	//r2	
	res  = find_rdst(iss, r2, ';');
	if(res)
		return -1;
	}
	else{
		r1 = "r0";
		r2 = "r0";
	}
		
		rtpins.kw = op +" " + r1+ " " + r2 ;
	return 0;
} 
