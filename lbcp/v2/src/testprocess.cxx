//testing file for process.cxx

#include"../headers/pplbcp.h"
#include"../headers/plbcp.h"
#include"../headers/wmif.h"

int main(int argc, char* argv[])
{
	vector<string>ts ;
	vector<string>vss ;
	vector<string> cmm(2);
	vector<string>para(4);
	int res = 0;
	
cmm[0]="This file used for initializating instruction cacche of LBlue.";
cmm[1]="The lblue compiler generated Memory Initialization File (.mif)";
	
	para[0]="32";
	para[1]="1024";
	para[2]="HEX";
	para[3]="HEX";
	
	
	string fname ;
	
	if(argc == 2){
	  fname = argv[1];
	}
	else{
	  cout<<"Please input source file:";
	  cin>>fname;
	}

	cout<<"Testing file "<<fname<<endl;
	
	ifstream ppifs (fname.c_str());
	if(!ppifs)
		error("no such file named ", fname);
	
	res = pplbcp(ppifs, ts);  //preprocessing
	if(res)
		error("Assembling failed!\n");
	
// 	cout<<"Now entering the file name you want to store processed text file:";
// 	cin>>fname;
	fname = "tmp.hex";
	ofstream ofs1 (fname.c_str());
	if(!ofs1)
		error("Can't write ", fname);
	
	res = plbcp(ts, vss, ofs1);
	if(res)
		return 1;
	
// 	cout<<"Now entering the file name where  you want to store mif code:";
// 	cin>>fname;
	fname = "icch.mif";
	ofstream ofs2 (fname.c_str());
	if(!ofs2)
		error("Can't write ", fname);
	
	res = wmif(cmm, para, vss, ofs2);
	if(res)
		return 1;
	
	
	return 0;
}