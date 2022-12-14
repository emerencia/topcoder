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
const int tt = 0;
// 
// END CUT HERE
int mem[4000];

class PotatoGame {
 public:
  bool rec(int n) {
    if (!n) return false;
    int& r = mem[n];
    if (r != -1) return r;
    int t = 0;
    int i = 1;
    while (i <= n) {
      t |= !rec(n-i);
      if (t) break;
      i *= 4;
    }
    return (r = t);
  }
  string theWinner(int n) {
    memset(mem,-1,sizeof(mem));
    for (int i=0;i < 100;i++)
      if (!rec(i))
        cout << i << endl;
    return rec(n) ? "Taro" : "Hanako";
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
		cout << "Testing PotatoGame (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1414269088;
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
		PotatoGame _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 1;
				_expected = "Taro";
				_received = _obj.theWinner(n); break;
			}
			case 1:
			{
				int n = 2;
				_expected = "Hanako";
				_received = _obj.theWinner(n); break;
			}
			case 2:
			{
				int n = 3;
				_expected = "Taro";
				_received = _obj.theWinner(n); break;
			}
			/*case 3:
			{
				int n = ;
				_expected = ;
				_received = _obj.theWinner(n); break;
			}*/
			/*case 4:
			{
				int n = ;
				_expected = ;
				_received = _obj.theWinner(n); break;
			}*/
			/*case 5:
			{
				int n = ;
				_expected = ;
				_received = _obj.theWinner(n); break;
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
