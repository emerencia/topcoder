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

class BitwiseEquations {
 public:
  long long kthPlusOrSolution(int x, int k) {
    LL xx = x;
    LL kk = k;
    LL r = 0;
    LL c = 0;
    for (int i=0;i<63;i++) {
      if (xx&(1LL<<i)) continue;
      r+=(((kk>>c)&1LL)<<i);
      c++;
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
	if(tt!=-1){char* b[2];b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}	if (argc == 1) 
	{
		cout << "Testing BitwiseEquations (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393513458;
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
		BitwiseEquations _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x = 5;
				int k = 1;
				_expected = 2LL;
				_received = _obj.kthPlusOrSolution(x, k); break;
			}
			case 1:
			{
				int x = 5;
				int k = 5;
				_expected = 18LL;
				_received = _obj.kthPlusOrSolution(x, k); break;
			}
			case 2:
			{
				int x = 10;
				int k = 3;
				_expected = 5LL;
				_received = _obj.kthPlusOrSolution(x, k); break;
			}
			case 3:
			{
				int x = 1;
				int k = 1000000000;
				_expected = 2000000000LL;
				_received = _obj.kthPlusOrSolution(x, k); break;
			}
			case 4:
			{
				int x = 1073741823;
				int k = 2000000000;
				_expected = 2147483648000000000LL;
				_received = _obj.kthPlusOrSolution(x, k); break;
			}
			/*case 5:
			{
				int x = ;
				int k = ;
				_expected = LL;
				_received = _obj.kthPlusOrSolution(x, k); break;
			}*/
			/*case 6:
			{
				int x = ;
				int k = ;
				_expected = LL;
				_received = _obj.kthPlusOrSolution(x, k); break;
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
