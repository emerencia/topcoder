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

class SemiPerfectSquare {
 public:
  string check(int N) {
    for (int a = 1;a<N;a++)
      for (int b=a+1;a*b*b <= N;b++)
        if (a*b*b == N) return "Yes";
    return "No";
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 48; string Arg1 = "Yes"; verify_case(0, Arg1, check(Arg0)); }
	void test_case_1() { int Arg0 = 1000; string Arg1 = "No"; verify_case(1, Arg1, check(Arg0)); }
	void test_case_2() { int Arg0 = 25; string Arg1 = "Yes"; verify_case(2, Arg1, check(Arg0)); }
	void test_case_3() { int Arg0 = 47; string Arg1 = "No"; verify_case(3, Arg1, check(Arg0)); }
	void test_case_4() { int Arg0 = 847; string Arg1 = "Yes"; verify_case(4, Arg1, check(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  SemiPerfectSquare ___test;
  ___test.run_test(-1);
}
// END CUT HERE
