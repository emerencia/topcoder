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

class PolygonTraversal2 {
 public:
  int n;
  int first;
  int rec(int mask, vector<vector<bool> >& g, int prev) {
    if (mask == (1<<n)-1) {
      if ((prev+1)%n == first || (prev-1+n)%n == first) return 0;
      bool foundcrossing = false;
      for (int j=(prev+1)%n;j!=first;j=(j+1)%n)
        for (int k=(first+1)%n;k!=prev;k=(k+1)%n)
          if (g[j][k]) {
            foundcrossing = true;
            break;
          }
      return foundcrossing;
    }
    int r = 0;
    for (int i=0;i<n;i++) {
      if (mask&(1<<i)) continue;
      if ((prev+1)%n == i || (prev-1+n)%n == i) continue;
      bool foundcrossing = false;
      for (int j=(prev+1)%n;j!=i;j=(j+1)%n)
        for (int k=(i+1)%n;k!=prev;k=(k+1)%n)
          if (g[j][k]) {
            foundcrossing = true;
            break;
          }
      if (!foundcrossing) continue;
      g[prev][i] = 1;
      g[i][prev] = 1;
      r+=rec(mask|(1<<i),g,i);
      g[prev][i] = 0;
      g[i][prev] = 0;
    }
    return r;
  }
  int count(int N, vector <int> points) {
    n = N;
    first = points[0]-1;
    vector<vector<bool> > g(N,vector<bool>(N,false));
    int mask = (1<<(points[0]-1));
    for (int i =0;i+1<points.size();i++) {
      g[points[i]-1][points[i+1]-1] = 1;
      g[points[i+1]-1][points[i]-1] = 1;
      mask |= (1<<(points[i+1]-1));
    }
    mask |= (1<<(points.back()-1));
    return rec(mask,g,points.back()-1);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {1, 3, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; int Arr1[] = {1, 4, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 7; int Arr1[] = {2, 4, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arr1[] = {1, 2, 3, 4, 6, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 11; int Arr1[] = {1, 5, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1412; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  PolygonTraversal2 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
