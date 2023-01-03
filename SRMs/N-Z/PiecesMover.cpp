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

int occupado[6][6];
int used[6];

class PiecesMover {
 public:
  vector<PII> stars;
  int n;
  int ans;
  void rec(int idx, int dist) {
    if (idx == n) {
      ans = min(ans,dist);
      return;
    }
    for (int i=0;i<5;i++)
      for (int j=0;j<5;j++) {
        if (occupado[i][j]) continue;
        bool good = (idx == 0);
        if (!good)
          for (int k=0;k<4;k++)
            if (i+dx[k] >=0 && i+dx[k] < 5 && j+dy[k] >= 0 && j+dy[k] < 5 &&
                occupado[i+dx[k]][j+dy[k]]) {
              good = true;
              break;
            }
        if (!good) continue;
        occupado[i][j] = 1;
        for (int k=0;k<n;k++) {
          if (used[k]) continue;
          used[k] = 1;
          rec(idx+1,dist+abs(stars[k].first-i)+abs(stars[k].second-j));
          used[k] = 0;
        }
        occupado[i][j] = 0;
      }
  }
  int getMinimumMoves(vector <string> board) {
    stars.clear();
    for (int i=0;i<board.size();i++)
      for (int j=0;j<board[0].size();j++)
        if (board[i][j] == '*')
          stars.push_back(PII(i,j));
    n = stars.size();
    memset(occupado,0,sizeof(occupado));
    memset(used,0,sizeof(used));
    ans = INT_MAX;
    rec(0,0);
    return ans;
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
