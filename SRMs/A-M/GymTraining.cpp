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

class GymTraining {
 public:
  int trainingTime(int needToTrain, int minPulse, int maxPulse, int trainChange, int restChange) {
    if (trainChange+minPulse > maxPulse) return -1;
    int pulse = minPulse;
    int c = 0;
    for (int i=0;i<needToTrain;i++) {
      while (pulse+trainChange > maxPulse) {
        pulse = max(minPulse,pulse-restChange);
        c++;
      }
      pulse +=trainChange;
    }
    return c + needToTrain;
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
		cout << "Testing GymTraining (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392219270;
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
		GymTraining _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int needToTrain = 5;
				int minPulse = 70;
				int maxPulse = 120;
				int trainChange = 25;
				int restChange = 15;
				_expected = 10;
				_received = _obj.trainingTime(needToTrain, minPulse, maxPulse, trainChange, restChange); break;
			}
			case 1:
			{
				int needToTrain = 100;
				int minPulse = 50;
				int maxPulse = 100;
				int trainChange = 5;
				int restChange = 200;
				_expected = 109;
				_received = _obj.trainingTime(needToTrain, minPulse, maxPulse, trainChange, restChange); break;
			}
			case 2:
			{
				int needToTrain = 1;
				int minPulse = 60;
				int maxPulse = 70;
				int trainChange = 11;
				int restChange = 11;
				_expected = -1;
				_received = _obj.trainingTime(needToTrain, minPulse, maxPulse, trainChange, restChange); break;
			}
			case 3:
			{
				int needToTrain = 200;
				int minPulse = 50;
				int maxPulse = 200;
				int trainChange = 150;
				int restChange = 1;
				_expected = 30050;
				_received = _obj.trainingTime(needToTrain, minPulse, maxPulse, trainChange, restChange); break;
			}
			case 4:
			{
				int needToTrain = 19;
				int minPulse = 89;
				int maxPulse = 143;
				int trainChange = 17;
				int restChange = 13;
				_expected = 40;
				_received = _obj.trainingTime(needToTrain, minPulse, maxPulse, trainChange, restChange); break;
			}
			/*case 5:
			{
				int needToTrain = ;
				int minPulse = ;
				int maxPulse = ;
				int trainChange = ;
				int restChange = ;
				_expected = ;
				_received = _obj.trainingTime(needToTrain, minPulse, maxPulse, trainChange, restChange); break;
			}*/
			/*case 6:
			{
				int needToTrain = ;
				int minPulse = ;
				int maxPulse = ;
				int trainChange = ;
				int restChange = ;
				_expected = ;
				_received = _obj.trainingTime(needToTrain, minPulse, maxPulse, trainChange, restChange); break;
			}*/
			/*case 7:
			{
				int needToTrain = ;
				int minPulse = ;
				int maxPulse = ;
				int trainChange = ;
				int restChange = ;
				_expected = ;
				_received = _obj.trainingTime(needToTrain, minPulse, maxPulse, trainChange, restChange); break;
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
