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

class RaceCalculator {
 public:
  int bestRace(vector <int> distances, vector <int> times) {
    vector<double> badness(distances.size(),-1e100);
    for (int i=0;i<distances.size();i++)
      for (int j=0;j<distances.size();j++) {
        if (i == j) continue;
        for (int k=0;k<distances.size();k++) {
          if (i == k || j == k) continue;
          double expected = times[i]*exp(log(double(times[j])/times[i])*
          log(double(distances[i])/distances[k])/log(double(distances[i])/distances[j]));
          badness[k] = max(badness[k],double(times[k]-expected)/expected);
        }
      }
    double mb = 1e100;
    int mi = -1;
    for (int i=0;i<badness.size();i++)
      if (badness[i] < mb) {
        mb = badness[i];
        mi = i;
      }
    return mi;
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
		cout << "Testing RaceCalculator (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398199680;
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
		RaceCalculator _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int distances[] = {1600,3200,16000};
				int times[] = {299,655,4020};
				_expected = 2;
				_received = _obj.bestRace(vector <int>(distances, distances+sizeof(distances)/sizeof(int)), vector <int>(times, times+sizeof(times)/sizeof(int))); break;
			}
			case 1:
			{
				int distances[] = {1600,2000,3200,3000,5000,9600};
				int times[] = {234,306,499,462,802,1629};
				_expected = 3;
				_received = _obj.bestRace(vector <int>(distances, distances+sizeof(distances)/sizeof(int)), vector <int>(times, times+sizeof(times)/sizeof(int))); break;
			}
			case 2:
			{
				int distances[] = {1000,2000,3000,4000};
				int times[] = {160,330,510,750};
				_expected = 2;
				_received = _obj.bestRace(vector <int>(distances, distances+sizeof(distances)/sizeof(int)), vector <int>(times, times+sizeof(times)/sizeof(int))); break;
			}
			case 3:
			{
				int distances[] = {1000,50000,10000,5000};
				int times[] = {200,70010,2250,1080};
				_expected = 2;
				_received = _obj.bestRace(vector <int>(distances, distances+sizeof(distances)/sizeof(int)), vector <int>(times, times+sizeof(times)/sizeof(int))); break;
			}
			/*case 4:
			{
				int distances[] = ;
				int times[] = ;
				_expected = ;
				_received = _obj.bestRace(vector <int>(distances, distances+sizeof(distances)/sizeof(int)), vector <int>(times, times+sizeof(times)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int distances[] = ;
				int times[] = ;
				_expected = ;
				_received = _obj.bestRace(vector <int>(distances, distances+sizeof(distances)/sizeof(int)), vector <int>(times, times+sizeof(times)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int distances[] = ;
				int times[] = ;
				_expected = ;
				_received = _obj.bestRace(vector <int>(distances, distances+sizeof(distances)/sizeof(int)), vector <int>(times, times+sizeof(times)/sizeof(int))); break;
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
