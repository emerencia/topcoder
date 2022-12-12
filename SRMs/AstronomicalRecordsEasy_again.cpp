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
// 15:34-15:57
// END CUT HERE

class AstronomicalRecordsEasy {
 public:
  int minimalPlanets(vector <int> a, vector <int> b) {
    vector<long long> A;
    for (int i=0;i<a.size();i++)
      A.push_back(a[i]);
    vector<long long> B;
    for (int i=0;i<b.size();i++)
      B.push_back(b[i]);
    int mn = INT_MAX;
    for (int i=0;i<A.size();i++) {
      vector<long long> Bn = B;
      for (int k=0;k<B.size();k++)
        Bn[k] = B[k]*A[i];
      for (int j=0;j<B.size();j++) {
        vector<long long> An = A;
        for (int k=0;k<A.size();k++)
          An[k] = A[k]*B[j];
        set<int> both;
        for (int k=0;k<An.size();k++)
          both.insert(An[k]);
        for (int k=0;k<Bn.size();k++)
          both.insert(Bn[k]);
        mn = min(mn,(int)both.size());
      }
    }
    return mn;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(0, Arg2, minimalPlanets(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,4,6,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, minimalPlanets(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,3,5,6,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,4,5,6,7,8,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(2, Arg2, minimalPlanets(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6,7,8,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(3, Arg2, minimalPlanets(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {200,500}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100,200,300,400,600,700,800,900}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(4, Arg2, minimalPlanets(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6,7,8,9,10,11,12,13,14,15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 15; verify_case(5, Arg2, minimalPlanets(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  AstronomicalRecordsEasy ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
