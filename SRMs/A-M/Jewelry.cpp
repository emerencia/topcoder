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

const int m = 30001;
long long waysabove[31][m];
long long waysbelow[31][m];
long long comb[31][31];

class Jewelry {
 public:
  void docomb() {
    for (int i=0;i<31;i++) {
      comb[i][0] = comb[i][i] = 1;
      for (int j=1;j<i;j++)
        comb[i][j] = comb[i-1][j]+comb[i-1][j-1];
    }
  }
  long long bico(int n, int k) {
    if (k > n-k) k = n-k;
    return comb[n][k];
  }
  long long howMany(vector <int> values) {
    memset(waysabove,0,sizeof(waysabove));
    memset(waysbelow,0,sizeof(waysbelow));
    docomb();
    long long a = 0;
    int n = values.size();
    sort(values.begin(),values.end());
    waysbelow[0][0] = 1;
    for (int i=1;i<n;i++) {
      for (int k=0;k<m;k++) {
        waysbelow[i][k]=waysbelow[i-1][k];
        if (k>=values[i-1]) 
          waysbelow[i][k]+=waysbelow[i-1][k-values[i-1]];
      }
    }
    sort(values.rbegin(),values.rend());
    waysabove[0][0] = 1;
    for (int i=1;i<n;i++) {
      for (int k=0;k<m;k++) {
        waysabove[i][k]=waysabove[i-1][k];
        if (k>=values[i-1]) 
          waysabove[i][k]+=waysabove[i-1][k-values[i-1]];
      }
    }
    sort(values.begin(),values.end());
    vector<int> h;
    vector<int> s;
    int last = -1;
    for (int i=0;i<n;i++) {
      if (last == values[i]) continue;
      if (h.size()) s.push_back(i-h.back());
      h.push_back(i);
      last = values[i];
    }
    s.push_back(n-h.back());
    for (int i=0;i<h.size();i++) {
      for (int g=0;g<s[i];g++) {
        int b = h[i]+g;
        for (int k=(g+1)*values[b];k<m;k++) {
          a += waysbelow[h[i]][k-(g+1)*values[b]] * 
               waysabove[n-1-(h[i]+g)][k] *
               bico(s[i],g+1);
        }
      }
    }
    return a;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,5,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9LL; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { int Arr0[] = {1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 18252025766940LL; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { int Arr0[] = {7,7,8,9,10,11,1,2,2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 607LL; verify_case(3, Arg1, howMany(Arg0)); }
	void test_case_4() { int Arr0[] = {123,217,661,678,796,964,54,111,417,526,917,923}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(4, Arg1, howMany(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  Jewelry ___test;
  ___test.run_test(-1);
}
// END CUT HERE
