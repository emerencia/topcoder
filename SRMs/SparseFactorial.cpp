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

class SparseFactorial {
 public:
  vector<PII> prime_factors(long long n) { // (num,exp)
    vector<PII> r;
    if (n == 1) {
      r.push_back(PII(1,1));
      return r;
    }
    for (int i=2;i*i<=n;i++) {
      int c = 0;
      while (n%i == 0) {
        c++;
        n/=i;
      }
      if (c) r.push_back(PII(c,i));
    }
    if (n > 1) r.push_back(PII(1,n));
    return r;
  }
  long long getCount(long long lo, long long hi, long long divisor) {
    if (divisor > hi) return 0;
    
    vector<vector<long long> > remainders;
    vector<long long> remainder(divisor,1e15);
    for (long long j=0;j*j<=hi;j++)
      if (remainder[(j*j)%divisor] == 1e15)
        remainder[(j*j)%divisor] = j*j+divisor;
    long long r = 0;
    long long end = min(lo+divisor,hi+1);
    for (long long i=lo;i<end;i++) {
      if (remainder[i%divisor] != 1e15 && remainder[i%divisor] <= hi) {
        long long start = max(i,remainder[i%divisor]);
        r+=1LL+(hi-start)/divisor;
      }
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; long long Arg1 = 8LL; long long Arg2 = 6LL; long long Arg3 = 3LL; verify_case(0, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 9LL; long long Arg1 = 11LL; long long Arg2 = 7LL; long long Arg3 = 1LL; verify_case(1, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 1LL; long long Arg1 = 1000000000000LL; long long Arg2 = 4LL; long long Arg3 = 999999999996LL; verify_case(2, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arg0 = 55LL; long long Arg1 = 66LL; long long Arg2 = 98LL; long long Arg3 = 7LL; verify_case(3, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_4() { long long Arg0 = 999990LL; long long Arg1 = 999999LL; long long Arg2 = 589824LL; long long Arg3 = 7LL; verify_case(4, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_5() { long long Arg0 = 100000000LL; long long Arg1 = 100000050LL; long long Arg2 = 749910LL; long long Arg3 = 8LL; verify_case(5, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_6() { long long Arg0 = 7777777776LL; long long Arg1 = 7777777777LL; long long Arg2 = 994009LL; long long Arg3 = 1LL; verify_case(6, Arg3, getCount(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  SparseFactorial ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
