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
// 01:47-02:03
// END CUT HERE

int parent[27];
void reset(int n) {
  for (int i=0;i<=n;i++)
    parent[i]=i;
}
int find(int u) {
  if (u==parent[u])
    return u;
  else
    return parent[u]=find(parent[u]);
}
void merge(int a,int b) {
  int pa=find(a);
  int pb=find(b);
  if (pa != pb)
    parent[pa]=pb;
}

class ConvertibleStrings {
 public:
  int leastRemovals(string A, string B) {
    int n = 9;
    reset(2*n);
    for (int i=0;i<A.size();i++)
      merge(A[i]-'A',n+B[i]-'A');
    vector<int> seen(2*n,false);
    int r = 0;
    for (int i=0;i<A.size();i++) {
      int component = find(A[i]-'A');
      if (seen[component]) continue;
      seen[component] = 1;
      map<PII,int> m;
      for (int j=0;j<A.size();j++) {
        if (find(A[j]-'A') != component) continue;
        PII p = PII(A[j]-'A',B[j]-'A');
        if (m.count(p)) m[p]++;
        else m[p] = 1;
      }
      int mx = 0;
      int tot = 0;
      for (map<PII,int>::iterator j=m.begin();j!=m.end();j++) {
        tot += (*j).second;
        if ((*j).second > mx) mx = (*j).second;
      }
      r += tot-mx;
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "DD"; string Arg1 = "FF"; int Arg2 = 0; verify_case(0, Arg2, leastRemovals(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "AAAA"; string Arg1 = "ABCD"; int Arg2 = 3; verify_case(1, Arg2, leastRemovals(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "AAIAIA"; string Arg1 = "BCDBEE"; int Arg2 = 3; verify_case(2, Arg2, leastRemovals(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ABACDCECDCDAAABBFBEHBDFDDHHD"; string Arg1 = "GBGCDCECDCHAAIBBFHEBBDFHHHHE"; int Arg2 = 9; verify_case(3, Arg2, leastRemovals(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ConvertibleStrings ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
