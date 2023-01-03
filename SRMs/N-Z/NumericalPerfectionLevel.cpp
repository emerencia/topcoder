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

class NumericalPerfectionLevel {
 public:
  long long ff(long long n) {
    if (n < 4) return 0;
    return 1+ff(n/4);
  }
  int rec(long long n) {
    if (n < 16) return 0;
    vector<int> r;
    for (long long i=2;i*i<=n;i++) {
      while (n%i == 0) {
        r.push_back(i);
        n/=i;
      }
    }
    if (n > 1) { r.push_back(n); }
    if (r.size() < 4) return 0;
    return ff(r.size());
  }
  int getLevel(long long N) {
    return rec(N);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; int Arg1 = 0; verify_case(0, Arg1, getLevel(Arg0)); }
	void test_case_1() { long long Arg0 = 144LL; int Arg1 = 1; verify_case(1, Arg1, getLevel(Arg0)); }
	void test_case_2() { long long Arg0 = 1152LL; int Arg1 = 1; verify_case(2, Arg1, getLevel(Arg0)); }
	void test_case_3() { long long Arg0 = 1679616LL; int Arg1 = 2; verify_case(3, Arg1, getLevel(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  NumericalPerfectionLevel ___test;
  ___test.run_test(-1);
}
// END CUT HERE
