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

class DengklekMakingChains {
 public:
   int mx;
   struct Chain {
     string a;
     int fx;
     int idx;
     Chain () : a(""),fx(-2),idx(-1) { }
     Chain (string a, int fx, int idx) : a(a),fx(fx),idx(idx) { }
     bool operator<(const Chain& c) const {
       return val() > c.val();
     }
     int val() const {
       if (fx == -1) { 
         int c =0;
         for (int i=0;i<a.size();i++) {
           if (a[i] == '.') break;
           c+= a[i]-'0';
         }
         return c;
       }
       int c = 0;
       for (int i=2;i>=0;i--) {
         if (a[i] == '.') break;
         c+=a[i]-'0';
       }
       return c;
     }
   };
   int isfix(string a) {
     if (a[0] != '.' && a[1] != '.' && a[2] != '.') return 0;
     if (a[0] == '.' && a[2] == '.') return -2;
     if (a[0] != '.' && a[2] != '.') {
       if (a[0] > a[2]) return -1;
       return 1;
     }
     if (a[0] != '.') return -1; // prefix
     return 1; // postfix
   }
  int maxBeauty(vector <string> chains) {
    mx = 0;
    for (int i=0;i<chains.size();i++) {
      for (int j =0;j<3;j++) {
        if (chains[i][j] != '.') {
          mx = max(mx,chains[i][j]-'0');
        }
      }
    }
    vector<Chain> prefix;
    vector<Chain> postfix;
    for (int i=0;i<chains.size();i++) {
      int fx = isfix(chains[i]);
      if (fx == 1 || fx == -1) {
        prefix.push_back(Chain(chains[i],-1,i));
        postfix.push_back(Chain(chains[i],1,i));
      }
    }
    sort(prefix.begin(),prefix.end());
    sort(postfix.begin(),postfix.end());
    int pre=0;
    int post=0;
    if (prefix.size() > 0) {
      pre = max(prefix[0].val(),postfix[0].val());
      if (prefix.size() > 1) {
        if (prefix[0].idx == postfix[0].idx) {
          if (postfix[0].val()+prefix[1].val() < prefix[0].val()+postfix[1].val()) {
            pre = prefix[0].val();
            post = postfix[1].val();
          } else {
            post = postfix[0].val();
            pre = prefix[1].val();
          }
        } else {
          pre = prefix[0].val();
          post = postfix[0].val();
        }
      }
    }
    int mm = 0;
    for (int i=0;i<chains.size();i++) {
      if (isfix(chains[i]) == 0) {
        for (int j=0;j<3;j++) mm += chains[i][j]-'0';
      }
    }
    return max(mx,mm+post+pre);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".15", "7..", "402", "..3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(0, Arg1, maxBeauty(Arg0)); }
	void test_case_1() { string Arr0[] = {"..1", "7..", "567", "24.", "8..", "234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; verify_case(1, Arg1, maxBeauty(Arg0)); }
	void test_case_2() { string Arr0[] = {"...", "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, maxBeauty(Arg0)); }
	void test_case_3() { string Arr0[] = {"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(3, Arg1, maxBeauty(Arg0)); }
	void test_case_4() { string Arr0[] = {"..1", "3..", "2..", ".7."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, maxBeauty(Arg0)); }
	void test_case_5() { string Arr0[] = {"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; verify_case(5, Arg1, maxBeauty(Arg0)); }
  void test_case_6() { string Arr0[] = {"..1", "9.8", "567", "24.", "8.6", ".42"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 34; verify_case(6, Arg1, maxBeauty(Arg0)); }
  void test_case_7() { string Arr0[] = {"40.", "540", "..0", ".5."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(7, Arg1, maxBeauty(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  DengklekMakingChains ___test;
  ___test.run_test(-1);
}
// END CUT HERE
