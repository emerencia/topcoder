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
// start read 21:43
// start imp 21:51
// end at 22:37
// END CUT HERE

bool isnice[2501][2501];
int pairsafter[2501][2501];

class LittleElephantAndRGB {
 public:
  string S;
  int greenafterstart(int start, int end) {
    int c = 0;
    for (int i=start;i<=start;i++) {
      if (S[i] != 'G')
        return c;
      c++;
    }
    return c;
  }
  int greenbeforeend(int start, int end) {
    int c = 0;
    for (int i=end;i>=start;i--) {
      if (S[i] != 'G')
        return c;
      c++;
    }
    return c;
  }
  long long getNumber(vector <string> list, int minGreen) {
    S = accumulate(list.begin(),list.end(),string(""));
    int N = S.size(); // 2500 max
    memset(isnice,0,sizeof(isnice));
    for (int i=0;i<N;i++) {
      bool iznice = false;
      int nrgreen = (S[i] == 'G');
      if (nrgreen == minGreen)
        iznice = true;
      for (int j=i;j<N;j++) {
        if (S[j] == 'G') {
          nrgreen++;
          if (nrgreen == minGreen)
            iznice = true;
        } else {
          nrgreen = 0;
        }
        isnice[i][j] = iznice;
      }
    }
    long long r = 0;
    for (int a = 0;a<N;a++)
      for (int b = a;b<N;b++)
        if (isnice[a][b]) {
          int start = b+1;
          int end = N-1;
          r+= ((end-start+1)*(end-start+2))/2;
        }
    /*
    for (int b = N-1;b>=0;b--)
      for (int a = b;a>=0;a--)
        if (isnice[a][b]) {
          int start = 0;
          int end = a-1;
          r+= ((end-start+1)*(end-start+2))/2;
        }
    */
    memset(pairsafter,0,sizeof(pairsafter));
    for (int i=0;i<N;i++) {
      for (int mg=1;mg<minGreen;mg++) {
        if (S[i+mg-1] == 'G') {
          for (int j=1;j<=mg;j++)
            pairsafter[i][j]+=N-i-mg+1;
        } else break;
      }
    }
    // go 
    for (int i=0;i<N;i++) {
      bool iznice = false;
      int nrgreen = (S[i] == 'G');
      if (nrgreen == minGreen)
        iznice = true;
      for (int j=i;j<N;j++) {
        if (S[j] == 'G') {
          nrgreen++;
          if (nrgreen == minGreen)
            iznice = true;
        } else {
          nrgreen = 0;
        }
        if (!iznice && nrgreen && nrgreen < minGreen) {
          r+= pairsafter[j+1][minGreen-nrgreen];
        }
      }
    }
    return r;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"GRG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; long long Arg2 = 1LL; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"GG", "GG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long long Arg2 = 9LL; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"GRBGRBBRG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; long long Arg2 = 11LL; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"RRBRBBRRR", "R", "B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; long long Arg2 = 0LL; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"GRGGGRBRGG", "GGGGGGGG", "BRGRBRB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; long long Arg2 = 12430LL; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  LittleElephantAndRGB ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
