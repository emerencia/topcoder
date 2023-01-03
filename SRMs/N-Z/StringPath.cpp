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
#include <limits>
#include <cstring>
#include <numeric>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
// BEGIN CUT HERE
const int toTest = -1;
// 
// END CUT HERE

const int kMod = 1e9+9;

long long dp[99][1<<8][1<<8];

class StringPath {
 public:
  int countBoards(int n, int m, string A, string B) {
    //if (A[0] != B[0] || A[A.size()-1] != B[B.size()-1]) return 0;
    if (A[0] != B[0]) return 0; // second check not needed
    memset(dp,0,sizeof(dp));
    dp[0][1][1] = 1; // at least one good path has to exist
    for (int i=0;i+1<n*m;i++) {
      int nextcol = (i+1)%m;
      int nextrow = (i+1)/m;
      for (int k=0;k<(1<<m);k++)
        for (int l=0;l<(1<<m);l++) {
          if (!dp[i][k][l]) continue;
          for (int c=0;c<26;c++) {
            int newstatea = k;
            int newstateb = l;
            if ((newstatea>>nextcol)&1) newstatea -= 1<<nextcol; // set to zero
            if ((newstateb>>nextcol)&1) newstateb -= 1<<nextcol; // set to zero
            if ('A'+c == A[nextrow+nextcol]) {
              if ((k>>nextcol)&1) // above was true
                newstatea |= 1<<nextcol;
              if (nextcol && ((k>>(nextcol-1))&1))
                newstatea |= 1<<nextcol;
            }
            if ('A'+c == B[nextrow+nextcol]) {
              if ((l>>nextcol)&1) // above was true
                newstateb |= 1<<nextcol;
              if (nextcol && ((l>>(nextcol-1))&1))
                newstateb |= 1<<nextcol;
            }
            (dp[i+1][newstatea][newstateb]+=dp[i][k][l])%=kMod;
          }
        }
    }
    long long r = 0;
    for (int i=0;i<(1<<m);i++)
      if ((i>>(m-1))&1)
        for (int j=0;j<(1<<m);j++)
          if ((j>>(m-1))&1)
            (r+=dp[n*m-1][i][j])%=kMod;
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; string Arg2 = "ABC"; string Arg3 = "ADC"; int Arg4 = 2; verify_case(0, Arg4, countBoards(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; string Arg2 = "ABC"; string Arg3 = "ABD"; int Arg4 = 0; verify_case(1, Arg4, countBoards(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 4; string Arg2 = "ABCDDE"; string Arg3 = "ACCBDE"; int Arg4 = 1899302; verify_case(2, Arg4, countBoards(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 8; string Arg2 = "ZZZZZZZZZZZZZZZ"; string Arg3 = "ZABCDEFGHIJKLMZ"; int Arg4 = 120390576; verify_case(3, Arg4, countBoards(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  StringPath ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
