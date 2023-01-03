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

class FourBlocksEasy {
 public:
  int maxScore(vector <string> grid) {
    int sc = 0;
    int bc = 0;
    for (int i=0;i<grid[0].size();i++) {
      if (grid[0][i] == '1' || grid[1][i] == '1') {
        if (bc > 0) {
          sc += 16*(bc/2);
          sc += 2*(bc%2);
        }
        bc = 0;
        sc+=2;
      } else {
        bc++;
      }
    }
    if (bc > 0) {
      sc += 16*(bc/2);
      sc += 2*(bc%2);      
    }
    return sc;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".....1..1..",
 "..1.....1.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 70; verify_case(0, Arg1, maxScore(Arg0)); }
	void test_case_1() { string Arr0[] = {"....................",
 "...................."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 160; verify_case(1, Arg1, maxScore(Arg0)); }
	void test_case_2() { string Arr0[] = {".1.........11.........",
 "..1.1......11........."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 128; verify_case(2, Arg1, maxScore(Arg0)); }
	void test_case_3() { string Arr0[] = {"......1.....1...1.",
 ".................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 108; verify_case(3, Arg1, maxScore(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  FourBlocksEasy ___test;
  ___test.run_test(-1);
}
// END CUT HERE
