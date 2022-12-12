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

const int kMod = 1000000009;
long long mem[51][51];

class MountainsEasy {
 public:
  void startmountain(vector<vector<bool> >& g, int ii, int jj) {
    if (ii == g.size() || jj == g[0].size() || jj < 0) return;
    if (!g[ii][jj]) {
      g[ii][jj] = true;
      startmountain(g,ii+1,jj-1);
      startmountain(g,ii+1,jj);
      startmountain(g,ii+1,jj+1);
    }
  }
  long long rec(int extra, int forced, int n) {
    long long &r = mem[forced][n];
    if (r != -1) return r;
    if (!n) return forced == 0;
    long long res = 0;
    if (forced) res = (forced*rec(extra+1,forced-1,n-1))%kMod;
    if (extra) res = (res + (extra*rec(extra,forced,n-1))%kMod)%kMod;
    return r = res;
  }
  int countPlacements(vector <string> picture, int N) {
    memset(mem,-1,sizeof(mem));
    vector<vector<bool> > g(picture.size(),vector<bool>(picture[0].size(),false));
    // true = isblack
    int d = 0;
    int bc = 0;
    for (int i=0;i<picture.size();i++)
      for (int j=0;j<picture[0].size();j++) {
        if (picture[i][j] == 'X' && !g[i][j]) {
          d++;
          startmountain(g,i,j);
        }
        if (picture[i][j] == 'X') bc++;
      }
    long long b = bc-d;
    return rec(b,d,N);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"X.",
 "XX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, countPlacements(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"X.",
 "XX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 5; verify_case(1, Arg2, countPlacements(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"X.X",
 "XXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; verify_case(2, Arg2, countPlacements(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"X.X",
 "XXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 24; verify_case(3, Arg2, countPlacements(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"......",
 "X..X..",
 "XXXXXX",
 "XXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 6; verify_case(4, Arg2, countPlacements(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"......",
 "X..X..",
 "XXXXXX",
 "XXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 300; verify_case(5, Arg2, countPlacements(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"....X...X..",
 "...XXX.XXX.",
 "XXXXXXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 764632413; verify_case(6, Arg2, countPlacements(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  MountainsEasy ___test;
  ___test.run_test(-1);
}
// END CUT HERE
