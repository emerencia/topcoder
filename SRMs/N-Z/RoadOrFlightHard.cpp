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
// start at 02:46
// done  at 03:17
// END CUT HERE
LL dp[2][2][41];

class RoadOrFlightHard {
 public:
  long long minTime(int N, int roadFirst, int roadProd, int roadAdd, int roadMod, int flightFirst, int flightProd, int flightAdd, int flightMod, int K) {
    vector<int> roadTime;
    roadTime.push_back(roadFirst%roadMod);
    for (int i=0;i+1<N;i++)
      roadTime.push_back(((LL)roadTime[i]*roadProd + roadAdd)%roadMod);
    vector<int> flightTime;
    flightTime.push_back(flightFirst%flightMod);
    for (int i=0;i+1<N;i++)
      flightTime.push_back(((LL)flightTime[i]*flightProd + flightAdd)%flightMod);
    // dp problem
    memset(dp,-1,sizeof(dp));
    int cur = 0,next = 1;
    dp[cur][0][K] = 0;
    for (int i=0;i<N;i++) {
      memset(dp[next],-1,sizeof(dp[next]));
      for (int f=0;f<2;f++) {
        for (int k=0;k<=K;k++) {
          LL t = LLONG_MAX;
          if (f) {
            if (k < K && dp[cur][0][k+1] != -1 && dp[cur][1][k] != -1) {
              t = min(t,min(dp[cur][0][k+1],dp[cur][1][k])+flightTime[i]);
            } else if (k < K && dp[cur][0][k+1] != -1) {
              t = min(t,dp[cur][0][k+1]+flightTime[i]);
            } else if (dp[cur][1][k] != -1) {
              t = min(t,dp[cur][1][k]+flightTime[i]);
            }
          } else {
            if (dp[cur][0][k] != -1 && dp[cur][1][k] != -1) {
              t = min(t,min(dp[cur][0][k],dp[cur][1][k])+roadTime[i]);
            } else if (dp[cur][0][k] != -1) {
              t = min(t,dp[cur][0][k]+roadTime[i]);
            } else if (dp[cur][1][k] != -1) {
              t = min(t,dp[cur][1][k]+roadTime[i]);
            }
          }
          dp[next][f][k] = (t == LLONG_MAX ? -1 : t);
        }
      }
      swap(cur,next);
    }
    LL r = LLONG_MAX;
    for (int i=0;i<=K;i++)
      for (int f = 0;f<2;f++)
        if (dp[cur][f][i] != -1)
          r = min(r,dp[cur][f][i]);
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
		cout << "Testing RoadOrFlightHard (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1407631586;
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
		RoadOrFlightHard _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int roadFirst = 14;
				int roadProd = 1;
				int roadAdd = 2;
				int roadMod = 10;
				int flightFirst = 18;
				int flightProd = 1;
				int flightAdd = 10;
				int flightMod = 17;
				int K = 1;
				_expected = 14LL;
				_received = _obj.minTime(N, roadFirst, roadProd, roadAdd, roadMod, flightFirst, flightProd, flightAdd, flightMod, K); break;
			}
			case 1:
			{
				int N = 3;
				int roadFirst = 4;
				int roadProd = 1;
				int roadAdd = 2;
				int roadMod = 10;
				int flightFirst = 1;
				int flightProd = 1;
				int flightAdd = 10;
				int flightMod = 17;
				int K = 2;
				_expected = 11LL;
				_received = _obj.minTime(N, roadFirst, roadProd, roadAdd, roadMod, flightFirst, flightProd, flightAdd, flightMod, K); break;
			}
			case 2:
			{
				int N = 3;
				int roadFirst = 4;
				int roadProd = 1;
				int roadAdd = 2;
				int roadMod = 10;
				int flightFirst = 1;
				int flightProd = 1;
				int flightAdd = 6;
				int flightMod = 9;
				int K = 1;
				_expected = 12LL;
				_received = _obj.minTime(N, roadFirst, roadProd, roadAdd, roadMod, flightFirst, flightProd, flightAdd, flightMod, K); break;
			}
			case 3:
			{
				int N = 5;
				int roadFirst = 85739;
				int roadProd = 94847;
				int roadAdd = 93893;
				int roadMod = 98392;
				int flightFirst = 92840;
				int flightProd = 93802;
				int flightAdd = 93830;
				int flightMod = 92790;
				int K = 3;
				_expected = 122365LL;
				_received = _obj.minTime(N, roadFirst, roadProd, roadAdd, roadMod, flightFirst, flightProd, flightAdd, flightMod, K); break;
			}
			/*case 4:
			{
				int N = ;
				int roadFirst = ;
				int roadProd = ;
				int roadAdd = ;
				int roadMod = ;
				int flightFirst = ;
				int flightProd = ;
				int flightAdd = ;
				int flightMod = ;
				int K = ;
				_expected = LL;
				_received = _obj.minTime(N, roadFirst, roadProd, roadAdd, roadMod, flightFirst, flightProd, flightAdd, flightMod, K); break;
			}*/
			/*case 5:
			{
				int N = ;
				int roadFirst = ;
				int roadProd = ;
				int roadAdd = ;
				int roadMod = ;
				int flightFirst = ;
				int flightProd = ;
				int flightAdd = ;
				int flightMod = ;
				int K = ;
				_expected = LL;
				_received = _obj.minTime(N, roadFirst, roadProd, roadAdd, roadMod, flightFirst, flightProd, flightAdd, flightMod, K); break;
			}*/
			/*case 6:
			{
				int N = ;
				int roadFirst = ;
				int roadProd = ;
				int roadAdd = ;
				int roadMod = ;
				int flightFirst = ;
				int flightProd = ;
				int flightAdd = ;
				int flightMod = ;
				int K = ;
				_expected = LL;
				_received = _obj.minTime(N, roadFirst, roadProd, roadAdd, roadMod, flightFirst, flightProd, flightAdd, flightMod, K); break;
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
