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
int dx[] = {-1,-2,-2,-1,1,2,2,1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};

class KnightsTour {
 public:
  struct Coord {
    int x,y,a;
    Coord(int x, int y, int a) : x(x),y(y),a(a) {};
    bool operator<(const Coord& o) const {
      if (a != o.a) return a < o.a;
      if (x != o.x) return x < o.x;
      return y < o.y;
    }
  };
  int visitedPositions(vector <string> board) {
    vector<vector<bool> > seen(8,vector<bool>(8,false));
    int cx = 0;
    int cy = 0;
    for (int i=0;i<8;i++)
      for (int j=0;j<8;j++)
        if (board[i][j] == 'K') {
          cx = i;
          cy = j;
          break;
        }
    int r = 1;
    seen[cx][cy] = 1;
    bool changed = true;
    while (changed) {
      changed = false;
      vector<Coord> next;
      for (int k=0;k<8;k++) {
        int ni = cx+dx[k];
        int nj = cy+dy[k];
        if (ni >= 0 && ni < 8 && nj >= 0 && nj < 8 && board[ni][nj] == '.' && !seen[ni][nj]) {
          int a = 0;
          for (int l=0;l<8;l++) {
            int nni = ni+dx[l];
            int nnj = nj+dy[l];
            if (nni >= 0 && nni < 8 && nnj >= 0 && nnj < 8 && board[nni][nnj] == '.' && !seen[nni][nnj])
              a++;
          }
          next.push_back(Coord(ni,nj,a));
        }
      }
      if (next.size()) {
        changed = true;
        sort(next.begin(),next.end());
        cx = next[0].x;
        cy = next[0].y;
        seen[cx][cy] = 1;
        r++;
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
	char* b[2];
	if(tt!=-1){b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing KnightsTour (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396388431;
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
		KnightsTour _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"........"
				                 ,".*.*...."
				                 ,".*......"
				                 ,"..K...*."
				                 ,"*...*..."
				                 ,"...*...."
				                 ,"...*.*.."
				                 ,"........"};
				_expected = 39;
				_received = _obj.visitedPositions(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"K......."
				                 ,"........"
				                 ,"........"
				                 ,"........"
				                 ,"........"
				                 ,"........"
				                 ,"........"
				                 ,"........"};
				_expected = 64;
				_received = _obj.visitedPositions(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"********"
				                 ,"*******."
				                 ,"********"
				                 ,"**.***.*"
				                 ,"********"
				                 ,"***.*.**"
				                 ,"********"
				                 ,"****K***"};
				_expected = 3;
				_received = _obj.visitedPositions(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"*.*....*"
				                 ,".......*"
				                 ,"**...*.."
				                 ,"..***..."
				                 ,".**.*..."
				                 ,"..*.*..K"
				                 ,"..***.*."
				                 ,"**...*.."};
				_expected = 17;
				_received = _obj.visitedPositions(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"..*...*."
				                 ,"**.....*"
				                 ,"*..*...."
				                 ,"*..*...."
				                 ,".....*.."
				                 ,"....*..K"
				                 ,"**.*...*"
				                 ,"..**...."};
				_expected = 27;
				_received = _obj.visitedPositions(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 5:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.visitedPositions(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.visitedPositions(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.visitedPositions(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
