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
typedef pair<int,PII> PIII;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

class PiecesMover {
 public:
  vector<vector<int> > dist;
  PIII dfs(PII cur, PII start, int steps, const vector<vector<int> >& dboard, const vector<string>& nboard) {
    // check if connected
    if (dist[cur.first][cur.second] <= steps) return PIII(100000,cur);
    dist[cur.first][cur.second] = steps;
    for (int k=0;k<4;k++) {
      int ni = cur.first+dx[k];
      int nj = cur.second+dy[k];
      if (ni >=0 && ni < 5 && nj >= 0 && nj < 5 && dboard[ni][nj])
        return PIII(steps,cur);
    }
    PIII minpiii(100000,cur);
    for (int k=0;k<4;k++) {
      int ni = cur.first+dx[k];
      int nj = cur.second+dy[k];
      if (ni >=0 && ni < 5 && nj >= 0 && nj < 5 && dist[ni][nj] > steps+1 && nboard[ni][nj] != '*') {
        PIII p = dfs(PII(ni,nj),start,steps+1,dboard,nboard);
        if (p.first < minpiii.first)
          minpiii = p;
      }
    }
    return minpiii;
  }
  int getMinimumMoves(vector <string> board) {
    vector<PII> stars;
    for (int i=0;i<board.size();i++)
      for (int j=0;j<board[0].size();j++)
        if (board[i][j] == '*')
          stars.push_back(PII(i,j));
    int n = stars.size();
    vector<int> p(n);
    for (int i=0;i<p.size();i++)
      p[i] = i;
    int mindist = INT_MAX;
    do {
      vector<string> nboard = board;
      vector<vector<int> > dboard(board.size(),vector<int>(board[0].size(),0));
      int dst = 0;
      dboard[stars[p[0]].first][stars[p[0]].second] = 1;
      for (int i=1;i<p.size();i++) {
        dist = vector<vector<int> >(board.size(),vector<int>(board[0].size(),INT_MAX));
        PIII closest = dfs(stars[p[i]],stars[p[i]],0,dboard,nboard);
        dst+=closest.first;
        dboard[closest.second.first][closest.second.second] = 1;
        if (closest.second != stars[p[i]]) {
          nboard[stars[p[i]].first][stars[p[i]].second] = '.';
          nboard[closest.second.first][closest.second.second] = '*';
        }
      }
      mindist = min(dst,mindist);
    } while(next_permutation(p.begin(),p.end()));
    return mindist;
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
		cout << "Testing PiecesMover (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392825158;
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
		PiecesMover _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {".....",
				                  "..**.",
				                  ".....",
				                  "...*.",
				                  "....."};
				_expected = 1;
				_received = _obj.getMinimumMoves(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {".....",
				                  ".....",
				                  ".**..",
				                  ".*...",
				                  "**..."};
				_expected = 0;
				_received = _obj.getMinimumMoves(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"*...*",
				                  ".....",
				                  ".....",
				                  ".....",
				                  "*...*"};
				_expected = 12;
				_received = _obj.getMinimumMoves(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"...*.", ".*...", ".....", ".....", "..*.."};
				_expected = 4;
				_received = _obj.getMinimumMoves(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 4:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.getMinimumMoves(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.getMinimumMoves(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
