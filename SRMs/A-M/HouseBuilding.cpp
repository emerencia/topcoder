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

class HouseBuilding {
 public:
  int getMinimum(vector <string> area) {
    int r = INT_MAX;
    for (int k=0;k<9;k++) {
      int c = 0;
      for (int i=0;i<area.size();i++)
        for (int j=0;j<area[i].size();j++) {
          if (abs(area[i][j]-'0'-k) > 0 && abs(area[i][j]-'0'-(k+1)) > 0)
            c+= min(abs(area[i][j]-'0'-(k+1)),abs(area[i][j]-'0'-k));
        }
      r = min(r,c);
    }
    return r;
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
		cout << "Testing HouseBuilding (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396725720;
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
		HouseBuilding _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string area[] = {"10",
				                 "31"};
				_expected = 2;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
			}
			case 1:
			{
				string area[] = {"54454",
				                 "61551"};
				_expected = 7;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
			}
			case 2:
			{
				string area[] = {"989"};
				_expected = 0;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
			}
			case 3:
			{
				string area[] = {"90"};
				_expected = 8;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
			}
			case 4:
			{
				string area[] = {"5781252",
				                 "2471255",
				                 "0000291",
				                 "1212489"};
				_expected = 53;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
			}
			/*case 5:
			{
				string area[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string area[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string area[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
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
