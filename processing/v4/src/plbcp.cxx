//testing file for process.cxx

#include"../headers/plbcp.h"

int plbcp (vector<string>& ssp, ostream& ofs)
{
	vector<spins> kwtbl;
	vector<spins>sppins;
	vector<pins>ppins;
	vector<rdst> regtbl;
	vector<string> ssins;
	
	init_acode_tbl(kwtbl);
	init_rdst_tbl(regtbl);
	
	setacode(ssp, kwtbl, sppins) ;
	reading_ins(sppins, ppins);
	
	cout<<"Raw rd, rs, rt\n";
	for(int i = 0; i < ppins.size(); ++i)
		cout<<"op-->"<<ppins[i][pins::op]<<'\t'
				<<"rd-->"<<ppins[i][pins::rd]<<'\t'
				<<"rs-->"<<ppins[i][pins::rs]<<'\t'
				<<"rt-->"<<ppins[i][pins::rt]<<'\t'
				<<"imm-->"<<ppins[i][pins::imm]<<'\t'<<endl;
				
	replacing_ins(regtbl, ppins);
	cout<<"Replaced rd, rs, rt\n";
	for(int i = 0; i < ppins.size(); ++i)
		cout<<"op-->"<<ppins[i][pins::op]<<'\t'
				<<"rd-->"<<ppins[i][pins::rd]<<'\t'
				<<"rs-->"<<ppins[i][pins::rs]<<'\t'
				<<"rt-->"<<ppins[i][pins::rt]<<'\t'
				<<"imm-->"<<ppins[i][pins::imm]<<'\t'<<endl;
	
	storing_ins(ssins, ppins);
	cout<<"Machine code \n";
	for(int i = 0; i < ssins.size(); ++i)
		cout<<ssins[i]<<endl;
	
// 	cout<<"Enter the file name you want to store processed text file:";
// 	string ss2 ;
// 	cin>>ss2;
// 	ofstream ofs (ss2.c_str());
// 	

	if(!ofs)
		return -1;
	
	writing_ins(ssins,  ofs);
	return 0;
}
