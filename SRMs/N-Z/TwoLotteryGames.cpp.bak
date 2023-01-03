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

class TwoLotteryGames {
 public:
  int bitcount (int n) {
    int r = 0;
    for (int i=n;i;i&=i-1) ++r;
    return r;
  }
  double getHigherChanceGame(int n, int m, int k) {
    LL tot = 0;
    LL win = 0;
    for (int i=0;i<(1<<n);i++) {
      if (bitcount(i) != m) continue;
      for (int j=0;j<(1<<n);j++) {
        if (bitcount(j) != m) continue;
        if (bitcount(i&j) >= k) win++;
        tot++;
      }
    }
    return win/double(tot);
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
		cout << "Testing TwoLotteryGames (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391307230;
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
		TwoLotteryGames _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				int m = 2;
				int k = 1;
				_expected = 1.0;
				_received = _obj.getHigherChanceGame(n, m, k); break;
			}
			case 1:
			{
				int n = 3;
				int m = 1;
				int k = 1;
				_expected = 0.3333333333333333;
				_received = _obj.getHigherChanceGame(n, m, k); break;
			}
			case 2:
			{
				int n = 8;
				int m = 2;
				int k = 1;
				_expected = 0.4642857142857143;
				_received = _obj.getHigherChanceGame(n, m, k); break;
			}
			case 3:
			{
				int n = 8;
				int m = 4;
				int k = 2;
				_expected = 0.7571428571428571;
				_received = _obj.getHigherChanceGame(n, m, k); break;
			}
			/*case 4:
			{
				int n = ;
				int m = ;
				int k = ;
				_expected = ;
				_received = _obj.getHigherChanceGame(n, m, k); break;
			}*/
			/*case 5:
			{
				int n = ;
				int m = ;
				int k = ;
				_expected = ;
				_received = _obj.getHigherChanceGame(n, m, k); break;
			}*/
			/*case 6:
			{
				int n = ;
				int m = ;
				int k = ;
				_expected = ;
				_received = _obj.getHigherChanceGame(n, m, k); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
