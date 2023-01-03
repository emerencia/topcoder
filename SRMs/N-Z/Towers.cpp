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

class Towers {
 public:
  int attack(int myUnits, int hpT, int attackT, int numT) {
    int tothp = numT*hpT;
    int i = 0;
    while (myUnits > 0) {
      tothp -= myUnits;
      if (tothp <= 0) return i+1;
      myUnits -= attackT*((tothp+hpT-1)/hpT);
      i++;
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
		cout << "Testing Towers (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391469425;
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
		Towers _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int myUnits = 13;
				int hpT = 2;
				int attackT = 3;
				int numT = 8;
				_expected = 2;
				_received = _obj.attack(myUnits, hpT, attackT, numT); break;
			}
			case 1:
			{
				int myUnits = 10;
				int hpT = 6;
				int attackT = 8;
				int numT = 2;
				_expected = 2;
				_received = _obj.attack(myUnits, hpT, attackT, numT); break;
			}
			case 2:
			{
				int myUnits = 10;
				int hpT = 6;
				int attackT = 9;
				int numT = 2;
				_expected = -1;
				_received = _obj.attack(myUnits, hpT, attackT, numT); break;
			}
			case 3:
			{
				int myUnits = 1;
				int hpT = 1;
				int attackT = 1;
				int numT = 1;
				_expected = 1;
				_received = _obj.attack(myUnits, hpT, attackT, numT); break;
			}
			case 4:
			{
				int myUnits = 10000;
				int hpT = 10;
				int attackT = 2;
				int numT = 2789;
				_expected = 10;
				_received = _obj.attack(myUnits, hpT, attackT, numT); break;
			}
			case 5:
			{
				int myUnits = 2;
				int hpT = 1;
				int attackT = 1;
				int numT = 3;
				_expected = 2;
				_received = _obj.attack(myUnits, hpT, attackT, numT); break;
			}
			/*case 6:
			{
				int myUnits = ;
				int hpT = ;
				int attackT = ;
				int numT = ;
				_expected = ;
				_received = _obj.attack(myUnits, hpT, attackT, numT); break;
			}*/
			/*case 7:
			{
				int myUnits = ;
				int hpT = ;
				int attackT = ;
				int numT = ;
				_expected = ;
				_received = _obj.attack(myUnits, hpT, attackT, numT); break;
			}*/
			/*case 8:
			{
				int myUnits = ;
				int hpT = ;
				int attackT = ;
				int numT = ;
				_expected = ;
				_received = _obj.attack(myUnits, hpT, attackT, numT); break;
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
