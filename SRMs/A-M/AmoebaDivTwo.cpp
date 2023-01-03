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

class AmoebaDivTwo {
 public:
  int count(vector <string> table, int K) {
    int r = 0;
    for (int i=0;i<table.size();i++)
      for (int j=0;j<table[0].size();j++) {
        if (j+K-1 < table[0].size()) {
          int good = true;
          for (int k = 0; k < K; k++)
            if (table[i][j+k] == 'M') {
              good = false;
              break;
            }
          if (good) ++r;
        }
        if (K >1 && i+K-1 < table.size()) {
          int good = true;
          for (int k = 0;k < K; k++)
            if (table[i+k][j] == 'M') {
              good = false;
              break;
            }
          if (good) ++r;
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
		cout << "Testing AmoebaDivTwo (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415204613;
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
		AmoebaDivTwo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string table[] = {"MA"};
				int K = 2;
				_expected = 0;
				_received = _obj.count(vector <string>(table, table+sizeof(table)/sizeof(string)), K); break;
			}
			case 1:
			{
				string table[] = {"AAA",
				                  "AMA",
				                  "AAA"};
				int K = 3;
				_expected = 4;
				_received = _obj.count(vector <string>(table, table+sizeof(table)/sizeof(string)), K); break;
			}
			case 2:
			{
				string table[] = {"AA",
				                  "AA",
				                  "AA"};
				int K = 2;
				_expected = 7;
				_received = _obj.count(vector <string>(table, table+sizeof(table)/sizeof(string)), K); break;
			}
			case 3:
			{
				string table[] = {"MMM",
				                  "MMM",
				                  "MMM"};
				int K = 1;
				_expected = 0;
				_received = _obj.count(vector <string>(table, table+sizeof(table)/sizeof(string)), K); break;
			}
			case 4:
			{
				string table[] = {"AAM",
				                  "MAM",
				                  "AAA"};
				int K = 1;
				_expected = 6;
				_received = _obj.count(vector <string>(table, table+sizeof(table)/sizeof(string)), K); break;
			}
			case 5:
			{
				string table[] = {"AAA",
				                  "AAM",
				                  "AAA"};
				int K = 2;
				_expected = 9;
				_received = _obj.count(vector <string>(table, table+sizeof(table)/sizeof(string)), K); break;
			}
			/*case 6:
			{
				string table[] = ;
				int K = ;
				_expected = ;
				_received = _obj.count(vector <string>(table, table+sizeof(table)/sizeof(string)), K); break;
			}*/
			/*case 7:
			{
				string table[] = ;
				int K = ;
				_expected = ;
				_received = _obj.count(vector <string>(table, table+sizeof(table)/sizeof(string)), K); break;
			}*/
			/*case 8:
			{
				string table[] = ;
				int K = ;
				_expected = ;
				_received = _obj.count(vector <string>(table, table+sizeof(table)/sizeof(string)), K); break;
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
