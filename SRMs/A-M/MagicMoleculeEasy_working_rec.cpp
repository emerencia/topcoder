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



class MagicMoleculeEasy {
 public:
  int n;
  int m;
  vector<int> mp;
  vector<int> l;
  vector<int> r;
  int rec(long long used,int idx,int k) {
    if (k == -1) return -1;
    if (idx == m) {
      vector<int> unusedpowers;
      int res = 0;
      for (int i=0;i<n;i++) {
        if (used&(1LL<<i)) res+= mp[i];
        else unusedpowers.push_back(mp[i]);
      }
      sort(unusedpowers.rbegin(),unusedpowers.rend());
      for (int i=0;i<k;i++)
        res+=unusedpowers[i];
      return res;
    }
    if ((used&(1LL<<l[idx])) || (used&(1LL<<r[idx]))) {
      return rec(used,idx+1,k);
    }
    return max(rec(used|(1LL<<l[idx]),idx+1,k-1),
               rec(used|(1LL<<r[idx]),idx+1,k-1));
  }
  int maxMagicPower(vector <int> magicPower, vector <string> magicBond, int k) {
    mp = magicPower;
    n = mp.size();
    l = vector<int>();
    r = vector<int>();
    for (int i=0;i<n;i++)
      for (int j=i;j<n;j++) {
        if (magicBond[i][j] == 'N') continue;
        l.push_back(i);
        r.push_back(j);
      }
    m = l.size();
    return rec(0,0,k);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NY",
 "YN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 2; verify_case(0, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {100, 1, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYN",
 "YNY",
 "NYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; verify_case(1, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {100, 1, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYN",
 "YNY",
 "NYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 200; verify_case(2, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {4, 7, 5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNY",
 "YNYN",
 "NYNY",
 "YNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 15; verify_case(3, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {46474, 60848, 98282, 58073, 42670, 50373}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNNNY", "YNNYNY", "NNNYYY", "NYYNNN", "NNYNNN", "YYYNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 209503; verify_case(4, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNYYYNYYNYNNY", "NNYNYYYYYYYNY", "YYNYYNYYYYYYY", "YNYNYYNYYYYYY",
 "YYYYNNYYYYYNY", "NYNYNNYYYYYNN", "YYYNYYNYYYYYY", "YYYYYYYNYNYYY",
 "NYYYYYYYNYYYY", "YYYYYYYNYNNNN", "NYYYYYYYYNNYN", "NNYYNNYYYNYNN", "YYYYYNYYYNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; int Arg3 = -1; verify_case(5, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arr0[] = {1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NN", "NN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; verify_case(6, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_7() { int Arr0[] = {1,1,2,5,2,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNNNNNN","NNYNNNN","NYNNNYN","NNNNNNY","NNNNNNN","NNYNNNN","NNNYNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 11; verify_case(7, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  MagicMoleculeEasy ___test;
  ___test.run_test(-1);
}
// END CUT HERE
