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
#include "ticks.h"
using namespace std;

class KingdomAndPassword {
 public:
   int bitCount(int n) {
     int r = 0;
     for (int i=n;i;i&=i-1) r++;
     return r;
   }
  long long newPassword(long long oldPassword, vector <int> restrictedDigits) {
    vector<int> digits; // has digits in reverse
    for (long long t = oldPassword;t;t/=10) digits.push_back(t%10);
    int n = digits.size();
    vector<long long> mul(16);
    mul[n-1] = 1;
    for (int i=n-2;i>=0;i--) mul[i] = mul[i+1]*10; // only thing that matters: 
    long long dp[2][1<<16];                        // very few bits = very large factor
    memset(dp,-1,sizeof(dp));                      // order doesn't matter
    dp[0][0] = 0;
    for (int i=0;i<(1<<n);i++) {
      int b = bitCount(i);
      for (int j=0;j<2;j++) {
        if (dp[j][i] == -1) continue;
        for (int k=0;k<n;k++) {
          if (i&(1<<k)) continue;
          if (digits[k] == restrictedDigits[b]) continue;
          long long a = 10*dp[j][i] + digits[k];
          if (a*mul[b] <= oldPassword) dp[0][i|(1<<k)] = max(dp[0][i|(1<<k)],a);
          else {
            if (dp[1][i|(1<<k)] == -1) dp[1][i|(1<<k)] = a;
            else dp[1][i|(1<<k)] = min(a,dp[1][i|(1<<k)]);
          }
        }
      }
    }
    long long a1 = dp[0][(1<<n)-1];
    if (dp[1][(1<<n)-1] != -1 && (a1 == -1 || oldPassword-a1 > dp[1][(1<<n)-1]-oldPassword))
      a1 = dp[1][(1<<n)-1];
    return a1;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4();if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 548LL; int Arr1[] = {5, 1, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 485LL; verify_case(0, Arg2, newPassword(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 7777LL; int Arr1[] = {4, 7, 4, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = -1LL; verify_case(1, Arg2, newPassword(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 58LL; int Arr1[] = {4, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 58LL; verify_case(2, Arg2, newPassword(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 172LL; int Arr1[] = {4, 7, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 127LL; verify_case(3, Arg2, newPassword(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 241529363573463LL; int Arr1[] = {1, 4, 5, 7, 3, 9, 8, 1, 7, 6, 3, 2, 6, 4, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 239676554423331LL; verify_case(4, Arg2, newPassword(Arg0, Arg1)); }	void test_case_5() { long long Arg0 = 9151LL; int Arr1[] = {9, 1, 5, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1915LL; verify_case(5, Arg2, newPassword(Arg0, Arg1)); }
  void test_case_6() { long long Arg0 = 3941LL; int Arr1[] = {5, 9, 5, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 4139LL; verify_case(6, Arg2, newPassword(Arg0, Arg1)); }
  void test_case_7() { long long Arg0 = 3345411115342361LL; int Arr1[] = {4, 1, 1, 3, 1, 1, 1, 6, 2, 1, 4, 1, 1, 1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1651544114133332LL; verify_case(7, Arg2, newPassword(Arg0, Arg1)); }  void test_case_8() { long long Arg0 = 4752914625388618LL; int Arr1[] = {9, 8, 7, 3, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 8188122344556679LL; verify_case(8, Arg2, newPassword(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  KingdomAndPassword ___test;
  beginn();
  ___test.run_test(8);
  endd();
  cout << "time: " << ticks() << "ms" << endl;
}
// END CUT HERE
