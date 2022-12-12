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
int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};
const int N = 8;
double mem[9][9][101];
bool seen[9][9][101];

class ChessKnight {
 public:
  double rec(int x, int y, int n) {
    double& r = mem[x][y][n];
    if (seen[x][y][n]) return r;
    seen[x][y][n] = 1;
    if (n == 0) return r = 1;
    double t = 0;
    double fac = 1.0/8;
    for (int k=0;k<8;k++) {
      int ni = x+dx[k];
      int nj = y+dy[k];
      if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
        t += fac*rec(ni,nj,n-1);
      }
    }
    return r = t;
  }
  double probability(int x, int y, int n) {
    x--; y--;
    memset(seen,0,sizeof(seen));
    return rec(x,y,n);
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
		cout << "Testing ChessKnight (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397654824;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ChessKnight _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x = 1;
				int y = 1;
				int n = 2;
				_expected = 0.1875;
				_received = _obj.probability(x, y, n); break;
			}
			case 1:
			{
				int x = 4;
				int y = 4;
				int n = 1;
				_expected = 1.0;
				_received = _obj.probability(x, y, n); break;
			}
			case 2:
			{
				int x = 2;
				int y = 3;
				int n = 10;
				_expected = 0.0522148497402668;
				_received = _obj.probability(x, y, n); break;
			}
			case 3:
			{
				int x = 4;
				int y = 3;
				int n = 50;
				_expected = 8.356427906809618E-7;
				_received = _obj.probability(x, y, n); break;
			}
			/*case 4:
			{
				int x = ;
				int y = ;
				int n = ;
				_expected = ;
				_received = _obj.probability(x, y, n); break;
			}*/
			/*case 5:
			{
				int x = ;
				int y = ;
				int n = ;
				_expected = ;
				_received = _obj.probability(x, y, n); break;
			}*/
			/*case 6:
			{
				int x = ;
				int y = ;
				int n = ;
				_expected = ;
				_received = _obj.probability(x, y, n); break;
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
