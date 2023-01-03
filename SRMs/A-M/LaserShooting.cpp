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

class LaserShooting {
 public:
  double numberOfHits(vector <int> x, vector <int> y1, vector <int> y2) {
    // expected number of targets getting hit is just the sum
    // of the probabilities for each target of getting hit.
    double r = 0;
    for (int i=0;i<x.size();i++) {
      double a1 = atan((double)abs(y1[i])/x[i]);
      double a2 = atan((double)abs(y2[i])/x[i]);
      double a;
      if ((y1[i] > 0 && y2[i] > 0) || (y1[i] < 0 && y2[i] < 0))
        a = abs(a1-a2);
      else 
        a = a1+a2;
      r+=a/M_PI;
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
	if(tt!=-1){char* b[2];b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}	if (argc == 1) 
	{
		cout << "Testing LaserShooting (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393608983;
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
		LaserShooting _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {1};
				int y1[] = {-1};
				int y2[] = {1};
				_expected = 0.5;
				_received = _obj.numberOfHits(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {1,2};
				int y1[] = {-1,-2};
				int y2[] = {1,2};
				_expected = 1.0;
				_received = _obj.numberOfHits(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {3,4,7,1};
				int y1[] = {1,2,3,4};
				int y2[] = {4,3,2,1};
				_expected = 0.4623163952488826;
				_received = _obj.numberOfHits(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {134,298,151,942};
				int y1[] = {-753,-76,19,568};
				int y2[] = {440,689,-39,672};
				_expected = 1.444210260641501;
				_received = _obj.numberOfHits(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int))); break;
			}
			/*case 4:
			{
				int x[] = ;
				int y1[] = ;
				int y2[] = ;
				_expected = ;
				_received = _obj.numberOfHits(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int x[] = ;
				int y1[] = ;
				int y2[] = ;
				_expected = ;
				_received = _obj.numberOfHits(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int y1[] = ;
				int y2[] = ;
				_expected = ;
				_received = _obj.numberOfHits(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int))); break;
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
