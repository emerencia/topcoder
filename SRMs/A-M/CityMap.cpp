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

class CityMap {
 public:
  string getLegend(vector <string> cityMap, vector <int> POIs) {
    vector<int> counts(26,0);
    for (int i=0;i<cityMap.size();i++)
      for (int j=0;j<cityMap[0].size();j++)
        if (cityMap[i][j]!= '.')
          counts[cityMap[i][j]-'A']++;
    string s;
    for (int i=0;i<POIs.size();i++)
      for (int j=0;j<counts.size();j++)
        if (POIs[i] == counts[j]) s+= string(1,j+'A');
      return s;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"M....M",
 "...R.M",
 "R..R.R"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "MR"; verify_case(0, Arg2, getLegend(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"XXXXXXXZXYYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 8, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ZXY"; verify_case(1, Arg2, getLegend(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"...........",
 "...........",
 "...........",
 "..........T"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "T"; verify_case(2, Arg2, getLegend(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"AIAAARRI.......GOAI.",
 ".O..AIIGI.OAAAGI.A.I",
 ".A.IAAAARI..AI.AAGR.",
 "....IAI..AOIGA.GAIA.",
 "I.AIIIAG...GAR.IIAGA",
 "IA.AOA....I....I.GAA",
 "IOIGRAAAO.AI.AA.RAAA",
 "AI.AAA.AIR.AGRIAAG..",
 "AAAAIAAAI...AAG.RGRA",
 ".J.IA...G.A.AA.II.AA"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {16,7,1,35,11,66}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "GOJIRA"; verify_case(3, Arg2, getLegend(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  CityMap ___test;
  ___test.run_test(-1);
}
// END CUT HERE
