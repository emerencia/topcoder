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

class RecursiveFigures {
 public:
  double getArea(int sideLength, int K) {
    double curside = sideLength;
    double r = 0;
    for (int i=0;i<K;i++) {
      r += curside*curside-M_PI*(curside/2)*(curside/2);
      curside = sqrt(0.5*curside*curside);
    }
    return sideLength*sideLength-r;
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
		cout << "Testing RecursiveFigures (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1399558952;
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
		RecursiveFigures _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int sideLength = 10;
				int K = 1;
				_expected = 78.53981633974483;
				_received = _obj.getArea(sideLength, K); break;
			}
			case 1:
			{
				int sideLength = 10;
				int K = 2;
				_expected = 67.80972450961724;
				_received = _obj.getArea(sideLength, K); break;
			}
			case 2:
			{
				int sideLength = 10;
				int K = 3;
				_expected = 62.444678594553444;
				_received = _obj.getArea(sideLength, K); break;
			}
			/*case 3:
			{
				int sideLength = ;
				int K = ;
				_expected = ;
				_received = _obj.getArea(sideLength, K); break;
			}*/
			/*case 4:
			{
				int sideLength = ;
				int K = ;
				_expected = ;
				_received = _obj.getArea(sideLength, K); break;
			}*/
			/*case 5:
			{
				int sideLength = ;
				int K = ;
				_expected = ;
				_received = _obj.getArea(sideLength, K); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(3);
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
