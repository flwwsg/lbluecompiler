/*
 * --------------------------------------------------------------
 * description:		processing machine code of preprocessed assembly code for 
 *							LBlue processor, tempalte file see preprocessed.lb.
 * date:					Sat Apr 18 19:48:10 CST 2015
 * 
 * author:				DJW
 * 
 * compiler:			g++-4.8
 * 
 * revision:			Sat Apr 18 19:48:10 CST 2015, originally writen
 * ----------------------------------------------------------
 */
#ifndef plb
#define plb

#include"header_lb.h"
//class pins for reading instruction
class pins {
public:
	enum ins_field{
		op = 0, rd, rs, rt, imm
	};
	
	enum acode{
		lw = 0, sw, beq, bne, jmp, add, sub, 
		lband, lbor, lbxor, lbnor, slt, 
		addi, andi, ori, xori, slti, pause,
		lbnot, neg, mov		// subi		
	};
	
	string operator [] (ins_field n) const
	{
		return vpins[n];
	}

	acode get_ac() const 
	{
		return tp;
	}
	
	void set_acode(acode ac)
	{	tp = ac;}
	
	void set_field(ins_field ff, const string ss)
	{	vpins[ff] = ss; }
	
	pins(string&  op, string& rd, string& rs, string& rt,
		string& imm, acode ac);
	
private:
	vector<string> vpins;
	acode tp;
};

//struct spins for storing instruction.
struct spins{
	
	spins(string& ss, pins::acode aa);
	spins(const string& ss, pins::acode aa);
	
	string sp;
	pins::acode tp;
};

struct rdst {
	rdst(const string& r1, const string& h1);
	string rr;
	string hex;
};
void init_acode_tbl (vector<spins>& sptbl);
void init_rdst_tbl(vector<rdst>& rtbl);
pins::acode find_kw (string& ss, vector<spins>& sptbl);
string find_rdst(string ss, vector<rdst>& rtbl);
void setacode (vector<string>ifs, vector<spins>& sptbl, vector<spins>& ssp);
void reading_ins(vector<spins>& spp, vector<pins>& pp);
void replacing_ins(vector<rdst>& regtbl, vector<pins>& ppins);
void storing_ins(vector<string>& ssins, vector<pins>& ppins);
void writing_ins(vector<string>& ssins, ostream& ofs);
int  plbcp (vector<string>& ssp, ostream& ofs);

#endif