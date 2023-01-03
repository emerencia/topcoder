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

//int mem[4][1<<11][51];

typedef pair<int,int> PII;

class SafeRemoval {
 public:
  int rx;
  vector<int> sq;
  set<long long> mem;
  void rec(long long done, int sm, int remaining) {
    if (mem.find(done) != mem.end()) return;
    mem.insert(done);
    if (remaining == 0) {
      rx = max(rx,sm);
      return;
    }
    vector<PII> elems(4,PII(1001,0));
    for (int i=0;i<sq.size();i++) {
      if (done&(1LL<<i)) continue;
      int md = (sm-sq[i])%4;
      if (md == 0) continue;
      if (elems[md].first > sq[i]) elems[md] = PII(sq[i],i);
    }
    for (int i=0;i<elems.size();i++)
      if (elems[i].first != 1001)
        rec(done|(1LL<<elems[i].second),sm-elems[i].first,remaining-1);
  }
  int removeThem(vector <int> seq, int k) {
    sort(seq.begin(),seq.end());
    sq = seq;
    //memset(mem,-1,sizeof(mem));
    mem = set<long long>();
    rx = -1;
    int sm = 0;
    for (int i=0;i<sq.size();i++) sm+= sq[i];
    rec(0,sm,k);
    return rx;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 8, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 11; verify_case(0, Arg2, removeThem(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = -1; verify_case(1, Arg2, removeThem(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,6,1,10,1,2,7,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 21; verify_case(2, Arg2, removeThem(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,1,1,1,1,1,1,1,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 6; verify_case(3, Arg2, removeThem(Arg0, Arg1)); }
  void test_case_4() { int Arr0[] = {1, 4, 1, 4, 2, 3, 2, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 14; verify_case(4, Arg2, removeThem(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  SafeRemoval ___test;
  ___test.run_test(-1);
}
// END CUT HERE
