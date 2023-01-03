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

class BestView {
 public:
  bool left_of_line(const PII& p, const PII& from, const PII& to) {
    LL d = ((LL)to.first-from.first)*(p.second -from.second) -
    ((LL)to.second-from.second)*(p.first - from.first);
    return d>=0;
  }
  int numberOfBuildings(vector <int> heights) {
    vector<PII> points;
    for (int i=0;i<heights.size();i++)
      points.push_back(PII(i,heights[i]));
    int mx = 0;
    for (int i=0;i<points.size();i++) {
      PII from = points[i];
      int cur = 0;
      for (int j=i+1;j<points.size();j++) {
        PII to = points[j];
        bool good = true;
         for (int k=i+1;k<j;k++)
          if (left_of_line(points[k],from,to)) {
            good = false;
            break;
          }
        cur += good;
      }
      for (int j=i-1;j>=0;j--) {
        PII to = points[j];
        bool good = true;
         for (int k=i-1;k>j;k--)
          if (left_of_line(points[k],to,from)) {
            good = false;
            break;
          }
        cur += good;
      }
      mx = max(mx,cur);
    }
    return mx;
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
		cout << "Testing BestView (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394472048;
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
		BestView _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int heights[] = {10};
				_expected = 0;
				_received = _obj.numberOfBuildings(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			case 1:
			{
				int heights[] = {5,5,5,5};
				_expected = 2;
				_received = _obj.numberOfBuildings(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			case 2:
			{
				int heights[] = {1,2,7,3,2};
				_expected = 4;
				_received = _obj.numberOfBuildings(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			case 3:
			{
				int heights[] = {1,5,3,2,6,3,2,6,4,2,5,7,3,1,5};
				_expected = 7;
				_received = _obj.numberOfBuildings(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			case 4:
			{
				int heights[] = {1000000000,999999999,999999998,999999997,999999996,1,2,3,4,5};
				_expected = 6;
				_received = _obj.numberOfBuildings(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			case 5:
			{
				int heights[] = {244645169,956664793,752259473,577152868,605440232,569378507,111664772,653430457,454612157,397154317};
				_expected = 7;
				_received = _obj.numberOfBuildings(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			/*case 6:
			{
				int heights[] = ;
				_expected = ;
				_received = _obj.numberOfBuildings(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int heights[] = ;
				_expected = ;
				_received = _obj.numberOfBuildings(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int heights[] = ;
				_expected = ;
				_received = _obj.numberOfBuildings(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
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
