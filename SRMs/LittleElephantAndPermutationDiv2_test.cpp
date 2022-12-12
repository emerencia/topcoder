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
#include <limits>
#include <cstring>
#include <numeric>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
// BEGIN CUT HERE
const int toTest = -1;
// 
// END CUT HERE

long long mem[2551][51][51];

class LittleElephantAndPermutationDiv2 {
 public:
  int N;
  int K;
  long long rec(int idx, int k, long long empty, long long top, long long bottom) {
    LL& res = mem[k][empty][top];
    if (res != -1) return res;
    if (idx == 0) {
      return res=(k >= K);
    }
    long long r = 0;
    if (empty > 1)
      r+=empty*(empty-1LL)*rec(idx-1,k+2*idx,empty-2,top+1,bottom+1);
    if (empty)
      r+=empty*rec(idx-1,k+idx,empty-1,top,bottom);
    if (top && empty)
      r+=top*empty*rec(idx-1,k+idx,empty-1,top,bottom);
    if (bottom && empty)
      r+=bottom*empty*rec(idx-1,k+idx,empty-1,top,bottom);
    if (top && bottom)
      r+=bottom*top*rec(idx-1,k,empty,top-1,bottom-1);
    return res=r;
  }
  long long getNumber(int N, int K) {
    this->N = N;
    this->K = K;
    memset(mem,-1,sizeof(mem));
    long long a = rec(N,0,N,0,0);
    return a;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; long long Arg2 = 1LL; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; long long Arg2 = 4LL; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 8; long long Arg2 = 18LL; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 47; long long Arg2 = 13168189440000LL; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  LittleElephantAndPermutationDiv2 ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
