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
typedef pair<int,int> PII;

class EllysCoprimesDiv2 {
 public:
  int gcd (int a, int b) {
    if (b == 0) return a;
    return gcd(b,a%b);
  }
  int getCount(vector<int> numbers) {
    sort(numbers.begin(),numbers.end());
    int c = 0;
    for (int i=0;i+1<numbers.size();i++)
      if (gcd(numbers[i],numbers[i+1]) > 1) {
        ++c;
        bool found = false;
        for (int j=numbers[i]+1;j<numbers[i+1];j++)
          if (gcd(numbers[i],j) == 1 && gcd(numbers[i+1],j) == 1) {
            found = true;
            break;
          }
        if (!found) ++c;
      }
    return c;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2200, 42, 2184, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, getCount(Arg0)); }
	void test_case_1() { int Arr0[] = {13, 1, 6, 20, 33}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getCount(Arg0)); }
	void test_case_2() { int Arr0[] = {7, 42}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, getCount(Arg0)); }
	void test_case_3() { int Arr0[] = {55780, 44918, 55653, 4762, 41536, 40083, 79260, 7374, 24124, 91858, 7856,
 12999, 64025, 12706, 19770, 71495, 32817, 79309, 53779, 8421, 97984, 34586,
 893, 64549, 77792, 12143, 52732, 94416, 54207, 51811, 80845, 67079, 14829,
 25350, 22976, 23932, 62273, 58871, 82358, 13283, 33667, 64263, 1337, 42666}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(3, Arg1, getCount(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  EllysCoprimesDiv2 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
