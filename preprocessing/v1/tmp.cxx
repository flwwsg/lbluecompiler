//testing file
#include"std_lb.h"
// #include<std_lib_facilities.h>
class tmp{
public:
	enum ins_field{
		op = 0, rd, rs, rt, imm
	};
	
	tmp();
	vector<int>vins;
};

tmp::tmp()
{
	vins.push_back(0);
	vins.push_back(0);
	vins.push_back(0);
	vins.push_back(0);
	vins.push_back(0);
}
int main()
{
	cout<<"YES\n";
	tmp t1;
	return 0;
}