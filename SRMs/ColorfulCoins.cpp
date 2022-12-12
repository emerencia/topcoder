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

class ColorfulCoins {
 public:
  int minQueries(vector<long long> values) {
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
		cout << "Testing ColorfulCoins (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1431026669;
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
		ColorfulCoins _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long values[] = {1LL};
				_expected = 1;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}
			case 1:
			{
				long long values[] = {1LL, 3LL};
				_expected = 1;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}
			case 2:
			{
				long long values[] = {1LL, 2LL, 4LL};
				_expected = 2;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}
			case 3:
			{
				long long values[] = {1LL, 2LL, 4LL, 8LL, 16LL};
				_expected = 3;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}
			case 4:
			{
				long long values[] = {1LL, 2LL, 6LL, 30LL, 90LL, 270LL, 810LL, 2430LL, 7290LL, 29160LL, 87480LL, 262440LL, 787320LL, 3149280LL,
				                       9447840LL, 28343520LL, 56687040LL, 170061120LL, 510183360LL, 1530550080LL, 3061100160LL,
				                       9183300480LL, 27549901440LL, 82649704320LL, 247949112960LL, 1239745564800LL, 3719236694400LL,
				                       14876946777600LL, 44630840332800LL, 223154201664000LL, 669462604992000LL, 2008387814976000LL,
				                       6025163444928000LL, 12050326889856000LL, 24100653779712000LL, 72301961339136000LL,
				                       289207845356544000LL, 867623536069632000LL};
				_expected = 4;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}
			/*case 5:
			{
				long long values[] = ;
				_expected = ;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}*/
			/*case 6:
			{
				long long values[] = ;
				_expected = ;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}*/
			/*case 7:
			{
				long long values[] = ;
				_expected = ;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
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
