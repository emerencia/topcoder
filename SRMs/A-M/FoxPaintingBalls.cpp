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

class FoxPaintingBalls {
 public:
  long long theMax(long long R, long long G, long long B, int N) {
    long long n = N;
    if (N == 1) return R+G+B;
    if (R == 0 || G == 0 || B == 0) return 0;
    vector<long long> balls(3);
    balls[0] = R;
    balls[1] = G;
    balls[2] = B;
    sort(balls.begin(),balls.end());
    if (N == 1) return balls[2];
    long long ballsn = (n*(n+1LL)/2LL)%3;
    long long ballsu = (n*(n+1LL)/2LL)/3LL;  
    if (ballsn == 0) return balls[0]/ballsu;
    long long mx = balls[0]/ballsu;
    return min(mx,(balls[0]+balls[1]+balls[2])/(3*ballsu+ballsn));
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 2LL; long long Arg2 = 2LL; int Arg3 = 3; long long Arg4 = 1LL; verify_case(0, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 2LL; long long Arg2 = 3LL; int Arg3 = 3; long long Arg4 = 0LL; verify_case(1, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { long long Arg0 = 8LL; long long Arg1 = 6LL; long long Arg2 = 6LL; int Arg3 = 4; long long Arg4 = 2LL; verify_case(2, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { long long Arg0 = 7LL; long long Arg1 = 6LL; long long Arg2 = 7LL; int Arg3 = 4; long long Arg4 = 2LL; verify_case(3, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { long long Arg0 = 100LL; long long Arg1 = 100LL; long long Arg2 = 100LL; int Arg3 = 4; long long Arg4 = 30LL; verify_case(4, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { long long Arg0 = 19330428391852493LL; long long Arg1 = 48815737582834113LL; long long Arg2 = 11451481019198930LL; int Arg3 = 3456; long long Arg4 = 5750952686LL; verify_case(5, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { long long Arg0 = 1LL; long long Arg1 = 1LL; long long Arg2 = 1LL; int Arg3 = 1; long long Arg4 = 3LL; verify_case(6, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  FoxPaintingBalls ___test;
  ___test.run_test(-1);
}
// END CUT HERE
