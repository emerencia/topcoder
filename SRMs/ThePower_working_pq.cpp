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
typedef pair<LL,LL> PILL;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE

class ThePower {
 public:
  LL pw(LL x, int p) {
    LL ret = 1;
    while (p) {
      if (p%2 == 1) ret *= x;
      x *= x;
      p /= 2;
    }
    return ret;
  }
  int count(long long N) {
    priority_queue<PILL> q;
    q.push(PILL(0,N));
    while (!q.empty()) {
      PILL p = q.top(); q.pop();
      if (p.second == 1) return max(0LL,-p.first-1);
      for (int i=2;i<=60;i++) {
        double root = pow(p.second,1.0/i);
        if (root < 1) break;
        LL iroot = round(root);
        q.push(PILL(-1*(-p.first+1+(LL)abs(pw(iroot,i)-p.second)),iroot));
      }
    }
    return -1;
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
		cout << "Testing ThePower (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394553776;
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
		ThePower _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long n = 8LL;
				_expected = 2;
				_received = _obj.count(n); break;
			}
			case 1:
			{
				long long n = 1LL;
				_expected = 0;
				_received = _obj.count(n); break;
			}
			case 2:
			{
				long long n = 80LL;
				_expected = 4;
				_received = _obj.count(n); break;
			}
			case 3:
			{
				long long n = 123456789LL;
				_expected = 2566;
				_received = _obj.count(n); break;
			}
			case 4:
			{
				long long n = 101567597359932145LL;
				_expected = 66648872;
				_received = _obj.count(n); break;
			}
			/*case 5:
			{
				long long n = LL;
				_expected = ;
				_received = _obj.count(n); break;
			}*/
			/*case 6:
			{
				long long n = LL;
				_expected = ;
				_received = _obj.count(n); break;
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
