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
const int kMax = 1e9;

class PowerOfThreeEasy {
 public:
  int x,y;
  bool rec(LL cx, LL cy, LL lastinc) {
    if (cx == x && cy == y) return true;
    if (cx > kMax || cy > kMax) return false;
    if (lastinc == 0)
      return rec(cx+1,cy,1) || rec(cx,cy+1,1);
    return rec(cx+3*lastinc,cy,3*lastinc) || 
        rec(cx,cy+3*lastinc,3*lastinc);
  }
  string ableToGet(int x, int y) {
    this->x = x;
    this->y = y;
    bool r = rec(0,0,0);
    return (r ? "Possible" : "Impossible");
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
		cout << "Testing PowerOfThreeEasy (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394218989;
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
		PowerOfThreeEasy _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x = 1;
				int y = 3;
				_expected = "Possible";
				_received = _obj.ableToGet(x, y); break;
			}
			case 1:
			{
				int x = 1;
				int y = 1;
				_expected = "Impossible";
				_received = _obj.ableToGet(x, y); break;
			}
			case 2:
			{
				int x = 3;
				int y = 0;
				_expected = "Impossible";
				_received = _obj.ableToGet(x, y); break;
			}
			case 3:
			{
				int x = 1;
				int y = 9;
				_expected = "Impossible";
				_received = _obj.ableToGet(x, y); break;
			}
			case 4:
			{
				int x = 3;
				int y = 10;
				_expected = "Possible";
				_received = _obj.ableToGet(x, y); break;
			}
			case 5:
			{
				int x = 1093;
				int y = 2187;
				_expected = "Possible";
				_received = _obj.ableToGet(x, y); break;
			}
			case 6:
			{
				int x = 0;
				int y = 0;
				_expected = "Possible";
				_received = _obj.ableToGet(x, y); break;
			}
			/*case 7:
			{
				int x = ;
				int y = ;
				_expected = ;
				_received = _obj.ableToGet(x, y); break;
			}*/
			/*case 8:
			{
				int x = ;
				int y = ;
				_expected = ;
				_received = _obj.ableToGet(x, y); break;
			}*/
			/*case 9:
			{
				int x = ;
				int y = ;
				_expected = ;
				_received = _obj.ableToGet(x, y); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
