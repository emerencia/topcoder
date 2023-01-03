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
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<string,int> PSI;
// BEGIN CUT HERE
const int toTest = -1;
// 
// END CUT HERE

class AllCycleLengths {
 public:
  vector<string> arcs;
  set<int> dists;
  string calcstring(int idx) {
    string s;
    set<int> a;
    set<int> b;
    a.insert(idx);
    for (int k=0;k<900;k++) {
      b.clear();
      for (set<int>::iterator i=a.begin();i!=a.end();i++)
        for (int j=0;j<arcs.size();j++)
          if (arcs[(*i)][j] == 'Y')
            b.insert(j);
      s+= (b.count(idx) ? '1' : '0');
      swap(a,b);
    }
    return s;
  }
  string mymerge(string a, string b) {
    if (b.size() < a.size()) swap(a,b);
    string s = b;
    for (int i=0;i<a.size();i++)
      if (a[i] == '1')
        s[i] = '1';
    return s;
  }
  string reduce(string s, int g) {
    string period = s.substr(s.size()-g);
    if (s.size() >= 2*g) {
      if (s.substr(s.size()-2*g) == period+period)
        return reduce(s.substr(0,s.size()-g),g);
    }
    return s.substr(0,s.size()-g)+"(" + period + ")";
  }
  string findAll(vector <string> arcs) {
    this->arcs = arcs;
    string s;
    for (int i=0;i<arcs.size();i++) {
      string t = calcstring(i);
      if (s != "") s = mymerge(s,t);
      else s = t;
    }
    string t(905,'0');
    for (int i=1;i<31;i++) {
      for (int j=0;j<i && j < 31 && i+j <= s.size();j++) {
        string b = reduce(s.substr(0,s.size()-j),i);
        if (b.size() < t.size() || (b.size() == t.size() && b < t))
          t = b;
      }
    }
    return t;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYNN", "NNYY", "NNNY", "YNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "00110(1)"; verify_case(0, Arg1, findAll(Arg0)); }
	void test_case_1() { string Arr0[] = {"NY", "YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "(01)"; verify_case(1, Arg1, findAll(Arg0)); }
	void test_case_2() { string Arr0[] = {"NYYYY", "NNYYY", "NNNYY", "NNNNY", "YNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0(1)"; verify_case(2, Arg1, findAll(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYNNN", "NNYNN", "NNNYN", "NNNNY", "YNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "010(1)"; verify_case(3, Arg1, findAll(Arg0)); }
	void test_case_4() { string Arr0[] = {"NNNYYNNNNN", "NNNNYNNNNN", "YYNNNNNNNN", "NNNNNYNNNN", "NNNNNNYNNN", "NNNNNNNNYN", "NNNYNNNNNY", "YNNNNNNNNN", "NNYNNNNYNN", "NNNNYNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "00101110110(1)"; verify_case(4, Arg1, findAll(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  AllCycleLengths ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
