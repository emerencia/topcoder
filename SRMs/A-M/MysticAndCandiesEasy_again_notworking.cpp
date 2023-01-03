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
int mem[51][2501];

class MysticAndCandiesEasy {
 public:
  int minBoxes(int C, int X, vector <int> high) {
    sort(high.rbegin(),high.rend());
    int t = 0;
    if (C == X) return high.size();
    for (int i=0;i<high.size();i++) {
      if (C-t < X) {
        return high.size()-(i-1);
      }
      t+= high[i];
    }
    return high.size();
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
	string a = tt == -1 ? "0" : string(1,'0'+tt);
	char* b[2] = {argv[0],(char*)a.c_str()};
	if(tt!=-1){argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing MysticAndCandiesEasy (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1412623405;
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
		MysticAndCandiesEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int C = 10;
				int X = 10;
				int high[] = {20};
				_expected = 1;
				_received = _obj.minBoxes(C, X, vector <int>(high, high+sizeof(high)/sizeof(int))); break;
			}
			case 1:
			{
				int C = 10;
				int X = 7;
				int high[] = {3, 3, 3, 3, 3};
				_expected = 4;
				_received = _obj.minBoxes(C, X, vector <int>(high, high+sizeof(high)/sizeof(int))); break;
			}
			case 2:
			{
				int C = 100;
				int X = 63;
				int high[] = {12, 34, 23, 45, 34};
				_expected = 3;
				_received = _obj.minBoxes(C, X, vector <int>(high, high+sizeof(high)/sizeof(int))); break;
			}
			case 3:
			{
				int C = 19;
				int X = 12;
				int high[] = {12, 9, 15, 1, 6, 4, 9, 10, 10, 10, 14, 14, 1, 1, 12, 10, 9, 2, 3, 6, 1, 7, 3, 4, 10, 3, 14};
				_expected = 22;
				_received = _obj.minBoxes(C, X, vector <int>(high, high+sizeof(high)/sizeof(int))); break;
			}
			case 4:
			{
				int C = 326;
				int X = 109;
				int high[] = {9, 13, 6, 6, 6, 16, 16, 16, 10, 16, 4, 3, 10, 8, 11, 17, 12, 5, 7, 8, 7, 4, 15, 7, 14, 2, 2, 1, 17, 1, 7, 7, 12, 17, 2, 9, 7, 1, 8, 16, 7, 4, 16, 2, 13, 3, 13, 1, 17, 6};
				_expected = 15;
				_received = _obj.minBoxes(C, X, vector <int>(high, high+sizeof(high)/sizeof(int))); break;
			}
			/*case 5:
			{
				int C = ;
				int X = ;
				int high[] = ;
				_expected = ;
				_received = _obj.minBoxes(C, X, vector <int>(high, high+sizeof(high)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int C = ;
				int X = ;
				int high[] = ;
				_expected = ;
				_received = _obj.minBoxes(C, X, vector <int>(high, high+sizeof(high)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int C = ;
				int X = ;
				int high[] = ;
				_expected = ;
				_received = _obj.minBoxes(C, X, vector <int>(high, high+sizeof(high)/sizeof(int))); break;
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
