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
typedef pair<int,char> PIC;
typedef pair<int,PIC> PIIC;
typedef long long LL;

map<string,int> mem;
map<string,int> seen;

class GooseTattarrattatDiv1 {
 public:
  bool ispalindrome(string s) {
    for (int i=0;i<s.size()/2;i++)
      if (s[i] != s[s.size()-i-1])
        return false;
    return true;
  }
  string transform(string S) {
    string r;
    vector<int> getindex(255,-1);
    int c = 0;
    for (int i=0;i<S.size();i++) {
      if (getindex[(int)S[i]] == -1) {
        getindex[(int)S[i]] = c++;
      }
      r+='A'+getindex[(int)S[i]];
    }
    return r;
  }
  int rec(string S, int cost) {
    S = transform(S);
    if (mem.count(S)) return mem[S];
    if (ispalindrome(S)) return mem[S] = 0;
    if (seen.count(S) && seen[S] <= cost) return 1400;
    seen[S] = cost;
    string uniquechars = S;
    sort(uniquechars.begin(),uniquechars.end());
    uniquechars.resize(unique(uniquechars.begin(),uniquechars.end())-uniquechars.begin());
    int mn = 1400;
    for (int k = 0;k< uniquechars.size(); k++) {
      char change = uniquechars[k];
      for (int i = 0;i<uniquechars.size();i++) {
        if (uniquechars[i] == change) continue;
        int cc = 0;
        for (int j=0;j<S.size();j++) {
          if (S[j] != change || S[S.size()-1-j] != uniquechars[i]) continue;
          cc++;
        }
        if (cc == 0) continue;
        string news = S;
        int tmn = 0;
        for (int j=0;j<news.size();j++)
          if (news[j] == change) {
            news[j] = uniquechars[i];
            tmn++;
          }
        mn = min(mn,tmn+rec(news,tmn+cost));
      }
    }
    return mem[S] = mn;
  }
  int getmin(string S) {
    mem = map<string,int>();
    seen = map<string,int>();
    return rec(S,0);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "geese"; int Arg1 = 2; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arg0 = "tattarrattat"; int Arg1 = 0; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arg0 = "xyyzzzxxx"; int Arg1 = 2; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arg0 = "xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag"; int Arg1 = 11; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arg0 = "abaabb"; int Arg1 = 3; verify_case(4, Arg1, getmin(Arg0)); }
  void test_case_5() { string Arg0 = "aaabbbcxyyopqrorrqoxyxcbaaddd"; int Arg1 = 13; verify_case(5, Arg1, getmin(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  GooseTattarrattatDiv1 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
