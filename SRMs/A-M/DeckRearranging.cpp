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

class DeckRearranging {
 public:
  string rearrange(string deck, vector <int> above) {
    string s;
    for (int i=0;i<deck.size();i++)
      s = s.substr(0,above[i])+deck[i]+s.substr(above[i]);
    return s;
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
		cout << "Testing DeckRearranging (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392135624;
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
		DeckRearranging _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string deck = "BRBRR";
				int above[] = {0, 0, 1, 0, 3};
				_expected = "RRBRB";
				_received = _obj.rearrange(deck, vector <int>(above, above+sizeof(above)/sizeof(int))); break;
			}
			case 1:
			{
				string deck = "RRRRRR";
				int above[] = {0,1,2,0,1,3};
				_expected = "RRRRRR";
				_received = _obj.rearrange(deck, vector <int>(above, above+sizeof(above)/sizeof(int))); break;
			}
			case 2:
			{
				string deck = "RBRRBRBB";
				int above[] = {0,1,2,3,4,5,6,7};
				_expected = "RBRRBRBB";
				_received = _obj.rearrange(deck, vector <int>(above, above+sizeof(above)/sizeof(int))); break;
			}
			case 3:
			{
				string deck = "RBRRBRBB";
				int above[] = {0,0,0,0,0,0,0,0};
				_expected = "BBRBRRBR";
				_received = _obj.rearrange(deck, vector <int>(above, above+sizeof(above)/sizeof(int))); break;
			}
			case 4:
			{
				string deck = "RBRRBRBB";
				int above[] = {0,1,0,0,4,0,6,7};
				_expected = "RRRRBBBB";
				_received = _obj.rearrange(deck, vector <int>(above, above+sizeof(above)/sizeof(int))); break;
			}
			/*case 5:
			{
				string deck = ;
				int above[] = ;
				_expected = ;
				_received = _obj.rearrange(deck, vector <int>(above, above+sizeof(above)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				string deck = ;
				int above[] = ;
				_expected = ;
				_received = _obj.rearrange(deck, vector <int>(above, above+sizeof(above)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				string deck = ;
				int above[] = ;
				_expected = ;
				_received = _obj.rearrange(deck, vector <int>(above, above+sizeof(above)/sizeof(int))); break;
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
