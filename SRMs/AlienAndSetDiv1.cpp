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
long long mem[51][102][102];

class AlienAndSetDiv1 {
 public:
  int N;
  int K;
  long long rec(int turn, int a, int b) {
    //cout << a << " " << b << endl;
    //if (b < a) swap(a,b);
    LL& r = mem[turn][a][b];
    if (r != -1) return r;
    if (turn == N) return r = 2;
    long long t = 0;
    if (a+1 < b) {
      for (int nb = max(b+1,a+1+K);nb<=2*N;nb++)
        (t+=rec(turn+1,a+1,nb))%=kMod;
    } else {
      for (int nb = max(b+1,a+2+K);nb<=2*N;nb++)
        (t+=rec(turn+1,a+2,nb))%=kMod;
    }
    return r = t;
  }
  int getNumber(int N, int K) {
    memset(mem,-1,sizeof(mem));
    this->N = N;
    this->K = K;
    long long r = 0;
    for (int i=1+K;i<=N+1;i++) {
      (r+=rec(1,1,i))%=kMod;
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
		cout << "Testing AlienAndSetDiv1 (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390307098;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AlienAndSetDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int K = 2;
				_expected = 2;
				_received = _obj.getNumber(N, K); break;
			}
			case 1:
			{
				int N = 3;
				int K = 1;
				_expected = 20;
				_received = _obj.getNumber(N, K); break;
			}
			case 2:
			{
				int N = 4;
				int K = 2;
				_expected = 14;
				_received = _obj.getNumber(N, K); break;
			}
			case 3:
			{
				int N = 10;
				int K = 7;
				_expected = 40;
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
