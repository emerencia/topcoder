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

class OlympicCandles {
 public:
  int numberOfNights(vector <int> candles) {
    int c = 0;
    while (accumulate(candles.begin(),candles.end(),0)) {
      sort(candles.rbegin(),candles.rend());
      if (candles.size() <= c) break;
      bool good = true;
      for (int i=0;i<=c;i++)
        if (candles[i]) candles[i]--;
        else {
          good = false;
          break;
        }
      if (!good) break;
      c++;
    }
    return c;
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
		cout << "Testing OlympicCandles (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1389800358;
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
		OlympicCandles _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int candles[] = {2, 2, 2};
				_expected = 3;
				_received = _obj.numberOfNights(vector <int>(candles, candles+sizeof(candles)/sizeof(int))); break;
			}
			case 1:
			{
				int candles[] = {2, 2, 2, 4};
				_expected = 4;
				_received = _obj.numberOfNights(vector <int>(candles, candles+sizeof(candles)/sizeof(int))); break;
			}
			case 2:
			{
				int candles[] = {5, 2, 2, 1};
				_expected = 3;
				_received = _obj.numberOfNights(vector <int>(candles, candles+sizeof(candles)/sizeof(int))); break;
			}
			case 3:
			{
				int candles[] = {1, 2, 3, 4, 5, 6};
				_expected = 6;
				_received = _obj.numberOfNights(vector <int>(candles, candles+sizeof(candles)/sizeof(int))); break;
			}
			case 4:
			{
				int candles[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				_expected = 4;
				_received = _obj.numberOfNights(vector <int>(candles, candles+sizeof(candles)/sizeof(int))); break;
			}
			/*case 5:
			{
				int candles[] = ;
				_expected = ;
				_received = _obj.numberOfNights(vector <int>(candles, candles+sizeof(candles)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int candles[] = ;
				_expected = ;
				_received = _obj.numberOfNights(vector <int>(candles, candles+sizeof(candles)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int candles[] = ;
				_expected = ;
				_received = _obj.numberOfNights(vector <int>(candles, candles+sizeof(candles)/sizeof(int))); break;
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
