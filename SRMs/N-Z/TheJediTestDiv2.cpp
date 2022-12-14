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

class TheJediTestDiv2 {
 public:
  int countSupervisors(vector <int> students, int Y, int J) {
    int r = INT_MAX;
    if (students.size() == 1 && students[0] <= Y) return 0;
    for (int i = 0;i<students.size();i++) {
      int cr = 0;
      for (int j = 0; j < students.size();j++) {
        if (i == j) {
          if (students[j] > Y)
            cr+= (students[j]-Y-1)/J+1;
        } else if (students[j]) {
          cr+= (students[j]-1)/J+1;
        }
      }
      r = min(r,cr);
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10, 15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 5; int Arg3 = 3; verify_case(0, Arg3, countSupervisors(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {11, 13, 15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 5; int Arg3 = 7; verify_case(1, Arg3, countSupervisors(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 2; int Arg3 = 0; verify_case(2, Arg3, countSupervisors(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 145; int Arg2 = 21; int Arg3 = 0; verify_case(3, Arg3, countSupervisors(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {4, 7, 10, 5, 6, 55, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; int Arg2 = 3; int Arg3 = 26; verify_case(4, Arg3, countSupervisors(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  TheJediTestDiv2 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
