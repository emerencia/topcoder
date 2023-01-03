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

const int kOffset = 150000;
const int kInf = 1000000;
int dp[300000];

class CubeRoll {
 public:
  int bfs(int init, int goal, int left, int right) {
    queue<int> q;
    q.push(init);
    vector<int> seen(right+1,kInf);
    seen[init] = 0;
    while (!q.empty()) {
      int p = q.front();q.pop();
      int steps = seen[p];
      for (int i=1;p+i*i<right;i++)
        if (steps+1 < seen[p+i*i]) {
          seen[p+i*i] = steps+1;
          q.push(p+i*i);
        }
      for (int i=1;p-i*i>left;i++)
        if (steps+1 < seen[p-i*i]) {
          seen[p-i*i] = steps+1;
          q.push(p-i*i);
        }
    }
    return seen[goal];
  }
  int unbounded(int dist) {
    int r = bfs(1,dist+1,0,dist+2);
    if (dist%4 != 2)
      r = min(r,2);
    else
      r = min(r,3);
    return r;
  }
  int getMinimumSteps(int initPos, int GoalPos, vector <int> holePos) {
    if (initPos > GoalPos) swap(initPos,GoalPos);
    int goalPos = GoalPos+kOffset;
    memset(dp,-1,sizeof(dp));
    vector<bool> holes(300000,0);
    for (int i=0;i<holePos.size();i++)
      holes[holePos[i]+kOffset] = 1;
    for (int i=initPos+kOffset;i<goalPos;i++)
      if (holes[i]) return -1;
    int leftMost = 1000000;
    int rightMost = 1000000;
    for (int i=0;i<holePos.size();i++)
      if (holePos[i] < initPos) leftMost = min(leftMost,initPos-holePos[i]);
      else rightMost = min(rightMost,holePos[i]-GoalPos);
    if (leftMost == 1000000 || rightMost == 1000000) {
      return unbounded(GoalPos-initPos);
    }
    return bfs(initPos,GoalPos,initPos-leftMost,GoalPos+rightMost);
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
