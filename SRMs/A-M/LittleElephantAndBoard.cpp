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
const int kMod = 1e9+7;
const int kSize = 1000001;
int fact[kSize];
int inv[kSize];

long long pw(int a, int b) {
  int x = 1, step = 1 << 30;
  while (step > 0) {
    x = (long long)x * x % kMod;
    if (step & b) x = (long long)x * a % kMod;
    step >>= 1;
  }
  return x;
}
long long bico(int n, int k) {
  if (n < 0 || k < 0 || k > n) return 0;
  int x = fact[n];
  int y = inv[k];
  int z = inv[n - k];
  return (long long)x * y % kMod * z % kMod;
}

class LittleElephantAndBoard {
 public:  
  long long count(int x, int y, int z) {
    if (x <= 0) return 0;
    long long res = 0;
    for (int g=x-1;g<=x;g++) {
      long long xp = 1;
      for (int e=0;e<=g;e++) {
        if (!((g-e+y-z)%2)) {
          int oy = (g-e+y-z)/2;
          int oz = g-e-oy;
          if (oy >= 0 && oz >= 0 && y-oy >= 0) {
            int r = y-oy-e; // divide the remaining ys over all the groups
            if (r >= 0) {   // they uniquely define the sequence, so no need to
                            // also divide oz
                            // bico(r+g-1,r) is: assign the remaining y to any of the g groups
                            // bico(g,e) is the number of ways to pick e subsets out of g subsets
                            // because we have g positions to put groups, and e of them have to be even
                            // bico(g-e,oy): g-e = oy+oz, determine the positions of which are the odd groups are the ones starting with y, and which are the odd groups starting with z
                            // xp is: every even group can start with y or z, so times 2
                            // for every even group
              (res+=(((((bico(r+g-1,r)*bico(g,e))%kMod)*bico(g-e,oy))%kMod)*xp)%kMod)%=kMod;
            }
          }
        }
        xp = (xp+xp)%kMod;
      }
    }
    return res;
  }
  int getNumber(int M, int R, int G, int B) {
    fact[0] = 1;
    for (int i = 1; i < kSize; i++) fact[i] = (long long)fact[i - 1] * i % kMod;
    inv[0] = 1;
    for (int i = 1; i < kSize; i++) inv[i] = pw(fact[i], kMod - 2);
    int k = M-R;
    int j = M-G;
    int i = M-B;
    long long cur = 0;
    (cur += 2LL*count(i,j,k))%= kMod;
    (cur += 2LL*count(j,i,k))%= kMod;
    (cur += 2LL*count(k,j,i))%= kMod;
    return cur;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; int Arg4 = 4; verify_case(0, Arg4, getNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 0; int Arg4 = 0; verify_case(1, Arg4, getNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 7; int Arg2 = 7; int Arg3 = 6; int Arg4 = 496; verify_case(2, Arg4, getNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 474; int Arg1 = 250; int Arg2 = 300; int Arg3 = 398; int Arg4 = 969878317; verify_case(3, Arg4, getNumber(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  LittleElephantAndBoard ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
