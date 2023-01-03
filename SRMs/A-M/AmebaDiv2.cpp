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

class AmebaDiv2 {
 public:
  int simulate(vector <int> X, int A) {
    int cur = A;
    for (int i=0;i<X.size();i++)
      if (cur == X[i]) cur*=2;
    return cur;
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
		cout << "Testing AmebaDiv2 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1425932982;
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
		AmebaDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int X[] = {2,1,3,1,2};
				int A = 1;
				_expected = 4;
				_received = _obj.simulate(vector <int>(X, X+sizeof(X)/sizeof(int)), A); break;
			}
			case 1:
			{
				int X[] = {1,4,9,16,25,36,49};
				int A = 10;
				_expected = 10;
				_received = _obj.simulate(vector <int>(X, X+sizeof(X)/sizeof(int)), A); break;
			}
			case 2:
			{
				int X[] = {1,2,4,8,16,32,64,128,256,1024,2048};
				int A = 1;
				_expected = 512;
				_received = _obj.simulate(vector <int>(X, X+sizeof(X)/sizeof(int)), A); break;
			}
			case 3:
			{
				int X[] = {817,832,817,832,126,817,63,63,126,817,832,287,823,817,574};
				int A = 63;
				_expected = 252;
				_received = _obj.simulate(vector <int>(X, X+sizeof(X)/sizeof(int)), A); break;
			}
			/*case 4:
			{
				int X[] = ;
				int A = ;
				_expected = ;
				_received = _obj.simulate(vector <int>(X, X+sizeof(X)/sizeof(int)), A); break;
			}*/
			/*case 5:
			{
				int X[] = ;
				int A = ;
				_expected = ;
				_received = _obj.simulate(vector <int>(X, X+sizeof(X)/sizeof(int)), A); break;
			}*/
			/*case 6:
			{
				int X[] = ;
				int A = ;
				_expected = ;
				_received = _obj.simulate(vector <int>(X, X+sizeof(X)/sizeof(int)), A); break;
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
