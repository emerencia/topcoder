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
LL MAX = 1e10;

class LotteryCheating {
 public:
  int numchanges(LL num, string ID) {
    stringstream a;
    a << num;
    string b = a.str();
    if (b.size() > ID.size()) return INT_MAX;
    if (ID.size() > b.size()) b = string(ID.size()-b.size(),'0')+b;
    int r = 0;
    for (int i=0;i<b.size();i++)
      r += b[i] != ID[i];
    return r;
  }
  int minimalChange(string ID) {
    // calculate all the perfect squares between 1 and 10 000 000 000
    // get the one with min dist
    int r = INT_MAX;
    for (LL i = 0;i*i<MAX;i++)
      r = min(r,numchanges(i*i,ID));
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
		cout << "Testing LotteryCheating (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1403639120;
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
		LotteryCheating _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string ID = "1";
				_expected = 0;
				_received = _obj.minimalChange(ID); break;
			}
			case 1:
			{
				string ID = "1234";
				_expected = 2;
				_received = _obj.minimalChange(ID); break;
			}
			case 2:
			{
				string ID = "9000000000";
				_expected = 1;
				_received = _obj.minimalChange(ID); break;
			}
			case 3:
			{
				string ID = "4294967296";
				_expected = 0;
				_received = _obj.minimalChange(ID); break;
			}
			case 4:
			{
				string ID = "7654321";
				_expected = 3;
				_received = _obj.minimalChange(ID); break;
			}
			case 5:
			{
				string ID = "49637";
				_expected = 3;
				_received = _obj.minimalChange(ID); break;
			}
			/*case 6:
			{
				string ID = ;
				_expected = ;
				_received = _obj.minimalChange(ID); break;
			}*/
			/*case 7:
			{
				string ID = ;
				_expected = ;
				_received = _obj.minimalChange(ID); break;
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
