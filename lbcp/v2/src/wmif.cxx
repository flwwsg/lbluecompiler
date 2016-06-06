/*
 * ----------------------------------------------------------------------
 * description:	This is a part of simple compiler for LBlue processor
 *						which performing writing file *.mif .
 * 
 * 					step a writing comments to *.mif
 * 					step a writing width , depth, 
 * 							  address_radix, data_radix		
 * 					step a writing content 
 * 								begin
 * 								end;
 * 					step a 
 * 					step a 
 * 					step a 
 * 					step a 
 * 					
 * date:			Wed Apr 22 14:05:12 CST 2015
 * 
 * version:	0.1
 * author:			DJW
 * compiler:		g++4.8
 * editor:			kate 3.14.6, tabwidth = 4
 *revison:
 * 
 * --------------------------------------------------------------------
 */

#include"../headers/wmif.h"

int wmif(vector<string>& cmm, vector<string>& para, 
		 vector<string>& ctents,
		 ostream& oss)
{
	wcomment(cmm, oss);
	wothers(para, oss);
	wctents(ctents, oss);
	
	return 0;
}

