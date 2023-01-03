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
// 556 1000

class LeftRightDigitsGame {
 public:
  string minNumber(string digits) {
    int k = 0;
    int i = digits.size();
    string res;
    while (i && i != k) {
      k = i;
      int mni = -1;
      for (int j=i-1;j>=0;j--) {
        if (digits[j] == '0' && res == "") continue;
        if (mni == -1 || digits[j] < digits[mni])
          mni = j;
      }
      if (mni != -1) {
        res+= digits[mni];
        digits[mni] = '#';
        i = mni;
      }
    }
    for (int j=0;j<digits.size();j++)
      if (digits[j] != '#')
        res+=digits[j];
    return res;
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
