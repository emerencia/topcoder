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
int mem[11][27][1<<10];

class TheLuckyString {
 public:
  string s;
  int rec(int idx, int prev, int used) {
    int& r = mem[idx][prev][used];
    if (r != -1) return r;
    if (idx == s.size()) return r = 1;
    int t = 0;
    set<int> usedhere;
    for (int i=0;i<s.size();i++) {
      if (s[i]-'a' == prev || (used&(1<<i)) || usedhere.count(s[i]-'a')) continue;
      usedhere.insert(s[i]-'a');
      t+=rec(idx+1,s[i]-'a',used|(1<<i));
    }
    return r = t;
  }
  int count(string s) {
    this->s = s;
    memset(mem,-1,sizeof(mem));
    return rec(0,26,0);
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
		cout << "Testing TheLuckyString (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393348367;
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
		TheLuckyString _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "ab";
				_expected = 2;
				_received = _obj.count(s); break;
			}
			case 1:
			{
				string s = "aaab";
				_expected = 0;
				_received = _obj.count(s); break;
			}
			case 2:
			{
				string s = "aabbbaa";
				_expected = 1;
				_received = _obj.count(s); break;
			}
			case 3:
			{
				string s = "abcdefghij";
				_expected = 3628800;
				_received = _obj.count(s); break;
			}
			/*case 4:
			{
				string s = ;
				_expected = ;
				_received = _obj.count(s); break;
			}*/
			/*case 5:
			{
				string s = ;
				_expected = ;
				_received = _obj.count(s); break;
			}*/
			/*case 6:
			{
				string s = ;
				_expected = ;
				_received = _obj.count(s); break;
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
