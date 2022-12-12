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
int divisorcount[100001];

class Underprimes {
 public:
  int howMany(int A, int B) {
    memset(divisorcount,0,sizeof(divisorcount));
    for (int i=2;i<=100000;i++) {
      if (divisorcount[i] != 0) continue;
      for (LL j=i;j<=100000;j*=i)
        for (LL m=j;m<=100000;m+=j)
          divisorcount[m]++;
    }
    int r = 0;
    for (int i=A;i<=B;i++)
      if (divisorcount[divisorcount[i]] == 1)
        r++;
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
  char* b[2];
  if(tt!=-1){b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}
  if (argc == 1) 
	{
		cout << "Testing Underprimes (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395984005;
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
		Underprimes _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 2;
				int B = 10;
				_expected = 5;
				_received = _obj.howMany(A, B); break;
			}
			case 1:
			{
				int A = 100;
				int B = 105;
				_expected = 2;
				_received = _obj.howMany(A, B); break;
			}
			case 2:
			{
				int A = 17;
				int B = 17;
				_expected = 0;
				_received = _obj.howMany(A, B); break;
			}
			case 3:
			{
				int A = 123;
				int B = 456;
				_expected = 217;
				_received = _obj.howMany(A, B); break;
			}
			/*case 4:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.howMany(A, B); break;
			}*/
			/*case 5:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.howMany(A, B); break;
			}*/
			/*case 6:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.howMany(A, B); break;
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
