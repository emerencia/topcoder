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
const int kMod = 1e9+7;
LL mem[2001][2048][2];

class WinterAndSnowmen {
 public:
  int N;
  int M;
  int k;
  int mask;
  LL rec(int i, int xy, int b) {
    LL& r = mem[i][xy][b];
    if (r != -1) return r;
    if (i == 0) {
      if (xy == 1 && b == 0)
        return r = 1;
      return r = 0;
    }
    LL t = 0;
    if (i <= N)
      (t += rec(i-1,xy^(i>>k),b^((i>>k)&1)))%=kMod;
    if (i <= M)
      (t += rec(i-1,xy^(i>>k),b))%=kMod;
    (t += rec(i-1,xy,b))%=kMod;
    return r = t;
  }
  int getNumber(int N, int M) {
    this->N = N;
    this->M = M;
    LL r = 0;
    for (int i=0;(1<<i)<=max(M,N);i++) {
      memset(mem,-1,sizeof(mem));
      k = i;
      mask = ~((1<<i)-1);
      (r += rec(max(N,M),0,0))%=kMod;
    }
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
		cout << "Testing WinterAndSnowmen (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391214735;
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
		WinterAndSnowmen _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int M = 2;
				_expected = 4;
				_received = _obj.getNumber(N, M); break;
			}
			case 1:
			{
				int N = 1;
				int M = 1;
				_expected = 1;
				_received = _obj.getNumber(N, M); break;
			}
			case 2:
			{
				int N = 3;
				int M = 5;
				_expected = 74;
				_received = _obj.getNumber(N, M); break;
			}
			case 3:
			{
				int N = 7;
				int M = 4;
				_expected = 216;
				_received = _obj.getNumber(N, M); break;
			}
			case 4:
			{
				int N = 47;
				int M = 74;
				_expected = 962557390;
				_received = _obj.getNumber(N, M); break;
			}
			case 5:
			{
				int N = 2000;
				int M = 2000;
				_expected = 11685307;
				_received = _obj.getNumber(N, M); break;
			}
			/*case 6:
			{
				int N = ;
				int M = ;
				_expected = ;
				_received = _obj.getNumber(N, M); break;
			}*/
			/*case 7:
			{
				int N = ;
				int M = ;
				_expected = ;
				_received = _obj.getNumber(N, M); break;
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
