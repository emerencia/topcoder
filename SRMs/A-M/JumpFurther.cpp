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
#include <numeric>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;

class JumpFurther {
 public:
  int furthest(int N, int badStep) {
    long long a = ((LL)N*((LL)N+1LL))/2LL;
    if (a < badStep) return a;
    int l = 1;
    int r = N;
    while (r-l > 1) {
      int pivot = (l+r)>>1;
      if (((LL)pivot*((LL)pivot+1LL))/2LL < badStep)
        l = pivot;
      else r = pivot;
    }
    if (((LL)l*((LL)l+1LL))/2LL < badStep && ((LL)(l+1LL)*((LL)(l+1LL)+1LL))/2LL > badStep)
      return a;
    return a-1;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, furthest(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 2; verify_case(1, Arg2, furthest(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 5; verify_case(2, Arg2, furthest(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1313; int Arg1 = 5858; int Arg2 = 862641; verify_case(3, Arg2, furthest(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 757065; int Arg2 = 1; verify_case(4, Arg2, furthest(Arg0, Arg1)); }
  void test_case_5() { int Arg0 = 2000; int Arg1 = 2001000; int Arg2 = 2000999; verify_case(5, Arg2, furthest(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  JumpFurther ___test;
  ___test.run_test(-1);
}
// END CUT HERE
