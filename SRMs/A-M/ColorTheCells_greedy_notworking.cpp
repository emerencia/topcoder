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
typedef pair<int,int> PII;
// 15:15

class ColorTheCells {
 public:
  int minTime(const vector<int>& drytime) {
    int r = 0;
    int n = drytime.size();
    for (int i=1;i+1<n;i++)
      r+=2;
    return r+min(4+drytime[n-2],3+min(max(0,(n <3 ? 1000 : drytime[n-3]-1)),drytime[n-1]-1));
  }
  int minimalTime(vector <int> dryingTime) {
    int r1 = minTime(dryingTime);
    //reverse(dryingTime.begin(),dryingTime.end());
    //int r2 = minTime(dryingTime);
    return r1;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, minimalTime(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 2, 100, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, minimalTime(Arg0)); }
	void test_case_2() { int Arr0[] = {33, 58, 21, 44}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 26; verify_case(2, Arg1, minimalTime(Arg0)); }
	void test_case_3() { int Arr0[] = {35198, 26281, 72533, 91031, 44326, 43178, 85530}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 26287; verify_case(3, Arg1, minimalTime(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ColorTheCells ___test;
  ___test.run_test(-1);
}
// END CUT HERE
