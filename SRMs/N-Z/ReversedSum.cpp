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

class ReversedSum {
 public:
  int rev(int n) {
    int r = n%10;
    while (n/10) {
      r*=10;
      n/=10;
      r+=n%10;
    }
    return r;
  }
  int getReversedSum(int x, int y) {
    return rev(rev(x)+rev(y));
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
		cout << "Testing ReversedSum (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390939555;
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
		ReversedSum _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x = 123;
				int y = 100;
				_expected = 223;
				_received = _obj.getReversedSum(x, y); break;
			}
			case 1:
			{
				int x = 111;
				int y = 111;
				_expected = 222;
				_received = _obj.getReversedSum(x, y); break;
			}
			case 2:
			{
				int x = 5;
				int y = 5;
				_expected = 1;
				_received = _obj.getReversedSum(x, y); break;
			}
			case 3:
			{
				int x = 1000;
				int y = 1;
				_expected = 2;
				_received = _obj.getReversedSum(x, y); break;
			}
			case 4:
			{
				int x = 456;
				int y = 789;
				_expected = 1461;
				_received = _obj.getReversedSum(x, y); break;
			}
			/*case 5:
			{
				int x = ;
				int y = ;
				_expected = ;
				_received = _obj.getReversedSum(x, y); break;
			}*/
			/*case 6:
			{
				int x = ;
				int y = ;
				_expected = ;
				_received = _obj.getReversedSum(x, y); break;
			}*/
			/*case 7:
			{
				int x = ;
				int y = ;
				_expected = ;
				_received = _obj.getReversedSum(x, y); break;
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
