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
// 01:06 naive solution start
// 01:09 naive solution end
// 02:23 intelligent solution end
// END CUT HERE

class LittleElephantAndRGB {
 public:
  long long getNumber(vector <string> list, int minGreen) {
    string S = accumulate(list.begin(),list.end(),string(""));
    int N = S.size(); // 2500 max
    long long r = 0;
    // let's say we iterate over a point b, which defines the end of the left
    // range and is always included
    // now for every 0 <= a <= b, we can precalc whether a,b is a segment with
    // at least mingreen greens. if it is, then add all pairs c-d as valid
    // the number of pairs c-d is ((N-b-1)*(N-b))/2 - the number of pairs
    // > b that are good on their own
    // or rather: given an index B, how many substrings end in b that
    // contain at least mingreen elements. (this is at most b+1 strings)
    // we can calc that easy. just create an array isnice.. a..b to see
    // if a..b is nice.
    // then also add (b-a+1)*(b-a+2)/2 times the number of good pairs 
    // > b that are good on their own
    // finally, add all pairs from the left that end in x G chars that are
    // not good on their own to all pairs > b that start with >= mg G chars
    // that are not good on their own
    // question is: how to precalc that last stuff
    
    vector<vector<bool> > isnice(N,vector<bool>(N,false));
    for (int a=0;a<N;a++) {
      int nrgreen = 0;
      bool iznice = false;
      for (int b=a;b<N;b++) {
        if (S[b] == 'G') {
          nrgreen++;
          if (nrgreen == minGreen) {
            iznice = true;
          }
        } else nrgreen = 0;
        isnice[a][b] = iznice;
      }
    }
    vector<long long> validc(N,0); // number of pairs that start at c or higher that are valid
    for (int c=N-1;c>=0;c--) {
      if (c+1 != N) validc[c] = validc[c+1];
      validc[c] += accumulate(isnice[c].begin(),isnice[c].end(),0LL);
    }
    vector<long long> validconly(N,0); // number of pairs that start at c that are valid
    for (int c=N-1;c>=0;c--) {
      validconly[c] = accumulate(isnice[c].begin(),isnice[c].end(),0LL);
    }
    {
      vector<vector<bool> >().swap(isnice); // clear memory
    }
    vector<vector<long long> > dp(N,vector<long long>(N,0));
    // number of pairs that start at c that start with at least x 'G' chars
    for (int c=N-1;c>=0;c--)
      if (S[c] == 'G') {
        dp[c][1] = N-c;
        if (c+1 < N)
          for (int g=1;g+1<N;g++)
            dp[c][g+1] = dp[c+1][g];
      }
    for (int c=0;c<N;c++)
      for (int g=N-2;g>=1;g--)
        dp[c][g] += dp[c][g+1];
    for (int a=0;a<N;a++) {
      int nrgreen = 0;
      //bool iznice = false;
      for (int b=a;b+1<N;b++) {
        if (S[b] == 'G') {
          nrgreen++;
          nrgreen = min(nrgreen,minGreen);
          if (nrgreen == minGreen) {
            //iznice = true;
          }
        } else nrgreen = 0;
        //long long numberofpairsbcgoodontheirown = validc[b+1];
        //if (iznice) r+= ((N-b-1)*(N-b))/2 - numberofpairsbcgoodontheirown;
       // r+= numberofpairsbcgoodontheirown;
       // if (!iznice && nrgreen) {
          // add to r at least the number of pairs that start with
         // cout << a << " " << b << " " << nrgreen << endl;
          long long t = 0;
          for (int c=b+1;c<N;c++) {
            //cout << c << " " << minGreen-nrgreen << " .. " << dp[c][minGreen-nrgreen]  << " " << validconly[c] << endl;
           if (dp[c][minGreen-nrgreen] > validconly[c])
              t+= dp[c][minGreen-nrgreen] - validconly[c];
          }
          r+= t;
        //}
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
