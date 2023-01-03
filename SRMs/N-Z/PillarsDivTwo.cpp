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

double dp[51][2][101];
class PillarsDivTwo {
 public:
   vector<int> h;
   int ww;
   double rec(int idx, int md, int ph) {
     if (dp[idx][md][ph] != -1.0) return dp[idx][md][ph];
     if (idx == h.size()) return dp[idx][md][ph] = 0.0;
     int hh = h[idx];
     if (idx%2 == md) hh = 1;
     double a = sqrt(abs(ph-hh)*abs(ph-hh)+ww*ww);
     return dp[idx][md][ph] = a+max(rec(idx+1,1-md,hh),rec(idx+1,md,hh));
   }
  double maximalLength(vector <int> height, int w) {
    // start at odd
    for (int i=0;i<51;i++)
      for (int j=0;j<2;j++)
        for (int k=0;k<101;k++)
          dp[i][j][k] = -1.0;
    ww = w;
    h = height;
    return max(rec(1,0,1),rec(1,1,height[0]));
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 5.656854249492381; verify_case(0, Arg2, maximalLength(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; double Arg2 = 300.0; verify_case(1, Arg2, maximalLength(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {100,2,100,2,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 396.32310051270036; verify_case(2, Arg2, maximalLength(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2,1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 3.82842712474619; verify_case(3, Arg2, maximalLength(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  PillarsDivTwo ___test;
  ___test.run_test(-1);
}
// END CUT HERE
