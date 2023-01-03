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

class DesignCalendar {
 public:
  int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b,a%b);
  }
  int shortestPeriod(int dayLength, int yearLength) {
    return dayLength/gcd(dayLength,yearLength);
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
		cout << "Testing DesignCalendar (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393267939;
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
		DesignCalendar _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int dayLength = 4;
				int yearLength = 1461;
				_expected = 4;
				_received = _obj.shortestPeriod(dayLength, yearLength); break;
			}
			case 1:
			{
				int dayLength = 86400;
				int yearLength = 31558150;
				_expected = 1728;
				_received = _obj.shortestPeriod(dayLength, yearLength); break;
			}
			case 2:
			{
				int dayLength = 98;
				int yearLength = 100;
				_expected = 49;
				_received = _obj.shortestPeriod(dayLength, yearLength); break;
			}
			case 3:
			{
				int dayLength = 1000;
				int yearLength = 50000100;
				_expected = 10;
				_received = _obj.shortestPeriod(dayLength, yearLength); break;
			}
			case 4:
			{
				int dayLength = 5673;
				int yearLength = 28565335;
				_expected = 5673;
				_received = _obj.shortestPeriod(dayLength, yearLength); break;
			}
			case 5:
			{
				int dayLength = 5555;
				int yearLength = 846555;
				_expected = 1111;
				_received = _obj.shortestPeriod(dayLength, yearLength); break;
			}
			case 6:
			{
				int dayLength = 999999999;
				int yearLength = 1000000000;
				_expected = 999999999;
				_received = _obj.shortestPeriod(dayLength, yearLength); break;
			}
			case 7:
			{
				int dayLength = 356251142;
				int yearLength = 636214872;
				_expected = 178125571;
				_received = _obj.shortestPeriod(dayLength, yearLength); break;
			}
			/*case 8:
			{
				int dayLength = ;
				int yearLength = ;
				_expected = ;
				_received = _obj.shortestPeriod(dayLength, yearLength); break;
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
