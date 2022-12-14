#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>-
#include <cmath>
#include <utility>
#include <climits>
#include <cstring>
using namespace std;
typedef pair<int,int> PII;

class SwappingDigits {
 public:
  string minNumber(string num) {
    vector<string> a;
    a.push_back(num);
    for (int i=0;i<num.size();i++) {
      for (int j=i+1;j<num.size();j++) {
        if (num[j] == '0' && i == 0) continue;
        swap(num[i],num[j]);
        a.push_back(num);
        swap(num[i],num[j]);
      }
    }
    sort(a.begin(),a.end());
    return a[0];
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "596"; string Arg1 = "569"; verify_case(0, Arg1, minNumber(Arg0)); }
	void test_case_1() { string Arg0 = "93561"; string Arg1 = "13569"; verify_case(1, Arg1, minNumber(Arg0)); }
	void test_case_2() { string Arg0 = "5491727514"; string Arg1 = "1491727554"; verify_case(2, Arg1, minNumber(Arg0)); }
	void test_case_3() { string Arg0 = "10234"; string Arg1 = "10234"; verify_case(3, Arg1, minNumber(Arg0)); }
	void test_case_4() { string Arg0 = "93218910471211292416"; string Arg1 = "13218910471211292496"; verify_case(4, Arg1, minNumber(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  SwappingDigits ___test;
  ___test.run_test(-1);
}
// END CUT HERE
