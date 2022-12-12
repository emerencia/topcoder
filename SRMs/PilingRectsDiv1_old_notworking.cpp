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
const int toTest = 3;
// 
// END CUT HERE

struct Item {
  long long x;
  long long y;
  Item(long long x, long long y) : x(x), y(y) { }
  bool operator<(const Item& o) const {
    //return min(x,y) < min(o.x,o.y);
    return x*y < o.x*o.y;
  }
};

class PilingRectsDiv1 {
 public:
  int N;
  long long rec(const vector<Item>& items,int idx,int n1, int n2, long long mins1, long long maxs1, long long mins2, long long maxs2) {
    cout << idx << endl;
    if (idx >= items.size()) {
      long long surf = mins1*maxs1 + mins2*maxs2;
      return surf;
    }
    //cout << idx << " " << n1 << " " << n2 << " " << mins1 << " " << maxs1
    long long mmin = min(items[idx].x,items[idx].y);
    long long mmax = max(items[idx].x,items[idx].y);
    long long lost1 = min(mins1-min(mins1,mmin)+maxs1-min(maxs1,mmax),
                          mins1-min(mins1,mmax)+maxs1-min(maxs1,mmin));
    long long lost2 = min(mins2-min(mins2,mmin)+maxs2-min(maxs2,mmax),
                          mins2-min(mins2,mmax)+maxs2-min(maxs2,mmin));
    long long r = 0;
    if (n2 == N || (n1 < N && lost1 < lost2))
      r = rec(items,idx+1,n1+1,n2,min(mins1,mmin),min(maxs1,mmax),mins2,maxs2);
    else
      r = rec(items,idx+1,n1,n2+1,mins1,maxs1,min(mins2,mmin),min(maxs2,mmax));
    return r;
  }
  long long getmax(int n, vector <int> XS, vector <int> YS, int XA, int XB, int XC, int YA, int YB, int YC) {
    N = n;
    vector<long long> Y(2*N);
    vector<long long> X(2*N);
    for (int i=0;i<XS.size();i++) {
      X[i] = XS[i];
      Y[i] = YS[i];
    }
    for (int i=XS.size();i<2*N;i++) {
      X[i] = (X[i-1] * XA + XB)%XC + 1;
      Y[i] = (Y[i-1] * YA + YB)%YC + 1;
    }
    vector<Item> items(2*N);
    for (int i=0;i<X.size();i++)
      items[i] = Item(X[i],Y[i]);
    sort(items.rbegin(),items.rend());
    long long mins1 = min(items[0].x,items[0].y);
    long long maxs1 = max(items[0].x,items[0].y);
    long long mins2 = min(items[1].x,items[1].y);
    long long maxs2 = max(items[1].x,items[1].y);
    return rec(items,2,1,1,mins1,maxs1,mins2,maxs2);
    /*
    for (int i=1;i<N;i++) {
      mins = min(mins,min(items[i].x,items[i].y));
      maxs = min(maxs,max(items[i].x,items[i].y));
    }
    long long r = mins*maxs;
    mins = min(items[N].x,items[N].y);
    maxs = max(items[N].x,items[N].y);
    for (int i=N+1;i<2*N;i++) {
      mins = min(mins,min(items[i].x,items[i].y));
      maxs = min(maxs,max(items[i].x,items[i].y));
    }
    r+= mins*maxs;
    return r;
    */
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,5,3,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; int Arg4 = 0; int Arg5 = 1; int Arg6 = 0; int Arg7 = 0; int Arg8 = 1; long long Arg9 = 14LL; verify_case(0, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {7,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 9; int Arg4 = 0; int Arg5 = 10; int Arg6 = 2; int Arg7 = 7; int Arg8 = 9; long long Arg9 = 56LL; verify_case(1, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {5,6,9,10,4,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {9,5,8,6,8,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; int Arg4 = 0; int Arg5 = 1; int Arg6 = 0; int Arg7 = 0; int Arg8 = 1; long long Arg9 = 69LL; verify_case(2, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_3() { int Arg0 = 10000; int Arr1[] = {1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000000000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 93827162; int Arg4 = 91238127; int Arg5 = 98231267; int Arg6 = 92138287; int Arg7 = 98563732; int Arg8 = 99381279; long long Arg9 = 1240119561532788LL; verify_case(3, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_4() { int Arg0 = 5; int Arr1[] = {375,571,973,896,460,930,583,530,657,590}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {284,37,994,699,941,745,166,884,270,708}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 428; int Arg4 = 1000; int Arg5 = 788; int Arg6 = 851; int Arg7 = 125; int Arg8 = 894; long long Arg9 = 420515LL; verify_case(4, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_5() { int Arg0 = 34734; int Arr1[] = {898,579,465,665,875,391,583,901,326,133,656,562,701,707,492,617,455,441,382,952,689,656,334,877,120,318,497,25,569,962,845,562,632,898,882,498,595,889,382,507,791,548,810,606,105,869,569,970,322,974}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {83,18,492,27,339,622,851,915,464,347,287,210,282,166,976,167,968,769,14,383,454,983,319,165,185,315,795,851,124,287,846,745,19,639,894,828,540,420,147,452,501,670,466,554,166,1,446,808,508,172}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 569; int Arg4 = 185; int Arg5 = 285; int Arg6 = 741; int Arg7 = 304; int Arg8 = 296; long long Arg9 = 10050LL; verify_case(5, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  PilingRectsDiv1 ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
