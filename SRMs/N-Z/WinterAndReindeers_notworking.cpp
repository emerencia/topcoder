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
typedef long long LL;
typedef pair<int,int> PII;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE
int mem[51][51];

class WinterAndReindeers {
 public:
  string as;
  string bs;
  int rec(int ai, int bi) {
    int& r = mem[ai][bi];
    if (r != -1) return r;
    if (ai == as.size() || bi == bs.size())
      return r = 0;
    if (as[ai] == bs[bi])
      return r = 1+rec(ai+1,bi+1);
    return r=max(rec(ai+1,bi),rec(ai,bi+1));
  }
  int lcs(const string& A, const string& B, const string& s) {
    int si = s.size()-1;
    int ai = A.size()-1;
    for (int i=A.size()-1;i>=0;i--)
      if (s[si] == A[i]) {
        si--;
        if (si == -1) {
          ai = i;
          break;
        }
      }
    // has to be less than i
    si = s.size()-1;
    int bi = B.size()-1;
    for (int i=B.size()-1;i>=0;i--)
      if (s[si] == B[i]) {
        si--;
        if (si == -1) {
          bi = i;
          break;
        }
      }
    int r = s.size();
    if (bi > 0 && ai > 0) {
      memset(mem,-1,sizeof(mem));
      as = A.substr(0,ai);
      bs = B.substr(0,bi);
      r+=rec(0,0);
    }
    // now other way around
    si = 0;
    ai = 0;
    for (int i=0;i<A.size();i++)
      if (s[si] == A[i]) {
        si++;
        if (si == s.size()) {
          ai = i+1;
          break;
        }
      }
    si = 0;
    bi = 0;
    for (int i=0;i<B.size();i++)
      if (s[si] == B[i]) {
        si++;
        if (si == s.size()) {
          bi = i+1;
          break;
        }
      }
    if (ai < A.size() && bi < B.size()) {
      memset(mem,-1,sizeof(mem));
      as = A.substr(ai);
      bs = B.substr(bi);
      r+=rec(0,0);
    }
    return r;
  }
  bool issubseq(const string& S, const string& s) {
    int si = 0;
    for (int i=0;i<S.size();i++)
      if (s[si] == S[i]) {
        si++;
        if (si == s.size()) return true;
      }
    return false;
  }
  int getNumber(vector <string> allA, vector <string> allB, vector <string> allC) {
    string A = accumulate(allA.begin(),allA.end(),string(""));
    string B = accumulate(allB.begin(),allB.end(),string(""));
    string C = accumulate(allC.begin(),allC.end(),string(""));
    int mxl = 0;
    for (int i=0;i<C.size();i++)
      for (int j=i+1;j<=C.size();j++) {
        string s = C.substr(i,j-i);
        if (issubseq(A,s) && issubseq(B,s))
          mxl = max(mxl,lcs(A,B,s));
      }
    return mxl;
  }
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if(tt!=-1){char* b[2];b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}	if (argc == 1) 
	{
		cout << "Testing WinterAndReindeers (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391206141;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		WinterAndReindeers _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string allA[] = {"X"};
				string allB[] = {"X", "Y"};
				string allC[] = {"X"};
				_expected = 1;
				_received = _obj.getNumber(vector <string>(allA, allA+sizeof(allA)/sizeof(string)), vector <string>(allB, allB+sizeof(allB)/sizeof(string)), vector <string>(allC, allC+sizeof(allC)/sizeof(string))); break;
			}
			case 1:
			{
				string allA[] = {"ABCXD"};
				string allB[] = {"BCDEF"};
				string allC[] = {"CD"};
				_expected = 3;
				_received = _obj.getNumber(vector <string>(allA, allA+sizeof(allA)/sizeof(string)), vector <string>(allB, allB+sizeof(allB)/sizeof(string)), vector <string>(allC, allC+sizeof(allC)/sizeof(string))); break;
			}
			case 2:
			{
				string allA[] = {"WE", "LOVE"};
				string allB[] = {"WORKING", "FOR", "SANTA"};
				string allC[] = {"JK"};
				_expected = 0;
				_received = _obj.getNumber(vector <string>(allA, allA+sizeof(allA)/sizeof(string)), vector <string>(allB, allB+sizeof(allB)/sizeof(string)), vector <string>(allC, allC+sizeof(allC)/sizeof(string))); break;
			}
			case 3:
			{
				string allA[] = {"ABCDE"};
				string allB[] = {"CDEAB"};
				string allC[] = {"B"};
				_expected = 2;
				_received = _obj.getNumber(vector <string>(allA, allA+sizeof(allA)/sizeof(string)), vector <string>(allB, allB+sizeof(allB)/sizeof(string)), vector <string>(allC, allC+sizeof(allC)/sizeof(string))); break;
			}
			case 4:
			{
				string allA[] = {"ABCABDEGAXAHDJBAAHFJDXBB", "ABHFHCDALFDJDBBA", "BABBAXAXXX"};
				string allB[] = {"ABLOCBAXBAHAJDXBIJKA", "JBABCDAHKFIUDALPJAH", "AABACX"};
				string allC[] = {"AXBADXBBAB", "CDD"};
				_expected = 23;
				_received = _obj.getNumber(vector <string>(allA, allA+sizeof(allA)/sizeof(string)), vector <string>(allB, allB+sizeof(allB)/sizeof(string)), vector <string>(allC, allC+sizeof(allC)/sizeof(string))); break;
			}
			/*case 5:
			{
				string allA[] = ;
				string allB[] = ;
				string allC[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <string>(allA, allA+sizeof(allA)/sizeof(string)), vector <string>(allB, allB+sizeof(allB)/sizeof(string)), vector <string>(allC, allC+sizeof(allC)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string allA[] = ;
				string allB[] = ;
				string allC[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <string>(allA, allA+sizeof(allA)/sizeof(string)), vector <string>(allB, allB+sizeof(allB)/sizeof(string)), vector <string>(allC, allC+sizeof(allC)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string allA[] = ;
				string allB[] = ;
				string allC[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <string>(allA, allA+sizeof(allA)/sizeof(string)), vector <string>(allB, allB+sizeof(allB)/sizeof(string)), vector <string>(allC, allC+sizeof(allC)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
