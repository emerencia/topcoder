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
#include <numeric>
using namespace std;
typedef pair<string,int> PSI;
typedef long long LL;

int g[51][51];
char leaveout[] = {'R', 'G', 'B'};

class GearsDiv1 {
 public:
  int nl;
  int nr;
  bool bpm(int l,vector<int>& leftof,vector<bool>& seenl, vector<bool>& seenr) {
    if (seenl[l]) return false;
    seenl[l] = true;
    for (int r=0;r<nr;r++) {
      if (seenr[r] || !g[l][r]) continue;
      seenr[r] = true;
      if (leftof[r] == -1 || bpm(leftof[r],leftof,seenl,seenr)) {
        leftof[r] = l;
        return true;
      }
    }
    return false;
  }
  int calc() {
    vector<int> leftof(nr,-1);
    int r = 0;
    for (int l=0;l<nl;l++) {
      vector<bool> seenl(nl,0);
      vector<bool> seenr(nr,0);
      r+= bpm(l,leftof,seenl,seenr);
    }
    return r;
  }
  int getmin(string color, vector <string> graph) {
    int mn = 1400;
    nl = graph.size();
    nr = graph.size();
    for (int i=0;i<3;i++) {
      memset(g,0,sizeof(g));
      for (int k=0;k<graph.size();k++) {
        if (color[k] != leaveout[(i+1)%3]) continue;
        for (int j=0;j<graph.size();j++) {
          if (color[j] != leaveout[(i+2)%3] || graph[k][j] == 'N') continue;
          g[k][j] = 1;
        }
      }
      mn = min(mn,calc());
    }
    return mn;
  }
  
// BEGIN CUT HERE
    // 15:14
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RGB"; string Arr1[] = {"NYY","YNY","YYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, getmin(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "RGBR"; string Arr1[] = {"NNNN","NNNN","NNNN","NNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, getmin(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "RGBR"; string Arr1[] = {"NYNN","YNYN","NYNY","NNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, getmin(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "RRRRRGRRBGRRGBBGGGBRRRGBRGRRGG"; string Arr1[] = {"NNNNNYNNNYNNYNNNYNNNNNNNNYNNYY",
 "NNNNNNNNYNNNYNYNNYNNNNYNNYNNYY",
 "NNNNNYNNNNNNNNNNNNYNNNNNNYNNNY",
 "NNNNNNNNNYNNYNNYYYNNNNYNNYNNNN",
 "NNNNNNNNNYNNYNNYYYNNNNYNNNNNNN",
 "YNYNNNYYYNNYNYYNNNNNYYNYNNYYNN",
 "NNNNNYNNNNNNNNNYYYNNNNYNNYNNYY",
 "NNNNNYNNNNNNNNNYNNNNNNNNNNNNYN",
 "NYNNNYNNNYNNYNNYYYNNNNYNNYNNYY",
 "YNNYYNNNYNNNNYYNNNYNYYNYNNNNNN",
 "NNNNNNNNNNNNYNNYNYNNNNYNNNNNNY",
 "NNNNNYNNNNNNYNNYYYNNNNNNNNNNYN",
 "YYNYYNNNYNYYNYYNNNYNYNNYNNNNNN",
 "NNNNNYNNNYNNYNNYYYNNNNYNNYNYYY",
 "NYNNNYNNNYNNYNNYYYNNNNYNNYNNYY",
 "NNNYYNYYYNYYNYYNNNYNYNNYYNYYNN",
 "YNNYYNYNYNNYNYYNNNYNNNNYYNNYNN",
 "NYNYYNYNYNYYNYYNNNNYYNNYYNYNNN",
 "NNYNNNNNNYNNYNNYYNNNNNYNNYNNNY",
 "NNNNNNNNNNNNNNNNNYNNNNYNNYNNNY",
 "NNNNNYNNNYNNYNNYNYNNNNYNNNNNYY",
 "NNNNNYNNNYNNNNNNNNNNNNYNNNNNNN",
 "NYNYYNYNYNYNNYYNNNYYYYNYYNYNNN",
 "NNNNNYNNNYNNYNNYYYNNNNYNNNNNNY",
 "NNNNNNNNNNNNNNNYYYNNNNYNNYNNYY",
 "YYYYNNYNYNNNNYYNNNYYNNNNYNYYNN",
 "NNNNNYNNNNNNNNNYNYNNNNYNNYNNYN",
 "NNNNNYNNNNNNNYNYYNNNNNNNNYNNYY",
 "YYNNNNYYYNNYNYYNNNNNYNNNYNYYNN",
 "YYYNNNYNYNYNNYYNNNYYYNNYYNNYNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, getmin(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  GearsDiv1 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
