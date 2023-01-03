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

class ReverseMagicalSource {
 public:
  int find(int source, int A) {
    int r = source;
    while (r <= A) {
      source*=10;
      r+=source;
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
	char* b[2];
	if(tt!=-1){b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing ReverseMagicalSource (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397743501;
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
		ReverseMagicalSource _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int source = 19;
				int A = 200;
				_expected = 209;
				_received = _obj.find(source, A); break;
			}
			case 1:
			{
				int source = 19;
				int A = 18;
				_expected = 19;
				_received = _obj.find(source, A); break;
			}
			case 2:
			{
				int source = 333;
				int A = 36963;
				_expected = 369963;
				_received = _obj.find(source, A); break;
			}
			case 3:
			{
				int source = 1234;
				int A = 1000000;
				_expected = 1370974;
				_received = _obj.find(source, A); break;
			}
			/*case 4:
			{
				int source = ;
				int A = ;
				_expected = ;
				_received = _obj.find(source, A); break;
			}*/
			/*case 5:
			{
				int source = ;
				int A = ;
				_expected = ;
				_received = _obj.find(source, A); break;
			}*/
			/*case 6:
			{
				int source = ;
				int A = ;
				_expected = ;
				_received = _obj.find(source, A); break;
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
