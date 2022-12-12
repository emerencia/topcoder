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
const int kMod = 1e9+7;

class HamiltonPath {
 public:
  int n;
  LL rec(int togo, LL visited, int cur, int start, vector<string>& roads) {
    if (togo == 0) {
      if (cur == start || visited != (1LL<<n)-1) return 0;
      bool good = true;
      for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
          if (roads[i][j] == 'Y') {
            good = false;
            break;
          }
      return good;
    }
    LL r = 0;
    for (int i=0;i<n;i++) {
      if (i == cur || visited&(1LL<<i)) continue;
      bool setback = roads[cur][i] == 'Y';
      roads[cur][i] = 'N';
      roads[i][cur] = 'N';
      (r+=rec(togo-1,visited|(1LL<<i),i,start,roads))%=kMod;
      if (setback) {
        roads[cur][i] = 'Y';
        roads[i][cur] = 'Y';
      }
    }
    return r;
  }
  int countPaths(vector <string> roads) {
    n = roads.size();
    LL r = 0;
    for (int i=0;i<n;i++) {
      (r+=rec(n-1,1LL<<i,i,i,roads))%=kMod;
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
	char* b[2];
	if(tt!=-1){b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing HamiltonPath (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398434799;
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
		HamiltonPath _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string roads[] = {"NYN",
				                  "YNN",
				                  "NNN"};
				_expected = 4;
				_received = _obj.countPaths(vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			case 1:
			{
				string roads[] = {"NYYY",
				                  "YNNN",
				                  "YNNN",
				                  "YNNN"};
				_expected = 0;
				_received = _obj.countPaths(vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			case 2:
			{
				string roads[] = {"NYY",
				                  "YNY",
				                  "YYN"};
				_expected = 0;
				_received = _obj.countPaths(vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			case 3:
			{
				string roads[] = {"NNNNNY",
				                  "NNNNYN",
				                  "NNNNYN",
				                  "NNNNNN",
				                  "NYYNNN",
				                  "YNNNNN"};
				_expected = 24;
				_received = _obj.countPaths(vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			case 4:
			{
				string roads[] = {"NNNYNNYNNNNNNNNNNYNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNN", "YNNNNNNNNYNNNNNNNNNNNNNNNNN", "NNNNNNNNYNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNYNNNNNNNNN", "YNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNYNNNNNNNNNNNNNNNNNNNNNN", "NNNYNNNNNNNNNNYNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNYNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNYNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNN", "YNNNNYNNNNNYNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNN"};
				_expected = 0;
				_received = _obj.countPaths(vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			/*case 5:
			{
				string roads[] = ;
				_expected = ;
				_received = _obj.countPaths(vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string roads[] = ;
				_expected = ;
				_received = _obj.countPaths(vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
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
