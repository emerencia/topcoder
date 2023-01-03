#include <string>
#include <iostream>
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
int dx[] = {-2,-2,-1,-1, 1, 1, 2, 2};
int dy[] = {-1, 1,-2, 2,-2, 2,-1, 1};

const int kMax = 4001;
char wins[kMax][kMax];  // winning
unsigned char wind[kMax][kMax];  // windir
unsigned char seen[kMax][kMax];  // windir cached?

class ErrantKnight {
 public:
  void makevalid(int& x, int& y) {
    x = abs(x);
    y = abs(y);
    if (x > y) swap(x,y);
  }
  void makevalid(int& x, int& y, int& d) {
    if (y < 0) {
      y = abs(y);
      int k = 0;
      while (dx[k] != dx[d] || dy[k] != -dy[d])
        ++k;
      d = k;
    }
    if (x < 0) {
      x = abs(x);
      int k = 0;
      while (dx[k] != -dx[d] || dy[k] != dy[d])
        ++k;
      d = k;
    }
    if (x > y) {
      swap(x,y);
      int k = 0;
      while (dx[k] != dy[d] || dy[k] != dx[d])
        ++k;
      d = k;
    }
  }
  bool winningdir(int x, int y, int d) {
    makevalid(x,y,d);
    if (seen[x][y]&(1<<d)) return (wind[x][y]>>d)&1;
    seen[x][y]|=(1<<d);
    int nx = x+dx[d];
    int ny = y+dy[d];
    if (x*x+y*y <= nx*nx+ny*ny) {
      return false;
    }
    /*
    if (nx == 0 && ny == 0) {
      wind[x][y]|=(1<<d);
      return true; // you got to 0,0 from point in 1 step
    }
    if (nx*nx+ny*ny == 1) {
      wind[x][y]|=(1<<d);
      return true; // your opponent can't make a move anymore
    }
    */
    if (!winning(nx,ny)) {
      wind[x][y]|=(1<<d);
      return true; // stop here and let the other player make a move
    }
    if (winningdir(nx,ny,d)) {
      wind[x][y]|=(1<<d);
      return true; // keep going same dir will make us win
    }
  
    return false;
  }
  char winning(int x, int y) {
    makevalid(x,y);
    char& r = wins[x][y];
    if (r != -1) return r;
    /*
    if (x == 0 && y == 0) return r = 0; // you lose
    if (x == 0 && y == 1) return r = 0; // can't make a move
    */
    for (int d=0;d<8;d++)
      if (winningdir(x,y,d))
        return r = 1;
    return r = 0;
  }
  string whoWins(vector <int> x, vector <int> y) {
    memset(seen,0,sizeof(seen));
    memset(wind,0,sizeof(wind));
    memset(wins,-1,sizeof(wins));
    string r;
    for (int i=0;i<x.size();i++)
      r+=winning(x[i],y[i]) ? 'W' : 'B';
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
	if(tt!=-1){char* b[2];b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}	if (argc == 1) 
	{
		cout << "Testing ErrantKnight (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390229800;
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
		ErrantKnight _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {1,1,2,2,9,3};
				int y[] = {0,1,0,1,5,3};
				_expected = "BWWWWB";
				_received = _obj.whoWins(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,7};
				int y[] = {0,0,0,0,0,0,0,1,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6,6,6,6,6,6,6,7};
				_expected = "BWBBBBBWWWWWWWWWWWWWWWWBWWWWWWWBWWWWWWWBWWWWWWWWWB";
				_received = _obj.whoWins(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {-10};
				int y[] = {0};
				_expected = "B";
				_received = _obj.whoWins(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {4000, 3999, 3998, 3997, 3996, 3995, 3994, 3993, 3992, 3991, 3990, 3989, 3988, 3987, 3986, 3985, 3984, 3983, 3982, 3981, 3980, 3979, 3978, 3977, 3976, 3975, 3974, 3973, 3972, 3971, 3970, 3969, 3968, 3967, 3966, 3965, 3964, 3963, 3962, 3961, 3960, 3959, 3958, 3957, 3956, 3955, 3954, 3953, 3952, 3951};
				int y[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
				_expected = "BWBBWBBWBBBBBWBBBBBWBBWBBWBBBBBWBBBBBWBBBBBWBBBBBW";
				_received = _obj.whoWins(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 4:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.whoWins(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.whoWins(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
