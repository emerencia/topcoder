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

long long dp[2][2][30001];
int idx[2];
const int m = 30001;

class Jewelry {
 public:
  long long howMany(vector <int> values) {
    sort(values.begin(),values.end());
    long long a = 0;
    int n = values.size();
    for (int b=0;b<n-1;b++) {
      memset(dp,-1,sizeof(dp));
      for (int o=0;o<2;o++) {
        memset(dp[o],-1,sizeof(dp[o]));
        int mn = 0;
        int mx = n;
        if (o) { mn = b+1; }
        else { mx = b+1; }
        int cur = 0,next = 1;
        dp[o][cur][0] = 0;
        for (int i=mn;i<mx;i++) {
          for (int k=0;k<m;k++) 
            dp[o][next][k] = dp[o][cur][k];
          for (int k=0;k+values[i]<m;k++) {
            if (dp[o][cur][k] == -1) continue;
            dp[o][next][k+values[i]] += max(1LL,dp[o][cur][k]);
          }
          swap(cur,next);
        }
        idx[o] = cur;
      }
      for (int i=0;i<m;i++) {
        if (dp[0][idx[0]][i] != -1 && dp[1][idx[1]][i] != -1)
          a+=dp[0][idx[0]][i]*dp[1][idx[1]][i];
        if (dp[0][idx[0]][i] != -1 || dp[1][idx[1]][i] != -1)
          cout << dp[0][idx[0]][i] << " " << dp[1][idx[1]][i] << endl;
      }
    }
    return a;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,5,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9LL; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { int Arr0[] = {1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 18252025766940LL; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { int Arr0[] = {7,7,8,9,10,11,1,2,2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 607LL; verify_case(3, Arg1, howMany(Arg0)); }
	void test_case_4() { int Arr0[] = {123,217,661,678,796,964,54,111,417,526,917,923}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(4, Arg1, howMany(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  Jewelry ___test;
  ___test.run_test(2);
}
// END CUT HERE
