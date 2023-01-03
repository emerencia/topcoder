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
const int INF = 1e9;

class EnemyTowers {
 public:
  int hpT, attackT;
  bool is_possible(int hp, int units, int rounds) {
    for (int i=0;i<rounds;i++) {
      if (hp == 0) return true;
      if (units == 0) return false;
      hp = max(0,hp-units);
      int nr = (hp+hpT-1)/hpT;
      units = max(0,units-attackT*nr);
    }
    if (hp == 0) return true;
    return false;
  }
  int min_units_for_possible_in_rounds(int hp, int rounds) {
    if (!is_possible(hp,INF,rounds)) return INF;
    int lo = 0, hi = INF, mid;
    while (hi-lo > 1) {
      mid = (lo+hi)/2;
      if (is_possible(hp,mid,rounds)) hi = mid; else lo = mid;
    }
    return hi;
  }
  int attack(int myUnits, int hpT, int attackT, int numWodT, int numStoT) {
    if (myUnits == 1) return -1;
    this->hpT = hpT;
    this->attackT = attackT;
    if (min_units_for_possible_in_rounds(numWodT*hpT,INF) +
        min_units_for_possible_in_rounds(numStoT*hpT,INF) > myUnits) return -1;
    int lo = 0, hi = INF, mid;
    while (hi-lo > 1) {
      mid = (lo+hi)/2;
      if (min_units_for_possible_in_rounds(numWodT*hpT,mid) +
          min_units_for_possible_in_rounds(numStoT*hpT,mid) <= myUnits) hi = mid;
      else lo = mid;
    }
    return hi;
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
		cout << "Testing EnemyTowers (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397512077;
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
		EnemyTowers _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int myUnits = 7;
				int hpT = 2;
				int attackT = 1;
				int numWodT = 2;
				int numStoT = 3;
				_expected = 2;
				_received = _obj.attack(myUnits, hpT, attackT, numWodT, numStoT); break;
			}
			case 1:
			{
				int myUnits = 120;
				int hpT = 10;
				int attackT = 40000;
				int numWodT = 6;
				int numStoT = 6;
				_expected = 1;
				_received = _obj.attack(myUnits, hpT, attackT, numWodT, numStoT); break;
			}
			case 2:
			{
				int myUnits = 119;
				int hpT = 10;
				int attackT = 40000;
				int numWodT = 6;
				int numStoT = 6;
				_expected = -1;
				_received = _obj.attack(myUnits, hpT, attackT, numWodT, numStoT); break;
			}
			case 3:
			{
				int myUnits = 200;
				int hpT = 50;
				int attackT = 3;
				int numWodT = 10;
				int numStoT = 5;
				_expected = 6;
				_received = _obj.attack(myUnits, hpT, attackT, numWodT, numStoT); break;
			}
			case 4:
			{
				int myUnits = 1000000000;
				int hpT = 40000;
				int attackT = 40000;
				int numWodT = 449;
				int numStoT = 40000;
				_expected = 7;
				_received = _obj.attack(myUnits, hpT, attackT, numWodT, numStoT); break;
			}
			case 5:
			{
				int myUnits = 9918874;
				int hpT = 12094;
				int attackT = 4;
				int numWodT = 8494;
				int numStoT = 37014;
				_expected = 534;
				_received = _obj.attack(myUnits, hpT, attackT, numWodT, numStoT); break;
			}
			case 6:
			{
				int myUnits = 15960246;
				int hpT = 40000;
				int attackT = 1;
				int numWodT = 40000;
				int numStoT = 40000;
				_expected = 1648;
				_received = _obj.attack(myUnits, hpT, attackT, numWodT, numStoT); break;
			}
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
