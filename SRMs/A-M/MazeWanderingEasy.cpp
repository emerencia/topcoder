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
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

class MazeWanderingEasy {
 public:
  vector<string> maze;
  int cx,cy;
  PII dfs(int mx, int my, int px, int py) {
    if (mx == cx && my == cy)
      return PII(0,0);
    int choices = 0;
    int dmin = 1000000;
    int dminchoices = 0;
    for (int k=0;k<4;k++) {
      int ni = mx+dx[k];
      int nj = my+dy[k];
      if (ni >= 0 && ni < maze.size() && nj >= 0 && nj < maze[0].size()) {
        if ((ni != px || nj != py) && (maze[ni][nj] == '.' || maze[ni][nj] == '*')) {
          choices++;
          PII p = dfs(ni,nj,mx,my);
          if (p.first < dmin) {
            dmin = p.first;
            dminchoices = p.second;
          }
        }
      }
    }
    return PII(1+dmin,dminchoices+(choices>1));
  }
  int decisions(vector <string> maze) {
    this->maze = maze;
    int mx = -1;
    int my = -1;
    for (int i=0;i<maze.size();i++)
      for (int j=0;j<maze[0].size();j++) {
        if (maze[i][j] == 'M') {
          mx = i;
          my = j;
        } else if (maze[i][j] == '*') {
          cx = i;
          cy = j;
        }
      }
    PII p = dfs(mx,my,-1,-1);
    return p.second;
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
		cout << "Testing MazeWanderingEasy (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395161492;
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
		MazeWanderingEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string maze[] = {"*.M"};
				_expected = 0;
				_received = _obj.decisions(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			case 1:
			{
				string maze[] = {"*.M",
				                 ".X."};
				_expected = 1;
				_received = _obj.decisions(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			case 2:
			{
				string maze[] = {"...",
				                 "XMX",
				                 "..*"};
				_expected = 2;
				_received = _obj.decisions(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			case 3:
			{
				string maze[] = {".X.X......X",
				                 ".X*.X.XXX.X",
				                 ".XX.X.XM...",
				                 "......XXXX."};
				_expected = 3;
				_received = _obj.decisions(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			case 4:
			{
				string maze[] = {"..........*",
				                 ".XXXXXXXXXX",
				                 "...........",
				                 "XXXXXXXXXX.",
				                 "M.........."};
				_expected = 0;
				_received = _obj.decisions(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			/*case 5:
			{
				string maze[] = ;
				_expected = ;
				_received = _obj.decisions(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string maze[] = ;
				_expected = ;
				_received = _obj.decisions(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string maze[] = ;
				_expected = ;
				_received = _obj.decisions(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
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
