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

class EllysCheckers {
 public:
   vector<int> dp;
   int winner(int b,int turn) {
     if (dp[b] != -1) return dp[b];
     b &=~(1<<0);
     for (int i=0;i<20;i++) {
       if (b&(1<<i) && i-3 >=0 && b&(1<<(i-1)) && 
               b&(1<<(i-2)) && (b&(1<<(i-3))) == 0) {
         if (winner(b^(1<<i)^(1<<(i-1)),1-turn) == turn) return dp[b] = turn;
       }
       if (b&(1<<i) && i-1 >=0 && (b&(1<<(i-1))) == 0) {
         if (winner(b^(1<<i)^(1<<(i-1)),1-turn) == turn) return dp[b] = turn;
       }
     }
     return dp[b] = 1-turn;
   }
  string getWinner(string board) {
    dp = vector<int>(1+(1<<20),-1);
    board[board.size()-1] = '.';
    int b =0;
    for (int i=0;i<board.size();i++) {
      if (board[i] == 'o')
        b |= (1 << (board.size()-1-i));
    }
    return (winner(b,0) == 0 ? "YES" : "NO");
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ".o..."; string Arg1 = "YES"; verify_case(0, Arg1, getWinner(Arg0)); }
	void test_case_1() { string Arg0 = "..o..o"; string Arg1 = "YES"; verify_case(1, Arg1, getWinner(Arg0)); }
	void test_case_2() { string Arg0 = ".o...ooo..oo.."; string Arg1 = "NO"; verify_case(2, Arg1, getWinner(Arg0)); }
	void test_case_3() { string Arg0 = "......o.ooo.o......"; string Arg1 = "YES"; verify_case(3, Arg1, getWinner(Arg0)); }
	void test_case_4() { string Arg0 = ".o..o...o....o.....o"; string Arg1 = "NO"; verify_case(4, Arg1, getWinner(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  EllysCheckers ___test;
  ___test.run_test(-1);
}
// END CUT HERE
