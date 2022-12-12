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
// start: 19:32
// done: 20:07
// END CUT HERE

class TwoLLogo {
 public:
  long long countWays(vector <string> grid) {
    LL r = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int> > mini = vector<vector<int> >(n,vector<int>(m,0));
    vector<vector<int> > maxj = vector<vector<int> >(n,vector<int>(m,0));
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++) {
        if (grid[i][j] != '.') continue;
        int imin = i;
        while (imin > 0 && grid[imin-1][j] == '.') imin--;
        mini[i][j] = imin;
        int jmax = j;
        while (jmax+1 < m && grid[i][jmax+1] == '.') jmax++;
        maxj[i][j] = jmax;
      }
    for (int simax = 0;simax < n; simax++)
      for (int sjmin = 0;sjmin < m; sjmin++) {
        if (grid[simax][sjmin] == '#') continue;
        if (simax == 0 || grid[simax-1][sjmin] == '#') continue;
        if (sjmin+1 == m || grid[simax][sjmin+1] == '#') continue;
        int simin = mini[simax][sjmin];
        int sjmax = maxj[simax][sjmin];
        for (int fimax = simax; fimax < n; fimax++)
          for (int fjmin = (fimax == simax ? sjmin + 2 : 0); fjmin < m; fjmin++) {
            if (grid[fimax][fjmin] == '#') continue;
            if (fimax == 0 || grid[fimax-1][fjmin] == '#') continue;
            if (fjmin+1 == m || grid[fimax][fjmin+1] == '#') continue;
            int fimin = mini[fimax][fjmin];
            int fjmax = maxj[fimax][fjmin];
            r+=((fimax-fimin)*(fjmax-fjmin))*((simax-simin)*(sjmax-sjmin));
            if (fjmin <= sjmax && fjmin > sjmin && simax < fimax && simax >= fimin) {
              r-=(1+(simax-fimin))*(1+(sjmax-fjmin))*(simax-simin)*(fjmax-fjmin);
            } else if (simax == fimax && sjmax >= fjmin) {
              r-=(1+(sjmax-fjmin))*(simax-simin)*(fimax-fimin)*(fjmax-fjmin);
            } else if (fjmin == sjmin && fimin <= simax) {
              r-=(1+(simax-fimin))*(simax-simin)*(sjmax-sjmin)*(fjmax-fjmin);
            }
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
		cout << "Testing TwoLLogo (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1428509138;
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
		TwoLLogo _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string grid[] = {"....",
				                 "...."};
				_expected = 1LL;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 1:
			{
				string grid[] = {".##..",
				                 "...#.",
				                 ".#.#.",
				                 "#...#"};
				_expected = 3LL;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 2:
			{
				string grid[] = {"..#.",
				                 "#.#.",
				                 "....",
				                 "..#."};
				_expected = 4LL;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 3:
			{
				string grid[] = {"..",
				                 ".."};
				_expected = 0LL;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 4:
			{
				string grid[] = {".#.#",
				                 "....",
				                 ".#.#",
				                 "...."};
				_expected = 34LL;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 5:
			{
				string grid[] = {"##############",
				                 "##############",
				                 "#.############",
				                 "#.############",
				                 "#.############",
				                 "#.############",
				                 "#.############",
				                 "#.############",
				                 "#.#####.######",
				                 "#.#####.######",
				                 "#.#####.######",
				                 "#....##.######",
				                 "#######.######",
				                 "#######.######",
				                 "#######.######",
				                 "#######.######",
				                 "#######.######",
				                 "#######.######",
				                 "#######......#",
				                 "##############"};
				_expected = 1350LL;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 6:
			{
				string grid[] = {"#......",
				                 ".#....#",
				                 ".#.#...",
				                 "#....#.",
				                 ".##..#.",
				                 ".#.....",
				                 ".....#.",
				                 ".#.#...",
				                 ".#...#.",
				                 "..##..."};
				_expected = 2386LL;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 7:
			{
				string grid[] = {"...#..........................",
				                 "..............................",
				                 "..............................",
				                 "..................#...#.......",
				                 "..................#...........",
				                 "..............................",
				                 "...........#..................",
				                 "..............................",
				                 ".....#..#.....................",
				                 ".......................#......",
				                 "..................#.....#.....",
				                 "..............................",
				                 "..............................",
				                 "..............................",
				                 "..............................",
				                 "..#...........................",
				                 "..............................",
				                 "..............................",
				                 "..............................",
				                 "#............................#",
				                 "..............................",
				                 ".....#.........#............#.",
				                 "..............................",
				                 ".........................#....",
				                 ".#............................",
				                 ".............#................",
				                 "..............................",
				                 "..............................",
				                 ".......................#......",
				                 ".............#................"};
				_expected = 5020791386LL;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			/*case 8:
			{
				string grid[] = ;
				_expected = LL;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				string grid[] = ;
				_expected = LL;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}*/
			/*case 10:
			{
				string grid[] = ;
				_expected = LL;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
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
