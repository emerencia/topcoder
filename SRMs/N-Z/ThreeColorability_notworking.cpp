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

class ThreeColorability {
 public:
  vector <string> lexSmallest(vector <string> cells) {
    vector<string> r = cells;
    // first cell
    if (cells[0][0] == '?') {
      int nn = 0;
      int nq = 0;
      if (1 < cells[0].size()) {
        nn += (cells[0][1] == 'N');
        nq += (cells[0][1] == '?');
      }
      if (1 < cells.size()) {
        nn += (cells[1][0] == 'N');
        nq += (cells[1][0] == '?');
      }
      if (1 < cells[0].size() && 1 < cells.size()) {
        nn += (cells[1][1] == 'N');
        nq += (cells[1][1] == '?');
      }
      if (nq) r[0][0] = 'N';
      else r[0][0] = (nn%2 ? 'N' : 'Z');
    }
    // first row
    for (int i=1;i<cells[0].size();i++) {
      if (r[0][i] != '?') continue;
      int nn = (r[0][i-1] == 'N');
      int nq = 0;
      if (1 < cells.size()) {
        nq += (r[1][i-1] == '?') + (r[1][i] == '?');
        nn += (r[1][i-1] == 'N') + (r[1][i] == 'N');
      }
      if (nq) r[0][i] = 'N';
      else r[0][i] = (nn%2 ? 'N' : 'Z');
    }
    // rest of the rows
    for (int i=1;i<cells.size();i++) {
      if (r[i][0] == '?') {
        int nq = (r[i-1][0] == '?');
        int nn = (r[i-1][0] == 'N');
        if (1 < cells[0].size()) {
          nq += (r[i-1][1] == '?')+(r[i][1] == '?');
          nn += (r[i-1][1] == 'N')+(r[i][1] == 'N');
        }
        if (nq) r[i][0] = 'N';
        else r[i][0] = (nn%2 ? 'N' : 'Z');
      }
      for (int j=1;j<cells.size();j++) {
        int nn = (r[i-1][j-1] == 'N')+(r[i-1][j] == 'N')+(r[i][j-1] == 'N');
        if (r[i][j] == '?') {
          r[i][j] = (nn%2 ? 'N' : 'Z');
        } else {
          if (r[i][j] != (nn%2 ? 'N' : 'Z')) return vector<string>();
        }
      }
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"Z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Z" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, lexSmallest(Arg0)); }
	void test_case_1() { string Arr0[] = {"??", "?N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NN", "NN" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, lexSmallest(Arg0)); }
	void test_case_2() { string Arr0[] = {"ZZZ", "ZNZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, lexSmallest(Arg0)); }
	void test_case_3() { string Arr0[] = {"N?N??NN","??ZN??Z","NN???Z?","ZZZ?Z??","Z???NN?","N?????N","ZZ?N?NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, lexSmallest(Arg0)); }
	void test_case_4() { string Arr0[] = {"ZZZZ","ZZZZ","ZZZZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ZZZZ", "ZZZZ", "ZZZZ" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, lexSmallest(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ThreeColorability ___test;
  ___test.run_test(-1);
}
// END CUT HERE
