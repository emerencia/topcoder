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
// 01:06 naive solution start
// 01:09 naive solution end
// 02:23 intelligent solution end
// END CUT HERE
const int kInf = 100000;

class LittleElephantAndRGB {
 public:
  long long getNumber(vector <string> list, int minGreen) {
    string S = accumulate(list.begin(),list.end(),string(""));
    int N = S.size(); // 2500 max
    long long r = 0;
    vector<int> minidx(N,kInf);  // p: the minimum index > b such that the minGreen following
                            // characters are G or infinite if such index doesn't exist
    vector<int> nrg(N,0);     // q: number of consecutive G characters starting at b+1
    for (int b=N-2;b>=0;b--) {
      int c = b+1;
      if (S[c] == 'G')
        nrg[b] = nrg[c]+1;
      else
        nrg[b] = 0;
      if (nrg[b] >= minGreen)
        minidx[b] = c;
      else
        minidx[b] = minidx[c];
    }
    vector<vector<long long> > dp(N,vector<long long>(minGreen+1,0));
    for (int b=N-2;b>=0;b--) {
      for (int g=0;g<=minGreen;g++) {
        if (b != N-2)
          dp[b][g] += dp[b+1][g];
        if (nrg[b] >= g)
          dp[b][g] += N-b-g;
        else if (minidx[b] != kInf)
          dp[b][g] += N-minidx[b]-minGreen+1;
      }
    }
    for (int a=0;a<N;a++) {
      int nrgreen = 0;
      bool iznice = false;
      for (int b=a;b+1<N;b++) {
        if (S[b] == 'G') {
          nrgreen++;
          nrgreen = min(nrgreen,minGreen);
          if (nrgreen == minGreen) {
            iznice = true;
          }
        } else nrgreen = 0;
        if (iznice) {
          r+= ((N-b-1)*(N-b))/2;
        } else {
          r+=dp[b][minGreen-nrgreen];
        }
      }
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"GRG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; long long Arg2 = 1LL; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"GG", "GG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long long Arg2 = 9LL; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"GRBGRBBRG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; long long Arg2 = 11LL; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"RRBRBBRRR", "R", "B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; long long Arg2 = 0LL; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"GRGGGRBRGG", "GGGGGGGG", "BRGRBRB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; long long Arg2 = 12430LL; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  LittleElephantAndRGB ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
