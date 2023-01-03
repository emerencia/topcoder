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
#include <limits>
#include <cstring>
#include <numeric>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
// BEGIN CUT HERE
const int toTest = -1;
// 
// END CUT HERE

class FoxAndFencingEasy {
 public:
  string WhoCanWin(int mov1, int mov2, int d) {
    // base cases: if d within range
    if (d <= mov1) return "Ciel";
    if (d+mov1 <= mov2) return "Liss";
    if (mov1 >= 1+2*mov2) return "Ciel";
    if (mov2 >= 1+2*mov1) return "Liss";
    return "Draw";
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 58; int Arg2 = 1; string Arg3 = "Ciel"; verify_case(0, Arg3, WhoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 100000000; string Arg3 = "Draw"; verify_case(1, Arg3, WhoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 150; int Arg2 = 100000000; string Arg3 = "Draw"; verify_case(2, Arg3, WhoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 250; int Arg2 = 100000000; string Arg3 = "Liss"; verify_case(3, Arg3, WhoCanWin(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  FoxAndFencingEasy ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
