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
bool seen[2400][2400];
double mem[2400][2400];

class PointSystem {
 public:
  int skill, pointsToWin, pointsToWinBy;
  double rec(int pointsplayed, int pointswon) {
    double& r = mem[pointsplayed][pointswon];
    if (seen[pointsplayed][pointswon]) return r;
    seen[pointsplayed][pointswon] = 1;
    int pointslost = pointsplayed-pointswon;
    if (pointslost > pointswon && pointslost >= pointsToWin &&
        pointslost-pointswon >= pointsToWinBy) {
      return r = 0;
    }
    if (pointswon > pointslost && pointswon >= pointsToWin &&
        pointswon-pointslost >= pointsToWinBy) {
      return r = 1;
    }
    if (pointsplayed == 2399) return r = skill/100.0;
    return r = (skill/100.0)*rec(pointsplayed+1,pointswon+1)+
               ((100-skill)/100.0)*rec(pointsplayed+1,pointswon);
  }
  double oddsOfWinning(int pointsToWin, int pointsToWinBy, int skill) {
    this->skill = skill;
    this->pointsToWin = pointsToWin;
    this->pointsToWinBy = pointsToWinBy;
    memset(seen,0,sizeof(seen));
    return rec(0,0);
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
		cout << "Testing PointSystem (800.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397735714;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 800.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PointSystem _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int pointsToWin = 2;
				int pointsToWinBy = 1;
				int skill = 40;
				_expected = 0.352;
				_received = _obj.oddsOfWinning(pointsToWin, pointsToWinBy, skill); break;
			}
			case 1:
			{
				int pointsToWin = 4;
				int pointsToWinBy = 5;
				int skill = 50;
				_expected = 0.4999999999999998;
				_received = _obj.oddsOfWinning(pointsToWin, pointsToWinBy, skill); break;
			}
			case 2:
			{
				int pointsToWin = 3;
				int pointsToWinBy = 3;
				int skill = 25;
				_expected = 0.035714285714285705;
				_received = _obj.oddsOfWinning(pointsToWin, pointsToWinBy, skill); break;
			}
			case 3:
			{
				int pointsToWin = 2;
				int pointsToWinBy = 1;
				int skill = 40;
				_expected = 0.352;
				_received = _obj.oddsOfWinning(pointsToWin, pointsToWinBy, skill); break;
			}
			/*case 4:
			{
				int pointsToWin = ;
				int pointsToWinBy = ;
				int skill = ;
				_expected = ;
				_received = _obj.oddsOfWinning(pointsToWin, pointsToWinBy, skill); break;
			}*/
			/*case 5:
			{
				int pointsToWin = ;
				int pointsToWinBy = ;
				int skill = ;
				_expected = ;
				_received = _obj.oddsOfWinning(pointsToWin, pointsToWinBy, skill); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(3);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
