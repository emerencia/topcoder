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
int mem[51][5001];

class AlbertoTheAviator {
 public:
	vector<PII> missions;
	int rec(int idx, int fuel) {
		int& r = mem[idx][fuel];
		if (r != -1) return r;
		if (idx == missions.size()) return r = 0;
		int t = 0;
		if (fuel >= missions[idx].first)
			t = max(t,1+rec(idx+1,fuel-missions[idx].first+missions[idx].second));
		t = max(t,rec(idx+1,fuel));
		return r = t;
	}
	int MaximumFlights(int F, vector <int> duration, vector <int> refuel) {
		missions.clear();
		for (int i=0;i<duration.size();i++)
			missions.push_back(PII(duration[i],refuel[i]));
		sort(missions.rbegin(),missions.rend());
		memset(mem,-1,sizeof(mem));
		return rec(0,F);
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
		cout << "Testing AlbertoTheAviator (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1421347766;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AlbertoTheAviator _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int F = 10;
				int duration[] = {10};
				int refuel[] = {0};
				_expected = 1;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}
			case 1:
			{
				int F = 10;
				int duration[] = {8, 4};
				int refuel[] = {0, 2};
				_expected = 2;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}
			case 2:
			{
				int F = 12;
				int duration[] = {4, 8, 2, 1};
				int refuel[] = {2, 0, 0, 0};
				_expected = 3;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}
			case 3:
			{
				int F = 9;
				int duration[] = {4, 6};
				int refuel[] = {0, 1};
				_expected = 2;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}
			case 4:
			{
				int F = 100;
				int duration[] = {101};
				int refuel[] = {100};
				_expected = 0;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}
			case 5:
			{
				int F = 1947;
				int duration[] = {2407, 2979, 1269, 2401, 3227, 2230, 3991, 2133, 3338, 356, 2535, 3859, 3267, 365};
				int refuel[] = {2406, 793, 905, 2400, 1789, 2229, 1378, 2132, 1815, 355, 72, 3858, 3266, 364};
				_expected = 3;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}
			case 6:
			{
				int F = 4596;
				int duration[] = {3195, 4264, 3037, 1529, 666, 440, 4844, 3414, 784, 731, 505, 3528, 1994, 4546, 828, 2139, 3826, 1875, 2350, 3404, 320, 4717, 4171, 4388, 4771, 967, 3977, 718, 2899, 2241, 3319, 1093, 1504, 2708, 3974, 3521, 3147, 169, 1934, 282, 2251, 3791, 161, 4244, 3336, 988, 1383, 2161, 4214, 3732};
				int refuel[] = {1864, 2851, 1120, 1528, 665, 439, 4396, 3413, 598, 730, 504, 3527, 1993, 1317, 649, 2138, 2554, 1874, 1604, 3403, 319, 3551, 1511, 2519, 2228, 800, 2512, 717, 949, 2240, 3318, 1092, 1219, 660, 1432, 1997, 3146, 168, 765, 281, 2250, 2884, 160, 2587, 3335, 987, 1382, 2160, 3841, 3405};
				_expected = 33;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}
			/*case 7:
			{
				int F = ;
				int duration[] = ;
				int refuel[] = ;
				_expected = ;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int F = ;
				int duration[] = ;
				int refuel[] = ;
				_expected = ;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
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
