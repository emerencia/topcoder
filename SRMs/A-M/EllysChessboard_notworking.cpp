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

class EllysChessboard {
 public:
  int calccost(long long mask, int pos) {
    int xc = pos/8;
    int yc = pos%8;
    int maxd = 0;
    for (int i=0;i<64;i++) {
      if (!(mask&(1LL<<i))) continue;
      maxd = max(maxd,abs((i%8)-yc)+abs((i/8)-xc));
    }
    return maxd;
  }
  int minCost(vector <string> board) {
    // go outwards, for each ring just try all combs
    // the idea is not to keep track of what you have, but just of the min/max of it,
    // that should be your dp state
    long long mask = 0;
    int n = 8;
    int maxd = n/2;
    int cost = 0;
    for (int i=0;i<4;i++) {
      int dist = 2*i+2;
      int mind = maxd-dist+1;
      vector<int> xs;
      vector<int> ys;
      if (board[mind][mind] == '#') { xs.push_back(mind); ys.push_back(mind); } // comma?
      if (board[maxd][maxd] == '#') { xs.push_back(maxd); ys.push_back(maxd); }
      if (board[mind][maxd] == '#') { xs.push_back(mind); ys.push_back(maxd); }
      if (board[maxd][mind] == '#') { xs.push_back(maxd); ys.push_back(mind); }
      for (int j=mind+1;j<maxd;j++) {
        if (board[mind][j] == '#') { xs.push_back(mind); ys.push_back(j); }
        if (board[j][mind] == '#') { xs.push_back(j); ys.push_back(mind); }
        if (board[j][maxd] == '#') { xs.push_back(j); ys.push_back(maxd); }
        if (board[maxd][j] == '#') { xs.push_back(maxd); ys.push_back(j); }
      }
      int mincost = INT_MAX;
      long long minmask = mask;
      /*
      cout << "round: " << i << endl;
      for (int i=0;i<xs.size();i++)
        cout << xs[i] << "," << ys[i] << endl;
      cout << endl;
      */
      for (int j=0;j<xs.size();j++) {
        long long tmask = mask;
        vector<PII> a;
        for(int k=0;k<xs.size();k++) {
          a.push_back(PII(abs(xs[k]-xs[j])+abs(ys[k]-ys[j]),k));
        }
        sort(a.begin(),a.end());
        int tcost = 0;
        for(int k=0;k<a.size();k++) {
          tcost += calccost(tmask,xs[a[k].second]*8+ys[a[k].second]);
          tmask |= (1LL<<(xs[a[k].second]*8+ys[a[k].second]));
        }
        if (tcost < mincost) {
          mincost = tcost;
          minmask = tmask;
        }
      }
      mask = minmask;
      /*
      cout << "mask: " << endl;
      for (int i=0;i<64;i++)
        if (mask&(1LL<<i)) cout << (i/8) << "," << (i%8) << endl;
      cout << endl;
      cout << "Mincost: " << mincost << endl;
      */
      if (mincost != INT_MAX) cost+= mincost;
      maxd++;
    }
    return cost;
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
