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
// 557 500

class IncubatorEasy {
 public:
  void bit_print(int a) {
    cout << a << endl;
    for (int i=31;i>=0;i--)
      cout << (a&(1<<i) ? 1 : 0);
    cout << endl;
  }
  int bitcount (int n) {
    int r = 0;
    for (int i=n;i;i&=i-1) r++;
    return r;
  }
  int maxMagicalGirls(vector <string> l) {
    bool g[11][11];
    memset(g,0,sizeof(g));
    for (int i=0;i<l.size();i++)
      for (int j=0;j<l.size();j++)
        g[i][j] = l[i][j] == 'Y';
    for (int j=0;j<l.size();j++)
      for (int i=0;i<l.size();i++)
        for (int k=0;k<l.size();k++)
          g[i][k] |= g[i][j] & g[j][k];
    int mx = 0;  
    vector<int> maxm;
    vector<int> maxp;
    for (int i=0;i<(1<<l.size());i++) {
      int m = 0;
      int p = 0;
      for (int j=0;j<l.size();j++) {
        if (i&(1<<j)) continue;
        m |= (1<<j);
        for (int k=0;k<l.size();k++)
          if (g[j][k]) p|=(1<<k);
      }
      int a = bitcount(m&(~p));
      if (a > mx) {
        mx = a;
        maxm.clear();
        maxp.clear();
      }
      if (a == mx) {
        maxm.push_back(m);
        maxp.push_back(p);
      }
    }
    cout << endl << endl;
    for (int i=0;i<maxm.size();i++) {
      cout << "m ";
      bit_print(maxm[i]);
      cout << "p ";
      bit_print(maxp[i]);
    }
    cout << mx << endl;
    cout << endl << endl;
    return mx;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NY","NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, maxMagicalGirls(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYN", "NNY", "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, maxMagicalGirls(Arg0)); }
	void test_case_2() { string Arr0[] = {"NNYNN","NNYNN","NNNYY","NNNNN","NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, maxMagicalGirls(Arg0)); }
	void test_case_3() { string Arr0[] = {"NNNNN","NYNNN","NYNYN","YNYNN","NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, maxMagicalGirls(Arg0)); }
	void test_case_4() { string Arr0[] = {"NNNNN","NNNNN","NNNNN","NNNNN","NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, maxMagicalGirls(Arg0)); }
	void test_case_5() { string Arr0[] = {"Y"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, maxMagicalGirls(Arg0)); }
void test_case_6() { string Arr0[] = {"NNNNNNYY", "YNNYNNNN", "NYYYYNYN", "NYNYNNNN", "NNNNNNNN", "YNYYYNNY", "NNYYNYNN", "NNNYNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(6, Arg1, maxMagicalGirls(Arg0)); }
// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  IncubatorEasy ___test;
  ___test.run_test(-1);
}
// END CUT HERE
