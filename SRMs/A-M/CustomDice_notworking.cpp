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
typedef pair<PII,int> PIII;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE
const int kMod = 1e9+7;
map<PIII,LL> mem;

class CustomDice {
 public:
  int tot;
  long long rec(int numbersleft, int sumleft, int last) {
    if (mem.count(PIII(PII(numbersleft,sumleft),last)))
      return mem[PIII(PII(numbersleft,sumleft),last)];
    // number of ways to sum up to ..
    if (numbersleft == 1) {
      if (sumleft > last) return mem[PIII(PII(numbersleft,sumleft),last)]=1;
      return mem[PIII(PII(numbersleft,sumleft),last)]=0;
    }
    long long t = 0;
    for (int i=last+1;numbersleft*i<sumleft;i++)
      t += rec(numbersleft-1,sumleft-i,i);
    return mem[PIII(PII(numbersleft,sumleft),last)]=t;
  }
  int countDice(int M) {
    mem.clear();
    tot = 6*M;
    long long r = 0;
    for (int i=21;i<=tot;i++)
      (r+=30LL*rec(6,i,0))%=kMod;
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
		cout << "Testing CustomDice (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390593470;
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
		CustomDice _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int M = 3;
				_expected = 0;
				_received = _obj.countDice(M); break;
			}
			case 1:
			{
				int M = 4;
				_expected = 210;
				_received = _obj.countDice(M); break;
			}
			case 2:
			{
				int M = 10;
				_expected = 863010;
				_received = _obj.countDice(M); break;
			}
			case 3:
			{
				int M = 50;
				_expected = 375588112;
				_received = _obj.countDice(M); break;
			}
			case 4:
			{
				int M = 10000;
				_expected = 276610130;
				_received = _obj.countDice(M); break;
			}
			/*case 5:
			{
				int M = ;
				_expected = ;
				_received = _obj.countDice(M); break;
			}*/
			/*case 6:
			{
				int M = ;
				_expected = ;
				_received = _obj.countDice(M); break;
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
