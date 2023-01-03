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

int mem[51][51];

class SpellCardsEasy {
 public:
  vector<int> lev;
  vector<int> dmg;
  int n;
  int rec(int idx, int owed) {
    if (idx == n) return 0;
    int& r = mem[idx][owed];
    if (r != -1) return r;
    int res = 0;
    if (owed+lev[idx] <= n-idx)
      res = dmg[idx]+rec(idx+1,owed+lev[idx]-1);
    return r = max(res,rec(idx+1,max(0,owed-1)));
  }
  int maxDamage(vector <int> level, vector <int> damage) {
    n = level.size();
    lev = level;
    dmg = damage;
    memset(mem,-1,sizeof(mem));
    return rec(0,0);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,20,30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 60; verify_case(0, Arg2, maxDamage(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,20,30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(1, Arg2, maxDamage(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {4,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,20,30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, maxDamage(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {50,1,50,1,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,20,30,40,50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 60; verify_case(3, Arg2, maxDamage(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {2,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {40,40,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 80; verify_case(4, Arg2, maxDamage(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1,2,1,1,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,40,10,10,90,40,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 150; verify_case(5, Arg2, maxDamage(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {1,2,2,3,1,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {113,253,523,941,250,534,454}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1577; verify_case(6, Arg2, maxDamage(Arg0, Arg1)); }
  void test_case_7() { int Arr0[] = {12, 3, 8, 3, 11, 11, 10, 11, 7, 10, 2, 2, 9, 1, 6, 8, 10, 5, 3, 5, 4, 8, 2, 9, 5, 6, 11, 11, 7, 8, 4, 9, 8, 2, 6, 7, 12, 8, 7, 10, 1, 6, 13, 1, 11, 1, 5, 3, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {884, 773, 922, 809, 917, 753, 803, 807, 768, 797, 920, 853, 790, 914, 929, 758, 804, 930, 873, 858, 771, 831, 835, 802, 904, 890, 837, 843, 857, 814, 874, 886, 905, 930, 770, 804, 789, 777, 904, 800, 817, 771, 834, 809, 909, 788, 873, 765, 896}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 13809; verify_case(7, Arg2, maxDamage(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  SpellCardsEasy ___test;
  ___test.run_test(-1);
}
// END CUT HERE
