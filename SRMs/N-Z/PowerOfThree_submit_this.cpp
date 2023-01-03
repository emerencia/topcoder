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
typedef pair<LL,LL> PLL;
// BEGIN CUT HERE
const int toTest = -1;
// 
// END CUT HERE
map<PLL,bool> mem;
long long poww[21];

class PowerOfThree {
 public:
  long long x;
  long long y;
  int bitcount(int n) {
    int r = 0;
    for (int i=n;i;i&=i-1) ++r;
    return r;
  }
  long long pow(long long x, long long y) {
    long long r=1;
    long long a=x;
    while (y > 0) {
        if ( (y&1)==1 ) {
            r = (r * a);
        }
        a = (a * a);
        y /= 2;
    }
    return r;
  }
  bool rec(int steps, long long xx, long long yy) {
    //cout << xx << " " << yy << endl;
    if (mem.count(PLL(xx,yy))) return mem[PLL(xx,yy)];
    if (xx == x && yy == y) return mem[PLL(xx,yy)] = true;
    if (steps > 9) return mem[PLL(xx,yy)] = false;
    bool ans = false;
    if (x != xx) {
      if (xx + poww[steps] <= x)
        ans |= rec(steps+1,xx+poww[steps],yy);
      if (!ans)
        ans |= rec(steps+1,xx-poww[steps],yy);
    }
    if (!ans && y != yy) {
      if (yy + poww[steps] <= y)
        ans |= rec(steps+1,xx,yy+poww[steps]);
      if (!ans)
        ans |= rec(steps+1,xx,yy-poww[steps]);
    }
    return mem[PLL(xx,yy)]=ans;
  }
  string ableToGet(int x, int y) {
    for (int i=0;i<21;i++) poww[i] = pow(3,i);
    mem.clear();
    this->x = abs(x);
    this->y = abs(y);
    return (rec(0,0,0) ? "Possible" : "Impossible");
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 3; string Arg2 = "Possible"; verify_case(0, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 2; string Arg2 = "Possible"; verify_case(1, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 9; string Arg2 = "Impossible"; verify_case(2, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 0; string Arg2 = "Impossible"; verify_case(3, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1; string Arg2 = "Impossible"; verify_case(4, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = -6890; int Arg1 = 18252; string Arg2 = "Possible"; verify_case(5, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 1000000000; int Arg1 = -1000000000; string Arg2 = "Impossible"; verify_case(6, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_7() { int Arg0 = 0; int Arg1 = 0; string Arg2 = "Possible"; verify_case(7, Arg2, ableToGet(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  PowerOfThree ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
