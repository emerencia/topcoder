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
// 21:45 start
// 22:26 done
// 22:26 debugging
// END CUT HERE

class LittleElephantAndXor {
 public:
  long long mask;
  long long rec(long long A, long long B, int idx) {
    if (idx == -1) return 1;
    long long r = 0;
    if (mask&(1LL<<idx)) {
      if (A >= (1LL<<idx)) r+= 2LL*rec(A-(1LL<<idx),min(B,(1LL<<idx)-1),idx-1);
      if (B >= (1LL<<idx)) r+= 2LL*rec(min(A,(1LL<<idx)-1),B-(1LL<<idx),idx-1);
      if (A < (1LL<<idx) && B < (1LL<<idx)) r+= max(A,1LL)*max(B,1LL);
    } else {
      if (A >= (1LL<<idx) && B >= (1LL<<idx)) r+= rec(A-(1LL<<idx),B-(1LL<<idx),idx-1);
      r+= rec(min(A,(1LL<<idx)-1),min(B,(1LL<<idx)-1),idx-1);
    }
    return r;
  }
  long long getNumber(int A, int B, int C) {
    mask = C;
    return rec(A,B,31);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; long long Arg3 = 5LL; verify_case(0, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 3; long long Arg3 = 20LL; verify_case(1, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 5; long long Arg3 = 57LL; verify_case(2, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 774; int Arg1 = 477; int Arg2 = 447; long long Arg3 = 214144LL; verify_case(3, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1000000000; int Arg1 = 1000000000; int Arg2 = 500000000; long long Arg3 = 468566946385621507LL; verify_case(4, Arg3, getNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  LittleElephantAndXor ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
