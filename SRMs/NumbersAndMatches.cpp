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
LL mem[20][256][1200];

class NumbersAndMatches {
 public:
  vector<int> masks;
  vector<int> num;
  int bitcount(int n) {
    int r = 0;
    for (int i=n;i;i&=i-1) ++r;
    return r;
  }
  LL rec(int idx, int movesleft, int matchbalance) {
    LL& r = mem[idx][movesleft][matchbalance+600];
    if (r != -1) return r;
    if (idx == num.size()) return r = matchbalance == 0;
    int mask = masks[num[idx]];
    LL t = 0;
    for (int i=0;i<10;i++) {
      int balancediff = bitcount(masks[i])-bitcount(mask);
      int movesmade = bitcount(masks[i]^mask);
      if (movesmade <= movesleft && matchbalance+balancediff+600 >= 0 && 
          matchbalance+balancediff+600 < 1200) {
        t+=rec(idx+1,movesleft-movesmade,matchbalance+balancediff);
      }
    }
    return r = t;
  }
  long long differentNumbers(long long N, int K) {
    masks = vector<int>();
    masks.push_back((1<<0)+(1<<1)+(1<<2)+(0<<3)+(1<<4)+(1<<5)+(1<<6)); // 0
    masks.push_back((0<<0)+(0<<1)+(1<<2)+(0<<3)+(0<<4)+(1<<5)+(1<<6)); // 1
    masks.push_back((1<<0)+(0<<1)+(1<<2)+(1<<3)+(1<<4)+(0<<5)+(1<<6)); // 2
    masks.push_back((1<<0)+(0<<1)+(1<<2)+(1<<3)+(0<<4)+(1<<5)+(1<<6)); // 3
    masks.push_back((0<<0)+(1<<1)+(1<<2)+(1<<3)+(0<<4)+(1<<5)+(0<<6)); // 4
    masks.push_back((1<<0)+(1<<1)+(0<<2)+(1<<3)+(0<<4)+(1<<5)+(1<<6)); // 5
    masks.push_back((1<<0)+(1<<1)+(0<<2)+(1<<3)+(1<<4)+(1<<5)+(1<<6)); // 6
    masks.push_back((1<<0)+(0<<1)+(1<<2)+(0<<3)+(0<<4)+(1<<5)+(0<<6)); // 7
    masks.push_back((1<<0)+(1<<1)+(1<<2)+(1<<3)+(1<<4)+(1<<5)+(1<<6)); // 8
    masks.push_back((1<<0)+(1<<1)+(1<<2)+(1<<3)+(0<<4)+(1<<5)+(1<<6)); // 9
    memset(mem,-1,sizeof(mem));
    num = vector<int>();
    while (N) {
      num.push_back(N%10);
      N/=10;
    }
    return rec(0,2*K,0);
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
		cout << "Testing NumbersAndMatches (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398859774;
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
		NumbersAndMatches _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long N = 10LL;
				int K = 1;
				_expected = 4LL;
				_received = _obj.differentNumbers(N, K); break;
			}
			case 1:
			{
				long long N = 23LL;
				int K = 1;
				_expected = 4LL;
				_received = _obj.differentNumbers(N, K); break;
			}
			case 2:
			{
				long long N = 66LL;
				int K = 2;
				_expected = 15LL;
				_received = _obj.differentNumbers(N, K); break;
			}
			case 3:
			{
				long long N = 888888888LL;
				int K = 100;
				_expected = 1LL;
				_received = _obj.differentNumbers(N, K); break;
			}
			case 4:
			{
				long long N = 444444444444444444LL;
				int K = 2;
				_expected = 1LL;
				_received = _obj.differentNumbers(N, K); break;
			}
			/*case 5:
			{
				long long N = LL;
				int K = ;
				_expected = LL;
				_received = _obj.differentNumbers(N, K); break;
			}*/
			/*case 6:
			{
				long long N = LL;
				int K = ;
				_expected = LL;
				_received = _obj.differentNumbers(N, K); break;
			}*/
			/*case 7:
			{
				long long N = LL;
				int K = ;
				_expected = LL;
				_received = _obj.differentNumbers(N, K); break;
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
