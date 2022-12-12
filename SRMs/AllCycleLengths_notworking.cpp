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
const int toTest = 4;
// 
// END CUT HERE

class AllCycleLengths {
 public:
  vector<string> arcs;
  set<int> dists;
  int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b,a%b);
  }
  void dfs(int cur, int end, int dist, vector<bool> seen) {
    if (dist != 0 && cur == end) {
      dists.insert(dist);
      return;
    }
    if (cur != end)
      seen[cur] = true;
    for (int i=0;i<arcs.size();i++)
      if (i != cur && !seen[i] && arcs[cur][i] == 'Y')
        dfs(i,end,dist+1,seen);
  }
  PSI calcstring(int idx) {
    vector<bool> seen(arcs.size(),0);
    dists.clear();
    dfs(idx,idx,0,seen);
    int g = -1;
    for (set<int>::iterator i=dists.begin();i!=dists.end();i++)
      g = (g == -1 ? (*i) : gcd(g,(*i)));
    long long fac = -1;
    for (set<int>::iterator i=dists.begin();i!=dists.end();i++)
      fac *= (fac == -1 ? -(*i) : (*i)/g);
    fac = min(60LL,fac);
    string s(fac,'0');
    bool changed = true;
    while (changed) {
      changed = false;      
      for (set<int>::iterator i=dists.begin();i!=dists.end();i++) {
        if (s[(*i)-1] != '1') {
          s[(*i)-1] = '1';
          changed = true;
        }
        for (int j=0;j<s.size();j++)
          if (s[j] == '1' && j+(*i) < s.size() && s[j+(*i)] != '1') {
            s[j+(*i)] = '1';
            changed = true;
          }
      }
    }
    return PSI(s,g);
  }
  PSI mymerge(PSI q, PSI t) {
    string a = q.first;
    string b = t.first;
    if (b.size() < a.size()) swap(a,b);
    string s = b;
    for (int i=0;i<a.size();i++)
      if (a[i] == '1')
        s[i] = '1';
    return PSI(s,gcd(q.second,t.second));
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
    PSI s("",-1);
    for (int i=0;i<arcs.size();i++) {
      PSI t = calcstring(i);
      if (s.second != -1) s = mymerge(s,t);
      else s = t;
    }
    cout << s.first << endl;
    s.first = reduce(s.first,s.second);
    return s.first;
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
