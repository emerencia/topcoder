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
typedef pair<int,int> PII;

class SurveillanceSystem {
 public:
  vector<vector<bool> > g;
  int nr;
  int nl;
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
  string getContainerInfo(string containers, vector <int> reports, int L) {
    int n = containers.size();
    int m = reports.size();
    vector<vector<bool> > canmonitor(m,vector<bool>(n-L+1,false));
    int c = 0;
    for (int i=0;i<L;i++)
      c+=(containers[i] == 'X');
    for (int j=0;j+L-1<n;j++) {
      if (j) {
        c-=(containers[j-1] == 'X');
        c+=(containers[j+L-1] == 'X');
      }
      for (int i=0;i<m;i++) {
        canmonitor[i][j] = (reports[i] == c);
      }
    }
    vector<int> nrcompat(n,0);
    for (int i=0;i<n;i++) {
      int ncompat = 0;
      for (int j=0;j<m;j++) {
        bool iscomp = false;
        for (int r=max(0,i-L+1);r<=i && r+L-1 < n;r++)
          if (canmonitor[j][r]) {
            iscomp = true;
            break;
          }
        ncompat+=iscomp;
      }
      nrcompat[i] = ncompat;
    }     
    string s(n,'?');
    g = canmonitor;
    nl = g.size();
    nr = g[0].size();
    for (int i=0;i<n;i++) {
      if (nrcompat[i] == 0) {
        s[i] = '-';
        continue;
      }
      for (int j=0;j<m;j++)
        for (int r=max(0,i-L+1);r<=i && r < n-L+1;r++)
          g[j][r] = 0;
      if (calc() != m)
        s[i] = '+';
      for (int j=0;j<m;j++)
        for (int r=max(0,i-L+1);r<=i && r < n-L+1;r++)
          g[j][r] = canmonitor[j][r];
    }
    return s;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "-X--XX"; int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "??++++"; verify_case(0, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "-XXXXX-"; int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = string("???")+string("-???"); verify_case(1, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "------X-XX-"; int Arr1[] = {3, 0, 2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; string Arg3 = "++++++++++?"; verify_case(2, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "-XXXXX---X--"; int Arr1[] = {2, 1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = string("???")+string("-??++++??"); verify_case(3, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "-XX--X-XX-X-X--X---XX-X---XXXX-----X"; int Arr1[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; string Arg3 = string("???++++?++++++++++++++++++++??????")+string("--"); verify_case(4, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  SurveillanceSystem ___test;
  ___test.run_test(-1);
}
// END CUT HERE
