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
typedef pair<int,long long> PII;

class SpaceWarDiv1 {
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
  long long minimalFatigue(vector <int> magicalGirlStrength, vector <int> enemyStrength, vector<long long> enemyCount) {
    int N = magicalGirlStrength.size();
    vector<long long> f(magicalGirlStrength.size(),0);
    vector<PII> enemy;
    for (int i=0;i<enemyStrength.size();i++)
      enemy.push_back(PII(enemyStrength[i],enemyCount[i]));
    sort(enemy.rbegin(),enemy.rend());
    sort(magicalGirlStrength.rbegin(),magicalGirlStrength.rend());
    if (enemy[0].first > magicalGirlStrength[0]) return -1;
    for (int i=0;i<enemy.size();i++) {
      long long goodgirls = 0;
      long long maxfat = 0;
      for (int j=0;j<magicalGirlStrength.size();j++)
        if (magicalGirlStrength[j] >= enemy[i].first) {
          goodgirls |= (1LL<<j);
          maxfat = max(maxfat,f[j]);
        } else break;
      long long todo = enemy[i].second;
      for (int j=0;j<N;j++) {
        if (!(goodgirls&(1LL<<j))) continue;
        if (f[j] < maxfat) {
          long long d = min(todo,maxfat-f[j]);
          todo -= d;
          f[j] += d;
        }
      }
      if (todo) {
        long long divv = todo/bitcount(goodgirls);
        if (divv)
          for (int j=0;j<N;j++) {
            if (!(goodgirls&(1LL<<j))) continue;
            f[j] += divv;
          }
        todo = todo%bitcount(goodgirls);
        if (todo)
          for (int j=0;j<N;j++) {
            if (!(goodgirls&(1LL<<j))) continue;
            f[j]++;
            if (!(--todo)) break;
          }
      }
    }
    long long r = 0;
    for (int j=0;j<N;j++)
      r = max(r,f[j]);
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 3, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {2, 9, 4}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 7LL; verify_case(0, Arg3, minimalFatigue(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {2, 3, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {2, 9, 4}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 5LL; verify_case(1, Arg3, minimalFatigue(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {14, 6, 22}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8, 33}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {9, 1}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = -1LL; verify_case(2, Arg3, minimalFatigue(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {869, 249, 599, 144, 929, 748, 665, 37, 313, 99, 33, 437, 308, 137, 665, 834, 955, 958, 613, 417}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {789, 57, 684, 741, 128, 794, 542, 367, 937, 739, 568, 872, 127, 261, 103, 763, 864, 360, 618, 307}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arr2[] = {20626770196420, 45538527263992, 52807114957507, 17931716090785, 65032910980630, 88711853198687, 26353250637092,
 61272534748707, 89294362230771, 52058590967576, 60568594469453, 23772707032338, 43019142889727, 39566072849912,
 78870845257173, 68135668032761, 36844201017584, 10133804676521, 6275847412927, 37492167783296}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 75030497287405LL; verify_case(3, Arg3, minimalFatigue(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  SpaceWarDiv1 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
