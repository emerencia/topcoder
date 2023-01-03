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

class LateProfessor {
 public:
  double getProbability(int waitTime, int walkTime, int lateTime, int bestArrival, int worstArrival) {
    if (lateTime >= walkTime) return 0;
    int madeIt = 0;
    int lastWaitTime = 1e9;
    if (bestArrival == worstArrival) {
      for (int i=worstArrival+walkTime+waitTime+1;i>=bestArrival;i--) {
        int state = (i%(waitTime+walkTime)) <= waitTime;
        if (state == 1 || lastWaitTime-i < lateTime)
          if (i == worstArrival)
            madeIt++;
        if (state == 1) lastWaitTime = i;
      }
      return 1-double(madeIt);
    }
    for (int i=worstArrival+walkTime+waitTime+1;i>=bestArrival;i--) {
      int state = (i%(waitTime+walkTime)) < waitTime;
      if (state == 1 || lastWaitTime-i <= lateTime)
        if (i < worstArrival)
          madeIt++;
      if (state == 1) lastWaitTime = i;
    }
    return 1.0-double(madeIt)/(worstArrival-bestArrival);
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
		cout << "Testing LateProfessor (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1407178890;
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
		LateProfessor _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int waitTime = 20;
				int walkTime = 30;
				int lateTime = 10;
				int bestArrival = 0;
				int worstArrival = 50;
				_expected = 0.4;
				_received = _obj.getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival); break;
			}
			case 1:
			{
				int waitTime = 20;
				int walkTime = 30;
				int lateTime = 10;
				int bestArrival = 30;
				int worstArrival = 100;
				_expected = 0.42857142857142855;
				_received = _obj.getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival); break;
			}
			case 2:
			{
				int waitTime = 20;
				int walkTime = 40;
				int lateTime = 50;
				int bestArrival = 0;
				int worstArrival = 300;
				_expected = 0.0;
				_received = _obj.getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival); break;
			}
			case 3:
			{
				int waitTime = 101;
				int walkTime = 230;
				int lateTime = 10;
				int bestArrival = 654;
				int worstArrival = 17890;
				_expected = 0.6637270828498492;
				_received = _obj.getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival); break;
			}
			case 4:
			{
				int waitTime = 20;
				int walkTime = 30;
				int lateTime = 10;
				int bestArrival = 90;
				int worstArrival = 90;
				_expected = 1.0;
				_received = _obj.getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival); break;
			}
			case 5:
			{
				int waitTime = 1000;
				int walkTime = 600;
				int lateTime = 1;
				int bestArrival = 17000;
				int worstArrival = 17000;
				_expected = 0.0;
				_received = _obj.getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival); break;
			}
			case 6:
			{
				int waitTime = 120000;
				int walkTime = 180000;
				int lateTime = 150000;
				int bestArrival = 600000;
				int worstArrival = 1400000;
				_expected = 0.1125;
				_received = _obj.getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival); break;
			}
			case 7:
			{
				int waitTime = 20;
				int walkTime = 30;
				int lateTime = 10;
				int bestArrival = 91;
				int worstArrival = 91;
				_expected = 0.0;
				_received = _obj.getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival); break;
			}
			/*case 8:
			{
				int waitTime = ;
				int walkTime = ;
				int lateTime = ;
				int bestArrival = ;
				int worstArrival = ;
				_expected = ;
				_received = _obj.getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival); break;
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
