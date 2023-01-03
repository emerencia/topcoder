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

int mem[1001];

class TheNumberGameDivTwo {
 public:
  vector<vector<int> > divisors;
  int rec(int n, int p) {
    //cout << "rec " << n << " " << p << endl;
    int& r = mem[n];
    if (r != -1) return (r ? p : 1-p);
    vector<int> divs = divisors[n];
    for (int i=0;i<divs.size();i++) {
      if (rec(n-divs[i],1-p) == p) {
        r = 1;
        return p;
      }
    }
    r = 0;
    return 1-p;
  }
  string find(int n) {
    divisors = vector<vector<int> >(1001);
    for (int i=2;i<=n;i++) {
      //int k = i;
      for (int j=2;j<i;j++) {
        if (i%j == 0) {
          if (j != i)
            divisors[i].push_back(j);
        }
      }
    }
    memset(mem,-1,sizeof(mem));
    return (rec(n,0) == 0 ? "John" : "Brus");
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4();  }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; string Arg1 = "John"; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arg0 = 2; string Arg1 = "Brus"; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arg0 = 747; string Arg1 = "Brus"; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arg0 = 128; string Arg1 = "Brus"; verify_case(3, Arg1, find(Arg0)); }
  void test_case_4() { int Arg0 = 64; string Arg1 = "John"; verify_case(4, Arg1, find(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  TheNumberGameDivTwo ___test;
  ___test.run_test(-1);
}
// END CUT HERE
