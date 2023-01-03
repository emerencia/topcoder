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

class TheSoccerDivTwo {
 public:
  int find(vector <int> points) {
    vector<int> npoints;
    for (int i=1;i<points.size();i++)
      npoints.push_back(points[i]);
    sort(npoints.rbegin(),npoints.rend());
    vector<bool> done(npoints.size(),false);
    int last = 0;
    for (int i=0;i<npoints.size();i++) {
      if (npoints[i] <= points[0]+3) {
        last = i;
        break;
      }
    }
    done[last] = true;
    for (int i=0;i<npoints.size();i++) {
      if (done[i]) continue;
      if (npoints[i] > points[0]+3) {
        // it will always be bigger, so let it win
        int next = -1;
        for (int j=i+1;j<npoints.size();j++) {
          if (done[j]) continue;
          next = j;
          if (npoints[next] <= points[0]+3) break;
        }
        npoints[i]+=3;
        done[i] = true;
        done[next] = true;
        continue;
      }
      if (npoints[i] == points[0]+3) {
        // try to let it lose if possible
        int next = -1;
        for (int j=npoints.size()-1;j>=i+1;j--) {
          if (done[j]) continue;
          next = j;
          if (npoints[next]+3 <= points[0]+3) break;
        }
        npoints[next]+=3;
        done[i] = true;
        done[next] = true;
        continue;
      }
      if (npoints[i] < points[0]+3) {
        // find smallest free and both +1
        int next = -1;
        for (int j=i+1;j<npoints.size();j++) {
          if (done[j]) continue;
          next = j;
          if (npoints[next] < points[0]+3) break;
          //break;
        }
        npoints[i]++;
        npoints[next]++;
        done[i] = true;
        done[next] = true;
        continue;
      }
    }
    sort(npoints.rbegin(),npoints.rend());
    int i = 0;
    while (i < npoints.size() && npoints[i] > points[0]+3)
      ++i;
    return i+1;
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
