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

class ReadingBooks {
 public:
  int countBooks(vector <string> readParts) {
    int r = 0;
    for (int i=1;i<readParts.size()-1;i++) {
      if (readParts[i] != readParts[i-1] &&
              readParts[i] != readParts[i+1] &&
              readParts[i+1] != readParts[i-1]) {
        r++;
        i+=2;
      }
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"introduction", "story", "introduction", "edification"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, countBooks(Arg0)); }
	void test_case_1() { string Arr0[] = {"introduction", "story", "edification", "introduction", "story", "edification"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, countBooks(Arg0)); }
	void test_case_2() { string Arr0[] = {"introduction", "story", "introduction", "edification", "story", "introduction"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, countBooks(Arg0)); }
	void test_case_3() { string Arr0[] = {"introduction", "story", "introduction", "edification", "story",
 "story", "edification", "edification", "edification", "introduction",
 "introduction", "edification", "story", "introduction", "story",
 "edification", "edification", "story", "introduction", "edification",
 "story", "story", "edification", "introduction", "story"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, countBooks(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ReadingBooks ___test;
  ___test.run_test(-1);
}
// END CUT HERE
