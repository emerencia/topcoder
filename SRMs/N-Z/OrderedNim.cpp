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

class OrderedNim {
 public:
  string winner(vector <int> layout) {
    if (layout.size() == 1) return "Alice";
    vector<string> winners;
    winners.push_back("Alice");
    winners.push_back("Bob");
    int winner = 0;
    for (int i=0;i+1<layout.size();i++) {
      if (layout[i] != 1)
        return winners[winner];
      winner = 1-winner;
    }
    return winners[winner];
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
		cout << "Testing OrderedNim (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397511299;
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
		OrderedNim _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int layout[] = {5};
				_expected = "Alice";
				_received = _obj.winner(vector <int>(layout, layout+sizeof(layout)/sizeof(int))); break;
			}
			case 1:
			{
				int layout[] = {1,2};
				_expected = "Bob";
				_received = _obj.winner(vector <int>(layout, layout+sizeof(layout)/sizeof(int))); break;
			}
			case 2:
			{
				int layout[] = {2,1};
				_expected = "Alice";
				_received = _obj.winner(vector <int>(layout, layout+sizeof(layout)/sizeof(int))); break;
			}
			case 3:
			{
				int layout[] = {10,9,8,7,6,5,4,3,2,1};
				_expected = "Alice";
				_received = _obj.winner(vector <int>(layout, layout+sizeof(layout)/sizeof(int))); break;
			}
			case 4:
			{
				int layout[] = {1,1,1,1};
				_expected = "Bob";
				_received = _obj.winner(vector <int>(layout, layout+sizeof(layout)/sizeof(int))); break;
			}
			case 5:
			{
				int layout[] = {1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 2, 1};
				_expected = "Bob";
				_received = _obj.winner(vector <int>(layout, layout+sizeof(layout)/sizeof(int))); break;
			}
			/*case 6:
			{
				int layout[] = ;
				_expected = ;
				_received = _obj.winner(vector <int>(layout, layout+sizeof(layout)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int layout[] = ;
				_expected = ;
				_received = _obj.winner(vector <int>(layout, layout+sizeof(layout)/sizeof(int))); break;
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
