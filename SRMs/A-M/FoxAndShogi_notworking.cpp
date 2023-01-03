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
// BEGIN CUT HERE
const int toTest = -1;
// 22:43
// END CUT HERE

long long dp [52][52];
const int kMod = 1e9+7;

class FoxAndShogi {
 public:
  long long calcColumn(string s) {
    vector<int> pos;
    vector<int> type; // 0 = right(D), 1 = left(U)
    for (int i=0;i<s.size();i++) {
      if (s[i] == '.') continue;
      pos.push_back(i);
      type.push_back(s[i] == 'U');
    }
    int n = pos.size();
    if (!n) return 1;
    vector<int> nextback(s.size()+1,-1);
    int ci = -1;
    int cur = n;
    for (int i=s.size();i>=0;i--) {
      nextback[i] = ci;
      if (s[i] != '.') {
        cur--;
        if (type[cur]) ci = cur;
      }
    }
    memset(dp,0,sizeof(dp));
    for (int k=0;k<s.size();k++) { // positions <= k
      for (int m=0;m<=min(n,k+1);m++) { // the first m elements (so <= m-1)
        if (m == 0) {
          // 0 elements
          if (pos[m] > k || 
              (nextback[k] == -1 && k < s.size()-n) ||
              (nextback[k] != -1 && pos[nextback[k]]-k > nextback[k]-m)) {
            dp[k][m] = 1;
          }
        } else {
          if ((m == n || pos[m] > k) || 
              (nextback[k] == -1 && k < s.size()-n) ||
              (nextback[k] != -1 && pos[nextback[k]]-k > nextback[k]-m)) {
            dp[k][m] = (k == 0 ? 1 : (dp[k-1][m] ? dp[k-1][m] + ((m != n || type[m-1] == 0) ? max(1LL,dp[k-1][m]*(m-1)+1LL) : 0) : 0));
           // if (k == 4 && m == 2) cout << "step: " << dp[k-1][m] << " " << dp[k][m] << endl;
            dp[k][m] = (dp[k][m])%kMod;
          }
          if (k > 0) {
            if (type[m-1]) {
              if (pos[m-1] >= k)
                dp[k][m] = (dp[k][m] + dp[k-1][m-1])%kMod;
            } else {
              if (pos[m-1] == k)
                dp[k][m] = (dp[k][m] + dp[k-1][m-1])%kMod;
            }
          }
        }
        //cout << "store " << m << " elements into the first <= " << k <<
        //   " positions: " << dp[k][m] << endl;
      }
    }
    /*
    long long a = 0;
    for (int i = 0;i<s.size();i++)
      a = (a + dp[i][n])%kMod;
    return a;
    */
    return dp[s.size()-1][n];
  }
  int differentOutcomes(vector <string> board) {
    long long a = 1;
    for (int i=0;i<board[0].size();i++) {
      string s;
      for (int j=0;j<board.size();j++)
        s+=board[j][i];
      a = (a*calcColumn(s))%kMod;
    }
    return a;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".D.",
 "...",
 "..."}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, differentOutcomes(Arg0)); }
	void test_case_1() { string Arr0[] = {".D.",
 "...",
 ".U."}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, differentOutcomes(Arg0)); }
	void test_case_2() { string Arr0[] = {"DDDDD",
 ".....",
 ".....",
 ".....",
 "....."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3125; verify_case(2, Arg1, differentOutcomes(Arg0)); }
	void test_case_3() { string Arr0[] = {"DDDDD",
 "U....",
 ".U...",
 "..U..",
 "...U."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 900; verify_case(3, Arg1, differentOutcomes(Arg0)); }
	void test_case_4() { string Arr0[] = {"....D..",
 "U....D.",
 "D.D.U.D",
 "U.U...D",
 "....U..",
 "D.U...D",
 "U.U...."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2268; verify_case(4, Arg1, differentOutcomes(Arg0)); }
	void test_case_5() { string Arr0[] = {"DDDDDDDDDD",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 ".........."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 999999937; verify_case(5, Arg1, differentOutcomes(Arg0)); }
	void test_case_6() { string Arr0[] = {"..",
 ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(6, Arg1, differentOutcomes(Arg0)); }
  void test_case_7() { string Arr0[] = {"D", ".", ".", "D", ".", "D"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(7, Arg1, differentOutcomes(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  FoxAndShogi ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
