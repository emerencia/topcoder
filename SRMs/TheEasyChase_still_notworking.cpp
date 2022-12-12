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
int mem[2][21][21][21][21];
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

class TheEasyChase {
 public:
  int n;
  int whowins;
  int rec(int turn, int rw, int cw, int rl, int cl) {
    int& r = mem[turn][rw][cw][rl][cl];
    if (r != -1) return r;
    int t = -1;
    r = -2;
    if (turn == whowins) {
      //r = INT_MAX;
      t = INT_MAX;
      // winner playing
      // check if we won
      if ((rw == rl && abs(cw-cl) <= (turn == 1 ? 2 : 1)) ||
          (cw == cl && abs(rw-rl) <= (turn == 1 ? 2 : 1))) {
        return r = 0;
      }
      for (int k=0;k<4;k++) {
        int ni = rw+dx[k];
        int nj = cw+dy[k];
        if (ni >= 0 && ni < n && nj >= 0 && nj < n && mem[1-turn][ni][nj][rl][cl] != -2) {
          t = min(t,1+rec(1-turn,ni,nj,rl,cl));
        }
      }
      if (turn == 1) {
        for (int k=0;k<4;k++) {
          int ni = rw+2*dx[k];
          int nj = cw+2*dy[k];
          if (ni >= 0 && ni < n && nj >= 0 && nj < n && mem[1-turn][ni][nj][rl][cl] != -2) {
            t = min(t,1+rec(1-turn,ni,nj,rl,cl));
          }
        }
      }
    } else {
      // loser trying to escape
      //r = 0;
      t = 0;
      for (int k=0;k<4;k++) {
        int ni = rl+dx[k];
        int nj = cl+dy[k];
        if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
          if (mem[1-turn][rw][cw][ni][nj] == -2) return r = 100000;
          t = max(t,1+rec(1-turn,rw,cw,ni,nj));
        }
      }
      if (turn == 1) {
        for (int k=0;k<4;k++) {
          int ni = rl+2*dx[k];
          int nj = cl+2*dy[k];
          if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
            if (mem[1-turn][rw][cw][ni][nj] == -2) return r = 100000;
            t = max(t,1+rec(1-turn,rw,cw,ni,nj));
          }
        }
      }
    }
    return r = t;
  }
  string winner(int n, int rowWhite, int colWhite, int rowBlack, int colBlack) {
    this->n = n;
    int parity = (abs(rowWhite-rowBlack)+abs(colWhite-colBlack))%2;
    string s;
    whowins = -1;
    if (parity == 0) {
      whowins = 1;
      s+="BLACK";
    } else {
      whowins = 0;
      s+="WHITE";
    }
        int longestwina = -1;
    int longestwinb = -1;
    
   // if (whowins == 1) {
    whowins = 1;
    memset(mem,-1,sizeof(mem));
      longestwina = 1+rec(0,rowBlack-1,colBlack-1,rowWhite-1,colWhite-1);
    //} else {
      whowins = 0;
      memset(mem,-1,sizeof(mem));
      longestwinb = 1+rec(0,rowWhite-1,colWhite-1,rowBlack-1,colBlack-1);
    //}
    cout << longestwina << endl;
    cout << longestwinb << endl;
    int longestwin = min(longestwina,longestwinb);
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
