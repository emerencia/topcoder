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

class MinimumSquare {
 public:
  long long minArea(vector <int> x, vector <int> y, int K) {
    LL r = LLONG_MAX;
    for (int i=0;i<x.size();i++) {
      int xs = x[i];
      for (int j = 0; j < x.size(); j++) {
        int ys = y[j];
        vector<int> dists;
        for (int k=0;k<x.size();k++)
          if (x[k] >= xs && y[k] >= ys)
            dists.push_back(max(x[k]-xs,y[k]-ys));
        if (dists.size() >= K) {
          sort(dists.begin(),dists.end());
          LL side = 2 + dists[K-1];
          r = min(r,(LL)side * side);
        }
      }
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
		cout << "Testing MinimumSquare (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1425931318;
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
		MinimumSquare _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {0, 3};
				int y[] = {0, 7};
				int K = 2;
				_expected = 81LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
			}
			case 1:
			{
				int x[] = {-4, 3, 1};
				int y[] = {3 , -1, -2};
				int K = 2;
				_expected = 16LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
			}
			case 2:
			{
				int x[] = {0, 0, 1, 1, 2, 2};
				int y[] = {0, 1, 0, 1, 0, 1};
				int K = 4;
				_expected = 9LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
			}
			case 3:
			{
				int x[] = {1000000000, 1000000000, 1000000000, -1000000000, -1000000000, -1000000000};
				int y[] = {1000000000, 0, -1000000000, 1000000000, 0, -1000000000};
				int K = 3;
				_expected = 4000000008000000004LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
			}
			case 4:
			{
				int x[] = {-47881, 28623, 1769, -38328, -16737, 16653, -23181, 37360, 41429, 26282, 254, 728, 8299, -41080, -29498, 17488, -23937, -11, 33319, 25232};
				int y[] = {-46462, 48985, -43820, -19587, -33593, -28337, 13667, -48131, -5568, -2332, -41918, -31370, -3695, 42599, -37788, -40096, 39049, 25045, -2122, 3874};
				int K = 8;
				_expected = 1695545329LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
			}
			/*case 5:
			{
				int x[] = ;
				int y[] = ;
				int K = ;
				_expected = LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				int K = ;
				_expected = LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				int y[] = ;
				int K = ;
				_expected = LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
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
