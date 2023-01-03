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

class AntiMatter {
 public:
  int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b,a%b);
  }
  string unstable(vector <int> xform) {
    int g = 0;
    for (int i=0;i<xform.size();i++) {
      for (int j=i+1;j<xform.size();j++) {
        int val = abs(xform[i]-xform[j]);
        if (!val) continue;
        g = g ? gcd(g,val) : val;
      }
    }
    if (!g) return ".00010000";
    if (g == 1) return "1.00000000";
    LL t = 0;
    for (int i=-4999;i<=5000;i++)
      for (int j=-4999;j<=5000;j++) {
        int diff = abs(i-j);
        t+= diff%g == 0;
      }
    double r = t/1e8;
    stringstream s;
    s << fixed << setprecision(8) << r;
    return s.str().substr(1);
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
		cout << "Testing AntiMatter (850.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398675416;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 850.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AntiMatter _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int xform[] = {6,6,6,6};
				_expected = ".00010000";
				_received = _obj.unstable(vector <int>(xform, xform+sizeof(xform)/sizeof(int))); break;
			}
			case 1:
			{
				int xform[] = {1,-1,1,-1};
				_expected = ".50000000";
				_received = _obj.unstable(vector <int>(xform, xform+sizeof(xform)/sizeof(int))); break;
			}
			case 2:
			{
				int xform[] = {0,1,-1,1};
				_expected = "1.00000000";
				_received = _obj.unstable(vector <int>(xform, xform+sizeof(xform)/sizeof(int))); break;
			}
			case 3:
			{
				int xform[] = {0,0,0,792};
				_expected = ".00126448";
				_received = _obj.unstable(vector <int>(xform, xform+sizeof(xform)/sizeof(int))); break;
			}
			/*case 4:
			{
				int xform[] = ;
				_expected = ;
				_received = _obj.unstable(vector <int>(xform, xform+sizeof(xform)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int xform[] = ;
				_expected = ;
				_received = _obj.unstable(vector <int>(xform, xform+sizeof(xform)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int xform[] = ;
				_expected = ;
				_received = _obj.unstable(vector <int>(xform, xform+sizeof(xform)/sizeof(int))); break;
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
