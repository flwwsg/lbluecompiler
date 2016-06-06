/* ------------------------------------------------------------------------
 *description:	This is a part of simple compiler for LBlue processor, which
 * 						performing step c.
 * 
 * 						c.	handling instructions like ins r1, r2, r3;
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

int  handling_rtp(classkw& rtpins)
{
	string op, r1, r2, r3;
	char com1, com2, scon;
	
	istringstream iss(rtpins.kw);
	
	//op
	iss>>op>>r1>>com1>>r2>>com2>>r3>>scon;
	
	if(!iss)
		return -1;
	op = rtpins.hex;
	rtpins.kw = op + ' ' + r1 + ' ' + r2 + ' ' + r3;
	
	return 0;
} 
