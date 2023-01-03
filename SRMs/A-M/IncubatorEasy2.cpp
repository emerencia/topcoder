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

int dp[1<<10][1<<10];
int mem[1<<10][10];
int mem2[1<<10];

class IncubatorEasy {
 public:
  vector<string> lv;
  int bitcount(int n) {
    int& r = mem2[n];
    if (r != -1) return r;
    int d = 0;
    for (int i=n;i;i&=i-1) d++;
    return r = d;
  }
  int added(int idx, int prot) {
    int& r = mem[prot][idx];
    if (r != -1) return r;
    queue<int> q;
    q.push(idx);
    while (!q.empty()) {
      int p = q.front();
      q.pop();
      for (int i=0;i<lv.size();i++) {
        if (prot&(1<<i)) continue;
        if (lv[p][i] == 'Y') {
          prot|=(1<<i);
          if (i == p) continue;
          q.push(i);
        }
      }
    }
    return r = prot;
  }
  int rec(int magical, int prot) {
    int& r = dp[magical][prot];
    if (r != -1) return r;
    int mx = bitcount(magical&(~prot));
    for (int i=0;i<lv.size();i++) {
      if (lv[i][i] == 'Y') continue;
      if (magical&(1<<i)) continue;
      if (prot&(1<<i)) continue;
      mx = max(mx,rec(magical|(1<<i),added(i,prot)));
    }
    return r = mx;
  }
  int maxMagicalGirls(vector <string> l) {
    lv = l;
    memset(dp,-1,sizeof(dp));
    memset(mem,-1,sizeof(mem));
    memset(mem2,-1,sizeof(mem2));
    return rec(0,0);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NY","NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, maxMagicalGirls(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYN", "NNY", "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, maxMagicalGirls(Arg0)); }
	void test_case_2() { string Arr0[] = {"NNYNN","NNYNN","NNNYY","NNNNN","NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, maxMagicalGirls(Arg0)); }
	void test_case_3() { string Arr0[] = {"NNNNN","NYNNN","NYNYN","YNYNN","NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, maxMagicalGirls(Arg0)); }
	void test_case_4() { string Arr0[] = {"NNNNN","NNNNN","NNNNN","NNNNN","NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, maxMagicalGirls(Arg0)); }
	void test_case_5() { string Arr0[] = {"Y"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, maxMagicalGirls(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  IncubatorEasy ___test;
  ___test.run_test(-1);
}
// END CUT HERE
