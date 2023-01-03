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

class BigFatInteger2 {
 public:
  map<int,int> prime_factors(long long n) {
    map<int,int> r;
    for (int i=2;i*i<=n;i++) {
      int c = 0;
      while (n%i == 0) {
        c++;
        n/=i;
      }
      if (c)
        r[i] = c;
    }
    if (n > 1) r[n] = 1;
    return r;
  }
  string isDivisible(int A, int B, int C, int D) {
    map<int,int> a = prime_factors(A);
    map<int,int> c = prime_factors(C);
    for (map<int,int>::iterator i=c.begin();i!=c.end();i++)
      if (!a.count((*i).first) || (LL)a[(*i).first]*B < (LL)(*i).second*D)
        return "not divisible";
    return "divisible";
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 1; int Arg2 = 2; int Arg3 = 1; string Arg4 = "divisible"; verify_case(0, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 6; int Arg3 = 1; string Arg4 = "not divisible"; verify_case(1, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1000000000; int Arg1 = 1000000000; int Arg2 = 1000000000; int Arg3 = 200000000; string Arg4 = "divisible"; verify_case(2, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 100; int Arg2 = 4; int Arg3 = 200; string Arg4 = "not divisible"; verify_case(3, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 999999937; int Arg1 = 1000000000; int Arg2 = 999999929; int Arg3 = 1; string Arg4 = "not divisible"; verify_case(4, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 4; int Arg3 = 1; string Arg4 = "divisible"; verify_case(5, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3)); }
  void test_case_6() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1000000000; string Arg4 = "divisible"; verify_case(6, Arg4, isDivisible(Arg0, Arg1, Arg2, Arg3)); }
// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  BigFatInteger2 ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
