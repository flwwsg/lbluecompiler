/* ------------------------------------------------------------------------
 *description:	header file for performing step c.
 * date:				Sat Apr 18 09:57:34 CST 2015
 * version:		0.3
 * author:			DJW
 * compiler:		g++4.8
 * editor:			kate 3.14.6, tabwidth = 4
 * revision:		Sat Apr 18 09:57:34 CST 2015, originally written (no 
 *						error handling)
 *						
 * 						Sun Apr 19 19:31:18 CST 2015 , supporting sw.
 * 						Mon Apr 20 00:05:29 CST 2015, adding terminator.
 * ---------------------------------------------------------------------
 */
//finding register , if found, return 0, or return -1;
#ifndef hh
#define hh

#include "pplbcp.h"

int inline find_rdst (istringstream& iss, string& reg, char terminator);

//finding immediate number, if found, return 0, or return -1;
int  inline find_imm3 (istringstream& iss, string& imm, char terminator);

int inline find_imm4 (istringstream& iss, string& imm, char terminator);

int  handling_lsw(classkw& slsw);
int  handling_itp(classkw& itpins);
int  handling_rtp(classkw& rtpins);
int  handling_rtp(classkw& rtpins, const string& ss);
int  handling_pause(classkw& rtpins);
int  handling_jmp(classkw& jtpins);
#endif