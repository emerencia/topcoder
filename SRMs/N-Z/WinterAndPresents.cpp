#include <string>
#include <iostream>
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

class WinterAndPresents {
 public:
  long long getNumber(vector <int> apple, vector <int> orange) {
    int maxx = INT_MAX;
    for (int i=0;i<apple.size();i++)
      maxx = min(maxx,apple[i]+orange[i]);
    LL r = 0;
    for (int j=1;j<=maxx;j++) {
      LL mn = 0;
      LL mx = 0;
      for (int i=0;i<apple.size();i++) {
        mn+= max(0,j-orange[i]);
        mx+= min(apple[i],j);
      }
      r+=mx-mn+1;
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
		cout << "Testing WinterAndPresents (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391213520;
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
		WinterAndPresents _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int apple[] = {1};
				int orange[] = {1};
				_expected = 3LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
			}
			case 1:
			{
				int apple[] = {1, 2, 0, 3};
				int orange[] = {4, 5, 0, 6};
				_expected = 0LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
			}
			case 2:
			{
				int apple[] = {2, 2, 2};
				int orange[] = {2, 2, 2};
				_expected = 16LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
			}
			case 3:
			{
				int apple[] = {7, 4, 5};
				int orange[] = {1, 10, 2};
				_expected = 46LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
			}
			case 4:
			{
				int apple[] = {1000000};
				int orange[] = {1000000};
				_expected = 1000002000000LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
			}
			/*case 5:
			{
				int apple[] = ;
				int orange[] = ;
				_expected = LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int apple[] = ;
				int orange[] = ;
				_expected = LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int apple[] = ;
				int orange[] = ;
				_expected = LL;
				_received = _obj.getNumber(vector <int>(apple, apple+sizeof(apple)/sizeof(int)), vector <int>(orange, orange+sizeof(orange)/sizeof(int))); break;
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
