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
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE
int mem2[5001][5001];

class PalindromicSubstringsDiv2 {
 public:
  string s;
  map<PII,int> mem;
  bool ispalindrome(int l, int rr) {
    int& r = mem2[l][rr];
    if (r != -1) return r;
    if (l == rr) return (r = true);
    if (s[l] != s[rr]) return (r = false);
    if (l+1 <= rr-1) return (r = ispalindrome(l+1,rr-1));
    return (r = true);
  }
  int count(vector <string> S1, vector <string> S2) {
    memset(mem2,-1,sizeof(mem2));
    this->s = accumulate(S1.begin(), S1.end(), string("")) +
        accumulate(S2.begin(), S2.end(), string(""));
    int r = 0;
    for (int i=0;i<s.size();i++)
      for (int j=i;j<s.size();j++)
        r+= ispalindrome(i,j);
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
	string a = tt == -1 ? "0" : string(1,'0'+tt);
	char* b[2] = {argv[0],(char*)a.c_str()};
	if(tt!=-1){argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing PalindromicSubstringsDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1411058580;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PalindromicSubstringsDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S1[] = {"a","a",""};
				string S2[] = {"a"};
				_expected = 6;
				_received = _obj.count(vector <string>(S1, S1+sizeof(S1)/sizeof(string)), vector <string>(S2, S2+sizeof(S2)/sizeof(string))); break;
			}
			case 1:
			{
				string S1[] = {"zaz"};
				string S2[] = {};
				_expected = 4;
				_received = _obj.count(vector <string>(S1, S1+sizeof(S1)/sizeof(string)), vector <string>(S2, S2+sizeof(S2)/sizeof(string))); break;
			}
			case 2:
			{
				string S1[] = {"top"};
				string S2[] = {"coder"};
				_expected = 8;
				_received = _obj.count(vector <string>(S1, S1+sizeof(S1)/sizeof(string)), vector <string>(S2, S2+sizeof(S2)/sizeof(string))); break;
			}
			case 3:
			{
				string S1[] = {};
				string S2[] = {"daata"};
				_expected = 7;
				_received = _obj.count(vector <string>(S1, S1+sizeof(S1)/sizeof(string)), vector <string>(S2, S2+sizeof(S2)/sizeof(string))); break;
			}
			/*case 4:
			{
				string S1[] = ;
				string S2[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(S1, S1+sizeof(S1)/sizeof(string)), vector <string>(S2, S2+sizeof(S2)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string S1[] = ;
				string S2[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(S1, S1+sizeof(S1)/sizeof(string)), vector <string>(S2, S2+sizeof(S2)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string S1[] = ;
				string S2[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(S1, S1+sizeof(S1)/sizeof(string)), vector <string>(S2, S2+sizeof(S2)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(3);
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
