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
int mem[51][101][51];

class BarracksEasy {
 public:
  int upr;
  int rec(int myunits, int theirunits, int barhp) {
    if (barhp <= 0 && theirunits <= 0) return 0;
    if (myunits <= 0) return 100000;
    if (theirunits > 100) return 100000;
    int& r = mem[myunits][theirunits][barhp];
    if (r != -1) return r;
    r = 100000; // stop recursion
    int t = 100000;
    if (barhp <= 0) {
      int tun = theirunits-myunits;
      int mun = myunits-tun;
      if (tun <= 0) return r = 1;
      t = min(t,1+rec(mun,tun,0));
    } else {
      for (int i=0;i<=min(theirunits,myunits);i++) {
        int tun = theirunits-i;
        int mun = myunits-tun;
        int bhp = barhp-(myunits-i);
        if (bhp <= 0 && tun <= 0) return r = 1;
        t = min(t,1+rec(mun,tun+(bhp <= 0 ? 0 : upr),bhp));
      }
    }
    return r = t;
  }
  int attack(int myUnits, int barHp, int unitsPerRound) {
    this->upr = unitsPerRound;
    memset(mem,-1,sizeof(mem));
    int r = rec(myUnits,0,barHp);
    return (r >= 100000 ? -1 : r);
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
		cout << "Testing BarracksEasy (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391469969;
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
		BarracksEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int myUnits = 10;
				int barHp = 11;
				int unitsPerRound = 15;
				_expected = 4;
				_received = _obj.attack(myUnits, barHp, unitsPerRound); break;
			}
			case 1:
			{
				int myUnits = 3;
				int barHp = 10;
				int unitsPerRound = 4;
				_expected = -1;
				_received = _obj.attack(myUnits, barHp, unitsPerRound); break;
			}
			case 2:
			{
				int myUnits = 2;
				int barHp = 10;
				int unitsPerRound = 1;
				_expected = 9;
				_received = _obj.attack(myUnits, barHp, unitsPerRound); break;
			}
			case 3:
			{
				int myUnits = 11;
				int barHp = 12;
				int unitsPerRound = 9;
				_expected = 2;
				_received = _obj.attack(myUnits, barHp, unitsPerRound); break;
			}
			case 4:
			{
				int myUnits = 5;
				int barHp = 8;
				int unitsPerRound = 5;
				_expected = 4;
				_received = _obj.attack(myUnits, barHp, unitsPerRound); break;
			}
			/*case 5:
			{
				int myUnits = ;
				int barHp = ;
				int unitsPerRound = ;
				_expected = ;
				_received = _obj.attack(myUnits, barHp, unitsPerRound); break;
			}*/
			/*case 6:
			{
				int myUnits = ;
				int barHp = ;
				int unitsPerRound = ;
				_expected = ;
				_received = _obj.attack(myUnits, barHp, unitsPerRound); break;
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
