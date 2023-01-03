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
#include <limits>
#include <cstring>
#include <numeric>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
// BEGIN CUT HERE
const int toTest = -1;
// 21:59 start
// END CUT HERE

int kOffset = 150000;
int dp[300000];

class CubeRoll {
 public:
  int goalPos;
  int mnn;
  void rec(int cur,int steps) {
    if (dp[cur] == -2) return;
    if (dp[cur] != -1 && dp[cur] <= steps) return;
    dp[cur] = steps;
    if (cur == goalPos) {
      if (mnn == -1 || mnn > steps)
        mnn = steps;
      return;
    }
    for (int i=1;i*i<300000;i++) {
      if (cur+i*i >= 0 && cur + i*i < 300000 && dp[cur+i*i] != -2 && (dp[cur+i*i] == -1 || dp[cur+i*i] > steps+1))
        rec(cur+i*i,steps+1);
      if (cur-i*i >= 0 && cur - i*i < 300000 && dp[cur-i*i] != -2 && (dp[cur-i*i] == -1 || dp[cur-i*i] > steps+1))
        rec(cur-i*i,steps+1);
    }
  }
  int getMinimumSteps(int initPos, int GoalPos, vector <int> holePos) {
    goalPos = GoalPos+kOffset;
    memset(dp,-1,sizeof(dp));
    for (int i=0;i<holePos.size();i++)
      dp[holePos[i]+kOffset] = -2;
    mnn = -1;
    rec(kOffset+initPos,0);
    return mnn;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(0, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 36; int Arg1 = 72; int Arr2[] = {300, 100, 200, 400}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(1, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 21; int Arr2[] = {38,45}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 98765; int Arg1 = 4963; int Arr2[] = {10,20,40,30}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(3, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 68332; int Arg1 = 825; int Arr2[] = {99726,371,67,89210}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(4, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  CubeRoll ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
