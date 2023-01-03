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

class TheCardShufflingDivTwo {
 public:
  int shuffle(int n, int m) {
    if (n == 1) return 1;
    int r = 1;
    int fac = 1;
    int mod = (n+(1-(n%2)));
    // there are only 2s in here, so this sum will only ever be divisible by n
    for (int i=0;i<m;i++) {
      (r += fac)%=mod;
      (fac *= 2)%=mod;
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
	char* b[2];
	if(tt!=-1){b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing TheCardShufflingDivTwo (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396528508;
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
		TheCardShufflingDivTwo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 5;
				int m = 1;
				_expected = 2;
				_received = _obj.shuffle(n, m); break;
			}
			case 1:
			{
				int n = 5;
				int m = 2;
				_expected = 4;
				_received = _obj.shuffle(n, m); break;
			}
			case 2:
			{
				int n = 2;
				int m = 10;
				_expected = 1;
				_received = _obj.shuffle(n, m); break;
			}
			case 3:
			{
				int n = 17;
				int m = 9;
				_expected = 2;
				_received = _obj.shuffle(n, m); break;
			}
			case 4:
			{
				int n = 10;
				int m = 3;
				_expected = 8;
				_received = _obj.shuffle(n, m); break;
			}
			case 5:
			{
				int n = 10;
				int m = 4;
				_expected = 5;
				_received = _obj.shuffle(n, m); break;
			}
			case 6:
			{
				int n = 10;
				int m = 5;
				_expected = 10;
				_received = _obj.shuffle(n, m); break;
			}
      case 7:
			{
				int n = 1;
				int m = 3;
				_expected = 1;
				_received = _obj.shuffle(n, m); break;
			}
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
