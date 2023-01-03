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
#include <cstring>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
// 21:32--22:07

class IDNumberVerification {
 public:
  bool checkregion(string region,const vector<string>& regionCodes) {
    for (int i=0;i<regionCodes.size();i++)
      if (regionCodes[i] == region)
        return true;
    return false;
  }
  bool isleapyear(int year) {
    if (year%4 == 0 && year%100) return true;
    if (year%400 == 0) return true;
    return false;
  }
  bool checkbirthday(string birthday) {
    string year = birthday.substr(0,4);
    string month = birthday.substr(4,2);
    string day = birthday.substr(6,2);
    int y,m,d;
    stringstream a(year);
    a >> y;
    stringstream b(month);
    b >> m;
    stringstream c(day);
    c >> d;
    if (y < 1900 || y > 2011) return false;
    if (m < 1 || m > 12) return false;
    vector<vector<int> > monthmaxdays(2,vector<int>(13,0));
    for (int leapyear=0;leapyear<2;leapyear++)
      for (int mon=1;mon<13;mon++) {
        if (mon < 8) monthmaxdays[leapyear][mon] = 30+(mon%2);
        if (mon >= 8) monthmaxdays[leapyear][mon] = 30+(1-(mon%2));
        if (mon == 2) monthmaxdays[leapyear][mon] = 28+leapyear;
      }
    int mmdays = monthmaxdays[isleapyear(y)][m];
    if (d < 1 || d > mmdays) return false;
    return true;
  }
  bool checksequential(string seq) {
    return (seq != "000");
  }
  string getsex(string seq) {
    stringstream s(seq);
    int sq;
    s >> sq;
    if (sq%2) return "Male";
    return "Female";
  }
  char getelevencode(string id) {
    long long code = 0;
    for (int i=0;i<id.size();i++)
      code += LL(id[i]-'0')*(1LL<<(17LL-i));
    int x = (12-(code%11))%11;
    return (x == 10 ? 'X' : '0'+x);
  }
  string verify(string id, vector <string> regionCodes) {
    if (checkregion(id.substr(0,6),regionCodes) &&
        checkbirthday(id.substr(6,8)) &&
        checksequential(id.substr(14,3))) {
      string sex = getsex(id.substr(14,3));
      char c = getelevencode(id.substr(0,17));
      if (id[17] == c) return sex;
    }
    return "Invalid";
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "441323200312060636"; string Arr1[] = {"441323"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Male"; verify_case(0, Arg2, verify(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "62012319240507058X"; string Arr1[] = {"620123"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Female"; verify_case(1, Arg2, verify(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "321669197204300886"; string Arr1[] = {"610111","659004"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Invalid"; verify_case(2, Arg2, verify(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "230231198306900162"; string Arr1[] = {"230231"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Invalid"; verify_case(3, Arg2, verify(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "341400198407260005"; string Arr1[] = {"341400"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Invalid"; verify_case(4, Arg2, verify(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "520381193206090891"; string Arr1[] = {"532922","520381"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Invalid"; verify_case(5, Arg2, verify(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  IDNumberVerification ___test;
  ___test.run_test(-1);
}
// END CUT HERE
