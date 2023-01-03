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
using namespace std;

typedef pair<bool,long long> mp;

class StrongPrimePower {
 public:
  long long to_the_power(long long b,int e,long long bound) {
    long long r = 1;
    for (int i=0;i<e;i++) {
      if (((bound/b) + (bound%b)) < r) { return bound+1; }
      r*=b;
    }
    return r;
  }
  mp inv_pow_is_int(long long b,int q,long long l,long long r) {
    cout << "invp 3, q: " << q << ", l: " << l << ", r: " << r << endl;
    if (l == r) {
      long long ttp = to_the_power(l,q,b);
      cout << "b^e: " << ttp << ", b: " << l << ", e: " << q << ", b: " << b << endl;
      if (ttp == b) return mp(true,ttp);
      return mp(false,ttp);
    }
    long long pivot = (l+r)/2;
    long long pivotp = to_the_power(pivot,q,b);
    if (b == pivotp) { return mp(true,pivotp); }
    else if (b < pivotp) { return inv_pow_is_int(b,q,l,max(l,pivot-1)); }
    return inv_pow_is_int(b,q,min(r,pivot+1),r);
  }
  bool is_prime(int p) {
    for (int i=2;i*i<=p;i++) if (p%i == 0) return false;
    return true;
  }
  vector <int> baseAndExponent(string n) {
    stringstream a(n);
    long long b;
    a >> b;
    vector<int> rr;
    int l = 2;
    int r = 59;
    mp p;
    while (l != r) {
      int q = (l+r)/2;
      p = inv_pow_is_int(b,q,2,b);
      if (b == p.second) { l = q; break; }
      else if (b < p.second) { r = max(l,q-1); }
      else { l = min(r,q+1); }
    }
    if (p.first && is_prime(p.second)) {
      rr.push_back(p.second);
      rr.push_back(l);
    }
    return rr;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "27"; int Arr1[] = {3, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, baseAndExponent(Arg0)); }
	void test_case_1() { string Arg0 = "10"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, baseAndExponent(Arg0)); }
	void test_case_2() { string Arg0 = "7"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, baseAndExponent(Arg0)); }
	void test_case_3() { string Arg0 = "1296"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, baseAndExponent(Arg0)); }
	void test_case_4() { string Arg0 = "576460752303423488"; int Arr1[] = {2, 59 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, baseAndExponent(Arg0)); }
	void test_case_5() { string Arg0 = "999999874000003969"; int Arr1[] = {999999937, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, baseAndExponent(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  StrongPrimePower ___test;
  ___test.run_test(-1);
}
// END CUT HERE
