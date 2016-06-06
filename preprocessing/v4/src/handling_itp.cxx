/* ------------------------------------------------------------------------
 *description:	This is a part of simple compiler for LBlue processor, which
 * 						performing step c.
 * 
 * 						c.	handling instructions like ins r1, r2, #imm;
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
#include "../headers/pplbcp.h"

int  handling_itp(classkw& itpins)
{
	string op, r1, r2, imm;
	string tmp;
	char sharp, com1, com2, sp = '0', scon;
	
	istringstream iss(itpins.kw);
	
	//op
	iss>>op>>r1>>com1>>r2>>com2>>sharp>>tmp>>scon;
	if(!iss | com1 != ',' | com2 != ',' | scon != ';')
		return -1;
	
	switch(tmp.size()){
		case 0:
							return -1;
		case 1:
							if(itpins.nimm == 3){
								imm += {sp, sp};
								imm += tmp;
								break;
							}
							else{
								imm += {sp, sp, sp};
								imm += tmp;
								break;
							}
		case 2:
							if(itpins.nimm == 3){
								imm += sp;
								imm += tmp;
								break;
							}
							else{
								imm += {sp, sp};
								imm += tmp;
								break;
							}
		case 3:
							{
								if(itpins.nimm == 3){
									imm = tmp;
									break;
								}
								else{
									imm += sp;
									imm += tmp;
									break;
								}
							}
		case 4:
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
		
	op = itpins.hex;
	itpins.kw = op + ' '+ r1+' '+r2+' '+imm;
	return 0;
}

int  handling_itp(classkw& itpins, int i)
{
	string op, r1, r2, imm, tmp;
	char com1, com2, scon, sharp, sp = '0';
	
	if(i)
		return -1;
	
	istringstream iss(itpins.kw);
	iss>>op>>r1>>com1;
	if(!iss)
		return -1;
	
	op = itpins.hex;
	
	iss>>sharp;
	if(sharp != '#'){
		iss.unget();
		iss>>r2>>com2>>sharp>>tmp>>scon;
	}
	else{
		iss>>tmp>>scon;
		r2 ="r0";
	}	
	
	if(!iss)
		return -1;
	switch(tmp.size()){
		case 0:
							return -1;
		case 1:
							{
								imm += {sp, sp};
								imm += tmp;
								break;
							}
		case 2:
							{
								imm += sp;
								imm += tmp;
								break;
							}
		case 3:
							{
								imm =tmp;
								break;
							}
							
		default:
							{
								return -1;
								break;
							}
	}
	
	itpins.kw = op + " "+ r1 + " "+ r2 + " "+imm;
	return 0;
}