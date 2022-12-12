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
// 555 1000
// how to do (muddyCount+1) subsets that sum up to N-muddyCount?)
const int kMod = 555555555;

int was[1000][1000][2][2];
int res[1000][1000][2][2];

class MuddyRoad2 {
 public:
  int go(int x,int y, int a,int b) { // he  is just counting modulo 3 with those bits
    if (y < 0) return 0;
    if (x == 1) return int(y == 0 && a == b);
    if (was[x][y][a][b]) return res[x][y][a][b];
    was[x][y][a][b] = 1;
    return res[x][y][a][b] = (go(x-1,y,b,a^b) + go(x-1,y-1,b,0))%kMod;
  }
  // a = previousonenotdivisiblebythree
  // b = currentnotdivisiblebythree
  // when you jump a segment, the next segment HAS to be divisible by 3
  // every time go one down, and simply count the number of thing that have
  // segments that are divisible by 3
  // you don't need to know that they can do different jumps of lenghts,
  // all you need to know is that there is an even amount of possible
  // jumps if the segment lengths are factors of 3

  int theCount(int n, int m) {
    memset(was, 0, sizeof(was));
    return go(n-1,m,0,1);
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, theCount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 2; verify_case(1, Arg2, theCount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 4; int Arg2 = 65; verify_case(2, Arg2, theCount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 314; int Arg1 = 78; int Arg2 = 498142902; verify_case(3, Arg2, theCount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 555; int Arg1 = 222; int Arg2 = 541606281; verify_case(4, Arg2, theCount(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  MuddyRoad2 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
