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
int mem[51][10];

class LuckyRemainder {
 public:
  string X;
  int rec(int idx, int sofar) {
    int& r = mem[idx][sofar];
    if (r != -1) return r;
    if (idx == X.size()) return r = sofar;
    return r = (rec(idx+1,sofar)+rec(idx+1,(sofar+X[idx]-'0')%9))%9;
  }
  int getLuckyRemainder(string X) {
    this->X = X;
    memset(mem,-1,sizeof(mem));
    return rec(0,0);
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
		cout << "Testing LuckyRemainder (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393360221;
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
		LuckyRemainder _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string X = "123";
				_expected = 6;
				_received = _obj.getLuckyRemainder(X); break;
			}
			case 1:
			{
				string X = "24816";
				_expected = 3;
				_received = _obj.getLuckyRemainder(X); break;
			}
			case 2:
			{
				string X = "8";
				_expected = 8;
				_received = _obj.getLuckyRemainder(X); break;
			}
			case 3:
			{
				string X = "11235813213455";
				_expected = 7;
				_received = _obj.getLuckyRemainder(X); break;
			}
			/*case 4:
			{
				string X = ;
				_expected = ;
				_received = _obj.getLuckyRemainder(X); break;
			}*/
			/*case 5:
			{
				string X = ;
				_expected = ;
				_received = _obj.getLuckyRemainder(X); break;
			}*/
			/*case 6:
			{
				string X = ;
				_expected = ;
				_received = _obj.getLuckyRemainder(X); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
