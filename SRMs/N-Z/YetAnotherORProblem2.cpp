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
const int kMod = 1e9+9;
long long mem[11][31];

class YetAnotherORProblem2 {
 public:
  int R;
  int N;
  int highestbit(int n) {
    for (int i=30;i>=0;i--)
      if (n&(1<<i))
        return i;
    return -1;
  }
  long long rec(int nreq, int idx) {
    if (idx == -1) return 1;
    LL& r = mem[nreq][idx];
    if (r != -1) return r;
    long long t = 0;
    if (R&(1<<idx)) {
      (t+=(LL)nreq*rec(1,idx-1))%=kMod;     // one of the equals gest the 1
      (t+=((LL)N-nreq)*rec(0,idx-1))%=kMod; // one of the non-equals gets the 1
      (t+=rec(0,idx-1))%=kMod;              // no one gets the 1
    } else {
      (t+=((LL)N-nreq)*rec(nreq,idx-1))%=kMod;  // one of the non-equals gets the 1
      (t+=rec(nreq,idx-1))%=kMod;               // no one gets the 1
    }
    return r = t;
  }
  int countSequences(int N, int R) {
    this->N = N;
    this->R = R;
    memset(mem,-1,sizeof(mem));
    return rec(N,highestbit(R));
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
		cout << "Testing YetAnotherORProblem2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390510724;
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
		YetAnotherORProblem2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int R = 2;
				_expected = 7;
				_received = _obj.countSequences(N, R); break;
			}
			case 1:
			{
				int N = 2;
				int R = 3;
				_expected = 9;
				_received = _obj.countSequences(N, R); break;
			}
			case 2:
			{
				int N = 3;
				int R = 3;
				_expected = 16;
				_received = _obj.countSequences(N, R); break;
			}
			case 3:
			{
				int N = 7;
				int R = 1023;
				_expected = 73741815;
				_received = _obj.countSequences(N, R); break;
			}
			/*case 4:
			{
				int N = ;
				int R = ;
				_expected = ;
				_received = _obj.countSequences(N, R); break;
			}*/
			/*case 5:
			{
				int N = ;
				int R = ;
				_expected = ;
				_received = _obj.countSequences(N, R); break;
			}*/
			/*case 6:
			{
				int N = ;
				int R = ;
				_expected = ;
				_received = _obj.countSequences(N, R); break;
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
