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

int dp[2][3001][51][3];

class MiniPaint {
 public:
  int leastBad(vector <string> picture, int maxStrokes) {
    fill(&dp[0][0][0][0],&dp[2][0][0][0],INT_MAX);
    int n = picture.size();
    int m = picture[0].size();
    vector<vector<int> > pic(n,vector<int>(m));
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++)
        pic[i][j] = picture[i][j] == 'B';
    if (maxStrokes == 0) return n*m;
    int cur = 0;
    int next = 1;
    for (int i=0;i<n;i++) {
      fill(&dp[next][0][0][0],&dp[next][3001][0][0],INT_MAX);
      for (int ii=0;ii<n;ii++)
        for (int jj=0;jj<m;jj++)
          for (int cc=0;cc<3;cc++)
            dp[next][0][jj][cc] = ii*m +jj+1;
      for (int k=1;k<=maxStrokes;k++)
        for (int j=0;j<m;j++)
          for (int c=0;c<3;c++) {
            if (j == 0) {
              if (i) {
                dp[next][k][j][c] = (pic[i][j] != c) + min(dp[cur][k-(c!=2)][m-1][0],
                    min(dp[cur][k-(c!=2)][m-1][1],dp[cur][k-(c!=2)][m-1][2]));
              } else {
                dp[next][k][j][c] = (pic[i][j] != c);
              }
            } else {
              dp[next][k][j][c] = (pic[i][j] != c) + min(dp[next][k][j-1][c],
                                                         min(dp[next][k-1][j-1][(c+1)%3],
                                                             dp[next][k-1][j-1][(c+2)%3]));
            }
          }
      swap(cur,next);
    }
    return min(dp[cur][maxStrokes][m-1][0],
           min(dp[cur][maxStrokes][m-1][1],
                dp[cur][maxStrokes][m-1][2]));
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"BBBBBBBBBBBBBBB",
"WWWWWWWWWWWWWWW",
"WWWWWWWWWWWWWWW",
"WWWWWBBBBBWWWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 0; verify_case(0, Arg2, leastBad(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {
"BBBBBBBBBBBBBBB",
"WWWWWWWWWWWWWWW",
"WWWWWWWWWWWWWWW",
"WWWWWBBBBBWWWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 5; verify_case(1, Arg2, leastBad(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {
"BBBBBBBBBBBBBBB",
"WWWWWWWWWWWWWWW",
"WWWWWWWWWWWWWWW",
"WWWWWBBBBBWWWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 60; verify_case(2, Arg2, leastBad(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 40; verify_case(3, Arg2, leastBad(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(4, Arg2, leastBad(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  MiniPaint ___test;
  ___test.run_test(-1);
}
// END CUT HERE
