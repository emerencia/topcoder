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
int outcome[2][21][21][21][21];
int need[2][21][21][21][21];
int moves[2][21][21][21][21];
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

class TheEasyChase {
 public:
  struct State {
    int p;
    int rw;
    int cw;
    int rb;
    int cb;
    State(int p,int rw,int cw,int rb,int cb) : p(p), rw(rw),cw(cw),rb(rb),cb(cb) {}
  };
  string winner(int n, int rowWhite, int colWhite, int rowBlack, int colBlack) {
    memset(outcome,-1,sizeof(outcome));
    queue<State> q;
    for (int p=0;p<2;p++)
      for (int rw=0;rw<n;rw++)
        for (int cw=0;cw<n;cw++)
          for (int rb=0;rb<n;rb++)
            for (int cb=0;cb<n;cb++) {
              if (rw == rb && cw == cb) continue;
              int nrpossiblemoves = 0;
              bool win = false;
              if (!p) {
                // white is playing
                for (int k=0;k<4;k++) {
                  int ni = rw+dx[k];
                  int nj = cw+dy[k];
                  if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                    ++nrpossiblemoves;
                    if (ni == rb && nj == cb) win = true;
                  }
                }
              } else {
                for (int c = 1;c<3;c++)
                  for (int k=0;k<4;k++) {
                    int ni = rb+c*dx[k];
                    int nj = cb+c*dy[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                      ++nrpossiblemoves;
                      if (ni == rw && nj == cw) win = true;
                    }
                  }
              }
              if (win) {
                outcome[p][rw][cw][rb][cb] = 1; // win
                moves[p][rw][cw][rb][cb] = 1;
                q.push(State(p,rw,cw,rb,cb));
              }
              need[p][rw][cw][rb][cb] = nrpossiblemoves;
            }
    while (!q.empty()) {
      State s = q.front(); q.pop();
      if (s.p) {
        // white was playing to get here
        for (int k=0;k<4;k++) {
          int ni = s.rw+dx[k];
          int nj = s.cw+dy[k];
          if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
            if (outcome[1-s.p][ni][nj][s.rb][s.cb] != -1) continue;
            if (outcome[s.p][s.rw][s.cw][s.rb][s.cb] == 1) 
              need[1-s.p][ni][nj][s.rb][s.cb]--;
            if (outcome[s.p][s.rw][s.cw][s.rb][s.cb] == 0 ||
                (outcome[s.p][s.rw][s.cw][s.rb][s.cb] == 1 &&
                need[1-s.p][ni][nj][s.rb][s.cb] == 0)) {
              outcome[1-s.p][ni][nj][s.rb][s.cb] = 1-outcome[s.p][s.rw][s.cw][s.rb][s.cb];
              moves[1-s.p][ni][nj][s.rb][s.cb] = 1+moves[s.p][s.rw][s.cw][s.rb][s.cb];
              q.push(State(1-s.p,ni,nj,s.rb,s.cb));
            }
          }
        }
      } else {
        // black was playing to get here
        for (int c = 1;c<3;c++)
          for (int k=0;k<4;k++) {
            int ni = s.rb+c*dx[k];
            int nj = s.cb+c*dy[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
              if (outcome[1-s.p][s.rw][s.cw][ni][nj] != -1) continue;
              if (outcome[s.p][s.rw][s.cw][s.rb][s.cb] == 1) 
                need[1-s.p][s.rw][s.cw][ni][nj]--;
              if (outcome[s.p][s.rw][s.cw][s.rb][s.cb] == 0 ||
                  (outcome[s.p][s.rw][s.cw][s.rb][s.cb] == 1 &&
                  need[1-s.p][s.rw][s.cw][ni][nj] == 0)) {
                outcome[1-s.p][s.rw][s.cw][ni][nj] = 1-outcome[s.p][s.rw][s.cw][s.rb][s.cb];
                moves[1-s.p][s.rw][s.cw][ni][nj] = 1+moves[s.p][s.rw][s.cw][s.rb][s.cb];
                q.push(State(1-s.p,s.rw,s.cw,ni,nj));
              }
            }
          }
      }
    }
    if (outcome[0][rowWhite-1][colWhite-1][rowBlack-1][colBlack-1] == -1)
      return "DRAW";
    stringstream r;
    r << (outcome[0][rowWhite-1][colWhite-1][rowBlack-1][colBlack-1] ? "WHITE" : "BLACK")
      << " " << moves[0][rowWhite-1][colWhite-1][rowBlack-1][colBlack-1];
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
			case 3:
			{
				int n = 3;
				int rowWhite = 3;
				int colWhite = 2;
				int rowBlack = 1;
				int colBlack = 1;
				_expected = "BLACK 8";
				_received = _obj.winner(n, rowWhite, colWhite, rowBlack, colBlack); break;
			}
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
