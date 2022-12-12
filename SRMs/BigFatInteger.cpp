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

class BigFatInteger {
 public:
  int minOperations(int A, int B) {
    int r = 0;
    int mx = 0;
    for (int i=2;i*i<=A;i++) {
      int c = 0;
      while (A%i == 0) {
        ++c;
        A/=i;
      }
      if (c) {
        r++;
        mx = max(mx,c);
      }
    }
    if (A > 1) {
      r++;
      mx = max(mx,1);
    }
    mx*=B;
    LL c = 1;
    while (c < mx) {
      ++r;
      c<<=1;
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, minOperations(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 162; int Arg1 = 1; int Arg2 = 4; verify_case(1, Arg2, minOperations(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 999983; int Arg1 = 9; int Arg2 = 5; verify_case(2, Arg2, minOperations(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 360; int Arg1 = 8; int Arg2 = 8; verify_case(3, Arg2, minOperations(Arg0, Arg1)); }
  void test_case_4() { int Arg0 = 524288; int Arg1 = 1000000; int Arg2 = 26; verify_case(4, Arg2, minOperations(Arg0, Arg1)); }
// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  BigFatInteger ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
