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
const int kOff = 100000;

class ConvexPolygonGame {
 public:
  string winner(vector <int> X, vector <int> Y) {
    vector<PII> validpoints;
    vector<int> minn(200001,-1);
    vector<int> maxx(200001,-1);
    for (int i=0;i<X.size();i++) {
      int x1 = X[i];
      int y1 = Y[i];
      int x2 = X[(i+1)%X.size()];
      int y2 = Y[(i+1)%X.size()];
      if (x1 == x2) {
        if (max(y1,y2)-min(y1,y2) > 1) {
          if (minn[x1+kOff] == -1)
            minn[x1+kOff] = min(y1,y2)+1+kOff;
          else
            minn[x1+kOff] = min(minn[x1+kOff],min(y1,y2)+1+kOff);
          maxx[x1+kOff] = max(maxx[x1+kOff],max(y1,y2)-1+kOff);
        }
      } else if (x1 < x2) {
        // we are at bottom
        minn[x1+kOff] = y1+1+kOff;
        minn[x2+kOff] = y2+1+kOff;
        for (int x=x1+1;x<x2;x++) {
          if (minn[x+kOff] == -1)
            minn[x+kOff] = y1+kOff+(int)ceil((((LL)x-x1)*(y2-y1))/double(x2-x1));
          else 
            minn[x+kOff] = min((LL)minn[x+kOff],y1+kOff+(LL)ceil((((LL)x-x1)*(y2-y1))/double(x2-x1)));
        }
      } else {
        // we are at top
        maxx[x1+kOff] = max(maxx[x1+kOff],y1-1+kOff);
        maxx[x2+kOff] = max(maxx[x2+kOff],y2-1+kOff);
        if (y2 <= y1) {
          for (int x=x2+1;x<x1;x++)
            maxx[x+kOff] = max((LL)maxx[x+kOff],y2+kOff+(LL)floor((((LL)x-x2)*(y1-y2))/double(x1-x2)));
        } else {
          for (int x=x2+1;x<x1;x++)
            maxx[x+kOff] = max((LL)maxx[x+kOff],y2+kOff+(LL)floor((((LL)x-x2)*(y1-y2))/double(x1-x2)));
        }
      }
    }
    for (int i=0;i<minn.size();i++) {
      /*
      if (i > kOff+99990 && (minn[i] != -1 || maxx[i] != -1)) {
        cout << i-kOff << ", minn: ";
        if (minn[i] == -1) cout << "?";
        else cout << minn[i]-kOff;
        cout << ", maxx: ";
        if (maxx[i] == -1) cout << "?";
        else cout << maxx[i]-kOff;
        cout << endl;
      }
      */
      if (minn[i] == -1 || maxx[i] == -1) continue;
      if (minn[i] > maxx[i]) continue;
      for (int j=minn[i];j<=maxx[i];j++)
        validpoints.push_back(PII(i-kOff,j-kOff));
      if (validpoints.size() > 200001) return "Masha";
    }
   //cout << validpoints.size() << endl;
    if (validpoints.size() < 3) return "Petya";
    PII p = validpoints[0];
    PII q = validpoints[1];
    for (int i=2;i<validpoints.size();i++) {
      PII r = validpoints[i];
      int area = abs(((LL)q.first-p.first)*(r.second-p.second) -
                 (q.second-p.second)*(r.first-p.first));
      if (!area) continue;
      return "Masha";
    }
    return "Petya";
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Petya"; verify_case(0, Arg2, winner(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 4, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Masha"; verify_case(1, Arg2, winner(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 100, 100, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 100, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Masha"; verify_case(2, Arg2, winner(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 50, 100, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, -1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Petya"; verify_case(3, Arg2, winner(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-100000, 100000, 100000, -100000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, -1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Masha"; verify_case(4, Arg2, winner(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {-100000, 0, 100000, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-100000, -1, 100000, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Petya"; verify_case(5, Arg2, winner(Arg0, Arg1)); }
void test_case_6() { int Arr0[] = {-500, -499, -399, -300, -202, -105, -9, 86}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-500, -500,  -499, -498, -497, -496, -495, -494}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Masha"; verify_case(6, Arg2, winner(Arg0, Arg1)); }
void test_case_7() { int Arr0[] = {-100000, 100000, 99997}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100000, -99998, -99995}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Masha"; verify_case(7, Arg2, winner(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ConvexPolygonGame ___test;
  ___test.run_test(toTest);
}
// END CUT HERE

