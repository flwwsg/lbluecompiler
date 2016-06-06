
#include"../headers/plbcp.h"

int main()
{
	vector<string> ts;
	int res = 0;
	ts.push_back("80 r1 r2 000");
	ts.push_back("81 r1 r2 100");
	ts.push_back("90 r1 r2 0E00");
	ts.push_back("F0 r1 r2 009");
	
	cout<<"Enter the file name you want to store processed text file:";
	string ss2 ;
	cin>>ss2;
	ofstream ofs (ss2.c_str());
	
	res = plbcp(ts, ofs);
	if(res)
		return 1;
	return 0;
}