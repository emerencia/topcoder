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
using namespace std;

class RandomColoringDiv2 {
 public:
  int getCount(int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2) {
    // at most d2 units
    // at least one differs by d1 units
    int c = 0;
    for (int r=max(0,startR-d2);r<min(startR+d2+1,maxR);r++) {
      for (int g=max(0,startG-d2);g<min(startG+d2+1,maxG);g++) {
        for (int b=max(0,startB-d2);b<min(startB+d2+1,maxB);b++) {
          if (abs(r-startR) >= d1 || abs(g-startG) >= d1 || abs(b-startB) >= d1) {
            c++;
          }
        }
      }
    }
    return c;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1; int Arg8 = 3; verify_case(0, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 2; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 3; int Arg7 = 3; int Arg8 = 4; verify_case(1, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 2; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 5; int Arg7 = 5; int Arg8 = 0; verify_case(2, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 9; int Arg2 = 10; int Arg3 = 1; int Arg4 = 2; int Arg5 = 3; int Arg6 = 0; int Arg7 = 10; int Arg8 = 540; verify_case(3, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_4() { int Arg0 = 6; int Arg1 = 9; int Arg2 = 10; int Arg3 = 1; int Arg4 = 2; int Arg5 = 3; int Arg6 = 4; int Arg7 = 10; int Arg8 = 330; verify_case(4, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_5() { int Arg0 = 49; int Arg1 = 59; int Arg2 = 53; int Arg3 = 12; int Arg4 = 23; int Arg5 = 13; int Arg6 = 11; int Arg7 = 22; int Arg8 = 47439; verify_case(5, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  RandomColoringDiv2 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
