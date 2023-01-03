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
long long mem[12][2];

class TheLuckyNumbers {
 public:
  vector<int> num;
  long long rec(int idx, bool stillequal) {
    if (idx == -1) return 1;
    LL& r = mem[idx][stillequal];
    if (r != -1) return r;
    long long t = 0;
    if (stillequal) {
      if (num[idx] >= 7) {
        if (num[idx] == 7) {
          t+=rec(idx-1,true);  // 7
          t+=rec(idx-1,false); // 4
        } else {
          t+=2LL*rec(idx-1,false); // 4 7
        }
      } else if (num[idx] >= 4) {
        if (num[idx] == 4) {
          t+= rec(idx-1,true); // 4
        } else {
          t+=rec(idx-1,false); // 4
        }
      }
    } else {
      t+=2LL*rec(idx-1,false);
    }
    return r = t;
  }
  long long numsleq(int a) {
    num.clear();
    memset(mem,-1,sizeof(mem));
    while(a/10) {
      num.push_back(a%10);
      a/=10;
    }
    if (a) num.push_back(a);
    long long t = 0;
    for (int i=0;i+1<num.size();i++)
      t+=rec(i,false);
    if (num.size())
      t+=rec(num.size()-1,true);
    return t;
  }
  int count(int a, int b) {
    return numsleq(b)-numsleq(a-1);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 11; int Arg1 = 20; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 74; int Arg1 = 77; int Arg2 = 2; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1000000; int Arg1 = 5000000; int Arg2 = 64; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  TheLuckyNumbers ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
