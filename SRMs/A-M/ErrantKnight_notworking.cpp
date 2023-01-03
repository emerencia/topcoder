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
int dx[] = {-1,-2,-1,-2, 1, 2, 1, 2};
int dy[] = {-2,-1, 2, 1, 2, 1,-2,-1};

const int kMax = 101;
char mem2[kMax][kMax];
char mem[kMax][kMax];

class ErrantKnight {
 public:
  char wins(int x, int y) {
    if (x < y) swap(x,y);
    char& r = mem2[x][y];
    if (r != 3) return r;
    if (x+y == 0) return (r = 1);
    if (x+y == 1) return (r = 0);
    if (x != y && x != 0 && y != 0) return (r = 1);
    int dis = x*x+y*y;
    for (int k=0;k<4;k++) {
      int lx = x+dx[k];
      int ly = y+dy[k];
      int pdis = dis;
      int ndis = lx*lx+ly*ly;
      while (ndis < pdis) {
        pdis = ndis;
        if (abs(lx)+abs(ly) <= 1) return (r = 1);
        if (abs(lx) < kMax && abs(ly) < kMax && !wins(abs(lx),abs(ly))) return (r = 1);
        lx +=dx[k];
        ly +=dy[k];
        ndis = lx*lx+ly*ly;
      }
    }
    return (r = 0);
  }
  char whowin(int x, int y) {
    //return wins(abs(x),abs(y)) ? 'W' : 'B';
    x = abs(x);
    y = abs(y);
    if (x < y) swap(x,y);
    return mem[abs(x)][abs(y)] ? 'W' : 'B';
  }
  string whoWins(vector <int> x, vector <int> y) {
    fill(&mem[0][0],&mem[kMax][0],3);
    fill(&mem2[0][0],&mem2[kMax][0],3);
    string r;
    mem[0][0] = 1;
    mem[1][0] = 0;
    mem[0][1] = 0;
    mem[1][1] = 1;
    for (int i=0;i<kMax;i++) {
      for (int j=0;j<kMax;j++) {
        for (int k=0;k<8;k++) {
          if (mem[i][j] == 3) continue;
          int l = 1;
          while (true) {
            int nx = abs(i+l*dx[k]);
            int ny = abs(j+l*dy[k]);
            //if (nx < ny) swap(nx,ny);
            if (nx >= ny && nx >= 0 && nx < kMax && ny >= 0 && ny < kMax && nx*nx+ny*ny > i*i+j*j) {
              if (mem[nx][ny] == 3) mem[nx][ny] = (i == 0 && j == 0 ? mem[i][j] : 1-mem[i][j]);
              else mem[nx][ny] |= (i == 0 && j == 0 ? mem[i][j] : 1-mem[i][j]);
            } else {
              break;
            }
            l++;
          }
        }
      }
    }
    /*
    cout << endl;
    for (int i=0;i<10;i++) {
      cout << string(i,' ');
      for (int j=i;j<10;j++)
        cout << (char)(mem[j][i]+'0');
      cout << "    ";
      cout << string(i,' ');
      for (int j=i;j<10;j++)
        cout << (char)(wins(j,i)+'0');
      cout << endl;
    }
    */
    for (int i=0;i<x.size();i++)
      r+=whowin(x[i],y[i]);
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
