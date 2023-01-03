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
typedef pair<int,int> PII;

class MarblePositioning {
 public:
  double distbetween(long long a, long long b) {
    if (a < b) swap(a,b);
    return sqrt((a+b)*(a+b)-(b-a)*(b-a));
  }
  double totalWidth(vector <int> radius) {
    int n = radius.size();
    vector<vector<double> > dist(n,vector<double>(n,0.0));
    for (int i=0;i<n;i++)
      for (int j=0;j<n;j++)
        dist[i][j] = distbetween(radius[i],radius[j]);
    double mind = -1.0;
    sort(radius.begin(),radius.end());
    do {
      vector<double> start(n,0.0);
      for (int i=0;i+1<n;i++) {
        for (int j=0;j<=i;j++) 
          start[i+1] = max(start[i+1],start[j]+distbetween(radius[j],radius[i+1]));
      }
      if (mind == -1.0 || start[n-1] < mind) mind = start[n-1];
    } while(next_permutation(radius.begin(),radius.end()));
    return mind;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (abs(Expected - Received) < 1e-9) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.8284271247461903; verify_case(0, Arg1, totalWidth(Arg0)); }
	void test_case_1() { int Arr0[] = {7,7,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 28.0; verify_case(1, Arg1, totalWidth(Arg0)); }
	void test_case_2() { int Arr0[] = {10, 20, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 62.92528739883945; verify_case(2, Arg1, totalWidth(Arg0)); }
	void test_case_3() { int Arr0[] = {100, 100,11,11,25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 200.0; verify_case(3, Arg1, totalWidth(Arg0)); }
	void test_case_4() { int Arr0[] = {1,999950884,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 63246.0; verify_case(4, Arg1, totalWidth(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  MarblePositioning ___test;
  ___test.run_test(-1);
}
// END CUT HERE
