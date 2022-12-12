#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <utility>
using namespace std;

string result = "";
int vowels[27];

class SimpleRotationDecoder {
 public:
  bool trypass(string s,int ii,int jj,int kk) {
    vector<int> a;
    a.push_back(ii);
    a.push_back(jj);
    a.push_back(kk);
    string r="";
    int j=0;
    int wl=0;
    int nvowel=0;
    for (int i=0;i<s.size();i++) {
      int rr;
      if (s[i] == ' ') rr = 0;
      else rr = s[i]-'a'+1;
      rr = (rr+27-a[j])%27;
      if (rr == 0) {
        // space
        if (i == 0 || i == s.size()-1) return false;
        if (wl < 2) return false;
        if (nvowel == 0) return false;
        r+=' ';
        nvowel = 0;
        wl = 0;
      } else {
        wl++;
        if (wl > 8) return false;
        if (vowels[rr]) nvowel++;
        r+='a'+rr-1;
      }
      j = (j+1)%3;
    }
    if (wl > 0) {
      if (wl < 2) return false;
      if (nvowel == 0) return false;
    }
    result = r;
    return true;
  }
  string decode(string cipherText) {
    // brute force
    for (int i=0;i<27;i++) {
      vowels[i]=0;
    }
    vowels['a'-'a'+1]=1;
    vowels['e'-'a'+1]=1;
    vowels['i'-'a'+1]=1;
    vowels['o'-'a'+1]=1;
    vowels['u'-'a'+1]=1;
    for (int i=1;i<27;i++) {
      for (int j=1;j<27;j++) {
        for (int k=1;k<27;k++) {
          if (trypass(cipherText,i,j,k)) return result;
        }
      }
    }
    return "wrong";
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "mmbtvrbhhtgohaktklqegnrmlelojotyeyeiudvtil ey ffg"; string Arg1 = "the quick brown fox jumps over the lazy dog again"; verify_case(0, Arg1, decode(Arg0)); }
	void test_case_1() { string Arg0 = "ntgntgntgntofwlfwlfwlnookookook"; string Arg1 = "he he he heh he he heh he he he"; verify_case(1, Arg1, decode(Arg0)); }
	void test_case_2() { string Arg0 = "f sgnzslhzquq ydyuinmqiwfyrtdvn"; string Arg1 = "abkbprnn usmlbqz mdpelkoa jofni"; verify_case(2, Arg1, decode(Arg0)); }
	void test_case_3() { string Arg0 = "shxnaaeqjlofhhsuurbhpdgt z"; string Arg1 = "naeiui jrghnca pnzxaxz avs"; verify_case(3, Arg1, decode(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  SimpleRotationDecoder ___test;
  ___test.run_test(-1);
}
// END CUT HERE
