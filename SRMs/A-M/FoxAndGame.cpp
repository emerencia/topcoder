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

class FoxAndGame {
 public:
  int countStars(vector <string> result) {
    int r = 0;
    for (int i = 0;i<result.size();i++)
      for (int j = 0;j<result[i].size();j++)
        r+= (result[i][j] == 'o');
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ooo",
 "ooo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, countStars(Arg0)); }
	void test_case_1() { string Arr0[] = {"ooo",
 "oo-",
 "o--"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, countStars(Arg0)); }
	void test_case_2() { string Arr0[] = {"ooo",
 "---",
 "oo-",
 "---",
 "o--"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, countStars(Arg0)); }
	void test_case_3() { string Arr0[] = {"o--",
 "o--",
 "o--",
 "ooo",
 "---"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, countStars(Arg0)); }
	void test_case_4() { string Arr0[] = {"---",
 "o--",
 "oo-",
 "ooo",
 "ooo",
 "oo-",
 "o--",
 "---"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(4, Arg1, countStars(Arg0)); }
	void test_case_5() { string Arr0[] = {"---",
 "---",
 "---",
 "---",
 "---",
 "---"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, countStars(Arg0)); }
	void test_case_6() { string Arr0[] = {"oo-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(6, Arg1, countStars(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  FoxAndGame ___test;
  ___test.run_test(-1);
}
// END CUT HERE
