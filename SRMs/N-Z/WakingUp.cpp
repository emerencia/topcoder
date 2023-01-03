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

int gcd(int a,int b) {
  if (b == 0) return a;
  return gcd(b,a%b);
}

int lcm(int a,int b) {
  int g = gcd(a,b);
  return (a/g)*b;
}



class WakingUp {
 public:
  int maxSleepiness(vector <int> period, vector <int> start, vector <int> volume, int D) {
    int check_range = start[0];
    for (int i=0;i<period.size();i++)
      check_range = lcm(check_range,period[i]);
    int current_sleepiness = 0;
    vector<int> next_index = start;
    int min_sleepiness = 1;
    int total_sleepiness_gained = 0;
    int total_sleepiness_lost = 0;
    for (int i = 1; i <= check_range; i++) {
      current_sleepiness += D;
      total_sleepiness_gained += D;
      for (int j=0;j<next_index.size();j++)
        if (next_index[j] == i) {
          current_sleepiness -= volume[j];
          total_sleepiness_lost += volume[j];
          next_index[j] = next_index[j] + period[j];
        }
      if (current_sleepiness < min_sleepiness)
        min_sleepiness = current_sleepiness;
    }
    if (total_sleepiness_lost > total_sleepiness_gained)
      return -1;
    if (min_sleepiness == 1) return 0;
    return -min_sleepiness;
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
		cout << "Testing WakingUp (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1431022556;
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
		WakingUp _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int period[] = {2, 3};
				int start[] = {1, 2};
				int volume[] = {3, 4};
				int D = 3;
				_expected = 2;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}
			case 1:
			{
				int period[] = {1};
				int start[] = {1};
				int volume[] = {17};
				int D = 17;
				_expected = 0;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}
			case 2:
			{
				int period[] = {1};
				int start[] = {1};
				int volume[] = {23};
				int D = 17;
				_expected = -1;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}
			case 3:
			{
				int period[] = {9, 2, 5, 5, 7};
				int start[] = {6, 1, 4, 1, 6};
				int volume[] = {71, 66, 7, 34, 6};
				int D = 50;
				_expected = 78;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}
			case 4:
			{
				int period[] = {5, 6, 5, 3, 8, 3, 4};
				int start[] = {1, 1, 3, 2, 6, 3, 3};
				int volume[] = {42, 85, 10, 86, 21, 78, 38};
				int D = 88;
				_expected = -1;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}
			case 5:
			{
				int period[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				int start[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				int volume[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				int D = 100;
				_expected = 0;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}
			/*case 6:
			{
				int period[] = ;
				int start[] = ;
				int volume[] = ;
				int D = ;
				_expected = ;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}*/
			/*case 7:
			{
				int period[] = ;
				int start[] = ;
				int volume[] = ;
				int D = ;
				_expected = ;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
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
