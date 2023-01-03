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
#include "ticks.h"
using namespace std;

typedef pair<int,int> PII;
int mem[1<<17];

class KingdomAndPassword {
 public:
   vector<int> resdig;
   vector<char> num;
   long long oldpw;
   long long mn;
   long long mndist;
   void rec(int done,int idx,string number, bool frombelow) {
     // largest one smaller than oldpw
     if (mem[done] != -1) return;
     if (idx == num.size()) {
       stringstream a(number);
       long long rnumb;
       a >> rnumb;
       if (abs(rnumb-oldpw) < mndist) {
         mndist = abs(rnumb-oldpw);
         mn = rnumb;
       }
       mem[done] = 1;
       return;
     }
     vector<PII> dfs;
     stringstream d;
     d << oldpw;
     stringstream f(d.str().substr(0,idx+1));
     long long opw;
     f >> opw;
     for (int i=0;i<num.size();i++) {
       if (done&(1<<i)) continue;
       if (resdig[idx] == num[i]-'0') continue;
       string h = number;
       h[idx] = num[i];
       stringstream c(h.substr(0,idx+1));
       long long rnumb;
       c >> rnumb;
       if ((frombelow && opw >= rnumb) || (!frombelow && opw <= rnumb))
         dfs.push_back(PII(num[i]-'0',i));
     }
     if (frombelow) sort(dfs.rbegin(),dfs.rend());
     else sort(dfs.begin(),dfs.end());
     for (int i=0;i<dfs.size();i++) {
       int j = dfs[i].second;
       if (mn != -1) break;
       string h = number;
       h[idx] = num[j];
       rec(done^(1<<j),idx+1,h,frombelow);
     }
     mem[done] = 1;
   }
  long long newPassword(long long oldPassword, vector <int> restrictedDigits) {
    oldpw = oldPassword;
    resdig = restrictedDigits;
    mn = -1;
    mndist = LLONG_MAX;
    stringstream a;
    a << oldPassword;
    string b = a.str();
    num = vector<char>(b.size());
    for (int i=0;i<b.size();i++) {
      num[i] = b[i];
    }
    bool f = true;
    for (int i=0;i<num.size();i++) {
      if (num[i]-'0' == resdig[i]) { f = false; break; }
    }
    if (f) return oldPassword;
    string n = string(b.size(),'0');
    for (int i=0;i<(1<<17);i++) mem[i] = -1;
    rec(0,0,n,true);
    long long a1 = mn;
    long long a1mndist = mndist;
    mn = -1;
    mndist = LLONG_MAX;
    for (int i=0;i<(1<<17);i++) mem[i] = -1;
    rec(0,0,n,false);
    if (mndist < a1mndist) return mn;
    return a1;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4();if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 548LL; int Arr1[] = {5, 1, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 485LL; verify_case(0, Arg2, newPassword(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 7777LL; int Arr1[] = {4, 7, 4, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = -1LL; verify_case(1, Arg2, newPassword(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 58LL; int Arr1[] = {4, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 58LL; verify_case(2, Arg2, newPassword(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 172LL; int Arr1[] = {4, 7, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 127LL; verify_case(3, Arg2, newPassword(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 241529363573463LL; int Arr1[] = {1, 4, 5, 7, 3, 9, 8, 1, 7, 6, 3, 2, 6, 4, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 239676554423331LL; verify_case(4, Arg2, newPassword(Arg0, Arg1)); }	void test_case_5() { long long Arg0 = 9151LL; int Arr1[] = {9, 1, 5, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1915LL; verify_case(5, Arg2, newPassword(Arg0, Arg1)); }
  void test_case_6() { long long Arg0 = 3941LL; int Arr1[] = {5, 9, 5, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 4139LL; verify_case(6, Arg2, newPassword(Arg0, Arg1)); }
  void test_case_7() { long long Arg0 = 3345411115342361LL; int Arr1[] = {4, 1, 1, 3, 1, 1, 1, 6, 2, 1, 4, 1, 1, 1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1651544114133332LL; verify_case(7, Arg2, newPassword(Arg0, Arg1)); }
  void test_case_8() { long long Arg0 = 4752914625388618LL; int Arr1[] = {9, 8, 7, 3, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 8188122344556679LL; verify_case(8, Arg2, newPassword(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  KingdomAndPassword ___test;
    beginn();
  ___test.run_test(8);
  endd();
  cout << "time: " << ticks() << "ms" << endl;
}
// END CUT HERE
