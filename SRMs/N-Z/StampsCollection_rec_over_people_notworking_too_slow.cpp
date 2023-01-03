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
typedef pair<int,LL> PLL;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE
map<PLL,LL> mem;

class StampsCollection {
 public:
  vector<vector<int> > demand;
  vector<int> price;
  LL rec(LL used, int idx) {
    if (idx == price.size()) {
      return 0;
    }
    if (mem.count(PLL(idx,used))) return mem[PLL(idx,used)];
    LL t = 0;
    bool good = true;
    for (int i=0;i<demand[idx].size();i++)
      if (used&(1LL<<demand[idx][i])) {
        good = false;
        break;
      }
    if (good) {
      LL nused = used;
      for (int i=0;i<demand[idx].size();i++)
        nused ^= 1LL<<demand[idx][i];
      t = (LL)price[idx]+rec(nused,idx+1);
    }
    t = max(t,rec(used,idx+1));
    return mem[PLL(idx,used)] = t;
  }
  int sell(int n, vector <string> deman, vector <int> price) {
    mem.clear();
    demand.clear();
    for (int i=0;i<deman.size();i++) {
      stringstream a(deman[i]);
      vector<int> cs;
      while (!a.eof()) {
        int c;
        a >> c;
        if (c > n) return 0;
        cs.push_back(c);
      }
      demand.push_back(cs);
    }
    this->price = price;
    return rec(0,0);
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
		cout << "Testing StampsCollection (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391531789;
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
		StampsCollection _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 10;
				string demand[] = {"0 4"};
				int price[] = {3};
				_expected = 3;
				_received = _obj.sell(n, vector <string>(demand, demand+sizeof(demand)/sizeof(string)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 2;
				string demand[] = {"1 0","0"};
				int price[] = {3,5};
				_expected = 5;
				_received = _obj.sell(n, vector <string>(demand, demand+sizeof(demand)/sizeof(string)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 3;
				string demand[] = {"0 1","0 2","1 2"};
				int price[] = {10,11,12};
				_expected = 12;
				_received = _obj.sell(n, vector <string>(demand, demand+sizeof(demand)/sizeof(string)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 3;
				string demand[] = {"0","1 0","1 2"};
				int price[] = {5,9,5};
				_expected = 10;
				_received = _obj.sell(n, vector <string>(demand, demand+sizeof(demand)/sizeof(string)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 20;
				string demand[] = {"0 1","1 2","2 3","3 0","4 5","5 6","6 4","8","8","9","9 10","10 11","11 12","12"};
				int price[] = {3,7,4,1,3,3,1,5,6,5,18,10,1,5};
				_expected = 40;
				_received = _obj.sell(n, vector <string>(demand, demand+sizeof(demand)/sizeof(string)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 50;
				string demand[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49"}
;
				int price[] = {1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000};
				_expected = 50000000;
				_received = _obj.sell(n, vector <string>(demand, demand+sizeof(demand)/sizeof(string)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			/*case 6:
			{
				int n = ;
				string demand[] = ;
				int price[] = ;
				_expected = ;
				_received = _obj.sell(n, vector <string>(demand, demand+sizeof(demand)/sizeof(string)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				string demand[] = ;
				int price[] = ;
				_expected = ;
				_received = _obj.sell(n, vector <string>(demand, demand+sizeof(demand)/sizeof(string)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
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
