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

class UnluckyNumbers {
 public:
  int getCount(vector <int> luckySet, int n) {
    int q = *max_element(luckySet.begin(),luckySet.end());
    vector<int> used(q+1,0);
    for (int i=0;i<luckySet.size();i++)
      used[luckySet[i]] = 1;
    int r = 0;
    for (int i=1;i<=q;i++)
      for (int j=i+1;j<=q;j++) {
        if (n < i || n > j) continue;
        bool good = true;
        for (int k=i;k<=j;k++)
          if (used[k]) {
            good = false;
            break;
          }
        r+=good;
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
		cout << "Testing UnluckyNumbers (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394728973;
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
		UnluckyNumbers _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int luckySet[] = {1, 7, 14, 10};
				int n = 2;
				_expected = 4;
				_received = _obj.getCount(vector <int>(luckySet, luckySet+sizeof(luckySet)/sizeof(int)), n); break;
			}
			case 1:
			{
				int luckySet[] = {4, 8, 13, 24, 30};
				int n = 10;
				_expected = 5;
				_received = _obj.getCount(vector <int>(luckySet, luckySet+sizeof(luckySet)/sizeof(int)), n); break;
			}
			case 2:
			{
				int luckySet[] = {10, 20, 30, 40, 50};
				int n = 30;
				_expected = 0;
				_received = _obj.getCount(vector <int>(luckySet, luckySet+sizeof(luckySet)/sizeof(int)), n); break;
			}
			case 3:
			{
				int luckySet[] = {3, 7, 12, 18, 25, 100, 33, 1000};
				int n = 59;
				_expected = 1065;
				_received = _obj.getCount(vector <int>(luckySet, luckySet+sizeof(luckySet)/sizeof(int)), n); break;
			}
			/*case 4:
			{
				int luckySet[] = ;
				int n = ;
				_expected = ;
				_received = _obj.getCount(vector <int>(luckySet, luckySet+sizeof(luckySet)/sizeof(int)), n); break;
			}*/
			/*case 5:
			{
				int luckySet[] = ;
				int n = ;
				_expected = ;
				_received = _obj.getCount(vector <int>(luckySet, luckySet+sizeof(luckySet)/sizeof(int)), n); break;
			}*/
			/*case 6:
			{
				int luckySet[] = ;
				int n = ;
				_expected = ;
				_received = _obj.getCount(vector <int>(luckySet, luckySet+sizeof(luckySet)/sizeof(int)), n); break;
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
