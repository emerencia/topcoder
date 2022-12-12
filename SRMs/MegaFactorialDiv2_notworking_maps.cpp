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

const int kMod = 1000000009;

class MegaFactorialDiv2 {
 public:
  map<int,int> merge(map<int,int>& a,map<int,int>& b) {
    map<int,int> r;
    for (map<int,int>::iterator i=a.begin();i!=a.end();i++) {
      r[i->first] = i->second;
    }
    for (map<int,int>::iterator i=b.begin();i!=b.end();i++) {
      if (r.count(i->first)) {
        r[i->first] +=i->second;
      } else {
        r[i->first] = i->second;
      }
    }
    return r;
  }
  int countDivs(map<int,int> a) {
    long long r = 1;
    for (map<int,int>::iterator i=a.begin();i!=a.end();i++) {
      long long t = i->second + 1;
      r = (r*t)%kMod;
    }
    return r;
  }
  int countDivisors(int N, int K) {
    vector<map<int,int > > m(N+1);
    for (int k=2;k<=N;k++) {
      int kk = k;
      for (int i=2;i*i<=kk;i++) {
        if (kk%i == 0) {
          m[k][i] = 1;
          kk/=i;
        }
        while (kk%i == 0) {
          m[k][i]++;
          kk/=i;
        }
      }
      if (kk > 1) {
        if (m[k].count(kk)) m[k][kk]++;
        else m[k][kk] = 1;
      }
    }
    vector<vector<map<int,int> > > dp(N+1,vector<map<int,int> >(K+1));
    for (int n=2;n<=N;n++)
      dp[n][0] = m[n];
    for (int n=1;n<=N;n++)
      for (int k=1;k<=K;k++) {
        dp[n][k] = merge(dp[n][k-1],dp[n-1][k]);
      }
    return countDivs(dp[N][K]);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 4; verify_case(0, Arg2, countDivisors(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 6; verify_case(1, Arg2, countDivisors(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 18; verify_case(2, Arg2, countDivisors(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 1392; verify_case(3, Arg2, countDivisors(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = 2; int Arg2 = 321266186; verify_case(4, Arg2, countDivisors(Arg0, Arg1)); }
  void test_case_5() { int Arg0 = 77; int Arg1 = 11; int Arg2 = 61095262; verify_case(5, Arg2, countDivisors(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  MegaFactorialDiv2 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
