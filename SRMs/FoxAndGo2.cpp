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
// 23:55-00:15
// END CUT HERE

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

class FoxAndGo2 {
 public:
  int n;
  int m;
  vector<string> board;
  vector<vector<int> > whites;
  vector<vector<int> > emptys;
  int whitedfs(int i, int j, int c) {
    if (whites[i][j] != -1) return 0;
    whites[i][j] = c;
    int r = 1;
    for (int k=0;k<4;k++) {
      int ni = i+dx[k];
      int nj = j+dy[k];
      if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
        if (board[ni][nj] == 'o')
          r += whitedfs(ni,nj,c);
        else
          emptys[ni][nj] = 1;
      }
    }
    return r;
  }
  int emptydfs(int i, int j, vector<vector<int> >& esegment, int ec, int c) {
    if (esegment[i][j] != -1) return 1;
    esegment[i][j] = ec;
    // return 0 if there is a field in this component that does not neighbour
    // the c segment
    int r = 1;
    bool isneighbortoc = false;
    for (int k=0;k<4;k++) {
      int ni = i+dx[k];
      int nj = j+dy[k];
      if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
        if (whites[ni][nj] == c)
          isneighbortoc = true;
        if (board[ni][nj] == '.')
          r = min(r,emptydfs(ni,nj,esegment,ec,c));
      }
    }
    if (!isneighbortoc) r = 0;
    return r;
  }
  int maxKill(vector <string> board) {
    this->board = board;
    n = board.size();
    m = board[0].size();
    int r = 0;
    int change = 1;
    while (change) {
      change = r;
      whites = vector<vector<int> >(n,vector<int>(m,-1));
      int c = 0;
      vector<string> newboard = this->board;
      for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) {
          if (this->board[i][j] != 'o' || whites[i][j] != -1) continue;
          // new segment
          c++;
          emptys = vector<vector<int> >(n,vector<int>(m,0));
          int whitecount = whitedfs(i,j,c-1); // color all white
          int ec = 0; // empty segment count
          // now find all empty segments touching the white segment
          vector<vector<int> > esegment(n,vector<int>(m,-1));
          int atmostone = 0;
          for (int ii=0;ii<n;ii++)
            for (int jj=0;jj<m;jj++) {
              if (!emptys[ii][jj] || esegment[ii][jj] != -1) continue;
              ec++;
              atmostone += emptydfs(ii,jj,esegment,ec-1,c-1);
            }
          if (atmostone <= 1) {
            r+= whitecount;
            for (int ii=0;ii<n;ii++)
              for (int jj=0;jj<m;jj++)
                if (whites[ii][jj] == c-1)
                  newboard[ii][jj] = '.';
          }
        }
      change = r-change;
      if (change) swap(this->board,newboard);
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
