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

int dist[64][64];
map<long long,int> mem;

class EllysChessboard {
 public:
  int n;
  int bitcount(long long t) {
    t = (t&0x5555555555555555LL) + ((t>>1)&0x5555555555555555LL);
    t = (t&0x3333333333333333LL) + ((t>>2)&0x3333333333333333LL);
    t = (t&0x0f0f0f0f0f0f0f0fLL) + ((t>>4)&0x0f0f0f0f0f0f0f0fLL);
    t = (t&0x00ff00ff00ff00ffLL) + ((t>>8)&0x00ff00ff00ff00ffLL);
    t = (t&0x0000ffff0000ffffLL) + ((t>>16)&0x0000ffff0000ffffLL);
    t = (t&0x00000000ffffffffLL) + ((t>>32)&0x00000000ffffffffLL);
    return t;
  }
  int distancebetween(int a,int b) {
    return abs(a/n-b/n)+abs(a%n-b%n);
  }
  int rec(long long mask) {
    if (bitcount(mask) == 0) return 0;
    if (bitcount(mask) == 1) return 0;
    if (mem.count(mask)) return mem[mask];
    int r = INT_MAX;
    set<int> a;
    int mdist = 0;
    for (int i=0;i<n*n;i++) {
      if (!(mask&(1LL<<i))) continue;
      for (int j=0;j<n*n;j++) {
        if (!(mask&(1LL<<j))) continue;
        if (dist[i][j] > mdist) {
          a.clear();
          a.insert(i); a.insert(j);
          mdist = dist[i][j];
        } else if (dist[i][j] == mdist) {
          a.insert(i); a.insert(j);
        }
      }
    }
    for (set<int>::iterator i=a.begin();i!=a.end();i++) {
      r = min(r,mdist+rec(mask^(1LL<<(*i))));
    }
    return mem[mask] = r;
  }
  int minCost(vector <string> board) {
    n = 8;
    for (int i=0;i<64;i++)
      for (int j=0;j<64;j++)
        dist[i][j] = distancebetween(i,j);
    long long mask=0;
    for (int i=0;i<board.size();i++)
      for (int j=0;j<board[0].size();j++)
        if (board[i][j]=='#')
          mask |= (1LL<<(i*n+j));
    int r = rec(mask);
    cout << mem.size() << endl;
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
