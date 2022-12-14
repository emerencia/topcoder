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

class MazeOnFire {
 public:
  int maximumTurns(vector <string> maze) {
    for (int turn=0;turn<2501;turn++) {
      // player moves
      int numplayers = 0;
      vector<string> newmaze = maze;
      for (int i=0;i<maze.size();i++)
        for (int j=0;j<maze[0].size();j++) {
          if (maze[i][j] != '$') continue;
          numplayers++;
          for (int k=0;k<4;k++) {
            int ni = i+dx[k];
            int nj = j+dy[k];
            if (ni >= 0 && ni < maze.size() && nj >= 0 && nj < maze[0].size() && maze[ni][nj] == '.') {
              newmaze[ni][nj] = '$';
            }
          }
        }
      if (numplayers == 0) return turn;
      maze = newmaze;
      // fire moves
      for (int i=0;i<maze.size();i++)
        for (int j=0;j<maze[0].size();j++) {
          if (maze[i][j] != 'F') continue;
          for (int k=0;k<4;k++) {
            int ni = i+dx[k];
            int nj = j+dy[k];
            if (ni >= 0 && ni < maze.size() && nj >= 0 && nj < maze[0].size() && maze[ni][nj] != '#') {
              newmaze[ni][nj] = 'F';
            }
          }
        }
      maze = newmaze;
    }
    return -1;
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
		cout << "Testing MazeOnFire (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1407273246;
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
		MazeOnFire _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string maze[] = {"F..",
				                 ".$.",
				                 "..."};
				_expected = 4;
				_received = _obj.maximumTurns(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			case 1:
			{
				string maze[] = {".F#...",
				                 "F....#",
				                 ".F###.",
				                 "F.#.$.",
				                 "F.#..."};
				_expected = -1;
				_received = _obj.maximumTurns(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			case 2:
			{
				string maze[] = {"....#.",
				                 "$##.#.",
				                 ".#..#F",
				                 ".F#.#.",
				                 "..#..."};
				_expected = 7;
				_received = _obj.maximumTurns(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			case 3:
			{
				string maze[] = {"...$..",
				                 "..#...",
				                 "..###.",
				                 "..#...",
				                 "F.#.F."};
				_expected = 7;
				_received = _obj.maximumTurns(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			case 4:
			{
				string maze[] = {".F....F.",
				                 ".#.##.#.",
				                 ".#....#.",
				                 "F.$##..F",
				                 ".#....#.",
				                 ".###.##.",
				                 ".F....F."};
				_expected = 4;
				_received = _obj.maximumTurns(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}
			/*case 5:
			{
				string maze[] = ;
				_expected = ;
				_received = _obj.maximumTurns(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string maze[] = ;
				_expected = ;
				_received = _obj.maximumTurns(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string maze[] = ;
				_expected = ;
				_received = _obj.maximumTurns(vector <string>(maze, maze+sizeof(maze)/sizeof(string))); break;
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
