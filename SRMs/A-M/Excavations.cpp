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

long long comb[51][51];
long long mem[52][52][52];

class Excavations {
 public:
  vector<int> ndepth;
  vector<int> kind;
  vector<int> kcount;
  vector<int> fcount;
  long long rec(int typei, int max_depth, int remaining, int extra) {
    long long& r = mem[typei][max_depth][extra];
    if (r != -1) return r;
    if (typei == 51) {
      int cnt = 0;
      for (int i=0;i<kind.size();i++)
        if (!fcount[kind[i]] && ndepth[i] > max_depth)
          cnt++;
      return r = comb[cnt+extra][remaining];
    }
    if (!fcount[typei])
      return r = rec(typei+1,max_depth,remaining,extra);
    long long ta = 0;
    vector<int> tocall;
    for (int i=0;i<kind.size();i++)
      if (kind[i] == typei) {
        tocall.push_back(ndepth[i]);
      }
    sort(tocall.begin(),tocall.end());
    for (int i=0;i<tocall.size();i++)
      ta += rec(typei+1,max(max_depth,tocall[i]),remaining-1,extra+kcount[typei]-i-1);
    return r = ta;
  }
  long long count(vector <int> kind, vector <int> depth, vector <int> found, int K) {
    this->kind = kind;
    // precalc bico
    for (int i=0;i<=50;i++) {
      comb[i][0] = comb[i][i] = 1;
      for (int j=1;j<i;j++)
        comb[i][j] = (comb[i-1][j]+comb[i-1][j-1]);
    }
    // compress and sort depths
    map<int,int> m;
    int c = 0;
    vector<int> d = depth;
    sort(d.begin(),d.end());
    for (int i=0;i<d.size();i++)
      if (!m.count(d[i]))
        m[d[i]] = c++;
    ndepth = vector<int>(depth.size());
    for (int i=0;i<ndepth.size();i++)    
      ndepth[i] = m[depth[i]];
    // calc which types to include
    fcount = vector<int>(51,0);
      for (int i=0;i<found.size();i++)
        fcount[found[i]]++;
    kcount = vector<int>(51,0);
      for (int i=0;i<kind.size();i++)
        kcount[kind[i]]++;
    memset(mem,-1,sizeof(mem));
    return rec(1,0,K,0);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 15, 10, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; long long Arg4 = 3LL; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1, 1, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 15, 10, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; long long Arg4 = 4LL; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 10, 10, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; long long Arg4 = 0LL; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {1, 2, 2, 3, 1, 3, 2, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {12512, 12859, 125, 1000, 99, 114, 125, 125, 114}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; long long Arg4 = 35LL; verify_case(3, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 18; long long Arg4 = 9075135300LL; verify_case(4, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {41, 40, 5, 46, 40, 47, 40, 45, 16, 6, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {41121, 80964, 44016, 90126, 80964, 91164, 60285, 91164, 60285, 86209, 30801}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {46, 47}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; long long Arg4 = 0LL; verify_case(5, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
  void test_case_6() { int Arr0[] = {21, 31, 32, 41, 28, 25, 6, 6, 32, 21, 3, 6, 35, 25, 21, 35, 49, 49, 6, 6, 49, 6, 32, 6, 46, 41, 6, 35, 25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {73547, 65249, 11502, 11919, 28061, 5700, 8979, 75087, 74217, 73547, 86653, 53735, 69214, 53735, 5700, 28061, 5700, 53735, 5700, 75087, 53735, 86653, 11502, 8979, 65249, 28061, 86653, 65249, 70601}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {32, 35}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 15; long long Arg4 = 10948LL; verify_case(6, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  Excavations ___test;
  ___test.run_test(-1);
}
// END CUT HERE
