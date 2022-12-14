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

class DengklekPaintingSquares {
 public:
  int numSolutions(int N, int M) {
    
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, numSolutions(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 8; verify_case(1, Arg2, numSolutions(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 5; verify_case(2, Arg2, numSolutions(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 47; int Arg1 = 7; int Arg2 = 944149920; verify_case(3, Arg2, numSolutions(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  DengklekPaintingSquares ___test;
  ___test.run_test(-1);
}
// END CUT HERE
