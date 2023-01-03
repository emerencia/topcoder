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

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int dx2[] = {-1,0,-1,0};
int dy2[] = {-1,-1,0,0};
char c2[] = {'N','Z','Z','N'};

class ThreeColorabilityEasy {
 public:
  int bitcount(int n) {
    int r = 0;
    for (int i=n;i;i&=i-1) ++r;
    return r;
  }
  string isColorable(vector <string> cells) {
    int H = cells.size();
    int W = cells[0].size();
    vector<vector<int> > color(H+1,vector<int>(W+1,-1));
    color[0][0] = 1;
    color[1][0] = 2;
    color[0][1] = (cells[0][0] == 'N' ? 2 : 4);
    bool changed = true;
    while (changed) {
      changed = false;
      for (int i=0;i<H+1;i++)
        for (int j=0;j<W+1;j++) {
          if (color[i][j] != -1) continue;
          int used = 0;
          for (int d=0;d<4;d++) {
            if (i+dx[d] >= 0 && i+dx[d] < H+1 && j+dy[d] >= 0 && j+dy[d] < W+1) {
              if (color[i+dx[d]][j+dy[d]] != -1)
                used |= color[i+dx[d]][j+dy[d]];
            }
            if (i+dx2[d] >= 0 && i+dx2[d] < H && j+dy2[d] >= 0 && j+dy2[d] < W) {
              if (cells[i+dx2[d]][j+dy2[d]] == c2[d] && color[i+(dx2[d])*2+1][j+(dy2[d])*2+1] != -1) {
                used |= color[i+(dx2[d])*2+1][j+(dy2[d])*2+1];
              }
            }
          }
          if (bitcount(used) == 3) return "No";
          if (bitcount(used) == 2) {
            color[i][j] = ((1<<3)-1)^used;
            changed = true;
          }
        }
    }
    return "Yes";
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(0, Arg1, isColorable(Arg0)); }
	void test_case_1() { string Arr0[] = {"NZ"
,"NZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(1, Arg1, isColorable(Arg0)); }
	void test_case_2() { string Arr0[] = {"ZZZ"
,"ZNZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "No"; verify_case(2, Arg1, isColorable(Arg0)); }
	void test_case_3() { string Arr0[] = {"NZNZNNN"
,"NNZNNNZ"
,"NNNNZZZ"
,"ZZZNZZN"
,"ZZNZNNN"
,"NZZZZNN"
,"ZZZNZNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "No"; verify_case(3, Arg1, isColorable(Arg0)); }
	void test_case_4() { string Arr0[] = {"ZZZZ"
,"ZZZZ"
,"ZZZZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(4, Arg1, isColorable(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ThreeColorabilityEasy ___test;
  ___test.run_test(-1);
}
// END CUT HERE
