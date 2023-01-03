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

class WinterAndCandies {
 public:
  int getNumber(vector <int> type) {
    vector<int> counts(51,0);
    for (int i=0;i<type.size();i++)
      counts[type[i]]++;
    long long r = 0;
    for (int i=1;i<=50;i++) {
      LL t = 1;
      if (counts[i] == 0)
        break;
      for (int j=1;j<=i;j++)
        t*=counts[j];
      r+=t;
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
		cout << "Testing WinterAndCandies (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391205867;
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
		WinterAndCandies _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int type[] = {1, 3, 2};
				_expected = 3;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int))); break;
			}
			case 1:
			{
				int type[] = {1, 1, 2};
				_expected = 4;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int))); break;
			}
			case 2:
			{
				int type[] = {1, 3, 2, 5, 7, 4, 5, 4};
				_expected = 9;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int))); break;
			}
			case 3:
			{
				int type[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
				_expected = 62;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int))); break;
			}
			case 4:
			{
				int type[] = {2};
				_expected = 0;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int))); break;
			}
			/*case 5:
			{
				int type[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int type[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int type[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int))); break;
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
