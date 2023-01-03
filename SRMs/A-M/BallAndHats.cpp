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

class BallAndHats {
 public:
  int getHat(string hats, int numSwaps) {
    int hb = 0;
    for (int i=0;i<hats.size();i++) if (hats[i] == 'o') { hb = i; break; }
    if (numSwaps == 0) return hb;
    if (hb == 1) return 1-(numSwaps%2);
    return numSwaps%2;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ".o."; int Arg1 = 1; int Arg2 = 0; verify_case(0, Arg2, getHat(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "..o"; int Arg1 = 0; int Arg2 = 2; verify_case(1, Arg2, getHat(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "o.."; int Arg1 = 1; int Arg2 = 1; verify_case(2, Arg2, getHat(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "..o"; int Arg1 = 2; int Arg2 = 0; verify_case(3, Arg2, getHat(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "o.."; int Arg1 = 101; int Arg2 = 1; verify_case(4, Arg2, getHat(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  BallAndHats ___test;
  ___test.run_test(-1);
}
// END CUT HERE
