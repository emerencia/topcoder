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
// 16:38-17:15

int minoff[27][27];
int maxoff[27][27];
int dist[27][27];

class History {
 public:
  string verifyClaims(vector <string> dynasties, vector <string> battles, vector <string> queries) {
    memset(dist,-1,sizeof(dist));
    fill(&minoff[0][0],&minoff[27][0],INT_MIN);
    fill(&maxoff[0][0],&maxoff[27][0],INT_MAX);
    int n = dynasties.size();
    vector<vector<PII> > dyn(dynasties.size());
    for (int i=0;i<dynasties.size();i++) {
      stringstream a(dynasties[i]);
      int prev = -1;
      int d = -1;
      int offset = 0;
      while (!a.eof()) {
        prev = d;
        a >> d;
        if (prev == -1) {
          offset = d;
          continue;
        }
        dyn[i].push_back(PII(prev-offset,d-offset));
      }
    }
    string bat = accumulate(battles.begin(),battles.end(),string(""));
    stringstream b(bat);
    string tb;
    while (!b.eof()) {
      b >> tb;
      int dyn1 = tb[0]-'A';
      PII p1 = dyn[dyn1][tb[1]-'0'];
      int dyn2 = tb[3]-'A';
      PII p2 = dyn[dyn2][tb[4]-'0'];
      for (int i=0;i<2;i++) {
        int mino = p2.first-p1.second+1;
        int maxo = p2.second-1-p1.first;
        minoff[dyn1][dyn2] = max(minoff[dyn1][dyn2],mino);
        maxoff[dyn1][dyn2] = min(maxoff[dyn1][dyn2],maxo);
        swap(dyn1,dyn2);
        swap(p1,p2);
      }
    }
    for (int i=0;i<n;i++)
      for (int j=0;j<n;j++)
        if (minoff[i][j] != INT_MIN)
          dist[i][j] = abs(maxoff[i][j]-minoff[i][j]);
    for (int k=0;k<n;k++)
      for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
          if (dist[i][k] != -1 && dist[k][j] != -1) {
            if (dist[i][j] == -1 || dist[i][k]+dist[k][j] < dist[i][j]) {
              minoff[i][j] = minoff[i][k]+minoff[k][j];
              maxoff[i][j] = maxoff[i][k]+maxoff[k][j];
              dist[i][j] = dist[i][k]+dist[k][j];
            }
          }
    string r(queries.size(),'Y');
    for (int i=0;i<queries.size();i++) {
      string ttb = queries[i];
      int dyn1 = ttb[0]-'A';
      PII p1 = dyn[dyn1][ttb[1]-'0'];
      int dyn2 = ttb[3]-'A';
      PII p2 = dyn[dyn2][ttb[4]-'0'];
      if (dist[dyn1][dyn2] == -1) continue;
      if (p1.first+minoff[dyn1][dyn2] < p2.second &&
          p1.second+maxoff[dyn1][dyn2] > p2.first) continue;
      r[i] = 'N';
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4();if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 2 4",
 "1 2 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A1-B0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A0-B0",
 "A0-B1",
 "A1-B0",
 "A1-B1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "NNYY"; verify_case(0, Arg3, verifyClaims(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"1000 2000 3000 10000",
 "600 650 2000",
 "1 1001 20001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"B1-C0 A0-B0 A2-C1 B1-C1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A0-B1",
 "A1-B1",
 "A2-B1",
 "C0-A0",
 "B0-A2",
 "C1-B0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "YYYYNN"; verify_case(1, Arg3, verifyClaims(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"1 4 5",
 "10 13 17"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A0-B0 A0-B0 B0-A0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A1-B0",
 "A0-B1",
 "A1-B1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "YYY"; verify_case(2, Arg3, verifyClaims(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"1 5 6",
 "1 2 5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A0",
 "-B0 A",
 "1-B1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A0-B0",
 "A1-B0",
 "A0-B1",
 "A1-B1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "YNYY"; verify_case(3, Arg3, verifyClaims(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"2294 7344","366 384 449 965 1307 1415","307 473 648 688 1097","1145 1411 1569 2606","87 188 551 598 947 998 1917 1942"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A0-B4 B4-E2 B3-E2 D2-E4 A0-E4 B1-C3 A0-E3 A0-E6 D0","-E2 B2-E1 B4-E3 B4-D0 D0-E3 A0-D1 B2-C3 B1-C3 B4-E","3 D0-E1 B3-D0 B3-E2"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A0-C2","E6-C2","A0-E4","B3-C1","C0-D2","B0-C1","D1-C3","C3-D0","C1-E3","D1-A0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "YNYNNYNNNY"; verify_case(4, Arg3, verifyClaims(Arg0, Arg1, Arg2)); }
  void test_case_5() { string Arr0[] = {"20860 31820 41745 43159 43989 50694 76706 80147", "2238 9362 10644 18518 20198 27220 34232", "7215 7486 34586 50015", "472 5972 9135 25699 32628 72739", "25042 25282 32799 34572 56172 87326"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"B2-C0 A4-E2 D4-E3 C1-D1 A4-D4 A2-E2 B4-C1 D2-E1 A4", "-E2 B2-C0 A3-D4 A3-C2 A3-E2 C2-E3 C1-D2 C1-D2 B4-C", "1 B2-C0 A2-C2 B2-D0 B4-D2 B5-C1 A4-C2 B4-D2 B2-C0 ", "D3-E1 D4-E3 A0-C1 A1-B5 D3-E2 A4-E3 A2-E1 C1-D3 D2", "-E1 A4-D4 C2-E1 C2-E3 C1-D0 A0-B4 A2-D4 A0-B4 A4-C", "2 A5-E3 C2-E2 C2-D4 A4-E3 D3-E1 A2-D4 A5-E4 B4-C1 ", "B5-D2 C0-D0 A3-E2 A1-D2 C2-E1 B2-D1 A0-C1 A5-C2 A2", "-E2 A0-B4 B2-C1 D2-E0 A0-D2 A6-E4 A2-C1 A0-B5 A3-D", "4 C2-D3 D2-E0 B3-D1 D2-E0 A5-C2 A4-C2 B2-C1 B4-C1 ", "C0-D0 A5-D4 A5-E4 B5-C1 A0-B5 A3-D4 A6-E4 A0-B5 C1", "-D1 C0-D0 A1-E0 A4-E2 A3-E2 D3-E1 A1-B5 A3-E2 A5-D", "4 A5-E4 A0-C1 B2-C1 A1-C1 A5-D4 A0-B4 A4-D4 A2-D4 ", "A1-D3 A1-E1 A5-C2 A3-E2 C0-D0 A1-E1 A2-C2 A1-D3 C2", "-E3 B2-C0 D4-E2 A5-C2 A5-C2 A5-E4 C2-E3 C0-D0 B3-D", "2 A3-E2 A1-B5 A3-C2 B2-D1 D2-E0 A4-E3 A3-D4 B2-D0 ", "B2-D0 C2-E2 A0-B4 C1-D0 C2-D4 D3-E1 B4-D2 D4-E2 A6", "-E4 A2-C1 A1-B5 A5-C2 A2-C2 C1-D2 B5-C1 A2-C1 C1-D", "2 C0-D0 B3-D1 A2-E2 D3-E2 B4-D2 A3-C2 A3-C2 B2-D0"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A2-B3", "C1-E4", "B1-C2", "E1-D4", "A5-B2", "B3-A2", "B2-D1", "C0-A5", "B0-E3", "E4-C2", "C1-E4", "C1-B5", "C1-D2", "C0-D4", "C1-D1", "C2-B3", "C0-A5", "C2-B2", "A1-C0", "B5-D1", "B1-E3", "E3-D2", "C1-A4", "D2-B0", "E4-A6", "C0-E0", "A2-C2", "E4-C2", "C0-B1", "C0-E0", "D1-B3", "A1-D3", "D0-A2", "B3-C0", "C1-B3", "C1-A6", "D2-B2", "A3-B1", "C0-A1", "D3-E0", "A3-D3", "B1-C1", "A2-C0", "E4-B4", "D0-E4", "E3-C1", "A6-D4", "E4-A1", "B2-A0", "A5-B0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "NNNNNNYNNNNYYNYNNNNNNNNNYNYNNNYYNNYNNNNNNNNNNNYNNN"; verify_case(5, Arg3, verifyClaims(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  History ___test;
  ___test.run_test(-1);
}
// END CUT HERE
