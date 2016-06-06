/*------------------------------------------------------------------------
 *description:	This is a simple program for testing compiler 
 * 						which designed for LBlue processor.
 *
 * date:				Sat Apr 18 09:57:34 CST 2015
 *	 
 * author:			DJW
 * 
 * revision:		Sat Apr 18 09:57:34 CST 2015, originally written
 * ---------------------------------------------------------------------
 */
#include"lbcp.cxx"

int main()
{
	vector<classkw> vtmpins;
	vector<classkw>kwtbl;
	vector<string>sins;
	
	init_kwtbl(kwtbl);
	
	string fname = "tmpins";
	
	cout<<"Testing reading_ins\n";
	ifstream ifs (fname.c_str());
	
	reading_ppins(vtmpins, ifs);
	
	cout<<"Raw contents of vtmpins"<<endl;
// 	for(int i = 0; i < vtmpins.size(); ++i)
// 		cout<<vtmpins[i].kw<<"\ntype:"<<vtmpins[i].tp<<endl;
	
	set_flag (vtmpins, kwtbl);
	
	cout<<"Modified contents of vtmpins\n";
// 	for(int i = 0; i < vtmpins.size(); ++i)
// 		cout<<vtmpins[i].kw<<"\ntype:"<<vtmpins[i].tp<<endl;

	handling_ins(vtmpins, sins);
	
	cout<<"preprocessed code\n";
	for(int i = 0; i < sins.size(); ++i)
		cout<<sins[i]<<endl;
			
	return 0;
}