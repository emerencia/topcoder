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

class CorporationSalary {
 public:
  long long totalSalary(vector <string> relations) {
    queue<int> q;
    int n = relations.size();
    vector<int> subcount(n,0);
    vector<long long> salary(n,-1);
    for (int i=0;i<n;i++) {
      int c = 0;
      for (int j=0;j<n;j++)
        c+=relations[i][j] == 'Y';
      if (c == 0) {
        q.push(i);
      }
      subcount[i] = c;
    }
    long long r = 0;
    while (!q.empty()) {
      int p = q.front();
      q.pop();
      if (salary[p] != -1) continue;
      salary[p] = 0;
      for (int i=0;i<n;i++)
        if (relations[p][i] == 'Y')
          salary[p]+=salary[i];
      if (salary[p] == 0) ++salary[p];
      r+=salary[p];
      for (int i=0;i<n;i++)
        if (relations[i][p] == 'Y') {
          subcount[i]--;
          if (!subcount[i])
            q.push(i);
        }
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(0, Arg1, totalSalary(Arg0)); }
	void test_case_1() { string Arr0[] = {"NNYN",
 "NNYN",
 "NNNN",
 "NYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; verify_case(1, Arg1, totalSalary(Arg0)); }
	void test_case_2() { string Arr0[] = {"NNNNNN",
 "YNYNNY",
 "YNNNNY",
 "NNNNNN",
 "YNYNNN",
 "YNNYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 17LL; verify_case(2, Arg1, totalSalary(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYNNYN",
 "NNNNNN",
 "NNNNNN",
 "NNYNNN",
 "NNNNNN",
 "NNNYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 8LL; verify_case(3, Arg1, totalSalary(Arg0)); }
	void test_case_4() { string Arr0[] = {"NNNN",
 "NNNN",
 "NNNN",
 "NNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(4, Arg1, totalSalary(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  CorporationSalary ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
