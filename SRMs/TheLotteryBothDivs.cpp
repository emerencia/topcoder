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

class TheLotteryBothDivs {
 public:
  double find(vector <string> goodSuffixes) {
    sort(goodSuffixes.begin(),goodSuffixes.end());
    goodSuffixes.resize(unique(goodSuffixes.begin(),goodSuffixes.end())-goodSuffixes.begin());
    bool changed = true;
    while (changed) {
      changed = false;
      int idx = -1;
      for (int i=0;i<goodSuffixes.size();i++) {
        for (int j=0;j<goodSuffixes.size();j++) {
          if (i == j) continue;
          if (goodSuffixes[j].size() > goodSuffixes[i].size() &&
              goodSuffixes[j].substr(goodSuffixes[j].size()-goodSuffixes[i].size()) ==goodSuffixes[i]) {
            changed = true;
            idx = j;
          }
        }
        if (changed) break;
      }
      if (changed) {
        for (int i = idx;i+1<goodSuffixes.size();i++)
          goodSuffixes[i] = goodSuffixes[i+1];
        goodSuffixes.resize(goodSuffixes.size()-1);
      }
    }
    double r = 0;
    for (int i=0;i<goodSuffixes.size();i++)
      r+=pow(10,9-goodSuffixes[i].size());
    r/=1e9;
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (abs(Expected- Received) < 1e-9) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.1; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arr0[] = {"4", "7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.2; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arr0[] = {"47", "47"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.01; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arr0[] = {"47", "58", "4747", "502"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.021; verify_case(3, Arg1, find(Arg0)); }
	void test_case_4() { string Arr0[] = {"8542861", "1954", "6", "523", "000000000", "5426", "8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.201100101; verify_case(4, Arg1, find(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  TheLotteryBothDivs ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
