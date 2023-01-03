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

long long T;
long long mem[51][100001];

class TheProgrammingContestDivOne {
 public:
  struct Assignment {
    long long ppm;
    long long maxp;
    long long timereq;
    Assignment(int ppm, int maxp, int timereq) : ppm(ppm), maxp(maxp), timereq(timereq) {}
    double points() const {
      return double(timereq)/double(ppm);
    }
    bool operator<(const Assignment& o) const {
      return points() < o.points();
    }
  };
  vector<Assignment> a;
  long long rec(int idx, int time) {
    if (idx == a.size())
      return 0;
    LL& r = mem[idx][time];
    if (r != -1) return r;
    long long t1 = 0;
    if (time+a[idx].timereq <= T)
      t1 = a[idx].maxp-(time+a[idx].timereq)*a[idx].ppm + rec(idx+1,time+a[idx].timereq);
    return r = max(t1,rec(idx+1,time));
  }
  int find(int T, vector <int> maxPoints, vector <int> pointsPerMinute, vector <int> requiredTime) {
    // when the set of problems you solve is the same, the order is not
    // dependent on max points, so you don't need to involve those in equations.
    // you can sort the problems to solve once, using ppm and requiredtime.
    // then just do knapsack to determine which problems to solve.
    ::T = T;
    memset(mem,-1,sizeof(mem));
    int N = maxPoints.size();
    a.clear();
    for (int i=0;i<N;i++)
      a.push_back(Assignment(pointsPerMinute[i],maxPoints[i],requiredTime[i]));
    sort(a.begin(),a.end());
    return rec(0,0);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 74; int Arr1[] = {502}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {47}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 408; verify_case(0, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 40000; int Arr1[] = {100000, 100000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 100000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {50000, 30000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(1, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 75; int Arr1[] = {250, 500, 1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 4, 8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {25, 25, 25}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1200; verify_case(2, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 30; int Arr1[] = {100, 100, 100000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {15, 15, 30}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 97000; verify_case(3, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
  	void test_case_4() { int Arg0 = 80; int Arr1[] = {290, 787, 919}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 12, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5, 57, 65}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 714; verify_case(4, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  TheProgrammingContestDivOne ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
