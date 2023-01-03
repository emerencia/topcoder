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

long long mem[61];

class TrafficCongestionDivTwo {
 public:
  long long rec(int h) {
    long long& r = mem[h];
    if (r != -1) return r;
    long long t = 1;
    for (int i=0;i+1<h;i++)
      t+=2LL*rec(i);
    return r = t;
  }
  long long theMinCars(int treeHeight) {
    memset(mem,-1,sizeof(mem));
    mem[0] = 1;
    return rec(treeHeight);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; long long Arg1 = 1LL; verify_case(0, Arg1, theMinCars(Arg0)); }
	void test_case_1() { int Arg0 = 2; long long Arg1 = 3LL; verify_case(1, Arg1, theMinCars(Arg0)); }
	void test_case_2() { int Arg0 = 3; long long Arg1 = 5LL; verify_case(2, Arg1, theMinCars(Arg0)); }
	void test_case_3() { int Arg0 = 10; long long Arg1 = 683LL; verify_case(3, Arg1, theMinCars(Arg0)); }
	void test_case_4() { int Arg0 = 60; long long Arg1 = 768614336404564651LL; verify_case(4, Arg1, theMinCars(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  TrafficCongestionDivTwo ___test;
  ___test.run_test(-1);
}
// END CUT HERE
