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
// 
// END CUT HERE

const int kMod = 1e9+7;

class LittleElephantAndArray {
 public:
  long long construct(long long num, int mask, int nrdigits) {
    long long factor = 1;
    long long r = 0;
    for (int i=0;i<nrdigits;i++) {
      if (mask&(1<<i)) {
        r += factor*(num%10LL);
        factor *= 10LL;
      }
      num/=10LL;
    }
    return r;
  }
  int getNumber(long long A, int N) {
    map<LL,LL> prev;
    map<LL,LL> next;
    prev[0]=1;
    for (int i=0;i<=N;i++) {
      long long cur = A+i;
      int nrdigits = 0;
      for (long long m=cur;m!=0;m=m/10LL) nrdigits++;
      next.clear();
      vector<LL> potnums;
      for (int k=1;k<(1<<nrdigits);k++) {
        // add to the map because it might already exist
        long long potnum = construct(cur,k,nrdigits);
        potnums.push_back(potnum);
      }
      sort(potnums.begin(),potnums.end());
      map<LL,LL>::iterator prv = prev.begin();
      map<LL,LL>::iterator prve = prev.end();
      int nxt = 0;
      int nxte = potnums.size();
      long long t = 0;
      while (nxt != nxte) {
        if (prv != prve && (*prv).first <= potnums[nxt]) {
          (t += (*prv).second)%=kMod;
          prv++;
          continue;
        }
        (next[potnums[nxt]] += t)%=kMod;
        nxt++;
      }
      swap(prev,next);
    }
    long long r = 0;
    for (map<LL,LL>::iterator i = prev.begin();i!=prev.end();i++)
      (r += (*i).second)%=kMod;
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; int Arg1 = 9; int Arg2 = 1; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 10LL; int Arg1 = 2; int Arg2 = 15; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 4747774LL; int Arg1 = 1; int Arg2 = 8369; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 6878542150015LL; int Arg1 = 74; int Arg2 = 977836619; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  LittleElephantAndArray ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
