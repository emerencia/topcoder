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
typedef pair<int,int> PII;
// 20:57-21:23

// min num  of moves
int dp[14][(1<<14)];

class YetAnotherBoardGame {
 public:
  int minimumMoves(vector <string> board) {
    int N = board.size();
    int M = board[0].size();
    int r = -1;
    for (int movetypes=0;movetypes<(1<<min(N,M));movetypes++) {
      // movetypes&(1<<i) = 1 means movetype 1 or nothing, 0 means movetype 2 or nothing
      // movetypes&(1<<j)
      // if they are not equal to each other, you cannot set any moves
      memset(dp,-1,sizeof(dp));
      vector<string> board2 = board;
      bool valid = true;
      // only toggle if not outside of scope
      for (int p=0;p<N*M;p++) {
        int i = p/M;
        int j = p%M;
        memset(dp[p%M],-1,sizeof(dp[p%M]));
        int movetype = -1;
        if (i < min(N,M) && j < min(N,M) && (movetypes&(1<<i)) != (movetypes&(1<<j)))
          movetype = -1;
        else if (i < min(N,M))
          movetype = (movetypes&(1<<i));
        else
          movetype = (movetypes&(1<<j));
        // movetype -1 = cannot make any moves
        // movetype  0 = only moves of type 1 or nothing
        // movetype  1 = only moves of type 2 or nothing
        int curwhite = (board2[i][j] == 'W');
        int prev = (p-1+M)%M;
        int countvalid = 0;
        
        if (!p) {
          int nstate = 0;
          if (movetype == )
        }
        if (!countvalid) {
          valid = false;
          break;
        }
      }
      if (valid) {
        int lastp = ((N*M)-1+M)%M;
        int r2 = 197;
        for (int i=0;i<(1<<M);i++)
          if (dp[lastp][i] != -1)
            r2 = min(r2,dp[lastp][i]);
        if (r2 != 197)
          if (r == -1)
            r = r2;
          else
            r = min(r,r2);
      }
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BBBBBBBBB",
 "BBWBBBBBB",
 "BWWWBBBBB",
 "BBWBBBWBB",
 "BBBBBWBWB",
 "BBBBBBWBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minimumMoves(Arg0)); }
	void test_case_1() { string Arr0[] = {"BBW",
 "WWW",
 "BWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minimumMoves(Arg0)); }
	void test_case_2() { string Arr0[] = {"WBW",
 "BBW",
 "WBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, minimumMoves(Arg0)); }
	void test_case_3() { string Arr0[] = {"BBBB",
 "WBWB",
 "BBBB",
 "BBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, minimumMoves(Arg0)); }
	void test_case_4() { string Arr0[] = {"WWWWWBW",
 "WBWBWBW",
 "BBWBBWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, minimumMoves(Arg0)); }
	void test_case_5() { string Arr0[] = {"WWWWWWWWWW",
 "WWWWWWWWWW",
 "WWWWWWWWWW",
 "WWWWWWWWWW",
 "WWWWWWWWWW",
 "WWWWWWWWWW",
 "WWWWWWWWWW",
 "WWWWWWWWWW",
 "WWWWWWWWWW",
 "WWWWWWWWWW"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; verify_case(5, Arg1, minimumMoves(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  YetAnotherBoardGame ___test;
  ___test.run_test(-1);
}
// END CUT HERE
