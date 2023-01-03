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
const int kMod = 1e9+7;
LL mem[51][51][51][51];

class VocaloidsAndSongs {
 public:
  int S;
  LL rec(int idx, int gumi, int ia, int mayu) {
    LL& r = mem[idx][gumi][ia][mayu];
    if (r != -1) return r;
    if (idx == S) {
      if (!gumi && !ia && !mayu) return r = 1;
      return r = 0;
    }
    LL t = 0;
    if (gumi) (t+=rec(idx+1,gumi-1,ia,mayu))%=kMod;
    if (ia) (t+=rec(idx+1,gumi,ia-1,mayu))%=kMod;
    if (mayu) (t+=rec(idx+1,gumi,ia,mayu-1))%=kMod;
    if (gumi && ia) (t+=rec(idx+1,gumi-1,ia-1,mayu))%=kMod;
    if (gumi && mayu) (t+=rec(idx+1,gumi-1,ia,mayu-1))%=kMod;
    if (mayu && ia) (t+=rec(idx+1,gumi,ia-1,mayu-1))%=kMod;
    if (gumi && ia && mayu) (t+=rec(idx+1,gumi-1,ia-1,mayu-1))%=kMod;
    return r = t;
  }
  int count(int S, int gumi, int ia, int mayu) {
    this->S = S;
    memset(mem,-1,sizeof(mem));
    return rec(0,gumi,ia,mayu);
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
		cout << "Testing VocaloidsAndSongs (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415733638;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 950.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		VocaloidsAndSongs _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int S = 3;
				int gumi = 1;
				int ia = 1;
				int mayu = 1;
				_expected = 6;
				_received = _obj.count(S, gumi, ia, mayu); break;
			}
			case 1:
			{
				int S = 3;
				int gumi = 3;
				int ia = 1;
				int mayu = 1;
				_expected = 9;
				_received = _obj.count(S, gumi, ia, mayu); break;
			}
			case 2:
			{
				int S = 50;
				int gumi = 10;
				int ia = 10;
				int mayu = 10;
				_expected = 0;
				_received = _obj.count(S, gumi, ia, mayu); break;
			}
			case 3:
			{
				int S = 18;
				int gumi = 12;
				int ia = 8;
				int mayu = 9;
				_expected = 81451692;
				_received = _obj.count(S, gumi, ia, mayu); break;
			}
			case 4:
			{
				int S = 50;
				int gumi = 25;
				int ia = 25;
				int mayu = 25;
				_expected = 198591037;
				_received = _obj.count(S, gumi, ia, mayu); break;
			}
			/*case 5:
			{
				int S = ;
				int gumi = ;
				int ia = ;
				int mayu = ;
				_expected = ;
				_received = _obj.count(S, gumi, ia, mayu); break;
			}*/
			/*case 6:
			{
				int S = ;
				int gumi = ;
				int ia = ;
				int mayu = ;
				_expected = ;
				_received = _obj.count(S, gumi, ia, mayu); break;
			}*/
			/*case 7:
			{
				int S = ;
				int gumi = ;
				int ia = ;
				int mayu = ;
				_expected = ;
				_received = _obj.count(S, gumi, ia, mayu); break;
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
