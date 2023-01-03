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

class SlimeXSlimonadeTycoon {
 public:
  int sell(vector <int> morning, vector <int> customers, int stale_limit) {
    vector<int> stock(morning.size(), 0);
    int r = 0;
    for (int i=0;i<morning.size();i++) {
      if (i-stale_limit >= 0)
        stock[i-stale_limit] = 0;
      stock[i] = morning[i];
      int current = accumulate(stock.begin(),stock.end(),0);
      int cansell = min(current,customers[i]);
      r += cansell;
      for (int j=0;j<morning.size();j++)
        if (stock[j]) {
          int delta = min(stock[j],cansell);
          stock[j] -= delta;
          cansell -= delta;
          if (!cansell) break;
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
	string a = tt == -1 ? "0" : string(1,'0'+tt);
	char* b[2] = {argv[0],(char*)a.c_str()};
	if(tt!=-1){argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing SlimeXSlimonadeTycoon (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1432914137;
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
		SlimeXSlimonadeTycoon _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int morning[] = {5, 1, 1};
				int customers[] = {1, 2, 3};
				int stale_limit = 2;
				_expected = 5;
				_received = _obj.sell(vector <int>(morning, morning+sizeof(morning)/sizeof(int)), vector <int>(customers, customers+sizeof(customers)/sizeof(int)), stale_limit); break;
			}
			case 1:
			{
				int morning[] = {10, 20, 30};
				int customers[] = {30, 20, 10};
				int stale_limit = 1;
				_expected = 40;
				_received = _obj.sell(vector <int>(morning, morning+sizeof(morning)/sizeof(int)), vector <int>(customers, customers+sizeof(customers)/sizeof(int)), stale_limit); break;
			}
			case 2:
			{
				int morning[] = {1, 2, 3, 4, 5};
				int customers[] = {5, 5, 5, 5, 5};
				int stale_limit = 5;
				_expected = 15;
				_received = _obj.sell(vector <int>(morning, morning+sizeof(morning)/sizeof(int)), vector <int>(customers, customers+sizeof(customers)/sizeof(int)), stale_limit); break;
			}
			case 3:
			{
				int morning[] = {10000, 0, 0, 0, 0, 0, 0};
				int customers[] = {1, 2, 4, 8, 16, 32, 64};
				int stale_limit = 4;
				_expected = 15;
				_received = _obj.sell(vector <int>(morning, morning+sizeof(morning)/sizeof(int)), vector <int>(customers, customers+sizeof(customers)/sizeof(int)), stale_limit); break;
			}
			/*case 4:
			{
				int morning[] = ;
				int customers[] = ;
				int stale_limit = ;
				_expected = ;
				_received = _obj.sell(vector <int>(morning, morning+sizeof(morning)/sizeof(int)), vector <int>(customers, customers+sizeof(customers)/sizeof(int)), stale_limit); break;
			}*/
			/*case 5:
			{
				int morning[] = ;
				int customers[] = ;
				int stale_limit = ;
				_expected = ;
				_received = _obj.sell(vector <int>(morning, morning+sizeof(morning)/sizeof(int)), vector <int>(customers, customers+sizeof(customers)/sizeof(int)), stale_limit); break;
			}*/
			/*case 6:
			{
				int morning[] = ;
				int customers[] = ;
				int stale_limit = ;
				_expected = ;
				_received = _obj.sell(vector <int>(morning, morning+sizeof(morning)/sizeof(int)), vector <int>(customers, customers+sizeof(customers)/sizeof(int)), stale_limit); break;
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
