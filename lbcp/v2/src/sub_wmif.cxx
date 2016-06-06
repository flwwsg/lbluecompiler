/*
 * ----------------------------------------------------------------------
 * description:	This is a part of simple compiler for LBlue processor
 *						which performing writing file *.mif .
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

//step a
void wcomment(vector<string>& cmm, ostream& oss)
{
	for(int i = 0; i < cmm.size(); ++i){
		oss<<"--"<<cmm[i]<<endl;
	}
	oss<<endl;
}

//step b
void wothers(vector<string>& others, ostream& oss)
{
	oss<<"WIDTH="<<others[0]<<';'<<endl
		<<"DEPTH="<<others[1]<<';'<<endl
		<<endl
		<<"ADDRESS_RADIX="<<others[2]<<';'<<endl
		<<"DATA_RADIX="<<others[3]<<';'<<endl
		<<endl;
}

//step c
//formatting contents of mif.
void wctents(vector<string>&ctents, ostream& oss)
{
	oss<<"CONTENT BEGIN\n"
		<<"\t000  :   00000000;"<<endl;
		
	int tmp = 0, i = 1;
	for(; i <ctents.size(); ){
		tmp = i-1;
		while(ctents[i] == ctents[tmp])
			++i;
		if(tmp == i-1){				//no repeated number;
			oss<<'\t'
				<<setw(3)<<setfill('0')<<hex<<uppercase<<i
				<<"  :   "<<ctents[tmp]<<';'<<endl;
				++i;
				continue;
		}				
		else{
			oss<<"\t["
				<<setw(3)<<setfill('0')<<hex<<uppercase<<tmp+1
				<<".."
				<<setw(3)<<setfill('0')<<hex<<uppercase<<i
				<<"]  :   "<<ctents[tmp]<<';'<<endl;
				++i;
				continue;
		}
	}
	if(i > 1024)
		error("no enough cacche!");
	else
			oss<<"\t["
				<<setw(3)<<setfill('0')<<hex<<uppercase<<i
				<<".."
				<<"3FF"
				<<"]  :   "<<"00000000"<<';'<<endl
				<<"END;";
		
}