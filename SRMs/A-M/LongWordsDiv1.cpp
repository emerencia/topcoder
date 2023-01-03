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
int dp[5002];

class LongWordsDiv1 {
 public:
  long long factorial(long long x) {
    long long c = 1;
    for (long long i=1;i<=x;i++)
      c = (c*i)%kMod;
    return c;
  }
  int count(int n) {
    memset(dp,0,sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    // the index is how many characters you have left
    for (int i = 2;i <= n; i++) {
      (dp[i] += dp[i-1])%=kMod;
      if (i > 2) {
        LL t = 0;
        for (int k = 1; k <= i-2; k++)
          (t += ((LL)dp[k] * dp[i-1-k])%kMod)%=kMod;
        (dp[i]+=t)%=kMod;
      }
    }
    return ((LL)dp[n]*factorial(n))%kMod;
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
		cout << "Testing LongWordsDiv1 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1437230621;
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
		LongWordsDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 1;
				_expected = 1;
				_received = _obj.count(n); break;
			}
			case 1:
			{
				int n = 2;
				_expected = 2;
				_received = _obj.count(n); break;
			}
			case 2:
			{
				int n = 5;
				_expected = 1080;
				_received = _obj.count(n); break;
			}
			case 3:
			{
				int n = 100;
				_expected = 486425238;
				_received = _obj.count(n); break;
			}
			case 4:
			{
				int n = 3;
				_expected = 12;
				_received = _obj.count(n); break;
			}
			/*case 5:
			{
				int n = ;
				_expected = ;
				_received = _obj.count(n); break;
			}*/
			/*case 6:
			{
				int n = ;
				_expected = ;
				_received = _obj.count(n); break;
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
