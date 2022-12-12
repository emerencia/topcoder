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
// 556 1000 (check pes+kankuro solutions)
// try iterative

class LeftRightDigitsGame {
 public:
  string mn;
  string dig;
  bool smaller_than_or_equal(const string& a, const string& b) {
    for (int i=0;i<a.size();i++)
      if (a[i] != b[i]) return a[i] < b[i];
    return true;
  }
  void rec(string sofar,int idx) {
    if (idx == dig.size()) {
      if (sofar < mn) mn = sofar;
      return;
    }
    if (smaller_than_or_equal(dig[idx]+sofar,sofar+dig[idx])) {
      rec(dig[idx]+sofar,idx+1);
    } else {
      rec(sofar+dig[idx],idx+1);
    }
  }
  string minNumber(string digits) {
    mn = "9"+string(50,'9');
    string mnn = mn;
    for (int i=0;i<digits.size();i++) {
      if (digits[i] == '0') continue;
      mn = "9"+string(50,'9');
      dig = digits.substr(0,i);
      string a = "";
      rec(a,0);
      mn = digits[i]+mn+digits.substr(i+1);
      if (mn < mnn) mnn = mn;
    }
    return mnn;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "565"; string Arg1 = "556"; verify_case(0, Arg1, minNumber(Arg0)); }
	void test_case_1() { string Arg0 = "9876543210"; string Arg1 = "1234567890"; verify_case(1, Arg1, minNumber(Arg0)); }
	void test_case_2() { string Arg0 = "8016352"; string Arg1 = "1086352"; verify_case(2, Arg1, minNumber(Arg0)); }
  void test_case_3() { string Arg0 = "00000000000000000000000000100000000000000000000000"; string Arg1 = "98765432109876543210987654321098765432109876543210"; verify_case(3, Arg1, minNumber(Arg0)); }
  void test_case_4() { string Arg0 = "109"; string Arg1 = "109"; verify_case(4, Arg1, minNumber(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  LeftRightDigitsGame ___test;
  ___test.run_test(-1);
}
// END CUT HERE
