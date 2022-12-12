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

class LampsGrid {
 public:
  int mostLit(vector <string> initial, int K) {
    map<string,int> counts;
    for (int i=0;i<initial.size();i++)
      if (counts.count(initial[i]))
        counts[initial[i]]++;
      else
        counts[initial[i]]=1;
    int r = 0;
    for (map<string,int>::iterator i=counts.begin();i!=counts.end();i++) {
      string s = (*i).first;
      int zerocount = 0;
      for (int j=0;j<s.size();j++)
        zerocount+=(s[j] == '0');
      if (zerocount%2 != K%2 || zerocount > K) continue;
      r=max(r,(*i).second);
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
		cout << "Testing LampsGrid (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393857030;
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
		LampsGrid _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string initial[] = {"01",
				                    "10",
				                    "10"};
				int K = 1;
				_expected = 2;
				_received = _obj.mostLit(vector <string>(initial, initial+sizeof(initial)/sizeof(string)), K); break;
			}
			case 1:
			{
				string initial[] = {"101010"};
				int K = 2;
				_expected = 0;
				_received = _obj.mostLit(vector <string>(initial, initial+sizeof(initial)/sizeof(string)), K); break;
			}
			case 2:
			{
				string initial[] = {"00", "11"};
				int K = 999;
				_expected = 0;
				_received = _obj.mostLit(vector <string>(initial, initial+sizeof(initial)/sizeof(string)), K); break;
			}
			case 3:
			{
				string initial[] = {"0", "1", "0", "1", "0"};
				int K = 1000;
				_expected = 2;
				_received = _obj.mostLit(vector <string>(initial, initial+sizeof(initial)/sizeof(string)), K); break;
			}
			case 4:
			{
				string initial[] = {"001", "101", "001", "000", "111", "001", "101", "111", "110", "000", "111", "010", "110", "001"};
				int K = 6;
				_expected = 4;
				_received = _obj.mostLit(vector <string>(initial, initial+sizeof(initial)/sizeof(string)), K); break;
			}
			case 5:
			{
				string initial[] = {"01", "10", "01", "01", "10"};
				int K = 1;
				_expected = 3;
				_received = _obj.mostLit(vector <string>(initial, initial+sizeof(initial)/sizeof(string)), K); break;
			}
			/*case 6:
			{
				string initial[] = ;
				int K = ;
				_expected = ;
				_received = _obj.mostLit(vector <string>(initial, initial+sizeof(initial)/sizeof(string)), K); break;
			}*/
			/*case 7:
			{
				string initial[] = ;
				int K = ;
				_expected = ;
				_received = _obj.mostLit(vector <string>(initial, initial+sizeof(initial)/sizeof(string)), K); break;
			}*/
			/*case 8:
			{
				string initial[] = ;
				int K = ;
				_expected = ;
				_received = _obj.mostLit(vector <string>(initial, initial+sizeof(initial)/sizeof(string)), K); break;
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
