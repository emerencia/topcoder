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


class GearsDiv2 {
 public:
  map<string,int> mem;
  bool isgood(string s) {
    int last = -1;
    for (int i=0;i<s.size();i++) {
      if (last != -1 && s[i] == s[last]) return false;
      last = i;
    }
    return true;
  }
  int rec(string s) {
    if (s.size() <= 1) return 0;
    if (mem.count(s)) return mem[s];
    if (isgood(s)) return mem[s] = 0;
    int mn = 10000;
    for (int i=0;i<s.size();i++) {
      mn = min(mn,1 + rec(s.substr(0,i)) + rec(s.substr(i+1)));
    }
    return mem[s] = mn;
  }
  int getmin(string Directions) {
    mem = map<string,int>();
    int r = 0;
    if (Directions[0] == Directions[Directions.size()-1]) {
      r = rec(Directions.substr(1));
      r = min(r,rec(Directions.substr(0,Directions.size()-1)));
      return r+1;
    }
    return rec(Directions);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6();}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LRRR"; int Arg1 = 1; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arg0 = "RRR"; int Arg1 = 2; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arg0 = "LRLR"; int Arg1 = 0; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arg0 = "LRLLRRLLLRRRLLLL"; int Arg1 = 6; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arg0 = "RRRRRRRLRRRRRRRLRLRLLRLRLRLRRLRLRLLLRLRLLRLLRRLRRR"; int Arg1 = 14; verify_case(4, Arg1, getmin(Arg0)); }
  void test_case_5() { string Arg0 = "LLLRR"; int Arg1 = 2; verify_case(5, Arg1, getmin(Arg0)); }
  void test_case_6() { string Arg0 = "LRLRRRLRL"; int Arg1 = 2; verify_case(6, Arg1, getmin(Arg0)); }
// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  GearsDiv2 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
