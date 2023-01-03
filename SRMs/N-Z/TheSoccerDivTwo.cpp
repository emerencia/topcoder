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
int mem[51][51][102];

class TheSoccerDivTwo {
 public:
  vector<int> points;
  int rec(int idx, int draws, int winbalance) {
    int& r = mem[idx][draws][winbalance+50];
    if (r != -1) return r;
    if (idx == 0) return r = rec(idx+1,draws,winbalance+1);
    if (idx == points.size()) {
      if (draws%2 || winbalance) return r = 1e6;
      return r = 0;
    }
    int t = INT_MAX;
    t = min(t,(points[idx]>points[0] ? 1 : 0)+rec(idx+1,draws,winbalance+1));
    t = min(t,(points[idx]>points[0]+2 ? 1 : 0)+rec(idx+1,draws+1,winbalance));
    t = min(t,(points[idx]>points[0]+3 ? 1 : 0)+rec(idx+1,draws,winbalance-1));
    return r = t;
  }
  int find(vector <int> points) {
    this->points = points;
    memset(mem,-1,sizeof(mem));
    return 1+rec(0,0,0);
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
		cout << "Testing TheSoccerDivTwo (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398680146;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TheSoccerDivTwo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int points[] = {4, 7};
				_expected = 1;
				_received = _obj.find(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			case 1:
			{
				int points[] = {4, 7, 7, 7};
				_expected = 2;
				_received = _obj.find(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			case 2:
			{
				int points[] = {5, 9, 11, 9, 10, 9};
				_expected = 6;
				_received = _obj.find(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			case 3:
			{
				int points[] = {2, 1, 3, 7, 6, 5, 3, 4, 2, 6, 5, 1};
				_expected = 4;
				_received = _obj.find(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			case 4:
			{
				int points[] = {11, 14, 12, 14, 12, 10, 14, 14, 14, 14, 12, 14, 14, 12, 15, 10, 10, 10};
				_expected = 3;
				_received = _obj.find(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
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
