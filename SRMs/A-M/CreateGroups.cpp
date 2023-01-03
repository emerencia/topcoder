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

class CreateGroups {
 public:
  int minChanges(vector <int> groups, int minSize, int maxSize) {
    LL totsize = 0;
    for (int i=0;i<groups.size();i++)
      totsize+=groups[i];
    LL totminsize = (LL)groups.size()*minSize;
    LL totmaxsize = (LL)groups.size()*maxSize;
    if (totsize < totminsize || totsize > totmaxsize) return -1;
    LL swapup = 0;
    LL swapdown = 0;
    for (int i=0;i<groups.size();i++)
      if (groups[i] < minSize)
        swapup+=minSize-groups[i];
      else if (groups[i] > maxSize)
        swapdown+=groups[i]-maxSize;
    return max(swapup,swapdown);
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
		cout << "Testing CreateGroups (275.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393512862;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 275.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CreateGroups _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int groups[] = {10,20};
				int minSize = 10;
				int maxSize = 15;
				_expected = 5;
				_received = _obj.minChanges(vector <int>(groups, groups+sizeof(groups)/sizeof(int)), minSize, maxSize); break;
			}
			case 1:
			{
				int groups[] = {20,8,6};
				int minSize = 10;
				int maxSize = 15;
				_expected = 6;
				_received = _obj.minChanges(vector <int>(groups, groups+sizeof(groups)/sizeof(int)), minSize, maxSize); break;
			}
			case 2:
			{
				int groups[] = {10,20,30};
				int minSize = 1;
				int maxSize = 18;
				_expected = -1;
				_received = _obj.minChanges(vector <int>(groups, groups+sizeof(groups)/sizeof(int)), minSize, maxSize); break;
			}
			case 3:
			{
				int groups[] = {50,10,20,20,5};
				int minSize = 15;
				int maxSize = 30;
				_expected = 20;
				_received = _obj.minChanges(vector <int>(groups, groups+sizeof(groups)/sizeof(int)), minSize, maxSize); break;
			}
			case 4:
			{
				int groups[] = {100,200,301};
				int minSize = 200;
				int maxSize = 200;
				_expected = -1;
				_received = _obj.minChanges(vector <int>(groups, groups+sizeof(groups)/sizeof(int)), minSize, maxSize); break;
			}
			case 5:
			{
				int groups[] = {1,10,10}	;
				int minSize = 9;
				int maxSize = 20;
				_expected = -1;
				_received = _obj.minChanges(vector <int>(groups, groups+sizeof(groups)/sizeof(int)), minSize, maxSize); break;
			}
			case 6:
			{
				int groups[] = {55,33,45,71,27,89,16,14,61};
				int minSize = 33;
				int maxSize = 56;
				_expected = 53;
				_received = _obj.minChanges(vector <int>(groups, groups+sizeof(groups)/sizeof(int)), minSize, maxSize); break;
			}
			case 7:
			{
				int groups[] = {49,60,36,34,36,52,60,43,52,59};
				int minSize = 45;
				int maxSize = 51;
				_expected = 31;
				_received = _obj.minChanges(vector <int>(groups, groups+sizeof(groups)/sizeof(int)), minSize, maxSize); break;
			}
			case 8:
			{
				int groups[] = {5,5,5,5,5};
				int minSize = 5;
				int maxSize = 5;
				_expected = 0;
				_received = _obj.minChanges(vector <int>(groups, groups+sizeof(groups)/sizeof(int)), minSize, maxSize); break;
			}
			/*case 9:
			{
				int groups[] = ;
				int minSize = ;
				int maxSize = ;
				_expected = ;
				_received = _obj.minChanges(vector <int>(groups, groups+sizeof(groups)/sizeof(int)), minSize, maxSize); break;
			}*/
			/*case 10:
			{
				int groups[] = ;
				int minSize = ;
				int maxSize = ;
				_expected = ;
				_received = _obj.minChanges(vector <int>(groups, groups+sizeof(groups)/sizeof(int)), minSize, maxSize); break;
			}*/
			/*case 11:
			{
				int groups[] = ;
				int minSize = ;
				int maxSize = ;
				_expected = ;
				_received = _obj.minChanges(vector <int>(groups, groups+sizeof(groups)/sizeof(int)), minSize, maxSize); break;
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
