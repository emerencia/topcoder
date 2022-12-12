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

class TheNumberGameDiv2 {
 public:
  int findstr(string a, string b) {
    if (b.size() > a.size()) return -1;
    if (a.substr(0,b.size()).find(b) != string::npos)
      return a.size()-b.size();
    int r = INT_MAX;
    for (int i=a.size()-b.size();i>=0;i--)
      if (a.substr(i).find(b) != string::npos) {
        r = min(r,int((i ? 2 : 0) + i + a.size()-i-b.size()));
        break;
      }
    reverse(b.begin(),b.end());
    for (int i=a.size()-b.size();i>=0;i--)
      if (a.substr(i).find(b) != string::npos) {
        r = min(r,1+int(i + a.size()-i-b.size()));
        break;
      }
    return (r == INT_MAX ? -1 : r);
  }
  int minimumMoves(int A, int B) {
    stringstream a;
    a << A;
    stringstream b;
    b << B;
    int r = findstr(a.str(),b.str());
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 25; int Arg1 = 5; int Arg2 = 2; verify_case(0, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5162; int Arg1 = 16; int Arg2 = 4; verify_case(1, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 334; int Arg1 = 12; int Arg2 = -1; verify_case(2, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 218181918; int Arg1 = 9181; int Arg2 = 6; verify_case(3, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 9798147; int Arg1 = 79817; int Arg2 = -1; verify_case(4, Arg2, minimumMoves(Arg0, Arg1)); }
  	void test_case_5() { int Arg0 = 999999999; int Arg1 = 9; int Arg2 = 8; verify_case(5, Arg2, minimumMoves(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  TheNumberGameDiv2 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
