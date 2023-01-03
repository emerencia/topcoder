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

class ShorterSuperSum {
 public:
  int calculate(int k, int n) {
    if (k == 0) return n;
    int r = 0;
    for (int i=1;i<=n;i++)
      r+= calculate(k-1,i);
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
		cout << "Testing ShorterSuperSum (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1407178801;
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
		ShorterSuperSum _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int k = 1;
				int n = 3;
				_expected = 6;
				_received = _obj.calculate(k, n); break;
			}
			case 1:
			{
				int k = 2;
				int n = 3;
				_expected = 10;
				_received = _obj.calculate(k, n); break;
			}
			case 2:
			{
				int k = 4;
				int n = 10;
				_expected = 2002;
				_received = _obj.calculate(k, n); break;
			}
			case 3:
			{
				int k = 10;
				int n = 10;
				_expected = 167960;
				_received = _obj.calculate(k, n); break;
			}
			case 4:
			{
				int k = 14;
				int n = 14;
				_expected = 37442160;
				_received = _obj.calculate(k, n); break;
			}
			/*case 5:
			{
				int k = ;
				int n = ;
				_expected = ;
				_received = _obj.calculate(k, n); break;
			}*/
			/*case 6:
			{
				int k = ;
				int n = ;
				_expected = ;
				_received = _obj.calculate(k, n); break;
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
