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

class TheTriangleBothDivs {
 public:
  string time;
  string timeinzero(const string& time) {
    int signoffset = time[9] == '-' ? 1 : -1;
    int houroffset = time[10]-'0';
    int offset = signoffset*houroffset;
    int hour = 10*(time[0]-'0')+time[1]-'0';
    hour = (hour + 24 + offset)%24;
    stringstream a;
    a << setfill('0') << setw(2) << hour;
    return a.str()+time.substr(2,3);
  }
  string rec(int idx, string sofar) {
    if (idx == time.size()) return timeinzero(sofar);
    if (time[idx] != '?') return rec(idx+1,sofar+time[idx]);
    string s = "@";
    switch (idx) {
      case 0: {
        int mx = (time[idx+1] != '?' && time[idx+1] > '3' ? 1 : 2);
        for (int i=0;i<=mx;i++)
          s = min(s,rec(idx+1,sofar+char('0'+i)));
        break;
      }
      case 1: {
        int mx = (time[idx-1] == '2' ? 3 : 9);
        for (int i=0;i<=mx;i++)
          s = min(s,rec(idx+1,sofar+char('0'+i)));
        break;
      }
      case 3:
        for (int i=0;i<6;i++)
          s = min(s,rec(idx+1,sofar+char('0'+i)));
        break;
      case 4:
        for (int i=0;i<10;i++)
          s = min(s,rec(idx+1,sofar+char('0'+i)));
        break;
      case 9:
        s = min(s,rec(idx+1,sofar+"-"));
        s = min(s,rec(idx+1,sofar+"+"));
        break;
      case 10:
        int mn = time[idx-1] == '-' ? 1 : 0;
        for (int i=mn;i<=9;i++)
          s = min(s,rec(idx+1,sofar+char('0'+i)));
        break;
    }
    return s;
  }
  string fix(string time) {
    time[2] = ':';
    time[5] = ' ';
    time[6] = 'G';
    time[7] = 'M';
    time[8] = 'T';
    this->time = time;
    string a;
    return rec(0,a);
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
		cout << "Testing TheTriangleBothDivs (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1399386287;
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
		TheTriangleBothDivs _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string time = "17:45 GMT-4";
				_expected = "21:45";
				_received = _obj.fix(time); break;
			}
			case 1:
			{
				string time = "16:?? GMT??";
				_expected = "00:00";
				_received = _obj.fix(time); break;
			}
			case 2:
			{
				string time = "?1:34 GMT-9";
				_expected = "06:34";
				_received = _obj.fix(time); break;
			}
			case 3:
			{
				string time = "??:?? GMT??";
				_expected = "00:00";
				_received = _obj.fix(time); break;
			}
			case 4:
			{
				string time = "?5:?? GMT+1";
				_expected = "04:00";
				_received = _obj.fix(time); break;
			}
			/*case 5:
			{
				string time = ;
				_expected = ;
				_received = _obj.fix(time); break;
			}*/
			/*case 6:
			{
				string time = ;
				_expected = ;
				_received = _obj.fix(time); break;
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
