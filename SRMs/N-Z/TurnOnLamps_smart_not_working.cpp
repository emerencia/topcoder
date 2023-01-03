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
// 01:23-01:45-02:07-02:16

class TurnOnLamps {
 public:
  vector<int> roads;
  vector<vector<bool> > g;
  long long nottoggleset;
  long long importantmask;
  int n;
  int mc;
  bool canalwayspass(int a,int b) {
    if (b < a) swap(a,b);
    // b is biggest
    // roads[i] < i+1
    int isnotimportant = (importantmask&(1LL<<(b-1))) ? 0 : 1;
    return (isnotimportant && roads[b-1] == a);
  }
  void dfs(int cur,int prev,vector<int>& seen) {
    seen[cur]++;
    int c = 0;
    for (int i=0;i<n;i++) {
      if (i == prev || i == cur) continue;
      if (!canalwayspass(cur,i) && !g[cur][i]) continue;
      seen[cur]++;
      if (seen[i] < 3)
      dfs(i,cur,seen);
      c++;
      if (c == 2 && prev != -1) mc++;
    }
      
    /*
    int c = 0;
    for (int i=0;i<roads.size();i++) {
      int from = roads[i];
      int to = i+1;
      if (from == cur) swap(from,to);
      if (to == cur && from != prev && !(nottoggleset&(1LL<<i))) {
        dfs(from,to,seen);
        c++;
        if (prev != -1 || c == 2) break;
      }
    }
    */
  }
  int minimize(vector <int> roads, string initState, string isImportant) {
    this->roads = roads;
    n = roads.size()+1;
    importantmask = 0;
    for (int i=0;i<isImportant.size();i++)
      if (isImportant[i] == '1')
        importantmask |= (1LL<<i);
    long long state = 0;
    for (int i=0;i<initState.size();i++)
      if (initState[i] == '1')
        state |= (1LL<<i);
    g = vector<vector<bool> >(n,vector<bool>(n,false));
    long long toggleset = ((~state)&importantmask);
    nottoggleset = (state&importantmask);
    vector<bool> isnode(n,false);
    for (int i=0;i<n;i++) {
      if (toggleset&(1LL<<i)) {
        int from = roads[i];
        int to = i+1;
        //cout << from << " " << to << endl;;
        isnode[from] = 1;
        isnode[to] = 1;
        g[from][to] = 1;
        g[to][from] = 1;
      }
    }
    vector<int> seen(n,0);
    int r = 0;
    for (int i=0;i<seen.size();i++) {
      if (!isnode[i]) continue;
      if (seen[i]) continue;
      r++;
      mc = 0;
      dfs(i,-1,seen);
      //r+=mc;
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0001"; string Arg2 = "0111"; int Arg3 = 1; verify_case(0, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0000"; string Arg2 = "0111"; int Arg3 = 2; verify_case(1, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,0,1,1,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "000100"; string Arg2 = "111111"; int Arg3 = 2; verify_case(2, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,1,1,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "100100"; string Arg2 = "011101"; int Arg3 = 2; verify_case(3, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,2,2,3,1,6,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "010001110"; string Arg2 = "000110100"; int Arg3 = 1; verify_case(4, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {0,0,1,2,4,4,6,1,2,5,2,8,8,3,6,4,14,7,18,14,11,7,1,12,7,5,18,23,0,14,11,10,2,2,6,1,30,11,9,12,5,35,25,11,23,17,14,45,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0000000000010000000000000010000010100000000000000"; string Arg2 = "1010111111111011011111000110111111111111111110111"; int Arg3 = 14; verify_case(5, Arg3, minimize(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  TurnOnLamps ___test;
  ___test.run_test(-1);
}
// END CUT HERE
