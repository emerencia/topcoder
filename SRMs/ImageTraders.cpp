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
int mem[11][1<<16][16];

class ImageTraders {
 public:
  int n;
  vector<string> price;
  int rec(int curprice, int alreadyownedby, int curowner) {
    int& r = mem[curprice][alreadyownedby][curowner];
    if (r != -1) return r;
    int t = 0;
    for (int i=0;i<n;i++) {
      if ((alreadyownedby&(1<<i)) || price[curowner][i]-'0' < curprice) continue;
      t= max(t,rec(price[curowner][i]-'0',alreadyownedby|(1<<i),i));
    }
    return r = t+1;
  }
  int maxOwners(vector <string> price) {
    n = price.size();
    this->price = price;
    memset(mem,-1,sizeof(mem));
    return rec(0,1,0);
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
		cout << "Testing ImageTraders (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393514130;
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
		ImageTraders _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string price[] = {
				                 "01",
				                 "10"
				                 };
				_expected = 2;
				_received = _obj.maxOwners(vector <string>(price, price+sizeof(price)/sizeof(string))); break;
			}
			case 1:
			{
				string price[] = {
				                 "022",
				                 "101",
				                 "110"
				                 };
				_expected = 2;
				_received = _obj.maxOwners(vector <string>(price, price+sizeof(price)/sizeof(string))); break;
			}
			case 2:
			{
				string price[] = {
				                 "01231",
				                 "00231",
				                 "00031",
				                 "00002",
				                 "00000"
				                 };
				_expected = 4;
				_received = _obj.maxOwners(vector <string>(price, price+sizeof(price)/sizeof(string))); break;
			}
			case 3:
			{
				string price[] = {
				                 "15555",
				                 "11111",
				                 "15111",
				                 "11111",
				                 "11111"
				                 };
				_expected = 3;
				_received = _obj.maxOwners(vector <string>(price, price+sizeof(price)/sizeof(string))); break;
			}
			case 4:
			{
				string price[] = {
				                 "0100000000",
				                 "0020000000",
				                 "0003000000",
				                 "0000400000",
				                 "0000050000",
				                 "0000006000",
				                 "0000000700",
				                 "0000000080",
				                 "0000000009",
				                 "1111111111"
				                 };
				_expected = 10;
				_received = _obj.maxOwners(vector <string>(price, price+sizeof(price)/sizeof(string))); break;
			}
			/*case 5:
			{
				string price[] = ;
				_expected = ;
				_received = _obj.maxOwners(vector <string>(price, price+sizeof(price)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string price[] = ;
				_expected = ;
				_received = _obj.maxOwners(vector <string>(price, price+sizeof(price)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string price[] = ;
				_expected = ;
				_received = _obj.maxOwners(vector <string>(price, price+sizeof(price)/sizeof(string))); break;
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
