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

class EllysFractions {
 public:
  int N;
  bool isprime(int N) {
    for (int i=2;i*i<=N;i++)
      if (N%i == 0) return false;
    return true;
  }
  long long getCount(int N) {
    LL r = 0;
    int pw = 0;
    for (int i=2;i<=N;i++) {
      pw+=isprime(i);
      r+=1LL<<pw;
    }
    return r>>1;
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
		cout << "Testing EllysFractions (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397308890;
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
		EllysFractions _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 1;
				_expected = 0LL;
				_received = _obj.getCount(N); break;
			}
			case 1:
			{
				int N = 2;
				_expected = 1LL;
				_received = _obj.getCount(N); break;
			}
			case 2:
			{
				int N = 3;
				_expected = 3LL;
				_received = _obj.getCount(N); break;
			}
			case 3:
			{
				int N = 5;
				_expected = 9LL;
				_received = _obj.getCount(N); break;
			}
			case 4:
			{
				int N = 100;
				_expected = 177431885LL;
				_received = _obj.getCount(N); break;
			}
			/*case 5:
			{
				int N = ;
				_expected = LL;
				_received = _obj.getCount(N); break;
			}*/
			/*case 6:
			{
				int N = ;
				_expected = LL;
				_received = _obj.getCount(N); break;
			}*/
			/*case 7:
			{
				int N = ;
				_expected = LL;
				_received = _obj.getCount(N); break;
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
