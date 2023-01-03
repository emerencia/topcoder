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
typedef pair<string,int> PSI;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE
map<PSI,int> mem;

class TheSwap {
 public:
  int rec(string& s, int left) {
    PSI p = PSI(s,left);
    if (mem.count(p)) return mem[p];
    if (left == 0) {
      stringstream a(s);
      int b;
      a >> b;
      return mem[p] = b;
    }
    int t = 0;
    for (int i=0;i<s.size();i++)
      for (int j=i+1;j<s.size();j++) {
        if (i == 0 && s[j] == '0') continue;
        swap(s[i],s[j]);
        t = max(t,rec(s,left-1));
        swap(s[i],s[j]);
      }
    return mem[p] = t;
  }
  int findMax(int n, int k) {
    if (n <= 10 || (n < 100 && n%10 == 0)) return -1;
    stringstream a;
    a << n;
    string b = a.str();
    return rec(b,k);
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
