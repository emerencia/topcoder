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

class NextNumber {
 public:
  int getNextNumber(int N) {
    int c = 0;
    for (int i=0;i<30;i++) {
      if ((N&(1<<i)) && !(N&(1<<(i+1))))
        return (N & ~((1<<i)-1)) ^ (1<<i) ^ (1<<(i+1)) ^ ((1<<c)-1);
      if (N&(1<<i)) ++c;
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
		cout << "Testing NextNumber (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390590620;
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
		NextNumber _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 1717;
				_expected = 1718;
				_received = _obj.getNextNumber(N); break;
			}
			case 1:
			{
				int N = 4;
				_expected = 8;
				_received = _obj.getNextNumber(N); break;
			}
			case 2:
			{
				int N = 7;
				_expected = 11;
				_received = _obj.getNextNumber(N); break;
			}
			case 3:
			{
				int N = 12;
				_expected = 17;
				_received = _obj.getNextNumber(N); break;
			}
			case 4:
			{
				int N = 555555;
				_expected = 555557;
				_received = _obj.getNextNumber(N); break;
			}
			/*case 5:
			{
				int N = ;
				_expected = ;
				_received = _obj.getNextNumber(N); break;
			}*/
			/*case 6:
			{
				int N = ;
				_expected = ;
				_received = _obj.getNextNumber(N); break;
			}*/
			/*case 7:
			{
				int N = ;
				_expected = ;
				_received = _obj.getNextNumber(N); break;
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
