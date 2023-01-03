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
// 555 555

const int kMin = 100;

class CuttingBitString {
 public:
  map<string,int> mincuts;
  set<string> powers;
  int rec(string s) {
    if (s[0] == '0') return -1;
    if (powers.count(s)) return 0;
    if (mincuts.count(s)) return mincuts[s];
    int mn = kMin;
    for (set<string>::iterator i=powers.begin();i!=powers.end();i++) {
      string p = (*i);
      if (p.size() >= s.size()) continue;
      if (s.substr(0,p.size()) != p) continue;
      int r = rec(s.substr(p.size()));
      if (r == -1) continue;
      mn = min(mn,1+r);
    }
    if (mn == kMin) mn = -1;
    return mincuts[s] = mn;
  }
  int getmin(string S) {
    powers = set<string>();
    int j=0;
    for (long long i=1;i<LLONG_MAX && i>j;i*=5) {
      string d = "";
      long long h = i;
      while (h) {
        d=char('0'+h%2)+d;
        h>>=1;
      }
      powers.insert(d);
      j = i;
    }
    int r = rec(S);
    return (r == -1 ? r : r+1);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "101101101"; int Arg1 = 3; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arg0 = "1111101"; int Arg1 = 1; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arg0 = "00000"; int Arg1 = -1; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arg0 = "110011011"; int Arg1 = 3; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arg0 = "1000101011"; int Arg1 = -1; verify_case(4, Arg1, getmin(Arg0)); }
	void test_case_5() { string Arg0 = "111011100110101100101110111"; int Arg1 = 5; verify_case(5, Arg1, getmin(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  CuttingBitString ___test;
  ___test.run_test(-1);
}
// END CUT HERE
