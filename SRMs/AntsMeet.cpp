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
using namespace std;

class AntsMeet {
  struct AntCollision {
    int a;
    int b;
    int d;
    AntCollision(int a,int b,int d) : a(a),b(b),d(d) {}
    bool operator<(const AntCollision& p) const {
      return d < p.d;
    }
  };
 public:
   int collide(char a, char b,int x0, int x1,int y0, int y1) {
     if (a == 'N' && b == 'S') {
       if (x0 == x1 && y0 < y1) return (y1-y0);
     } else if (a == 'S' && b == 'N') {
       if (x0 == x1 && y1 < y0) return (y0-y1);
     } else if (a == 'E' && b == 'W') {
       if (y0 == y1 && x0 < x1) return (x1-x0);
     } else if (a == 'W' && b == 'E') {
       if (y0 == y1 && x0 > x1) return (x0-x1);
     } else if (a == 'N' && b == 'E') {
       if (y0 < y1 && x0 > x1 && y1 - y0 == x0 - x1) return 2*(y1-y0);
     } else if (a == 'E' && b == 'N') {
       if (y1 < y0 && x1 > x0 && y0 - y1 == x1 - x0) return 2*(x1-x0);
     } else if (a == 'N' && b == 'W') {
       if (y0 < y1 && x0 < x1 && y1 - y0 == x1 - x0) return 2*(y1-y0);
     } else if (a == 'W' && b == 'N') {
       if (y1 < y0 && x1 < x0 && y0 - y1 == x0 - x1) return 2*(x0-x1);
     } else if (a == 'S' && b == 'E') {
       if (y0 > y1 && x0 > x1 && y0 - y1 == x0 - x1) return 2*(y0-y1);
     } else if (a == 'E' && b == 'S') {
       if (y1 > y0 && x1 > x0 && y1 - y0 == x1 - x0) return 2*(x1-x0);
     } else if (a == 'S' && b == 'W') {
       if (y0 > y1 && x0 < x1 && y0 - y1 == x1 - x0) return 2*(y0-y1);
     } else if (a == 'W' && b == 'S') {
       if (y1 > y0 && x1 < x0 && y1 - y0 == x0 - x1) return 2*(x0-x1);
     }
     return -1;
   }
  int countAnts(vector <int> x, vector <int> y, string direction) {
    int n = x.size();
    vector<AntCollision> s;
    for (int i=0;i<n;i++) {
      char da = direction[i];
      for (int j=i+1;j<n;j++) {
        char db = direction[j];
        int col = collide(da,db,x[i],x[j],y[i],y[j]);
        if (col != -1) {
          s.push_back(AntCollision(i,j,col));
        }
      }
    }
    vector<bool> active(n,true);
    vector<int> deactivated(n,-1);
    sort(s.begin(),s.end());
    int r = n;
    for (int i=0;i<s.size();i++) {
      if ((active[s[i].a] || deactivated[s[i].a] == s[i].d) &&
          (active[s[i].b] || deactivated[s[i].b] == s[i].d)) {
        if (active[s[i].a]) r--;
        if (active[s[i].b]) r--;
        deactivated[s[i].a] = s[i].d;
        deactivated[s[i].b] = s[i].d;
        active[s[i].a] = false;
        active[s[i].b] = false;
      }
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,10,20,30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,10,20,30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NWNE"; int Arg3 = 2; verify_case(0, Arg3, countAnts(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {-10,0,0,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,-10,10,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NEWS"; int Arg3 = 0; verify_case(1, Arg3, countAnts(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {-1,-1,-1,0,0,0,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,0,1,-1,0,1,-1,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ESEWNNEWW"; int Arg3 = 4; verify_case(2, Arg3, countAnts(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {4,7,6,2,6,5,7,7,8,4,7,8,8,8,5,4,8,9,1,5,9,3,4,0,0,1,0,7,2,6,9,6,3,0,5,5,1,2,0,4,9,7,7,1,8,1,9,2,7,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,0,6,8,4,9,0,5,0,2,4,3,8,1,5,0,7,3,7,0,9,8,1,9,4,7,8,1,1,6,6,6,2,8,5,1,9,0,1,1,1,7,0,2,5,4,7,5,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "SSNWSWSENSWSESWEWSWSENWNNNESWSWSWWSSWEEWWNWWWNWENN" ; int Arg3 = 25; verify_case(3, Arg3, countAnts(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {478,-664,759,434,-405,513,565,-396,311,-174,56,993,251,-341,993,-112,242,129,383,513,-78,-341,-148,129,423
,493,434,-405,478,-148,929,251,56,242,929,-78,423,-664,802,251,759,383,-112,-591,-591,-248,660,660,735,493}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-186,98,948,795,289,-678,948,-170,-195,290,-354,-424,289,-157,-166,150,706,-678,684,-294,-234,36,36,-294,-216
,-234,427,945,265,-157,265,715,275,715,-186,337,798,-170,427,706,754,961,286,-216,798,286,961,684,-424,337}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "WNSNNSSWWWEENWESNSWSWSEWWEWEWWWNWESNSSNNSNNWWWNESE"; int Arg3 = 44; verify_case(4, Arg3, countAnts(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  AntsMeet ___test;
  ___test.run_test(-1);
}
// END CUT HERE
