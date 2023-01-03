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
typedef pair<string,PII> PSI;
map<PSI,int> mem;

class StripePainter {
 public:
  string a;
  int n;
  // d = stackstart
  // m = movesleft
  // k = index
  int rec(int k, int m, string s) {
    if (k == n) return 1;
    if (mem.count(PSI(s,PII(k,m)))) return mem[PSI(s,PII(k,m))];
    if (k+1 < n && a[k] == a[k+1])
      return mem[PSI(s,PII(k,m))] = rec(k+1,m,s);
    string t = s;
    int ret = 0;
    if (t.find(a[k]) != string::npos) {
      t = t.substr(t.find(a[k])+1);
      ret = rec(k+1,m,a[k]+t);
    }
    if (!ret && m > 0) {
      ret = rec(k+1,m-1,a[k]+s);
    }
    return mem[PSI(s,PII(k,m))] = ret;
  }
  int minStrokes(string stripes) {
    a = stripes;
    n = stripes.size();
    string s;
    for (int i=0;i<n;i++) {
      mem.clear();
      if (rec(0,i,s)) return i;
    }
    return n;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RGBGR"; int Arg1 = 3; verify_case(0, Arg1, minStrokes(Arg0)); }
	void test_case_1() { string Arg0 = "RGRG"; int Arg1 = 3; verify_case(1, Arg1, minStrokes(Arg0)); }
	void test_case_2() { string Arg0 = "ABACADA"; int Arg1 = 4; verify_case(2, Arg1, minStrokes(Arg0)); }
	void test_case_3() { string Arg0 = "AABBCCDDCCBBAABBCCDD"; int Arg1 = 7; verify_case(3, Arg1, minStrokes(Arg0)); }
	void test_case_4() { string Arg0 = "BECBBDDEEBABDCADEAAEABCACBDBEECDEDEACACCBEDABEDADD"; int Arg1 = 26; verify_case(4, Arg1, minStrokes(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  StripePainter ___test;
  ___test.run_test(-1);
}
// END CUT HERE
