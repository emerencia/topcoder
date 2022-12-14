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
#include <limits>
#include <cstring>
#include <numeric>
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
typedef long long LL;
// BEGIN CUT HERE
const int toTest = -1;
// 40 minutes to write this.
// END CUT HERE

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

class FoxAndGo2 {
 public:
  vector<vector<int> > seen;
  int dfs(const vector<string>& board, int i, int j, int c, char chr) {
    if (seen[i][j] != -1) return 0;
    seen[i][j] = c;
    int r = 0;
    for (int k=0;k<4;k++) {
      int ni = i+dx[k];
      int nj = j+dy[k];
      if (ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size()) {
        if (board[ni][nj] == '.') {
          r = 1;
        } else if (board[ni][nj] == chr) {
          r = max(r,dfs(board,ni,nj,c,chr));
        }
      }
    }
    return r;
  }
  int removecomponents(vector<string>& board, char chr) {
    vector<int> goodcomponents;
    seen = vector<vector<int> >(board.size(),vector<int>(board[0].size(),-1));
    int c = 0;
    for (int i=0;i<board.size();i++)
      for (int j=0;j<board[0].size();j++) {
        if (board[i][j] != chr || seen[i][j] != -1) continue;
        c++;
        goodcomponents.push_back(dfs(board,i,j,c-1,chr));
      }
    int r = 0;
    for (int i=0;i<board.size();i++)
      for (int j=0;j<board[0].size();j++)
        if (seen[i][j] != -1 && !goodcomponents[seen[i][j]]) {
          r++;
          board[i][j] = '.';
        }
    return r;
  }
  PIII tryplace(vector<string>& board, int i, int j) {
    board[i][j] = 'X';
    int r = removecomponents(board,'o');
    int nrwhites = 0;
    int nrempty = 0;
    int nrblacks = 4;
    for (int k=0;k<4;k++) {
      int ni = i+dx[k];
      int nj = j+dy[k];
      if (ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size()) {
        if (board[ni][nj] == 'o') ++nrwhites;
        else if (board[ni][nj] == 'X') --nrblacks;
        else if (board[ni][nj] == '.') ++nrempty;
      }
    }
    if (r) return PIII(r,PII(nrwhites,0));
    int b = removecomponents(board,'X');
    if (b) return PIII(-1,PII(nrwhites,0));
    return PIII(0,PII(nrwhites,0));
  }
  int maxKill(vector <string> board) {
    int maxnr = board.size()*board[0].size();
    int r = removecomponents(board,'o');
    int whitecount = 0;
    for (int i=0;i<board.size();i++)
      for (int j=0;j<board[0].size();j++)
        whitecount += board[i][j]== '.';
    for (int k=0;k<maxnr;k++) {
      PIII changed(-1,PII(0,0));
      vector<string> maxboard = board;
      for (int i=0;i<board.size();i++)
        for (int j=0;j<board[0].size();j++) {
          if (board[i][j] != '.') continue;
          vector<string> newboard = board;
          PIII t = tryplace(newboard,i,j);
          if (t > changed) {
            changed = t;
            maxboard = newboard;
          }
        }
      if (changed.first != -1) {
        r+= changed.first;
        board = maxboard;
      } else break;
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"...",
 ".o.",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, maxKill(Arg0)); }
	void test_case_1() { string Arr0[] = {"o.",
 "oo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, maxKill(Arg0)); }
	void test_case_2() { string Arr0[] = {".o.o.",
 "o.o.o",
 ".o.o.",
 "o.o.o",
 ".o.o."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, maxKill(Arg0)); }
	void test_case_3() { string Arr0[] = {".o.o.",
 "o.o.o",
 ".o.o.",
 "o.o.o",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, maxKill(Arg0)); }
	void test_case_4() { string Arr0[] = {".o.o.o.o.o.",
 "o.ooo.ooo.o",
 ".o.......o.",
 "oo.......oo",
 ".o...o...o.",
 "o...o.o...o",
 ".o...o...o.",
 "oo.......oo",
 ".o.......o.",
 "o.ooo.ooo.o",
 ".o.o.o.o.o."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, maxKill(Arg0)); }
	void test_case_5() { string Arr0[] = {"...ooo.....",
 "...o.o.....",
 ".ooo.ooo...",
 ".o.....o...",
 ".ooo.ooo...",
 "...o.o.....",
 "...ooo.....",
 "....o......",
 "....o...ooo",
 "....ooooo.o",
 "........ooo"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 38; verify_case(5, Arg1, maxKill(Arg0)); }
	void test_case_6() { string Arr0[] = {"ooooooooooo",
 "o.........o",
 "o...ooo...o",
 "o...o.o...o",
 "o...ooo...o",
 "o....o....o",
 "o....oooooo",
 "o..........",
 "o.......ooo",
 "o.......o.o",
 "ooooooooooo"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(6, Arg1, maxKill(Arg0)); }
	void test_case_7() { string Arr0[] = {"oo.o.ooo.o..o..",
 "...ooo.o..oo.oo",
 "o..o.o.ooo.o..o",
 "oo.......oo.ooo",
 "..oo.o.o.o.ooo.",
 "..oo..oo..o.ooo",
 "oo.o.oo..o.oooo",
 ".oo.o..ooo.o.oo",
 "o..o.o.o.o.oo..",
 ".oo.oo...o....o",
 "o.o.oo....oo..o",
 ".o.o..o.oo..ooo",
 "o.o.o..o..o....",
 "ooo.oooooooo..o",
 "o..oo.o..o.ooo."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 60; verify_case(7, Arg1, maxKill(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  FoxAndGo2 ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
