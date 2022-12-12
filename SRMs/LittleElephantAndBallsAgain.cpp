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
// 
// END CUT HERE

class LittleElephantAndBallsAgain {
 public:
  int getNumber(string S) {
    int mx = 0;
    char c = 0;
    int cur = 0;
    for (int i=0;i<S.size();i++) {
      if (S[i] != c) {
        c = S[i];
        mx = max(cur,mx);
        cur = 0;
      }
      cur++;
    }
    mx = max(cur,mx);
    return S.size()-mx;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RRGGBB"; int Arg1 = 4; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { string Arg0 = "R"; int Arg1 = 0; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { string Arg0 = "RGBRGB"; int Arg1 = 5; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { string Arg0 = "RGGGBB"; int Arg1 = 3; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { string Arg0 = "RGBRBRGRGRBBBGRBRBRGBGBBBGRGBBBBRGBGRRGGRRRGRBBBBR"; int Arg1 = 46; verify_case(4, Arg1, getNumber(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  LittleElephantAndBallsAgain ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
