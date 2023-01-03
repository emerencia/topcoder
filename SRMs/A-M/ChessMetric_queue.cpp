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

long long dp[101][101][51];
bool seen[101][101][51];

typedef pair<int,int> PII;
typedef pair<int,PII > PIII;

int dx[] = {-2,-2,-1,-1,-1,-1,-1,0,0,1,1,1,1,1,2,2};
int dy[] = {-1,1,-2,-1,0,1,2,-1,1,-2,-1,0,1,2,-1,1};
const int dn = 16;

class ChessMetric {
 public:
  long long howMany(int size, vector <int> start, vector <int> end, int numMoves) {
    memset(dp,0,sizeof(dp));
    memset(seen,0,sizeof(seen));
    dp[start[0]][start[1]][numMoves] = 1;
    seen[start[0]][start[1]][numMoves] = 1;
    queue<PIII> q;
    q.push(PIII(start[0],PII(start[1],numMoves)));
    while (!q.empty()) {
      PIII p = q.front();
      q.pop();
      int cnum = p.second.second;
      if (!cnum) continue;
      int i = p.first;
      int j = p.second.first;
      long long nways = dp[i][j][cnum];
      for (int k=0;k<dn;k++) {
        int ii = i+dx[k];
        int jj = j+dy[k];
        if (ii >= 0 && ii < size && jj >= 0 && jj < size) {
          dp[ii][jj][cnum-1] += nways;
          if (!seen[ii][jj][cnum-1]) {
            seen[ii][jj][cnum-1] = 1; // this is just so that you only check something
                                      // (position and nr of moves to get there) ONCE.
                                      // The queue enforces that all moves are handled in
                                      // sequence, so that's why when you get to something
                                      // you know that you've already had all the ways to
                                      // get there in the same amount of moves
            q.push(PIII(ii,PII(jj,cnum-1)));
          }
        }
      }
    }
    return dp[end[0]][end[1]][0];
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

