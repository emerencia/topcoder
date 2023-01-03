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
int g[8][8];
int dx[] = {0,1,1,0,-1,-1};
int dy[] = {1,1,0,-1,-1,0};

class HexagonalBattlefieldEasy {
 public:
  int N;
  vector<int> counts;
  int rec() {
    for (int i=0;i<2*N-1;i++)
      for (int j=0;j<2*N-1;j++) {
        if (g[i][j] != 0) continue;
        int r = 0;
        int cnt = 0;
        for (int k=0;k<6;k++) {
          int ni = i+dx[k];
          int nj = j+dy[k];
          if (ni >= 0 && ni < 2*N-1 && nj >= 0 && nj < 2*N-1 && g[ni][nj] == 0) {
            cnt++;
            g[ni][nj] = 2;
            g[i][j] = 2;
            int t = rec();
            if (t < 100000)
              r += t;
            g[ni][nj] = 0;
            g[i][j] = 0;
          }
        }
        counts[cnt]++;
        if (!r) return 100000;
        return r;
      }
    return 1;
  }
  int countArrangements(vector <int> X, vector <int> Y, int N) {
    this->N = N;
    memset(g,-1,sizeof(g));
    counts = vector<int>(7,0);
    int freespots = 0;
    for (int i=-N+1;i<N;i++)
      for (int j=-N+1;j<N;j++)
        if (abs(i-j) < N) {
          freespots++;
          g[i+N-1][j+N-1] = 0;
        }
    for (int i=0;i<X.size();i++)
      g[X[i]+N-1][Y[i]+N-1] = 1;
    freespots -= X.size();
    if (freespots == 0) return 1;
    int r = rec();
    for (int i=0;i<counts.size();i++)
      cout << i << ": " << counts[i] << endl;
    cout << endl;
    return (r == 100000 ? 0 : r);
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
		cout << "Testing HexagonalBattlefieldEasy (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396667876;
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
		HexagonalBattlefieldEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int X[] = {-2,0,1,1,0};
				int Y[] = {-2,0,1,0,2};
				int N = 3;
				_expected = 10;
				_received = _obj.countArrangements(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), N); break;
			}
			case 1:
			{
				int X[] = {0};
				int Y[] = {0};
				int N = 2;
				_expected = 2;
				_received = _obj.countArrangements(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), N); break;
			}
			case 2:
			{
				int X[] = {0};
				int Y[] = {0};
				int N = 3;
				_expected = 104;
				_received = _obj.countArrangements(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), N); break;
			}
			case 3:
			{
				int X[] = {-1,0,0,1,2};
				int Y[] = {0,0,1,0,0};
				int N = 3;
				_expected = 6;
				_received = _obj.countArrangements(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), N); break;
			}
			case 4:
			{
				int X[] = {0,1,0,0,1,-1,-1};
				int Y[] = {0,0,-1,1,1,0,-1};
				int N = 2;
				_expected = 1;
				_received = _obj.countArrangements(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), N); break;
			}
			case 5:
			{
				int X[] = {0, 0};
				int Y[] = {0, -1};
				int N = 2;
				_expected = 0;
				_received = _obj.countArrangements(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), N); break;
			}
			case 6:
			{
				int X[] = {-3};
				int Y[] = {-3};
				int N = 4;
				_expected = 117600;
				_received = _obj.countArrangements(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), N); break;
			}
			/*case 7:
			{
				int X[] = ;
				int Y[] = ;
				int N = ;
				_expected = ;
				_received = _obj.countArrangements(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), N); break;
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
