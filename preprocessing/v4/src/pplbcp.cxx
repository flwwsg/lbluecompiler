/* ------------------------------------------------------------------------
 *description:	source file for header file handling.h performing step c.
 * date:				Mon Apr 20 14:49:39 CST 2015
 * version:		0.3
 * author:			DJW
 * compiler:		g++4.8
 * editor:			kate 3.14.6, tabwidth = 4
 * revision:		Mon Apr 20 14:49:39 CST 2015
 *						 originally written (no error handling)
 * ---------------------------------------------------------------------
 */
#include"../headers/pplbcp.h"
// #include "lbcp.cxx"

inline void print_vector (vector<classkw>& vprint)
{
	for(int i = 0; i < vprint.size(); ++i)
		cout<<vprint[i].kw<<"\ntype:"<<vprint[i].tp<<endl;
}

int pplbcp(istream& ppis, vector<string>& ppins)
{
	vector<classkw> vtmpins;
	vector<classkw>kwtbl;
	
	init_kwtbl(kwtbl);
	
	cout<<"Testing reading_ins\n";
	reading_ppins(vtmpins, ppis);
	cout<<"Raw contents of vtmpins"<<endl;
	print_vector(vtmpins);
	
	set_flag (vtmpins, kwtbl);
	cout<<"Modified contents of vtmpins\n";
	print_vector(vtmpins);

	handling_ins(vtmpins);
	
			
	for(int i = 0; i < vtmpins.size(); ++i){
		ppins.push_back(vtmpins[i].kw);
	}
	
	cout<<"preprocessed code\n";
	for(int i = 0; i < ppins.size(); ++i){
		cout<<ppins[i]<<endl;
	}
	return 0;
}