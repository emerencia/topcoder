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
typedef pair<double,double> PDD;
typedef long long LL;

class TriangleXor {
 public:
  double triangleArea(double x1, double y1, double x2, double y2, double x3, double y3) {
    x1 -= x3; y1 -= y3; x2 -= x3; y2 -= y3;
    return (x1 * y2 - x2 * y1) / 2;
  }
  PDD intersection(double x1s, double y1s, double x1e, double y1e, double x2s, double y2s, double x2e, double y2e) {
    double m = ((y1e-y1s)*x1s+(x1e-x1s)*y2s-(x1e-x1s)*y1s-(y1e-y1s)*x2s)/((y1e-y1s)*(x2e-x2s)-(x1e-x1s)*(y2e-y2s));
    return PDD(x2s+m*(x2e-x2s),y2s+m*(y2e-y2s));
  }
  int theArea(int W) {
    // Four sections
    double r = 0;
    // upper part
    if (W%2 == 0) {
      r+= W/4.0;
    }
    // left and right part
    // last part is black
    // part W-1 to part W don't count
    // so start at part W-1 minues part W-2 then go 2 down
    for (int i = W-(1-W%2);i>0;i-=2) {
      // surface current
      PDD ip = intersection(0,0,W,1,0,1,i,0); // how to do this better
      PDD ipp = intersection(0,0,W,1,0,1,i-1,0);
      r += 2*(triangleArea(0,0,ip.first,ip.second,0,1)-
              triangleArea(0,0,ipp.first,ipp.second,0,1));

    }
    // bottom part
    for (int i = 1;i<W;i+=2) {
      PDD ipd = intersection(0,0,W,1,0,1,i-1,0);
      PDD ipu = intersection(0,0,W,1,0,1,i+1,0);
      PDD ipc = intersection(0,0,W,1,0,1,i,0);
      double h = ipu.second-ipd.second;
      double w = W-2*ipc.first;
      r+=0.5*h*w;
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 0; verify_case(0, Arg1, theArea(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; verify_case(1, Arg1, theArea(Arg0)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 1; verify_case(2, Arg1, theArea(Arg0)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 2; verify_case(3, Arg1, theArea(Arg0)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 2; verify_case(4, Arg1, theArea(Arg0)); }
	void test_case_5() { int Arg0 = 12345; int Arg1 = 4629; verify_case(5, Arg1, theArea(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  TriangleXor ___test;
  ___test.run_test(-1);
}
// END CUT HERE
