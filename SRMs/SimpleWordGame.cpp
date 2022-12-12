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

class SimpleWordGame {
 public:
  int points(vector <string> player, vector <string> dictionary) {
    int r = 0;
    for (int i=0;i<dictionary.size();i++)
      for (int j=0;j<player.size();j++)
        if (player[j] == dictionary[i]) {
          r+= dictionary[i].size()*dictionary[i].size();
          break;
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
		cout << "Testing SimpleWordGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395983847;
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
		SimpleWordGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string player[] = { "apple", "orange", "strawberry" };
				string dictionary[] = { "strawberry", "orange", "grapefruit", "watermelon" };
				_expected = 136;
				_received = _obj.points(vector <string>(player, player+sizeof(player)/sizeof(string)), vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}
			case 1:
			{
				string player[] = { "apple" };
				string dictionary[] = { "strawberry", "orange", "grapefruit", "watermelon" };
				_expected = 0;
				_received = _obj.points(vector <string>(player, player+sizeof(player)/sizeof(string)), vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}
			case 2:
			{
				string player[] = { "orange", "orange" };
				string dictionary[] = { "strawberry", "orange", "grapefruit", "watermelon" };
				_expected = 36;
				_received = _obj.points(vector <string>(player, player+sizeof(player)/sizeof(string)), vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}
			case 3:
			{
				string player[] = { "lidi", "o", "lidi", "gnbewjzb", "kten",
				                    "ebnelff", "gptsvqx", "rkauxq", "rkauxq", "kfkcdn"};
				string dictionary[] = { "nava", "wk", "kfkcdn", "lidi", "gptsvqx",
				                        "ebnelff", "hgsppdezet", "ulf", "rkauxq", "wcicx"};
				_expected = 186;
				_received = _obj.points(vector <string>(player, player+sizeof(player)/sizeof(string)), vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}
			/*case 4:
			{
				string player[] = ;
				string dictionary[] = ;
				_expected = ;
				_received = _obj.points(vector <string>(player, player+sizeof(player)/sizeof(string)), vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string player[] = ;
				string dictionary[] = ;
				_expected = ;
				_received = _obj.points(vector <string>(player, player+sizeof(player)/sizeof(string)), vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string player[] = ;
				string dictionary[] = ;
				_expected = ;
				_received = _obj.points(vector <string>(player, player+sizeof(player)/sizeof(string)), vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
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
