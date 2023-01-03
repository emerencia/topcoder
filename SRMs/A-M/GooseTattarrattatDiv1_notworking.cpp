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

class GooseTattarrattatDiv1 {
 public:
  bool ispalindrome(string s) {
    for (int i=0;i<s.size()/2;i++)
      if (s[i] != s[s.size()-i-1])
        return false;
    return true;
  }
  int getmin(string S) {
    int mn = 0;
    while (!ispalindrome(S)) {
      map<char,int> m;
      for (int i=0;i<S.size();i++) {
        if (!m.count(S[i])) {
          m[S[i]] = 0;
        }
        m[S[i]]++;
      }
      vector<PIC> v;
      for (map<char,int>::iterator i=m.begin();i!=m.end();i++) {
        v.push_back(PIC((*i).second,(*i).first));
      }
      sort(v.begin(),v.end());
      vector<PIIC> t;
      char c = 0;
      int k = 0;
      do {
        c = v[k].second;
        vector<int> counts(255,0);
        for (int j=0;j<S.size();j++)
          if (S[j] == c && S[j] != S[S.size()-j-1]) {
            counts[S[S.size()-j-1]]++;
          }
        for (int j=0;j<counts.size();j++) {
          if (!counts[j]) continue;
          t.push_back(PIIC(counts[j],PIC(m[(char)j],j)));
        }
        k++;
      } while (t.empty());
      sort(t.rbegin(),t.rend());
      char nc = t[0].second.second;
      for (int j=0;j<S.size();j++)
        if (S[j] == c) {
          mn++;
          S[j] = nc;
        }
    }
    return mn;
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
