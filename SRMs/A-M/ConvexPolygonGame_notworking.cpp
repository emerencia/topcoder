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
const int toTest = 5;
// 
// END CUT HERE

class ConvexPolygonGame {
 public:
  string winner(vector <int> X, vector <int> Y) {
    for (int i=0;i<X.size();i++)
      for (int j=i+1;j<X.size();j++)
        for (int k=j+1;k<X.size();k++) {
          // line through i and j
          int x = X[j]-X[i];
          int y = Y[j]-Y[i];
          int area = abs(x*(Y[k]-Y[i]) - (X[k]-X[i])*y);
          //cout << area << endl;
          if (area == 0) continue;
          if (area == 1 || abs(x) == 1 || abs(y) == 1 ||
              abs(Y[k]-Y[i]) == 1 || abs(X[k]-X[i]) == 1) continue;
          double base1 = sqrt((LL)x*x + (LL)y*y);
          double base2 = sqrt((LL)(Y[k]-Y[i])*(Y[k]-Y[i]) + (LL)(X[k]-X[i])*(X[k]-X[i]));
          double height1 = double(area)/base1;
          double height2 = double(area)/base2;
          cout << "base1 " << base1 << ", base2 " << base2 << ", height1 " <<
              height1 << ", height2 " << height2 << ", area " << area << endl;
          if (height1 <= 1 || height2 <= 1) {
              continue;
          }
          
          
          // now the line has to be a multiple of 
          /*
          if (x == X[k] && y == Y[k]) {
            continue;
          }
          if (x<X[k] && y < Y[k] && X[k]%x == 0 && Y[k]%y == 0) {
            continue;
          }
          if (x>X[k] && y > Y[k] && x%X[k] == 0 && y%Y[k] == 0) {
            continue;
          }
          */
          return "Masha";
        }
    return "Petya";
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5();  }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Petya"; verify_case(0, Arg2, winner(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 4, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Masha"; verify_case(1, Arg2, winner(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 100, 100, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 100, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Masha"; verify_case(2, Arg2, winner(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 50, 100, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, -1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Petya"; verify_case(3, Arg2, winner(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-100000, 100000, 100000, -100000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, -1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Masha"; verify_case(4, Arg2, winner(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {-100000, 0, 100000, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-100000, -1, 100000, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Petya"; verify_case(5, Arg2, winner(Arg0, Arg1)); }
// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ConvexPolygonGame ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
