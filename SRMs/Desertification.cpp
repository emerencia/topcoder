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
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

class Desertification {
 public:
  int desertArea(vector <string> island, int T) {
    int r = 0;
    for (int k=0;k<T;k++) {
      vector<string> nisland = island;
      for (int i=0;i<island.size();i++)
        for (int j=0;j<island[0].size();j++) {
          if (island[i][j] == 'D') continue;
          for (int c=0;c<4;c++) {
            int ni = i+dx[c];
            int nj = j+dy[c];
            if (ni >= 0 && ni < island.size() && nj >= 0 && nj < island[0].size() && island[ni][nj] == 'D')
              nisland[i][j] = 'D';
          }
        }
      island = nisland;
      r = 0;
      for (int i=0;i<island.size();i++)
        for (int j=0;j<island[0].size();j++)
          r+=island[i][j] == 'D';
      if (r == island.size() * island[0].size()) return r;
      if (r == 0) return 0;
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
		cout << "Testing Desertification (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1399466090;
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
		Desertification _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string island[] = {"FFF",
				                   "FDF",
				                   "FFF"};
				int T = 1;
				_expected = 5;
				_received = _obj.desertArea(vector <string>(island, island+sizeof(island)/sizeof(string)), T); break;
			}
			case 1:
			{
				string island[] = {"FFF",
				                   "FDF",
				                   "FFF"};
				int T = 2;
				_expected = 9;
				_received = _obj.desertArea(vector <string>(island, island+sizeof(island)/sizeof(string)), T); break;
			}
			case 2:
			{
				string island[] = {"FFFFF",
				                   "FFDFF",
				                   "FFFFD",
				                   "FFFFF",
				                   "FFFFF"};
				int T = 2;
				_expected = 17;
				_received = _obj.desertArea(vector <string>(island, island+sizeof(island)/sizeof(string)), T); break;
			}
			case 3:
			{
				string island[] = {"FFFFFF",
				                   "FFFFFF",
				                   "FFFFFF",
				                   "FFFFFF"};
				int T = 1000000000;
				_expected = 0;
				_received = _obj.desertArea(vector <string>(island, island+sizeof(island)/sizeof(string)), T); break;
			}
			case 4:
			{
				string island[] = {"FFFFFDFFFF",
				                   "FDFDFFFFFF",
				                   "FFFFFFFFFD",
				                   "FFFFFFFFFF",
				                   "DDFFFFFFFF", 
				                   "FFFFFFFFFD",
				                   "FFFFFFFFFF",
				                   "FFFFFFFDFF",
				                   "FFFFFFFDFF",
				                   "FFFFDDFFFF"};
				int T = 3;
				_expected = 90;
				_received = _obj.desertArea(vector <string>(island, island+sizeof(island)/sizeof(string)), T); break;
			}
			case 5:
			{
				string island[] = {"FFFFFDFFFF",
				                   "FDFDFFFFFF",
				                   "FFFFFFFFFD",
				                   "FFFFFFFFFF",
				                   "DDFFFFFFFF", 
				                   "FFFFFFFFFD",
				                   "FFFFFFFFFF",
				                   "FFFFFFFDFF",
				                   "FFFFFFFDFF",
				                   "FFFFDDFFFF"};
				int T = 98765432;
				_expected = 100;
				_received = _obj.desertArea(vector <string>(island, island+sizeof(island)/sizeof(string)), T); break;
			}
			/*case 6:
			{
				string island[] = ;
				int T = ;
				_expected = ;
				_received = _obj.desertArea(vector <string>(island, island+sizeof(island)/sizeof(string)), T); break;
			}*/
			/*case 7:
			{
				string island[] = ;
				int T = ;
				_expected = ;
				_received = _obj.desertArea(vector <string>(island, island+sizeof(island)/sizeof(string)), T); break;
			}*/
			/*case 8:
			{
				string island[] = ;
				int T = ;
				_expected = ;
				_received = _obj.desertArea(vector <string>(island, island+sizeof(island)/sizeof(string)), T); break;
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
