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
LL dp [2][50002][11];

class Polygons2 {
 public:
  long long number(vector <int> segments, int K) {
    sort(segments.begin(),segments.end());
    memset(dp,0,sizeof(dp));
    int cur = 0, next = 1;
    for (int i=segments.size()-1;i>=0;i--) {
      for (int s=0;s<50002;s++)
        for (int l=0;l<K;l++)
          if (l == K-1)
            dp[next][s][l] = (s > segments[i] ? 1 : 0) + dp[cur][s][l];
          else
            dp[next][s][l] = dp[cur][s][l]+dp[cur][min(s+segments[i],50001)][l+1];
      swap(cur,next);
    }
    return dp[cur][0][0];
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
		cout << "Testing Polygons2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396055805;
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
		Polygons2 _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int segments[] = {1,1,1,1};
				int K = 3;
				_expected = 4LL;
				_received = _obj.number(vector <int>(segments, segments+sizeof(segments)/sizeof(int)), K); break;
			}
			case 1:
			{
				int segments[] = {2,3,4,5};
				int K = 3;
				_expected = 3LL;
				_received = _obj.number(vector <int>(segments, segments+sizeof(segments)/sizeof(int)), K); break;
			}
			case 2:
			{
				int segments[] = {4,4,4,2,2,2};
				int K = 3;
				_expected = 11LL;
				_received = _obj.number(vector <int>(segments, segments+sizeof(segments)/sizeof(int)), K); break;
			}
			case 3:
			{
				int segments[] = {10,1,4,9,20};
				int K = 4;
				_expected = 2LL;
				_received = _obj.number(vector <int>(segments, segments+sizeof(segments)/sizeof(int)), K); break;
			}
			case 4:
			{
				int segments[] = {3310,1660,211,1260,160,213,884,539,17212,2025,105,120,5510};
				int K = 7;
				_expected = 532LL;
				_received = _obj.number(vector <int>(segments, segments+sizeof(segments)/sizeof(int)), K); break;
			}
			/*case 5:
			{
				int segments[] = ;
				int K = ;
				_expected = LL;
				_received = _obj.number(vector <int>(segments, segments+sizeof(segments)/sizeof(int)), K); break;
			}*/
			/*case 6:
			{
				int segments[] = ;
				int K = ;
				_expected = LL;
				_received = _obj.number(vector <int>(segments, segments+sizeof(segments)/sizeof(int)), K); break;
			}*/
			/*case 7:
			{
				int segments[] = ;
				int K = ;
				_expected = LL;
				_received = _obj.number(vector <int>(segments, segments+sizeof(segments)/sizeof(int)), K); break;
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
