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

int component[27];

class GooseTattarrattatDiv1 {
 public:
  string S;
  long long c;
  void dfs(int idx, int compi) {
    c++;
    if (component[idx] != -1) return;
    component[idx] = compi;
    for (int i=0;i<S.size();i++) {
      c++;
      if (S[i]-'a' == idx && component[S[S.size()-i-1]-'a'] == -1)
        dfs(S[S.size()-i-1]-'a',compi);
    }
  }
  int getmin(string S) {
    c = 0;
    this->S = S;
    int n = 26;
    vector<int> counts(n,0);
    for (int i=0;i<S.size();i++)
      counts[S[i]-'a']++;
    memset(component,-1,sizeof(component));
    for (int i=0;i<n;i++) {
      c++;
      if (counts[i] && component[i] == -1)
        dfs(i,i);
    }
    vector<int> scounts(n,0);
    vector<int> smax(n,0);
    for (int i=0;i<S.size();i++) {
      int compi = component[S[i]-'a'];
      scounts[compi]++;
      smax[compi] = max(smax[compi],counts[S[i]-'a']);
    }
    int r = 0;
    for (int i=0;i<n;i++)
      if (scounts[i])
        r+= scounts[i]-smax[i];
    cout << c << endl;
    return r;
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
