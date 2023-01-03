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

int stored[51];
int ns;
int mins;

class BinPackingEasy {
 public:
  vector<int> item;
  void backtrack(int idx) {
    if (ns >= mins) return;
    if (idx == item.size()) {
      mins = min(mins,ns);
      return;
    }
    // add to existing
    int flag = false;
    for (int i=0;i<ns;i++) {
      if (stored[i]+item[idx] <= 300) {
        stored[i]+=item[idx];
        backtrack(idx+1);
        stored[i]-=item[idx];
        flag = true;
      }
    }
    // add to new backpack
    if (!flag && ns+1 < mins) {
      stored[ns++] = item[idx];
      backtrack(idx+1);
      ns--;
    }
  }
  int minBins(vector <int> item) {
    sort(item.rbegin(),item.rend());
    this->item = item;
    ns = 0;
    mins = item.size();
    backtrack(0);
    return mins;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6();  }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {150, 150, 150, 150, 150}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minBins(Arg0)); }
	void test_case_1() { int Arr0[] = {130, 140, 150, 160}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minBins(Arg0)); }
	void test_case_2() { int Arr0[] = {101, 101, 101, 101, 101, 101, 101, 101, 101}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, minBins(Arg0)); }
	void test_case_3() { int Arr0[] = {101, 200, 101, 101, 101, 101, 200, 101, 200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, minBins(Arg0)); }
	void test_case_4() { int Arr0[] = {123, 145, 167, 213, 245, 267, 289, 132, 154, 176, 198}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(4, Arg1, minBins(Arg0)); }
 void test_case_5() { int Arr0[] = {263, 235, 133, 144, 253, 128, 223, 113, 135, 250, 107, 264, 219, 182, 130, 123, 147, 253, 173, 219, 132, 174, 259, 268, 124, 148, 117, 221, 265, 172, 161, 126, 101, 126, 254, 170, 203, 237, 222, 126, 170, 207, 185, 160, 193, 264, 268, 221, 159, 164}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; verify_case(5, Arg1, minBins(Arg0)); }
  void test_case_6() { int Arr0[] = {185, 166, 194, 201, 220, 198, 176, 179, 160, 138, 196, 150, 149, 157, 160, 222, 109, 169, 196, 197, 124, 119, 224, 152, 123, 116, 142, 119, 218, 123, 131, 188, 187, 177, 210, 205, 196, 166, 120, 214, 165, 192, 154, 200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; verify_case(6, Arg1, minBins(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  BinPackingEasy ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
