#include <string>
#include <iostream>
#include <iomanip>
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
#include <tuple>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef tuple<string,int> State;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE
map<State,int> mem;

class PalindromeFactory {
 public:
  bool isPalindrome(const string& s) {
    for (int i=0;i<s.size()/2;i++)
      if (s[i] != s[s.size()-i-1])
        return false;
    return true;
  }
  int rec(string& s,int opsleft) {
    State p(s,opsleft);
    if (mem.count(p)) return mem[p];
    if (isPalindrome(s)) return mem[p] = 0;
    if (!opsleft) return mem[p] = (isPalindrome(s) ? 0 : 100000);
    int t = INT_MAX;
    

    
    t = 0;
    for (int i=0;i<s.size()/2;i++)
      if (s[i] != s[s.size()-i-1])
        t++;
    
    for (int i=0;i<s.size();i++) {
      string s2 = s.substr(0,i)+s.substr(i+1);
      t = min(t,1+rec(s2,opsleft-1));
    }
    /*
    for (int i=0;i<s.size()/2;i++) {
      char c = s[i];
      s[i] = s[s.size()-i-1];
      t = min(t,1+rec(s,opsleft-1));
      s[i] = c;
    }
    */
    return mem[p] = t;
  }
  int getEditDistance(string initial) {
    mem.clear();
    int r = rec(initial,initial.size()/2);
    mem.clear();
    /*
    for (int k=0;k<initial.size();k++) {
      mem.clear();
      string s2 = initial.substr(0,k)+initial.substr(k+1);
      r = min(r,1+rec(s2,s2.size()/2));
    }
    */
    for (int i=0;i<initial.size();i++)
      for (int j=0;j<initial.size();j++) {
        if (i == j) continue;
        mem.clear();
        swap(initial[i],initial[j]);
        r = min(r,1+rec(initial,initial.size()/2));
        /*
        for (int k=0;k<initial.size();k++) {
          mem.clear();
          string s2 = initial.substr(0,k)+initial.substr(k+1);
          r = min(r,2+rec(s2,s2.size()/2));
        }
        */
        swap(initial[i],initial[j]);
      }
    return r;
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
		cout << "Testing PalindromeFactory (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395069774;
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
		PalindromeFactory _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string initial = "abba";
				_expected = 0;
				_received = _obj.getEditDistance(initial); break;
			}
			case 1:
			{
				string initial = "dabba";
				_expected = 1;
				_received = _obj.getEditDistance(initial); break;
			}
			case 2:
			{
				string initial = "babacvabba";
				_expected = 2;
				_received = _obj.getEditDistance(initial); break;
			}
			case 3:
			{
				string initial = "abc";
				_expected = 1;
				_received = _obj.getEditDistance(initial); break;
			}
			case 4:
			{
				string initial = "acxcba";
				_expected = 1;
				_received = _obj.getEditDistance(initial); break;
			}
			case 5:
			{
				string initial = "abcacbd";
				_expected = 1;
				_received = _obj.getEditDistance(initial); break;
			}
			case 6:
			{
				string initial = "jicaejceicfhhejaebab";
				_expected = 7;
				_received = _obj.getEditDistance(initial); break;
			}
			case 7:
			{
				string initial = "aaacaacbcabaaaabbabacacabbabacaacabbabcbabbaaacbaa";
				_expected = 8;
				_received = _obj.getEditDistance(initial); break;
			}
			/*case 8:
			{
				string initial = ;
				_expected = ;
				_received = _obj.getEditDistance(initial); break;
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
