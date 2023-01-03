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

class TheShuttles {
 public:
  int getLeastCost(vector <int> cnt, int baseCost, int seatCost) {
    int mn = INT_MAX;
    for (int i=1;i<=100;i++) {
      int tmn = 0;
      for (int j=0;j<cnt.size();j++)
        tmn+=((cnt[j]+i-1)/i)*(baseCost+seatCost*i);
      mn = min(mn,tmn);
    }
    return mn;
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
		cout << "Testing TheShuttles (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390839745;
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
		TheShuttles _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int cnt[] = {9};
				int baseCost = 30;
				int seatCost = 5;
				_expected = 75;
				_received = _obj.getLeastCost(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int)), baseCost, seatCost); break;
			}
			case 1:
			{
				int cnt[] = {9, 4};
				int baseCost = 30;
				int seatCost = 5;
				_expected = 150;
				_received = _obj.getLeastCost(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int)), baseCost, seatCost); break;
			}
			case 2:
			{
				int cnt[] = {9, 4};
				int baseCost = 10;
				int seatCost = 5;
				_expected = 105;
				_received = _obj.getLeastCost(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int)), baseCost, seatCost); break;
			}
			case 3:
			{
				int cnt[] = {51, 1, 77, 14, 17, 10, 80};
				int baseCost = 32;
				int seatCost = 40;
				_expected = 12096;
				_received = _obj.getLeastCost(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int)), baseCost, seatCost); break;
			}
			/*case 4:
			{
				int cnt[] = ;
				int baseCost = ;
				int seatCost = ;
				_expected = ;
				_received = _obj.getLeastCost(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int)), baseCost, seatCost); break;
			}*/
			/*case 5:
			{
				int cnt[] = ;
				int baseCost = ;
				int seatCost = ;
				_expected = ;
				_received = _obj.getLeastCost(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int)), baseCost, seatCost); break;
			}*/
			/*case 6:
			{
				int cnt[] = ;
				int baseCost = ;
				int seatCost = ;
				_expected = ;
				_received = _obj.getLeastCost(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int)), baseCost, seatCost); break;
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
