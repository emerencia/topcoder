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
map<vector<int>,double> mem;

class RandomSort {
 public:
  double exnum(vector<int>& permutation) {
    if (mem.count(permutation)) return mem[permutation];
    int tot = 0;
    double fac = 0;
    for (int i=0;i<permutation.size();i++)
      for (int j=i+1;j<permutation.size();j++)
        if (permutation[i] > permutation[j]) {
          tot++;
          swap(permutation[i],permutation[j]);
          fac += 1+exnum(permutation);
          swap(permutation[i],permutation[j]);
        }
    if (tot)
      return mem[permutation] = fac/double(tot);
    return mem[permutation] = 0;
  }
  double getExpected(vector <int> permutation) {
    mem.clear();
    return exnum(permutation);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (abs(Expected - Received) < 1e-9) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(0, Arg1, getExpected(Arg0)); }
	void test_case_1() { int Arr0[] = {4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4.066666666666666; verify_case(1, Arg1, getExpected(Arg0)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(2, Arg1, getExpected(Arg0)); }
	void test_case_3() { int Arr0[] = {2,5,1,6,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 5.666666666666666; verify_case(3, Arg1, getExpected(Arg0)); }
  void test_case_4() { int Arr0[] = {4, 1, 8, 3, 6, 5, 2, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 8.933333333333334; verify_case(4, Arg1, getExpected(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  RandomSort ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
