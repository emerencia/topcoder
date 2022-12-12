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

const int kMod = 1e9+7;
const int K = 1226;

long long dp[51][K];
long long fact[51];

class DistinctRemainders {
 public:
  long long modPow(long long x, long long y) {
    long long r=1;
    long long a=x;
    while (y > 0) {
        if ( (y&1)==1 ) {
            r = (r * a)%kMod;
        }
        a = (a * a)%kMod;
        y /= 2;
    }
    return r;
  }
  long long modInverse(long long x) {
    return modPow(x, kMod-2);
  }
  long long bico(long long n, long long k) {
    if (k < 0 || k > n) return 0;
    if (k > n-k) k = n-k;
    long long r = 1;
    for (long long i=0;i<k;i++)
      r = ((n-i)%kMod*r%kMod*modInverse(i+1LL))%kMod;
    return r;
  }
  int howMany(long long N, int m) {
    long long M = m;
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for (int i=0;i<M;i++)
      for (int j=M;j>=1;j--)
        for (int k=i;k<K;k++)
           dp[j][k]=(dp[j][k] + dp[j-1][k-i])%kMod;
    fact[0] = 1;
    for (int i=1;i<51;i++) fact[i] = (i*fact[i-1])%kMod;
    long long r = 0;
    for (int i=1;i<=M;i++)
      for (int j=N%M;j<K && j <= N;j+=M) {
        long long Q = (N-j)/M;
        r = (r + (((dp[i][j]*fact[i])%kMod)*bico(Q+i-1,i-1))%kMod)%kMod;
      }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 3LL; int Arg1 = 2; int Arg2 = 5; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 3LL; int Arg1 = 3; int Arg2 = 9; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 58LL; int Arg1 = 1; int Arg2 = 1; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 572LL; int Arg1 = 7; int Arg2 = 922572833; verify_case(3, Arg2, howMany(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 1000000000000000000LL; int Arg1 = 20; int Arg2 = 240297629; verify_case(4, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  DistinctRemainders ___test;
  ___test.run_test(-1);
}
// END CUT HERE
