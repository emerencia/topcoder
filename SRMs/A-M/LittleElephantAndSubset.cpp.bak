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
// 16:06 start
// 16:24 end
// END CUT HERE

const int kMod = 1e9+7;

class LittleElephantAndSubset {
 public:
  int N;
  vector<int> partition;
  vector<int> num;
  int pn;
  long long r;
  long long ways;
  int bitcount(int n) {
    int r = 0;
    for (int i=n;i;i&=i-1) ++r;
    return r;
  }
  long long factorial(long long x) {
    long long c = 1;
    for (long long i=1;i<=x;i++)
      c = (c*i)%kMod;
    return c;
  }
  long long subprob2(int mask, int idx, bool stillequal) {
    if (idx == -1) return 1;
    if (!stillequal) return factorial(bitcount(mask));
    long long t = 0;
    for (int i=0;(1<<i)<=mask;i++) {
      if (!(mask&(1<<i))) continue;
      if (i == num[idx])
        (t+=subprob2(mask^(1<<i),idx-1,true))%=kMod;
      else if (i < num[idx] && (i != 0 || idx != num.size()-1))
        (t+=subprob2(mask^(1<<i),idx-1,false))%=kMod;
    }
    return t;
  }
  long long subprob(int mask) {
    if (bitcount(mask) > num.size())
      return 0;
    if (bitcount(mask) < num.size()) {
      if (mask&(1<<0))
        return ((bitcount(mask)-1)*factorial(bitcount(mask)-1))%kMod;
      return factorial(bitcount(mask));
    }
    return subprob2(mask,num.size()-1,true);
  }
  void backtrack(int d) {
    if (d == 10) {
      // done
      long long t = 1;
      for (int i=0;i<pn;i++)
        (t*=subprob(partition[i]))%=kMod;
      r+=t;
      ways++;
      return;
    }
    for (int i=0;i<pn;i++) {
      partition[i] |= (1<<d);
      backtrack(d+1);
      partition[i] &= ~(1<<d);
    }
    // new partition
    partition[pn++] = (1<<d);
    backtrack(d+1);
    pn--;
    // do not count this digit
    backtrack(d+1);
  }
  int getNumber(int N) {
    this->N = N;
    ways = 0;
    num = vector<int>();
    while (N) {
      num.push_back(N%10);
      N/=10;
    }
    partition = vector<int>(10,0);
    pn = 0;
    r = 0;
    backtrack(0);
    // bell number 11:
    //cout << this->N << " partitions found: " << ways << endl; 
    return (r-1+kMod)%kMod; // -1 because subsets have to be nonempty
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 7; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 767; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { int Arg0 = 47; int Arg1 = 25775; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { int Arg0 = 4777447; int Arg1 = 66437071; verify_case(3, Arg1, getNumber(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  LittleElephantAndSubset ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
