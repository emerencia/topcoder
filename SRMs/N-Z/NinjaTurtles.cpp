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

class NinjaTurtles {
 public:
  int countOpponents(int p, int k) {
    /*
    long long n = 3LL*k*p/(9LL+k);
    for (int a = -9*401;a<9*401;a++)
      if (n+a > 0 && 3LL*((n+a)/k)+((n+a)/3LL) == p) return n+a;
    return -1;
    */
    long long l = 1;
    long long r = k*p;
    while (l < r) {
      long long v = (l+r)>>1;
      if ((v/k)*3+(v/3) < p) l = v+1;
      else r = v;
    }
    return ((r/k)*3+(r/3) == p ? l : -1);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 4; int Arg2 = 6; verify_case(0, Arg2, countOpponents(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 4; int Arg2 = 3; verify_case(1, Arg2, countOpponents(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 13; int Arg1 = 6; int Arg2 = -1; verify_case(2, Arg2, countOpponents(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 13; int Arg1 = 17; int Arg2 = 30; verify_case(3, Arg2, countOpponents(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 122; int Arg1 = 21; int Arg2 = 258; verify_case(4, Arg2, countOpponents(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  NinjaTurtles ___test;
  ___test.run_test(-1);
}
// END CUT HERE
