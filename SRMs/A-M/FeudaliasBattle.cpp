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

class FeudaliasBattle {
 public:
  vector<int> baseX;
  vector<int> baseY;
  vector<int> siloX;
  vector<int> siloY;
  int takeOffTime, rechargeTime;
  double missileSpeed;
  double getmintime(int i0, int i1) {
    double dist0 = sqrt(((LL)siloX[i0]-baseX[0])*(siloX[i0]-baseX[0]) +
                   ((LL)siloY[i0]-baseY[0])*(siloY[i0]-baseY[0]));
    double dist1 = sqrt(((LL)siloX[i1]-baseX[1])*(siloX[i1]-baseX[1]) +
                   ((LL)siloY[i1]-baseY[1])*(siloY[i1]-baseY[1]));
    double r = 0;
    if (i0 == i1) {
      double d1 = max(takeOffTime+dist0/missileSpeed,rechargeTime+2*takeOffTime+dist1/missileSpeed);
      double d2 = max(rechargeTime+2*takeOffTime+dist0/missileSpeed,takeOffTime+dist1/missileSpeed);
      r+= min(d1,d2);
    } else {
      r+= takeOffTime+max(dist0,dist1)/missileSpeed;
    }
    return r/60;
  }
  double getMinimumTime(vector <int> baseX, vector <int> baseY, vector <int> siloX, vector <int> siloY, int takeOffTime, int rechargeTime, int missileSpeed) {
    this->baseX = baseX;
    this->baseY = baseY;
    this->siloX = siloX;
    this->siloY = siloY;
    this->missileSpeed = missileSpeed/60.0;
    this->takeOffTime = takeOffTime;
    this->rechargeTime = rechargeTime*60;
    double mn = 1e100;
    mn = min(mn,getmintime(0,0));
    mn = min(mn,getmintime(0,1));
    mn = min(mn,getmintime(1,0));
    mn = min(mn,getmintime(1,1));
    return mn;
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
		cout << "Testing FeudaliasBattle (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394729426;
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
		FeudaliasBattle _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int baseX[] = {100, 500};
				int baseY[] = {100, 100};
				int siloX[] = {100, 500};
				int siloY[] = {300, 300};
				int takeOffTime = 6;
				int rechargeTime = 10;
				int missileSpeed = 1;
				_expected = 200.1;
				_received = _obj.getMinimumTime(vector <int>(baseX, baseX+sizeof(baseX)/sizeof(int)), vector <int>(baseY, baseY+sizeof(baseY)/sizeof(int)), vector <int>(siloX, siloX+sizeof(siloX)/sizeof(int)), vector <int>(siloY, siloY+sizeof(siloY)/sizeof(int)), takeOffTime, rechargeTime, missileSpeed); break;
			}
			case 1:
			{
				int baseX[] = {100, 100};
				int baseY[] = {100, 500};
				int siloX[] = {100, 500};
				int siloY[] = {300, 300};
				int takeOffTime = 6;
				int rechargeTime = 10;
				int missileSpeed = 1;
				_expected = 210.2;
				_received = _obj.getMinimumTime(vector <int>(baseX, baseX+sizeof(baseX)/sizeof(int)), vector <int>(baseY, baseY+sizeof(baseY)/sizeof(int)), vector <int>(siloX, siloX+sizeof(siloX)/sizeof(int)), vector <int>(siloY, siloY+sizeof(siloY)/sizeof(int)), takeOffTime, rechargeTime, missileSpeed); break;
			}
			case 2:
			{
				int baseX[] = {100, 100};
				int baseY[] = {100, 500};
				int siloX[] = {100, 500};
				int siloY[] = {300, 300};
				int takeOffTime = 6;
				int rechargeTime = 20;
				int missileSpeed = 20;
				_expected = 22.4606797749979;
				_received = _obj.getMinimumTime(vector <int>(baseX, baseX+sizeof(baseX)/sizeof(int)), vector <int>(baseY, baseY+sizeof(baseY)/sizeof(int)), vector <int>(siloX, siloX+sizeof(siloX)/sizeof(int)), vector <int>(siloY, siloY+sizeof(siloY)/sizeof(int)), takeOffTime, rechargeTime, missileSpeed); break;
			}
			case 3:
			{
				int baseX[] = {401, 208};
				int baseY[] = {622, 603};
				int siloX[] = {51, 387};
				int siloY[] = {411, 828};
				int takeOffTime = 59;
				int rechargeTime = 518;
				int missileSpeed = 1941;
				_expected = 1.1111118724871378;
				_received = _obj.getMinimumTime(vector <int>(baseX, baseX+sizeof(baseX)/sizeof(int)), vector <int>(baseY, baseY+sizeof(baseY)/sizeof(int)), vector <int>(siloX, siloX+sizeof(siloX)/sizeof(int)), vector <int>(siloY, siloY+sizeof(siloY)/sizeof(int)), takeOffTime, rechargeTime, missileSpeed); break;
			}
			/*case 4:
			{
				int baseX[] = ;
				int baseY[] = ;
				int siloX[] = ;
				int siloY[] = ;
				int takeOffTime = ;
				int rechargeTime = ;
				int missileSpeed = ;
				_expected = ;
				_received = _obj.getMinimumTime(vector <int>(baseX, baseX+sizeof(baseX)/sizeof(int)), vector <int>(baseY, baseY+sizeof(baseY)/sizeof(int)), vector <int>(siloX, siloX+sizeof(siloX)/sizeof(int)), vector <int>(siloY, siloY+sizeof(siloY)/sizeof(int)), takeOffTime, rechargeTime, missileSpeed); break;
			}*/
			/*case 5:
			{
				int baseX[] = ;
				int baseY[] = ;
				int siloX[] = ;
				int siloY[] = ;
				int takeOffTime = ;
				int rechargeTime = ;
				int missileSpeed = ;
				_expected = ;
				_received = _obj.getMinimumTime(vector <int>(baseX, baseX+sizeof(baseX)/sizeof(int)), vector <int>(baseY, baseY+sizeof(baseY)/sizeof(int)), vector <int>(siloX, siloX+sizeof(siloX)/sizeof(int)), vector <int>(siloY, siloY+sizeof(siloY)/sizeof(int)), takeOffTime, rechargeTime, missileSpeed); break;
			}*/
			/*case 6:
			{
				int baseX[] = ;
				int baseY[] = ;
				int siloX[] = ;
				int siloY[] = ;
				int takeOffTime = ;
				int rechargeTime = ;
				int missileSpeed = ;
				_expected = ;
				_received = _obj.getMinimumTime(vector <int>(baseX, baseX+sizeof(baseX)/sizeof(int)), vector <int>(baseY, baseY+sizeof(baseY)/sizeof(int)), vector <int>(siloX, siloX+sizeof(siloX)/sizeof(int)), vector <int>(siloY, siloY+sizeof(siloY)/sizeof(int)), takeOffTime, rechargeTime, missileSpeed); break;
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
