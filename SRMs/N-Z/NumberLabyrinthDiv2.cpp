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
typedef pair<PII,int> PIII;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE
int steps[51][51][51];
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

class NumberLabyrinthDiv2 {
 public:
  int getMinimumNumberOfMoves(vector <string> board, int r1, int c1, int r2, int c2, int K) {
    fill(&steps[0][0][0],&steps[51][0][0],INT_MAX);
    int n = board.size();
    int m = board[0].size();
    queue<PIII> q;
    steps[r1][c1][0] = 0;
    q.push(PIII(PII(r1,c1),0));
    while (!q.empty()) {
      PIII p = q.front(); q.pop();
      int emptyused = p.second;
      int ci = p.first.first;
      int cj = p.first.second;
      int cursteps = steps[ci][cj][emptyused];
      if (ci == r2 && cj == c2) return cursteps;
      if (board[ci][cj] == '0') continue;
      if (board[ci][cj] == '.') {
        if (emptyused == K) continue;
        for (int c=1;c<10;c++)
          for (int k=0;k<4;k++) {
            int ni = ci+c*dx[k];
            int nj = cj+c*dy[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                steps[ni][nj][emptyused+1] > cursteps+1) {
              steps[ni][nj][emptyused+1] = cursteps+1;
              q.push(PIII(PII(ni,nj),emptyused+1));
            }
          }
      } else {
        int c = board[ci][cj]-'0';
        for (int k=0;k<4;k++) {
          int ni = ci+c*dx[k];
          int nj = cj+c*dy[k];
          if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
              steps[ni][nj][emptyused] > cursteps+1) {
            steps[ni][nj][emptyused] = cursteps+1;
            q.push(PIII(PII(ni,nj),emptyused));
          }
        }
      }
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
	if(tt!=-1){char* b[2];b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}	if (argc == 1) 
	{
		cout << "Testing NumberLabyrinthDiv2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393439488;
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
		NumberLabyrinthDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"...2",
				                  "....",
				                  "3..."};
				int r1 = 0;
				int c1 = 0;
				int r2 = 2;
				int c2 = 3;
				int K = 0;
				_expected = -1;
				_received = _obj.getMinimumNumberOfMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), r1, c1, r2, c2, K); break;
			}
			case 1:
			{
				string board[] = {"...2",
				                  "....",
				                  "3..."};
				int r1 = 0;
				int c1 = 0;
				int r2 = 2;
				int c2 = 3;
				int K = 1;
				_expected = 2;
				_received = _obj.getMinimumNumberOfMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), r1, c1, r2, c2, K); break;
			}
			case 2:
			{
				string board[] = {"...3",
				                  "....",
				                  "2..."};
				int r1 = 0;
				int c1 = 0;
				int r2 = 2;
				int c2 = 3;
				int K = 3;
				_expected = 3;
				_received = _obj.getMinimumNumberOfMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), r1, c1, r2, c2, K); break;
			}
			case 3:
			{
				string board[] = {"55255",
				                  ".0.0.",
				                  "..9..",
				                  "..3..",
				                  "3.9.3",
				                  "44.44"};
				int r1 = 3;
				int c1 = 2;
				int r2 = 4;
				int c2 = 2;
				int K = 10;
				_expected = 6;
				_received = _obj.getMinimumNumberOfMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), r1, c1, r2, c2, K); break;
			}
			case 4:
			{
				string board[] = {"920909949",
				                  "900020000",
				                  "009019039",
				                  "190299149",
				                  "999990319",
				                  "940229120",
				                  "000409399",
				                  "999119320",
				                  "009939999"};
				int r1 = 7;
				int c1 = 3;
				int r2 = 1;
				int c2 = 1;
				int K = 50;
				_expected = 10;
				_received = _obj.getMinimumNumberOfMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), r1, c1, r2, c2, K); break;
			}
			/*case 5:
			{
				string board[] = ;
				int r1 = ;
				int c1 = ;
				int r2 = ;
				int c2 = ;
				int K = ;
				_expected = ;
				_received = _obj.getMinimumNumberOfMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), r1, c1, r2, c2, K); break;
			}*/
			/*case 6:
			{
				string board[] = ;
				int r1 = ;
				int c1 = ;
				int r2 = ;
				int c2 = ;
				int K = ;
				_expected = ;
				_received = _obj.getMinimumNumberOfMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), r1, c1, r2, c2, K); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				int r1 = ;
				int c1 = ;
				int r2 = ;
				int c2 = ;
				int K = ;
				_expected = ;
				_received = _obj.getMinimumNumberOfMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), r1, c1, r2, c2, K); break;
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
