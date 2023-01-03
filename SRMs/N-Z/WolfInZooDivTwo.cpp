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

const int kMod = 1e9+7;

long long dp[301][301];

class WolfInZooDivTwo {
 public:
  vector<int> tovector(const vector<string>& a) {
    vector<int> r;
    string s;
    for (int i=0;i<a.size();i++)
      s+=a[i];
    stringstream b(s);
    while (!b.eof()) {
      int c;
      b >> c;
      r.push_back(c+1);
    }
    return r;
  }
  int count(int N, vector<string> L, vector<string> R) {
    vector<int> l = tovector(L);
    vector<int> r = tovector(R);
    int M = l.size();
    if (M != r.size()) cout << "Ms not equal: " << M << " " << r.size() << endl;
    vector<PII> intervals;
    for (int i=0;i<M;i++)
      intervals.push_back(PII(l[i],r[i]));
    sort(intervals.begin(),intervals.end());
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for (int n=1;n<=N;n++)
      for (int k=0;k<n;k++) {
        dp[n][n] = (dp[n][n]+dp[n-1][k])%kMod;
        bool f = false;
        for (int i=0;i<intervals.size();i++) {
          if (intervals[i].second != n) continue;
          if (intervals[i].first <= k) continue;
          f = true;
          break;
        }
        if (!f)
          dp[n][k] = (dp[n][k]+dp[n-1][k])%kMod;
      }
    long long re = 0;
    for (int i=0;i<301;i++)
      re = (re+dp[N][i])%kMod;
    return re;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; string Arr1[] = {"0 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 27; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; string Arr1[] = {"0 4 2 7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"3 9 5 9"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 798; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 100; string Arr1[] = {"0 2 2 7 10 1","3 16 22 30 33 38"," 42 44 49 51 57 60 62"," 65 69 72 74 77 7","8 81 84 88 91 93 96"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"41 5 13 22 12 13 ","33 41 80 47 40 ","4","8 96 57 66 ","80 60 71 79"," 70 77 ","99"," 83 85 93 88 89 97 97 98"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 250671525; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; string Arr1[] = {"1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  WolfInZooDivTwo ___test;
  ___test.run_test(-1);
}
// END CUT HERE
