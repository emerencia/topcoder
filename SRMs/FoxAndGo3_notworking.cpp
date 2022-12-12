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
typedef long long LL;
// BEGIN CUT HERE
const int toTest = -1;
// 00:54 reading
// 01:10 start imp
// 01:38 done imp (44 min)
// 02:14 done fixes (another 36 min)
// END CUT HERE

int dx[] = {0,-1,1,0,-1,1,-1,1};
int dy[] = {-1,0,0,1,-1,-1,1,1};

class FoxAndGo3 {
 public:
  int n;
  vector<string> board;
  vector<vector<int> > empties;
  vector<vector<int> > component;
  int dfs(int i, int j, int c) {
    if (component[i][j] != -1) return 0;
    component[i][j] = c;
    int r = 1;
    for (int k=0;k<8;k++) {
      int ni = i+dx[k];
      int nj = j+dy[k];
      if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
        if (board[ni][nj] == '.' && k < 4)
          empties[ni][nj] = 1;
        if (board[ni][nj] == 'o')
          r += dfs(ni,nj,c);
      }
    }
    return r;
  }
  int maxEmptyCells(vector <string> Board) {
    board = Board;
    n = board.size();
    int emptycount = 0;
    for (int i=0;i<n;i++)
      for (int j=0;j<n;j++)
        emptycount += board[i][j] == '.';
    bool changed = true;
    while (changed) {
      changed = false;
      bool mychanged = true;
      while (mychanged) {
        mychanged = false;
        for (int i=0;i<n;i++)
          for (int j=0;j<n;j++) {
            if (board[i][j] != 'o') continue;
            int ec = 0;
            for (int k=0;k<4;k++) {
              int ni = i+dx[k];
              int nj = j+dy[k];
              if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                if (board[ni][nj] == '.') ++ec;
              }
            }
            if (ec == 0) {
              emptycount++;
              board[i][j] = '.';
            } else if (ec == 1) {
              mychanged = true;
              board[i][j] = '.';
              for (int k=0;k<4;k++) {
                int ni = i+dx[k];
                int nj = j+dy[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                  if (board[ni][nj] == '.') 
                    board[ni][nj] = 'x';
                }
              }
            }
          }
      }
      int c = 0;
      component = vector<vector<int> >(n,vector<int>(n,-1));
      vector<string> newboard = board;
      int maxinc = 0;
      for (int i=0;i<n;i++)
        for (int j=0;j<n;j++) {
          if (board[i][j] != 'o' || component[i][j] != -1) continue;
          c++;
          empties = vector<vector<int> >(n,vector<int>(n,0));
          int whitecount = dfs(i,j,c-1);
          int blackcount = 0;
          for (int k=0;k<n;k++)
            for (int l=0;l<n;l++)
              blackcount += empties[k][l];
          if (whitecount >= blackcount) {
            changed = true;
            if (whitecount-blackcount >= maxinc) {
              maxinc = whitecount-blackcount;
              newboard = board;
              for (int k=0;k<n;k++)
                for (int l=0;l<n;l++) {
                  if (empties[k][l])
                    newboard[k][l] = 'x';
                  if (component[k][l] == c-1)
                    newboard[k][l] = '.';
                }
            }
          }
        }
      if (changed) {
        emptycount += maxinc;
        /*
        cout << endl << endl;
        cout << maxinc << endl;
        for (int i=0;i<n;i++)
          cout << board[i] << "  ->  " << newboard[i] << endl;
        cout << endl << endl;
        */
        swap(board,newboard);
      }
    }
    /*
    cout << endl << endl;
    for (int i=0;i<n;i++)
      cout << board[i] << endl;
    cout << endl << endl;
    */
    return emptycount;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"o.o",
 ".o.",
 "o.o"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, maxEmptyCells(Arg0)); }
	void test_case_1() { string Arr0[] = {"...",
 ".o.",
 "..."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, maxEmptyCells(Arg0)); }
	void test_case_2() { string Arr0[] = {"xxxxx",
 "xxoxx",
 "xo.ox",
 "xxoxx",
 "xxxxx"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, maxEmptyCells(Arg0)); }
	void test_case_3() { string Arr0[] = {".xox.",
 ".o.ox",
 "x.o.o",
 "ox.ox",
 ".ox.."}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(3, Arg1, maxEmptyCells(Arg0)); }
	void test_case_4() { string Arr0[] = {"o.o.o",
 ".ox..",
 "oxxxo",
 "..x..",
 "o.o.o"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(4, Arg1, maxEmptyCells(Arg0)); }
	void test_case_5() { string Arr0[] = {"...",
 "...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(5, Arg1, maxEmptyCells(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  FoxAndGo3 ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
