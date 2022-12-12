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

class ValueHistogram {
 public:
  vector <string> build(vector <int> values) {
    int n = values.size(), H = 0;
    vector<int> cnt(10,0);
    for (int i=0;i<n;i++) {
      cnt[values[i]]++;
      H = max(H,cnt[values[i]]);
    }
    vector<string> res(H+1,string(10,'.'));
    for(int i=0;i<10;i++) {
      for (int j=0;j<cnt[i];j++)
        res[H-j][i] = 'X';
    }
    return res;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {2, 3, 5, 5, 5, 2, 0, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..........", ".....X....", "..X..X....", "X.XX.X..X." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, build(Arg0)); }
	void test_case_1() { int Arr0[] = {9, 9, 9, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..........", ".........X", ".........X", ".........X", ".........X" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, build(Arg0)); }
	void test_case_2() { int Arr0[] = {6, 4, 0, 0, 3, 9, 8, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..........", "X.......X.", "X..XX.X.XX" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, build(Arg0)); }
	void test_case_3() { int Arr0[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..........", "XXXXXXXXXX" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, build(Arg0)); }
	void test_case_4() { int Arr0[] = {6, 2, 3, 3, 3, 7, 8, 1, 0, 9, 2, 2, 4, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..........", "...X......", "..XX......", "..XX......", "XXXXX.XXXX" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, build(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ValueHistogram ___test;
  ___test.run_test(-1);
}
// END CUT HERE
