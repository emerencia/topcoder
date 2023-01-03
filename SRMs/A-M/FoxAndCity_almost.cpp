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
typedef pair<int,int> PII;
typedef long long LL;
// BEGIN CUT HERE
const int toTest = -1;
// 15:00-15:12-15:38
// END CUT HERE

int dist[41][41];

class FoxAndCity {
 public:
  int n;
  vector<int> layer;
  vector<string> linked;
  vector<int> want;
  void lower_branch_layers(int node, int offset) {
    int oldlayer = layer[node];
    for (int i=1;i<n;i++)
      if (linked[node][i] == 'Y' && layer[i] == oldlayer+1)
        lower_branch_layers(i,offset);
    layer[node]-=offset;
  }
  int branch_unhappiness(int node, int offset) {
    int r = (want[node] - (layer[node]+offset))*
            (want[node] - (layer[node]+offset));
    for (int i=0;i<n;i++)
      if (linked[node][i] == 'Y' && layer[i] == layer[node]+1)
        r+=branch_unhappiness(i,offset);
    return r;
  }
  int minimalCost(vector <string> linked, vector <int> want) {
    this->linked = linked;
    this->want = want;
    n = linked.size();
    fill(&dist[0][0],&dist[41][0],INT_MAX);
    for (int i=0;i<n;i++)
      for (int j=0;j<n;j++) {
        if (i == j) dist[i][j] = 0;
        else if (linked[i][j] == 'Y')
          dist[i][j] = 1;
      }
    for (int k=0;k<n;k++)
      for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
          if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
              dist[i][k]+dist[k][j] < dist[i][j])
            dist[i][j] = dist[i][k]+dist[k][j];
    layer = vector<int>(n);
    int maxlayer = 0;
    for (int i=0;i<n;i++) {
      layer[i] = dist[i][0];
      maxlayer = max(maxlayer,layer[i]);
    }
    for (int l=2;l<=maxlayer;l++) {
      int mini = -1;
      int minoffset = -1;
      int maxunhappy = 0;
      for (int i=1;i<n;i++) {
        if (layer[i] != l) continue;
        int nowunhappy = branch_unhappiness(i,0);
        for (int o=1;o<l;o++) {
          int thenunhappy = branch_unhappiness(i,-o);
          if (thenunhappy < nowunhappy) {
            int happydiff = nowunhappy-thenunhappy;
            if (happydiff > maxunhappy) {
              maxunhappy = happydiff;
              mini = i;
              minoffset = o;
            }
          }
        }
      }
      if (mini != -1) {
        lower_branch_layers(mini,minoffset);
        int j = 0;
        for (;j<n;j++)
          if (layer[j] == l-minoffset-1) break;
        if (j != n) {
          this->linked[mini][j] ='Y';
          this->linked[j][mini] ='Y';
        }
        l -= minoffset;
      }
    }
    return branch_unhappiness(0,0);
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
  ___test.run_test(toTest);
}
// END CUT HERE
