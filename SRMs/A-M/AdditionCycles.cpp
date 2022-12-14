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

class AdditionCycles {
 public:
  int cycleLength(int n) {
    int a = n/10;
    int b = n%10;
    int c = 0;
    do {
      int d = a;
      a = b;
      b = (d + b)%10;
      ++c;
    } while (a != n/10 || b != n%10);
    return c;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 26; int Arg1 = 4; verify_case(0, Arg1, cycleLength(Arg0)); }
	void test_case_1() { int Arg0 = 55; int Arg1 = 3; verify_case(1, Arg1, cycleLength(Arg0)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 1; verify_case(2, Arg1, cycleLength(Arg0)); }
	void test_case_3() { int Arg0 = 71; int Arg1 = 12; verify_case(3, Arg1, cycleLength(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  AdditionCycles ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
