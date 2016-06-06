//testing file for process.cxx

#include"../headers/plbcp.h"

int plbcp (vector<string>& ssp, vector<string>& ssins, ostream& ofs)
{
	vector<spins> kwtbl;
	vector<spins>sppins;
	vector<pins>ppins;
	vector<rdst> regtbl;
// 	vector<string> ssins;
	
	init_acode_tbl(kwtbl);
	init_rdst_tbl(regtbl);
	
	setacode(ssp, kwtbl, sppins) ;
	reading_ins(sppins, ppins);
	
	replacing_ins(regtbl, ppins);
	
	storing_ins(ssins, ppins);
	
	if(!ofs)
		return -1;
	
	writing_ins(ssins,  ofs);
	return 0;
}
