/* ------------------------------------------------------------------------
 *description:	source file for header file handling.h performing step c.
 * date:				Mon Apr 20 14:49:39 CST 2015
 * version:		0.3
 * author:			DJW
 * compiler:		g++4.8
 * editor:			kate 3.14.6, tabwidth = 4
 * revision:		Mon Apr 20 14:49:39 CST 2015
 *						 originally written (no error handling)
 * 
 *						 Wed Apr 22 13:53:20 CST 2015, release.
 * ---------------------------------------------------------------------
 */
#include"../headers/pplbcp.h"


int pplbcp(istream& ppis, vector<string>& ppins)
{
	vector<classkw> vtmpins;
	vector<classkw>kwtbl;
	
	init_kwtbl(kwtbl);
	
	reading_ppins(vtmpins, ppis);
	
	set_flag (vtmpins, kwtbl);

	handling_ins(vtmpins);
	
	for(int i = 0; i < vtmpins.size(); ++i){
		ppins.push_back(vtmpins[i].kw);
	}
	
	return 0;
}