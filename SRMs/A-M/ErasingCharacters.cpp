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

class ErasingCharacters {
 public:
  string simulate(string s) {
    bool changed = true;
    while (changed) {
      changed = false;
      for (int i=0;i+1<s.size();i++) {
        if (s[i] == s[i+1]) {
          s = s.substr(0,i)+s.substr(i+2);
          changed = true;
          break;
        }
      }
    }
    return s;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "cieeilll"; string Arg1 = "cl"; verify_case(0, Arg1, simulate(Arg0)); }
	void test_case_1() { string Arg0 = "topcoder"; string Arg1 = "topcoder"; verify_case(1, Arg1, simulate(Arg0)); }
	void test_case_2() { string Arg0 = "abcdefghijklmnopqrstuvwxyyxwvutsrqponmlkjihgfedcba"; string Arg1 = ""; verify_case(2, Arg1, simulate(Arg0)); }
	void test_case_3() { string Arg0 = "bacaabaccbaaccabbcabbacabcbba"; string Arg1 = "bacbaca"; verify_case(3, Arg1, simulate(Arg0)); }
	void test_case_4() { string Arg0 = "eel"; string Arg1 = "l"; verify_case(4, Arg1, simulate(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ErasingCharacters ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
