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
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

class RectangularIsland {
 public:
  double theProbablity(int width, int height, int x, int y, int steps) {
    for (int l=0;l<=steps;l++) {
      for (int u=0;u<=steps;u++) {

      }
    }
    LL tot = 1;
    for (int i=0;i<steps;i++)
      tot *= 4LL;
    return r/tot;
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
		cout << "Testing RectangularIsland (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1414271088;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RectangularIsland _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int width = 5;
				int height = 8;
				int x = 4;
				int y = 3;
				int steps = 1;
				_expected = 0.75;
				_received = _obj.theProbablity(width, height, x, y, steps); break;
			}
			case 1:
			{
				int width = 5;
				int height = 8;
				int x = 4;
				int y = 7;
				int steps = 1;
				_expected = 0.5;
				_received = _obj.theProbablity(width, height, x, y, steps); break;
			}
			case 2:
			{
				int width = 2;
				int height = 2;
				int x = 0;
				int y = 1;
				int steps = 5;
				_expected = 0.03125;
				_received = _obj.theProbablity(width, height, x, y, steps); break;
			}
			case 3:
			{
				int width = 58;
				int height = 85;
				int x = 47;
				int y = 74;
				int steps = 1000;
				_expected = 0.13056659769966347;
				_received = _obj.theProbablity(width, height, x, y, steps); break;
			}
			case 4:
			{
				int width = 1000;
				int height = 1000;
				int x = 123;
				int y = 456;
				int steps = 5000;
				_expected = 0.9868611148475199;
				_received = _obj.theProbablity(width, height, x, y, steps); break;
			}
			/*case 5:
			{
				int width = ;
				int height = ;
				int x = ;
				int y = ;
				int steps = ;
				_expected = ;
				_received = _obj.theProbablity(width, height, x, y, steps); break;
			}*/
			/*case 6:
			{
				int width = ;
				int height = ;
				int x = ;
				int y = ;
				int steps = ;
				_expected = ;
				_received = _obj.theProbablity(width, height, x, y, steps); break;
			}*/
			/*case 7:
			{
				int width = ;
				int height = ;
				int x = ;
				int y = ;
				int steps = ;
				_expected = ;
				_received = _obj.theProbablity(width, height, x, y, steps); break;
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
