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
int luckysofar[4748];

class TheLuckyGameDivTwo {
 public:
  void rec(int n) {
    if (n && n < 4748) luckysofar[n] = 1;
    if (n < 4748) {
      rec(10*n+4);
      rec(10*n+7);
    }
  }
  int find(int a, int b, int jLen, int bLen) {
    memset(luckysofar,0,sizeof(luckysofar));
    rec(0);
    for (int i=1;i<4748;i++)
      luckysofar[i] += luckysofar[i-1];
    int rmx = 0;
    for (int i=a;i+jLen-1<=b;i++) {
      int mn = INT_MAX;
      for (int j=i;j+bLen<=i+jLen;j++)
        mn = min(mn,luckysofar[j+bLen-1]-luckysofar[j-1]);
      rmx = max(rmx,mn);
    }
    return rmx;
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
		cout << "Testing TheLuckyGameDivTwo (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395716023;
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
		TheLuckyGameDivTwo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a = 1;
				int b = 10;
				int jLen = 2;
				int bLen = 1;
				_expected = 0;
				_received = _obj.find(a, b, jLen, bLen); break;
			}
			case 1:
			{
				int a = 1;
				int b = 100;
				int jLen = 100;
				int bLen = 100;
				_expected = 6;
				_received = _obj.find(a, b, jLen, bLen); break;
			}
			case 2:
			{
				int a = 4;
				int b = 8;
				int jLen = 3;
				int bLen = 2;
				_expected = 1;
				_received = _obj.find(a, b, jLen, bLen); break;
			}
			case 3:
			{
				int a = 1;
				int b = 100;
				int jLen = 75;
				int bLen = 50;
				_expected = 2;
				_received = _obj.find(a, b, jLen, bLen); break;
			}
			/*case 4:
			{
				int a = ;
				int b = ;
				int jLen = ;
				int bLen = ;
				_expected = ;
				_received = _obj.find(a, b, jLen, bLen); break;
			}*/
			/*case 5:
			{
				int a = ;
				int b = ;
				int jLen = ;
				int bLen = ;
				_expected = ;
				_received = _obj.find(a, b, jLen, bLen); break;
			}*/
			/*case 6:
			{
				int a = ;
				int b = ;
				int jLen = ;
				int bLen = ;
				_expected = ;
				_received = _obj.find(a, b, jLen, bLen); break;
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
