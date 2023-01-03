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

class WolfDelaymaster {
 public:
  string check(string str) {
    int state = 0;
    int cnt = 0;
    int curcnt = 0;
    for (int i=0;i<str.size();i++)
      switch(state) {
        case 0:
          if (str[i] == 'w') {
            cnt++;
            break;
          } else if (str[i] != 'o' || cnt == 0)
            return "INVALID";
          state = 1;
        case 1:
          if (str[i] == 'o') {
            curcnt++;
            break;
          } else if (str[i] != 'l' || curcnt != cnt)
            return "INVALID";
          state = 2;
          curcnt = 0;
        case 2:
          if (str[i] == 'l') {
            curcnt++;
            break;
          } else if (str[i] != 'f' || curcnt != cnt)
            return "INVALID";
          state = 3;
          curcnt = 0;
        case 3:
          if (str[i] == 'f') {
            curcnt++;
            if (curcnt == cnt) {
              state = 0;
              curcnt = 0;
              cnt = 0;
            }
            break;
          } else if (str[i] != 'w' || curcnt != cnt)
            return "INVALID";
          curcnt = 0;
          cnt = 0;
          state = 0;
          i--;
      }
    return ((state == 0 && cnt == 0) ? "VALID" : "INVALID");
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "wolf"; string Arg1 = "VALID"; verify_case(0, Arg1, check(Arg0)); }
	void test_case_1() { string Arg0 = "wwolfolf"; string Arg1 = "INVALID"; verify_case(1, Arg1, check(Arg0)); }
	void test_case_2() { string Arg0 = "wolfwwoollffwwwooolllfffwwwwoooollllffff"; string Arg1 = "VALID"; verify_case(2, Arg1, check(Arg0)); }
	void test_case_3() { string Arg0 = "flowolf"; string Arg1 = "INVALID"; verify_case(3, Arg1, check(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  WolfDelaymaster ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
