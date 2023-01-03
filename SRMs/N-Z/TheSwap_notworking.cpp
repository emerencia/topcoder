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

class TheSwap {
 public:
  int findMax(int n, int k) {
    if (n <= 10) return -1;
    bool onlyzeros = true;
    int nn = n;
    while (nn/10) {
      if (nn%10 != 0) {
        onlyzeros = false;
        break;
      }
      nn/=10;
    }
    if (onlyzeros) return -1;
    stringstream a;
    a << n;
    string b = a.str();
    for (int i=0;i<b.size();i++) {
      char mx = b[i];
      int mxi = i;
      for (int j=i+1;j<b.size();j++)
        if (b[j] >= mx) {
          mx = b[j];
          mxi = j;
        }
      if (b[i] != b[mxi]) {
        swap(b[i],b[mxi]);
        k--;
        if (!k) break;
      }
    }
    if (k%2)
      swap(b[b.size()-1],b[b.size()-2]);
    stringstream c(b);
    int r;
    c >> r;
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
		cout << "Testing TheSwap (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394552070;
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
		TheSwap _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 16375;
				int k = 1;
				_expected = 76315;
				_received = _obj.findMax(n, k); break;
			}
			case 1:
			{
				int n = 432;
				int k = 1;
				_expected = 423;
				_received = _obj.findMax(n, k); break;
			}
			case 2:
			{
				int n = 90;
				int k = 4;
				_expected = -1;
				_received = _obj.findMax(n, k); break;
			}
			case 3:
			{
				int n = 5;
				int k = 2;
				_expected = -1;
				_received = _obj.findMax(n, k); break;
			}
			case 4:
			{
				int n = 436659;
				int k = 2;
				_expected = 966354;
				_received = _obj.findMax(n, k); break;
			}
			/*case 5:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.findMax(n, k); break;
			}*/
			/*case 6:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.findMax(n, k); break;
			}*/
			/*case 7:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.findMax(n, k); break;
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
