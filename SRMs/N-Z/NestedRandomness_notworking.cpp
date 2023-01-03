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
const int tt = 0;
// 
// END CUT HERE

class NestedRandomness {
 public:
  LL g, t;
  int target;
  void rec(int N, int nestleft) {
    if (nestleft == 0) {
      cout << N << endl;
      if (N == target) ++g;
      ++t;
      return;
    }
    for (int i=0;i<N;i++)
      rec(i,nestleft-1);
  }
  double probability(int N, int nestings, int target) {
    this->target = target;
    g = 0;
    t = 0;
    rec(N,nestings);
    cout << endl;
    cout << g << endl;
    cout << t << endl;
    return double(g)/t;
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
		cout << "Testing NestedRandomness (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397304229;
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
		NestedRandomness _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 5;
				int nestings = 2;
				int target = 1;
				_expected = 0.21666666666666667;
				_received = _obj.probability(N, nestings, target); break;
			}
			case 1:
			{
				int N = 10;
				int nestings = 4;
				int target = 0;
				_expected = 0.19942680776014104;
				_received = _obj.probability(N, nestings, target); break;
			}
			case 2:
			{
				int N = 1000;
				int nestings = 10;
				int target = 990;
				_expected = 1.0461776397050886E-30;
				_received = _obj.probability(N, nestings, target); break;
			}
			/*case 3:
			{
				int N = ;
				int nestings = ;
				int target = ;
				_expected = ;
				_received = _obj.probability(N, nestings, target); break;
			}*/
			/*case 4:
			{
				int N = ;
				int nestings = ;
				int target = ;
				_expected = ;
				_received = _obj.probability(N, nestings, target); break;
			}*/
			/*case 5:
			{
				int N = ;
				int nestings = ;
				int target = ;
				_expected = ;
				_received = _obj.probability(N, nestings, target); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(3);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
