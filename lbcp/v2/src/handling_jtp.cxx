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

int  handling_jtp(classkw& jtpins)
{
	string op, imm,tmp;
	char sharp, scon, sp('0');
	
	istringstream iss(jtpins.kw);
	
	//op
	iss>>op>>sharp>>tmp>>scon;
	if(!iss)
		return -1;
	
	op = jtpins.hex;
	
	switch(tmp.size()){
		case 0:
						{
							return -1;
							break;
						}
		case 1:
						{
							imm += {sp,sp};
							imm += tmp;
							break;
						}
						
		case 2:
						{
							imm += {sp};
							imm += tmp;
							break;
						}
						
		case 3:
						{
							imm = tmp;
							break;
						}
						
		default:
						{
							return -1;
							break;
						}
	}
	
		jtpins.kw = op +" " + "r0"+" "+ "r0"+ " "+ imm;
	return 0;
} 
