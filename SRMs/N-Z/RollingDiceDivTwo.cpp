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
using namespace std;

class RollingDiceDivTwo {
 public:
  int minimumFaces(vector <string> rolls) {
    int r =0;
    vector<int> m(rolls[0].size(),0);
    for (int i=0;i<rolls.size();i++) {
      sort(rolls[i].begin(),rolls[i].end());
      for (int j=0;j<rolls[i].size();j++) {
        if (m[j] < rolls[i][j]-'0') m[j] = rolls[i][j]-'0';
      }
    }
    for (int i=0;i<m.size();i++) r+=m[i];
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"137", "364", "115", "724"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(0, Arg1, minimumFaces(Arg0)); }
	void test_case_1() { string Arr0[] = {"1112", "1111", "1211", "1111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, minimumFaces(Arg0)); }
	void test_case_2() { string Arr0[] = {"24412", "56316", "66666", "45625"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; verify_case(2, Arg1, minimumFaces(Arg0)); }
	void test_case_3() { string Arr0[] = {"931", "821", "156", "512", "129", "358", "555"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(3, Arg1, minimumFaces(Arg0)); }
	void test_case_4() { string Arr0[] = {"3", "7", "4", "2", "4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, minimumFaces(Arg0)); }
	void test_case_5() { string Arr0[] = {"281868247265686571829977999522", "611464285871136563343229916655", "716739845311113736768779647392", "779122814312329463718383927626",
"571573431548647653632439431183", "547362375338962625957869719518", "539263489892486347713288936885", "417131347396232733384379841536"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 176; verify_case(5, Arg1, minimumFaces(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  RollingDiceDivTwo ___test;
  ___test.run_test(-1);
}
// END CUT HERE
