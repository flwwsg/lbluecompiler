/* ------------------------------------------------------------------------
 *description:	source file for header file handling.h performing step c.
 * date:				Sat Apr 18 09:57:34 CST 2015
 * version:		0.3
 * author:			DJW
 * compiler:		g++4.8
 * editor:			kate 3.14.6, tabwidth = 4
 * revision:		Sat Apr 18 09:57:34 CST 2015, originally written (no 
 *						error handling)
 *						
 * 						Sun Apr 19 19:31:18 CST 2015 , 
supporting sw.
 * 						Mon Apr 20 00:05:29 CST 2015, 
adding terminator.
 * ---------------------------------------------------------------------
 */
#include "../headers/std_lb.h"
#include "../headers/handling.h"

int inline find_rdst (istringstream& iss, string& reg, char terminator)
{
	char rr, n1, n2, n3;
	iss>>rr>>n1>>n2>>n3;         //r14, or r0,
	if((rr == 'r') & (n2 == terminator)){
		reg  = {rr, n1};
		iss.unget();
		return 0;
	}
	else if(n3 == terminator){
		reg  = {rr, n1, n2};
		return 0;
	}
	else
		return -1;
}

//finding immediate number, if found, return 0, or return -1;
int  inline find_imm3 (istringstream& iss, string& imm, char terminator)
{
	char n1, n2, n3, t;
		iss>>n1>>n2>>n3>>t;
		if(t != terminator)
			return -1;
		imm = {n1, n2, n3};
		return 0;
}

int inline find_imm4 (istringstream& iss, string& imm, char terminator)
{
	char n1, n2, n3, n4, t;
		iss>>n1>>n2>>n3>>n4>>t;
		if(t != terminator)
			return -1;
		imm = {n1, n2, n3, n4};
		return 0 ;
}