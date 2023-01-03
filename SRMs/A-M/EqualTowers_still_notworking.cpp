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
int sums[500001];

class EqualTowers {
 public:
  int height(vector <int> bricks) {
    sort(bricks.begin(),bricks.end());
    int sofar = 0;
    vector<int> used(bricks.size(),false);
    for (int i=bricks.size()-1;i>=0;i--) {
      memset(sums,0,sizeof(sums));
      sums[0] = 1;
      for (int j=0;j<bricks.size();j++) {
        if (used[j] || i == j) continue;
        for (int k=500000-bricks[j];k>=0;k--)
          if (sums[k])
            sums[k+bricks[j]] = 1;
      }
      int idx = bricks[i];
      if (!sums[bricks[i]]) continue;
      for (int j=bricks.size();j>=0;j--) {
        if (used[j] || i == j) continue;
        if (bricks[j] > idx) continue;
        if (sums[idx-bricks[j]]) {
          idx -= bricks[j];
          used[j] = true;
          if (idx == 0) break;
        }
      }
      if (idx != 0) cout << "error" << endl;
      used[i] = true;
      sofar+=bricks[i];
    }
    return sofar == 0 ? -1 : sofar;
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
		cout << "Testing EqualTowers (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395987360;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		EqualTowers _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int bricks[] = { 2, 3, 5 };
				_expected = 5;
				_received = _obj.height(vector <int>(bricks, bricks+sizeof(bricks)/sizeof(int))); break;
			}
			case 1:
			{
				int bricks[] = { 10, 9, 2 };
				_expected = -1;
				_received = _obj.height(vector <int>(bricks, bricks+sizeof(bricks)/sizeof(int))); break;
			}
			case 2:
			{
				int bricks[] = { 11, 11 };
				_expected = 11;
				_received = _obj.height(vector <int>(bricks, bricks+sizeof(bricks)/sizeof(int))); break;
			}
			case 3:
			{
				int bricks[] = { 14, 3, 20, 15, 15, 14, 24, 23, 15 };
				_expected = 64;
				_received = _obj.height(vector <int>(bricks, bricks+sizeof(bricks)/sizeof(int))); break;
			}
			/*case 4:
			{
				int bricks[] = ;
				_expected = ;
				_received = _obj.height(vector <int>(bricks, bricks+sizeof(bricks)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int bricks[] = ;
				_expected = ;
				_received = _obj.height(vector <int>(bricks, bricks+sizeof(bricks)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int bricks[] = ;
				_expected = ;
				_received = _obj.height(vector <int>(bricks, bricks+sizeof(bricks)/sizeof(int))); break;
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
