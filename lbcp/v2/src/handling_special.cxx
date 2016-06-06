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
 * 						Wed May 13 18:17:34 CST 2015,
 * 						supporting pause rs, rt, #imm 
 * ---------------------------------------------------------------------
 */
#include "../headers/pplbcp.h"

int  handling_special(classkw& stpins)
{
	string op, r1, r2, imm;
	char com1, scon, charp ;
	
	istringstream iss(stpins.kw);
	
	iss>>op>>r1>>com1>>r2>>scon;
	
	if(!iss && r1 == ";"){
			if(op != "pause"){
				stpins.kw = stpins.hex + " "+ "r0" +" "+ "r0";
				return 0;
			}
			else{
				stpins.kw = stpins.hex + " "+ "r0" +" "+ "r0" + " 000";
				return 0;
			}
		}
		
		else if(!iss)
		return -1;
		
	switch(stpins.tp){
		case classkw::pause:
											{
												iss>>charp>>imm>>scon;
												if(!iss)
													imm = "000";
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
	
	if(op != "F0"){
		stpins.kw = op + " "+r1+ " " + r2 + " " + imm;
		return 0;
	}
	
	switch (imm.size()){
		case 0:
		case 3:
								{
							stpins.kw = op + " "+r1+ " " + r2 + " " + imm;
							return 0;
							break;
								}
		case 2:
								{
							stpins.kw = op + " "+r1+ " " + r2 + " 0" + imm;
							return 0;
							break;
								}
								
		case 1:
								{
							stpins.kw = op + " "+r1+ " " + r2 + " 00" + imm;
							return 0;
							break;
								}
		default:
								{
									return -1;
									break;
								}
	}
	
	return -1;
} 
