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
#include <numeric>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

int ds[2500][2500];

class GameInDarknessDiv1 {
 public:
  vector<string> field;
  int n;
  int m;
  int dfs(int cur, int prev, int steps) {
    if (steps == 0) return 0;
    int i = cur/m;
    int j = cur%m;
    int mx = 0;
    for (int d = 0;d<4;d++) {
      if (i+dx[d] >= 0 && i+dx[d] < n && j+dy[d] >= 0 &&
          j+dy[d] < m && field[i+dx[d]][j+dy[d]] != '#') {
        int ni = (i+dx[d])*m+j+dy[d];
        if (ni == prev) continue;
        mx = max(mx,1+dfs(ni,cur,steps-1));
      }
    }
    return mx;
  }
  string check(vector <string> field) {
    this->field = field;
    memset(ds,-1,sizeof(ds));
    n = field.size();
    m = field[0].size();
    vector<bool> isjunction(n*m,false);
    int apos = 0;
    int bpos = 0;
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++) {
        if (field[i][j] == '#') continue;
        if (field[i][j] == 'A') apos = i*m+j;
        if (field[i][j] == 'B') bpos = i*m+j;
        int c = 0;
        for (int d=0;d<4;d++) {
          if (i+dx[d] >= 0 && i+dx[d] < n && j+dy[d] >= 0 &&
              j+dy[d] < m && field[i+dx[d]][j+dy[d]] != '#') {
            ds[i*m+j][(i+dx[d])*m+j+dy[d]] = 1;
            c++;
          }
        }
        if (c > 2) isjunction[i*m+j] = true;
      }
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++) {
        if (field[i][j] == '#') continue;
        queue<int> q;
        int cur = i*m+j;
        ds[cur][cur] = 0;
        q.push(cur);
        while (!q.empty()) {
          int p = q.front();
          q.pop();
          int ii = p/m;
          int jj = p%m;
          for (int d=0;d<4;d++) {
            if (ii+dx[d] >= 0 && ii+dx[d] < n && jj+dy[d] >= 0 &&
                jj+dy[d] < m && field[ii+dx[d]][jj+dy[d]] != '#') {
              int ni = (ii+dx[d])*m+jj+dy[d];
              if (p == cur || ds[cur][ni] == -1) {
                ds[cur][ni] = ds[cur][p]+ds[p][ni];
                q.push(ni);
              }
            }
          }
        }
      }
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++) {
        if (!isjunction[i*m+j]) continue;
        int c = 0;
        for (int d=0;d<4;d++) {
            if (i+dx[d] >= 0 && i+dx[d] < n && j+dy[d] >= 0 &&
                j+dy[d] < m && field[i+dx[d]][j+dy[d]] != '#') {
              int ni = (i+dx[d])*m+j+dy[d];
              int len = 1+dfs(ni,i*m+j,4);
              if (len > 2) c++;
            }
        }
        if (c >= 3) {
          int cur = i*m+j;
          if (ds[apos][cur]-ds[bpos][cur] >= 2)
            return "Bob wins";
        }
      }
    return "Alice wins";
  }
  
// BEGIN CUT HERE
  // 00:09-00:53
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"A.B..",
 "##.##",
 "##.##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Alice wins"; verify_case(0, Arg1, check(Arg0)); }
	void test_case_1() { string Arr0[] = {"A.B..",
 ".#.#.",
 "#..##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bob wins"; verify_case(1, Arg1, check(Arg0)); }
	void test_case_2() { string Arr0[] = {"#...#",
 ".#A#.",
 "..B..",
 ".#.#.",
 "#...#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Alice wins"; verify_case(2, Arg1, check(Arg0)); }
	void test_case_3() { string Arr0[] = {"##..#",
 "A.#..",
 "#B..#",
 "#.##.",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Alice wins"; verify_case(3, Arg1, check(Arg0)); }
	void test_case_4() { string Arr0[] = {"##################################################",
 "###..................#................#........###",
 "###.################.########.#######.########.###",
 "###.################.########.#######.########.###",
 "###.################.########.#######.########.###",
 "###.################.########.#######.########.###",
 "###.################.########.#######.########.###",
 "###.################.########.#######.########.###",
 "###.################.########.#######.########.###",
 "###.################.########.#######.########.###",
 "###..........#######........#.#######........#.###",
 "############.#######.########.#######.########.###",
 "############.#######.########.#######.########.###",
 "############.#######.########.#######.########.###",
 "############.#######.########.#######.########.###",
 "############.#######.########.#######.########.###",
 "############.#######.########.#######.########.###",
 "############.#######.########.#######.########.###",
 "############.#######.########.#######.########.###",
 "###B.........#######..........#######..A.......###",
 "##################################################"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bob wins"; verify_case(4, Arg1, check(Arg0)); }
	void test_case_5() { string Arr0[] = {"###.#",
 "###..",
 "A..B#",
 "###..",
 "###.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Alice wins"; verify_case(5, Arg1, check(Arg0)); }
	void test_case_6() { string Arr0[] = {".....#.##.##.#.#",
 ".###.#.##.##....",
 "#......B#...#.#.",
 "#.#A#.#.#.#..##.",
 "...#..#....#...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Alice wins"; verify_case(6, Arg1, check(Arg0)); }
	void test_case_7() { string Arr0[] = {"...#.....###....#.....#...#.#.",
 ".#..#.##..#..#.#..###...#.....",
 "..#..#..#...#.#..#....##.#.###",
 ".#.#...###.#..#.#..###....#...",
 "...##.###..#.#..#.#...#.##..#.",
 ".#..#..#..#...#.#.#.#.#..#.#..",
 "..#..#.#.#..#..##.#.#..#.##..#",
 ".#.###.#.##..#.....A##......#.",
 "#.........#.#..#.###..###.#...",
 "..###.#.#.#..#.#....#.....#.#.",
 ".#..#.#.####.#..#.#..#.#.###..",
 "..#...#...#..#.#...#.#..#.#..#",
 "#..#.#..#.#.#..###.#.#.#....#.",
 "..#..##.##...#....#..#.#.####.",
 "#..#...#...#..#.#..###.#......",
 "#.#.##...#..#..#.#....#..#.#.#",
 "....#..##.#..#....#.#.#.#...#.",
 ".#.#..#....#.#.##..#..##..#.#.",
 "..##.#..##.#..#..#..#...#.#...",
 "#.#..##..#..#..#..#..##.#.#.#.",
 "..#.#.#.#.#..#...##.#...#..#..",
 ".##.....#..#.#.#.#..#.##.#..#.",
 "...#.#.#..#..#.###.#..#...#.#.",
 ".#..#....#..#.#...###.#.#..#..",
 ".#.#.#####.#....#..#..#.##.#.#",
 ".#...#......#.#..###B#....#...",
 "..###..####.#..#.#...#.#.#..#.",
 "#.#..#.#..#.#.#..#.#..#....#..",
 "..#.##..#.#.#.####..#.#####..#",
 "#.....#...#.#......#.......#.."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bob wins"; verify_case(7, Arg1, check(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  GameInDarknessDiv1 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
