//testing file for process.cxx

#include"../headers/process.h"

int main()
{
	vector<string> ts;
	ts.push_back("80 r1 r2 000");
	ts.push_back("81 r1 r2 100");
	ts.push_back("90 r1 r2 0E00");
	plbcp(ts);
	return 0;
}