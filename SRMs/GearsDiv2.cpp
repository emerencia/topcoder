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

map<string,int> mem;

class GearsDiv2 {
 public:
  int rec(string D) {
    if (mem.count(D)) return mem[D];
    int r = -1;
    for (int i=0;i+1<D.size();i++) {
      if (D[i] != D[i+1]) continue;
      int r1 = min(rec(D.substr(0,i+1))+1+rec(D.substr(i+2)),
                   rec(D.substr(0,i))+1+rec(D.substr(i+1)));
      if (r == -1 || r > r1)
        r = r1;
    }
    if (r == -1) r = 0;
    return mem[D] = r;
  }
  int getmin(string D) {
    mem = map<string,int>();
    int n = D.size();
    if (D[0] == D[n-1])
      return 1+min(rec(D.substr(0,n-1)),rec(D.substr(1,n-1)));
    return rec(D);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LRRR"; int Arg1 = 1; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arg0 = "RRR"; int Arg1 = 2; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arg0 = "LRLR"; int Arg1 = 0; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arg0 = "LRLLRRLLLRRRLLLL"; int Arg1 = 6; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arg0 = "RRRRRRRLRRRRRRRLRLRLLRLRLRLRRLRLRLLLRLRLLRLLRRLRRR"; int Arg1 = 14; verify_case(4, Arg1, getmin(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  GearsDiv2 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
