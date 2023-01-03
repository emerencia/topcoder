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

const int kMod = 1234567891;
int dp[48][8][4][4][4][4];

class TheBrickTowerHardDivTwo {
 public:
  int c;
  int rec(int h,int k,int p1, int p2,int p3, int p4) {
    int& ret = dp[h][k][p1][p2][p3][p4];
    if (ret != -1) return ret;
    if (h == 0) return ret = 1;
    long long r = 1;
    for (int np1=0;np1<c;np1++)
      for (int np2=0;np2<c;np2++)
        for (int np3=0;np3<c;np3++)
          for (int np4=0;np4<c;np4++) {
            int d = 0;
            d+= int(np1==p1)+int(np1==np2);
            d+= int(np2==p2)+int(np2==np3);
            d+= int(np3==p3)+int(np3==np4);
            d+= int(np4==p4)+int(np4==np1);
            if (d > k) continue;
            r = (r + rec(h-1,k-d,np1,np2,np3,np4))%kMod;
          }
    return ret = int(r);
  }
  int find(int C, int K, int H) {
    c = C;
    memset(dp,-1,sizeof(dp));
    long long r = 0;
    for (int np1=0;np1<c;np1++)
      for (int np2=0;np2<c;np2++)
        for (int np3=0;np3<c;np3++)
          for (int np4=0;np4<c;np4++) {
            int d = 0;
            d+= int(np1==np2);
            d+= int(np2==np3);
            d+= int(np3==np4);
            d+= int(np4==np1);
            if (d > K) continue;
            r = (r + rec(H-1,K-d,np1,np2,np3,np4))%kMod;
          }
    return int(r);
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
