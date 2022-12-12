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
bool cut[402][402];
bool seen[402][402];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

class HoleCakeCuts {
 public:
  int cutTheCake(int cakeLength, int holeLength, vector <int> hc, vector <int> vc) {
    cout << cakeLength << endl; // unused parameter warning
    memset(cut,0,sizeof(cut));
    for (int i=0;i<hc.size();i++)
      for(int j=0;j<402;j++)
        cut[2*hc[i]+200][j] = 1;
    for (int i=0;i<vc.size();i++)
      for(int j=0;j<402;j++)
        cut[j][2*vc[i]+200] = 1;
    memset(seen,0,sizeof(seen));
    for (int i=-2*holeLength;i<=2*holeLength;i++)
      for (int j=-2*holeLength;j<=2*holeLength;j++)
        seen[i+200][j+200] = 1;
    int r = 0;
    for (int i=0;i<402;i++)
      for (int j=0;j<402;j++) {
        if (cut[i][j] || seen[i][j]) continue;
        ++r;
        seen[i][j] = 1;
        queue<PII> q;
        q.push(PII(i,j));
        while (!q.empty()) {
          PII p = q.front();
          q.pop();
          for (int k=0;k<4;k++) {
            int ni = p.first+dx[k];
            int nj = p.second+dy[k];
            if (ni >= 0 && ni < 402 && nj >= 0 && nj < 402 && !cut[ni][nj] && !seen[ni][nj]) {
              seen[ni][nj] = 1;
              q.push(PII(ni,nj));
            }
          }
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
	if(tt!=-1){char* b[2];b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}	if (argc == 1) 
	{
		cout << "Testing HoleCakeCuts (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1389906043;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		HoleCakeCuts _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int cakeLength = 5;
				int holeLength = 3;
				int horizontalCuts[] = {1, -4};
				int verticalCuts[] = {1};
				_expected = 6;
				_received = _obj.cutTheCake(cakeLength, holeLength, vector <int>(horizontalCuts, horizontalCuts+sizeof(horizontalCuts)/sizeof(int)), vector <int>(verticalCuts, verticalCuts+sizeof(verticalCuts)/sizeof(int))); break;
			}
			case 1:
			{
				int cakeLength = 10;
				int holeLength = 5;
				int horizontalCuts[] = {};
				int verticalCuts[] = {-2, 2};
				_expected = 4;
				_received = _obj.cutTheCake(cakeLength, holeLength, vector <int>(horizontalCuts, horizontalCuts+sizeof(horizontalCuts)/sizeof(int)), vector <int>(verticalCuts, verticalCuts+sizeof(verticalCuts)/sizeof(int))); break;
			}
			case 2:
			{
				int cakeLength = 10;
				int holeLength = 5;
				int horizontalCuts[] = {1};
				int verticalCuts[] = {-5, 5};
				_expected = 6;
				_received = _obj.cutTheCake(cakeLength, holeLength, vector <int>(horizontalCuts, horizontalCuts+sizeof(horizontalCuts)/sizeof(int)), vector <int>(verticalCuts, verticalCuts+sizeof(verticalCuts)/sizeof(int))); break;
			}
			case 3:
			{
				int cakeLength = 50;
				int holeLength = 5;
				int horizontalCuts[] = {40, -40};
				int verticalCuts[] = {20, 0, -20};
				_expected = 12;
				_received = _obj.cutTheCake(cakeLength, holeLength, vector <int>(horizontalCuts, horizontalCuts+sizeof(horizontalCuts)/sizeof(int)), vector <int>(verticalCuts, verticalCuts+sizeof(verticalCuts)/sizeof(int))); break;
			}
			case 4:
			{
				int cakeLength = 25;
				int holeLength = 15;
				int horizontalCuts[] = {-17, 12, 13, 14, 15};
				int verticalCuts[] = {20, 24, -1, -20, -22, -9};
				_expected = 39;
				_received = _obj.cutTheCake(cakeLength, holeLength, vector <int>(horizontalCuts, horizontalCuts+sizeof(horizontalCuts)/sizeof(int)), vector <int>(verticalCuts, verticalCuts+sizeof(verticalCuts)/sizeof(int))); break;
			}
			case 5:
			{
				int cakeLength = 58;
				int holeLength = 16;
				int horizontalCuts[] = {-31, 40};
				int verticalCuts[] = {8, 13};
				_expected = 10;
				_received = _obj.cutTheCake(cakeLength, holeLength, vector <int>(horizontalCuts, horizontalCuts+sizeof(horizontalCuts)/sizeof(int)), vector <int>(verticalCuts, verticalCuts+sizeof(verticalCuts)/sizeof(int))); break;
			}
			/*case 6:
			{
				int cakeLength = ;
				int holeLength = ;
				int horizontalCuts[] = ;
				int verticalCuts[] = ;
				_expected = ;
				_received = _obj.cutTheCake(cakeLength, holeLength, vector <int>(horizontalCuts, horizontalCuts+sizeof(horizontalCuts)/sizeof(int)), vector <int>(verticalCuts, verticalCuts+sizeof(verticalCuts)/sizeof(int))); break;
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
