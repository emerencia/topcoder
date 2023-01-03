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
const int tt = 0;
// 
// END CUT HERE
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

class ActivateGame {
 public:
  int score(char c) {
    if (c >= '0' && c <= '9') return c-'0';
    if (c >= 'a' && c <= 'z') return c-'a'+10;
    return c-'A'+36;
  }
  int findMaxScore(vector <string> grid) {
    vector<vector<bool> > marked(grid.size(),vector<bool>(grid[0].size(),false));
    marked[0][0] = true;
    int r = 0;
    while (true) {
      int mdiff = -1;
      int mi = -1;
      int mj = -1;
      for (int i=0;i<grid.size();i++)
        for (int j=0;j<grid[0].size();j++) {
          if (!marked[i][j]) continue;
          int tscore = score(grid[i][j]);
          for (int k=0;k<4;k++) {
            int ni = i+dx[k];
            int nj = j+dy[k];
            if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && !marked[ni][nj]) {
              int diff = abs(score(grid[ni][nj])-tscore);
              if (diff > mdiff) {
                mdiff = diff;
                mi = ni;
                mj = nj;
              }
            }
          }
        }
      if (mi == -1) break;
      marked[mi][mj] = true;
      r+=mdiff;
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
		cout << "Testing ActivateGame (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1410085215;
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
		ActivateGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string grid[] = {"05",
				                 "aB"};
				_expected = 69;
				_received = _obj.findMaxScore(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 1:
			{
				string grid[] = {"03",
				                 "21"};
				_expected = 7;
				_received = _obj.findMaxScore(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 2:
			{
				string grid[] = {"John",
				                 "Brus",
				                 "Gogo"};
				_expected = 118;
				_received = _obj.findMaxScore(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 3:
			{
				string grid[] = {"AAA",
				                 "AAA",
				                 "AAA"};
				_expected = 0;
				_received = _obj.findMaxScore(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			/*case 4:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.findMaxScore(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.findMaxScore(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.findMaxScore(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
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
