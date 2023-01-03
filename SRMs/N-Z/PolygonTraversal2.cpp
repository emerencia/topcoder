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
int dp[13][1<<13];

class PolygonTraversal2 {
 public:
  int count(int N, vector <int> points) {
    int mask = (1<<(points[0]-1));
    for (int i =0;i+1<points.size();i++) {
      mask |= (1<<(points[i+1]-1));
    }
    mask |= (1<<(points.back()-1));
    
    memset(dp,0,sizeof(dp));
    dp[points.back()-1][mask] = 1;
    for (int i=0;i<(1<<N);i++)
      for (int j=0;j<N;j++) {
        if (!dp[j][i]) continue;
        for (int k=0;k<N;k++) {
          if (i&(1<<k)) continue;
          bool ok1 = false, ok2 = false;
          // you know you crossed it at some point because
          // points of the collection appear on both sides of the line,
          // so somewhere there was a crossing
          for (int l=(k+1)%N;l!=j;l=(l+1)%N) if (i&(1<<l)) { ok1 = true; break; }
          for (int l=(j+1)%N;l!=k;l=(l+1)%N) if (i&(1<<l)) { ok2 = true; break; }
          if (ok1 && ok2) dp[k][i|(1<<k)] += dp[j][i];
        }
      }
    int r = 0;
    for (int i=0;i<N;i++) {
      if (abs(i-points[0]+1) <= 1 || abs(i-points[0]+1) == N-1) continue;
      r+= dp[i][(1<<N)-1];
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {1, 3, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; int Arr1[] = {1, 4, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 7; int Arr1[] = {2, 4, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arr1[] = {1, 2, 3, 4, 6, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 11; int Arr1[] = {1, 5, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1412; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  PolygonTraversal2 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
