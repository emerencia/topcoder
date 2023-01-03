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

int g[110][110];
int col[110];

class ThreeColorability {
 public:
  int M;
  int N;
  void dfs(int idx,int color) {
    if (col[idx] != -1) return;
    col[idx] = color;
    for (int i=0;i<N+M;i++)
      if (g[idx][i] != -1 && col[i] == -1)
        dfs(i,(color^g[idx][i]));
  }
  bool check() {
    memset(col,-1,sizeof(col));
    for (int i=0;i<N+M;i++)
      if (col[i] == -1)
        dfs(i,0);
    for (int i=0;i<N+M;i++)
      for (int j=0;j<N+M;j++)
        if (g[i][j] != -1 && ((col[i] ^ col[j]) != g[i][j]))
          return false;
    return true;
  }
  vector <string> lexSmallest(vector <string> cells) {
    N = cells.size();
    M = cells[0].size();
    memset(g,-1,sizeof(g));
    for (int i=0;i<N;i++)
      for (int j=0;j<M;j++) {
        if (cells[i][j] == '?') continue;
        g[i][j+N] = g[j+N][i] = (cells[i][j] == 'Z');
      }
    if (!check()) return vector<string>();
    for (int i=0;i<N;i++)
      for (int j=0;j<M;j++) {
        if (cells[i][j] != '?') continue;
        g[i][j+N] = g[j+N][i] = 0;
        if (!check())
          g[i][j+N] = g[j+N][i] = 1;
      }
    vector<string> r(N,string(M,'N'));
    for (int i=0;i<N;i++)
      for (int j=0;j<M;j++)
        if (g[i][j+N])
          r[i][j] = 'Z';
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
