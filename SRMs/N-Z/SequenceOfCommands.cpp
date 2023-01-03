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

class SequenceOfCommands {
 public:
  string whatHappens(vector <string> commands) {
    string allcommands = accumulate(commands.begin(),commands.end(),string(""));
    int facing = 0;
    PII position = PII(0,0);
    for (int k=0;k<4;k++) {
      for (int i=0;i<allcommands.size();i++) {
        if (allcommands[i] == 'S') {
          position.first += dx[facing];
          position.second += dy[facing];
        } else if (allcommands[i] == 'L') {
          facing = (facing+3)%4;
        } else {
          facing = (facing+1)%4;
        }
      }
      if (position.first == 0 && position.second == 0 && facing == 0)
        return "bounded";
    }
    return "unbounded";
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
		cout << "Testing SequenceOfCommands (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1414275961;
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
		SequenceOfCommands _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string commands[] = {"L"};
				_expected = "bounded";
				_received = _obj.whatHappens(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
			}
			case 1:
			{
				string commands[] = {"SRSL"};
				_expected = "unbounded";
				_received = _obj.whatHappens(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
			}
			case 2:
			{
				string commands[] = {"SSSS","R"};
				_expected = "bounded";
				_received = _obj.whatHappens(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
			}
			case 3:
			{
				string commands[] = {"SRSL","LLSSSSSSL","SSSSSS","L"};
				_expected = "unbounded";
				_received = _obj.whatHappens(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
			}
			/*case 4:
			{
				string commands[] = ;
				_expected = ;
				_received = _obj.whatHappens(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string commands[] = ;
				_expected = ;
				_received = _obj.whatHappens(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string commands[] = ;
				_expected = ;
				_received = _obj.whatHappens(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
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
