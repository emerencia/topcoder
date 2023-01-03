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
LL mem[51][102][1<<11];

class AlienAndSetDiv2 {
 public:
  int N, K;
  int highestbit(int n) {
    for (int i=30;i>=0;i--)
      if (n&(1<<i))
        return i;
    return -1;
  }
  LL rec(int idx, int lastA, int used) {
    if (lastA+highestbit(used) > 2*N) return 0;
    LL& r = mem[idx][lastA][used];
    if (r != -1) return r;
    if (idx == N-1) return r = 1;
    LL t = 0;
    int nextA = 1+lastA;
    while (used&(1<<(nextA-lastA))) ++nextA;
    int lastB = lastA+highestbit(used);
    LL fac = 1;
    if (nextA > lastB) fac = 2;
    used >>= nextA-lastA;
    for (int nextB=max(lastB+1,nextA+1);nextB-nextA<=K;nextB++) {
      int onextb = nextB-nextA;
      if (nextB == nextA || used&(1<<onextb)) continue;
      (t+= fac*rec(idx+1,nextA,used|(1<<onextb)))%=kMod;
    }
    return r = t;
  }
  int getNumber(int N, int K) {
    this->N = N;
    this->K = K;
    memset(mem,-1,sizeof(mem));
    LL r = 0;
    for (int i=1;i<=K;i++)
      (r+= (2LL*rec(0,1,1<<i))%kMod)%=kMod;
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
	char* b[2];
	if(tt!=-1){b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing AlienAndSetDiv2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397058317;
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
		AlienAndSetDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int K = 1;
				_expected = 4;
				_received = _obj.getNumber(N, K); break;
			}
			case 1:
			{
				int N = 3;
				int K = 1;
				_expected = 8;
				_received = _obj.getNumber(N, K); break;
			}
			case 2:
			{
				int N = 4;
				int K = 2;
				_expected = 44;
				_received = _obj.getNumber(N, K); break;
			}
			case 3:
			{
				int N = 10;
				int K = 10;
				_expected = 184756;
				_received = _obj.getNumber(N, K); break;
			}
			/*case 4:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.getNumber(N, K); break;
			}*/
			/*case 5:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.getNumber(N, K); break;
			}*/
			/*case 6:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.getNumber(N, K); break;
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
