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

class SoldierLabeling {
 public:
  int count(int n, int lowerBound, int upperBound) {
    if (lowerBound > n) return 0;
    int mn = 1;
    for (int i=1;i<lowerBound;i++)
      mn*=10;
    int mx = 9;
    for (int i=1;i<upperBound;i++)
      mx = mx*10+9;
    mx = min(n,mx);
    return max(0,mx-(mn-1));
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
	char* b[2];
	if(tt!=-1){b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing SoldierLabeling (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396297702;
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
		SoldierLabeling _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 100;
				int lowerBound = 2;
				int upperBound = 2;
				_expected = 90;
				_received = _obj.count(n, lowerBound, upperBound); break;
			}
			case 1:
			{
				int n = 31;
				int lowerBound = 2;
				int upperBound = 3;
				_expected = 22;
				_received = _obj.count(n, lowerBound, upperBound); break;
			}
			case 2:
			{
				int n = 1;
				int lowerBound = 2;
				int upperBound = 8;
				_expected = 0;
				_received = _obj.count(n, lowerBound, upperBound); break;
			}
			case 3:
			{
				int n = 10000000;
				int lowerBound = 8;
				int upperBound = 8;
				_expected = 1;
				_received = _obj.count(n, lowerBound, upperBound); break;
			}
			case 4:
			{
				int n = 2718317;
				int lowerBound = 3;
				int upperBound = 7;
				_expected = 2718218;
				_received = _obj.count(n, lowerBound, upperBound); break;
			}
			case 5:
			{
				int n = 59;
				int lowerBound = 3;
				int upperBound = 3;
				_expected = 0;
				_received = _obj.count(n, lowerBound, upperBound); break;
			}
			/*case 6:
			{
				int n = ;
				int lowerBound = ;
				int upperBound = ;
				_expected = ;
				_received = _obj.count(n, lowerBound, upperBound); break;
			}*/
			/*case 7:
			{
				int n = ;
				int lowerBound = ;
				int upperBound = ;
				_expected = ;
				_received = _obj.count(n, lowerBound, upperBound); break;
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
