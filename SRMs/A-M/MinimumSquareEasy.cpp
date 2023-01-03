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
// 21:12
// END CUT HERE

class MinimumSquareEasy {
 public:
  long long minArea(vector <int> x, vector <int> y) {
    LL r = LLONG_MAX;
    for (int i=0;i<x.size();i++)
      for (int j=0;j<i;j++) {
        int minx = INT_MAX;
        int miny = INT_MAX;
        int maxx = INT_MIN;
        int maxy = INT_MIN;
        for (int k=0;k<x.size();k++) {
          if (k == i || k == j) continue;
          if (x[k] < minx) minx = x[k];
          if (x[k] > maxx) maxx = x[k];
          if (y[k] < miny) miny = y[k];
          if (y[k] > maxy) maxy = y[k];
        }
        LL maxdist = max(maxx-minx,maxy-miny);
        maxdist+=2;
        r = min(r,maxdist*maxdist);
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
        case 4:
        {
          int x[] = {-4193334, -9039900, -678674, -9888380, -4897631, -202485, -3082567, -5656936, -2403738, -7098768, -1643106, -2496510, -6928612, -4090638, -5167004, -149972, -5427668, -2769614, -2925505, -6696909, -3102086, -2972959, -9227294, -1290206, -8266925, -8828240, -5062822, -2630392};
          int y[] = {-390488, -5313389, -6883976, -2497381, -6414575, -4061417, -2076191, -6900149, -1221254, -2674561, -1156670, -4419532, -7971660, -4316737, -6313761, -1029930, -5158771, -3292124, -9291974, -7614951, -7941561, -3658836, -8271895, -7396608, -7423035, -9095820, -9655568, -6063686};
          _expected = 82397811000976LL;
          _received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
        }
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
