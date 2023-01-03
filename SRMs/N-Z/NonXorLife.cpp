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

const int kMx  = 3100;
const int kOff = 1500;

typedef pair<int,int> pi;

const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};

class NonXorLife {
 public:
  int countAliveCells(vector <string> field, int K) {
    vector<vector<int> > dist(kMx,vector<int>(kMx,1502));
    queue<pi> q;
    for (int i=0;i<field.size();i++) {
      for (int j=0;j<field[0].size();j++) {
        if (field[i][j] == 'o') {
          dist[i+kOff][j+kOff] = 0;
          q.push(pi(i+kOff,j+kOff));
        }
      }
    }
    while (!q.empty()) {
      pi a = q.front();
      q.pop();
      int d = 1+dist[a.first][a.second];
      if (d > K) continue;
      for (int i=0;i<4;i++) {
        int xx = a.first+dx[i];
        int yy = a.second+dy[i];
        if (xx >=0 && yy >= 0 && xx < dist.size() && yy < dist.size()) {
          if (d < dist[xx][yy]) {
            dist[xx][yy] = d;
            q.push(pi(xx,yy));
          }
        }
      }
    }
    int c = 0;
    for (int i=0;i<dist.size();i++) {
      for (int j=0;j<dist.size();j++) {
        if (dist[i][j] <= K) c++;
      }
    }
    return c;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"oo"
,"o."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 36; verify_case(0, Arg2, countAliveCells(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".."
,".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 23; int Arg2 = 0; verify_case(1, Arg2, countAliveCells(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"o"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 2002001; verify_case(2, Arg2, countAliveCells(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"o.oo.ooo"
,"o.o.o.oo"
,"ooo.oooo"
,"o.o..o.o"
,"o.o..o.o"
,"o..oooo."
,"..o.o.oo"
,"oo.ooo.o"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1234; int Arg2 = 3082590; verify_case(3, Arg2, countAliveCells(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  NonXorLife ___test;
  ___test.run_test(-1);
}
// END CUT HERE
