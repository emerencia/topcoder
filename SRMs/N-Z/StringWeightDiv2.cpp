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
// 11:10

const int kMod = 1e9+9;

class StringWeightDiv2 {
 public:
  long long factorial(long long x) {
    long long c = 1;
    for (long long i=1;i<=x;i++)
      c = (c*i)%kMod;
    return c;
  }
  long long modPow(long long x, long long y) {
    long long r=1;
    long long a=x;
    while (y > 0) {
        if ( (y&1)==1 ) {
            r = (r * a)%kMod;
        }
        a = (a * a)%kMod;
        y /= 2;
    }
    return r;
  }
  long long modInverse(long long x) {
    return modPow(x, kMod-2);
  }
  long long bico(long long n, long long k) {
    if (k < 0 || k > n) return 0;
    if (k > n-k) k = n-k;
    long long r = 1;
    for (long long i=0;i<k;i++)
      r = ((n-i)%kMod*r%kMod*modInverse(i+1LL))%kMod;
    return r;
  }
  int countMinimums(int L) {
    if (L <= 26) {
      return (factorial(26)*modInverse(factorial(26-L)))%kMod;
    }
    //return (factorial(26)*bico(L-1,L-26))%kMod;
    return (26LL*((factorial(L-1)*modInverse(factorial(L-26)))%kMod))%kMod;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 26; verify_case(0, Arg1, countMinimums(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 650; verify_case(1, Arg1, countMinimums(Arg0)); }
	void test_case_2() { int Arg0 = 50; int Arg1 = 488801539; verify_case(2, Arg1, countMinimums(Arg0)); }
  void test_case_3() { int Arg0 = 81; int Arg1 = 903534367; verify_case(3, Arg1, countMinimums(Arg0)); }
  void test_case_4() { int Arg0 = 100; int Arg1 = 997628957; verify_case(4, Arg1, countMinimums(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  StringWeightDiv2 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
