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
map<LL,LL> mem;

class InfiniteSequence {
 public:
  LL p;
  LL q;
  long long rec(long long n) {
    if (mem.count(n)) return mem[n];
    if (n == 0) return mem[n] = 1;
    return mem[n] = rec(n/p)+rec(n/q);
  }
  long long calc(long long n, int p, int q) {
    mem.clear();
    this->p = p;
    this->q = q;
    return rec(n);
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
		cout << "Testing InfiniteSequence (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390321794;
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
		InfiniteSequence _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long n = 0LL;
				int p = 2;
				int q = 3;
				_expected = 1LL;
				_received = _obj.calc(n, p, q); break;
			}
			case 1:
			{
				long long n = 7LL;
				int p = 2;
				int q = 3;
				_expected = 7LL;
				_received = _obj.calc(n, p, q); break;
			}
			case 2:
			{
				long long n = 10000000LL;
				int p = 3;
				int q = 3;
				_expected = 32768LL;
				_received = _obj.calc(n, p, q); break;
			}
			case 3:
			{
				long long n = 256LL;
				int p = 2;
				int q = 4;
				_expected = 89LL;
				_received = _obj.calc(n, p, q); break;
			}
			case 4:
			{
				long long n = 1LL;
				int p = 1000000;
				int q = 1000000;
				_expected = 2LL;
				_received = _obj.calc(n, p, q); break;
			}
			case 5:
			{
				long long n = 10e12;
				int p = 2;
				int q = 3;
				_expected = 5LL;
				_received = _obj.calc(n, p, q); break;
			}
			/*case 6:
			{
				long long n = LL;
				int p = ;
				int q = ;
				_expected = LL;
				_received = _obj.calc(n, p, q); break;
			}*/
			/*case 7:
			{
				long long n = LL;
				int p = ;
				int q = ;
				_expected = LL;
				_received = _obj.calc(n, p, q); break;
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
