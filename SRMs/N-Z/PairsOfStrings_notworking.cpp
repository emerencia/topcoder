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
int comb[51][51];

class PairsOfStrings {
 public:
  long long modPow(long long x, long long y) {
    long long r=1;
    long long a=x;
    while (y > 0) {
        if ( (y&1)==1 ) {
            r = (r * a)%kMod;
        }
        a = (a * a)%kMod;
        y /= 2;
    }
    return r;
  }
  LL stirling2timesfac(int n, int k) {
	  if (k < 0 || k > n) return 0;
	  LL r = 0;
	  for (int i=0;i<k;i++)
	    (r+= ((i%2 ? -1LL : 1LL) * comb[k][i] * modPow(k-i,n))%kMod)%=kMod;
	  return r;
  }
  int getNumber(int n, int k) {
    for (int i=0;i<=50;i++) {
      comb[i][0] = comb[i][i] = 1;
      for (int j=1;j<i;j++)
        comb[i][j] = (comb[i-1][j]+comb[i-1][j-1])%kMod;
    }
    LL r = 0;
    for (int i=1;i<=k;i++) {
      (r += ((LL)(1)*comb[k][i]*stirling2timesfac(n,i))%kMod)%=kMod;
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
		cout << "Testing PairsOfStrings (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393610406;
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
		PairsOfStrings _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int k = 2;
				_expected = 6;
				_received = _obj.getNumber(n, k); break;
			}
			case 1:
			{
				int n = 3;
				int k = 2;
				_expected = 20;
				_received = _obj.getNumber(n, k); break;
			}
			case 2:
			{
				int n = 3;
				int k = 4;
				_expected = 184;
				_received = _obj.getNumber(n, k); break;
			}
			case 3:
			{
				int n = 6;
				int k = 2;
				_expected = 348;
				_received = _obj.getNumber(n, k); break;
			}
			case 4:
			{
				int n = 100;
				int k = 26;
				_expected = 46519912;
				_received = _obj.getNumber(n, k); break;
			}
			case 5:
			{
				int n = 2;
				int k = 2;
				_expected = 6;
				_received = _obj.getNumber(n, k); break;
			}
			/*case 6:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.getNumber(n, k); break;
			}*/
			/*case 7:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.getNumber(n, k); break;
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
