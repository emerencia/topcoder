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
#include <limits>
#include <cstring>
#include <numeric>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
// BEGIN CUT HERE
const int toTest = -1;
// 
// END CUT HERE

class WordAbbreviation {
 public:
  vector <string> getAbbreviations(vector <string> words) {
    vector<string> r;
    for (int i=0;i<words.size();i++)
      for (int j=1;j<=words[i].size();j++) {
        bool isvalid = true;
        string prefix = words[i].substr(0,j);
        for (int k=0;k<words.size();k++) {
          if (k == i) continue;
          if (prefix.size() <= words[k].size() &&
              words[k].substr(0,prefix.size()) == prefix) {
            isvalid = false;
            break;
          }
        }
        if (isvalid) {
          r.push_back(prefix);
          break;
        }
      }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"abc","def","ghi"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a", "d", "g" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getAbbreviations(Arg0)); }
	void test_case_1() { string Arr0[] = {"aaab","aaac","aaad"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"aaab", "aaac", "aaad" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getAbbreviations(Arg0)); }
	void test_case_2() { string Arr0[] = {"top","coder","contest"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"t", "cod", "con" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getAbbreviations(Arg0)); }
	void test_case_3() { string Arr0[] = {
 "bababaaaaa",
 "baaabaababa",
 "bbabaaabbaaabbabaabaabbbbbaabb",
 "aaababababbbbababbbaabaaaaaaaabbabbbaaab",
 "baaaaabaababbbaabbbabbababbbabbbbbbbbab"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"bab", "baaab", "bb", "a", "baaaa" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getAbbreviations(Arg0)); }
	void test_case_4() { string Arr0[] = {"oneword"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"o" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getAbbreviations(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  WordAbbreviation ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
