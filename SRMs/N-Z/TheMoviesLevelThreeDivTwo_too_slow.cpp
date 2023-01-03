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

class TheMoviesLevelThreeDivTwo {
 public:
  int find(vector <int> timeJ, vector <int> timeB) {
    int r = 0;
    for (int i=0;i<(1<<timeJ.size());i++) {
      queue<int> john,brus;
      for (int j=0;j<timeJ.size();j++)
        if (i&(1<<j))
          john.push(j);
        else
          brus.push(j);
      int johntime = 0;
      if (!john.empty()) johntime = timeJ[john.front()];
      int brustime = 0;
      if (!brus.empty()) brustime = timeB[brus.front()];
      int jwatched = 0,bwatched = 0;
      while (true) {
        if (johntime < 0 && brustime < 0) break;
        if (brustime == 0 && !brus.empty()) {
          bwatched++;
          int movie = brus.front();
          brus.pop();
          if (!(i&(1<<movie))) john.push(movie);
        }
        if (johntime == 0 && !john.empty()) {
          jwatched++;
          int movie = john.front();
          john.pop();
          if (i&(1<<movie)) brus.push(movie);
        }
        if (brustime == 0 && !brus.empty()) {
          brustime = timeB[brus.front()];
        }
        if (johntime == 0 && !john.empty()) {
          johntime = timeJ[john.front()];
        }
        int mn = min(max(1,johntime),max(1,brustime));
        johntime-=mn;
        brustime-=mn;
      }
      if (jwatched == timeJ.size() && bwatched == timeJ.size()) r++;
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
		cout << "Testing TheMoviesLevelThreeDivTwo (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1408649760;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TheMoviesLevelThreeDivTwo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int timeJ[] = {4, 4};
				int timeB[] = {4, 4};
				_expected = 2;
				_received = _obj.find(vector <int>(timeJ, timeJ+sizeof(timeJ)/sizeof(int)), vector <int>(timeB, timeB+sizeof(timeB)/sizeof(int))); break;
			}
			case 1:
			{
				int timeJ[] = {1, 4};
				int timeB[] = {4, 2};
				_expected = 1;
				_received = _obj.find(vector <int>(timeJ, timeJ+sizeof(timeJ)/sizeof(int)), vector <int>(timeB, timeB+sizeof(timeB)/sizeof(int))); break;
			}
			case 2:
			{
				int timeJ[] = {10, 10, 10, 10};
				int timeB[] = {1, 1, 1, 10};
				_expected = 3;
				_received = _obj.find(vector <int>(timeJ, timeJ+sizeof(timeJ)/sizeof(int)), vector <int>(timeB, timeB+sizeof(timeB)/sizeof(int))); break;
			}
			case 3:
			{
				int timeJ[] = {1, 2, 3, 4, 5, 6, 7};
				int timeB[] = {7, 6, 5, 4, 3, 2, 1};
				_expected = 98;
				_received = _obj.find(vector <int>(timeJ, timeJ+sizeof(timeJ)/sizeof(int)), vector <int>(timeB, timeB+sizeof(timeB)/sizeof(int))); break;
			}
			case 4:
			{
				int timeJ[] = {9, 9, 12, 3, 11, 17, 1, 4, 1, 7, 13, 1, 7, 5, 5, 11, 6, 12, 1, 3};
				int timeB[] = {15, 14, 5, 19, 14, 11, 9, 4, 13, 5, 5, 7, 13, 8, 9, 11, 8, 11, 17, 1};
				_expected = 957134;
				_received = _obj.find(vector <int>(timeJ, timeJ+sizeof(timeJ)/sizeof(int)), vector <int>(timeB, timeB+sizeof(timeB)/sizeof(int))); break;
			}
			/*case 5:
			{
				int timeJ[] = ;
				int timeB[] = ;
				_expected = ;
				_received = _obj.find(vector <int>(timeJ, timeJ+sizeof(timeJ)/sizeof(int)), vector <int>(timeB, timeB+sizeof(timeB)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int timeJ[] = ;
				int timeB[] = ;
				_expected = ;
				_received = _obj.find(vector <int>(timeJ, timeJ+sizeof(timeJ)/sizeof(int)), vector <int>(timeB, timeB+sizeof(timeB)/sizeof(int))); break;
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
