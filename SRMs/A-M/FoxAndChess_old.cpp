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

class FoxAndChess {
 public:
  string ableToMove(string begin, string target) {
    if (begin == target) return "Possible";
    int lcb = 0;
    int rcb = 0;
    int ceb = 0;
    int lct = 0;
    int rct = 0;
    int cet = 0;
    for (int i=0;i<begin.size();i++) {
      if (begin[i] == 'L') lcb++;
      else if (begin[i] == 'R') rcb++;
      else ceb++;
      if (target[i] == 'L') lct++;
      else if (target[i] == 'R') rct++;
      else cet++;
    }
    if (lcb != lct || rcb != rct || ceb != cet) return "Impossible";
    if (ceb == 0) return "Impossible";
    string aa = "";
    string bb = "";
    for (int i=0;i<begin.size();i++) {
      if (begin[i] != '.') aa+= begin[i];
      if (target[i] != '.') bb+= target[i];
    }
    if (aa != bb) return "Impossible";
    vector<int> a;
    vector<int> b;
    vector<int> c;
    vector<int> d;
    for (int i=0;i<begin.size();i++) {
      if (begin[i] == 'L') a.push_back(i);
      if (begin[i] == 'R') c.push_back(i);
      if (target[i] == 'L') b.push_back(i);
      if (target[i] == 'R') d.push_back(i);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    sort(d.begin(),d.end());
    for (int i=0;i<a.size();i++) {
      if (a[i] < b[i]) return "Impossible";
    }
    for (int i=0;i<c.size();i++) {
      if (c[i] > d[i]) return "Impossible";
    }
    return "Possible";
  }
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "R..."; string Arg1 = "..R."; string Arg2 = "Possible"; verify_case(0, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "..R."; string Arg1 = "R..."; string Arg2 = "Impossible"; verify_case(1, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = ".L.R.R."; string Arg1 = "L...R.R"; string Arg2 = "Possible"; verify_case(2, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = ".L.R."; string Arg1 = ".R.L."; string Arg2 = "Impossible"; verify_case(3, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "LRLLRLRLLRLLRLRLRL"; string Arg1 = "LRLLRLRLLRLLRLRLRL"; string Arg2 = "Possible"; verify_case(4, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "L"; string Arg1 = "."; string Arg2 = "Impossible"; verify_case(5, Arg2, ableToMove(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  FoxAndChess ___test;
  ___test.run_test(-1);
}
// END CUT HERE
