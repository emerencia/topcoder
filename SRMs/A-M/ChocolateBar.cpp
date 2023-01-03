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
// 556 250

class ChocolateBar {
 public:
  int maxLength(string letters) {
    int mx = 0;
    for (int i=0;i<letters.size();i++)
      for (int j=i;j<letters.size();j++) {
        bool ok = true;
        for (int k=i;k<j;k++)
          if (letters[k] == letters[j]) { ok = false; break; }
        if (!ok) break;
        mx = max(mx,j-i+1);
      }
    return mx;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "srm"; int Arg1 = 3; verify_case(0, Arg1, maxLength(Arg0)); }
	void test_case_1() { string Arg0 = "dengklek"; int Arg1 = 6; verify_case(1, Arg1, maxLength(Arg0)); }
	void test_case_2() { string Arg0 = "haha"; int Arg1 = 2; verify_case(2, Arg1, maxLength(Arg0)); }
	void test_case_3() { string Arg0 = "www"; int Arg1 = 1; verify_case(3, Arg1, maxLength(Arg0)); }
	void test_case_4() { string Arg0 = "thisisansrmbeforetopcoderopenfinals"; int Arg1 = 9; verify_case(4, Arg1, maxLength(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ChocolateBar ___test;
  ___test.run_test(-1);
}
// END CUT HERE
