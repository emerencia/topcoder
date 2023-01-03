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
// 17:23-18:15
// END CUT HERE

class FlippingBitsDiv1 {
 public:
  int makeZero(const vector<vector<int> >& counts) {
    vector<vector<int> >dp(2,vector<int>(2,0));
    int cur = 0,next = 1;
    for (int i=0;i<counts.size();i++) {
      dp[next] = vector<int>(2,1300);
      for (int j=0;j<2;j++)
        for (int k=0;k<2;k++) {
          int cost = 0;
          if (j != k) ++cost;
          cost+= counts[i][j];
          dp[next][j] = min(dp[next][j],cost+dp[cur][k]);
        }
      swap(cur,next);
    }
    return min(dp[cur][0]+1,dp[cur][1]);
  }
  int smallM(string s, int M) {
    int N = s.size();
    int T = N/M;
    int mincost = 3000;
    for (int i = 0;i<(1<<M);i++) {
      vector<bool> needtotoggle;
      for (int j=0;j<N;j++) {
        int orig = s[j]-'0';
        int target = ((i>>(j%M))&1);
        needtotoggle.push_back(orig^target);
      }
      // toggle the tail
      int cost = 0;
      for (int j=T*M;j<N;j++)
        cost+=needtotoggle[j];
      // toggle the rest
      vector<vector<int> > counts(T,vector<int>(2,0));
      for (int j=0;j<T;j++) {
        int zeros = count(needtotoggle.begin()+j*M,
                          needtotoggle.begin()+(j+1)*M,0);
        counts[j][0] = zeros;
        counts[j][1] = M-zeros;
      }
      cost += makeZero(counts);
      mincost = min(mincost,cost);
    }
    return mincost;
  }
  int smallT(string s, int M) {
    // now iterate over all possible flips
    int N = s.size();
    int T = N/M;
    int mincost = 1400;
    vector<int> origstring;
    for (int i=0;i<N;i++)
      origstring.push_back(s[i]-'0');
    for (int i=0;i<(1<<T);i++) {
      int cost = 0;
      vector<int> nstring = origstring;
      for (int j=0;j<T;j++)
        if (i&(1<<j)) {
          cost++;
          for (int k=0;k<N && k<M*(j+1);k++)
            nstring[k] = 1-nstring[k];
        }
      vector<vector<int> > counts(M,vector<int>(2,0));
      for (int j=0;j<N;j++)
        counts[j%M][nstring[j]]++;
      for (int j=0;j<M;j++)
        cost+=min(counts[j][0],counts[j][1]);
      mincost = min(mincost,cost);
    }
    return mincost;
  }
  int getmin(vector <string> S, int M) {
    string s = accumulate(S.begin(),S.end(),string(""));
    if (M <= 17)
      return smallM(s,M);
    return smallT(s,M);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"00111000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, getmin(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"101100001101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; verify_case(1, Arg2, getmin(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"11111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 0; verify_case(2, Arg2, getmin(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"1101001000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 1; verify_case(3, Arg2, getmin(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"1","10","11","100","101","110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 4; verify_case(4, Arg2, getmin(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"1001011000101010001111111110111011011100110001001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 16; verify_case(5, Arg2, getmin(Arg0, Arg1)); }
  void test_case_6() { string Arr0[] = {"10101110011011000011111010111110010001001111101011", "11100111101101001000101010101000100000110001010011", "01111001100001110011101001011111110011101010111000", "01101000000010110110011110011010111000100101101010", "10001111101111101100000110111111110111011010010011", "00011101100000010010011100001010010010100111010101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 162; int Arg2 = 63; verify_case(6, Arg2, getmin(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  FlippingBitsDiv1 ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
