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

class LinearPolyominoCovering {
 public:
  string findCovering(string region) {
    string r;
    for (int i=0;i<region.size();i++) {
      if (region[i] != 'X') {
        r+= '.';
        continue;
      }
      if (region.substr(i,4) == "XXXX") {
        i+=3;
        r+="AAAA";
        continue;
      }
      if (region.substr(i,2) == "XX") {
        i+=1;
        r+="BB";
        continue;
      }
      return "impossible";
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
	if(tt!=-1){char* b[2];b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}	if (argc == 1) 
	{
		cout << "Testing LinearPolyominoCovering (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393353563;
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
		LinearPolyominoCovering _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string region = "XXXXXX";
				_expected = "AAAABB";
				_received = _obj.findCovering(region); break;
			}
			case 1:
			{
				string region = "XX.XX";
				_expected = "BB.BB";
				_received = _obj.findCovering(region); break;
			}
			case 2:
			{
				string region = "XXXX....XXX.....XX";
				_expected = "impossible";
				_received = _obj.findCovering(region); break;
			}
			case 3:
			{
				string region = "X";
				_expected = "impossible";
				_received = _obj.findCovering(region); break;
			}
			case 4:
			{
				string region = "XX.XXXXXXXXXX..XXXXXXXX...XXXXXX";
				_expected = "BB.AAAAAAAABB..AAAAAAAA...AAAABB";
				_received = _obj.findCovering(region); break;
			}
			/*case 5:
			{
				string region = ;
				_expected = ;
				_received = _obj.findCovering(region); break;
			}*/
			/*case 6:
			{
				string region = ;
				_expected = ;
				_received = _obj.findCovering(region); break;
			}*/
			/*case 7:
			{
				string region = ;
				_expected = ;
				_received = _obj.findCovering(region); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
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
