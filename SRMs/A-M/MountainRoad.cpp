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

class MountainRoad {
 public:
  double findDistance(vector <int> start, vector <int> finish) {
    int mn = *min_element(start.begin(),start.end());
    int mx = *max_element(finish.begin(),finish.end());
    double dist = (mx-mn)/2.0;
    return 2*sqrt(dist*dist+dist*dist);
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
		cout << "Testing MountainRoad (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396664279;
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
		MountainRoad _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int start[] = {1};
				int finish[] = {7};
				_expected = 8.485281374238571;
				_received = _obj.findDistance(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(finish, finish+sizeof(finish)/sizeof(int))); break;
			}
			case 1:
			{
				int start[] = {0,3,4};
				int finish[] = {5,9,6};
				_expected = 12.727922061357857;
				_received = _obj.findDistance(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(finish, finish+sizeof(finish)/sizeof(int))); break;
			}
			case 2:
			{
				int start[] = {1,4,5,6,-10};
				int finish[] = {101,102,101,100,99};
				_expected = 158.39191898578665;
				_received = _obj.findDistance(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(finish, finish+sizeof(finish)/sizeof(int))); break;
			}
			case 3:
			{
				int start[] = {-5,-3};
				int finish[] = {-2,-2};
				_expected = 4.242640687119286;
				_received = _obj.findDistance(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(finish, finish+sizeof(finish)/sizeof(int))); break;
			}
			/*case 4:
			{
				int start[] = ;
				int finish[] = ;
				_expected = ;
				_received = _obj.findDistance(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(finish, finish+sizeof(finish)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int start[] = ;
				int finish[] = ;
				_expected = ;
				_received = _obj.findDistance(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(finish, finish+sizeof(finish)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int start[] = ;
				int finish[] = ;
				_expected = ;
				_received = _obj.findDistance(vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(finish, finish+sizeof(finish)/sizeof(int))); break;
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
