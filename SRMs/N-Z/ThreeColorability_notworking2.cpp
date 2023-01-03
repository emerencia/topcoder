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
    string c = cells[0];
    vector<int> r;
    r.push_back(0);
    for (int i=1;i<cells.size();i++) {
      string c0 = c;
      string c1 = c;
      bool valid0 = true;
      bool valid1 = true;
      for (int k=0;k<cells[0].size();k++) {
        if (c[k] != '?') {
          if (cells[i][k] == '?') continue; // can be both
          if (c[k] == cells[i][k]) valid1 = false;
          else valid0 = false;
        } else {
          c0[k] = cells[i][k];
          c1[k] = (cells[i][k] == 'N' ? 'Y' : (cells[i][k] == 'Y' ? 'N' : '?'));
        }
      }
      if (valid0 && valid1) {
        if (c0 <= c1) {
          r.push_back(0);
          c = c0;
        } else {
          r.push_back(1);
          c = c1;
        }
      } else if (valid0) {
        c = c0;
        r.push_back(0);
      } else if (valid1) {
        c = c1;
        r.push_back(1);
      } else {
        return vector<string>();
      }
    }
    vector<string> rr;
    string ci = c;
    for (int i=0;i<c.size();i++)
      ci[i] = (c[i] == 'N' ? 'Y' : (c[i] == 'Y' ? 'N' : '?'));
    for (int i=0;i<r.size();i++)
      if (r[i])
        rr.push_back(ci);
      else
        rr.push_back(c);
    return rr;
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
