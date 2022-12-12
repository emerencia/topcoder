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

long long dp[2][103][103];

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

const int kMod = 1e9+7;

class WolfPackDivTwo {
 public:
  int calc(vector <int> x, vector <int> y, int M) {
    memset(dp,0,sizeof(dp));
    int n = x.size();
    dp[0][51][51] = 1;// the wolves all walk the same path...
    int cur = 0, next = 1;
    for (int m=0;m<M;m++) {
      memset(dp[next],0,sizeof(dp[next]));
      for (int k=0;k<4;k++)
        for (int i=1;i<102;i++)
          for (int j=1;j<102;j++)
            dp[next][i+dx[k]][j+dy[k]] = (dp[next][i+dx[k]][j+dy[k]]+
                                             dp[cur][i][j])%kMod;
      swap(cur,next);
    }
    long long r = 0;
      for (int i=0;i<153;i++)
        for (int j=0;j<153;j++) {
          long long r1 = 1;
          for (int k=0;k<n;k++) {
            if (i >= x[k] && j >= y[k] && i-x[k] < 103 && j-y[k] < 103)
              r1 = (r1*dp[cur][i-x[k]][j-y[k]])%kMod;
            else { r1 = 0; break; }
          }
          r = (r+r1)%kMod;
        }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; verify_case(0, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 0; verify_case(1, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 4; verify_case(2, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {7,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 2; verify_case(3, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,4,6,6,6,6,6,6,6,6,6,6,8,8,8,8,8,8,8,8,8,8}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; int Arg3 = 0; verify_case(4, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,4,6,6,6,6,6,6,6,6,6,6,8,8,8,8,8,8,8,8,8,8}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 31; int Arg3 = 573748580; verify_case(5, Arg3, calc(Arg0, Arg1, Arg2)); }
  void test_case_6() { int Arr0[] = {20,30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20,30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 50; int Arg3 = 138410702; verify_case(6, Arg3, calc(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  WolfPackDivTwo ___test;
  ___test.run_test(-1);
}
// END CUT HERE
