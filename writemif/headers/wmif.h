/*
 * ----------------------------------------------------------------------
 * description:	This is a simple header file for performing writing file *.mif 
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

#include"../headers/header_lb.h"
// struct hexctent{
// 	string ss;
// 	string hex;
// };
void wcomment(vector<string>& cmm, ostream& oss);
void wothers(vector<string>& others, ostream& oss);
void wctents(vector<string>&ctents, ostream& oss);
int wmif(vector<string>& cmm, vector<string>& para, 
		 vector<string>& ctents,
		 ostream& oss);


