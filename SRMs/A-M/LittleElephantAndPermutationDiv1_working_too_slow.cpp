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
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<PII,LL> PIL;
// BEGIN CUT HERE
const int toTest = -1;
// 
// END CUT HERE

const int kMod = 1e9+7;
map<PIL,LL> mem;

class LittleElephantAndPermutationDiv1 {
 public:
  int N;
  int K;
  long long factorial(long long x) {
    long long c = 1;
    for (long long i=1;i<=x;i++)
      c = (c*i)%kMod;
    return c;
  }
  long long rec(int idx, long long used, int k) {
    if (idx == N) {
      return (k >= K);
    }
    PIL p = PIL(PII(idx,k),used);
    if (mem.count(p)) return mem[p];
    long long r = 0;
    for (int i=0;i<N;i++) {
      if (used&(1LL<<i)) continue;
      (r += rec(idx+1,used|(1LL<<i),k+max(idx,i)+1))%=kMod;
    }
    return mem[p]=r;
  }
  int getNumber(int N, int K) {
    this->N = N;
    this->K = K;
    mem.clear();
    long long a = rec(0,0,0);
    (a *= factorial(N))%=kMod;
    //(a *= a)%=kMod;
    return a;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 4; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 8; int Arg2 = 18; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 74; int Arg2 = 484682624; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 1000; int Arg2 = 539792695; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  LittleElephantAndPermutationDiv1 ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
