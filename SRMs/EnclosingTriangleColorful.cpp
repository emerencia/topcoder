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

bool allleftofline[1201][1201];

class EnclosingTriangleColorful {
 public:
  int left_of_or_on_line(const PII& p, const PII& from, const PII& to) {
    int d = (to.first-from.first)*(p.second -from.second) -
    (to.second-from.second)*(p.first - from.first);
    return d;
  }
  int getNumber(int m, vector <int> x, vector <int> y) {
    int k = m-1;
    vector<PII> points(k*4);
    for (int i=0;i<points.size();i++) {
      if (i/k == 0) points[i] = PII(i+1,m);
      else if (i/k == 1) points[i] = PII(m,m-(i%k)-1);
      else if (i/k == 2) points[i] = PII(m-(i%k)-1,0);
      else points[i] = PII(0,(i%k)+1);
    }
    vector<PII> bl(x.size());
    for (int i=0;i<bl.size();i++)
      bl[i] = PII(x[i],y[i]);
    int r = 0;
    for (int i=0;i<k*4;i++)
      for (int j=i+1;j<k*4;j++) {
        bool allleft = true;
        bool allright = true;
        for (int d=0;d<bl.size();d++) {
          int a = left_of_or_on_line(bl[d],points[i],points[j]);
          if (!a) continue;
          if (a > 0) {
            allright = false;
            if (!allleft) break;
          } else {
            allleft = false;
            if (!allright) break;
          }
        }
        allleftofline[i][j] = allleft;
        allleftofline[j][i] = allright;
      }
    for (int i=0;i<2*k;i++) {
      for (int j=((i/k)+1)*k;j<3*k;j++) {
        // all points have to be left of the line from j to i
        if (!allleftofline[j][i]) continue;
        for (int l=((j/k)+1)*k;l<4*k;l++) {
          // they need to be on right hand side of all
          r += (allleftofline[l][j] & allleftofline[i][l]);
        }
      }
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = { 1, 2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1, 3, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(0, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 7; int Arr1[] = { 1, 1, 6, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1, 6, 1, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(1, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arr1[] = { 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 72; verify_case(2, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10; int Arr1[] = { 2, 6, 7, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 7, 7, 9, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 52; verify_case(3, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 15; int Arr1[] = { 7, 6, 5, 4, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1, 4, 7, 10, 13 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 150; verify_case(4, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 300; int Arr1[] = { 117, 183, 181, 118, 132, 128, 184, 150, 168, 121, 
  179, 132, 168, 182, 119, 117, 180, 120, 175, 177, 
  116, 175, 128, 163, 181, 178, 123, 118, 172, 143, 
  163, 157, 179, 122, 121, 119, 157, 122, 150, 180, 
  137, 177, 125, 123, 172, 125, 137, 143, 120, 178 }
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 157, 157, 132, 163, 181, 180, 150, 116, 181, 125, 
  125, 119, 119, 163, 132, 143, 172, 172, 179, 178, 
  150, 121, 120, 118, 168, 123, 178, 137, 120, 117, 
  182, 117, 175, 177, 175, 168, 183, 123, 184, 128, 
  118, 122, 179, 122, 180, 121, 182, 183, 128, 177 }
; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 21690886; verify_case(5, Arg3, getNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  EnclosingTriangleColorful ___test;
  ___test.run_test(-1);
}
// END CUT HERE
