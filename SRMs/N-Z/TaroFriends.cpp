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

class TaroFriends {
 public:
  int getNumber(vector <int> coordinates, int X) {
    sort(coordinates.begin(),coordinates.end());
    LL r = 201000000;
    for (int i=0;i<=coordinates.size();i++) {
      LL mindst = 101000000;
      LL maxdst = -101000000;
      for (int j=0;j<coordinates.size();j++) {
        LL dst = 0;
        if (j < i) {
          dst = (LL)coordinates[j]+X;
        } else {
          dst = (LL)coordinates[j]-X;
        }
        if (dst < mindst) mindst = dst;
        if (dst > maxdst) maxdst = dst;
      }
      LL md = maxdst-mindst;
      r = min(r,md);
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
	if(tt!=-1){char* b[2];b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}	if (argc == 1) 
	{
		cout << "Testing TaroFriends (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395414001;
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
		TaroFriends _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int coordinates[] = {-3, 0, 1};
				int X = 3;
				_expected = 3;
				_received = _obj.getNumber(vector <int>(coordinates, coordinates+sizeof(coordinates)/sizeof(int)), X); break;
			}
			case 1:
			{
				int coordinates[] = {4, 7, -7};
				int X = 5;
				_expected = 4;
				_received = _obj.getNumber(vector <int>(coordinates, coordinates+sizeof(coordinates)/sizeof(int)), X); break;
			}
			case 2:
			{
				int coordinates[] = {-100000000, 100000000};
				int X = 100000000;
				_expected = 0;
				_received = _obj.getNumber(vector <int>(coordinates, coordinates+sizeof(coordinates)/sizeof(int)), X); break;
			}
			case 3:
			{
				int coordinates[] = {3, 7, 4, 6, -10, 7, 10, 9, -5};
				int X = 7;
				_expected = 7;
				_received = _obj.getNumber(vector <int>(coordinates, coordinates+sizeof(coordinates)/sizeof(int)), X); break;
			}
			case 4:
			{
				int coordinates[] = {-4, 0, 4, 0};
				int X = 4;
				_expected = 4;
				_received = _obj.getNumber(vector <int>(coordinates, coordinates+sizeof(coordinates)/sizeof(int)), X); break;
			}
			case 5:
			{
				int coordinates[] = {7};
				int X = 0;
				_expected = 0;
				_received = _obj.getNumber(vector <int>(coordinates, coordinates+sizeof(coordinates)/sizeof(int)), X); break;
			}
			/*case 6:
			{
				int coordinates[] = ;
				int X = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(coordinates, coordinates+sizeof(coordinates)/sizeof(int)), X); break;
			}*/
			/*case 7:
			{
				int coordinates[] = ;
				int X = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(coordinates, coordinates+sizeof(coordinates)/sizeof(int)), X); break;
			}*/
			/*case 8:
			{
				int coordinates[] = ;
				int X = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(coordinates, coordinates+sizeof(coordinates)/sizeof(int)), X); break;
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
