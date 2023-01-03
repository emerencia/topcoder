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

class Multifactorial {
 public:
  int k;
  LL rec(int n, LL sofar) {
    if (k >= n) return n;
    if ((sofar*n)/n != sofar) return -1;
    LL r = rec(n-k,sofar*n);
    if (r < 0 || (LL)(n*r)/n != r) return -1;
    return n*r;
  }
  string calcMultiFact(int n, int k) {
    this->k = k;
    LL r = rec(n,1);
    if (r < 0 || r > 1e18) return "overflow";
    stringstream a;
    a << r;
    return a.str();
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
		cout << "Testing Multifactorial (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396912339;
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
		Multifactorial _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 14;
				int k = 3;
				_expected = "12320";
				_received = _obj.calcMultiFact(n, k); break;
			}
			case 1:
			{
				int n = 5;
				int k = 4;
				_expected = "5";
				_received = _obj.calcMultiFact(n, k); break;
			}
			case 2:
			{
				int n = 1000;
				int k = 2;
				_expected = "overflow";
				_received = _obj.calcMultiFact(n, k); break;
			}
			case 3:
			{
				int n = 2000000000;
				int k = 1900000000;
				_expected = "200000000000000000";
				_received = _obj.calcMultiFact(n, k); break;
			}
			case 4:
			{
				int n = 1000;
				int k = 256;
				_expected = "84232704000";
				_received = _obj.calcMultiFact(n, k); break;
			}
			case 5:
			{
				int n = 2000000000;
				int k = 1;
				_expected = "overflow";
				_received = _obj.calcMultiFact(n, k); break;
			}
			case 6:
			{
				int n = 423332300;
				int k = 165035639;
				_expected = "overflow";
				_received = _obj.calcMultiFact(n, k); break;
			}
			/*case 7:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.calcMultiFact(n, k); break;
			}*/
			/*case 8:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.calcMultiFact(n, k); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
