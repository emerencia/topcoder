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
using namespace std;

class NoRepeatPlaylist {
 public:
  vector<vector<long long> > dp;
  int m;
  long long rec(int idx,int played,int unplayed) {
    if (idx == 0) {
      if (unplayed == 0) return 1;
      return 0;
    }
    if (dp[played][idx] != -1) return dp[played][idx];
    long long r = 0;
    if (unplayed > 0) {
      r+= unplayed * rec(idx-1,played+1,unplayed-1);
      r=r%1000000007;
    }
    if (played > m) {
      r+= (played-m) * rec(idx-1,played,unplayed);
      r=r%1000000007;
    }
    dp[played][idx] = r;
    return r;
  }
  int numPlaylists(int N, int M, int P) {
    // n songs, m = between, p = songs listened
    m = M;
    dp = vector<vector<long long> >(101,vector<long long>(101,-1));
    return rec(P,0,N);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 3; int Arg3 = 1; verify_case(0, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 3; int Arg3 = 0; verify_case(1, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 3; int Arg3 = 6; verify_case(2, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 0; int Arg2 = 4; int Arg3 = 24; verify_case(3, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 4; int Arg3 = 2; verify_case(4, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 50; int Arg1 = 5; int Arg2 = 100; int Arg3 = 222288991; verify_case(5, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  NoRepeatPlaylist ___test;
  ___test.run_test(-1);
}
// END CUT HERE
