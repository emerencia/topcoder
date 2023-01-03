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
// 20:14 start
// 20:41 done
// 20:45 passed all tests
// END CUT HERE

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
bool seen[51][51][1<<9];

class SlimeXResidentSlime {
 public:
  vector<string> field;
  int n;
  int m;
  vector<vector<int> > myseen;
  int bitcount(int n) {
    int r = 0;
    for (int i=n;i;i&=i-1) ++r;
    return r;
  }
  int dfs(int sx,int sy,int ex, int ey, int steps) {
    if (sx == ex && sy == ey) return 0;
    int r = 5000;
    if (myseen[sx][sy] > steps) {
      myseen[sx][sy] = steps;
      for (int k = 0;k<4;k++) {
        int ni = sx+dx[k];
        int nj = sy+dy[k];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && field[ni][nj] != '#') {
          r = min(r,dfs(ni,nj,ex,ey,steps+1));
        }
      }
    }
    return 1+r;
  }
  int exterminate(vector <string> Field) {
    field = Field;
    n = field.size();
    m = field[0].size();
    int ns = 0;
    int sx = 0, sy = 0;
    vector<vector<int> > slimecode(n,vector<int>(m,-1));
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++) {
        if (field[i][j]-'0' > 0 &&  field[i][j]-'0' <= 9) {
          slimecode[i][j] = ns++;
        }
        if (field[i][j] == '$') {
          sx = i;
          sy = j;
        }
      }
    if (ns > 9) return -1;
    if (!ns) return 0;
    int mmin = 1000000;
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++) {
        if (slimecode[i][j] == -1) continue;
        memset(seen,0,sizeof(seen));
        queue<PII> q;
        queue<PII> r;
        q.push(PII(i,j));
        r.push(PII(0,field[i][j]-'0'));
        int minsteps = -1;
        while (!q.empty()) {
          PII p = q.front(); q.pop();
          PII e = r.front(); r.pop();
          int mask = e.first;
          int stepsleft = e.second;
          if (slimecode[p.first][p.second] != -1) {
            if (field[p.first][p.second]-'0' >= ns-bitcount(mask))
              mask |= 1<<slimecode[p.first][p.second];
          }
          if (mask == (1<<ns)-1) {
            minsteps = field[i][j]-'0'-stepsleft;
            break;
          }
          stepsleft--;
          if (stepsleft == 0) continue;
          if (seen[p.first][p.second][mask]) continue;
          seen[p.first][p.second][mask] = 1;
          for (int k=0;k<4;k++) {
            int ni = p.first+dx[k];
            int nj = p.second+dy[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && field[ni][nj] != '#') {
              q.push(PII(ni,nj));
              r.push(PII(mask,stepsleft));
            }
          }
        }
        if (minsteps != -1) {
          myseen = vector<vector<int> >(n,vector<int>(m,1000000));
          int mminsteps = dfs(sx,sy,i,j,0);
          if (mminsteps < 5000) {
            mminsteps += minsteps;
            if (mminsteps < mmin) {
              mmin = mminsteps;
            }
          }
        }
      }
    return (mmin == 1000000 ? -1 : mmin);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6();  }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = 
{
"#1$",
".2."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, exterminate(Arg0)); }
	void test_case_1() { string Arr0[] = {
"$",
"1",
"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, exterminate(Arg0)); }
	void test_case_2() { string Arr0[] = {
"$124"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, exterminate(Arg0)); }
	void test_case_3() { string Arr0[] = {"$.#2"
,"#..1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, exterminate(Arg0)); }
  	void test_case_4() { string Arr0[] = {"$..............", "##############.", "...............", ".##############", "...............", "####.####.####.", "..........#....", ".........#9#...", ".........78....", ".......456.....", ".....123.......", "###............"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 55; verify_case(4, Arg1, exterminate(Arg0)); }
  	void test_case_5() { string Arr0[] = {"$4#4", "...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(5, Arg1, exterminate(Arg0)); }
    void test_case_6() { string Arr0[] = {".##.###..#....##.#.#......##...#.#....#####.#....#", "####..#####.####..#....###.#..######.##.#.#.##..##", ".##.#####.#.#####.#.###....#.##..##.##.#...######.", ".#.####.#..#.###.#.#........#.##.#.#..###..#.####.", "###.#.##....#..#..#..#..###.#.####..##..#.#.#.#...", "....##.###...#####.#..#.###.##..####..#.##.#..###.", "######.##.#.##...#..#.#####..#..##.#.#.##.##.#....", "####.###..##.##.##..#...##.#.###.#.####.#.##...###", "#.....#.###..#...#.###....#..#.#.#.##.#####.#....#", "###.###.##.#..#..###.###..##...##..#.##.#.####..#.", "..#....#..#..##.##...#....####.......#.####..#..##", ".#.....####.#.##.#.#.#..##.#.####....####.$.###.##", "#####..#.#.##..#...##.#..##...##.##.##.#....##.###", "#.####...###.##.#..#.#....#...#.#.#..###..#..##..#", ".#.##.#...########.#.......#.##..###.###.#.#.##.#.", ".##....#...##..##...#.#...#..#.##.##..#.....#.##..", "..##...###..#..#####..79##..#.#.#..#......#.###.#.", ".####...##...#.##..#.#7#.#.#.###....######.....###", "#..##.###....#..###...4.###.#####.##.##.#.#..##...", "##...#..###..#.#.#.#.#5..#.#.....###..#.#..#...###", "..#####.#.####..##....6...###...###...#..###.#.###", "#.####.#..##....######7.##.#.#...#..#..##..#.#...#", "...##.#..###....##.#.98..#..#.#..#..##.#.....#...#", ".....#...#.#..###..##.##..#..#.#..#.##.###.####.#.", ".#.#.#.#.####....#.##...#####.###.#..#..#.###....#", ".#...#...#.....##.#..#.#.#.#.###..#...#.##.#..#.##", "#..##.#.##.##.####.##.##.###...#.#...####..#.###.#", "#.##...###.##....####.##.###.##..##.#.#.#.#.#.....", ".......###...#.####....#..###..#.#.####...##.#####", "####..#..######........##.######.####.#...#.....##", "#######..#####...##..#.#...##..##..##.##.##.#...#.", "##..###.....#.#######..###...####....#.####.....##", "##.##...#.###.##.#.###..##....###....###..#####.#.", "#...#.###..#....#.###......#.#..##.#..##.....#.#.#", ".#.#.##..#..#..######.#.....###.#.#..#.#####...#..", "#.##.#.###.####.###..##.#..####.....##.##.###...##", "#.....##.##....#######...#...#..#.##.#.#.##....###", "###.#.#.##.....#.#..###.#.#..#...##.##.###...##..#", "#.....##.#.#.####.#....##..##.#....##.##...#######", "..#...##..#.#####...#.#.##...##....#.#..#.#.#....#", "#.###...#####.##..##.##..##.###.####.#..#.#..#...#", "####.###...####.#..#..#....#.######.#.##.......#.#", "..#...#.....###....#####.##.##..#.#..#..##.##..#.#", ".###..##.#.#...###.#..#....##..#.#.#..#.#.##.#..##", ".####....#...##.##...###.##...########.#.....##.##", ".#.#######.###...#.....#.##..#.#..#####.#.##..##..", "#.##..#.##.##.####.#.#.#####...##.#.#.##.###...##.", ".###.#.#.#......####..##.##.#.#.#####.###.##...#..", ".#.#.#....#..#.#...#.#.....###...#...#.###......##", "#.##.###..###..#.#...#.######.#.##...##.#..#..####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 74; verify_case(6, Arg1, exterminate(Arg0)); }
    
// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  SlimeXResidentSlime ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
