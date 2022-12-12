#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <climits>
#include <utility>
using namespace std;

typedef pair<int,int> pi;

class ImportantSequence {
 public:
  int getCount(vector <int> B, string operators) {
    long long c=0;
    long long lb = 0;
    long long ub = LLONG_MAX;
    int s = 1;
    for (int i=0;i<B.size();i++) {
     if (operators[i] == '+') {
       c = B[i]-c;
       // c + x = B[i]
       // x = B[i]-c   // lb =   B[i]-ub
                       // ub =   B[i]-lb
       s*=-1;
     } else {
       // c - x = B[i]    // lb = lb-B[i]
       // x = c-B[i]      // ub = ub-B[i]
       c = c-B[i];
     }
     if (s == -1) {
       ub = min(ub,c);
     } else {
       lb = max(lb,-c);
     }
    }
    if (ub == LLONG_MAX) return -1;
    if (ub <= lb) return 0;
    return ub-lb-1;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, -1, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "+-+"; int Arg2 = 2; verify_case(0, Arg2, getCount(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "-"; int Arg2 = -1; verify_case(1, Arg2, getCount(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "+"; int Arg2 = 0; verify_case(2, Arg2, getCount(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "+"; int Arg2 = 9; verify_case(3, Arg2, getCount(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {540, 2012, 540, 2012, 540, 2012, 540}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "-+-+-+-"; int Arg2 = 1471; verify_case(4, Arg2, getCount(Arg0, Arg1)); }
  void test_case_5() { int Arr0[] = {7, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 999999999, 1234, 4311}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "-------+--"; int Arg2 = 999994453; verify_case(5, Arg2, getCount(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ImportantSequence ___test;
  ___test.run_test(-1);
}
// END CUT HERE
