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

class LongLongTripDiv2 {
 public:
  string isAble(long long D, int T, int B) {
    // binary search
    // how many B jumps do you need
    int l = 0;
    int r = T;
    while (l != r) {
      int m = (l+r)/2;
      LL distat = (LL)m*B + ((LL)T-m);
      if (distat >= D)
        r = m;
      else
        l = m+1;
    }
    LL distatl = (LL)l*B + ((LL)T-l);
    if (distatl != D) return "Impossible";
    return "Possible";
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
	string a = tt == -1 ? "0" : string(1,'0'+tt);
	char* b[2] = {argv[0],(char*)a.c_str()};
	if(tt!=-1){argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing LongLongTripDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1425933083;
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
		LongLongTripDiv2 _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long D = 10LL;
				int T = 6;
				int B = 3;
				_expected = "Possible";
				_received = _obj.isAble(D, T, B); break;
			}
			case 1:
			{
				long long D = 10LL;
				int T = 5;
				int B = 3;
				_expected = "Impossible";
				_received = _obj.isAble(D, T, B); break;
			}
			case 2:
			{
				long long D = 50LL;
				int T = 100;
				int B = 2;
				_expected = "Impossible";
				_received = _obj.isAble(D, T, B); break;
			}
			case 3:
			{
				long long D = 120LL;
				int T = 10;
				int B = 11;
				_expected = "Impossible";
				_received = _obj.isAble(D, T, B); break;
			}
			case 4:
			{
				long long D = 10LL;
				int T = 10;
				int B = 9999;
				_expected = "Possible";
				_received = _obj.isAble(D, T, B); break;
			}
			case 5:
			{
				long long D = 1000LL;
				int T = 100;
				int B = 10;
				_expected = "Possible";
				_received = _obj.isAble(D, T, B); break;
			}
			case 6:
			{
				long long D = 1000010000100001LL;
				int T = 1100011;
				int B = 1000000000;
				_expected = "Possible";
				_received = _obj.isAble(D, T, B); break;
			}
			/*case 7:
			{
				long long D = LL;
				int T = ;
				int B = ;
				_expected = ;
				_received = _obj.isAble(D, T, B); break;
			}*/
			/*case 8:
			{
				long long D = LL;
				int T = ;
				int B = ;
				_expected = ;
				_received = _obj.isAble(D, T, B); break;
			}*/
			/*case 9:
			{
				long long D = LL;
				int T = ;
				int B = ;
				_expected = ;
				_received = _obj.isAble(D, T, B); break;
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
