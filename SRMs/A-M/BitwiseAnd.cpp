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

class BitwiseAnd {
 public:
    int bitcount(long long t) {
    t = (t&0x5555555555555555LL) + ((t>>1)&0x5555555555555555LL);
    t = (t&0x3333333333333333LL) + ((t>>2)&0x3333333333333333LL);
    t = (t&0x0f0f0f0f0f0f0f0fLL) + ((t>>4)&0x0f0f0f0f0f0f0f0fLL);
    t = (t&0x00ff00ff00ff00ffLL) + ((t>>8)&0x00ff00ff00ff00ffLL);
    t = (t&0x0000ffff0000ffffLL) + ((t>>16)&0x0000ffff0000ffffLL);
    t = (t&0x00000000ffffffffLL) + ((t>>32)&0x00000000ffffffffLL);
    return t;
  }
  vector<long long> lexSmallest(vector<long long> subset, int N) {
    // check if existing set is valid
    vector<long long> r;
    long long freebits = (1LL<<60)-1;
    for (int i=0;i<subset.size();i++) {
      freebits&=~(subset[i]);
      long long overlapmask = 0;
      if (bitcount(subset[i]) < N-1) {
        return r;
      }
      for (int j=0;j<subset.size();j++) {
        if (i == j) continue;
        long long overlap = subset[i]&subset[j];
        if (overlap == 0 || (overlapmask&overlap)) {
          return r;
        }
        overlapmask |= overlap;
      }
    }
    if (N >= 3 && (N-subset.size() > 1 || subset.size() > 1) &&
        N-subset.size() > bitcount(freebits)+1) {
      return r;
    }
    //now do the real stuff 
    int toadd = N-subset.size();
    for (int i=0;i<toadd;i++) {
      vector<long long> validjs;
      for (int j=0;j<subset.size();j++) {
        long long validj = subset[j];
        for (int k=0;k<subset.size();k++) {
          if (j == k) continue;
          validj&=~(subset[k]);
        }
        if (!validj) {
          return r;
        }
        validjs.push_back(validj);
      }
      //sort(validjs.begin(),validjs.end()); // not needed because all distinct
      // so if you can add one you add the smallest used bit and the smallest free bit
      long long notmask = 0;
      long long newnum = 0;
      for (int j=0;j<validjs.size();j++) {
        validjs[j]&=~(notmask);
        if (!validjs[j]) {
          return r;
        }
        for (int k=0;(1LL<<k)<=validjs[j];k++)
          if (validjs[j]&(1LL<<k)) {
            newnum|=(1LL<<k);
            notmask|=(1LL<<k);
            break;
          }
      }
      for (int k=i+1;k<toadd;k++)
        for (int l=0;(1LL<<l)<=freebits;l++)
          if ((1LL<<l)&freebits) {
            newnum|=(1LL<<l);
            freebits&=~(1LL<<l);
            break;
          }
      subset.push_back(newnum);
    }
    sort(subset.begin(),subset.end());
    return subset;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { long long Arr0[] = {14, 20}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long Arr2[] = {14, 18, 20 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, lexSmallest(Arg0, Arg1)); }
	void test_case_1() { long long Arr0[] = {11, 17, 20}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; long Arr2[] = { }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, lexSmallest(Arg0, Arg1)); }
	void test_case_2() { long long Arr0[] = {99, 157}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; long Arr2[] = {99, 157, 262, 296 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, lexSmallest(Arg0, Arg1)); }
	void test_case_3() { long long Arr0[] = {1152921504606846975LL}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long Arr2[] = { }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, lexSmallest(Arg0, Arg1)); }
	void test_case_4() { long long Arr0[] = {}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; long Arr2[] = {15, 113, 402, 676, 840 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, lexSmallest(Arg0, Arg1)); }
	void test_case_5() { long long Arr0[] = {1, 3, 5, 7, 9, 11}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; long Arr2[] = { }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, lexSmallest(Arg0, Arg1)); }
	void test_case_6() { long long Arr0[] = {255, 257, 258}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long Arr2[] = {255,257,258}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(6, Arg2, lexSmallest(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  BitwiseAnd ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
