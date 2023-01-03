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

class TheTournamentDivTwo {
 public:
  int find(vector <int> points) {
    int c = 0;
    for (int i=0;i<points.size();i++)
      if (points[i]%2) {
        c++;
        points[i]--;
      }
    if (c%2) return -1;
    int mx = 0;
    for (int i=0;i<points.size();i++)
      mx += points[i]/2;
    return mx+c/2;
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
		cout << "Testing TheTournamentDivTwo (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398679233;
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
		TheTournamentDivTwo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int points[] = {10, 1, 1};
				_expected = 6;
				_received = _obj.find(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			case 1:
			{
				int points[] = {1, 1, 1};
				_expected = -1;
				_received = _obj.find(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			case 2:
			{
				int points[] = {0, 0, 0, 0, 0, 0, 0};
				_expected = 0;
				_received = _obj.find(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			case 3:
			{
				int points[] = {13, 8, 7};
				_expected = 14;
				_received = _obj.find(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			/*case 4:
			{
				int points[] = ;
				_expected = ;
				_received = _obj.find(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int points[] = ;
				_expected = ;
				_received = _obj.find(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int points[] = ;
				_expected = ;
				_received = _obj.find(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
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
