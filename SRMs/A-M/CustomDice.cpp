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
const int kSize = 6e6+1;
int dp[2][kSize];

class CustomDice {
 public:
  int countDice(int M) {
    fill(&dp[0][0],&dp[2][0],1);
    int tot = 6*M-21;
    if (tot < 0) return 0;
    int cur = 0, next = 1;
    for (int i=0;i<6;i++) {
      for (int j=0;j<=kSize;j++) {
        dp[next][j] = dp[cur][j];
        if (j >= i+1)
          (dp[next][j] += dp[next][j-i-1])%=kMod;
      }
      swap(cur,next);
    }
    return (30LL*dp[cur][tot])%kMod;
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
			case 5:
			{
				int M = 249850;
				_expected = 826840433;
				_received = _obj.countDice(M); break;
			}
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
