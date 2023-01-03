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

class PouringWater {
 public:
  int getMinBottles(int N, int K) {
    if (K >= N) return 0;
    vector<LL> contents(27,0);  // bottles at index i hold 2^i
    contents[0] = N;
    LL numbottles = N;
    LL extra = 0;
    while (numbottles > K) {
      bool changed = false;
      for (int i=0;i<contents.size();i++) {
        if (contents[i] > 1) {
          numbottles-=contents[i]/2;
          contents[i+1]+=contents[i]/2;
          contents[i]-=2*(contents[i]/2);
          changed = true;
        }
      }
      if (!changed) {
        contents[0]++;
        numbottles++;
        extra++;
      }
    }
    return extra;
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
		cout << "Testing PouringWater (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395068407;
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
		PouringWater _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int K = 1;
				_expected = 1;
				_received = _obj.getMinBottles(N, K); break;
			}
			case 1:
			{
				int N = 13;
				int K = 2;
				_expected = 3;
				_received = _obj.getMinBottles(N, K); break;
			}
			case 2:
			{
				int N = 1000000;
				int K = 5;
				_expected = 15808;
				_received = _obj.getMinBottles(N, K); break;
			}
			/*case 3:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.getMinBottles(N, K); break;
			}*/
			/*case 4:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.getMinBottles(N, K); break;
			}*/
			/*case 5:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.getMinBottles(N, K); break;
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
