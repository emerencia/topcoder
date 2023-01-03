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

class Undo {
 public:
  struct Action {
    int type;
    string val;
    int time;
    Action(int type, string val, int time) : type(type),val(val),time(time) {}
    int value() {
      stringstream a(val);
      int r;
      a >> r;
      return r;
    }
  };
  string getText(vector <string> commands, vector <int> time) {
    vector<Action> actions;
    for (int i=0;i<commands.size();i++) {
      stringstream a(commands[i]);
      string type, val;
      a >> type >> val;
      actions.push_back(Action(type == "type",val,time[i]));
      // type 1 = type, 0 = undo
    }
    vector<bool> valid(actions.size(),true);
    for (int i=actions.size()-1;i>=0;i--) {
      if (actions[i].type) continue;
      if (!valid[i]) cout << "error: not valid" << endl;
      int downto = actions[i].time-actions[i].value();
      while (i >=0 && actions[i].time >= downto) {
        valid[i] = false;
        i--;
      }
      i++;
    }
    string r;
    for (int i=0;i<actions.size();i++) {
      if (!valid[i]) continue;
      r+=actions[i].val;
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
		cout << "Testing Undo (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392048634;
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
		Undo _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string commands[] = {"type a", "type b", "type c", "undo 3"};
				int time[] = {1, 2, 3, 5};
				_expected = "a";
				_received = _obj.getText(vector <string>(commands, commands+sizeof(commands)/sizeof(string)), vector <int>(time, time+sizeof(time)/sizeof(int))); break;
			}
			case 1:
			{
				string commands[] = {"type a", "type b", "undo 2", "undo 2"};
				int time[] = {1,2,3,4};
				_expected = "a";
				_received = _obj.getText(vector <string>(commands, commands+sizeof(commands)/sizeof(string)), vector <int>(time, time+sizeof(time)/sizeof(int))); break;
			}
			case 2:
			{
				string commands[] = {"type a", "undo 1", "undo 1"};
				int time[] = {1,2,3};
				_expected = "a";
				_received = _obj.getText(vector <string>(commands, commands+sizeof(commands)/sizeof(string)), vector <int>(time, time+sizeof(time)/sizeof(int))); break;
			}
			case 3:
			{
				string commands[] = {"type a", "type b", "type c", "undo 10"};
				int time[] = {1, 2, 3, 1000};
				_expected = "abc";
				_received = _obj.getText(vector <string>(commands, commands+sizeof(commands)/sizeof(string)), vector <int>(time, time+sizeof(time)/sizeof(int))); break;
			}
			case 4:
			{
				string commands[] = {"undo 1"};
				int time[] = {1};
				_expected = "";
				_received = _obj.getText(vector <string>(commands, commands+sizeof(commands)/sizeof(string)), vector <int>(time, time+sizeof(time)/sizeof(int))); break;
			}
			/*case 5:
			{
				string commands[] = ;
				int time[] = ;
				_expected = ;
				_received = _obj.getText(vector <string>(commands, commands+sizeof(commands)/sizeof(string)), vector <int>(time, time+sizeof(time)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				string commands[] = ;
				int time[] = ;
				_expected = ;
				_received = _obj.getText(vector <string>(commands, commands+sizeof(commands)/sizeof(string)), vector <int>(time, time+sizeof(time)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				string commands[] = ;
				int time[] = ;
				_expected = ;
				_received = _obj.getText(vector <string>(commands, commands+sizeof(commands)/sizeof(string)), vector <int>(time, time+sizeof(time)/sizeof(int))); break;
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
