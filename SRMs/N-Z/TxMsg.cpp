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

class TxMsg {
 public:
   string vowelenc(string s) {
     string r = (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') ?"" : string(1,s[0]);
     for (int i=1;i<s.size();i++) {
       if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
         continue;
       if (s[i-1] != 'a' && s[i-1] != 'e' && s[i-1] != 'i' && s[i-1] != 'o' && s[i-1] != 'u')
         continue;
       r+=s[i];
     }
     return r;
   }
  string getMessage(string original) {
    string r = "";
    string w = "";
    int wp = 0;
    bool onlyvowels = true;
    for (int i=0;i<original.size();i++) {
      if (original[i] == ' ') {
        if (w != "") {
          if (onlyvowels) r+= original.substr(wp,i-wp);
          else r+= vowelenc(original.substr(wp,i-wp));
        }
        onlyvowels=true;
        w = "";
        r+= " ";
      } else {
        if (w == "") {
          wp = i;
          w = string(1,original[i]);
        } else {
          w += original[i];
        }
        if (original[i] != 'a' && original[i] != 'e' && original[i] != 'i' && original[i] != 'o' && original[i] != 'u')
          onlyvowels=false;
      }
    }
    if (w != "") {
      if (onlyvowels) r+= original.substr(wp);
      else r+= vowelenc(original.substr(wp));
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "text message"; string Arg1 = "tx msg"; verify_case(0, Arg1, getMessage(Arg0)); }
	void test_case_1() { string Arg0 = "ps i love u"; string Arg1 = "p i lv u"; verify_case(1, Arg1, getMessage(Arg0)); }
	void test_case_2() { string Arg0 = "please please me"; string Arg1 = "ps ps m"; verify_case(2, Arg1, getMessage(Arg0)); }
	void test_case_3() { string Arg0 = "back to the ussr"; string Arg1 = "bc t t s"; verify_case(3, Arg1, getMessage(Arg0)); }
	void test_case_4() { string Arg0 = "aeiou bcdfghjklmnpqrstvwxyz"; string Arg1 = "aeiou b"; verify_case(4, Arg1, getMessage(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  TxMsg ___test;
  ___test.run_test(-1);
}
// END CUT HERE
