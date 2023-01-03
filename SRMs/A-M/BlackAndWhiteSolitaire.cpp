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

class BlackAndWhiteSolitaire {
 public:
  int minimumTurns(string cardFront) {
    if (cardFront.size() < 2) return 0;
    int c = 0;
    int c2 = 0;
    for (int i=0;i<cardFront.size();i++) {
      if ((i%2 && cardFront[i] == 'W') || (i%2 == 0 && cardFront[i] == 'B')) c++;
      if ((i%2 == 0 && cardFront[i] == 'W') || (i%2 && cardFront[i] == 'B')) c2++;
    }
    return min(c,c2);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BBBW"; int Arg1 = 1; verify_case(0, Arg1, minimumTurns(Arg0)); }
	void test_case_1() { string Arg0 = "WBWBW"; int Arg1 = 0; verify_case(1, Arg1, minimumTurns(Arg0)); }
	void test_case_2() { string Arg0 = "WWWWWWWWW"; int Arg1 = 4; verify_case(2, Arg1, minimumTurns(Arg0)); }
	void test_case_3() { string Arg0 = "BBWBWWBWBWWBBBWBWBWBBWBBW"; int Arg1 = 10; verify_case(3, Arg1, minimumTurns(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  BlackAndWhiteSolitaire ___test;
  ___test.run_test(-1);
}
// END CUT HERE
