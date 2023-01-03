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
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

class CubeWalking {
 public:
  string finalPosition(string movement) {
    int dir = 0;
    int x = 1;
    int y = 1;
    for (int i=0;i<movement.size();i++) {
      if (movement[i] == 'L') {
        dir = (dir-1+4)%4;
      } else if (movement[i] == 'R') {
        dir = (dir+1)%4;
      } else {
        x = (x+dx[dir]+3)%3;
        y = (y+dy[dir]+3)%3;
      }
    }
    if (x == 1 && y == 1) return "GREEN";
    if ((x == 0 && y == 2) || (y == 0 && x == 2) ||
        (x == 0 && y == 0) || (x == 2 && y == 2)) return "RED";
    return "BLUE";
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
		cout << "Testing CubeWalking (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396298289;
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
		CubeWalking _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string movement = "LLRR";
				_expected = "GREEN";
				_received = _obj.finalPosition(movement); break;
			}
			case 1:
			{
				string movement = "WWWWWWWWWWWW";
				_expected = "GREEN";
				_received = _obj.finalPosition(movement); break;
			}
			case 2:
			{
				string movement = "WLWRW";
				_expected = "RED";
				_received = _obj.finalPosition(movement); break;
			}
			case 3:
			{
				string movement = "WWLLWRWLWLLRWW";
				_expected = "BLUE";
				_received = _obj.finalPosition(movement); break;
			}
			/*case 4:
			{
				string movement = ;
				_expected = ;
				_received = _obj.finalPosition(movement); break;
			}*/
			/*case 5:
			{
				string movement = ;
				_expected = ;
				_received = _obj.finalPosition(movement); break;
			}*/
			/*case 6:
			{
				string movement = ;
				_expected = ;
				_received = _obj.finalPosition(movement); break;
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
