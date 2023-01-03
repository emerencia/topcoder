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
typedef pair<int,int> PII;

class TreeUnionDiv2 {
 public:
  vector<vector<int> > dist(const vector<string>& tree) {
    int n = tree.size();
    vector<vector<int> > g(n,vector<int>(n,-1));
    for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++)
        if (tree[i][j] == 'X')
          g[i][j] = 1;
      g[i][i] = 0;
    }
    for (int k=0;k<n;k++)
      for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
          if (g[i][k] != -1 && g[k][j] != -1) {
            if (g[i][j] == -1) g[i][j] = g[i][k]+g[k][j];
            else g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
          }
    return g;
  }
  int maximumCycles(vector <string> tree1, vector <string> tree2, int K) {
    vector<vector<int> > dist1 = dist(tree1);
    vector<vector<int> > dist2 = dist(tree2);
    int n = tree1.size();
    int r = 0;
    vector<int> p(n);
    for (int k=0;k<n;k++) p[k] = k;
    do {
      int c = 0;
      for (int l=0;l<n;l++)
        for (int m=l+1;m<n;m++)
          c+= (dist1[l][m]+1+dist2[p[l]][p[m]] == K-1);
      r = max(r,c);
    } while(next_permutation(p.begin(),p.end()));
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"-X",
 "X-"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-X",
 "X-"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 1; verify_case(0, Arg3, maximumCycles(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"-X-",
 "X-X",
 "-X-"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-X-",
 "X-X",
 "-X-"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 2; verify_case(1, Arg3, maximumCycles(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"-X-",
 "X-X",
 "-X-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-X-",
 "X-X",
 "-X-"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 0; verify_case(2, Arg3, maximumCycles(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"-X---",
 "X-XXX",
 "-X---",
 "-X---",
 "-X---"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-X-X-",
 "X-X-X",
 "-X---",
 "X----",
 "-X---"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = 5; verify_case(3, Arg3, maximumCycles(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"-XX------",
 "X------X-",
 "X--XX-X--",
 "--X--X---",
 "--X------",
 "---X----X",
 "--X------",
 "-X-------",
 "-----X---"}

; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-X-------",
 "X-X------",
 "-X-XX----",
 "--X---X--",
 "--X--X---",
 "----X--XX",
 "---X-----",
 "-----X---",
 "-----X---"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; int Arg3 = 17; verify_case(4, Arg3, maximumCycles(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  TreeUnionDiv2 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
