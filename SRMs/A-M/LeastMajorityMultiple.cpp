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

class LeastMajorityMultiple {
 public:
  int leastMajorityMultiple(int a, int b, int c, int d, int e) {
    vector<int> ints;
    ints.push_back(a);
    ints.push_back(b);
    ints.push_back(c);
    ints.push_back(d);
    ints.push_back(e);
    for (int i=1;i<=1000000;i++) {
      int c = 0;
      for (int j=0;j<ints.size();j++)
        if (i%ints[j] == 0)
          c++;
      if (c >= 3) return i;
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
		cout << "Testing LeastMajorityMultiple (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393945609;
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
		LeastMajorityMultiple _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a = 1;
				int b = 2;
				int c = 3;
				int d = 4;
				int e = 5;
				_expected = 4;
				_received = _obj.leastMajorityMultiple(a, b, c, d, e); break;
			}
			case 1:
			{
				int a = 30;
				int b = 42;
				int c = 70;
				int d = 35;
				int e = 90;
				_expected = 210;
				_received = _obj.leastMajorityMultiple(a, b, c, d, e); break;
			}
			case 2:
			{
				int a = 30;
				int b = 45;
				int c = 23;
				int d = 26;
				int e = 56;
				_expected = 1170;
				_received = _obj.leastMajorityMultiple(a, b, c, d, e); break;
			}
			case 3:
			{
				int a = 3;
				int b = 14;
				int c = 15;
				int d = 92;
				int e = 65;
				_expected = 195;
				_received = _obj.leastMajorityMultiple(a, b, c, d, e); break;
			}
			/*case 4:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				int e = ;
				_expected = ;
				_received = _obj.leastMajorityMultiple(a, b, c, d, e); break;
			}*/
			/*case 5:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				int e = ;
				_expected = ;
				_received = _obj.leastMajorityMultiple(a, b, c, d, e); break;
			}*/
			/*case 6:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				int e = ;
				_expected = ;
				_received = _obj.leastMajorityMultiple(a, b, c, d, e); break;
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
