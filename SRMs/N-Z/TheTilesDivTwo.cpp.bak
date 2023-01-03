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

int dp[50][1<<8];
int masks[2][6];

class TheTilesDivTwo {
 public:
  int bin(int a,int b,int c) {
    return (1<<a)+(1<<b)+(1<<c);
  }
  int find(vector <string> board) {
    int n = board[0].size();
    int m = board.size();
    if (m == 1 || n == 1) return 0;
    while (m < 4) {
      board.push_back(string(n,'X'));
      m++;
    }
    // create masks
    masks[0][0] = bin(1,0,5);
    masks[0][1] = bin(1,2,5);
    masks[0][2] = bin(3,2,7);
    masks[0][3] = bin(6,2,7);
    masks[0][4] = bin(6,2,5);
    masks[0][5] = bin(4,0,5);
    masks[1][0] = bin(0,1,4);
    masks[1][1] = bin(2,1,6);
    masks[1][2] = bin(2,3,6);
    masks[1][3] = bin(7,3,6);
    masks[1][4] = bin(5,1,6);
    masks[1][5] = bin(5,1,4);
    // start mask
    int startmask = 0;
    for (int i=0;i<2;i++)
      for (int j=3;j>=0;j--)
        startmask = 2*startmask+(board[j][i] == 'X');
    memset(dp,-1,sizeof(dp));
    dp[0][startmask] = 0;
    for (int i=0;i+1<n;i++) {
      for (int j=0;j<(1<<8);j++) {
        if (dp[i][j] == -1) continue;
        for (int k=0;k<6;k++) {
          if (j&(masks[i%2][k])) continue;
          dp[i][j|masks[i%2][k]] = max(dp[i][j|masks[i%2][k]],1+dp[i][j]);
        }
      }
      int nextmask = 0;
      if (i+2 < n)
        for (int j=3;j>=0;j--)
          nextmask = 2*nextmask+(board[j][i+2]=='X');
      for (int j=0;j<(1<<8);j++) {
        if (dp[i][j] == -1) continue;
        int t = ((j<<4)&((1<<8)-1))|nextmask;
        dp[i+1][t] = max(dp[i+1][t],dp[i][j]);
      }
    }
    int r = 0;
    for (int i=0;i<(1<<8);i++)
      r = max(r,dp[n-1][i]);
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"X.X",
 "...",
 "X.X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arr0[] = {"...",
 "...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arr0[] = {"......X.X.XXX.X.XX."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arr0[] = {"X.....XXX.XX..XXXXXXXXX...X.XX.XX....X",
 ".XXXX..X..XXXXXXXX....XX.X.X.X.....XXX",
 "....XX....X.XX..X.X...XX.X..XXXXXXX..X",
 "XX.XXXXX.X.X..X..XX.XXX..XX...XXX.X..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  TheTilesDivTwo ___test;
  ___test.run_test(-1);
}
// END CUT HERE
