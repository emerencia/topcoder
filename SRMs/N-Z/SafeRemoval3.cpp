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


int dp[51][51][51];
const int INF = 1000000007;

class SafeRemoval {
 public:
  int removeThem(vector <int> seq, int K) {
    vector<vector<int> > v(4);
    fill(&dp[0][0][0],&dp[51][0][0],INF);
    int sum = 0;
    for (int i=0;i<seq.size();i++) {
      sum+=seq[i];
      v[seq[i]%4].push_back(seq[i]);
    }
    for (int i=0;i<v.size();i++) sort(v[i].begin(),v[i].end());
    int res = -1;
    dp[0][0][0] = 0;
    for (int i=0;i<=v[1].size();i++) {
      for (int j=0;j<=v[2].size();j++) {
        for (int k=0;k<=v[3].size();k++) {
          if (i+j+k > K) continue;
          if (dp[i][j][k] == INF) continue;
          if (i!=v[1].size() && (dp[i][j][k]+v[1][i])%4 != sum%4) dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j][k]+v[1][i]);
          if (j!=v[2].size() && (dp[i][j][k]+v[2][j])%4 != sum%4) dp[i][j+1][k] = min(dp[i][j+1][k],dp[i][j][k]+v[2][j]);
          if (k!=v[3].size() && (dp[i][j][k]+v[3][k])%4 != sum%4) dp[i][j][k+1] = min(dp[i][j][k+1],dp[i][j][k]+v[3][k]);
          if (i+j+k+v[0].size() >= K) {
            int r = dp[i][j][k];
            for (int l=0;l<K-(i+j+k);l++) r+=v[0][l];
            res = max(res,sum-r);
          }
        }
      }
    }
    return res;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 8, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 11; verify_case(0, Arg2, removeThem(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = -1; verify_case(1, Arg2, removeThem(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,6,1,10,1,2,7,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 21; verify_case(2, Arg2, removeThem(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,1,1,1,1,1,1,1,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 6; verify_case(3, Arg2, removeThem(Arg0, Arg1)); }
  void test_case_4() { int Arr0[] = {1, 4, 1, 4, 2, 3, 2, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 14; verify_case(4, Arg2, removeThem(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  SafeRemoval ___test;
  ___test.run_test(-1);
}
// END CUT HERE
