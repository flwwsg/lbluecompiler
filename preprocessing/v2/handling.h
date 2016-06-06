/* ------------------------------------------------------------------------
 *description:	header file for performing step c.
 * date:				Sat Apr 18 09:57:34 CST 2015
 * version:		0.2
 * author:			DJW
 * compiler:		g++4.8
 * editor:			kate 3.14.6, tabwidth = 4
 * revision:		Sat Apr 18 09:57:34 CST 2015, originally written (no 
 *						error handling)
 *						
 * 						Sun Apr 19 19:31:18 CST 2015 , 
supporting sw.
 * ---------------------------------------------------------------------
 */
//finding register , if found, return 0, or return -1;
#ifndef hh
#define hh
int inline find_rdst (istringstream& iss, string& reg, char terminor)
{
	char rr, n1, n2, n3;
	iss>>rr>>n1>>n2>>n3;         //r14, or r0,
	if((rr == 'r') & (n2 == terminor)){
		reg  = {rr, n1};
		iss.unget();
		return 0;
	}
	else if(n3 == terminor){
		reg  = {rr, n1, n2};
		return 0;
	}
	else
		return -1;
}

//finding immediate number, if found, return 0, or return -1;
void inline find_imm3 (istringstream& iss, string& imm)
{
	char n1, n2, n3;
		iss>>n1>>n2>>n3;
		imm = {n1, n2, n3};
		return ;
}

void inline find_imm4 (istringstream& iss, string& imm)
{
	char n1, n2, n3, n4;
		iss>>n1>>n2>>n3>>n4;
		imm = {n1, n2, n3, n4};
		return ;
}
#endif