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

class Constellation {
 public:
  double expectation(vector <int> x, vector <int> y, vector <int> prob) {
    int n = x.size();
    double r = 0;
    for (int i=0;i<n;i++) {
      int x1 = x[i];
      int y1 = y[i];
      for (int j=0;j<n;j++) {
        if (j == i) continue;
        int x2 = x[j];
        int y2 = y[j];
        double pr = prob[i]*prob[j]/1000000.0;
        for (int k=0;k<n;k++) {
          if (k == i || k == j) continue;
          int x3 = x[k];
          int y3 = y[k];
          bool bad = false;
          int d = (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
          if (d < 0) bad = true; // if x3 lies right of x1->x2
          else if (d == 0) {
            int z1 = (x3-x1)*(x2-x1)+(y3-y1)*(y2-y1);
            int z2 = (x3-x2)*(x1-x2)+(y3-y2)*(y1-y2);
            if (z1 < 0 || z2 < 0) bad = true;
          }
          if (bad)
            pr *= (1000-prob[k])/1000.0;
        }
        r += pr*(x1*y2 - x2*y1);
      }
    }
    return r/2.0;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (abs(Expected-Received) <= 1e-9) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {500,500,500}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.0625; verify_case(0, Arg3, expectation(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,1,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000,1000,400,800}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.6000000000000001; verify_case(1, Arg3, expectation(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {-1,-1,-1,0,0,0,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,0,1,-1,0,1,-1,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {500,500,500,500,500,500,500,500,500}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 1.9375; verify_case(2, Arg3, expectation(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,1,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000,500,200,500,1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 1.3; verify_case(3, Arg3, expectation(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {1,5,5,8,2,6,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,6,4,2,5,7,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100,400,200,1000,400,900,600}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 12.888936; verify_case(4, Arg3, expectation(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {-100,100,-100,100,-42,57,-34,76,35,-75,-54,10,43}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-100,-100,100,100,52,-57,-84,63,-43,50,63,10,-44}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000,1000,1000,1000,342,747,897,325,678,34,53,6,253}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 40000.0; verify_case(5, Arg3, expectation(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  Constellation ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
