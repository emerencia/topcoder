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

long long dp[2][101][101];

int dx[] = {-2,-2,-1,-1,-1,-1,-1,0,0,1,1,1,1,1,2,2};
int dy[] = {-1,1,-2,-1,0,1,2,-1,1,-2,-1,0,1,2,-1,1};

class ChessMetric {
 public:
  long long howMany(int size, vector <int> start, vector <int> end, int numMoves) {
    memset(dp,0,sizeof(dp));
    int cur = 0, next = 1;
    dp[cur][start[0]][start[1]] = 1;
    for (int k=0;k<numMoves;k++) {
      memset(dp[next],0,sizeof(dp[next]));
      for (int i=0;i<size;i++)
        for (int j=0;j<size;j++)
          for (int d=0;d<16;d++) {
            int ii = i+dx[d];
            int jj = j+dy[d];
            if (ii >= 0 && ii < size && jj >= 0 && jj < size)
              dp[next][ii][jj] += dp[cur][i][j];
          }
      swap(cur,next);
    }
    return dp[cur][end[0]][end[1]];
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; long long Arg4 = 1LL; verify_case(0, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; long long Arg4 = 1LL; verify_case(1, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; long long Arg4 = 0LL; verify_case(2, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 3; int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; long long Arg4 = 5LL; verify_case(3, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 100; int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,99}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 50; long long Arg4 = 243097320072600LL; verify_case(4, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ChessMetric ___test;
  ___test.run_test(-1);
}
// END CUT HERE

