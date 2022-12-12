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
const int kMod = 1e9+9;
long long mem[16384][11];

class YetAnotherORProblem2 {
 public:
  int R;
  long long equalto(int mask, int left) {
    LL& r = mem[mask][left];
    if (r != -1) return r;
    if (left == 1) {
      if (mask > R) return r = 0;
      return r = 1;
    }
    long long t = 0;
    for (int u = mask; u >= 0; u = (u? ((u - 1)&mask) : -1) ) {
      if ((mask&(~u)) > R) continue;
      (t+=(equalto(u,left-1))%kMod)%=kMod;
    }
    return r = t;
  }
  int countSequences(int N, int R) {
    this->R = R;
    memset(mem,-1,sizeof(mem));
    int highest = 0;
    for (int i=30;i>=0;i--)
      if (R&(1<<i)) {
        highest = i;
        break;
      }
    long long r = 1;
    long long hmask = (1LL<<(highest+1))-1;
    for (int i=1;i<=hmask;i++)
      (r+=equalto(i,N))%=kMod;
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 7; verify_case(0, Arg2, countSequences(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 9; verify_case(1, Arg2, countSequences(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 16; verify_case(2, Arg2, countSequences(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 1023; int Arg2 = 73741815; verify_case(3, Arg2, countSequences(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  YetAnotherORProblem2 ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
