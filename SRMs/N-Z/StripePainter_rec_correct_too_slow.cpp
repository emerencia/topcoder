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

typedef pair<string,int> PSI;
map<PSI,int> mem;

class StripePainter {
 public:
  string a;
  int n;
  int rec(string s, int k) {
    if (k == n) return 0;
    if (mem.count(PSI(s,k))) return mem[PSI(s,k)];
    if (k+1 < n && a[k] == a[k+1]) return mem[PSI(s,k)] = rec(s,k+1);
    int r = INT_MAX;
    string t = s;
    if (t.find(a[k]) != string::npos) {
      t = t.substr(t.find(a[k])+1);
      r = min(r,rec(a[k]+t,k+1));
    }
    r = min(r,1+rec(a[k]+s,k+1));
    return mem[PSI(s,k)] = r;
  }
  int minStrokes(string stripes) {
    a = stripes;
    n = stripes.size();
    mem.clear();
    string s;
    return rec(s,0);
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
