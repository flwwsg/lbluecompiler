/*------------------------------------------------------------------------
 *description:	This is a simple compiler for LBlue processor.
 *						define class 
 * date:				Sat Apr 18 09:57:34 CST 2015
 *	 
 * author:			DJW
 * 
 * revision:		Sat Apr 18 09:57:34 CST 2015, originally written
 * ---------------------------------------------------------------------
 */

 
#include "std_lb.h"

//instruction class
class ins{
public:
	enum ins_field{
		op = 0, rd, rs, rt, imm
	};
	
	enum ins_type{
		rtp = 1, jtp, itp, stp, utp 			//rtp stands for R-type, 
														//jtp stands for J-type
														//itp stands for I-type
														//stp stands for S-type
														//utp stands for 
														//undefined-type
	};
	
string operator [] (ins_field n) const
{
	return vins[n];
}
	void set(ins_field f1,  string& s){
			vins[f1] = s;
	}
	void set(ins_type t1){
		tp = t1;
	}
	
	int get_itp() const{
		return tp;
	}
	
	string get_field(ins_field f1)  const{
		return vins[f1];
	}
	
	ins();
	
	ins(string&  op, string& rd, string& rs, string& rt,
		string& imm, ins_type itype);
	
	ins(const string&  op, const  string& rd, const string& rs,
		const string& rt, const string& imm, const ins_type itype);
	
private:
	vector<string> vins;
	ins_type tp;
};

// keyword class
struct  keyword{
	
	enum ins_type{
		rtp = 1, jtp, itp, stp, utp 			//rtp stands for R-type, 
														//jtp stands for J-type
														//itp stands for I-type
														//stp stands for S-type
														//utp stands for 
														//undefined-type
	};
	
	string kw;
	string hex;
	ins_type tp;
	
	keyword();
	keyword(string& s1 , string& s2, ins_type itp1);
	keyword(const string& s1 , const string& s2,  ins_type itp1);
	
};

