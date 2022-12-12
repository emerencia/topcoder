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

class TPS {
 public:
  int n;
  vector<string> linked;
  vector<int> degree;
  int firstjunction(int idx, int prev) {
    if (degree[idx] >= 3) return idx;
    for (int i=0;i<n;i++) {
      if (i == idx || i == prev) continue;
      if (linked[idx][i] == 'Y')
        return firstjunction(i,idx);
    }
    return -1;
  }
  int minimalBeacons(vector <string> linked) {
    this->linked = linked;
    n = linked.size();
    if (n == 1) return 0;
    int nleafnodes = 0;
    int njunctions = 0;
    degree = vector<int>(n,0);
    for (int i = 0;i<n;i++) {
      int connections = 0;
      for (int j=0;j<n;j++)
        connections += linked[i][j] == 'Y';
      if (connections == 1)
        nleafnodes++;
      else if (connections >= 3)
        njunctions++;
      degree[i] = connections;
    }
    if (!njunctions) return 1;
    vector<int> belongsto(n,0);
    for (int i=0;i<n;i++) {
      if (degree[i] != 1) continue;
      int junk = firstjunction(i,-1);
      if (junk != -1)
        belongsto[junk]++;
    }
    int r = nleafnodes;
    for (int i=0;i<n;i++)
      if (degree[i] >= 3 && belongsto[i])
        r--;
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYNN",
 "YNYN",
 "NYNY",
 "NNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minimalBeacons(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYYY",
 "YNNN",
 "YNNN",
 "YNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minimalBeacons(Arg0)); }
	void test_case_2() { string Arr0[] = {"NNYNNNNNNN",
 "NNNNNYNNNN",
 "YNNYNNYNNN",
 "NNYNYNNYNN",
 "NNNYNYNNYN",
 "NYNNYNNNNY",
 "NNYNNNNNNN",
 "NNNYNNNNNN",
 "NNNNYNNNNN",
 "NNNNNYNNNN"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minimalBeacons(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYNYNNYNN",
 "YNYNYNNYN",
 "NYNNNYNNY",
 "YNNNNNNNN",
 "NYNNNNNNN",
 "NNYNNNNNN",
 "YNNNNNNNN",
 "NYNNNNNNN",
 "NNYNNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minimalBeacons(Arg0)); }
	void test_case_4() { string Arr0[] = {"NYYYYYYYYY",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(4, Arg1, minimalBeacons(Arg0)); }
	void test_case_5() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, minimalBeacons(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  TPS ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
