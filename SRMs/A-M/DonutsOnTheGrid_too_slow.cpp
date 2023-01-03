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

class DonutsOnTheGrid {
 public:
  int lastx,H,W,threshold;
  vector<vector<int> > grid;
  int getx() {
    return lastx = (lastx * 25173 + 13849)%65536;
  }
  long long calc(int H, int W, int seed, int threshold) {
    lastx = seed;
    this->H = H;
    this->W = W;
    this->threshold = threshold;
    grid = vector<vector<int> >(H,vector<int>(W));
    for (int i=0;i<H;i++)
      for (int j=0;j<W;j++)
        grid[i][j] = getx() >= threshold ? 0 : 1;
    vector<vector<int> > above(H,vector<int>(W,0));
    above[0] = grid[0];
    for (int i=1;i<H;i++)
      for (int j=0;j<W;j++)
        above[i][j] = grid[i][j] ? 1+above[i-1][j] : 0;
    vector<vector<int> > leftof(H,vector<int>(H,0));
    for (int i=0;i<H;i++)
      leftof[i][0] = grid[i][0];
    for (int j=1;j<W;j++)
      for (int i=0;i<H;i++)
        leftof[i][j] = grid[i][j] ? 1+leftof[i][j-1] : 0;
    LL r = 0;
    for (int i=0;i<H;i++)
      for (int j=i+2;j<H;j++) {
        int last0 = -1;
        for (int k=0;k<W;k++) {
          if (!above[i][k] || !above[j][k]) last0 = k;
          else {
            for (int l=last0+1;l+2<=k;l++)
              if (above[j][l] >= j-i && above[j][k] >= j-i)
                ++r;
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
	char* b[2];
	if(tt!=-1){b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing DonutsOnTheGrid (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398954832;
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
		DonutsOnTheGrid _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int H = 5;
				int W = 5;
				int seed = 222;
				int threshold = 55555;
				_expected = 4LL;
				_received = _obj.calc(H, W, seed, threshold); break;
			}
			case 1:
			{
				int H = 5;
				int W = 6;
				int seed = 121;
				int threshold = 58000;
				_expected = 3LL;
				_received = _obj.calc(H, W, seed, threshold); break;
			}
			case 2:
			{
				int H = 4;
				int W = 5;
				int seed = 6;
				int threshold = 50000;
				_expected = 1LL;
				_received = _obj.calc(H, W, seed, threshold); break;
			}
			case 3:
			{
				int H = 4;
				int W = 4;
				int seed = 1;
				int threshold = 65536;
				_expected = 9LL;
				_received = _obj.calc(H, W, seed, threshold); break;
			}
			/*case 4:
			{
				int H = ;
				int W = ;
				int seed = ;
				int threshold = ;
				_expected = LL;
				_received = _obj.calc(H, W, seed, threshold); break;
			}*/
			/*case 5:
			{
				int H = ;
				int W = ;
				int seed = ;
				int threshold = ;
				_expected = LL;
				_received = _obj.calc(H, W, seed, threshold); break;
			}*/
			/*case 6:
			{
				int H = ;
				int W = ;
				int seed = ;
				int threshold = ;
				_expected = LL;
				_received = _obj.calc(H, W, seed, threshold); break;
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
