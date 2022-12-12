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
#include <numeric>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;

long long comb[51][51];
long long dp[51][51];
long long pd[51][51];

class Excavations2 {
 public:
  long long count(vector <int> kind, vector <int> found, int K) {
    vector<int> kcount(51,0);
    for (int i=0;i<kind.size();i++)
      kcount[kind[i]]++;
    vector<int> fcount(51,0);
    for (int i=0;i<found.size();i++)
      fcount[found[i]]++;
    for (int i=0;i<=50;i++) {
      comb[i][0] = comb[i][i] = 1;
      for (int j=1;j<i;j++)
        comb[i][j] = (comb[i-1][j]+comb[i-1][j-1]);
    }
    memset(dp,0,sizeof(dp));
    for (int i=0;i<51;i++)
      if (fcount[i])
        for (int j=1;j<=K && j <= kcount[i];j++)
          dp[i][j] = comb[kcount[i]][j];
    memset(pd,0,sizeof(pd));
    pd[0][0] = 1;
    int c = 0;
    for (int j=0;j<51;j++) { // j is type
      if (fcount[j]) {
        c++;
        for (int k=0;k<=K;k++) // k is amount
          for (int l=1;l<=kcount[j] && k+l<=K;l++) // l is amount of this
            pd[c][k+l] += pd[c-1][k]*dp[j][l];
      }
    }
    return pd[c][K];
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; long long Arg3 = 1LL; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1, 2, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; long long Arg3 = 4LL; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 2, 1, 1, 2, 3, 4, 3, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; long long Arg3 = 6LL; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 21; long long Arg3 = 5567902560LL; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  Excavations2 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
