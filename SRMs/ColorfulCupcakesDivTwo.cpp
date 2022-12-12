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

int mem[3][52][52][52];
const int kMod = 1000000007;

class ColorfulCupcakesDivTwo {
 public:
  int n;
  int firstc;
  int rec(int lastc, vector<int>& counts, int idx) {
    int& res = mem[lastc][counts[0]][counts[1]][counts[2]];
    if (res != -1) return res;
    if (idx == n)  return res = (firstc != lastc);
    int r = 0;
    for (int i=0;i<2;i++) {
      int j = (i+1+lastc)%3;
      if (counts[j]) {
        counts[j]--;
        r = (r + rec(j,counts,idx+1))%kMod;
        counts[j]++;
      }
    }
    return res = r;
  }
  int countArrangements(string cupcakes) {
    vector<int> counts(3,0);
    for (int i=0;i<cupcakes.size();i++)
      counts[cupcakes[i]-'A']++;
    n = cupcakes.size();
    int r = 0;
    for (int i=0;i<3;i++)
      if (counts[i]) {
        firstc = i;
        memset(mem,-1,sizeof(mem));
        counts[i]--;
        r = (r+rec(i,counts,1))%kMod;
        counts[i]++;
      }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABAB"; int Arg1 = 2; verify_case(0, Arg1, countArrangements(Arg0)); }
	void test_case_1() { string Arg0 = "ABABA"; int Arg1 = 0; verify_case(1, Arg1, countArrangements(Arg0)); }
	void test_case_2() { string Arg0 = "ABC"; int Arg1 = 6; verify_case(2, Arg1, countArrangements(Arg0)); }
	void test_case_3() { string Arg0 = "ABABABABABABABABABABABABABABABABABABABABABABABABAB"; int Arg1 = 2; verify_case(3, Arg1, countArrangements(Arg0)); }
	void test_case_4() { string Arg0 = "BCBABBACBABABCCCCCAABBAACBBBBCBCAAA"; int Arg1 = 741380640; verify_case(4, Arg1, countArrangements(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ColorfulCupcakesDivTwo ___test;
  ___test.run_test(-1);
}
// END CUT HERE
