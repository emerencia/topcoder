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

const int kMod = 1e9+9;

class StringPath {
 public:
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
  int countBoards(int n, int m, string A, string B) {
    if (A[0] != B[0] || A[A.size()-1] != B[B.size()-1]) return 0;
    if (m < n) swap(n,m);
    // n is min(n,m)
    // m is max(n,m)
    long long base = 1LL;
    long long r = 1;
    for (int i=0;i<n+m-1;i++) {
      if (base != 1) {
        if (A[i] == B[i]) {
          r *= (base*modPow(25,base-1))%kMod;
        } else {
          r *= (2LL*bico(base,2)*modPow(24,base-2))%kMod;
        }
        r %= kMod;
      }
      if (base < n && i+1 < m) base++;
      if (i+1 >= m) base--;
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; string Arg2 = "ABC"; string Arg3 = "ADC"; int Arg4 = 2; verify_case(0, Arg4, countBoards(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; string Arg2 = "ABC"; string Arg3 = "ABD"; int Arg4 = 0; verify_case(1, Arg4, countBoards(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 4; string Arg2 = "ABCDDE"; string Arg3 = "ACCBDE"; int Arg4 = 1899302; verify_case(2, Arg4, countBoards(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 8; string Arg2 = "ZZZZZZZZZZZZZZZ"; string Arg3 = "ZABCDEFGHIJKLMZ"; int Arg4 = 120390576; verify_case(3, Arg4, countBoards(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  StringPath ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
