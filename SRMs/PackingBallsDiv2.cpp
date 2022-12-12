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
int mem[101][101][101];

class PackingBallsDiv2 {
 public:
  int rec(int rr, int gg, int bb) {
    int& r = mem[rr][gg][bb];
    if (r != -1) return r;
    if (!rr && !gg && !bb) return r = 0;
    int t = INT_MAX;
    if (rr && bb && gg) t = min(t,1+rec(rr-1,gg-1,bb-1));
    if (rr > 2) t = min(t,1+rec(rr-3,gg,bb));
    if (gg > 2) t = min(t,1+rec(rr,gg-3,bb));
    if (bb > 2) t = min(t,1+rec(rr,gg,bb-3));
    if (rr && bb) t = min(t,1+rec(rr-1,gg,bb-1));
    if (rr && gg) t = min(t,1+rec(rr-1,gg-1,bb));
    if (gg && bb) t = min(t,1+rec(rr,gg-1,bb-1));
    if (rr > 1) t = min(t,1+rec(rr-2,gg,bb));
    if (gg > 1) t = min(t,1+rec(rr,gg-2,bb));
    if (bb > 1) t = min(t,1+rec(rr,gg,bb-2));
    if (gg) t = min(t,1+rec(rr,gg-1,bb));
    if (rr) t = min(t,1+rec(rr-1,gg,bb));
    if (bb) t = min(t,1+rec(rr,gg,bb-1));
    return r = t;
  }
  int minPacks(int R, int G, int B) {
    memset(mem,-1,sizeof(mem));
    return rec(R,G,B);
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
		cout << "Testing PackingBallsDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415732958;
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
		PackingBallsDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int R = 4;
				int G = 2;
				int B = 4;
				_expected = 4;
				_received = _obj.minPacks(R, G, B); break;
			}
			case 1:
			{
				int R = 1;
				int G = 7;
				int B = 1;
				_expected = 3;
				_received = _obj.minPacks(R, G, B); break;
			}
			case 2:
			{
				int R = 2;
				int G = 3;
				int B = 5;
				_expected = 4;
				_received = _obj.minPacks(R, G, B); break;
			}
			case 3:
			{
				int R = 78;
				int G = 53;
				int B = 64;
				_expected = 66;
				_received = _obj.minPacks(R, G, B); break;
			}
			case 4:
			{
				int R = 100;
				int G = 100;
				int B = 100;
				_expected = 100;
				_received = _obj.minPacks(R, G, B); break;
			}
			/*case 5:
			{
				int R = ;
				int G = ;
				int B = ;
				_expected = ;
				_received = _obj.minPacks(R, G, B); break;
			}*/
			/*case 6:
			{
				int R = ;
				int G = ;
				int B = ;
				_expected = ;
				_received = _obj.minPacks(R, G, B); break;
			}*/
			/*case 7:
			{
				int R = ;
				int G = ;
				int B = ;
				_expected = ;
				_received = _obj.minPacks(R, G, B); break;
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
