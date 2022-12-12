#include <string>
#include <iostream>
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

class YearProgressbar {
 public:
  double percentage(string currentDate) {
    stringstream a(currentDate);
    string month, day, time;
    int year;
    a >> month >> day >> year >> time;
    bool leapyear = !(year%400) || (!(year%4) && year%100);
    int dday;
    stringstream b(day.substr(0,day.size()-1));
    b >> dday;
    dday--;
    map<string,int> monthdays;
    monthdays["January"] = 0;
    monthdays["February"] = 31;
    monthdays["March"] = monthdays["February"]+28+leapyear;
    monthdays["April"] = monthdays["March"]+31;
    monthdays["May"] = monthdays["April"]+30;
    monthdays["June"] = monthdays["May"]+31;
    monthdays["July"] = monthdays["June"]+30;
    monthdays["August"] = monthdays["July"]+31;
    monthdays["September"] = monthdays["August"]+31;
    monthdays["October"] = monthdays["September"]+30;
    monthdays["November"] = monthdays["October"]+31;
    monthdays["December"] = monthdays["November"]+30;
    int secondstotal = (365+leapyear)*24*3600;
    int secondspassed = (monthdays[month]+dday)*24*3600;
    stringstream c(time.substr(0,time.find(":")));
    int hhour;
    c >> hhour;
    stringstream d(time.substr(time.find(":")+1));
    int hmin;
    d >> hmin;
    secondspassed+=hhour*3600+hmin*60;
    return ((double)100*secondspassed)/secondstotal;
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
		cout << "Testing YearProgressbar (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392136062;
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
		YearProgressbar _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string currentDate = "January 01, 2008 00:00";
				_expected = 0.0;
				_received = _obj.percentage(currentDate); break;
			}
			case 1:
			{
				string currentDate = "December 31, 2007 23:59";
				_expected = 99.99980974124807;
				_received = _obj.percentage(currentDate); break;
			}
			case 2:
			{
				string currentDate = "July 02, 2007 12:00";
				_expected = 50.0;
				_received = _obj.percentage(currentDate); break;
			}
			case 3:
			{
				string currentDate = "July 02, 2008 00:00";
				_expected = 50.0;
				_received = _obj.percentage(currentDate); break;
			}
			case 4:
			{
				string currentDate = "May 10, 1981 00:31";
				_expected = 35.348363774733635;
				_received = _obj.percentage(currentDate); break;
			}
			case 5:
			{
				string currentDate = "January 31, 1900 00:47";
				_expected = 8.228120243531203;
				_received = _obj.percentage(currentDate); break;
			}
			case 6:
			{
				string currentDate = "March 08, 2000 09:12";
				_expected = 18.410746812386158;
				_received = _obj.percentage(currentDate); break;
			}
			/*case 7:
			{
				string currentDate = ;
				_expected = ;
				_received = _obj.percentage(currentDate); break;
			}*/
			/*case 8:
			{
				string currentDate = ;
				_expected = ;
				_received = _obj.percentage(currentDate); break;
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
