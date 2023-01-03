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

class LotteryTicket {
 public:
  string buy(int price, int b1, int b2, int b3, int b4) {
    vector<int> possibleprice(4001,false);
    vector<int> prices;
    prices.push_back(b1);
    prices.push_back(b2);
    prices.push_back(b3);
    prices.push_back(b4);
    possibleprice[0] = true;
    for (int i=0;i<prices.size();i++)
      for (int j=possibleprice.size()-1;j>=0;j--)
        if (possibleprice[j] && prices[i]+j < possibleprice.size())
          possibleprice[j+prices[i]] = true;
    return possibleprice[price] ? "POSSIBLE" : "IMPOSSIBLE";
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
		cout << "Testing LotteryTicket (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1403638768;
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
		LotteryTicket _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int price = 10;
				int b1 = 1;
				int b2 = 5;
				int b3 = 10;
				int b4 = 50;
				_expected = "POSSIBLE";
				_received = _obj.buy(price, b1, b2, b3, b4); break;
			}
			case 1:
			{
				int price = 15;
				int b1 = 1;
				int b2 = 5;
				int b3 = 10;
				int b4 = 50;
				_expected = "POSSIBLE";
				_received = _obj.buy(price, b1, b2, b3, b4); break;
			}
			case 2:
			{
				int price = 65;
				int b1 = 1;
				int b2 = 5;
				int b3 = 10;
				int b4 = 50;
				_expected = "POSSIBLE";
				_received = _obj.buy(price, b1, b2, b3, b4); break;
			}
			case 3:
			{
				int price = 66;
				int b1 = 1;
				int b2 = 5;
				int b3 = 10;
				int b4 = 50;
				_expected = "POSSIBLE";
				_received = _obj.buy(price, b1, b2, b3, b4); break;
			}
			case 4:
			{
				int price = 1000;
				int b1 = 999;
				int b2 = 998;
				int b3 = 997;
				int b4 = 996;
				_expected = "IMPOSSIBLE";
				_received = _obj.buy(price, b1, b2, b3, b4); break;
			}
			case 5:
			{
				int price = 20;
				int b1 = 5;
				int b2 = 5;
				int b3 = 5;
				int b4 = 5;
				_expected = "POSSIBLE";
				_received = _obj.buy(price, b1, b2, b3, b4); break;
			}
			case 6:
			{
				int price = 2;
				int b1 = 1;
				int b2 = 5;
				int b3 = 10;
				int b4 = 50;
				_expected = "IMPOSSIBLE";
				_received = _obj.buy(price, b1, b2, b3, b4); break;
			}
			/*case 7:
			{
				int price = ;
				int b1 = ;
				int b2 = ;
				int b3 = ;
				int b4 = ;
				_expected = ;
				_received = _obj.buy(price, b1, b2, b3, b4); break;
			}*/
			/*case 8:
			{
				int price = ;
				int b1 = ;
				int b2 = ;
				int b3 = ;
				int b4 = ;
				_expected = ;
				_received = _obj.buy(price, b1, b2, b3, b4); break;
			}*/
			/*case 9:
			{
				int price = ;
				int b1 = ;
				int b2 = ;
				int b3 = ;
				int b4 = ;
				_expected = ;
				_received = _obj.buy(price, b1, b2, b3, b4); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
