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
const int tt = 3;
// 
// END CUT HERE

class MinimumSquareEasy {
 public:
  long long minArea(vector <int> x, vector <int> y) {
    LL r = LLONG_MAX;
    int maxinside = 0;
    for (int i=0;i<x.size();i++)
      for (int ii=0;ii<3;ii++) {
        int xi = x[i]-1+ii;
        int yi = y[i]-1+ii;
        for (int j=0;j<x.size();j++)
          for (int jj=0;jj<3;jj++) {
            int xj = x[j]-1+jj;
            int yj = y[j]-1+jj;
            for (int l=0;l<4;l++) {
              LL sqsize = max(abs(yi - yj), abs(xi - xj));
              LL minx, maxx, miny, maxy;
              switch(l) {
                case 0:
                  minx = min(xi, xj);
                  maxx = minx + sqsize;
                  maxy = max(yi, yj);
                  miny = maxy - sqsize;
                  break;
                case 1:
                  minx = min(xi, xj);
                  maxx = minx + sqsize;
                  miny = min(yi, yj);
                  maxy = miny + sqsize;
                  break;
                case 2:
                  maxx = max(xi,xj);
                  minx = maxx-sqsize;
                  maxy = max(yi,yj);
                  miny = maxy-sqsize;
                  break;
                case 3:
                  maxx = max(xi,xj);
                  minx = maxx-sqsize;
                  miny = min(yi,yj);
                  maxy = miny+sqsize;
                  break;
              }
              int ninside = 0;
              for (int k=0;k<x.size();k++)
                if (x[k] > minx && x[k]  < maxx && y[k] > miny && y[k] < maxy)
                  ninside++;
              maxinside = max(maxinside,ninside);
              if (ninside >= x.size()-2)
                r = min(r,sqsize*sqsize);
            }
          }
      }
    cout << x.size()-2 << endl;
    cout << maxinside << endl;
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
