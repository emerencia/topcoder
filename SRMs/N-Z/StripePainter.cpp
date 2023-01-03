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

int dp [50][51][27];

class StripePainter {
 public:
  int minStrokes(string stripes) {
    int n = stripes.size();
    fill(&dp[0][0][0],&dp[50][0][0],INT_MAX);
    for (int k=0;k<=n;k++)
      for (int a=0;a<27;a++)
        dp[k][0][a] = 0;
    for (int m=1;m<=n;m++)
      for (int k=0;k<=n-m;k++)
        for (int a=0;a<27;a++)
          if (stripes[k]-'@' == a)
            dp[k][m][a] = dp[k+1][m-1][a];
          else
            for (int j=1;j<=m;j++)
              dp[k][m][a] = min(dp[k][m][a],1+dp[k+1][j-1][stripes[k]-'@']+
                                              dp[k+j][m-j][a]);
    return dp[0][n][0];
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RGBGR"; int Arg1 = 3; verify_case(0, Arg1, minStrokes(Arg0)); }
	void test_case_1() { string Arg0 = "RGRG"; int Arg1 = 3; verify_case(1, Arg1, minStrokes(Arg0)); }
	void test_case_2() { string Arg0 = "ABACADA"; int Arg1 = 4; verify_case(2, Arg1, minStrokes(Arg0)); }
	void test_case_3() { string Arg0 = "AABBCCDDCCBBAABBCCDD"; int Arg1 = 7; verify_case(3, Arg1, minStrokes(Arg0)); }
	void test_case_4() { string Arg0 = "BECBBDDEEBABDCADEAAEABCACBDBEECDEDEACACCBEDABEDADD"; int Arg1 = 26; verify_case(4, Arg1, minStrokes(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  StripePainter ___test;
  ___test.run_test(-1);
}
// END CUT HERE
