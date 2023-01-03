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
// 20:57-21:23-22:32-23:22

int dx[] = {-1,0,1,0,0};
int dy[] = {0,-1,0,1,0};

class YetAnotherBoardGame {
 public:
  int N;
  int M;
  int minmoveSub(vector<vector<bool> >& board, int flips, int movetypes) {
    int state = 0;
    for (int i=0;i<M;i++)
      if (board[0][i])
        state |= (1<<(M-i-1));
    for (int p=M;p<M*N;p++) {
      int i = p/M;
      int j = p%M;
      int movetype = getmovetype(movetypes,i,j);
      if (state&(1<<(M-1))) {
        // we need to flip
        if (movetype == -1) return -1;
        flips++;
        int k = 4+movetype;
        for (int d=2;d<k;d++)
          if (i+dx[d] >= 0 && i+dx[d] < N && j+dy[d] >= 0 && j+dy[d] < M)
            board[i+dx[d]][j+dy[d]] = 1-board[i+dx[d]][j+dy[d]];
        // toggle left
        // state = state^1 <-- does this work too
        if (j)
          state ^= (1<<0);
      }
      int curcol = board[i][j];
      state = ((state<<1)&((1<<M)-1));
      if (curcol)
        state |= (1<<0);
    }
    if (state == 0)
      return flips;
    return -1;
  }
  int mymin(int a, int b) {
    if (a == -1) return b;
    if (b == -1) return a;
    return min(a,b);
  }
  int getmovetype(int movetypes, int i, int j) {
    if (i < min(N,M) && j < min(N,M) && ((movetypes&(1<<i)) != (movetypes&(1<<j))))
      return -1;
    if (i < min(N,M))
      return (movetypes&(1<<i));
    return (movetypes&(1<<j));
  }
  int minimumMoves(vector <string> board) {
    N = board.size();
    M = board[0].size();
    vector<vector<bool> > binboard(N,vector<bool>(M,false));
    for (int i=0;i<N;i++)
      for (int j=0;j<M;j++)
        binboard[i][j] = (board[i][j] == 'W');
    int r = -1;
    for (int movetypes=0;movetypes<(1<<min(N,M));movetypes++) {
      for (int i=0;i<(1<<M);i++) {
        // only type 1 allowed
        vector<vector<bool> > b = binboard;
        int flips = 0;
        bool isvalid = true;
        for (int j=0;j<M;j++) {
          if (!(i&(1<<j))) continue;
          flips++;
          int movetype = getmovetype(movetypes,0,j);
          if (movetype == -1) {
            isvalid = false;
            break;
          }
          int k = 4+movetype;
          for (int d=0;d<k;d++)
            if (dx[d] >= 0 && dx[d] < N && j+dy[d] >= 0 && j+dy[d] < M)
              b[dx[d]][j+dy[d]] = 1-b[dx[d]][j+dy[d]];
        }
        if (isvalid)
          r = mymin(r,minmoveSub(b,flips,movetypes));
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
