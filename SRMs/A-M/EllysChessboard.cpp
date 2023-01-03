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

int dp[15][15][16][16];

int srs[] = {-1,0,0,0};
int nrs[] = {1,0,1,0};
int scs[] = {0,0,0,-1};
int ncs[] = {0,1,0,1};

class EllysChessboard {
 public:
  int n;
  vector<PII> stone;
  int bitcount(long long t) {
    t = (t&0x5555555555555555LL) + ((t>>1)&0x5555555555555555LL);
    t = (t&0x3333333333333333LL) + ((t>>2)&0x3333333333333333LL);
    t = (t&0x0f0f0f0f0f0f0f0fLL) + ((t>>4)&0x0f0f0f0f0f0f0f0fLL);
    t = (t&0x00ff00ff00ff00ffLL) + ((t>>8)&0x00ff00ff00ff00ffLL);
    t = (t&0x0000ffff0000ffffLL) + ((t>>16)&0x0000ffff0000ffffLL);
    t = (t&0x00000000ffffffffLL) + ((t>>32)&0x00000000ffffffffLL);
    return t;
  }
  int calccost(long long curmask, long long addmask) {
    int r = 0;
    curmask |= addmask;
    for (int i=0;i<stone.size();i++) {
      if (!(addmask&(1LL<<i))) continue;
      int mx = 0;
      for (int j=0;j<stone.size();j++) {
        if (!(curmask&(1LL<<j))) continue;
        mx = max(mx,max(abs(stone[i].first-stone[j].first),
                        abs(stone[i].second-stone[j].second)));
      }
      r+= mx;
    }
    return r;
  }
  long long insidemask(int sr,int sc,int nr,int nc) {
    if (sr < 0 || sc < 0 || sr+nr > n || sc+nc > n) return 0;
    long long r = 0;
    for (int i=0;i<stone.size();i++) {
      if (stone[i].first >= sr && stone[i].first < sr+nr &&
          stone[i].second >= sc && stone[i].second < sc+nc)
        r |= (1LL<<i);
    }
    return r;
  }
  int minCost(vector <string> board) {
    n = 15;
    fill(&dp[0][0][0][0],&dp[n][0][0][0],10000);
    dp[0][0][n][n] = 0;
    int r = INT_MAX;
    stone = vector<PII>();
    for (int i=0;i<board.size();i++)
      for (int j=0;j<board[0].size();j++)
        if (board[i][j] == '#')
          stone.push_back(PII(i+j,i-j+7));
    for (int sr=0;sr<n;sr++)
      for (int nr=n-sr;nr>0;nr--)
        for (int sc=0;sc<n;sc++)
          for (int nc=n-sc;nc>0;nc--) {
            long long curmask = insidemask(sr,sc,nr,nc);
            for (int k=0;k<4;k++) {
              long long omask = insidemask(sr+srs[k],sc+scs[k],nr+nrs[k],nc+ncs[k]);
              if (omask) {
                int addedcost = calccost(curmask,(curmask^omask));
                dp[sr][sc][nr][nc] = min(dp[sr][sc][nr][nc],
                    dp[sr+srs[k]][sc+scs[k]][nr+nrs[k]][nc+ncs[k]]+addedcost);
              }
            }
            if (bitcount(curmask) < 2)
              r = min(r,dp[sr][sc][nr][nc]);
          }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"........",
 "........",
 "...#....",
 ".#......",
 ".......#",
 "........",
 "........",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(0, Arg1, minCost(Arg0)); }
	void test_case_1() { string Arr0[] = {"........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, minCost(Arg0)); }
	void test_case_2() { string Arr0[] = {".#......",
 "........",
 "..#..#.#",
 "...#..#.",
 "........",
 "...#...#",
 "...#...#",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; verify_case(2, Arg1, minCost(Arg0)); }
	void test_case_3() { string Arr0[] = {"##..####",
 "#####..#",
 "..#.#...",
 "#..##.##",
 ".#.###.#",
 "####.###",
 "#.#...#.",
 "##....#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 275; verify_case(3, Arg1, minCost(Arg0)); }
	void test_case_4() { string Arr0[] = {"########",
 "########",
 "########",
 "########",
 "########",
 "########",
 "########",
 "########"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 476; verify_case(4, Arg1, minCost(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  EllysChessboard ___test;
  ___test.run_test(-1);
}
// END CUT HERE
