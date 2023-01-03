#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <utility>
using namespace std;


class OneRegister {
 public:
   string bla;
   void rec(int s,int t,string ops) {
     if (s == t) {
       if (bla == ":-(" || ops.size() < bla.size() || (ops.size() == bla.size() && ops < bla))
         bla = ops;
       return;
     }
     if (s < t) {
       if (s <= t/s && (s*s)/s == s && s*s > s) rec(s*s,t,ops+"*");
       if (s+s <= t && (s+s)-s == s && s+s > s) rec(s+s,t,ops+"+");
     }
   }
  string getProgram(int s, int t) {
    if (t == s) return "";
    if (t == 0) {
      if (s == 0) return "";
      return "-";
    }
    if (t == 1) {
      if (s == 0) return ":-(";
      return "/";
    }
    if (s == 0) return ":-(";
    bla = ":-(";
    rec(1,t,"/");
    rec(s,t,"");
    return bla;
    // +  == *2
    // -  == set to 0
    // *  == ^2 (square)
    // /  == set to 1
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 392; string Arg2 = "+*+"; verify_case(0, Arg2, getProgram(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 256; string Arg2 = "/+***"; verify_case(1, Arg2, getProgram(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 256; string Arg2 = "**"; verify_case(2, Arg2, getProgram(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 7; string Arg2 = ""; verify_case(3, Arg2, getProgram(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 7; int Arg1 = 9; string Arg2 = ":-("; verify_case(4, Arg2, getProgram(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 10; int Arg1 = 1; string Arg2 = "/"; verify_case(5, Arg2, getProgram(Arg0, Arg1)); }
  void test_case_6() { int Arg0 = 1024; int Arg1 = 65536; string Arg2 = "++++++"; verify_case(6, Arg2, getProgram(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  OneRegister ___test;
  ___test.run_test(-1);
}
// END CUT HERE
