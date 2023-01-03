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

class ProductTriplet {
 public:
  long long countTriplets(int minx, int maxx, int miny, int maxy, int minz, int maxz) {
    LL r = 0;
    for (int i=max(minx,miny);i<=min(maxx,maxy) && maxz/i >= i;i++)   
      if (i*i >= minz)
        ++r;
    for (int i=1;i*i<maxz;i++) {
      if (i >= minx && i <= maxx) {
        int from = max(i+1,max(miny,(minz+i-1)/i));
        int to = min(maxz/i,maxy);
        if (to >= from)
          r+= to-from+1;
      }
      if (i >= miny && i <= maxy) {
        int from = max(i+1,max(minx,(minz+i-1)/i));
        int to = min(maxz/i,maxx);
        if (to >= from)
          r+= to-from+1;
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
	char* b[2];
	if(tt!=-1){b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing ProductTriplet (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1399468803;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 950.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ProductTriplet _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int minx = 2;
				int maxx = 2;
				int miny = 3;
				int maxy = 3;
				int minz = 6;
				int maxz = 6;
				_expected = 1LL;
				_received = _obj.countTriplets(minx, maxx, miny, maxy, minz, maxz); break;
			}
			case 1:
			{
				int minx = 2;
				int maxx = 2;
				int miny = 3;
				int maxy = 3;
				int minz = 7;
				int maxz = 7;
				_expected = 0LL;
				_received = _obj.countTriplets(minx, maxx, miny, maxy, minz, maxz); break;
			}
			case 2:
			{
				int minx = 6;
				int maxx = 8;
				int miny = 4;
				int maxy = 5;
				int minz = 27;
				int maxz = 35;
				_expected = 4LL;
				_received = _obj.countTriplets(minx, maxx, miny, maxy, minz, maxz); break;
			}
			case 3:
			{
				int minx = 1;
				int maxx = 458;
				int miny = 1;
				int maxy = 458;
				int minz = 1;
				int maxz = 458;
				_expected = 2877LL;
				_received = _obj.countTriplets(minx, maxx, miny, maxy, minz, maxz); break;
			}
			case 4:
			{
				int minx = 8176;
				int maxx = 184561;
				int miny = 1348;
				int maxy = 43168;
				int minz = 45814517;
				int maxz = 957843164;
				_expected = 2365846085LL;
				_received = _obj.countTriplets(minx, maxx, miny, maxy, minz, maxz); break;
			}
			case 5:
			{
				int minx = 1138;
				int maxx = 1000000000;
				int miny = 674290;
				int maxy = 1151090;
				int minz = 16;
				int maxz = 1000000000;
				_expected = 32267110LL;
				_received = _obj.countTriplets(minx, maxx, miny, maxy, minz, maxz); break;
			}
			/*case 6:
			{
				int minx = ;
				int maxx = ;
				int miny = ;
				int maxy = ;
				int minz = ;
				int maxz = ;
				_expected = LL;
				_received = _obj.countTriplets(minx, maxx, miny, maxy, minz, maxz); break;
			}*/
			/*case 7:
			{
				int minx = ;
				int maxx = ;
				int miny = ;
				int maxy = ;
				int minz = ;
				int maxz = ;
				_expected = LL;
				_received = _obj.countTriplets(minx, maxx, miny, maxy, minz, maxz); break;
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
