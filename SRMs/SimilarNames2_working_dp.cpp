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
typedef pair<int,string> PIS;
typedef long long LL;
// BEGIN CUT HERE
const int toTest = -1;
// 17:31 start dp
// END CUT HERE

const int kMod = 1e9+7;
long long dp[2][52][52];

class SimilarNames2 {
 public:
  long long factorial(long long x) {
    long long c = 1;
    for (long long i=1;i<=x;i++)
      c = (c*i)%kMod;
    return c;
  }
  struct Prefix {
    string s;
    Prefix(string s) : s(s) {}
    bool operator<(const Prefix& o) const {
      return PIS(s.size(),s) < PIS(o.s.size(),o.s);
    }
  };
  int count(vector <string> names, int L) {
    memset(dp,0,sizeof(dp));
    vector<Prefix> nms;
    for (int i=0;i<names.size();i++)
      nms.push_back(Prefix(names[i]));
    sort(nms.begin(),nms.end());
    int n = nms.size();
    long long unsure = factorial(nms.size()-L);
    int cur = 0,next = 1;
    for (int i=0;i<=n;i++)
      dp[cur][i][0] = unsure;
    for (int i=n-1;i>=0;i--) { // idx
      memset(dp[next],0,sizeof(dp[next]));
      for (int j=0;j<=i;j++) // lastprefix
        for (int k=0;k<=L;k++) { // remaining
          if (k == 0) {
            dp[next][j][k] = unsure;
            continue;
          }
          if (j == 0 || 
              nms[i].s.substr(0,nms[j-1].s.size()) == nms[j-1].s)
            dp[next][j][k] = dp[cur][i+1][k-1];
          (dp[next][j][k] += dp[cur][j][k])%=kMod;
        }
      swap(cur,next);
    }
    return dp[cur][0][L];
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"kenta", "kentaro", "ken"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"hideo", "hideto", "hideki", "hide"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 6; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"aya", "saku", "emi", "ayane", "sakura", "emika", "sakurako"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 24; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"taro", "jiro", "hanako"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 0; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"alice", "bob", "charlie"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 6; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"ryota", "ryohei", "ryotaro", "ryo", "ryoga", "ryoma", "ryoko", "ryosuke", "ciel", "lun",
 "ryuta", "ryuji", "ryuma", "ryujiro", "ryusuke", "ryutaro", "ryu", "ryuhei", "ryuichi", "evima"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 276818566; verify_case(5, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  SimilarNames2 ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
