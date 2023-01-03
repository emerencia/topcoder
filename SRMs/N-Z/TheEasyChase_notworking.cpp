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
int seen[2][21][21][21][21];
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

class TheEasyChase {
 public:
  string winner(int n, int rowWhite, int colWhite, int rowBlack, int colBlack) {
    int parity = (abs(rowWhite-rowBlack)+abs(colWhite-colBlack))%2;
    string s;
    int whowins = -1;
    if (parity == 0) {
      whowins = 1;
      s+="BLACK";
    } else {
      whowins = 0;
      s+="WHITE";
    }
    memset(seen,-1,sizeof(seen));
    queue<PII> q1;
    queue<PII> q2;
    queue<PII> q3;
    // winner always in q1
    if (whowins == 1) {
      q2.push(PII(rowWhite-1,colWhite-1));
      q1.push(PII(rowBlack-1,colBlack-1));
    } else {
      q1.push(PII(rowWhite-1,colWhite-1));
      q2.push(PII(rowBlack-1,colBlack-1));
    }
    q3.push(PII(0,1));
    int longestwin = 0;
    while (!q1.empty()) {
      PII p1 = q1.front(); q1.pop();
      PII p2 = q2.front(); q2.pop();
      PII p3 = q3.front(); q3.pop();
      int turn = p3.first;
      int steps = p3.second;
      int& r = seen[turn][p1.first][p1.second][p2.first][p2.second];
      if (r != -1) continue;
      r = 1;
      if (turn == whowins) {
        // winner playing
        // check if we won
        if ((p1.first == p2.first && abs(p1.second-p2.second) <= (turn == 1 ? 2 : 1)) ||
            (p1.second == p2.second && abs(p1.first-p2.first) <= (turn == 1 ? 2 : 1))) {
          longestwin = max(longestwin,steps);
        }
        for (int k=0;k<4;k++) {
          int ni = p1.first+dx[k];
          int nj = p1.second+dy[k];
          if (ni >= 0 && ni < n && nj >= 0 && nj < n && seen[1-turn][ni][nj][p2.first][p2.second] == -1) {
            q1.push(PII(ni,nj));
            q2.push(PII(p2.first,p2.second));
            q3.push(PII(1-turn,steps+1));
          }
        }
        if (turn == 1) {
          for (int k=0;k<4;k++) {
            int ni = p1.first+2*dx[k];
            int nj = p1.second+2*dy[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < n && seen[1-turn][ni][nj][p2.first][p2.second] == -1) {
              q1.push(PII(ni,nj));
              q2.push(PII(p2.first,p2.second));
              q3.push(PII(1-turn,steps+1));
            }
          }
        }
      } else {
        // loser trying to escape
        for (int k=0;k<4;k++) {
          int ni = p2.first+dx[k];
          int nj = p2.second+dy[k];
          if (ni >= 0 && ni < n && nj >= 0 && nj < n && seen[1-turn][p1.first][p1.second][ni][nj] == -1) {
            q2.push(PII(ni,nj));
            q1.push(PII(p1.first,p1.second));
            q3.push(PII(1-turn,steps+1));
          }
        }
        if (turn == 1) {
          for (int k=0;k<4;k++) {
            int ni = p2.first+2*dx[k];
            int nj = p2.second+2*dy[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < n && seen[1-turn][p1.first][p1.second][ni][nj] == -1) {
              q2.push(PII(ni,nj));
              q1.push(PII(p1.first,p1.second));
              q3.push(PII(1-turn,steps+1));
            }
          }
        }
      }
    }
    stringstream r;
    r << s << " " << longestwin;
    return r.str();
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
		cout << "Testing TheEasyChase (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392652758;
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
		TheEasyChase _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int rowWhite = 1;
				int colWhite = 1;
				int rowBlack = 2;
				int colBlack = 2;
				_expected = "BLACK 2";
				_received = _obj.winner(n, rowWhite, colWhite, rowBlack, colBlack); break;
			}
			case 1:
			{
				int n = 2;
				int rowWhite = 2;
				int colWhite = 2;
				int rowBlack = 1;
				int colBlack = 2;
				_expected = "WHITE 1";
				_received = _obj.winner(n, rowWhite, colWhite, rowBlack, colBlack); break;
			}
			case 2:
			{
				int n = 3;
				int rowWhite = 1;
				int colWhite = 1;
				int rowBlack = 3;
				int colBlack = 3;
				_expected = "BLACK 6";
				_received = _obj.winner(n, rowWhite, colWhite, rowBlack, colBlack); break;
			}
			/*case 3:
			{
				int n = ;
				int rowWhite = ;
				int colWhite = ;
				int rowBlack = ;
				int colBlack = ;
				_expected = ;
				_received = _obj.winner(n, rowWhite, colWhite, rowBlack, colBlack); break;
			}*/
			/*case 4:
			{
				int n = ;
				int rowWhite = ;
				int colWhite = ;
				int rowBlack = ;
				int colBlack = ;
				_expected = ;
				_received = _obj.winner(n, rowWhite, colWhite, rowBlack, colBlack); break;
			}*/
			/*case 5:
			{
				int n = ;
				int rowWhite = ;
				int colWhite = ;
				int rowBlack = ;
				int colBlack = ;
				_expected = ;
				_received = _obj.winner(n, rowWhite, colWhite, rowBlack, colBlack); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
