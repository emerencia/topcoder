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

class ZigZag {
 public:
  int longestZigZag(vector <int> sequence) {
    int dp[2][51];
    fill(&dp[0][0],&dp[2][0],1);
    int n = sequence.size();
    for (int i=0;i<n;i++)
      for (int j=0;j<i;j++) {
        if (sequence[j] > sequence[i])
          dp[0][i] = max(dp[0][i],1+dp[1][j]);
        else if (sequence[j] < sequence[i])
          dp[1][i] = max(dp[1][i],1+dp[0][j]);
      }
    return max(dp[0][n-1],dp[1][n-1]);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 7, 4, 9, 2, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, longestZigZag(Arg0)); }
	void test_case_1() { int Arr0[] = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, longestZigZag(Arg0)); }
	void test_case_2() { int Arr0[] = { 44 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, longestZigZag(Arg0)); }
	void test_case_3() { int Arr0[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, longestZigZag(Arg0)); }
	void test_case_4() { int Arr0[] = { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(4, Arg1, longestZigZag(Arg0)); }
	void test_case_5() { int Arr0[] = { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 
600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 
67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 
477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 
249, 22, 176, 279, 23, 22, 617, 462, 459, 244 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; verify_case(5, Arg1, longestZigZag(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ZigZag ___test;
  ___test.run_test(-1);
}
// END CUT HERE
