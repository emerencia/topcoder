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

int mem[51][51];

class PenguinPals {
  int n;
  string col;
 public:
  int rec(int l, int r) {
    if (l == r) return 0;
    int& res = mem[l][r];
    if (res != -1) return res;
    int res2 = 0;
    for (int i=l;i!=r;i=(i+1)%n)
      for (int j=(i+1)%n;j!=(r+1)%n;j=(j+1)%n) {
        if (i == j || col[i] != col[j]) continue;
        int res3 = 1;
        if (l != i) res3+= rec(l,(i+n-1)%n);
        if ((i+1)%n != j) res3+= rec((i+1)%n,(j+n-1)%n);
        if (j != r) res3+= rec((j+1)%n,r);
        res2 = max(res2,res3);
      }
    return res = res2;
  }
  int findMaximumMatching(string colors) {
    int r = 0;
    col = colors;
    n = colors.size();
    memset(mem,-1,sizeof(mem));
    for (int i = 0;i<colors.size();i++) {
      r = max(r,rec((i+1)%n,i));
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); if ((Case == -1) || (Case == 9)) test_case_9(); if ((Case == -1) || (Case == 10)) test_case_10(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RRBRBRBB"; int Arg1 = 3; verify_case(0, Arg1, findMaximumMatching(Arg0)); }
	void test_case_1() { string Arg0 = "RRRR"; int Arg1 = 2; verify_case(1, Arg1, findMaximumMatching(Arg0)); }
	void test_case_2() { string Arg0 = "BBBBB"; int Arg1 = 2; verify_case(2, Arg1, findMaximumMatching(Arg0)); }
	void test_case_3() { string Arg0 = "RBRBRBRBR"; int Arg1 = 4; verify_case(3, Arg1, findMaximumMatching(Arg0)); }
	void test_case_4() { string Arg0 = "RRRBRBRBRBRB"; int Arg1 = 5; verify_case(4, Arg1, findMaximumMatching(Arg0)); }
	void test_case_5() { string Arg0 = "R"; int Arg1 = 0; verify_case(5, Arg1, findMaximumMatching(Arg0)); }
	void test_case_6() { string Arg0 = "RBRRBBRB"; int Arg1 = 3; verify_case(6, Arg1, findMaximumMatching(Arg0)); }
	void test_case_7() { string Arg0 = "RBRBBRBRB"; int Arg1 = 4; verify_case(7, Arg1, findMaximumMatching(Arg0)); }
  void test_case_8() { string Arg0 = "RRRBBBRRRBBBRBRBRBRB"; int Arg1 = 9; verify_case(8, Arg1, findMaximumMatching(Arg0)); }
  void test_case_9() { string Arg0 = "RRBBRRBBBRBRRBRBRBRBRBRBRBRBBRRBRBRBRBBBBBBBBRRRRB"; int Arg1 = 24; verify_case(9, Arg1, findMaximumMatching(Arg0)); }
  void test_case_10() { string Arg0 = "RBRBRBRBRBBRBRBRBBRBRBBBRBRBBRBRBRBBRBBBRBBBRBB"; int Arg1 = 23; verify_case(10, Arg1, findMaximumMatching(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  PenguinPals ___test;
  ___test.run_test(-1);
}
// END CUT HERE
