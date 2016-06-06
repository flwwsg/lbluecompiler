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
 *						 Wed Apr 22 13:53:20 CST 2015, release.
 * ---------------------------------------------------------------------
 */
#include "../headers/pplbcp.h"

int  handling_special(classkw& stpins)
{
	string op, r1, r2, imm;
	char com1, scon ;
	
	istringstream iss(stpins.kw);
	
	iss>>op>>r1>>com1>>r2>>scon;
	if(!iss ){
		if(r1 == ";"){
			stpins.kw = stpins.hex + " "+ "r0" +" "+ "r0";
			return 0;
		}
		return -1;
	}
		
	switch(stpins.tp){
		case classkw::pause:
											{
												imm = "";
												break;
											}
		case classkw::lbnot:
											{
												imm = "FFFF";
												break;
											}
		case classkw::mov:
											{
												imm = "r0";
												break;
											}
		case classkw::neg:
											{
				stpins.kw = stpins.hex + " " +r1 +" " +"r0" + " "+r2;
												return 0;
												break;
											}
	}
	
	op = stpins.hex;
	stpins.kw = op + " "+r1+ " " + r2 + " " + imm;
	return 0;
} 
