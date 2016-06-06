/*--------------------------------------------------
 * std_lb.h 
 * description:	simple header file for providing the most common standard 
 *						headers.
 *date :				Sat Apr 18 09:57:34 CST 2015
 * 
 * author: 		DJW
 * 
 * revison:		Sat Apr 18 09:57:34 CST 2015, originally written.
 * ------------------------------------------------------------------
 */


#ifndef stdlb
#define stdlb

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<cstdlib>
#include<stdexcept>
#include<ios>
#include<iomanip>  //for manipulators that taking arguments
using namespace std;

//simple error to terminal program.
inline void error(const string& s)
{
	throw runtime_error(s);
}

inline void error(const string& s1, string& s2)
{
	throw runtime_error(s1 + s2);
}


inline void error(const string& s, int i)
{
  ostringstream os;
  os << s <<": " << i;
  error(os.str());
}
#endif 