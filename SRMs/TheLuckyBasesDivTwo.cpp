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

class TheLuckyBasesDivTwo {
 public:
  void factors(long long n, vector<LL>& r) {
    for (LL i=1;i*i<=n;i++)
      if (n%i == 0) {
        r.push_back(i);
        if (n/i != i)
          r.push_back(n/i);
      }
  }
  long long find(long long n) {
    if (n == 4 || n == 7) return -1;
    if (n < 8) return 0;
    vector<LL> ps;
    factors(n-4,ps);
    factors(n-7,ps);
    sort(ps.begin(),ps.end());
    ps.resize(unique(ps.begin(),ps.end())-ps.begin());
    LL r = 0;
    for (int i=0;i<ps.size();i++) {
      LL base = ps[i];
      LL m = n;
      while (m%base == 4 || m%base == 7) {
        m/=base;
      }
      r += m == 0;
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
		cout << "Testing TheLuckyBasesDivTwo (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395719276;
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
		TheLuckyBasesDivTwo _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long n = 255LL;
				_expected = 1LL;
				_received = _obj.find(n); break;
			}
			case 1:
			{
				long long n = 4LL;
				_expected = -1LL;
				_received = _obj.find(n); break;
			}
			case 2:
			{
				long long n = 13LL;
				_expected = 0LL;
				_received = _obj.find(n); break;
			}
			case 3:
			{
				long long n = 60LL;
				_expected = 2LL;
				_received = _obj.find(n); break;
			}
			/*case 4:
			{
				long long n = LL;
				_expected = LL;
				_received = _obj.find(n); break;
			}*/
			/*case 5:
			{
				long long n = LL;
				_expected = LL;
				_received = _obj.find(n); break;
			}*/
			/*case 6:
			{
				long long n = LL;
				_expected = LL;
				_received = _obj.find(n); break;
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
