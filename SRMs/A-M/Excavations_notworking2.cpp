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
long long pd[2][51];

class Excavations {
 public:
  long long count(vector <int> kind, vector <int> depth, vector <int> found, int K) {
    vector<int> udepth = depth;
    sort(udepth.begin(),udepth.end());
    udepth.resize(unique(udepth.begin(),udepth.end())-udepth.begin());
    for (int i=0;i<=50;i++) {
      comb[i][0] = comb[i][i] = 1;
      for (int j=1;j<i;j++)
        comb[i][j] = (comb[i-1][j]+comb[i-1][j-1]);
    }
    vector<int> fcount(51,0);
      for (int i=0;i<found.size();i++)
        fcount[found[i]]++;
    int cur = 0,next = 1;
    long long x = 0;
    long long r = 0;
    for (int a = 0; a+1<udepth.size();a++) {
      int d = udepth[a];
      vector<int> kcount(51,0);
      vector<int> kisdepth(51,0);
      vector<int> kbigcount(51,0);
      vector<int> kbiggercount(51,0);
      for (int i=0;i<kind.size();i++) {
        if (depth[i] <= d)
          kcount[kind[i]]++;
        if (depth[i] == d)
          kisdepth[kind[i]]++;
        if (depth[i] >= d)
          kbigcount[kind[i]]++;
        if (depth[i] > d)
          kbiggercount[kind[i]]++;
      }
      bool isvalid = true;
      for (int i=0;i<51;i++)
        if (fcount[i] && !kcount[i]) { isvalid = false; break; }
      if (!isvalid) continue;
      x = 0;
      if (x == 0) {
        memset(pd,0,sizeof(pd));
        pd[0][0] = 1;
        int cur = 0,next = 1;
        for (int j=0;j<51;j++) { // j is type
          if (fcount[j]) {
            memset(pd[next],0,sizeof(pd[next]));
            for (int k=0;k<=K;k++) // k is amount
              for (int l=1;l<=1 && k+l<=found.size();l++) // l is amount of this
                pd[next][k+l] += pd[cur][k]*comb[kcount[j]][l];
            swap(cur,next);
          }
        }
        x = pd[cur][found.size()];
      }
      memset(pd,0,sizeof(pd));
      pd[cur][found.size()] = x;
      for (int j=0;j<51;j++) { // j is type
        //if (fcount[j]) {
          int kjcount = (kisdepth[j] ? kisdepth[j] : kcount[j]);
          //int kdcount = 0;
          if (fcount[j]) {
            kjcount = kbigcount[j]-1;
            //kdcount = kbigcount[j];
          } else {
            kjcount = kbiggercount[j];
            //kdcount = kjcount;
          }
          if (!kjcount) continue;
          memset(pd[next],0,sizeof(pd[next]));
          for (int k=0;k<=K;k++) // k is amount
            for (int l=1;l<=kjcount && k+l<=K;l++) // l is amount of this
              pd[next][k+l] += pd[cur][k]*comb[kjcount][l];
          swap(cur,next);
        //}
          /*
        if (kbigcount[j] && !fcount[j]) {
          memset(pd[next],0,sizeof(pd[next]));
          for (int i=0;i<51;i++)
            pd[next][i] = pd[cur][i];
          int kjcount = kbigcount[j];
          for (int k=0;k<=K;k++) // k is amount
            for (int l=1;l<=kjcount && k+l<=K;l++) // l is amount of this
              pd[next][k] += pd[cur][k]*comb[kjcount][l];
          swap(cur,next);
        }
           * */
      }
      r += pd[cur][K];
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 15, 10, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; long long Arg4 = 3LL; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1, 1, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 15, 10, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; long long Arg4 = 4LL; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 10, 10, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; long long Arg4 = 0LL; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {1, 2, 2, 3, 1, 3, 2, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {12512, 12859, 125, 1000, 99, 114, 125, 125, 114}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; long long Arg4 = 35LL; verify_case(3, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 18; long long Arg4 = 9075135300LL; verify_case(4, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  Excavations ___test;
  ___test.run_test(-1);
}
// END CUT HERE
