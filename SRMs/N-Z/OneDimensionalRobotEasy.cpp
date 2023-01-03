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

class OneDimensionalRobotEasy {
 public:
  int finalPosition(string commands, int A, int B) {
    int pos = 0;
    for (int i=0;i<commands.size();i++) {
      if (commands[i] == 'L' && pos > -A) pos--;
      if (commands[i] == 'R' && pos < B) pos++;
    }
    return pos;
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
		cout << "Testing OneDimensionalRobotEasy (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1412623289;
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
		OneDimensionalRobotEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string commands = "RRLRRLLR";
				int A = 10;
				int B = 10;
				_expected = 2;
				_received = _obj.finalPosition(commands, A, B); break;
			}
			case 1:
			{
				string commands = "RRRRR";
				int A = 3;
				int B = 4;
				_expected = 4;
				_received = _obj.finalPosition(commands, A, B); break;
			}
			case 2:
			{
				string commands = "LLLLLLLLLLR";
				int A = 2;
				int B = 6;
				_expected = -1;
				_received = _obj.finalPosition(commands, A, B); break;
			}
			case 3:
			{
				string commands = "RRRRRRRLRRLRRRRRRRRRRRRLRLRRRRRRRRLRRRRRLRRRRRRRRR";
				int A = 5;
				int B = 20;
				_expected = 20;
				_received = _obj.finalPosition(commands, A, B); break;
			}
			case 4:
			{
				string commands = "RLRLLLLLLLRLLLRLLLLLLLLRLLLLLRLLLRRLLLLLRLLLLLRLLL";
				int A = 34;
				int B = 15;
				_expected = -30;
				_received = _obj.finalPosition(commands, A, B); break;
			}
			/*case 5:
			{
				string commands = ;
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.finalPosition(commands, A, B); break;
			}*/
			/*case 6:
			{
				string commands = ;
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.finalPosition(commands, A, B); break;
			}*/
			/*case 7:
			{
				string commands = ;
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.finalPosition(commands, A, B); break;
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
