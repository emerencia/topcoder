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

const int kMod  = 1e9+7;

class DistinctRemainders {
 public:
  long long factorial(int n) {
    long long r = 1;
    for (long long i=2;i<=n;i++) {
      r = (r*i)%kMod;
    }
    return r;
  }
  int bitcount (int n) {
    int r = 0;
    for (int i=n;i;i&=i-1) ++r;
    return r;
  }
  int howMany(long long N, int m) {
    long long M = m;
    vector<long long> nummod(M,(N/M)+1); // how many there are between 1 and N
    for (long long i=(N%M)+1;i<M;i++)
      if (nummod[i]) --nummod[i];
    /*
    for (int i=0;i<nummod.size();i++)
      cout << "nummod " << i << ": " << nummod[i] << endl;
    */
    vector<vector<long long> > combs(M); // vector of combinations
    combs[0].push_back(0);
    for (long long i = 0;i<M;i++)
      for (long long j = 0;j<combs.size();j++)
        for (long long k = 0;k<combs[j].size();k++) {
          if (combs[j][k]&(1LL<<i)) continue;
          long long state = combs[j][k]|(1LL<<i);
          bool found = false;
          for (long long a=0;a<combs[(j-i+M)%M].size();a++)
            if (combs[(j-i+M)%M][a] == state) { found = true; break; }
          if (!found) combs[(j-i+M)%M].push_back(state);
          state = combs[j][k]|(1LL<<i);
          found = false;
          for (long long a=0;a<combs[(j+i)%M].size();a++)
            if (combs[(j+i)%M][a] == state) { found = true; break; }
          if (!found) combs[(j+i)%M].push_back(state);
        }
    set<long long> validcombs;
    for (int i=0;i<combs[N%M].size();i++)
      validcombs.insert(combs[N%M][i]);
    long long r = 0;
    /*
    for (int j=0;j<combs.size();j++)
    for (int i=0;i<combs[j].size();i++) {
      cout << j << ": ";
      for (int p=0;p<M;p++)
        if (combs[j][i]&(1LL<<p)) cout << p << " ";
      cout << endl;
    }
    */
    for (set<long long>::iterator i=validcombs.begin();i!=validcombs.end();i++) {
      long long comb = *i;
      if (!comb) continue;
      long long r2 = 0;
      for (int j=0;j<M;j++) {
        if (!(comb&(1LL<<j)) || nummod[j] == 0) continue;
        long long r3 = 1;
        for (int u=0;u<M;u++) {
          if (j == u || !(comb&(1LL<<u))) continue;
          r3 = (r3*(nummod[u]-1LL))%kMod;
        }
        r2 = (r2+r3)%kMod;
      }
      if (r2 == 0) r2 =1;
      /*
      cout << "comb: ";
      for (int i=0;i<M;i++)
        if (comb&(1LL<<i)) cout << i << " ";
      cout << " = " << (r2) << " * " << factorial(bitcount(comb)) << endl;
      */
      //r2 = ((r2)*factorial(bitcount(comb)))%kMod;
      r = (r+r2)%kMod;
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 3LL; int Arg1 = 2; int Arg2 = 5; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 3LL; int Arg1 = 3; int Arg2 = 9; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 58LL; int Arg1 = 1; int Arg2 = 1; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 572LL; int Arg1 = 7; int Arg2 = 922572833; verify_case(3, Arg2, howMany(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 1000000000000000000LL; int Arg1 = 20; int Arg2 = 240297629; verify_case(4, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  DistinctRemainders ___test;
  ___test.run_test(-1);
}
// END CUT HERE
