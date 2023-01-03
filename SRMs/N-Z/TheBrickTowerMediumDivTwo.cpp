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
// 554 500

class TheBrickTowerMediumDivTwo {
 public:
  int mindist;
  vector<int> minorder;
  vector<int> h;
  bool smaller_than(const vector<int>& a, const vector<int>& b) {
    // return true if a<b
    for (int i=0;i<a.size();i++) {
      if (a[i] == b[i]) continue;
      return a[i] < b[i];
    }
    return false;
  }
  void rec(vector<int> order) {
    if (order.size() == h.size()) {
      int dist = 0;
      for (int i=1;i<order.size();i++) {
        dist+= max(h[order[i-1]],h[order[i]]);
      }
      if (dist < mindist || (dist == mindist && smaller_than(order,minorder))) {
        mindist = dist;
        minorder = order;
      }
      return;
    }
    for (int i=0;i<h.size();i++) {
      bool f = false;
      for (int j=0;j<order.size();j++) if (order[j] == i) { f = true; break; }
      if (f) continue;
      vector<int> e = order;
      e.push_back(i);
      rec(e);
    }
  }
  vector <int> find(vector <int> heights) {
    h = heights;
    mindist = 500;
    minorder = vector<int>();
    for (int i=0;i<heights.size();i++) {
      vector<int> a;
      a.push_back(i);
      rec(a);
    }
    return minorder;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {4, 7, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arr0[] = {4, 4, 4, 4, 4, 4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3, 4, 5, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 3, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 3, 1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arr0[] = {13, 32, 38, 25, 43, 47, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 6, 3, 1, 2, 4, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  TheBrickTowerMediumDivTwo ___test;
  ___test.run_test(-1);
}
// END CUT HERE
