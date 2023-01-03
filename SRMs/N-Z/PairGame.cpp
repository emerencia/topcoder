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
// solve in 8 min
// END CUT HERE

class PairGame {
 public:
    set<PII> possible_sums(int a, int b) {
      set<PII> r;
      while (a > 0 && b > 0) {
        r.insert(PII(a,a+b));
        if (a == b) break;
        if (a < b) b-=a;
        else a-=b;
      }
      return r;
    }
  int maxSum(int a, int b, int c, int d) {
    set<PII> x = possible_sums(a,b);
    set<PII> y = possible_sums(c,d);
    int r = -1;
    for (set<PII>::iterator i =x.begin();i!=x.end();i++)
      if (y.count(*i))
        r = max(r,i->second);
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
	string a = tt == -1 ? "0" : string(1,'0'+tt);
	char* b[2] = {argv[0],(char*)a.c_str()};
	if(tt!=-1){argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing PairGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 2; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1444742812;
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
		PairGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a = 1;
				int b = 2;
				int c = 2;
				int d = 1;
				_expected = 2;
				_received = _obj.maxSum(a, b, c, d); break;
			}
			case 1:
			{
				int a = 15;
				int b = 4;
				int c = 10;
				int d = 7;
				_expected = 7;
				_received = _obj.maxSum(a, b, c, d); break;
			}
			case 2:
			{
				int a = 1;
				int b = 1;
				int c = 10;
				int d = 10;
				_expected = -1;
				_received = _obj.maxSum(a, b, c, d); break;
			}
			case 3:
			{
				int a = 1000;
				int b = 1001;
				int c = 2000;
				int d = 2001;
				_expected = 1001;
				_received = _obj.maxSum(a, b, c, d); break;
			}
			case 4:
			{
				int a = 10944;
				int b = 17928;
				int c = 7704;
				int d = 21888;
				_expected = 144;
				_received = _obj.maxSum(a, b, c, d); break;
			}
			case 5:
			{
				int a = 1;
				int b = 1;
				int c = 1;
				int d = 1;
				_expected = 2;
				_received = _obj.maxSum(a, b, c, d); break;
			}
			/*case 6:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				_expected = ;
				_received = _obj.maxSum(a, b, c, d); break;
			}*/
			/*case 7:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				_expected = ;
				_received = _obj.maxSum(a, b, c, d); break;
			}*/
			/*case 8:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				_expected = ;
				_received = _obj.maxSum(a, b, c, d); break;
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
