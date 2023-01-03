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
// BEGIN CUT HERE
const int toTest = -1;
// 18:59-19:25-19:57
// END CUT HERE

class XorCards {
 public:
  int rank(vector<vector<int> > a, vector<int> b, int p) {
    // p is the mod
    int n = a.size();    // n == number of variables (b also has size n) 
    int m = a[0].size(); // m == number of equations
    int r = 0;
    vector<bool> used(n,false);
    for (int i=0;i<m;i++) {
      int j = 0;
      while (j < n && (used[j] || a[j][i] == 0)) ++j;
      if (j == n) continue;
      used[j] = 1;
      ++r;
      for (int k=0;k<n;k++) {
        if (used[k]) continue;
        for (int l=0;l<p;l++)
          if ((l*a[j][i] + a[k][i])%p == 0) {
            for (int g=0;g<m;g++)
              a[k][g] = (a[k][g] + l*a[j][g])%p;
            b[k] = (b[k] + l*b[j])%p;
            break;
          }
      }
    }
    for (int i=0;i<n;i++)
      if (!used[i] && b[i]) return -1;
    return r;
  }
  long long numberOfWays(vector<long long> number, long long limit) {
    long long r = 0;
    int m = number.size();
    { // the equals case
      int i = 0;
      long long nlim = (limit >> (i));
      int n = 50-i;
      vector<int> b(n);
      for (int j=0;j<b.size();j++)
        b[j] = ((nlim >> j)&1LL);
      vector<vector<int> > a(n,vector<int>(m));
      for (int k=0;k<n;k++)
        for (int j=0;j<m;j++)
          a[k][j] = ((number[j] >> (k+i))&1LL);
      int rnk = rank(a,b,2);
      if (rnk != -1)
        r+=(1LL<<(m-rnk));
    }
    for (int i=0;i<50;i++) {
      if (!(limit&(1LL<<i))) continue;
      long long nlim = (limit >> (i+1)) << 1;
      int n = 50-i;
      vector<int> b(n);
      for (int j=0;j<b.size();j++)
        b[j] = ((nlim >> j)&1LL);
      vector<vector<int> > a(n,vector<int>(m));
      for (int k=0;k<n;k++)
        for (int j=0;j<m;j++)
          a[k][j] = ((number[j] >> (k+i))&1LL);
      int rnk = rank(a,b,2);
      if (rnk != -1)
        r+=(1LL<<(m-rnk));
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long Arr0[] = {1,2}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; long long Arg2 = 3LL; verify_case(0, Arg2, numberOfWays(Arg0, Arg1)); }
	void test_case_1() { long Arr0[] = {5,5}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3LL; long long Arg2 = 2LL; verify_case(1, Arg2, numberOfWays(Arg0, Arg1)); }
	void test_case_2() { long Arr0[] = {1,2,3,4,5,6,7}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; long long Arg2 = 96LL; verify_case(2, Arg2, numberOfWays(Arg0, Arg1)); }
	void test_case_3() { long Arr0[] = {123, 456, 789, 147, 258, 369, 159, 357}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 500LL; long long Arg2 = 125LL; verify_case(3, Arg2, numberOfWays(Arg0, Arg1)); }
	void test_case_4() { long Arr0[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1000000000000000LL; long long Arg2 = 4294967296LL; verify_case(4, Arg2, numberOfWays(Arg0, Arg1)); }
	void test_case_5() { long long Arr0[] = {1000000000000000, 999999999999999}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 65535LL; long long Arg2 = 2LL; verify_case(5, Arg2, numberOfWays(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  XorCards ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
