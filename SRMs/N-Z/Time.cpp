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

class Time {
 public:
  string whatTime(int seconds) {
    int hours = seconds/3600;
    seconds -=hours*3600;
    int minutes = seconds/60;
    seconds -=minutes*60;
    stringstream a;
    a << hours << ":" << minutes << ":" << seconds;
    return a.str();
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
		cout << "Testing Time (200.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1408030385;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 200.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Time _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int seconds = 0;
				_expected = "0:0:0";
				_received = _obj.whatTime(seconds); break;
			}
			case 1:
			{
				int seconds = 3661;
				_expected = "1:1:1";
				_received = _obj.whatTime(seconds); break;
			}
			case 2:
			{
				int seconds = 5436;
				_expected = "1:30:36";
				_received = _obj.whatTime(seconds); break;
			}
			case 3:
			{
				int seconds = 86399;
				_expected = "23:59:59";
				_received = _obj.whatTime(seconds); break;
			}
			/*case 4:
			{
				int seconds = ;
				_expected = ;
				_received = _obj.whatTime(seconds); break;
			}*/
			/*case 5:
			{
				int seconds = ;
				_expected = ;
				_received = _obj.whatTime(seconds); break;
			}*/
			/*case 6:
			{
				int seconds = ;
				_expected = ;
				_received = _obj.whatTime(seconds); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
