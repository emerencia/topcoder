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

class ColorfulChocolates {
 public:
  int maximumSpread(string chocolates, int maxSwaps) {
    int mx = 0;
    for (int i=0;i<chocolates.size();i++) {
      int tmx = 1;
      vector<int> swapsneeded;
      int d = 0;
      if (i > 0)
        for (int j=i-1;j>=0;j--)
          if (chocolates[j] == chocolates[i])
            swapsneeded.push_back(d);
          else
            d++;
      d = 0;
      for (int j=i+1;j<chocolates.size();j++)
        if (chocolates[j] == chocolates[i])
          swapsneeded.push_back(d);
        else
          d++;
      sort(swapsneeded.begin(),swapsneeded.end());
      int t=0;
      for (int j=0;j<swapsneeded.size();j++) {
        t+=swapsneeded[j];
        if (t > maxSwaps) break;
        tmx++;
      }
      mx = max(mx,tmx);
    }
    return mx;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6();}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABCDCBC"; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, maximumSpread(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ABCDCBC"; int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, maximumSpread(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ABBABABBA"; int Arg1 = 3; int Arg2 = 4; verify_case(2, Arg2, maximumSpread(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ABBABABBA"; int Arg1 = 4; int Arg2 = 5; verify_case(3, Arg2, maximumSpread(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO"; int Arg1 = 77; int Arg2 = 5; verify_case(4, Arg2, maximumSpread(Arg0, Arg1)); }
void test_case_5() { string Arg0 = "ZZZZZZZ"; int Arg1 = 3; int Arg2 = 7; verify_case(5, Arg2, maximumSpread(Arg0, Arg1)); }
void test_case_6() { string Arg0 = "FFECCEADDDCEDEAFACCDCFFABDDACDDAAACCCDEFAEBDDAADCA"; int Arg1 = 108; int Arg2 = 13; verify_case(6, Arg2, maximumSpread(Arg0, Arg1)); }
// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ColorfulChocolates ___test;
  ___test.run_test(-1);
}
// END CUT HERE
