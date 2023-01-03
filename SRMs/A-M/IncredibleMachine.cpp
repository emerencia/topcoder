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

class IncredibleMachine {
 public:
  double gravitationalAcceleration(vector <int> x, vector <int> y, int T) {
    double g = 1;
    double ttot = 0;
    double v0 = 0;
    for (int i=1;i<x.size();i++) {
      double d = sqrt((x[i]-x[i-1])*(x[i]-x[i-1])+(y[i-1]-y[i])*(y[i-1]-y[i]));
      double alpha = atan(((double)y[i-1]-y[i])/(x[i]-x[i-1]));
      double a = g*sin(alpha);
      double t = (-v0+sqrt(v0*v0+2*a*d))/a;
      v0 = v0+a*t;
      ttot += t;
    }
    return double(ttot*ttot)/(T*T);
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
		cout << "Testing IncredibleMachine (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395448108;
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
		IncredibleMachine _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {0,6};
				int y[] = {100,22};
				int T = 4;
				_expected = 9.807692307692307;
				_received = _obj.gravitationalAcceleration(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), T); break;
			}
			case 1:
			{
				int x[] = {0,26,100};
				int y[] = {50,26,24};
				int T = 4;
				_expected = 26.743031720603582;
				_received = _obj.gravitationalAcceleration(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), T); break;
			}
			case 2:
			{
				int x[] = {0,7,8};
				int y[] = {10,6,0};
				int T = 7;
				_expected = 1.1076837407708007;
				_received = _obj.gravitationalAcceleration(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), T); break;
			}
			/*case 3:
			{
				int x[] = ;
				int y[] = ;
				int T = ;
				_expected = ;
				_received = _obj.gravitationalAcceleration(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), T); break;
			}*/
			/*case 4:
			{
				int x[] = ;
				int y[] = ;
				int T = ;
				_expected = ;
				_received = _obj.gravitationalAcceleration(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), T); break;
			}*/
			/*case 5:
			{
				int x[] = ;
				int y[] = ;
				int T = ;
				_expected = ;
				_received = _obj.gravitationalAcceleration(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), T); break;
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
