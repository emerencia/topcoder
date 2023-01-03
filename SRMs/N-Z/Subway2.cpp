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

class Subway2 {
 public:
  double minTime(int length, int maxAcceleration, int maxVelocity) {
    double a = maxAcceleration;
    double l = double(length)/2;
    double v = maxVelocity;
    double t = v/a;
    double distinc = 0.5*a*t*t;
    if (distinc >= l) {
      return 2.0*sqrt(2.0*l/a);
    }
    double ndist = l-distinc;
    return 2.0*(t+ndist/v);
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
		cout << "Testing Subway2 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390319255;
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
		Subway2 _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int length = 1;
				int maxAcceleration = 2;
				int maxVelocity = 10;
				_expected = 1.4142135623730951;
				_received = _obj.minTime(length, maxAcceleration, maxVelocity); break;
			}
			case 1:
			{
				int length = 1;
				int maxAcceleration = 1;
				int maxVelocity = 1;
				_expected = 2.0;
				_received = _obj.minTime(length, maxAcceleration, maxVelocity); break;
			}
			case 2:
			{
				int length = 10;
				int maxAcceleration = 1;
				int maxVelocity = 1;
				_expected = 11.0;
				_received = _obj.minTime(length, maxAcceleration, maxVelocity); break;
			}
			case 3:
			{
				int length = 1;
				int maxAcceleration = 10;
				int maxVelocity = 1;
				_expected = 1.1;
				_received = _obj.minTime(length, maxAcceleration, maxVelocity); break;
			}
			case 4:
			{
				int length = 778;
				int maxAcceleration = 887;
				int maxVelocity = 384;
				_expected = 2.458961621570838;
				_received = _obj.minTime(length, maxAcceleration, maxVelocity); break;
			}
			case 5:
			{
				int length = 336;
				int maxAcceleration = 794;
				int maxVelocity = 916;
				_expected = 1.301036207838119;
				_received = _obj.minTime(length, maxAcceleration, maxVelocity); break;
			}
			/*case 6:
			{
				int length = ;
				int maxAcceleration = ;
				int maxVelocity = ;
				_expected = ;
				_received = _obj.minTime(length, maxAcceleration, maxVelocity); break;
			}*/
			/*case 7:
			{
				int length = ;
				int maxAcceleration = ;
				int maxVelocity = ;
				_expected = ;
				_received = _obj.minTime(length, maxAcceleration, maxVelocity); break;
			}*/
			/*case 8:
			{
				int length = ;
				int maxAcceleration = ;
				int maxVelocity = ;
				_expected = ;
				_received = _obj.minTime(length, maxAcceleration, maxVelocity); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
