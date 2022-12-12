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

int sum[1200][1200];
class LotsOfLines {
 public:
  int gcd(int a, int b) {
    while (a != 0) {
        int c = a;
        a = b % a;
        b = c;
    }
    return b;
  }
  long long countDivisions(int A, int B) {
    if (A == 1) return 1+B;
    for (int i = 1; i < A; i++) {
      for (int j = 1; j < B; j++) {
        int x = ( (gcd(i,j) == 1) ? 1 : 0 );
        sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + x;
      }
    }
    LL r = 1;
    for (int a = 0;a<A;a++)
      for (int b = 0;b<B;b++) {
        r++;
        if (a != 0) {
          r += 1LL + 2LL*sum[a][b];
        }
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
		cout << "Testing LotsOfLines (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390932952;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		LotsOfLines _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 1;
				int B = 1;
				_expected = 2LL;
				_received = _obj.countDivisions(A, B); break;
			}
			case 1:
			{
				int A = 2;
				int B = 2;
				_expected = 9LL;
				_received = _obj.countDivisions(A, B); break;
			}
			case 2:
			{
				int A = 3;
				int B = 2;
				_expected = 17LL;
				_received = _obj.countDivisions(A, B); break;
			}
			case 3:
			{
				int A = 1;
				int B = 1200;
				_expected = 1201LL;
				_received = _obj.countDivisions(A, B); break;
			}
			case 4:
			{
				int A = 5;
				int B = 9;
				_expected = 638LL;
				_received = _obj.countDivisions(A, B); break;
			}
			/*case 5:
			{
				int A = ;
				int B = ;
				_expected = LL;
				_received = _obj.countDivisions(A, B); break;
			}*/
			/*case 6:
			{
				int A = ;
				int B = ;
				_expected = LL;
				_received = _obj.countDivisions(A, B); break;
			}*/
			/*case 7:
			{
				int A = ;
				int B = ;
				_expected = LL;
				_received = _obj.countDivisions(A, B); break;
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
