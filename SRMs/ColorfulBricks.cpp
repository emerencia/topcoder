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
#include <climits>
#include <cstring>
using namespace std;

class ColorfulBricks {
 public:
  int countLayouts(string bricks) {
    set<char> a;
    for (int i=0;i<bricks.size();i++) a.insert(bricks[i]);
    if (a.size() == 1) return 1;
    if (a.size() == 2) return 2;
    return 0;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABAB"; int Arg1 = 2; verify_case(0, Arg1, countLayouts(Arg0)); }
	void test_case_1() { string Arg0 = "AAA"; int Arg1 = 1; verify_case(1, Arg1, countLayouts(Arg0)); }
	void test_case_2() { string Arg0 = "WXYZ"; int Arg1 = 0; verify_case(2, Arg1, countLayouts(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ColorfulBricks ___test;
  ___test.run_test(-1);
}
// END CUT HERE
