/*------------------------------------------------------------------------
 *description:	This is a simple program for testing compiler 
 * 						which designed for LBlue processor.
 *
 * date:				Sat Apr 18 09:57:34 CST 2015
 *	 
 * author:			DJW
 * 
 * revision:		Sat Apr 18 09:57:34 CST 2015, originally written
 * ---------------------------------------------------------------------
 */
#include"../headers/pplbcp.h"
#include "../headers/header_lb.h"

int main()
{
	vector<string>sins;
	int res = 0;
	
	string fname("pp_test.lb");
	cout<<"Testing file "<<fname<<endl;
	
	ifstream ppifs (fname.c_str());
	if(!ppifs)
		error("no such file named ", fname);
	
	res = pplbcp(ppifs, sins);  //preprocessing
	if(res)
		error("Assembling failed!\n");
	
	return 0;
}