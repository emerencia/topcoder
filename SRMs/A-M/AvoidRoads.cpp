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

int bad[102][102][2];
long long dp[102][102];

class AvoidRoads {
 public:
  long long numWays(int m, int n, vector <string> ba) {
    m++;
    n++;
    for (int i=0;i<ba.size();i++) {
      stringstream a(ba[i]);
      int b,c,d,e;
      a >> b >> c >> d >> e;
      stringstream f;
      f << min(b,d) << " ";
      f << min(c,e) << " ";
      f << max(b,d) << " ";
      f << max(c,e);
      ba[i] = f.str();
    }
    memset(bad,0,sizeof(bad));
    memset(dp,0,sizeof(dp));
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++)
        for (int k=0;k<2;k++) {
          stringstream a;
          a << j << " " << i << " " << (k == 1 ? j+1 : j) << " " << (k == 0 ? i+1 : i);
          string s = a.str();
          for (int l=0;l<ba.size();l++)
            if (s == ba[l]) {
              bad[i][j][k] = 1;
              break;
            }
        }
    dp[0][0] = 1;
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++) {
        if (i != n-1 && !bad[i][j][0]) dp[i+1][j] += dp[i][j];
        if (j != m-1 && !bad[i][j][1]) dp[i][j+1] += dp[i][j];
      }
    return dp[n-1][m-1];
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 6; string Arr2[] = {"0 0 0 1","6 6 5 6"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 252LL; verify_case(0, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 2LL; verify_case(1, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 35; int Arg1 = 31; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 6406484391866534976LL; verify_case(2, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; string Arr2[] = {"0 0 1 0", "1 2 2 2", "1 1 2 1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 0LL; verify_case(3, Arg3, numWays(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  AvoidRoads ___test;
  ___test.run_test(-1);
}
// END CUT HERE
