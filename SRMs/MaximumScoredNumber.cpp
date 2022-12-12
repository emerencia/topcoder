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

class MaximumScoredNumber {
 public:
  int score(int num) {
    int r = 0;
    for (int i=0;i*i<=num;i++)
      for (int j=i;i*i+j*j<=num;j++)
        if (i*i+j*j == num) ++r;
    return r;
  }
  int getNumber(int lowerBound, int upperBound) {
    int maxn = lowerBound;
    int r = 0;
    for (int i=lowerBound;i<=upperBound;i++) {
      int sc = score(i);
      if (sc >= r) {
        r = sc;
        maxn = i;
      }
    }
    return maxn;
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
		cout << "Testing MaximumScoredNumber (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1389904301;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MaximumScoredNumber _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int lowerBound = 0;
				int upperBound = 2;
				_expected = 2;
				_received = _obj.getNumber(lowerBound, upperBound); break;
			}
			case 1:
			{
				int lowerBound = 0;
				int upperBound = 30;
				_expected = 25;
				_received = _obj.getNumber(lowerBound, upperBound); break;
			}
			case 2:
			{
				int lowerBound = 0;
				int upperBound = 0;
				_expected = 0;
				_received = _obj.getNumber(lowerBound, upperBound); break;
			}
			case 3:
			{
				int lowerBound = 5;
				int upperBound = 99;
				_expected = 85;
				_received = _obj.getNumber(lowerBound, upperBound); break;
			}
			case 4:
			{
				int lowerBound = 0;
				int upperBound = 10000;
				_expected = 9425;
				_received = _obj.getNumber(lowerBound, upperBound); break;
			}
			/*case 5:
			{
				int lowerBound = ;
				int upperBound = ;
				_expected = ;
				_received = _obj.getNumber(lowerBound, upperBound); break;
			}*/
			/*case 6:
			{
				int lowerBound = ;
				int upperBound = ;
				_expected = ;
				_received = _obj.getNumber(lowerBound, upperBound); break;
			}*/
			/*case 7:
			{
				int lowerBound = ;
				int upperBound = ;
				_expected = ;
				_received = _obj.getNumber(lowerBound, upperBound); break;
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
