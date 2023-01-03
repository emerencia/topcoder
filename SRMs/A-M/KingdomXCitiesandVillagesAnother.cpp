#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <utility>
#include <climits>
#include <limits>
#include <cstring>
#include <numeric>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
// BEGIN CUT HERE
const int toTest = -1;
// 
// END CUT HERE

long long dist[102][102];

class KingdomXCitiesandVillagesAnother {
 public:
  double determineLength(vector <int> cityX, vector <int> cityY, vector <int> villageX, vector <int> villageY) {
    int nc = cityX.size();
    int nv = villageX.size();
    memset(dist,0,sizeof(dist));
    for (int i=0;i<nc+nv;i++) {
      int x1 = (i < nc ? cityX[i] : villageX[i-nc]);
      int y1 = (i < nc ? cityY[i] : villageY[i-nc]);
      for (int j=i+1;j<nc+nv;j++) {
        int x2 = (j < nc ? cityX[j] : villageX[j-nc]);
        int y2 = (j < nc ? cityY[j] : villageY[j-nc]);
        dist[i][j] = (LL)(x1-x2)*(x1-x2)+(LL)(y1-y2)*(y1-y2);
        if (dist[i][j] < 0) { cout << dist[i][j] << endl; return 0; }
        dist[j][i] = dist[i][j];
      }
    }
    vector<bool> isconnected(nc+nv,false);
    for (int i=0;i<nc;i++)
      isconnected[i] = true;
    vector<LL> mindisttobeconnected(nc+nv,LLONG_MAX);
    for (int i=nc;i<nc+nv;i++) {
      for (int j=0;j<nc;j++) {
        mindisttobeconnected[i] = min(mindisttobeconnected[i],
                                      dist[i][j]);
      }
    }
    double r = 0;
    for (int j=0;j<nv;j++) {
      int besti = -1;
      long long mindist = LLONG_MAX;
      for (int i = nc;i<nc+nv;i++) {
        if (isconnected[i]) continue;
        if (mindisttobeconnected[i] < mindist) {
          mindist = mindisttobeconnected[i];
          besti = i;
        }
      }
      r+=sqrt(mindist);
      isconnected[besti] = true;
      for (int i=nc;i<nc+nv;i++) {
        if (isconnected[i]) continue;
        mindisttobeconnected[i] = min(mindisttobeconnected[i],dist[i][besti]);
      }
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (abs(Expected-Received) < 1e-9) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << fixed << setprecision(9) << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 2.0; verify_case(0, Arg4, determineLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 2.0; verify_case(1, Arg4, determineLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 2.8284271247461903; verify_case(2, Arg4, determineLength(Arg0, Arg1, Arg2, Arg3)); }
  //{, {}, {}, {}}
	void test_case_3() { int Arr0[] = {358205}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {466801}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {367279}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {354690}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 112477.61464842682; verify_case(3, Arg4, determineLength(Arg0, Arg1, Arg2, Arg3)); }
// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  KingdomXCitiesandVillagesAnother ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
