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

class RoadOrFlightEasy {
 public:
  int minTime(int N, vector <int> roadTime, vector <int> flightTime, int K) {
    vector<int> diffs;
    for (int i=0;i<N;i++)
      diffs.push_back(roadTime[i]-flightTime[i]);
    sort(diffs.rbegin(),diffs.rend());
    int r = accumulate(roadTime.begin(),roadTime.end(),0);
    for (int i=0;i<diffs.size();i++) {
      if (i == K || diffs[i] < 0) break;
      r -= diffs[i];
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
		cout << "Testing RoadOrFlightEasy (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1407353351;
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
		RoadOrFlightEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int roadTime[] = {4, 6, 7};
				int flightTime[] = {1, 2, 3};
				int K = 1;
				_expected = 13;
				_received = _obj.minTime(N, vector <int>(roadTime, roadTime+sizeof(roadTime)/sizeof(int)), vector <int>(flightTime, flightTime+sizeof(flightTime)/sizeof(int)), K); break;
			}
			case 1:
			{
				int N = 3;
				int roadTime[] = {4, 6, 7};
				int flightTime[] = {1, 2, 3};
				int K = 2;
				_expected = 9;
				_received = _obj.minTime(N, vector <int>(roadTime, roadTime+sizeof(roadTime)/sizeof(int)), vector <int>(flightTime, flightTime+sizeof(flightTime)/sizeof(int)), K); break;
			}
			case 2:
			{
				int N = 3;
				int roadTime[] = {4, 6, 7};
				int flightTime[] = {1, 2, 3};
				int K = 3;
				_expected = 6;
				_received = _obj.minTime(N, vector <int>(roadTime, roadTime+sizeof(roadTime)/sizeof(int)), vector <int>(flightTime, flightTime+sizeof(flightTime)/sizeof(int)), K); break;
			}
			case 3:
			{
				int N = 3;
				int roadTime[] = {1, 2, 3};
				int flightTime[] = {2, 3, 4};
				int K = 2;
				_expected = 6;
				_received = _obj.minTime(N, vector <int>(roadTime, roadTime+sizeof(roadTime)/sizeof(int)), vector <int>(flightTime, flightTime+sizeof(flightTime)/sizeof(int)), K); break;
			}
			case 4:
			{
				int N = 7;
				int roadTime[] = {50, 287, 621, 266, 224, 68, 636};
				int flightTime[] = {797, 661, 644, 102, 114, 452, 420};
				int K = 2;
				_expected = 1772;
				_received = _obj.minTime(N, vector <int>(roadTime, roadTime+sizeof(roadTime)/sizeof(int)), vector <int>(flightTime, flightTime+sizeof(flightTime)/sizeof(int)), K); break;
			}
			/*case 5:
			{
				int N = ;
				int roadTime[] = ;
				int flightTime[] = ;
				int K = ;
				_expected = ;
				_received = _obj.minTime(N, vector <int>(roadTime, roadTime+sizeof(roadTime)/sizeof(int)), vector <int>(flightTime, flightTime+sizeof(flightTime)/sizeof(int)), K); break;
			}*/
			/*case 6:
			{
				int N = ;
				int roadTime[] = ;
				int flightTime[] = ;
				int K = ;
				_expected = ;
				_received = _obj.minTime(N, vector <int>(roadTime, roadTime+sizeof(roadTime)/sizeof(int)), vector <int>(flightTime, flightTime+sizeof(flightTime)/sizeof(int)), K); break;
			}*/
			/*case 7:
			{
				int N = ;
				int roadTime[] = ;
				int flightTime[] = ;
				int K = ;
				_expected = ;
				_received = _obj.minTime(N, vector <int>(roadTime, roadTime+sizeof(roadTime)/sizeof(int)), vector <int>(flightTime, flightTime+sizeof(flightTime)/sizeof(int)), K); break;
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
