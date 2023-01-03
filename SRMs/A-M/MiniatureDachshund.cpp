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

class MiniatureDachshund {
 public:
  int maxMikan(vector <int> mikan, int weight) {
    sort(mikan.begin(),mikan.end());
    int c = 0;
    for (int i=0;i<mikan.size();i++) {
      weight+=mikan[i];
      if (weight <= 5000)
        c++;
      else break;
    }
    return c;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100, 100, 100, 100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4750; int Arg2 = 2; verify_case(0, Arg2, maxMikan(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {100, 100, 100, 100, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4750; int Arg2 = 3; verify_case(1, Arg2, maxMikan(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {120, 90, 130, 100, 110, 80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3000; int Arg2 = 6; verify_case(2, Arg2, maxMikan(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5000; int Arg2 = 0; verify_case(3, Arg2, maxMikan(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {200, 50, 200, 50, 200, 50, 200, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4800; int Arg2 = 4; verify_case(4, Arg2, maxMikan(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  MiniatureDachshund ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
