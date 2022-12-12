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

const int kMod = 1000000009;

class DivisibleSequence {
 public:
  map<int,int> countdivisors(int n) {
    map<int,int> m;
    for (int i=2;i*i<=n;i++) {
      if (n%i == 0) {
        m[i] = 1;
        n/=i;
      }
      while (n%i == 0) {
        m[i] += 1;
        n/=i;
      }
    }
    if (n > 1) m[n] = 1;
    return m;
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
      r = ((n-i)*r*modInverse(i+1LL))%kMod;
    return r;
  }
  int count(int N, int H) {
    if (N == 1) return 1;
    map<int,int> m = countdivisors(N);
    long long r = 1;
    for (map<int,int>::iterator i = m.begin();i!=m.end();i++) {
      r=(r*bico(H-1+(*i).second,(*i).second))%kMod;
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 3; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 9; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 2; int Arg2 = 4; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 10000; int Arg2 = 1; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 30; int Arg1 = 4; int Arg2 = 64; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 25883; int Arg1 = 100000; int Arg2 = 991000009; verify_case(5, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  DivisibleSequence ___test;
  ___test.run_test(-1);
}
// END CUT HERE
