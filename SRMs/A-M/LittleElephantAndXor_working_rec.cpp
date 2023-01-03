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
// 00:24 imp2
// 00:57 done
// END CUT HERE

long long mem[2][2][2][32];

class LittleElephantAndXor {
 public:
  long long mask;
  long long A;
  long long B;
  long long rec(bool aanything, bool banything, bool canything, int idx) {
    if (idx == -1) return 1;
    long long& r = mem[aanything][banything][canything][idx];
    if (r != -1) return r;
    long long t = 0;
    if (mask&(1LL<<idx) || canything) {
      // they still have to be same
      // either a is 1 and b is 0
      // a can be 1 if it is 1 in the bit or if it can be anything
      // b can always be 0... but if it was 1 then it can now be anything
      if (aanything || A&(1LL<<idx)) {
        t+=rec(aanything,banything|((B>>idx)&1),canything,idx-1);
      }
      // or b is 1 and a is 0
      // b can be 1 if it is 1 in the bit or if it can be anything
      if (banything || B&(1LL<<idx)) {
        // a can always be 0, but if it was 1 then it can now be anything
        t+=rec(aanything|((A>>idx)&1),banything,canything,idx-1);
      }
    }
    // a and b have to be zero
    // if they were 1, they can now be anything
    t+=rec(aanything|((A>>idx)&1),banything|((B>>idx)&1),canything|((mask>>idx)&1),idx-1);
    // or a and b have to be 1
    if ((aanything || A&(1LL<<idx)) && (banything || (B&(1LL<<idx)))) {
      // their anything state does not change because the resulting mask is equal
      t+=rec(aanything,banything,canything|((mask>>idx)&1),idx-1);
    }
    return r = t;
  }
  long long getNumber(int a, int b, int C) {
    mask = C;
    A = a;
    B = b;
    memset(mem,-1,sizeof(mem));
    return rec(false,false,false,31);
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
