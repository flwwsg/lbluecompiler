//testing file for wmif.cxx
#include"../headers/wmif.h"

int main()
{
	vector<string> cmm(2);
	vector<string>para(4);
	vector<string>ctents(5);
	
cmm[0]="This file used for initializating instruction cacche of LBlue.";
cmm[1]="The lblue compiler generated Memory Initialization File (.mif)";
	
	para[0]="32";
	para[1]="1024";
	para[2]="HEX";
	para[3]="HEX";
	
	ctents[0] = "1";
	ctents[1] = "2";
	ctents[2] = "3";
	ctents[3] = "4";
	ctents[4] = "the end";
	
	string fn ("icch.mif");
	ofstream oss (fn.c_str());
	
	if(!oss)
		error("No such file named ", fn);
	
	int res = 0;
	res = wmif(cmm, para, ctents, oss);
	if(res)
		return 1;
	
	return 0;
}