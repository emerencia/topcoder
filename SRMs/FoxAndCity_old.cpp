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

class FoxAndCity {
 public:
  vector<int> wan;
  int calchap(const vector<int>& dist) {
    int r = 0;
    for (int i=1;i<dist.size();i++)
      r+= (wan[i]-dist[i])*(wan[i]-dist[i]);
    return r;
  }
  vector<int> calcdist(const vector<string>& linked) {
    vector<int> d(linked.size(),linked.size()+1);
    d[0] = 0;
    for (int i=1;i<linked.size();i++) 
      if (linked[0][i] == 'Y') d[i] = 1;
    for (int i=0;i<linked.size();i++)
      for (int j=0;j<linked.size();j++) {
        if (i == j) continue;
        if (d[j] == linked.size()+1) continue;
        for (int k=0;k<linked.size();k++) {
          if (j == k) continue;
          if (linked[k][j] == 'Y') d[k] = min(d[k],d[j]+1);
        }
      }
    return d;
  }
  int minimalCost(vector <string> linked, vector <int> want) {
    wan = want;
    vector<int> d = calcdist(linked);
    int minhap = calchap(d);
    for (int i=0;i<linked.size();i++) {
      for (int j=i+1;j<linked.size();j++) {
        if (linked[i][j] == 'Y') continue;
        linked[i][j] = 'Y';
        linked[j][i] = 'Y';
        minhap = min(minhap,calchap(calcdist(linked)));
        linked[i][j] = 'N';
        linked[j][i] = 'N';
      }
    }
    return minhap;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN",
 "YNY",
 "NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"NYNN",
 "YNYN",
 "NYNY",
 "NNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 3, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(1, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"NYNNNY",
 "YNYNNN",
 "NYNYNN",
 "NNYNYN",
 "NNNYNY",
 "YNNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 2, 2, 2, 2, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"NYY","YNN","YNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"NYNNNN",
 "YNYNNN",
 "NYNYYY",
 "NNYNYY",
 "NNYYNY",
 "NNYYYN"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3, 0, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(4, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"NYNNNN",
 "YNYNNN",
 "NYNYYY",
 "NNYNYY",
 "NNYYNY",
 "NNYYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 4, 0, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(5, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"NYNYYYYYYYY","YNYNNYYNYYY","NYNNNYYNYYN","YNNNYYYYYYY","YNNYNYYYNYY","YYYYYNNYYNY","YYYYYNNNYYY","YNNYYYNNNYY","YYYYNYYNNNY","YYYYYNYYNNY","YYNYYYYYYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,0,0,5,1,3,0,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 28; verify_case(6, Arg2, minimalCost(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  FoxAndCity ___test;
  ___test.run_test(-1);
}
// END CUT HERE
