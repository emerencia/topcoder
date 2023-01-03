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

class BunnyPuzzle {
 public:
  int theCount(vector <int> bunnies) {
    sort(bunnies.begin(),bunnies.end());
    int r = 0;
    for (int i=0;i+1<bunnies.size();i++) {
      int j = i+1;
      if (j+1 == bunnies.size() || bunnies[j+1] > 2*bunnies[j]-bunnies[i]) ++r;
      if (i == 0 || bunnies[i-1] < 2*bunnies[i]-bunnies[j]) ++r;
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
	string a = tt == -1 ? "0" : string(1,'0'+tt);
	char* b[2] = {argv[0],(char*)a.c_str()};
	if(tt!=-1){argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing BunnyPuzzle (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1401374706;
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
		BunnyPuzzle _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int bunnies[] = {5, 8};
				_expected = 2;
				_received = _obj.theCount(vector <int>(bunnies, bunnies+sizeof(bunnies)/sizeof(int))); break;
			}
			case 1:
			{
				int bunnies[] = {-1, 0, 1};
				_expected = 2;
				_received = _obj.theCount(vector <int>(bunnies, bunnies+sizeof(bunnies)/sizeof(int))); break;
			}
			case 2:
			{
				int bunnies[] = {0, 1, 3};
				_expected = 3;
				_received = _obj.theCount(vector <int>(bunnies, bunnies+sizeof(bunnies)/sizeof(int))); break;
			}
			case 3:
			{
				int bunnies[] = {-677, -45, -2, 3, 8, 29, 384, 867};
				_expected = 7;
				_received = _obj.theCount(vector <int>(bunnies, bunnies+sizeof(bunnies)/sizeof(int))); break;
			}
			case 4:
			{
				int bunnies[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
				_expected = 2;
				_received = _obj.theCount(vector <int>(bunnies, bunnies+sizeof(bunnies)/sizeof(int))); break;
			}
			/*case 5:
			{
				int bunnies[] = ;
				_expected = ;
				_received = _obj.theCount(vector <int>(bunnies, bunnies+sizeof(bunnies)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int bunnies[] = ;
				_expected = ;
				_received = _obj.theCount(vector <int>(bunnies, bunnies+sizeof(bunnies)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int bunnies[] = ;
				_expected = ;
				_received = _obj.theCount(vector <int>(bunnies, bunnies+sizeof(bunnies)/sizeof(int))); break;
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
