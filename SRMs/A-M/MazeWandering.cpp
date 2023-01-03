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

class MazeWandering {
 public:
  vector<vector<int> > subtreesize;
  vector<string> maze;
  int nodecount;
  int dfs(int ci, int cj, int pi, int pj) {
    int subsz = 0;
    for (int k=0;k<4;k++) {
      int ni = ci+dx[k];
      int nj = cj+dy[k];
      if (ni >= 0 && ni < maze.size() && nj >= 0 && nj < maze[0].size() &&
          (ni != pi || nj != pj) && maze[ni][nj] != 'X') {
        subsz+=1+dfs(ni,nj,ci,cj);
      }
    }
    return subtreesize[ci][cj] = subsz;
  }
  LL dfs2(int ci, int cj, int pi, int pj, int parentval) {
    int curval = (pi == -1 ? 0 : parentval + 2*subtreesize[ci][cj]+1);
    LL r = curval;
    nodecount++;
    for (int k=0;k<4;k++) {
      int ni = ci+dx[k];
      int nj = cj+dy[k];
      if (ni >= 0 && ni < maze.size() && nj >= 0 && nj < maze[0].size() &&
          (ni != pi || nj != pj) && maze[ni][nj] != 'X') {
        r+=dfs2(ni,nj,ci,cj,curval);
      }
    }
    return r;
  }
  double expectedTime(vector <string> maze) {
    this->maze = maze;
    subtreesize = vector<vector<int> >(maze.size(),vector<int>(maze[0].size(),0));
    int si = 0, sj = 0;
    for (int i=0;i<maze.size();i++)
      for (int j=0;j<maze[0].size();j++)
        if (maze[i][j] == '*') {
          si = i;
          sj = j;
          break;
        }
    dfs(si,sj,-1,-1);
    nodecount = 0;
    double r = dfs2(si,sj,-1,-1,0);
    r/=nodecount;
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
		cout << "Testing MazeWandering (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395755203;
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
		MazeWandering _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string maze[] = {"*",
				                 "."};
				_expected = 0.5;
				_received = _obj.expectedTime(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			case 1:
			{
				string maze[] = {"*.."};
				_expected = 2.3333333333333335;
				_received = _obj.expectedTime(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			case 2:
			{
				string maze[] = {"...",
				                 "X*X",
				                 "..."};
				_expected = 4.857142857142857;
				_received = _obj.expectedTime(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			case 3:
			{
				string maze[] = {".*.",
				                 ".XX",
				                 "..."};
				_expected = 13.714285714285714;
				_received = _obj.expectedTime(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			case 4:
			{
				string maze[] = {"*........",
				                 "XXX.XXXX.",
				                 ".XX.X....",
				                 ".....XX.X"};
				_expected = 167.2608695652174;
				_received = _obj.expectedTime(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			/*case 5:
			{
				string maze[] = ;
				_expected = ;
				_received = _obj.expectedTime(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string maze[] = ;
				_expected = ;
				_received = _obj.expectedTime(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string maze[] = ;
				_expected = ;
				_received = _obj.expectedTime(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
