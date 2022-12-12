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

const int kMod = 1e9+7;
int mem[1300][37];
long long comb[1300][1300];

class LISNumber {
 public:
  int n;
  int K;
  vector<int> cardsum;
  
  long long bico(long long n, long long k) {
    return comb[n][k];
  }
  int rec(int lisnum, int at) {
    int& r = mem[lisnum][at];
    if (r != -1) return r;
    if (at == 0) {
      if (lisnum == 0)
        return r = 1;
      return r = 0;
    }
    at--;
    long long a = 0;
    int totn = 0;
    for (int i=at+1;i<n;i++)
      totn+= cardsum[i];
    long long slotsUp = K-lisnum;
    long long slotsDown = totn+1-slotsUp;
    for (int up=0;up<=cardsum[at] && up<=slotsUp;up++) {
      for (int dn=0;up+dn<=cardsum[at] && dn<=slotsDown;dn++) {
        int eq = cardsum[at]-up-dn;
        if (lisnum-dn-eq < 0) continue;
        a = (a+(((((bico(slotsUp,up)*bico(slotsDown,dn))%kMod)*(eq > 0 ? bico(up+dn+eq-1,eq) : 1LL))%kMod)*rec(lisnum-dn-eq,at))%kMod)%kMod;
      }
    }
    return r = a;
  }
  int count(vector <int> cardsum, int K) {
    for (int i=0;i<1300;i++) {
      comb[i][0] = comb[i][i] = 1;
      for (int j=1;j<i;j++)
        comb[i][j] = (comb[i-1][j]+comb[i-1][j-1])%kMod;
    }
    n = cardsum.size();
    this->K = K;
    this->cardsum = cardsum;
    memset(mem,-1,sizeof(mem));
    return rec(K-1,n);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 4; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {36, 36, 36, 36, 36}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; int Arg2 = 1; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {3, 2, 11, 5, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; int Arg2 = 474640725; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {31, 4, 15, 9, 26, 5, 35, 8, 9, 7, 9, 32, 3, 8, 4, 6, 26}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; int Arg2 = 12133719; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {27, 18, 28, 18, 28, 4, 5, 9, 4, 5, 23, 5,
 36, 28, 7, 4, 7, 13, 5, 26, 6, 24, 9, 7,
 7, 5, 7, 24, 7, 9, 36, 9, 9, 9, 5, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 116; int Arg2 = 516440918; verify_case(5, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  LISNumber ___test;
  ___test.run_test(-1);
}
// END CUT HERE
