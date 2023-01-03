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
#include <numeric>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;

class FoxAndGomoku {
 public:
  string win(vector <string> board) {
    for (int i=0;i<board.size();i++)
      for (int j=0;j<board.size();j++) {
        if (i+4 < board.size()) 
          for (int k=0;k<5;k++) {
            if (board[i+k][j] != 'o') break;
            if (k == 4) return "found";
          }
        if (j+4 >= board.size()) continue;
        if (i>=4)
          for (int k=0;k<5;k++) {
            if (board[i-k][j+k] != 'o') break;
            if (k == 4) return "found";
          }
        for (int k=0;k<5;k++) {
          if (board[i][j+k] != 'o') break;
          if (k == 4) return "found";
        }
        if (i+4 >= board.size()) continue;
        for (int k=0;k<5;k++) {
          if (board[i+k][j+k] != 'o') break;
          if (k == 4) return "found";
        }
      }
    return "not found";
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"....o.",
 "...o..",
 "..o...",
 ".o....",
 "o.....",
 "......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "found"; verify_case(0, Arg1, win(Arg0)); }
	void test_case_1() { string Arr0[] = {"oooo.",
 ".oooo",
 "oooo.",
 ".oooo",
 "....."}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "not found"; verify_case(1, Arg1, win(Arg0)); }
	void test_case_2() { string Arr0[] = {"oooo.",
 ".oooo",
 "oooo.",
 ".oooo",
 "....o"}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "found"; verify_case(2, Arg1, win(Arg0)); }
	void test_case_3() { string Arr0[] = {"o.....",
 ".o....",
 "..o...",
 "...o..",
 "....o.",
 "......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "found"; verify_case(3, Arg1, win(Arg0)); }
	void test_case_4() { string Arr0[] = {"o....",
 "o.o..",
 "o.o.o",
 "o.o..",
 "o...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "found"; verify_case(4, Arg1, win(Arg0)); }
	void test_case_5() { string Arr0[] = {"..........",
 "..........",
 "..oooooo..",
 "..o.......",
 "..o.......",
 "..oooooo..",
 ".......o..",
 ".......o..",
 "..oooooo..",
 ".........."}
 
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "found"; verify_case(5, Arg1, win(Arg0)); }
	void test_case_6() { string Arr0[] = {"..........",
 "..........",
 "..oooo.o..",
 "..o.......",
 "..o.......",
 "..o.oooo..",
 ".......o..",
 ".......o..",
 "..oooo.o..",
 ".........."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "not found"; verify_case(6, Arg1, win(Arg0)); }
	void test_case_7() { string Arr0[] = {"ooooo",
 "ooooo",
 "ooooo",
 "ooooo",
 "ooooo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "found"; verify_case(7, Arg1, win(Arg0)); }
	void test_case_8() { string Arr0[] = {".....",
 ".....",
 ".....",
 ".....",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "not found"; verify_case(8, Arg1, win(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  FoxAndGomoku ___test;
  ___test.run_test(-1);
}
// END CUT HERE
