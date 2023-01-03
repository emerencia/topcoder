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

typedef pair<double,double> PDD;
const double PI = acos(-1);
const double kInf = 1e50;

class FencingPenguinsEasy {
 public:
  double triangleArea(double x1, double y1, double x2, double y2, double x3, double y3) {
      x1 -= x3; y1 -= y3; x2 -= x3; y2 -= y3;
      return (x1 * y2 - x2 * y1) / 2;
  }
  bool ccw(double x1, double y1, double x2, double y2, double x3, double y3) {
    double xt = x2-x1;
    double yt = y2-y1;
    double d = xt*(y3-y1) - yt*(x3-x1);
    return d > 0;
  }
  bool ccwa(double x1, double y1, double x2, double y2, double x3, double y3){
    x1 -= x3; y1 -= y3; x2 -= x3; y2 -= y3;
    double s = x1 * y2 - x2 * y1;
    return (s > 0);
  }
  double calculateMinArea(int numPosts, int radius, vector <int> x, vector <int> y) {
    // calculate posts coordinates
    vector<PDD> posts(numPosts);
    for (int i=0;i<numPosts;i++) {
      double rad = i * 2 * PI / numPosts;
      posts[i] = PDD(radius*cos(rad),radius*sin(rad));
    }
    // calculate whether each post edge is valid
    vector<vector<int> > valid(numPosts,vector<int>(numPosts,true));
    for (int i=0;i<numPosts;i++)
      for (int j=0;j<numPosts;j++) {
        bool ok = true;
        for (int k=0;k<x.size();k++)
          if (!ccw(posts[i].first,posts[i].second,
                   posts[j].first,posts[j].second,
                   x[k],y[k])) {
            ok = false;
            break;
          }
        if (!ok) valid[i][j] = false;
      }
    // calculate dp area
    vector<vector<double> > dp(numPosts,vector<double>(numPosts,kInf));
    for (int i=0;i<numPosts;i++) dp[i][i] = 0.0;
    for (int k=1;k<numPosts;k++)
      for (int i=0;i+k<numPosts;i++) {
        int r = i+k;
        for (int j=i+1;j<=r;j++) {
          if (!valid[i][j]) continue;
          double area = triangleArea(posts[i].first,posts[i].second,
                                     posts[j].first,posts[j].second,
                                     posts[r].first,posts[r].second);
          dp[i][r] = min(dp[i][r],area+dp[j][r]);
        }
      }
    // return result
    double r = kInf;
    for (int i=0;i<numPosts;i++)
      for (int j=i+2;j<numPosts;j++) {
        if (!valid[j][i]) continue;
        r = min(r,dp[i][j]);
      }
    return (r < kInf ? r : -1);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (abs(Expected - Received) < 1e-7) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 5; int Arr2[] = {-1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 32.47595264191645; verify_case(0, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 30; int Arg1 = 5; int Arr2[] = {6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = -1.0; verify_case(1, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 5; int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 25.0; verify_case(2, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 5; int Arr2[] = {2,-2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,-1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 50.0; verify_case(3, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 8; int Arg1 = 5; int Arr2[] = {8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {8}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = -1.0; verify_case(4, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 7; int Arg1 = 10; int Arr2[] = {9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 29.436752637711805; verify_case(5, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arg0 = 30; int Arg1 = 800; int Arr2[] = {8,2,100,120,52,67,19,-36}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-19,12,88,-22,53,66,-140,99}
; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 384778.74757953023; verify_case(6, Arg4, calculateMinArea(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  FencingPenguinsEasy ___test;
  ___test.run_test(-1);
}
// END CUT HERE
