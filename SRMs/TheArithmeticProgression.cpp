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

class TheArithmeticProgression {
 public:
  double minimumChange(int a, int b, int c) {
    if (a > c) swap(a,c);
    return abs(a+(c-a)/2.0-b);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 1; int Arg2 = 2; double Arg3 = 0.0; verify_case(0, Arg3, minimumChange(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 2; int Arg2 = 1; double Arg3 = 1.5; verify_case(1, Arg3, minimumChange(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; double Arg3 = 0.0; verify_case(2, Arg3, minimumChange(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 8; double Arg3 = 2.0; verify_case(3, Arg3, minimumChange(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  TheArithmeticProgression ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
