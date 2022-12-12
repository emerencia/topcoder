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
int mem[1001][1001];

class PairGameEasy {
 public:
  void rec(int a, int b) {
    if (a > 1000 || b > 1000) return;
    int& r = mem[a][b];
    if (r != -1) return;
    mem[a][b] = 1;
    rec(a+b,b);
    rec(a,a+b);
  }
  string able(int a, int b, int c, int d) {
    memset(mem,-1,sizeof(mem));
    rec(a,b);
    return mem[c][d] == -1 ? "Not able to generate" : "Able to generate";
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
		cout << "Testing PairGameEasy (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1437240599;
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
		PairGameEasy _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a = 1;
				int b = 2;
				int c = 3;
				int d = 5;
				_expected = "Able to generate";
				_received = _obj.able(a, b, c, d); break;
			}
			case 1:
			{
				int a = 1;
				int b = 2;
				int c = 2;
				int d = 1;
				_expected = "Not able to generate";
				_received = _obj.able(a, b, c, d); break;
			}
			case 2:
			{
				int a = 2;
				int b = 2;
				int c = 2;
				int d = 999;
				_expected = "Not able to generate";
				_received = _obj.able(a, b, c, d); break;
			}
			case 3:
			{
				int a = 2;
				int b = 2;
				int c = 2;
				int d = 1000;
				_expected = "Able to generate";
				_received = _obj.able(a, b, c, d); break;
			}
			case 4:
			{
				int a = 47;
				int b = 58;
				int c = 384;
				int d = 221;
				_expected = "Able to generate";
				_received = _obj.able(a, b, c, d); break;
			}
			case 5:
			{
				int a = 1000;
				int b = 1000;
				int c = 1000;
				int d = 1000;
				_expected = "Able to generate";
				_received = _obj.able(a, b, c, d); break;
			}
			/*case 6:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				_expected = ;
				_received = _obj.able(a, b, c, d); break;
			}*/
			/*case 7:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				_expected = ;
				_received = _obj.able(a, b, c, d); break;
			}*/
			/*case 8:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				_expected = ;
				_received = _obj.able(a, b, c, d); break;
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
