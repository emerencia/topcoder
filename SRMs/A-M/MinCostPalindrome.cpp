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

class MinCostPalindrome {
 public:
  int getMinimum(string s, int oCost, int xCost) {
    int c =0;
    for (int i=0;i<s.size()/2;i++) {
      if (s[i] == 'o' && s[s.size()-i-1] == 'o') continue;
      if (s[i] == 'x' && s[s.size()-i-1] == 'x') continue;
      if (s[i] == 'o' && s[s.size()-i-1] == '?') { c+=oCost; continue; }
      if (s[i] == '?' && s[s.size()-i-1] == 'o') { c+=oCost; continue; }
      if (s[i] == '?' && s[s.size()-i-1] == 'x') { c+=xCost; continue; }
      if (s[i] == 'x' && s[s.size()-i-1] == '?') { c+=xCost; continue; }
      if (s[i] == 'x' && s[s.size()-i-1] == 'o') return -1;
      if (s[i] == 'o' && s[s.size()-i-1] == 'x') return -1;
      if (s[i] == '?' && s[s.size()-i-1] == '?') { c+= 2*min(xCost,oCost); continue; }
    }
    return c;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "oxo?xox?"; int Arg1 = 3; int Arg2 = 5; int Arg3 = 8; verify_case(0, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "x??x"; int Arg1 = 9; int Arg2 = 4; int Arg3 = 8; verify_case(1, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "ooooxxxx"; int Arg1 = 12; int Arg2 = 34; int Arg3 = -1; verify_case(2, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "oxoxooxxxxooxoxo"; int Arg1 = 7; int Arg2 = 4; int Arg3 = 0; verify_case(3, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "?o"; int Arg1 = 6; int Arg2 = 2; int Arg3 = 6; verify_case(4, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "????????????????????"; int Arg1 = 50; int Arg2 = 49; int Arg3 = 980; verify_case(5, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arg0 = "o??oxxo?xoox?ox??x??" ; int Arg1 = 3; int Arg2 = 10; int Arg3 = 38; verify_case(6, Arg3, getMinimum(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  MinCostPalindrome ___test;
  ___test.run_test(-1);
}
// END CUT HERE
