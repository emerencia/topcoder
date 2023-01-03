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
const int kMod = 1e9+7;

class RabbitNumbering {
 public:
  int theCount(vector <int> maxNumber) {
    sort(maxNumber.begin(),maxNumber.end());
    LL r = maxNumber[0];
    for (int i=1;i<maxNumber.size();i++) {
      if (maxNumber[i]-i <= 0) return 0;
      (r*=maxNumber[i]-i)%=kMod;
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
	string a = tt == -1 ? "0" : string(1,'0'+tt);
	char* b[2] = {argv[0],(char*)a.c_str()};
	if(tt!=-1){argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing RabbitNumbering (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1401374706;
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
		RabbitNumbering _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int bunnies[] = {5};
				_expected = 5;
				_received = _obj.theCount(vector <int>(bunnies, bunnies+sizeof(bunnies)/sizeof(int))); break;
			}
			case 1:
			{
				int bunnies[] = {4,4,4,4};
				_expected = 24;
				_received = _obj.theCount(vector <int>(bunnies, bunnies+sizeof(bunnies)/sizeof(int))); break;
			}
			case 2:
			{
				int bunnies[] = {5,8};
				_expected = 35;
				_received = _obj.theCount(vector <int>(bunnies, bunnies+sizeof(bunnies)/sizeof(int))); break;
			}
			case 3:
			{
				int bunnies[] = {2,1,2};
				_expected = 0;
				_received = _obj.theCount(vector <int>(bunnies, bunnies+sizeof(bunnies)/sizeof(int))); break;
			}
			case 4:
			{
				int bunnies[] = {25, 489, 76, 98, 704, 98, 768, 39, 697, 8, 56, 74, 36, 95, 87, 2, 968, 4, 920, 54, 873, 90};
				_expected = 676780400;
				_received = _obj.theCount(vector <int>(bunnies, bunnies+sizeof(bunnies)/sizeof(int))); break;
			}
			/*case 5:
			{
				int bunnies[] = ;
				_expected = ;
				_received = _obj.theCount(vector <int>(bunnies, bunnies+sizeof(bunnies)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int bunnies[] = ;
				_expected = ;
				_received = _obj.theCount(vector <int>(bunnies, bunnies+sizeof(bunnies)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int bunnies[] = ;
				_expected = ;
				_received = _obj.theCount(vector <int>(bunnies, bunnies+sizeof(bunnies)/sizeof(int))); break;
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
