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
// 23:12--23:50

class SurveillanceSystem {
 public:
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
    /*
    for (int k=0;k<n;k++) {
      int nrcompat = 0;
      for (int i=0;i<m;i++) {
        bool cando = true;
        bool seen = false;
        for (int j=0;j<canmonitor[0].size();j++)
          if (canmonitor[i][j] && (k < j || k > j+L-1)) {
            cando = false;
            break;
          } else if (canmonitor[i][j]) {
            seen = true;
          }
        if (cando && seen) {
          s[k] = '+';
          break;
        }
      }
      if (nrcompat == 0) s[k] = '-';
      else if (nrcompat == 1) s[k] = '+';
    }
    return s;
    */
    vector<int> nrcompat(n,0);
    vector<vector<int> > iscompat(n,vector<int>(m,false));
    priority_queue<PII> q;
    for (int i=0;i<n;i++) {
      int ncompat = 0;
      for (int j=0;j<m;j++) {
        bool iscomp = false;
        for (int r=max(0,i-L+1);r<=i && r+L-1 < n;r++)
          if (canmonitor[j][r]) {
            iscomp = true;
            break;
          }
        if (iscomp) {
         ncompat++;
         iscompat[i][j] = 1;
        }
      }
      nrcompat[i] = ncompat;
      q.push(PII(-ncompat,-i));
    }
    vector<bool> seen(n,false);
    for (int i=0;i<n;i++)
      cout << nrcompat[i];
    cout << endl << endl;
    for (int j=0;j<m;j++) {
      for (int i=0;i<n-L+1;i++)
        cout << canmonitor[j][i];
      cout << endl;
    }
    string s(n,'?');
    while (!q.empty()) {
      PII p = q.top();
      q.pop();
      int nc = -p.first;
      p.second = -p.second;
      if (nc != nrcompat[p.second]) continue;
      cout << "> " << p.second << " " << nc << endl;
      if (seen[p.second]) continue;
      seen[p.second] = 1;
      if (nc == 0) {
        if (s[p.second] == '?') s[p.second] = '-';
        continue;
      }
      if (nc == 1) {
        int idx = -1;
        for (int i=0;i<iscompat[p.second].size();i++)
          if (iscompat[p.second][i]) {
            idx = i;
            break;
          }
        s[p.second] = '+';
        for (int i=0;i<iscompat.size();i++) {
          if (!iscompat[i][idx]) continue;
          nrcompat[i]--;
          iscompat[i][idx] = 0;
          if (i == p.second) continue;
          q.push(PII(-nrcompat[i],-i));
        }
      }
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
  ___test.run_test(0);
}
// END CUT HERE
