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
using namespace std;

int dp[51][1<<15];

class RelativelyPrimeSubset {
 public:
   vector<int> get_primes(int n) {
     vector<bool> p(n+1,true);
     for (int i=2;i*i<=n;i++) {
       if (p[i]) {
         for (int j=i*i;j<=n;j+=i) p[j] = false;
       }
     }
     vector<int> r;
     for (int i=2;i<p.size();i++)
       if (p[i]) r.push_back(i);
     return r;
   }
  int findSize(vector <int> S) {
    vector<int> primes = get_primes(50);
    //cout << primes.size() << endl;
    vector<int> divisors = vector<int>(S.size(),0);
    for (int i=0;i<S.size();i++) {
      for (int j=0;j<primes.size();j++) {
        if (S[i]%primes[j] == 0) divisors[i] |= (1<<j);
      }
    }
    for (int i=0;i<51;i++)
      for (int j=0;j<(1<<15);j++)
        dp[i][j] = 0;
    for (int i=0;i<S.size();i++)
      dp[i][divisors[i]] = 1;
    for (int i=1;i<S.size();i++) {
      for (int mask=0;mask<(1<<15);mask++) {
        if ((mask|divisors[i]) == mask) {
          dp[i][mask] = max(dp[i-1][mask],dp[i-1][mask^divisors[i]]+1);
        } else {
          dp[i][mask] = dp[i-1][mask];
        }
      }
    }
    int mx = 0;
    for (int i=0;i<(1<<15);i++) {
      mx = max(mx,dp[S.size()-1][i]);
    }
    return mx;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,3,7,11,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, findSize(Arg0)); }
	void test_case_1() { int Arr0[] = {4,8,12,16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, findSize(Arg0)); }
	void test_case_2() { int Arr0[] = {100,17,81,82}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, findSize(Arg0)); }
	void test_case_3() { int Arr0[] = {2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, findSize(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  RelativelyPrimeSubset ___test;
  ___test.run_test(-1);
}
// END CUT HERE
