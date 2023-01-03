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

class TheAlmostLuckyNumbersDivTwo {
 public:
  int find(int a, int b) {
    int r = 0;
    for (int i=a;i<=b;i++) {
      int c = 0;
      int j = i;
      while (j) {
        c+=(j%10 != 7 && j%10 != 4);
        j/=10;
      }
      r+= c<=1;
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
		cout << "Testing TheAlmostLuckyNumbersDivTwo (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395715843;
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
		TheAlmostLuckyNumbersDivTwo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a = 4;
				int b = 7;
				_expected = 4;
				_received = _obj.find(a, b); break;
			}
			case 1:
			{
				int a = 8;
				int b = 19;
				_expected = 4;
				_received = _obj.find(a, b); break;
			}
			case 2:
			{
				int a = 28;
				int b = 33;
				_expected = 0;
				_received = _obj.find(a, b); break;
			}
			case 3:
			{
				int a = 1234;
				int b = 4321;
				_expected = 36;
				_received = _obj.find(a, b); break;
			}
			/*case 4:
			{
				int a = ;
				int b = ;
				_expected = ;
				_received = _obj.find(a, b); break;
			}*/
			/*case 5:
			{
				int a = ;
				int b = ;
				_expected = ;
				_received = _obj.find(a, b); break;
			}*/
			/*case 6:
			{
				int a = ;
				int b = ;
				_expected = ;
				_received = _obj.find(a, b); break;
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
