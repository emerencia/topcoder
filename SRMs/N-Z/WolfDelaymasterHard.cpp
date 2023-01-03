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

int dp[1000001];

class WolfDelaymasterHard {
 public:
  string generate(int N, int wlen, int w0, int wmul, int wadd, int olen, int o0, int omul, int oadd) {
    string s(N,'?');
    long long x = w0;
    for (int i=0;i<wlen;i++) {
      s[x]='w';
      x = (x*wmul+wadd)%N;
    }
    x = o0;
    for (int i=0;i<olen;i++) {
      s[x]='o';
      x = (x*omul+oadd)%N;
    }
    return s;
  }
  bool pattern(const string& s, int ii, int jj) {
    int wc = 0;
    bool lastwaso = false;
    for (int i=2*ii;i<2*jj;i++) {
      
    }
  }
  int countWords(int N, int wlen, int w0, int wmul, int wadd, int olen, int o0, int omul, int oadd) {
    string s = generate(N,wlen,w0,wmul,wadd,olen,o0,omul,oadd);
    if (s.size() < 100)
      cout << s << endl;
    memset(dp,0,sizeof(dp));
    int n = s.size();
    dp[0] = 0;
    for (int j = 1;j<n/2;j++) {
      dp[j] = 0;
      for (int i=0;i<j-1;i++) {
        if (pattern(s,i,j)) {
            dp[j] = dp[j] + dp[i];
        }
      }
    }
    return 0;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; int Arg1 = 5; int Arg2 = 2; int Arg3 = 3; int Arg4 = 2; int Arg5 = 0; int Arg6 = 6; int Arg7 = 7; int Arg8 = 1; int Arg9 = 6; verify_case(0, Arg9, countWords(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_1() { int Arg0 = 20; int Arg1 = 19; int Arg2 = 12; int Arg3 = 9; int Arg4 = 15; int Arg5 = 1; int Arg6 = 8; int Arg7 = 11; int Arg8 = 1; int Arg9 = 26; verify_case(1, Arg9, countWords(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_2() { int Arg0 = 40; int Arg1 = 24; int Arg2 = 34; int Arg3 = 5; int Arg4 = 11; int Arg5 = 33; int Arg6 = 35; int Arg7 = 23; int Arg8 = 27; int Arg9 = 296; verify_case(2, Arg9, countWords(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_3() { int Arg0 = 60; int Arg1 = 35; int Arg2 = 8; int Arg3 = 55; int Arg4 = 3; int Arg5 = 11; int Arg6 = 20; int Arg7 = 9; int Arg8 = 29; int Arg9 = 10058904; verify_case(3, Arg9, countWords(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_4() { int Arg0 = 2000; int Arg1 = 183; int Arg2 = 994; int Arg3 = 862; int Arg4 = 468; int Arg5 = 148; int Arg6 = 433; int Arg7 = 1247; int Arg8 = 1989; int Arg9 = 532199331; verify_case(4, Arg9, countWords(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_5() { int Arg0 = 2000000; int Arg1 = 419443; int Arg2 = 1305303; int Arg3 = 1761823; int Arg4 = 1007025; int Arg5 = 874640; int Arg6 = 1516339; int Arg7 = 229519; int Arg8 = 1473199; int Arg9 = 861766906; verify_case(5, Arg9, countWords(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_6() { int Arg0 = 8; int Arg1 = 6; int Arg2 = 0; int Arg3 = 1; int Arg4 = 1; int Arg5 = 3; int Arg6 = 3; int Arg7 = 6; int Arg8 = 1; int Arg9 = 0; verify_case(6, Arg9, countWords(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  WolfDelaymasterHard ___test;
  ___test.run_test(-1);
}
// END CUT HERE
