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
// 21:02 rewrite with numbers
// END CUT HERE
int mem[1<<10];
bool has[1<<10];

class EllysCandyGame {
 public:
  vector<int> sweets;
  int getvalue(int state, int idx) {
    int r = sweets[idx];
    if (idx > 0 && state&(1<<(idx-1))) r*=2;
    if (idx+1 < sweets.size() && state&(1<<(idx+1))) r*=2;
    return r;
  }
  int rec(int state) {
    int& r = mem[state];
    if (has[state]) return r;
    has[state] = 1;
    int t = INT_MIN;
    for (int i=0;i<sweets.size();i++) {
      if (state&(1<<i) || !sweets[i]) continue;
      t = max(t, getvalue(state, i)-rec(state|(1<<i)));
    }
    if (t == INT_MIN) return r = 0;
    return r = t;
  }
  string getWinner(vector <int> sweets) {
    this->sweets = sweets;
    memset(has,0,sizeof(has));
    int r = rec(0);
    if (r == 0) return "Draw";
    if (r < 0) return "Kris";
    return "Elly";
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
		cout << "Testing EllysCandyGame (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1410265625;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		EllysCandyGame _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int sweets[] = {20, 50, 70, 0, 30};
				_expected = "Kris";
				_received = _obj.getWinner(vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int))); break;
			}
			case 1:
			{
				int sweets[] = {42, 13, 7};
				_expected = "Elly";
				_received = _obj.getWinner(vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int))); break;
			}
			case 2:
			{
				int sweets[] = {10, 20};
				_expected = "Draw";
				_received = _obj.getWinner(vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int))); break;
			}
			case 3:
			{
				int sweets[] = {3, 1, 7, 11, 1, 1};
				_expected = "Kris";
				_received = _obj.getWinner(vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int))); break;
			}
			case 4:
			{
				int sweets[] = {41, 449, 328, 474, 150, 501, 467, 329, 536, 440};
				_expected = "Kris";
				_received = _obj.getWinner(vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int))); break;
			}
			case 5:
			{
				int sweets[] = {177, 131, 142, 171, 411, 391, 17, 222, 100, 298};
				_expected = "Elly";
				_received = _obj.getWinner(vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int))); break;
			}
			/*case 6:
			{
				int sweets[] = ;
				_expected = ;
				_received = _obj.getWinner(vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int sweets[] = ;
				_expected = ;
				_received = _obj.getWinner(vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int sweets[] = ;
				_expected = ;
				_received = _obj.getWinner(vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int))); break;
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
