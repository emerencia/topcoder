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

const int kMax = 1000002;
const int kOff = kMax/2;

class MayTheBestPetWin {
 public:
  int calc(vector <int> A, vector <int> B) {
    int n = A.size();
    vector<int> prev(kMax,-1);
    vector<int> next(kMax,-1);
    prev[kOff] = 1;
    int dff = 0;
    for (int i=0;i<n;i++) {
      next = vector<int>(kMax,-1);
      for (int k=0;k<prev.size();k++) {
        if (prev[k] != -1) {
          next[k+B[i]] = 1;
          next[k-A[i]] = 1;
        }
      }
      dff += B[i]-A[i];
      swap(prev,next);
    }
    int mn = kOff;
    for (int i=0;i<kMax;i++)
      if (prev[i] != -1)
        mn = min(mn,max(abs(kOff-i),abs(i-dff-kOff)));
    return mn;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,4,4,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,4,4,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, calc(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,3,5,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,5,6,8,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(1, Arg2, calc(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2907,949,1674,6092,8608,5186,2630,970,1050,2415,1923,2697,5571,6941,8065,4710,716,756,5185,1341,993,5092,248,1895,4223,1783,3844,3531,2431,1755,2837,4015}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7296,6954,4407,9724,8645,8065,9323,8433,1352,9618,6487,7309,9297,8999,9960,5653,4721,7623,6017,7320,3513,6642,6359,3145,7233,5077,6457,3605,2911,4679,5381,6574}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 52873; verify_case(2, Arg2, calc(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  MayTheBestPetWin ___test;
  ___test.run_test(toTest);
}
// END CUT HERE