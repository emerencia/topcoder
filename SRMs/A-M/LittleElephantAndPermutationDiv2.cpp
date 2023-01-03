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

long long dp[1<<11][120];

class LittleElephantAndPermutationDiv2 {
 public:
  int K;
  int N;
  long long rec(const vector<int>& a,int used,int idx, int k) {
    LL& r = dp[used][k];
    if (r != -1) return r;
    if (idx == a.size()) {
      return r=(k >= K);
    }
    long long t = 0;
    for (int i=1;i<=N;i++)
      if (!(used&(1<<i))) {
        int mx = max(a[idx],i);
        t+=rec(a,used|(1<<i),idx+1,k+mx);
      }
    return r = t;
  }
  long long getNumber(int N, int K) {
    this->K = K;
    this->N = N;
    vector<int> a;
    for (int i=0;i<N;i++)
      a.push_back(i+1);
    long long r = 0;
    memset(dp,-1,sizeof(dp));
    do {
      r += rec(a,0,0,0);
    } while(next_permutation(a.begin(),a.end()));
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; long long Arg2 = 1LL; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; long long Arg2 = 4LL; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 8; long long Arg2 = 18LL; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 47; long long Arg2 = 13168189440000LL; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  LittleElephantAndPermutationDiv2 ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
