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
// 15:16

class EelAndRabbit {
 public:
  int getmax(vector<int> l, vector<int> t) {
    vector<int> events;
    for (int i=0;i<l.size();i++) {
      events.push_back(t[i]);
      events.push_back(t[i]+l[i]);
    }
    events.resize(unique(events.begin(),events.end())-events.begin());
    int mx = 0;
    for (int i=0;i<events.size();i++)
      for (int j=i;j<events.size();j++) {
        int c = 0;
        for (int k=0;k<l.size();k++) {
          if (t[k] <= events[i] && events[i] <= l[k]+t[k]) c++;
          else if (t[k] <= events[j] && events[j] <= l[k]+t[k]) c++;
        }
        mx = max(mx,c);
      }
    return mx;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 4, 3, 2, 2, 1, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 6, 3, 7, 0, 2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(0, Arg2, getmax(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 0, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, getmax(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, getmax(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {8, 2, 1, 10, 8, 6, 3, 1, 2, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {17, 27, 26, 11, 1, 27, 23, 12, 11, 13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(3, Arg2, getmax(Arg0, Arg1)); }
//{314, 430, 907, 346, 449, 405, 841, 50, 407, 9, 649, 420, 577, 67, 917, 152, 588, 674, 514, 433, 504, 233, 797, 771, 413, 898, 246, 834, 424, 497, 799, 918, 169, 777, 208, 378, 606, 225, 139, 855, 258, 10, 528, 542, 67, 533, 162, 54, 266, 310}, {363, 533, 470, 417, 490, 735, 729, 564, 251, 726, 650, 761, 707, 134, 541, 542, 82, 61, 467, 552, 132, 58, 107, 761, 555, 801, 367, 656, 418, 561, 373, 539, 582, 198, 603, 805, 275, 184, 100, 292, 242, 585, 385, 769, 283, 102, 748, 268, 789, 192}
void test_case_4() { int Arr0[] = {314, 430, 907, 346, 449, 405, 841, 50, 407, 9, 649, 420, 577, 67, 917, 152, 588, 674, 514, 433, 504, 233, 797, 771, 413, 898, 246, 834, 424, 497, 799, 918, 169, 777, 208, 378, 606, 225, 139, 855, 258, 10, 528, 542, 67, 533, 162, 54, 266, 310}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {363, 533, 470, 417, 490, 735, 729, 564, 251, 726, 650, 761, 707, 134, 541, 542, 82, 61, 467, 552, 132, 58, 107, 761, 555, 801, 367, 656, 418, 561, 373, 539, 582, 198, 603, 805, 275, 184, 100, 292, 242, 585, 385, 769, 283, 102, 748, 268, 789, 192}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 41; verify_case(4, Arg2, getmax(Arg0, Arg1)); }
// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  EelAndRabbit ___test;
  ___test.run_test(-1);
}
// END CUT HERE
