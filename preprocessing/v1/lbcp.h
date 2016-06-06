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

//keyword class
struct  classkw{
		enum acode{
		lw = 0, sw, beq, bne, jmp, add, sub, 
		lband, lbor, lbxor, lbnor, slt, 
		addi, andi, ori, xori, slti, pause,
		lbnot, neg, subi, undef	
	};
	
	classkw();
	classkw(string& s1 ,  acode ac);
	classkw(const string& s1 ,  acode ac);
	
	string kw;
	acode tp;
};

//instruction class
// class ppins{
// public:
// 	enum ins_field{
// 		op = 0, rd, rs, rt, imm
// 	};
// // 	
// 	enum acode{
// 		lw = 0, sw, beq, bne, jmp, add, sub, 
// 		lband, lbor, lbxor, lbnor, slt, 
// 		addi, andi, ori, xori, slti, pause
// 		lbnot, neg, subi		
// 	};
// 	
// 	enum ins_type{
// 		rtp = 1, jtp, itp, stp, utp 			//rtp stands for R-type, 
// 														//jtp stands for J-type
// 														//itp stands for I-type
// 														//stp stands for S-type
// 														//utp stands for 
// 														//undefined-type
// 	};
// 	
// string operator [] (ins_field n)
// {
// 	return vppins[n];
// }
// 	void set(ins_field f1,  string& s){
// 			vins[f1] = s;
// 	}
// 	void set(ins_type t1){
// 		tp = t1;
// 	}
// 	
// 	acode get_ac() const
// 	{
// 		return tp;
// 	}
// 	
// 	string get_field(ins_field f1)  const{
// 		return vins[f1];
// 	}
// 	
// 	ppins();
// 	
// 	ins(string&  op, string& rd, string& rs, string& rt,
// 		string& imm, ins_type itype);
// 	
// 	ppins(const string&  op, const  string& rd, const string& rs,
// 		const string& rt, const string& imm, const acode ac);
	
// private:
// 	vector<string> vppins;
// 	acode tp;
// };


