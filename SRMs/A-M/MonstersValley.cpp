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

long long mem[51][103];

class MonstersValley {
 public:
  vector<long long> dre;
  vector <int> pri;
  int n;
  long long maximumdreadwithatmost(int idx,int p) {
    if (idx == -1) return 0;
    long long& r = mem[idx][p];
    if (r != -2) return r;
    if (p == 0) return r = -1;
    long long res = maximumdreadwithatmost(idx-1,p);
    if (res < dre[idx]) res = -1;
    if (p >= pri[idx]) {
      long long res2 = maximumdreadwithatmost(idx-1,p-pri[idx]);
      if (res2 != -1)
        res = max(res,dre[idx]+res2);
    }
    return r = res;
  }
  int minimumPrice(vector<long long> dread, vector <int> price) {
    pri = price;
    n = price.size();
    dre = dread;
    for (int i=0;i<51;i++)
      for (int j=0;j<103;j++)
        mem[i][j] = -2;
    for (int i=0;i<103;i++) {
      maximumdreadwithatmost(n-1,i);
    }
    int mj = 0;
    for (int i=0;i<51;i++) {
      for (int j=0;j<103;j++) {
        if (mem[i][j] >= dre[i]) { mj = max(mj,j); break; }
      }
    }
    return mj;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long Arr0[] = {8, 5, 10}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, minimumPrice(Arg0, Arg1)); }
	void test_case_1() { long Arr0[] = {1, 2, 4, 1000000000}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(1, Arg2, minimumPrice(Arg0, Arg1)); }
	void test_case_2() { long Arr0[] = {200, 107, 105, 206, 307, 400}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 1, 1, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, minimumPrice(Arg0, Arg1)); }
	void test_case_3() { long Arr0[] = {5216, 12512, 613, 1256, 66, 17202, 30000, 23512, 2125, 33333}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 1, 1, 1, 1, 2, 1, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(3, Arg2, minimumPrice(Arg0, Arg1)); }
void test_case_4() { long long Arr0[] = {8589934592LL, 4294967296LL, 2147483648LL, 1073741824LL, 536870912LL, 268435456LL, 134217728LL, 67108864LL, 33554432LL, 16777216LL, 8388608LL, 4194304LL, 2097152LL, 1048576LL, 524288LL, 262144LL, 131072LL, 65536LL, 32768LL, 16384LL, 8192LL, 4096LL, 2048LL, 1024LL, 512LL, 256LL, 128LL, 64LL, 32LL, 16LL, 8LL, 4LL, 2LL, 1LL, 89011169278LL, 900913592218LL, 573105180887LL, 579137087003LL, 149698905839LL, 832047692813LL, 558111502004LL, 253561629925LL, 876887316333LL, 235624898040LL, 155336388121LL, 197770970131LL, 463071223829LL, 345224747632LL, 921657583888LL, 881486688024LL}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(4, Arg2, minimumPrice(Arg0, Arg1)); }
void test_case_5() { long long Arr0[] = {1LL, 2LL, 4LL, 8LL, 16LL, 32LL, 64LL, 128LL, 256LL, 512LL, 1024LL, 2048LL, 4096LL, 8192LL, 16384LL, 32768LL, 65536LL, 131072LL, 262144LL, 524288LL, 1048576LL, 2097152LL, 4194304LL, 8388608LL, 16777216LL, 33554432LL, 67108864LL, 134217728LL, 268435456LL, 536870912LL, 1073741824LL, 2147483648LL, 4294967296LL, 8589934592LL, 17179869184LL, 34359738368LL, 68719476736LL, 137438953472LL, 274877906944}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 78; verify_case(5, Arg2, minimumPrice(Arg0, Arg1)); }
// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  MonstersValley ___test;
  ___test.run_test(-1);
}
// END CUT HERE
