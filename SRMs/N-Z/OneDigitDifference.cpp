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
// 17:03
// END CUT HERE

class OneDigitDifference {
 public:
  int getSmallest(int N) {
    if (!N) return 1;
    int r = 0;
    int base = 1;
    while (N/10) {
      r+=base*(N%10);
      N/=10;
      base*=10;
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
	string a = tt == -1 ? "0" : string(1,'0'+tt);
	char* b[2] = {argv[0],(char*)a.c_str()};
	if(tt!=-1){argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing OneDigitDifference (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1400540193;
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
		OneDigitDifference _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 9;
				_expected = 0;
				_received = _obj.getSmallest(N); break;
			}
			case 1:
			{
				int N = 0;
				_expected = 1;
				_received = _obj.getSmallest(N); break;
			}
			case 2:
			{
				int N = 900000123;
				_expected = 123;
				_received = _obj.getSmallest(N); break;
			}
			case 3:
			{
				int N = 30000;
				_expected = 0;
				_received = _obj.getSmallest(N); break;
			}
			case 4:
			{
				int N = 47;
				_expected = 7;
				_received = _obj.getSmallest(N); break;
			}
			case 5:
			{
				int N = 1907654321;
				_expected = 907654321;
				_received = _obj.getSmallest(N); break;
			}
			/*case 6:
			{
				int N = ;
				_expected = ;
				_received = _obj.getSmallest(N); break;
			}*/
			/*case 7:
			{
				int N = ;
				_expected = ;
				_received = _obj.getSmallest(N); break;
			}*/
			/*case 8:
			{
				int N = ;
				_expected = ;
				_received = _obj.getSmallest(N); break;
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
