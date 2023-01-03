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
#include <stack>
#include <cstring>
using namespace std;
//553 500

class Suminator {
 public:
  int findMissing(vector <int> program, int wantedResult) {
    bool f = true;
    int minusoneindex = 0;
    int zerobalance = 0;
    for (int i=program.size()-1;i>=0;i--) {
      if (program[i] == -1) { minusoneindex = i; break; }
      if (program[i] == 0) zerobalance++;
      else {
        zerobalance--;
        if (zerobalance < 0) f = false;
      }
    }
    stack<long long> s;
    for (int i=0;i<program.size();i++) {
      if (program[i] == -1) { s.push(0); continue; }
      if (program[i] == 0) { 
        long long a = 0;
        long long b = 0;
        if (!s.empty()) { a = s.top(); s.pop(); }
        if (!s.empty()) { b = s.top(); s.pop(); }
        s.push(a+b);
      } else {
        s.push(program[i]);
      }
    }
    if (!f) {
      if (wantedResult == s.top()) return 0;
      return -1;
    }
    int r = -1;
    if (wantedResult > s.top()) r = wantedResult-s.top();
    while (!s.empty()) s.pop();
    for (int i=0;i<program.size();i++) {
      if (program[i] == 0 || program[i] == -1) { 
        long long a = 0;
        long long b = 0;
        if (!s.empty()) { a = s.top(); s.pop(); }
        if (!s.empty()) { b = s.top(); s.pop(); }
        s.push(a+b);
      } else {
        s.push(program[i]);
      }
    }
    if (s.top() == wantedResult) return 0;
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {7,-1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 3; verify_case(0, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {100, 200, 300, 0, 100, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 600; int Arg2 = 0; verify_case(1, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1, 7, 3, 0, 1, 2, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; int Arg2 = 0; verify_case(2, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-1, 8, 4, 0, 1, 2, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; int Arg2 = -1; verify_case(3, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1000000000, 1000000000, 1000000000,  1000000000, -1, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; int Arg2 = -1; verify_case(4, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {7, -1, 3, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = -1; verify_case(5, Arg2, findMissing(Arg0, Arg1)); }
  void test_case_6() { int Arr0[] = {0, 1, -1, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(6, Arg2, findMissing(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  Suminator ___test;
  ___test.run_test(-1);
}
// END CUT HERE
