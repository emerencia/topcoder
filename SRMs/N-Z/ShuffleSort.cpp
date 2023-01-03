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
// 568 1000

class ShuffleSort {
 public:
  double shuffle(vector <int> cards) {
    vector<int> hist(51,0);
    int c = cards.size();
    for (int i=0;i<cards.size();i++) {
      hist[cards[i]]++;
    }
    double a = 1.0;
    for (int i=0;i<hist.size();i++) {
      for (int j=0;j<hist[i];j++) {
        // -1 because we dont shuffle when we reach
        // a new card or the same card, and because
        // the answer starts at 1.0 as well
        a+= -1 + double(c)/double(hist[i]-j);
        c--;
      }
    }
    return a;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(0, Arg1, shuffle(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.0; verify_case(1, Arg1, shuffle(Arg0)); }
	void test_case_2() { int Arr0[] = {2,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4.0; verify_case(2, Arg1, shuffle(Arg0)); }
	void test_case_3() { int Arr0[] = {15,16,4,8,42,23}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 16.0; verify_case(3, Arg1, shuffle(Arg0)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,1,1,1,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(4, Arg1, shuffle(Arg0)); }
void test_case_5() { int Arr0[] = {1,1,2,2,3,3}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 10.0; verify_case(5, Arg1, shuffle(Arg0)); }
// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ShuffleSort ___test;
  ___test.run_test(-1);
}
// END CUT HERE
