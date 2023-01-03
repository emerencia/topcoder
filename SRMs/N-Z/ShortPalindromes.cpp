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

int dp[27][27];

class ShortPalindromes {
 public:
  string shortest(string base) {
    vector<vector<string> > pd(27,vector<string>(27));
    fill(&dp[0][0],&dp[27][0],INT_MAX);
    for (int i=0;i<27;i++) {
      dp[i][0] = 0;
      pd[i][0] = "";
      dp[i][1] = 0;
      pd[i][1] = string(1,base[i]);
    }
    int n = base.size();
    for (int m=2;m<=n;m++)
      for (int l=0;l+m<=n;l++)
        if (base[l] == base[l+m-1]) {
          dp[l][m] = dp[l+1][m-2];
          pd[l][m] = base[l]+pd[l+1][m-2]+base[l+m-1];
        } else {
          dp[l][m] = 1+min(dp[l][m-1],dp[l+1][m-1]);
          if (dp[l][m-1] == dp[l+1][m-1]) {
            pd[l][m] = min(base[l+m-1]+pd[l][m-1]+base[l+m-1],
                           base[l]+pd[l+1][m-1]+base[l]);
          } else if (dp[l+1][m-1] > dp[l][m-1]) {
            pd[l][m] = base[l+m-1]+pd[l][m-1]+base[l+m-1];
          } else {
            pd[l][m] = base[l]+pd[l+1][m-1]+base[l];
          }
        }
    return pd[0][n];
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RACE"; string Arg1 = "ECARACE"; verify_case(0, Arg1, shortest(Arg0)); }
	void test_case_1() { string Arg0 = "TOPCODER"; string Arg1 = "REDTOCPCOTDER"; verify_case(1, Arg1, shortest(Arg0)); }
	void test_case_2() { string Arg0 = "Q"; string Arg1 = "Q"; verify_case(2, Arg1, shortest(Arg0)); }
	void test_case_3() { string Arg0 = "MADAMIMADAM"; string Arg1 = "MADAMIMADAM"; verify_case(3, Arg1, shortest(Arg0)); }
	void test_case_4() { string Arg0 = "ALRCAGOEUAOEURGCOEUOOIGFA"; string Arg1 = "AFLRCAGIOEOUAEOCEGRURGECOEAUOEOIGACRLFA"; verify_case(4, Arg1, shortest(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ShortPalindromes ___test;
  ___test.run_test(-1);
}
// END CUT HERE
