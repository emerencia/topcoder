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

class FriendScore {
 public:
  int highestScore(vector <string> friends) {
    int mx = 0;
    for (int i=0;i<friends.size();i++) {
      int cur = 0;
      for (int j=0;j<friends[0].size();j++) {
        if (i == j) continue;
        if (friends[i][j] == 'Y' && friends[j][i] == 'Y') {
          cur++;
          continue;
        }
        bool good = false;
        for (int k=0;k<friends[0].size();k++)
          if (friends[i][k] == 'Y' && friends[k][j] == 'Y') {
            good = true;
            break;
          }
        if (!good) continue;
        cur++;
      }
      mx = max(mx,cur);
    }
    return mx;
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
		cout << "Testing FriendScore (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394471766;
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
		FriendScore _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string friends[] = {"NNN",
				                    "NNN",
				                    "NNN"};
				_expected = 0;
				_received = _obj.highestScore(vector <string>(friends, friends+sizeof(friends)/sizeof(string))); break;
			}
			case 1:
			{
				string friends[] = {"NYY",
				                    "YNY",
				                    "YYN"};
				_expected = 2;
				_received = _obj.highestScore(vector <string>(friends, friends+sizeof(friends)/sizeof(string))); break;
			}
			case 2:
			{
				string friends[] = {"NYNNN",
				                    "YNYNN", 
				                    "NYNYN", 
				                    "NNYNY", 
				                    "NNNYN"};
				_expected = 4;
				_received = _obj.highestScore(vector <string>(friends, friends+sizeof(friends)/sizeof(string))); break;
			}
			case 3:
			{
				string friends[] = {"NNNNYNNNNN",
				                    "NNNNYNYYNN",
				                    "NNNYYYNNNN",
				                    "NNYNNNNNNN",
				                    "YYYNNNNNNY",
				                    "NNYNNNNNYN",
				                    "NYNNNNNYNN",
				                    "NYNNNNYNNN",
				                    "NNNNNYNNNN",
				                    "NNNNYNNNNN"};
				_expected = 8;
				_received = _obj.highestScore(vector <string>(friends, friends+sizeof(friends)/sizeof(string))); break;
			}
			case 4:
			{
				string friends[] = {"NNNNNNNNNNNNNNY",
				                    "NNNNNNNNNNNNNNN",
				                    "NNNNNNNYNNNNNNN",
				                    "NNNNNNNYNNNNNNY",
				                    "NNNNNNNNNNNNNNY",
				                    "NNNNNNNNYNNNNNN",
				                    "NNNNNNNNNNNNNNN",
				                    "NNYYNNNNNNNNNNN",
				                    "NNNNNYNNNNNYNNN",
				                    "NNNNNNNNNNNNNNY",
				                    "NNNNNNNNNNNNNNN",
				                    "NNNNNNNNYNNNNNN",
				                    "NNNNNNNNNNNNNNN",
				                    "NNNNNNNNNNNNNNN",
				                    "YNNYYNNNNYNNNNN"};
				_expected = 6;
				_received = _obj.highestScore(vector <string>(friends, friends+sizeof(friends)/sizeof(string))); break;
			}
			/*case 5:
			{
				string friends[] = ;
				_expected = ;
				_received = _obj.highestScore(vector <string>(friends, friends+sizeof(friends)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string friends[] = ;
				_expected = ;
				_received = _obj.highestScore(vector <string>(friends, friends+sizeof(friends)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string friends[] = ;
				_expected = ;
				_received = _obj.highestScore(vector <string>(friends, friends+sizeof(friends)/sizeof(string))); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
