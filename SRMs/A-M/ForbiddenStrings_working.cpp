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
long long mem[31][3][3];

class ForbiddenStrings {
 public:
  int N;
  long long rec(int n, int prev, int prevprev) {
    if (n == 0) return 1;
    LL& r = mem[n][prev][prevprev];
    if (r != -1) return r;
    long long t = 0;
    if (prev != prevprev && n+1 != N) {
      t += rec(n-1,prev,prev);
      t += rec(n-1,prevprev,prev);
    } else {
      t += rec(n-1,0,prev);
      t += rec(n-1,1,prev);
      t += rec(n-1,2,prev);
    }
    return r = t;
  }
  long long countNotForbidden(int n) {
    N = n;
    memset(mem,-1,sizeof(mem));
    long long r = rec(n,0,0);
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
		cout << "Testing ForbiddenStrings (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390226676;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ForbiddenStrings _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				_expected = 9LL;
				_received = _obj.countNotForbidden(n); break;
			}
			case 1:
			{
				int n = 3;
				_expected = 21LL;
				_received = _obj.countNotForbidden(n); break;
			}
			case 2:
			{
				int n = 4;
				_expected = 51LL;
				_received = _obj.countNotForbidden(n); break;
			}
			/*case 3:
			{
				int n = ;
				_expected = LL;
				_received = _obj.countNotForbidden(n); break;
			}*/
			/*case 4:
			{
				int n = ;
				_expected = LL;
				_received = _obj.countNotForbidden(n); break;
			}*/
			/*case 5:
			{
				int n = ;
				_expected = LL;
				_received = _obj.countNotForbidden(n); break;
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
