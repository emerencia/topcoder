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

class PikachuEasy {
 public:
  string check(string word) {
    for (int i=0;i<word.size();i++) {
      if (word.substr(i,2) == "pi" || word.substr(i,2) == "ka") i+= 1;
      else if (word.substr(i,3) == "chu") i+= 2;
      else return "NO";
    }
    return "YES";
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "pikapi"; string Arg1 = "YES"; verify_case(0, Arg1, check(Arg0)); }
	void test_case_1() { string Arg0 = "pipikachu"; string Arg1 = "YES"; verify_case(1, Arg1, check(Arg0)); }
	void test_case_2() { string Arg0 = "pikaqiu"; string Arg1 = "NO"; verify_case(2, Arg1, check(Arg0)); }
	void test_case_3() { string Arg0 = "topcoder"; string Arg1 = "NO"; verify_case(3, Arg1, check(Arg0)); }
	void test_case_4() { string Arg0 = "piika"; string Arg1 = "NO"; verify_case(4, Arg1, check(Arg0)); }
	void test_case_5() { string Arg0 = "chupikachupipichu"; string Arg1 = "YES"; verify_case(5, Arg1, check(Arg0)); }
	void test_case_6() { string Arg0 = "pikapipachu"; string Arg1 = "NO"; verify_case(6, Arg1, check(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  PikachuEasy ___test;
  ___test.run_test(-1);
}
// END CUT HERE
