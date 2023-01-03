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

int dp[51][51][51][51];

class StarAdventure {
 public:
  int mostStars(vector <string> level) {
    int n = level.size();
    int m = level[0].size();
    int minsize = min(n,m);
    if (minsize <= 2) {
      int c = 0;
      for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
          c+=level[i][j]-'0';
      return c;
    }
    memset(dp,0,sizeof(dp));
    vector<vector<int> > value(n,vector<int>(m));
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++)
        value[i][j] = level[i][j]-'0';
    dp[0][0][1][2] = value[0][0]+value[0][1]+value[0][2];
    for (int k=0;k+2<m;k++)
        for (int i=k+1;i+1<m;i++)
          for (int j=i+1;j<m;j++) {
            int c = 0;
            for (int a=0;a<=j;a++)
              c+=value[0][a];
            dp[0][k][i][j] = c;
          }    
    for (int r=0;r<n;r++) {
      for (int k=0;k<m;k++)
        for (int i=k+1;i<m;i++)
          for (int j=i+1;j<m;j++) {
            int tmp = dp[r][k][i][j];
            if (r) tmp = max(tmp,dp[r-1][k][i][j]+value[r][k]+value[r][i]+value[r][j]);
            dp[r][k][i][j] = tmp;
          }
      for (int k=1;k<m;k++)
        for (int i=k+1;i<m;i++)
          for (int j=i+1;j<m;j++) {
            dp[r][k][i][j] = max(dp[r][k][i][j],
                                 dp[r][k-1][i][j]+value[r][k]);
          }
      for (int k=0;k<m;k++)
        for (int i=k+2;i<m;i++)
          for (int j=i+1;j<m;j++) {
            dp[r][k][i][j] = max(dp[r][k][i][j],
                                 dp[r][k][i-1][j]+value[r][i]);
          }
      for (int k=0;k<m;k++)
        for (int i=k+1;i<m;i++)
          for (int j=i+2;j<m;j++) {
            dp[r][k][i][j] = max(dp[r][k][i][j],
                                 dp[r][k][i][j-1]+value[r][j]);
          }
    }
    return dp[n-1][m-3][m-2][m-1];
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4();if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7();}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"01",
 "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, mostStars(Arg0)); }
	void test_case_1() { string Arr0[] = {"0999999999"
,"9999999999"
,"9999999999"
,"9999999999"
,"9999999999"
,"9999999999"
,"9999999999"
,"9999999999"
,"9999999999"
,"9999999999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 450; verify_case(1, Arg1, mostStars(Arg0)); }
	void test_case_2() { string Arr0[] = {"012"
,"012"
,"012"
,"012"
,"012"
,"012"
,"012"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 21; verify_case(2, Arg1, mostStars(Arg0)); }
	void test_case_3() { string Arr0[] = {"0123456789",
 "1123456789",
 "2223456789",
 "3333456789",
 "4444456789",
 "5555556789",
 "6666666789",
 "7777777789",
 "8888888889",
 "9999999999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 335; verify_case(3, Arg1, mostStars(Arg0)); }
  void test_case_4() { string Arr0[] = {"0333111111", "1300000000", "1330999990", "1030999990", "1030999990", "1010999990", "1011000000", "1111111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 195; verify_case(4, Arg1, mostStars(Arg0)); }
  void test_case_5() { string Arr0[] = {"0461545807", "6851422546", "2292977576", "7177110443", "0678224492", "2040267038", "5121461930", "2243193946", "8471169494", "3596207711"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 268; verify_case(5, Arg1, mostStars(Arg0)); }
  void test_case_6() { string Arr0[] = {"0083039389", "0316994532", "0429276387", "7278052794", "7754242148", "0079252101", "9400204252", "5707353941", "2022597127", "2821388373"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 251; verify_case(6, Arg1, mostStars(Arg0)); }
  void test_case_7() { string Arr0[] = {"0869850487", "4511490545", "1954802392", "2104680042", "2617080263", "0855992992", "6271501046", "6283422315", "2938839005", "7042808171"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 272; verify_case(7, Arg1, mostStars(Arg0)); }
  

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  StarAdventure ___test;
  ___test.run_test(-1);
}
// END CUT HERE
