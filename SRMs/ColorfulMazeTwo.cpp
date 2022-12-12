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

class ColorfulMazeTwo {
 public:
  double getProbability(vector <string> maze, vector <int> trap) {
    vector<vector<vector<double> > > seen(maze.size(),vector<vector<double> >(maze[0].size(),vector<double>(1<<7,0)));
    int s0 = 0,s1 = 0,e0 = 0,e1 = 0;
    for (int i=0;i<maze.size();i++)
      for (int j=0;j<maze[0].size();j++)
        if (maze[i][j] == '$') {
          s0 = i;
          s1 = j;
        } else if (maze[i][j] == '!') {
          e0 = i;
          e1 = j;
        }
    queue<PII> q;
    queue<double> q2;
    queue<int> q3;
    q.push(PII(s0,s1));
    seen[s0][s1][0] = 1;
    q2.push(1);
    q3.push(0);
    while (!q.empty()) {
      PII p = q.front();
      q.pop();
      double prob = q2.front();
      q2.pop();
      int state = q3.front();
      q3.pop();
      if (prob != seen[p.first][p.second][state]) continue;
      for (int k=0;k<4;k++) {
        int ni = p.first+dx[k];
        int nj = p.second+dy[k];
        if (ni >= 0 && ni < maze.size() && nj >= 0 && nj < maze[0].size() && maze[ni][nj] != '#') {
          double nprob = prob;
          int nstate = state;
          if (maze[ni][nj] >= 'A' && maze[ni][nj] <= 'G') {
            int idx = maze[ni][nj]-'A';
            if (!(nstate&(1<<idx))) {
              nstate |= (1<<idx);
              nprob *= (100-trap[idx])/100.0;
            }
          }
          if (nprob > seen[ni][nj][nstate]) {
            seen[ni][nj][nstate] = nprob;
            q.push(PII(ni,nj));
            q2.push(nprob);
            q3.push(nstate);
          }
        }
      }
    }
    double r = 0;
    for (int i=0;i<(1<<7);i++)
      r = max(r,seen[e0][e1][i]);
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
		cout << "Testing ColorfulMazeTwo (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1401739504;
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
		ColorfulMazeTwo _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string maze[] = { ".$.",
				                  "A#B",
				                  "A#B",
				                  ".!." };
				int trap[] = { 50, 50, 0, 0, 0, 0, 0 };
				_expected = 0.5;
				_received = _obj.getProbability(vector <string>(maze, maze+sizeof(maze)/sizeof(string)), vector <int>(trap, trap+sizeof(trap)/sizeof(int))); break;
			}
			case 1:
			{
				string maze[] = { ".$.",
				                  "A#B",
				                  "A#B",
				                  ".!." };
				int trap[] = { 50, 40, 0, 0, 0, 0, 0 };
				_expected = 0.6;
				_received = _obj.getProbability(vector <string>(maze, maze+sizeof(maze)/sizeof(string)), vector <int>(trap, trap+sizeof(trap)/sizeof(int))); break;
			}
			case 2:
			{
				string maze[] = { "$A#",
				                  ".#.",
				                  "#B!" };
				int trap[] = { 10, 10, 10, 10, 10, 10, 10 };
				_expected = 0.0;
				_received = _obj.getProbability(vector <string>(maze, maze+sizeof(maze)/sizeof(string)), vector <int>(trap, trap+sizeof(trap)/sizeof(int))); break;
			}
			case 3:
			{
				string maze[] = { "$A..",
				                  "##.A",
				                  "..B!" };
				int trap[] = { 50, 50, 0, 0, 0, 0, 0 };
				_expected = 0.5;
				_received = _obj.getProbability(vector <string>(maze, maze+sizeof(maze)/sizeof(string)), vector <int>(trap, trap+sizeof(trap)/sizeof(int))); break;
			}
			case 4:
			{
				string maze[] = { "$C..",
				                  "##.A",
				                  "..B!" };
				int trap[] = { 50, 50, 100, 0, 0, 0, 0 };
				_expected = 0.0;
				_received = _obj.getProbability(vector <string>(maze, maze+sizeof(maze)/sizeof(string)), vector <int>(trap, trap+sizeof(trap)/sizeof(int))); break;
			}
			case 5:
			{
				string maze[] = { ".$.D.E.F.G.!." };
				int trap[] = { 10, 20, 30, 40, 50, 60, 70 };
				_expected = 0.036000000000000004;
				_received = _obj.getProbability(vector <string>(maze, maze+sizeof(maze)/sizeof(string)), vector <int>(trap, trap+sizeof(trap)/sizeof(int))); break;
			}
			/*case 6:
			{
				string maze[] = ;
				int trap[] = ;
				_expected = ;
				_received = _obj.getProbability(vector <string>(maze, maze+sizeof(maze)/sizeof(string)), vector <int>(trap, trap+sizeof(trap)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				string maze[] = ;
				int trap[] = ;
				_expected = ;
				_received = _obj.getProbability(vector <string>(maze, maze+sizeof(maze)/sizeof(string)), vector <int>(trap, trap+sizeof(trap)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				string maze[] = ;
				int trap[] = ;
				_expected = ;
				_received = _obj.getProbability(vector <string>(maze, maze+sizeof(maze)/sizeof(string)), vector <int>(trap, trap+sizeof(trap)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(3);
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
