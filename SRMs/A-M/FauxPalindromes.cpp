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

class FauxPalindromes {
 public:
  string classifyIt(string word) {
    bool good = true;
    for (int i=0;i<word.size()/2;i++)
      if (word[i] != word[word.size()-1-i]) { good = false; break; }
    if (good) return "PALINDROME";
    string s = string(1,word[0]);
    for (int i = 1;i<word.size();i++)
      if (word[i] != s[s.size()-1]) s+= word[i];
    good = true;
    for (int i=0;i<s.size()/2;i++)
      if (s[i] != s[s.size()-1-i]) { good = false; break; }
    return (good ? "FAUX" : "NOT EVEN FAUX");
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ANA"; string Arg1 = "PALINDROME"; verify_case(0, Arg1, classifyIt(Arg0)); }
	void test_case_1() { string Arg0 = "AAAAANNAA"; string Arg1 = "FAUX"; verify_case(1, Arg1, classifyIt(Arg0)); }
	void test_case_2() { string Arg0 = "LEGENDARY"; string Arg1 = "NOT EVEN FAUX"; verify_case(2, Arg1, classifyIt(Arg0)); }
	void test_case_3() { string Arg0 = "XXXYTYYTTYX"; string Arg1 = "FAUX"; verify_case(3, Arg1, classifyIt(Arg0)); }
	void test_case_4() { string Arg0 = "TOPCOODEREDOOCPOT"; string Arg1 = "PALINDROME"; verify_case(4, Arg1, classifyIt(Arg0)); }
	void test_case_5() { string Arg0 = "TOPCODEREDOOCPOT"; string Arg1 = "FAUX"; verify_case(5, Arg1, classifyIt(Arg0)); }
	void test_case_6() { string Arg0 = "XXXXYYYYYZZXXYYY"; string Arg1 = "NOT EVEN FAUX"; verify_case(6, Arg1, classifyIt(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  FauxPalindromes ___test;
  ___test.run_test(-1);
}
// END CUT HERE
