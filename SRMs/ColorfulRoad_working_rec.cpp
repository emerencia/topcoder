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

int mem[16];

class ColorfulRoad {
 public:
  string road;
  vector<int> conv;
  int rec(int idx) {
    if (idx+1 == road.size())
      return 0;
    int& r = mem[idx];
    if (r != -1) return r;
    char next = (conv[road[idx]]+1)%3;
    int t = 1000000;
    for (int i=idx+1;i<road.size();i++) {
      if (conv[road[i]] != next) continue;
      t = min(t,(i-idx)*(i-idx)+rec(i));
    }
    return r = t;
  }
  int getMin(string Road) {
    road = Road;
    memset(mem,-1,sizeof(mem));
    // 0 is red
    conv = vector<int>(255,-1);
    conv['R'] = 0;
    conv['G'] = 1;
    conv['B'] = 2;
    int r = rec(0);
    return (r < 500000 ? r : -1);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RGGGB"; int Arg1 = 8; verify_case(0, Arg1, getMin(Arg0)); }
	void test_case_1() { string Arg0 = "RGBRGBRGB"; int Arg1 = 8; verify_case(1, Arg1, getMin(Arg0)); }
	void test_case_2() { string Arg0 = "RBBGGGRR"; int Arg1 = -1; verify_case(2, Arg1, getMin(Arg0)); }
	void test_case_3() { string Arg0 = "RBRRBGGGBBBBR"; int Arg1 = 50; verify_case(3, Arg1, getMin(Arg0)); }
	void test_case_4() { string Arg0 = "RG"; int Arg1 = 1; verify_case(4, Arg1, getMin(Arg0)); }
	void test_case_5() { string Arg0 = "RBRGBGBGGBGRGGG"; int Arg1 = 52; verify_case(5, Arg1, getMin(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ColorfulRoad ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
