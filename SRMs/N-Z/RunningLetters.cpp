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
// 16:05 start
// 16:29 done
// END CUT HERE

class RunningLetters {
 public:
  string getString(const vector<string>& a) {
    string all = accumulate(a.begin(),a.end(),string(""));
    string s;
    stringstream b(all);
    int c;
    string d;
    while (!b.eof()) {
      b >> c;
      b >> d;
      for (int i=0;i<c;i++)
        s+=d;
    }
    return s;
  }
  vector<int> kmpf(string p) {
    vector<int> r(p.size(),0);
    int i = 1;
    int j = 0;
    while (i < p.size()) {
      if (p[i] == p[j]) {
        r[i++] = ++j;
      } else if (j > 0) {
        j = r[j-1];
      } else {
        r[i++] = 0;
      }
    }
    return r;
  }
  int newsLength(vector <string> running) {
    string a = getString(running);
    vector<int> b = kmpf(a);
    return a.size()-b.back();
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3 abc 1 ab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, newsLength(Arg0)); }
	void test_case_1() { string Arr0[] = {"1 babaaba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, newsLength(Arg0)); }
	void test_case_2() { string Arr0[] = {"1 ba 1 c 1 bacba 3 cba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, newsLength(Arg0)); }
	void test_case_3() { string Arr0[] = {"42 runningletters 42 runningletters 1 running"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(3, Arg1, newsLength(Arg0)); }
	void test_case_4() { string Arr0[] = {"1 b ", "1 a ", "1 b ", "1 a", " 1 b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, newsLength(Arg0)); }
  	void test_case_5() { string Arr0[] = {"1 b 2 a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(5, Arg1, newsLength(Arg0)); }
  	void test_case_6() { string Arr0[] = {"400000 ab 1 a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(6, Arg1, newsLength(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  RunningLetters ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
