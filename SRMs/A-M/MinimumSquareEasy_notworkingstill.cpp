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

class MinimumSquareEasy {
 public:
  long long minArea(vector <int> x, vector <int> y) {
    int minx = INT_MAX;
    int maxx = INT_MIN;
    int miny = INT_MAX;
    int maxy = INT_MIN;
    for (int i=0;i<x.size();i++) {
      maxx = max(maxx,x[i]);
      minx = min(minx,x[i]);
      maxy = max(maxy,y[i]);
      miny = min(miny,y[i]);
    }
    int xmaxpoints = 0;
    int xminpoints = 0;
    int ymaxpoints = 0;
    int yminpoints = 0;
    for (int i=0;i<x.size();i++) {
      if (x[i] == maxx) xmaxpoints++;
      if (x[i] == minx) xminpoints++;
      if (y[i] == miny) yminpoints++;
      if (y[i] == maxy) ymaxpoints++;
    }
    if (xmaxpoints > 1) { xmaxpoints = 0; maxx++; }
    if (xminpoints > 1) { xminpoints = 0; minx--; }
    if (ymaxpoints > 1) { ymaxpoints = 0; maxy++; }
    if (yminpoints > 1) { yminpoints = 0; miny--; }
    int edgepoints = xmaxpoints + xminpoints + ymaxpoints + yminpoints;
    LL xsize = maxx-minx;
    LL ysize = maxy-miny;
    if (xsize == ysize && edgepoints > 2)
      return (xsize+1)*(xsize+1);
    LL sqsize = max(xsize,ysize);
    return sqsize*sqsize;
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
		cout << "Testing MinimumSquareEasy (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1423602134;
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
		MinimumSquareEasy _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {0, 1, 2};
				int y[] = {0, 1, 5};
				_expected = 4LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {-1, -1, 0, 2, 0};
				int y[] = {-2, -1, 0, -1, -2};
				_expected = 9LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {1000000000, -1000000000, 1000000000, -1000000000};
				int y[] = {1000000000, 1000000000, -1000000000, -1000000000};
				_expected = 4000000008000000004LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {93, 34, 12, -11, -7, -21, 51, -22, 59, 74, -19, 29, -56, -95, -96, 9, 44, -37, -54, -21};
				int y[] = {64, 12, -43, 20, 55, 74, -20, -54, 24, 20, -18, 77, 86, 22, 47, -24, -33, -57, 5, 7};
				_expected = 22801LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 4:
			{
				int x[] = ;
				int y[] = ;
				_expected = LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int x[] = ;
				int y[] = ;
				_expected = LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				_expected = LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
