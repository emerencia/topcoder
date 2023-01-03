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

class DoorsGame {
 public:
  int determineOutcome(string doors, int trophy) {
    set<char> jchars;
    set<char> gchars;
    for (int i=0;i<doors.size();i++)
      if (i < trophy)
        jchars.insert(doors[i]);
      else
        gchars.insert(doors[i]);
    int jdchars = jchars.size();
    int gdchars = gchars.size();
    int inboth = 0;
    for (set<char>::iterator i=jchars.begin();i!=jchars.end();i++)
      if (gchars.count(*i))
        ++inboth;
    if (jchars == gchars) return 0;
    if (inboth && (abs(jdchars-gdchars) < inboth || jdchars-gdchars == inboth)) return 0;
    if (jdchars <= gdchars) {
      return min(16,2*jdchars -1);
    } else {
      return -min(16,2*gdchars);
    }
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
		cout << "Testing DoorsGame (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1409771350;
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
		DoorsGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string doors = "ABCD";
				int trophy = 2;
				_expected = 3;
				_received = _obj.determineOutcome(doors, trophy); break;
			}
			case 1:
			{
				string doors = "ABCC";
				int trophy = 2;
				_expected = -2;
				_received = _obj.determineOutcome(doors, trophy); break;
			}
			case 2:
			{
				string doors = "ABABAB";
				int trophy = 3;
				_expected = 0;
				_received = _obj.determineOutcome(doors, trophy); break;
			}
			case 3:
			{
				string doors = "ABAPDCAA";
				int trophy = 5;
				_expected = -4;
				_received = _obj.determineOutcome(doors, trophy); break;
			}
			case 4:
			{
				string doors = "MOCFDCE";
				int trophy = 3;
				_expected = 5;
				_received = _obj.determineOutcome(doors, trophy); break;
			}
			case 5:
			{
				string doors = "ABCCDE";
				int trophy = 3;
				_expected = 0;
				_received = _obj.determineOutcome(doors, trophy); break;
			}
			case 6:
			{
				string doors = "ABCCD";
				int trophy = 3;
				_expected = 0;
				_received = _obj.determineOutcome(doors, trophy); break;
			}
			case 7:
			{
				string doors = "ABCDEFGHIJKLMNOPABCDEFGHIJKLMNOP";
				int trophy = 9;
				_expected = 0;
				_received = _obj.determineOutcome(doors, trophy); break;
			}
			/*case 8:
			{
				string doors = ;
				int trophy = ;
				_expected = ;
				_received = _obj.determineOutcome(doors, trophy); break;
			}*/
			/*case 9:
			{
				string doors = ;
				int trophy = ;
				_expected = ;
				_received = _obj.determineOutcome(doors, trophy); break;
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
