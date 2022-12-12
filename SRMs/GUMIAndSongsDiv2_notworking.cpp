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

class GUMIAndSongsDiv2 {
 public:
   int maxc;
   void rec(vector<int> duration, vector<int> tone,vector<vector<int> > dp, vector<bool> seen,int j,int mi, long long tt,int c) {
     tt-=dp[j][mi];
     j = mi;
     c++;
     seen[j] = true;
     if (c > maxc) maxc = c;
     if (tt == 0) { return; }
      int mn = 10000001;
      bool f = false;
      for (int k=0;k<dp[j].size();k++) {
        if (k == j) continue;
        if (!seen[k] && tt-dp[j][k] >= 0 && dp[j][k] < mn) {
          mn = dp[j][k];
          f = true;
        }
      }
      for (int k=0;k<dp[j].size();k++) {
        if (k == j) continue;
        if (!seen[k] && tt-dp[j][k] >= 0 && dp[j][k] == mn) {
          vector<bool> sseen = seen;
          sseen[k] = true;
          rec(duration,tone,dp,sseen,j,k,tt,c);
        }
      }
   }
  int maxSongs(vector <int> duration, vector <int> tone, int T) {
    maxc = 0;
    vector<vector<int> > dp(duration.size(),vector<int>(duration.size(),0));
    for (int i=0;i<dp.size();i++) {
      for (int j=0;j<dp[0].size();j++) {
        dp[i][j] = duration[j]+abs(tone[i]-tone[j]);
      }
    }
    vector<pair<int,int> > mp(duration.size());
    for (int i=0;i<duration.size();i++) {
      mp.push_back(pair<int,int>(duration[i],i));
    }
    sort(mp.begin(),mp.end());
    //for (int kk = 0;kk<duration.size();kk++) {
      int j = mp[0].second;
      long long tt = T;
      vector<bool> seen(duration.size(),false);
      int c = 0;
      //int j = mp[0].second;
      tt-=duration[j];
      if (tt >= 0) { 
        c++;
        if (c > maxc) { maxc = c; } 
      }
      for (int i=0;i<duration.size();i++) {
        seen[j] = true;
        if (tt == 0) { break; }
        int mn = 10000001;
        int mi = -1;
        bool f = false;
        for (int k=0;k<dp[j].size();k++) {
          if (k == j) continue;
          if (!seen[k] && tt-dp[j][k] >= 0 && dp[j][k] < mn) {
            mn = dp[j][k];
            mi = k;
            f = true;
          }
        }
        for (int k=0;k<dp[j].size();k++) {
          if (k == j) continue;
          if (!seen[k] && tt-dp[j][k] >= 0 && dp[j][k] == mn) {
            rec(duration,tone,dp,seen,j,k,tt,c);
          }
        }
        break;
      }
      //if (c > maxc) maxc = c;
    //}
    return maxc;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 5, 4, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 3, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 17; int Arg3 = 3; verify_case(0, Arg3, maxSongs(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {100, 200, 300}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; int Arg3 = 0; verify_case(1, Arg3, maxSongs(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = 4; verify_case(2, Arg3, maxSongs(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {10, 10, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {58, 58, 58}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 30; int Arg3 = 3; verify_case(3, Arg3, maxSongs(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {8, 11, 7, 15, 9, 16, 7, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 8, 5, 4, 2, 7, 4, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; int Arg3 = 1; verify_case(4, Arg3, maxSongs(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {5611,39996,20200,56574,81643,90131,33486,99568,48112,97168,5600,49145,73590,3979,94614}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2916,53353,64924,86481,44803,61254,99393,5993,40781,2174,67458,74263,69710,40044,80853}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 302606; int Arg3 = 8; verify_case(5, Arg3, maxSongs(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  GUMIAndSongsDiv2 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
