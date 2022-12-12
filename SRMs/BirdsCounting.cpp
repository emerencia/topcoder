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
double mem[6][21];

class BirdsCounting {
 public:
  int birdsNumber, caughtPerDay, daysNumber, birdsMarked;
  double bico(int n,int k) {
    if (k < 0 || k > n) return 0;
    if (k > n-k) k = n-k;
    long long p = 1;
    for (int i=0;i<k;i++) {
      p = ((n-i)*p)/(i+1);
    }
    return p;
  }
  double rec(int idx, int marked) {
    double& r = mem[idx][marked];
    if (abs(r+1) < 1e-9) return r;
    if (idx == daysNumber) return r = (marked == birdsMarked);
    // returns the prob of marking caughtperday birds on day idx
    double t = 0;
    for (int i = 0;i<=caughtPerDay;i++) {
      double fact = bico(marked,i)*bico(birdsNumber-marked,caughtPerDay-i)/
                    bico(birdsNumber,caughtPerDay);
      t+=fact*rec(idx+1,marked+caughtPerDay-i);
    }
    return r = t;
  }
  double computeProbability(int birdsNumber, int caughtPerDay, int daysNumber, int birdsMarked) {
    this->birdsNumber = birdsNumber;
    this->caughtPerDay = caughtPerDay;
    this->daysNumber = daysNumber;
    this->birdsMarked = birdsMarked;
    memset(mem,-1,sizeof(mem));
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
	if(tt!=-1){char* b[2];b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}	if (argc == 1) 
	{
		cout << "Testing BirdsCounting (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394216386;
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
		BirdsCounting _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int birdsNumber = 3;
				int caughtPerDay = 1;
				int daysNumber = 2;
				int birdsMarked = 2;
				_expected = 0.6666666666666666;
				_received = _obj.computeProbability(birdsNumber, caughtPerDay, daysNumber, birdsMarked); break;
			}
			case 1:
			{
				int birdsNumber = 3;
				int caughtPerDay = 1;
				int daysNumber = 5;
				int birdsMarked = 1;
				_expected = 0.012345679012345678;
				_received = _obj.computeProbability(birdsNumber, caughtPerDay, daysNumber, birdsMarked); break;
			}
			case 2:
			{
				int birdsNumber = 8;
				int caughtPerDay = 3;
				int daysNumber = 3;
				int birdsMarked = 7;
				_expected = 0.2582908163265306;
				_received = _obj.computeProbability(birdsNumber, caughtPerDay, daysNumber, birdsMarked); break;
			}
			case 3:
			{
				int birdsNumber = 5;
				int caughtPerDay = 3;
				int daysNumber = 2;
				int birdsMarked = 4;
				_expected = 0.6;
				_received = _obj.computeProbability(birdsNumber, caughtPerDay, daysNumber, birdsMarked); break;
			}
			case 4:
			{
				int birdsNumber = 20;
				int caughtPerDay = 6;
				int daysNumber = 5;
				int birdsMarked = 17;
				_expected = 0.30035494805367574;
				_received = _obj.computeProbability(birdsNumber, caughtPerDay, daysNumber, birdsMarked); break;
			}
			/*case 5:
			{
				int birdsNumber = ;
				int caughtPerDay = ;
				int daysNumber = ;
				int birdsMarked = ;
				_expected = ;
				_received = _obj.computeProbability(birdsNumber, caughtPerDay, daysNumber, birdsMarked); break;
			}*/
			/*case 6:
			{
				int birdsNumber = ;
				int caughtPerDay = ;
				int daysNumber = ;
				int birdsMarked = ;
				_expected = ;
				_received = _obj.computeProbability(birdsNumber, caughtPerDay, daysNumber, birdsMarked); break;
			}*/
			/*case 7:
			{
				int birdsNumber = ;
				int caughtPerDay = ;
				int daysNumber = ;
				int birdsMarked = ;
				_expected = ;
				_received = _obj.computeProbability(birdsNumber, caughtPerDay, daysNumber, birdsMarked); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
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
