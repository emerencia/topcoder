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
// 558 600 2
class Stamp {
 public:
  int n;
  int rmn;
  string des;
  bool failed;
  int pscost;
  int l;
  map<string,int> mem;
  void rec(string sofar,int idx, int cost) {
    if (idx > n || cost > rmn) return;
    if (mem.count(sofar) && mem[sofar] <= cost) return;
    mem[sofar] = cost;
    bool same = true;
    for (int i=0;i<n;i++) 
      if ((des[i] != '*' && sofar[i] != des[i]) || sofar[i] == '*') { same = false; break; }
    if (same) {
      //cout << l << " " << sofar << " " << idx << " " << cost << endl;
      failed = false;
      rmn = min(rmn,cost);
      return;
    }
    if (idx == n) return;
    for (int i=idx;i<n-l+1;i++) {
      string sofar2 = sofar;
      bool good = true;
      char f = 'R';
      for (int b=0;b<l;b++) {
        if (des[i+b] == '*') continue;
        f = des[i+b];
        for (int c=b+1;c<l;c++) {
          if (des[i+c] == '*') continue;
          if (des[i+c] != des[i+b]) { good = false; break; }
        }
        if (!good) break;
      }
      if (!good) break;
      for (int b=0;b<l;b++) {
        sofar2[i+b] = f;
      }
      rec(sofar2,i+l,cost+pscost);
    }
  }
  int getMinimumCost(string desiredColor, int stampCost, int pushCost) {
    des = desiredColor;
    pscost = pushCost;
    n = desiredColor.size();
    int mn = INT_MAX;
    for (int ll=1;ll<=n;ll++) {
      l = ll;
      failed = true;
      rmn = INT_MAX;
      mem = map<string,int>();
      string a = string(n,'*');
      rec(a,0,ll*stampCost);
      mn = min(mn,rmn);
      if (failed) break;
    }
    return mn;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RRGGBB"; int Arg1 = 1; int Arg2 = 1; int Arg3 = 5; verify_case(0, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "R**GB*"; int Arg1 = 1; int Arg2 = 1; int Arg3 = 5; verify_case(1, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "BRRB"; int Arg1 = 2; int Arg2 = 7; int Arg3 = 30; verify_case(2, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "R*RR*GG"; int Arg1 = 10; int Arg2 = 58; int Arg3 = 204; verify_case(3, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "*B**B**B*BB*G*BBB**B**B*"; int Arg1 = 5; int Arg2 = 2; int Arg3 = 33; verify_case(4, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "*R*RG*G*GR*RGG*G*GGR***RR*GG"; int Arg1 = 7; int Arg2 = 1; int Arg3 = 30; verify_case(5, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  Stamp ___test;
  ___test.run_test(-1);
}
// END CUT HERE
