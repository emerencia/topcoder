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
using namespace std;

class FractionInDifferentBases {
 public:
   long long lcm_primes(long long n) {
     long long r = 1;
     for (long long i=2;i*i<=n;i++) {
       if (n%i == 0) {
         r*=i;
         n/=i;
       }
       if (n) {
         while (n%i == 0) {
           n/= i;
         }
       }
     }
     if (n != 0) r*= n;
     return r;
   }
   long long gcd(long long a,long long b) {
     if (b == 0) return a;
     return gcd(b,a%b);
   }
  long long getNumberOfGoodBases(long long P, long long Q, long long A, long long B) {
    long long g = gcd(P,Q);
    //long long p = P/g;
    long long q = Q/g;
    long long pp = lcm_primes(q);
    long long nr_fin = B/pp - (A-1)/pp;
    long long nr_inf = B-(A-1)-nr_fin;
    return nr_inf;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 2LL; long long Arg2 = 10LL; long long Arg3 = 10LL; long long Arg4 = 0LL; verify_case(0, Arg4, getNumberOfGoodBases(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 9LL; long long Arg2 = 9LL; long long Arg3 = 10LL; long long Arg4 = 1LL; verify_case(1, Arg4, getNumberOfGoodBases(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { long long Arg0 = 5LL; long long Arg1 = 6LL; long long Arg2 = 2LL; long long Arg3 = 10LL; long long Arg4 = 8LL; verify_case(2, Arg4, getNumberOfGoodBases(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { long long Arg0 = 2662LL; long long Arg1 = 540LL; long long Arg2 = 2LL; long long Arg3 = 662LL; long long Arg4 = 639LL; verify_case(3, Arg4, getNumberOfGoodBases(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { long long Arg0 = 650720LL; long long Arg1 = 7032600LL; long long Arg2 = 2012LL; long long Arg3 = 2012540LL; long long Arg4 = 2010495LL; verify_case(4, Arg4, getNumberOfGoodBases(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  FractionInDifferentBases ___test;
  ___test.run_test(-1);
}
// END CUT HERE
