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

map<long long,int> mem;

class TurnOnLamps {
 public:
  vector<int> roads;
  long long importantmask;
  long long dontswapmask;
  vector<long long> nodesleftof;
  vector<vector<long long> > toggledby;
  int n;
  int curmin;
  void dfs(int cur, int prev, vector<int>& seen) {
    seen[cur] = 1;
    for (int i=0;i<roads.size();i++) {
      int from = i+1;
      int to = roads[i];
      if (from == cur) swap(from,to);
      if (to == cur && from != prev) {
        dfs(from,cur,seen);
      }
    }
  }
  int bitcount(long long t) {
    t = (t&0x5555555555555555LL) + ((t>>1)&0x5555555555555555LL);
    t = (t&0x3333333333333333LL) + ((t>>2)&0x3333333333333333LL);
    t = (t&0x0f0f0f0f0f0f0f0fLL) + ((t>>4)&0x0f0f0f0f0f0f0f0fLL);
    t = (t&0x00ff00ff00ff00ffLL) + ((t>>8)&0x00ff00ff00ff00ffLL);
    t = (t&0x0000ffff0000ffffLL) + ((t>>16)&0x0000ffff0000ffffLL);
    t = (t&0x00000000ffffffffLL) + ((t>>32)&0x00000000ffffffffLL);
    return t;
  }
  long long dfsdist(int cur, int prev, int endn, long long ways) {
    if (cur == endn) return ways;
    long long r = 0;
    for (int i=0;i<roads.size();i++) {
      int from = i+1;
      int to = roads[i];
      if (from == cur) swap(from,to);
      if (to == cur && from != prev) {
        r |= dfsdist(from,cur,endn,ways|(1LL<<i));
      }
    }
    return r;
  }
  void rec(long long state, long long togglededges, int movessofar) {
    if (movessofar > curmin) return;
    long long realstate = (state&importantmask);
    if (realstate == importantmask) curmin = min(curmin,movessofar);
    if (mem.count(realstate) && mem[realstate] <= movessofar) return;
    mem[realstate] = movessofar;
    int mbc = bitcount(state&importantmask);
    long long mtog = 0;
    for (int j=0;j<roads.size()+1;j++)
      for (int k=j+1;k<roads.size()+1;k++) {
        long long tog = toggledby[j][k];
        int nrchange = bitcount((state^tog)&importantmask);
        if (nrchange > mbc && (!(dontswapmask&tog)) && (!(togglededges&importantmask&tog))) {
          mbc = nrchange;
          mtog = tog;
        }
      }
    if (mbc > bitcount(state&importantmask)) {
      rec(state^mtog,togglededges^mtog,movessofar+1);
    }
  }
  int minimize(vector <int> roads, string initState, string isImportant) {
    this->roads = roads;
    mem.clear();
    n = roads.size()+1;
    toggledby = vector<vector<long long> >(n,vector<long long>(n,0));
    for (int i=0;i<n;i++)
      for (int j=i+1;j<n;j++) {
        toggledby[i][j] = dfsdist(i,-1,j,0);
        toggledby[j][i] = toggledby[i][j];
      }
    importantmask = 0;
    for (int i=0;i<isImportant.size();i++)
      if (isImportant[i] == '1')
        importantmask |= (1LL<<i);
    long long state = 0;
    for (int i=0;i<initState.size();i++)
      if (initState[i] == '1')
        state |= (1LL<<i);
    dontswapmask = (importantmask&state);
    curmin = n+1;
    rec(state,0,0);
    return curmin;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0001"; string Arg2 = "0111"; int Arg3 = 1; verify_case(0, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0000"; string Arg2 = "0111"; int Arg3 = 2; verify_case(1, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,0,1,1,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "000100"; string Arg2 = "111111"; int Arg3 = 2; verify_case(2, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,1,1,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "100100"; string Arg2 = "011101"; int Arg3 = 2; verify_case(3, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,2,2,3,1,6,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "010001110"; string Arg2 = "000110100"; int Arg3 = 1; verify_case(4, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {0,0,1,2,4,4,6,1,2,5,2,8,8,3,6,4,14,7,18,14,11,7,1,12,7,5,18,23,0,14,11,10,2,2,6,1,30,11,9,12,5,35,25,11,23,17,14,45,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0000000000010000000000000010000010100000000000000"; string Arg2 = "1010111111111011011111000110111111111111111110111"; int Arg3 = 14; verify_case(5, Arg3, minimize(Arg0, Arg1, Arg2)); }
  void test_case_6() { int Arr0[] = {0, 0, 2, 1, 4, 4, 2, 6, 6, 8, 6, 1, 4, 8, 9, 3, 2, 17, 16, 7, 7, 19, 1, 21, 2, 23, 12, 9, 15, 17, 12, 2, 25, 7, 15, 4, 23, 23, 21, 5, 27, 11, 24, 8, 39, 31, 8, 36, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0100100000010001000000000000000000000010000100100"; string Arg2 = "1111110111111111101111101111111111101111110111110"; int Arg3 = 16; verify_case(6, Arg3, minimize(Arg0, Arg1, Arg2)); }


// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  TurnOnLamps ___test;
  ___test.run_test(-1);
}
// END CUT HERE
