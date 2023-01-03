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

class WinterAndMandarins {
 public:
  int getNumber(vector <int> bags, int K) {
    sort(bags.begin(),bags.end());
    int mn = INT_MAX;
    for (int i=0;i+K-1<bags.size();i++)
      mn = min(mn,bags[i+K-1]-bags[i]);
    return mn;
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
		cout << "Testing WinterAndMandarins (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391205664;
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
		WinterAndMandarins _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int bags[] = {10, 20, 30};
				int K = 2;
				_expected = 10;
				_received = _obj.getNumber(vector <int>(bags, bags+sizeof(bags)/sizeof(int)), K); break;
			}
			case 1:
			{
				int bags[] = {4, 7, 4};
				int K = 3;
				_expected = 3;
				_received = _obj.getNumber(vector <int>(bags, bags+sizeof(bags)/sizeof(int)), K); break;
			}
			case 2:
			{
				int bags[] = {4, 1, 2, 3};
				int K = 3;
				_expected = 2;
				_received = _obj.getNumber(vector <int>(bags, bags+sizeof(bags)/sizeof(int)), K); break;
			}
			case 3:
			{
				int bags[] = {5, 4, 6, 1, 9, 4, 2, 7, 5, 6};
				int K = 4;
				_expected = 1;
				_received = _obj.getNumber(vector <int>(bags, bags+sizeof(bags)/sizeof(int)), K); break;
			}
			case 4:
			{
				int bags[] = {47, 1000000000, 1, 74};
				int K = 2;
				_expected = 27;
				_received = _obj.getNumber(vector <int>(bags, bags+sizeof(bags)/sizeof(int)), K); break;
			}
			/*case 5:
			{
				int bags[] = ;
				int K = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(bags, bags+sizeof(bags)/sizeof(int)), K); break;
			}*/
			/*case 6:
			{
				int bags[] = ;
				int K = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(bags, bags+sizeof(bags)/sizeof(int)), K); break;
			}*/
			/*case 7:
			{
				int bags[] = ;
				int K = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(bags, bags+sizeof(bags)/sizeof(int)), K); break;
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
