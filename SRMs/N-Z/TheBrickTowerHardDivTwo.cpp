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
// 554 1000

const unsigned int kMod = 1234567891;
unsigned int dp[2][8][256];

class TheBrickTowerHardDivTwo {
 public:
  int find(int C, int K, int H) {
    memset(dp,0,sizeof(dp));
    unsigned int res = 0;
    for (int a=0;a<C;a++)
      for (int b=0;b<C;b++)
        for (int c=0;c<C;c++)
          for (int d=0;d<C;d++) {
            int t = 0;
            t+= int(a == b);
            t+= int(b == c);
            t+= int(c == d);
            t+= int(d == a);
            if (t <= K) {
              dp[0][t][a|(b<<2)|(c<<4)|(d<<6)] = 1;
              res++;
            }
          }
    for (int i=0;i<4*(H-1);i++) {
      // i describes the index of every block in the tower of max length
      // so this loop runs once per block of every tower
      int cur = i%2; // just to indicate that we only save one layer state
      int next = 1-cur;
      memset(dp[next],0,sizeof(dp[next]));
      for (int j=0;j<=K;j++) {
        for (int k=0;k<256;k++) {
          if (!dp[cur][j][k]) continue;
          for (int c=0;c<C;c++) {
            int add = 0;
            add += c == k%4;
            if ((i%4) != 0) add+= c == (k>>6)%4;
            if ((i%4) == 3) add+= c == (k>>2)%4;
            if (j+add <= K) {
              dp[next][j+add][(k>>2)|(c<<6)] += dp[cur][j][k];
              dp[next][j+add][(k>>2)|(c<<6)] %= kMod;
            }
          }
        }
      }
      if (i%4 == 3) { // full layer
        for (int j=0;j<=K;j++)
          for (int k=0;k<256;k++)
            if (dp[next][j][k])
              res = (res+dp[next][j][k])%kMod;
      }
    }
    return res;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 2; int Arg3 = 4; verify_case(0, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 7; int Arg2 = 19; int Arg3 = 1; verify_case(1, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 1; int Arg3 = 14; verify_case(2, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 47; int Arg3 = 1008981254; verify_case(3, Arg3, find(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  TheBrickTowerHardDivTwo ___test;
  ___test.run_test(-1);
}
// END CUT HERE
