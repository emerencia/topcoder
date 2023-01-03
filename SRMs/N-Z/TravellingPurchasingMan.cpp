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
typedef long long LL;
typedef pair<int,long long> PILL;
typedef pair<int,PILL> PII;
typedef pair<int,int> PIII;
        // visited at(inc in visited))
long long dp[1<<16][16];

class TravellingPurchasingMan {
 public:
  int bitcount(int n) {
    int c = 0;
    for (int i=n;i;i&=i-1) c++;
    return c;
  }
  int maxStores(int N, vector <string> interestingStores, vector <string> roads) {
    vector<vector<int> > stores(interestingStores.size());
    int M = interestingStores.size();
    for (int i=0;i<interestingStores.size();i++) {
      stringstream a(interestingStores[i]);
      for (int j=0;j<3;j++) {
        int b;
        a >> b;
        stores[i].push_back(b);
      }
    }
    vector<vector<int> > g(N,vector<int>(N,-1));
    for (int i=0;i<roads.size();i++) {
      stringstream a(roads[i]);
      int c;
      a >> c;
      int b;
      a >> b;
      int w;
      a >> w;
      g[c][b] = w;
      g[b][c] = w;
    }
    for (int k=0;k<N;k++)
      for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
          if (g[i][k]!= -1 && g[k][j] != -1)
            g[i][j] = (g[i][j] == -1 ? g[i][k]+g[k][j] : min(g[i][j],g[i][k]+g[k][j]));
    memset(dp,-1,sizeof(dp));
    for (int i=0;i<M;i++)
      if (i == N-1)
        dp[(1<<i)][i] = stores[i][0]+stores[i][2];
      else if (g[N-1][i] != -1 && g[N-1][i] <= stores[i][1])
        dp[(1<<i)][i] = max(g[N-1][i],stores[i][0])+stores[i][2];
    for (int i=0;i<(1<<M);i++) {
      for (int j=0;j<M;j++) {
        if (dp[i][j] == -1) continue;
        for (int k=0;k<M;k++) {
          if (i&(1<<k) || g[j][k] == -1 || dp[i][j]+g[j][k] > stores[k][1]) continue;
          long long t = max(dp[i][j]+g[j][k],LL(stores[k][0]))+stores[k][2];
          dp[i|(1<<k)][k] = (dp[i|(1<<k)][k] == -1 ? t : min(dp[i|(1<<k)][k],t));
        }
      }
    }
    int mx = 0;
    for (int i=0;i<(1<<M);i++)
      for (int j=0;j<M;j++)
        if (dp[i][j] != -1) {
          mx = max(mx,bitcount(i));
          break;
        }
    return mx;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4();}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"1 10 10" , "1 55 31", "10 50 100" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 2 10"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, maxStores(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; string Arr1[] = {"1 10 10" , "1 55 30", "10 50 100" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 2 10"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, maxStores(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; string Arr1[] = {"0 1000 17"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2 3 400", "4 1 500", "4 3 300", "1 0 700", "0 2 400"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, maxStores(Arg0, Arg1, Arg2)); }
// {28, {"12897 45253 5567", "32358 91385 33065", "16950 69822 47672"}, {"0 1 12643", "1 2 2357", "0 4 59434", "2 7 50359", "2 3 28579", "1 10 33977", "10 5 10462", "5 6 16747", "0 8 49198", "4 15 17704", "4 13 13312", "7 23 22798", "13 22 50343", "13 9 20092", "13 21 36378", "6 25 29976", "0 19 2910", "6 16 20911", "16 12 18283", "7 24 1351", "12 18 14119", "5 21 48237", "18 22 18289", "3 0 14409", "10 26 35188", "9 21 21013", "23 9 8414", "14 8 39207", "11 1 51543", "22 6 36024", "2 27 1240", "1 9 24302", "22 25 25281", "8 7 52570", "25 27 610", "2 23 37579", "22 3 24467", "18 10 19856", "16 21 19105", "3 17 39795", "20 18 53957", "0 6 21225", "19 23 21090", "23 15 19640"}}
void test_case_3() { int Arg0 = 28; string Arr1[] = {"12897 45253 5567", "32358 91385 33065", "16950 69822 47672"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0 1 12643", "1 2 2357", "0 4 59434", "2 7 50359", "2 3 28579", "1 10 33977", "10 5 10462", "5 6 16747", "0 8 49198", "4 15 17704", "4 13 13312", "7 23 22798", "13 22 50343", "13 9 20092", "13 21 36378", "6 25 29976", "0 19 2910", "6 16 20911", "16 12 18283", "7 24 1351", "12 18 14119", "5 21 48237", "18 22 18289", "3 0 14409", "10 26 35188", "9 21 21013", "23 9 8414", "14 8 39207", "11 1 51543", "22 6 36024", "2 27 1240", "1 9 24302", "22 25 25281", "8 7 52570", "25 27 610", "2 23 37579", "22 3 24467", "18 10 19856", "16 21 19105", "3 17 39795", "20 18 53957", "0 6 21225", "19 23 21090", "23 15 19640"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(3, Arg3, maxStores(Arg0, Arg1, Arg2)); }
// {4, {"140 141 1", "20 21 10", "10 40 20", "0 10 5"}, {"0 1 70", "1 2 10", "2 3 5"}}
void test_case_4() { int Arg0 = 4; string Arr1[] = {"140 141 1", "20 21 10", "10 40 20", "0 10 5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0 1 70", "1 2 10", "2 3 5"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(4, Arg3, maxStores(Arg0, Arg1, Arg2)); }
// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  TravellingPurchasingMan ___test;
  ___test.run_test(-1);
}
// END CUT HERE
