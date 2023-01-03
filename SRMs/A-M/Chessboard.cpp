#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <utility>
using namespace std;

class Chessboard {
 public:
  string changeNotation(string cell) {
    if (cell[0] >= 'a' && cell[0] <= 'h') {
      ostringstream a;
      int r = (cell[1]-'1')*8+(cell[0]-'a')%8+1;
      a << r;
      return a.str();
    }
    int r;
    stringstream a(cell);
    a >> r;
    return string(1,'a'+((r-1)%8))+string(1,'0'+((r+7)/8));    
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "1"; string Arg1 = "a1"; verify_case(0, Arg1, changeNotation(Arg0)); }
	void test_case_1() { string Arg0 = "2"; string Arg1 = "b1"; verify_case(1, Arg1, changeNotation(Arg0)); }
	void test_case_2() { string Arg0 = "26"; string Arg1 = "b4"; verify_case(2, Arg1, changeNotation(Arg0)); }
	void test_case_3() { string Arg0 = "c1"; string Arg1 = "3"; verify_case(3, Arg1, changeNotation(Arg0)); }
	void test_case_4() { string Arg0 = "e4"; string Arg1 = "29"; verify_case(4, Arg1, changeNotation(Arg0)); }
	void test_case_5() { string Arg0 = "h8"; string Arg1 = "64"; verify_case(5, Arg1, changeNotation(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  Chessboard ___test;
  ___test.run_test(-1);
}
// END CUT HERE
