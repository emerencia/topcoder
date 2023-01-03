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

class IncredibleMachineEasy {
 public:
  double gravitationalAcceleration(vector <int> height, int T) {
    double l = 1e-9;
    double r = 1e100;
    while (r-l > 1e-9) {
      double p = (l+r)/2;
      double tapprox = 0;
      for (int i=0;i<height.size();i++)
        tapprox += sqrt(height[i]*2.0/p);
      if (T > tapprox) {
        r = p;
      } else {
        l = p;
      }
    }
    return l;
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
		cout << "Testing IncredibleMachineEasy (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395160743;
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
		IncredibleMachineEasy _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int height[] = {16,23,85,3,35,72,96,88,2,14,63};
				int T = 30;
				_expected = 9.803799620759717;
				_received = _obj.gravitationalAcceleration(vector <int>(height, height+sizeof(height)/sizeof(int)), T); break;
			}
			case 1:
			{
				int height[] = {6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5};
				int T = 12;
				_expected = 26.73924541044107;
				_received = _obj.gravitationalAcceleration(vector <int>(height, height+sizeof(height)/sizeof(int)), T); break;
			}
			case 2:
			{
				int height[] = {8,8};
				int T = 3;
				_expected = 7.111111111111111;
				_received = _obj.gravitationalAcceleration(vector <int>(height, height+sizeof(height)/sizeof(int)), T); break;
			}
			case 3:
			{
				int height[] = {3,1,3,1,3};
				int T = 12;
				_expected = 0.7192306901503684;
				_received = _obj.gravitationalAcceleration(vector <int>(height, height+sizeof(height)/sizeof(int)), T); break;
			}
			/*case 4:
			{
				int height[] = ;
				int T = ;
				_expected = ;
				_received = _obj.gravitationalAcceleration(vector <int>(height, height+sizeof(height)/sizeof(int)), T); break;
			}*/
			/*case 5:
			{
				int height[] = ;
				int T = ;
				_expected = ;
				_received = _obj.gravitationalAcceleration(vector <int>(height, height+sizeof(height)/sizeof(int)), T); break;
			}*/
			/*case 6:
			{
				int height[] = ;
				int T = ;
				_expected = ;
				_received = _obj.gravitationalAcceleration(vector <int>(height, height+sizeof(height)/sizeof(int)), T); break;
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
