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

class SumAndProduct {
 public:
  int smallestSet(int S, int P) {
    if (S == P) return 1;
    int c = 2;
    double s = S;
    while (c <= S && pow(s/c,c) < P) ++c;
    return (c > S ? -1 : c);
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
		cout << "Testing SumAndProduct (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393517147;
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
		SumAndProduct _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int S = 10;
				int P = 10;
				_expected = 1;
				_received = _obj.smallestSet(S, P); break;
			}
			case 1:
			{
				int S = 5;
				int P = 6;
				_expected = 2;
				_received = _obj.smallestSet(S, P); break;
			}
			case 2:
			{
				int S = 5;
				int P = 100;
				_expected = -1;
				_received = _obj.smallestSet(S, P); break;
			}
			case 3:
			{
				int S = 100;
				int P = 1000000000;
				_expected = 9;
				_received = _obj.smallestSet(S, P); break;
			}
			/*case 4:
			{
				int S = ;
				int P = ;
				_expected = ;
				_received = _obj.smallestSet(S, P); break;
			}*/
			/*case 5:
			{
				int S = ;
				int P = ;
				_expected = ;
				_received = _obj.smallestSet(S, P); break;
			}*/
			/*case 6:
			{
				int S = ;
				int P = ;
				_expected = ;
				_received = _obj.smallestSet(S, P); break;
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
