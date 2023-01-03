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

class PaperAndPaintEasy {
 public:
  long long computeArea(int width, int height, int xfold, int cnt, int x1, int y1, int x2, int y2) {
    xfold = min(xfold,width-xfold);
    int pwidth = width-xfold;
    int pheight = height/(cnt+1);
    LL cutsum = (LL)pheight*pwidth;
    cutsum += (LL)pheight*xfold;
    if (x1 < xfold && x2 <= xfold) {
      cutsum -= 2LL*((LL)x2-x1)*(y2-y1);
    } else if (x1 >= xfold && x2 > xfold) {
      cutsum -= ((LL)x2-x1)*(y2-y1);
    } else {
      cutsum -= ((LL)x2-xfold)*(y2-y1);
      cutsum -= 2LL*((LL)xfold-x1)*(y2-y1);
    }
    cutsum*=cnt+1;
    return cutsum;
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
		cout << "Testing PaperAndPaintEasy (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395543284;
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
		PaperAndPaintEasy _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int width = 5;
				int height = 6;
				int xfold = 2;
				int cnt = 2;
				int x1 = 1;
				int y1 = 1;
				int x2 = 3;
				int y2 = 2;
				_expected = 21LL;
				_received = _obj.computeArea(width, height, xfold, cnt, x1, y1, x2, y2); break;
			}
			case 1:
			{
				int width = 3;
				int height = 13;
				int xfold = 1;
				int cnt = 0;
				int x1 = 1;
				int y1 = 8;
				int x2 = 2;
				int y2 = 12;
				_expected = 35LL;
				_received = _obj.computeArea(width, height, xfold, cnt, x1, y1, x2, y2); break;
			}
			case 2:
			{
				int width = 12;
				int height = 12;
				int xfold = 7;
				int cnt = 3;
				int x1 = 3;
				int y1 = 1;
				int x2 = 6;
				int y2 = 2;
				_expected = 124LL;
				_received = _obj.computeArea(width, height, xfold, cnt, x1, y1, x2, y2); break;
			}
			case 3:
			{
				int width = 4;
				int height = 5;
				int xfold = 4;
				int cnt = 0;
				int x1 = 0;
				int y1 = 0;
				int x2 = 1;
				int y2 = 1;
				_expected = 19LL;
				_received = _obj.computeArea(width, height, xfold, cnt, x1, y1, x2, y2); break;
			}
			case 4:
			{
				int width = 4;
				int height = 8;
				int xfold = 4;
				int cnt = 3;
				int x1 = 0;
				int y1 = 1;
				int x2 = 2;
				int y2 = 2;
				_expected = 24LL;
				_received = _obj.computeArea(width, height, xfold, cnt, x1, y1, x2, y2); break;
			}
			case 5:
			{
				int width = 4;
				int height = 8;
				int xfold = 3;
				int cnt = 0;
				int x1 = 1;
				int y1 = 1;
				int x2 = 3;
				int y2 = 2;
				_expected = 30LL;
				_received = _obj.computeArea(width, height, xfold, cnt, x1, y1, x2, y2); break;
			}
			/*case 6:
			{
				int width = ;
				int height = ;
				int xfold = ;
				int cnt = ;
				int x1 = ;
				int y1 = ;
				int x2 = ;
				int y2 = ;
				_expected = LL;
				_received = _obj.computeArea(width, height, xfold, cnt, x1, y1, x2, y2); break;
			}*/
			/*case 7:
			{
				int width = ;
				int height = ;
				int xfold = ;
				int cnt = ;
				int x1 = ;
				int y1 = ;
				int x2 = ;
				int y2 = ;
				_expected = LL;
				_received = _obj.computeArea(width, height, xfold, cnt, x1, y1, x2, y2); break;
			}*/
			/*case 8:
			{
				int width = ;
				int height = ;
				int xfold = ;
				int cnt = ;
				int x1 = ;
				int y1 = ;
				int x2 = ;
				int y2 = ;
				_expected = LL;
				_received = _obj.computeArea(width, height, xfold, cnt, x1, y1, x2, y2); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
