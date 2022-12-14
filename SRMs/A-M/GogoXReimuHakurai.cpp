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

class GogoXReimuHakurai {
 public:
   int n;
   vector<vector<int> > mConn;
   vector<vector<int> > mSeen;
   vector<int> mVisited;
   vector<int> mPaths;
  int solve(vector <string> choices) {
    n = choices.size();
    mConn.resize(n,vector<int>(n,0));
    mSeen.resize(n,vector<int>(n,0));
    for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++) {
        if (choices[i][j] == 'Y') mConn[i][j]= 1; 
      }
    }
    mVisited.resize(n,0);
    mPaths.resize(n,0);
    mPaths[n-1] = 1;
    mVisited[n-1] = 1;
    int ch = GetMaxChoices(0);
    return ch;
  }
  int GetMaxChoices(int i) {
    if (mVisited[i]) return mPaths[i] ? 1 : 0;
    int count = 0;
    for (int j=n-1;j>=0;j--) {
      if (mConn[i][j]) {
        if (!mVisited[j]) {
          count += GetMaxChoices(j);
        } else {
          count += mPaths[j] ? 1 : 0;
        }
      }
    }
    mVisited[i] = 1;
    return mPaths[i] = count;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"NYY",
"NNY",
"NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { string Arr0[] = {
"NYNY",
"NNYY",
"NNNY",
"NNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { string Arr0[] = {"NNY"
,"NNY"
,"NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { string Arr0[] = {"NN"
,"NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, solve(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  GogoXReimuHakurai ___test;
  ___test.run_test(-1);
}
// END CUT HERE
