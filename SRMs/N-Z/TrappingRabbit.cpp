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

class TrappingRabbit {
 public:
  int findMinimumTime(vector <int> trapX, vector <int> trapY) {
    int mn = INT_MAX;
    for (int i=0;i<trapX.size();i++)
      mn = min(mn,trapX[i]+trapY[i]-2);
    return mn;
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
		cout << "Testing TrappingRabbit (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1400856751;
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
		TrappingRabbit _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int trapX[] = {4,6,8};
				int trapY[] = {1,2,1};
				_expected = 3;
				_received = _obj.findMinimumTime(vector <int>(trapX, trapX+sizeof(trapX)/sizeof(int)), vector <int>(trapY, trapY+sizeof(trapY)/sizeof(int))); break;
			}
			case 1:
			{
				int trapX[] = {5,4,3};
				int trapY[] = {5,4,3};
				_expected = 4;
				_received = _obj.findMinimumTime(vector <int>(trapX, trapX+sizeof(trapX)/sizeof(int)), vector <int>(trapY, trapY+sizeof(trapY)/sizeof(int))); break;
			}
			case 2:
			{
				int trapX[] = {3,4,5};
				int trapY[] = {5,4,3};
				_expected = 6;
				_received = _obj.findMinimumTime(vector <int>(trapX, trapX+sizeof(trapX)/sizeof(int)), vector <int>(trapY, trapY+sizeof(trapY)/sizeof(int))); break;
			}
			case 3:
			{
				int trapX[] = {958,375,195,686,483,629,377};
				int trapY[] = {104,505,882,357,759,400,869};
				_expected = 878;
				_received = _obj.findMinimumTime(vector <int>(trapX, trapX+sizeof(trapX)/sizeof(int)), vector <int>(trapY, trapY+sizeof(trapY)/sizeof(int))); break;
			}
			/*case 4:
			{
				int trapX[] = ;
				int trapY[] = ;
				_expected = ;
				_received = _obj.findMinimumTime(vector <int>(trapX, trapX+sizeof(trapX)/sizeof(int)), vector <int>(trapY, trapY+sizeof(trapY)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int trapX[] = ;
				int trapY[] = ;
				_expected = ;
				_received = _obj.findMinimumTime(vector <int>(trapX, trapX+sizeof(trapX)/sizeof(int)), vector <int>(trapY, trapY+sizeof(trapY)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int trapX[] = ;
				int trapY[] = ;
				_expected = ;
				_received = _obj.findMinimumTime(vector <int>(trapX, trapX+sizeof(trapX)/sizeof(int)), vector <int>(trapY, trapY+sizeof(trapY)/sizeof(int))); break;
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
