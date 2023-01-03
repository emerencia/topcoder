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

int dp[12][12][102];

class QuickSums {
 public:
  int minSums(string numbers, int sum) {
    fill(&dp[0][0][0],&dp[12][0][0],1000);
    for (int i=0;i<12;i++)
      for (int j=0;j<102;j++)
        dp[i][0][j] = 0;
    int n = numbers.size();
    for (int c=1;c<=n;c++)
      for (int a=0;a+c<=n;a++)
        for (int d=0;d<=sum;d++) {
          int h = 0;
          for (int x=0;x<c;x++)
            h=h*10+numbers[a+x]-'0';
          if (d == h)
            dp[a][c][d] = 0;
          else {
            int aa = numbers[a]-'0';
            for (int j=0;j<c && j < 5;j++) {
              for (int e=0;e+aa<=d;e++) {
                int f = d-e-aa;
                if (f < 0) break;
                if (j == 0 && f+aa != d) continue;
                if (j == c-1 && e+aa != d) continue;
                dp[a][c][d] = min(dp[a][c][d],
                    1+dp[a+1][j][e]+dp[a+j+1][c-j-1][f]);
              }
              aa*=10;
            }
          }
        }
    return (dp[0][n][sum] >= n ? -1 : dp[0][n][sum]);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "99999"; int Arg1 = 45; int Arg2 = 4; verify_case(0, Arg2, minSums(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "1110"; int Arg1 = 3; int Arg2 = 3; verify_case(1, Arg2, minSums(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "0123456789"; int Arg1 = 45; int Arg2 = 8; verify_case(2, Arg2, minSums(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "99999"; int Arg1 = 100; int Arg2 = -1; verify_case(3, Arg2, minSums(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "382834"; int Arg1 = 100; int Arg2 = 2; verify_case(4, Arg2, minSums(Arg0, Arg1)); }
	void test_case_5() { string Arg0 =   "9230560001"; int Arg1 = 71; int Arg2 = 4; verify_case(5, Arg2, minSums(Arg0, Arg1)); }
  	void test_case_6() { string Arg0 = "8833614925"; int Arg1 = 10; int Arg2 = -1; verify_case(6, Arg2, minSums(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  QuickSums ___test;
  ___test.run_test(-1);
}
// END CUT HERE
