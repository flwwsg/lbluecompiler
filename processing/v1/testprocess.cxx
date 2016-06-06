//testing file for process.cxx

#include"process.cxx"

int main()
{
	vector<spins> kwtbl;
	vector<spins>sppins;
	vector<pins>ppins;
	vector<rdst> regtbl;
	vector<string> ssins;
	
	init_acode_tbl(kwtbl);
	init_rdst_tbl(regtbl);
	
	cout<<"Please enter the testing file name "
		  <<"(preprocessed assembly code 	file)\n";
		  
	string fname;
	cin>>fname;
	ifstream ifs(fname.c_str());
	if(!ifs)
		error("no such file named ", fname );
	
	setacode(ifs, kwtbl, sppins) ;
	reading_ins(sppins, ppins);
// 	for(int i = 0; i < kwtbl.size(); ++i)
// 	cout<<kwtbl[i].sp<<'\t'<<kwtbl[i].tp<<endl;
// 	for(int i = 0; i < ins.size(); ++i)
// 	cout<<ins[i].sp<<'\t'<<ins[i].tp<<endl;
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
	
	string ss2 = "tmphex.hex";
	ofstream ofs (ss2.c_str());
	writing_ins(ssins,  ofs);
	return 0;
}