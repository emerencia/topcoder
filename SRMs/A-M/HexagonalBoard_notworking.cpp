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
// 15:43-16:03
// END CUT HERE

int dx[] = {-1,-1,0,1,1,0};
int dy[] = {0,1,1,0,-1,-1};
const int kPos = 6;

class HexagonalBoard {
 public:
  vector<string> board;
  int n;
  int m;
  vector<vector<int> > seen;
  vector<vector<int> > color;
  int bitcount(int n) {
    int r = 0;
    for (int i = n;i;i&=i-1) ++r;
    return r;
  }
  int pickacolor(int i, int j) {
    int r = color[i][j];
    for (int k=0;k<kPos;k++) {
      int ni = i+dx[k];
      int nj = j+dy[k];
      if (ni >= 0 && ni < n && nj >= 0 && nj < m && board[ni][nj] == 'X') {
        if (bitcount(color[ni][nj]) == 1) {
          r &= ~(color[ni][nj]);
        }
      }
    }
    if (!bitcount(r)) cout << "ERROR" << endl;
    return r;
  }
  int dfs(int i, int j) {
    //cout << "dfs " << i << " " << j << endl;
    if (seen[i][j] == color[i][j]) 
      return color[i][j];
    if (bitcount(color[i][j]) != 1)
      color[i][j] = pickacolor(i,j);
    if (!bitcount(color[i][j])) return 3;
    seen[i][j] = color[i][j];
    int r = 1;
    if (bitcount(color[i][j]) == 1)
      for (int k=0;k<kPos;k++) {
        r = 2;
        int ni = i+dx[k];
        int nj = j+dy[k];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && board[ni][nj] == 'X') {
          color[ni][nj] &= ~(color[i][j]);
        }
      }
    for (int k=0;k<kPos;k++) {
      int ni = i+dx[k];
      int nj = j+dy[k];
      if (ni >= 0 && ni < n && nj >= 0 && nj < m && board[ni][nj] == 'X') {
        if (bitcount(color[ni][nj]) == 1)
          r = max(r,dfs(ni,nj));
      }
    }
    return r;
  }
  int minColors(vector <string> board) {
    this->board = board;
    n = board.size();
    m = board[0].size();
    seen = vector<vector<int> >(n,vector<int>(m,-1));
    color = vector<vector<int> >(n,vector<int>(m,7));
    bool f = true;
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++) {
        if (board[i][j] != 'X') continue;
        if (f) {
          color[i][j] = 1;
          f = false;
        }
        if (dfs(i,j) == 3) return 3;
      }
    int r = 0;
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++)
        if (bitcount(color[i][j]) == 1)
          r |= color[i][j];
    return bitcount(r);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"---",
 "---",
 "---"}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, minColors(Arg0)); }
	void test_case_1() { string Arr0[] = {"-X--",
 "---X",
 "----",
 "-X--"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minColors(Arg0)); }
	void test_case_2() { string Arr0[] = {"XXXX",
 "---X",
 "---X",
 "---X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minColors(Arg0)); }
	void test_case_3() { string Arr0[] = {"XX-XX--"
,"-XX-XXX"
,"X-XX--X"
,"X--X-X-"
,"XX-X-XX"
,"-X-XX-X"
,"-XX-XX-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minColors(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  HexagonalBoard ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
