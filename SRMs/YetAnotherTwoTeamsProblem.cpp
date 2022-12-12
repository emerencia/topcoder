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
// 22:31
// END CUT HERE

int dp[30000001];

class YetAnotherTwoTeamsProblem {
 public:
  long long count(vector <int> skill) {
    sort(skill.rbegin(),skill.rend());
    int totalsum = accumulate(skill.begin(),skill.end(),0);
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    long long r = 0;
    for (int i=0;i<skill.size();i++) {
      for (int k = totalsum;k>=skill[i];k--) {
        long long diff = dp[k-skill[i]];
        dp[k] += diff;
        if (k > totalsum-k && k-skill[i] < totalsum-k+skill[i]) r+=diff;
      }
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 4, 7, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 10LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 5, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 4, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { int Arr0[] = {999, 999, 999, 1000, 1000, 1001, 999, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 999, 1000, 512, 511, 1001, 1001, 1001, 1001, 1001, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 17672631900LL; verify_case(4, Arg1, count(Arg0)); }

  void test_case_5() { int Arr0[] = {20000, 10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(5, Arg1, count(Arg0)); }
  
void test_case_6() { int Arr0[] = {23696, 36001, 31037, 34244, 1070, 59614, 32627, 31562, 59949, 15522, 54451, 969, 19273, 41134, 36651, 39281, 40685, 7178, 9707, 56131, 39347, 421, 53291, 42393, 59279, 2859, 6083, 59464, 38237, 18704, 41352, 28269, 46581, 19207, 59830, 40320, 13547, 38493, 47445, 30912, 32539, 1035, 40975, 26742, 44732, 53264}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 215725275242LL; verify_case(6, Arg1, count(Arg0)); }
// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  YetAnotherTwoTeamsProblem ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
