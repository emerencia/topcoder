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
// 564 500

typedef pair<long long,string> PLLS;

class AlternateColors {
 public:
  string getColor(long long r, long long g, long long b, long long k) {
    vector<PLLS> a;
    a.push_back(PLLS(r,"1RED"));
    a.push_back(PLLS(g,"2GREEN"));
    a.push_back(PLLS(b,"3BLUE"));
    sort(a.begin(),a.end());
    if (k <= 3*a[0].first) {
      // all three remaining
      cout << "case1" << endl;
      return (k%3 == 1 ? "RED" : (k%3 == 2 ? "GREEN" : "BLUE"));
    }
    // k > 3*a[0].first
    k-=3*a[0].first; // blue green order might be diff
    a[1].first-=a[0].first;
    a[2].first-=a[0].first;
    if (k <= 2*a[1].first) {
      // two remaining mods
      cout << "case2" << endl;
      if (a[1].second < a[2].second) return (k%2 == 1 ? a[1].second.substr(1) :
                                                        a[2].second.substr(1));
      else return (k%2 == 1 ? a[2].second.substr(1) :
                              a[1].second.substr(1));
    }
    cout << "case3" << endl;
    return a[2].second.substr(1);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 1LL; long long Arg2 = 1LL; long long Arg3 = 3LL; string Arg4 = "BLUE"; verify_case(0, Arg4, getColor(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { long long Arg0 = 3LL; long long Arg1 = 4LL; long long Arg2 = 5LL; long long Arg3 = 4LL; string Arg4 = "RED"; verify_case(1, Arg4, getColor(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { long long Arg0 = 7LL; long long Arg1 = 7LL; long long Arg2 = 1LL; long long Arg3 = 7LL; string Arg4 = "GREEN"; verify_case(2, Arg4, getColor(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { long long Arg0 = 1000000000000LL; long long Arg1 = 1LL; long long Arg2 = 1LL; long long Arg3 = 1000000000002LL; string Arg4 = "RED"; verify_case(3, Arg4, getColor(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { long long Arg0 = 653LL; long long Arg1 = 32LL; long long Arg2 = 1230LL; long long Arg3 = 556LL; string Arg4 = "BLUE"; verify_case(4, Arg4, getColor(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  AlternateColors ___test;
  ___test.run_test(-1);
}
// END CUT HERE
