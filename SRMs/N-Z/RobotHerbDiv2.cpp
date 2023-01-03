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

vector<int> a;

class RobotHerbDiv2 {
 public:
  vector<long long> sub(int dir) {
    vector<long long> r(3,0);
    for (int i = 0;i<a.size();i++) {
      long long dist = (dir/2) ? a[i] : -a[i];
      r[dir%2] += dist;
      dir = (dir+a[i])%4;
    }
    r[2] = dir;
    return r;
  }
  int getdist(int T, vector <int> a) {
    ::a = a;
    vector<long long> r(3,0);
    if (T > 4) {
      vector<long long> temp(3,0);
      for (int i = 0;i<4;i++) {
        vector<long long> t2 = sub(temp[2]);
        temp[2] = t2[2];
        temp[0] += t2[0];
        temp[1] += t2[1];
      }
      r[2] = temp[2];
      r[0] = (T/4)*temp[0];
      r[1] = (T/4)*temp[1];
    }
    for (int i=0;i<T%4;i++) {
      vector<long long> t2 = sub(r[2]);
      r[0] += t2[0];
      r[1] += t2[1];
      r[2] = t2[2];
    }
    return abs(r[0])+abs(r[1]);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, getdist(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, getdist(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {1,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(2, Arg2, getdist(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 100; int Arr1[] = {400000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 40000000; verify_case(3, Arg2, getdist(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  RobotHerbDiv2 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
