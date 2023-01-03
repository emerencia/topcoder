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

class TheLockDivTwo {
 public:
  string password(int n, int k) {
    vector<bool> used(1<<n,false);
    int cur = 0;
    for (int i=0;i<k;i++)
      for (int j=0;j<used.size();j++) {
        if (used[j]) continue;
        // one has to be a subset of the other
        if ((j&cur) == cur || (j&cur) == j) {
          used[j] = true;
          cur = j;
          break;
        }
      }
    string r;
    for (int j=n-1;j>=0;j--)
      r+=(cur&(1<<j) ? '1' : '0');
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
		cout << "Testing TheLockDivTwo (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396153188;
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
		TheLockDivTwo _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int k = 4;
				_expected = "10";
				_received = _obj.password(n, k); break;
			}
			case 1:
			{
				int n = 4;
				int k = 6;
				_expected = "0100";
				_received = _obj.password(n, k); break;
			}
			case 2:
			{
				int n = 10;
				int k = 1;
				_expected = "0000000000";
				_received = _obj.password(n, k); break;
			}
			case 3:
			{
				int n = 7;
				int k = 100;
				_expected = "1100001";
				_received = _obj.password(n, k); break;
			}
			/*case 4:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.password(n, k); break;
			}*/
			/*case 5:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.password(n, k); break;
			}*/
			/*case 6:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.password(n, k); break;
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
