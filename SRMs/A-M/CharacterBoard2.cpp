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

const int kMod = 1e9+9;

class CharacterBoard2 {
 public:
  int countGenerators(vector <string> fragment, int W, int i0, int j0) {
    long long r = 0;
    for (int i=1;i<=W;i++) {
      string s(i,'?');
      bool f = true;
      for (int j=0;j<fragment.size();j++) {
        for (int k=0;k<fragment[0].size();k++) {
          int idx = ((i0+j)*W+j0+k)%i;
          if (s[idx] != '?' && s[idx] != fragment[j][k]) { f = false; break; }
          s[idx] = fragment[j][k];
        }
        if (!f) break;
      }
      if (!f) continue;
      long long t = 1;
      for (int j=0;j<s.size();j++)
        if (s[j] == '?')
          t = (26*t)%kMod;
      r = (r+t)%kMod;
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"dea",
 "abc"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; verify_case(0, Arg4, countGenerators(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"xyxxy"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 1; int Arg3 = 0; int Arg4 = 28; verify_case(1, Arg4, countGenerators(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"gogogo",
 "jijiji",
 "rarara"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; verify_case(2, Arg4, countGenerators(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"abababacac",
 "aaacacacbb",
 "ccabababab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 882; int Arg2 = 10; int Arg3 = 62; int Arg4 = 361706985; verify_case(3, Arg4, countGenerators(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"asjkffqw",
 "basjkffq",
 "qbasjkff",
 "qqbasjkf"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9031; int Arg2 = 9024; int Arg3 = 1959; int Arg4 = 173947456; verify_case(4, Arg4, countGenerators(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  CharacterBoard2 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
