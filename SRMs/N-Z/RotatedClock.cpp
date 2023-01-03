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

class RotatedClock {
 public:
  string getEarliest(int hourHand, int minuteHand) {
    vector<string> times;
    for (int offset = 0;offset < 360;offset+=30) {
      int minute = ((minuteHand+offset)%360)*60/360;
      int hour = ((hourHand+offset)%360)*12/360;
      int hourdeg = ((hourHand+offset)%360);
      int prevhourdeg = (((hourHand+offset)%360)/30)*30;
      if ((((hourdeg-prevhourdeg)*360)/30) != (minuteHand+offset)%360)
        continue;
      stringstream a;
      a << setw(2) << setfill('0') << hour << ":" << setw(2) << minute;
      times.push_back(a.str());
    }
    if (!times.size()) return "";
    sort(times.begin(),times.end());
    return times[0];
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
		cout << "Testing RotatedClock (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397135634;
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
		RotatedClock _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int hourHand = 70;
				int minuteHand = 300;
				_expected = "08:20";
				_received = _obj.getEarliest(hourHand, minuteHand); break;
			}
			case 1:
			{
				int hourHand = 90;
				int minuteHand = 120;
				_expected = "11:00";
				_received = _obj.getEarliest(hourHand, minuteHand); break;
			}
			case 2:
			{
				int hourHand = 240;
				int minuteHand = 36;
				_expected = "";
				_received = _obj.getEarliest(hourHand, minuteHand); break;
			}
			case 3:
			{
				int hourHand = 19;
				int minuteHand = 19;
				_expected = "";
				_received = _obj.getEarliest(hourHand, minuteHand); break;
			}
			case 4:
			{
				int hourHand = 1;
				int minuteHand = 12;
				_expected = "00:02";
				_received = _obj.getEarliest(hourHand, minuteHand); break;
			}
			/*case 5:
			{
				int hourHand = ;
				int minuteHand = ;
				_expected = ;
				_received = _obj.getEarliest(hourHand, minuteHand); break;
			}*/
			/*case 6:
			{
				int hourHand = ;
				int minuteHand = ;
				_expected = ;
				_received = _obj.getEarliest(hourHand, minuteHand); break;
			}*/
			/*case 7:
			{
				int hourHand = ;
				int minuteHand = ;
				_expected = ;
				_received = _obj.getEarliest(hourHand, minuteHand); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
