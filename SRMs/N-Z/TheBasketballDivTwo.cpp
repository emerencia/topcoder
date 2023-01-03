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

class TheBasketballDivTwo {
 public:
  int rec(int idx, const vector<int>& undecided, vector<int>& wins) {
    if (idx == undecided.size()) {
      int mx = 0;
      for (int i=0;i<wins.size();i++)
        mx = max(mx,wins[i]);
      return mx;
    }
    int mn = 1e6;
    for (int i=0;i<6;i++) {
      if (!(undecided[idx]&(1<<i))) continue;
      wins[i]++;
      mn = min(mn,rec(idx+1,undecided,wins));
      wins[i]--;
    }
    return mn;
  }
  int find(vector <string> table) {
    vector<int> wins(table.size(),0);
    vector<int> undecided;
    for (int i=0;i<table.size();i++)
      for (int j=0;j<table[i].size();j++) {
        if (i == j) continue;
        if (table[i][j] == 'W') wins[i]++;
        else if (table[i][j] == 'L') wins[j]++;
        else undecided.push_back((1<<i)+(1<<j));
      }
    return rec(0,undecided,wins);
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
		cout << "Testing TheBasketballDivTwo (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398679570;
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
		TheBasketballDivTwo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string table[] = {"X?", "?X"};
				_expected = 1;
				_received = _obj.find(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 1:
			{
				string table[] = {"XW", "LX"};
				_expected = 2;
				_received = _obj.find(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 2:
			{
				string table[] = {"XWL", "?XW", "WLX"};
				_expected = 2;
				_received = _obj.find(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 3:
			{
				string table[] = {"XW?", "LX?", "??X"};
				_expected = 2;
				_received = _obj.find(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			/*case 4:
			{
				string table[] = ;
				_expected = ;
				_received = _obj.find(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string table[] = ;
				_expected = ;
				_received = _obj.find(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string table[] = ;
				_expected = ;
				_received = _obj.find(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
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
