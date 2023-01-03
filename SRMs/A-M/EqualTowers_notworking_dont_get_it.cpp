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
int mem[51][250001];

class EqualTowers {
 public:
  vector<int> bricks;
  int rec(int idx, int heightdiff) {
    int& r = mem[idx][heightdiff];
    if (r != -1) return r;
    if (idx == bricks.size())
      return r = (heightdiff == 0 ? 0 : -1000000);
    int a = 0;
    if (bricks[idx]+heightdiff <= 250000)
      a = rec(idx+1,heightdiff+bricks[idx]);
    else
      a = -2;
    int b = -2;
    if (bricks[idx] > heightdiff) {
      int d = rec(idx+1,bricks[idx]-heightdiff);
      if (d != -2) b = heightdiff+d;
    } else {
      int d = rec(idx+1,heightdiff-bricks[idx]);
      if (d != -2)
        b = bricks[idx]+d;
    }
    int c = rec(idx+1,heightdiff);
    return r = max(a,max(b,c));
  }
  int height(vector <int> bricks) {
    this->bricks = bricks;
    memset(mem,-1,sizeof(mem));
    int r = rec(0,0);
    return r == 0 ? -1 : r;
  }
};
/*
const int MAX_TOWER_SIZE = 250000;
const int INF = 1000000;
int mem[50][MAX_TOWER_SIZE+1];

struct EqualTowers
{

    
    int subProblem(const vector<int>&bricks, int K, int D)
    {
        if(D>MAX_TOWER_SIZE) // Invalid case,
            return -INF;     // difference is too large

        if(K== bricks.size() )
        {
            if ( D == 0)  //towers have equal sizes:
                return 0; //So it is a valid case with max increment 0
            else
                return -INF ; //invalid case.
        }
                
        int &res = mem[K][D];
        if(res!=-1)     // memo-ization step
            return res; //

        // ignore this brick:
        int a = subProblem( bricks, K+1, D);
        
        // place this brick on the larger tower (A):
        int b = subProblem( bricks, K+1, D + bricks[K] );
        
        // place this brick on the shorter tower:
        int c;
        if ( bricks[K] > D)
            c = D + subProblem( bricks, K+1, bricks[K]-D); //(C)
        else
            c = bricks[K] + subProblem( bricks, K+1, D-bricks[K]); //(B)

        res = std::max(a, std::max(b,c) ); //pick the largest tower
                                           // size increment.
        return res;

    }
    
    int height(vector <int> bricks)
    {
        memset(mem, -1, sizeof(mem));           // initialize memory
        
        int largest = subProblem(bricks, 0, 0);
        
        if( largest == 0) // for our subproblem, a par of towers
            return -1;    // of size 0 is possible, but the problem
                          // requires us to return -1 in this case.

        return largest;
    }
};
*/

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
		cout << "Testing EqualTowers (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395987360;
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
		EqualTowers _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int bricks[] = { 2, 3, 5 };
				_expected = 5;
				_received = _obj.height(vector <int>(bricks, bricks+sizeof(bricks)/sizeof(int))); break;
			}
			case 1:
			{
				int bricks[] = { 10, 9, 2 };
				_expected = -1;
				_received = _obj.height(vector <int>(bricks, bricks+sizeof(bricks)/sizeof(int))); break;
			}
			case 2:
			{
				int bricks[] = { 11, 11 };
				_expected = 11;
				_received = _obj.height(vector <int>(bricks, bricks+sizeof(bricks)/sizeof(int))); break;
			}
			case 3:
			{
				int bricks[] = { 14, 3, 20, 15, 15, 14, 24, 23, 15 };
				_expected = 64;
				_received = _obj.height(vector <int>(bricks, bricks+sizeof(bricks)/sizeof(int))); break;
			}
			case 4:
			{
				int bricks[] = {88242, 313, 1991, 4207, 2483, 1763, 224, 16, 582, 22943, 28632, 47682, 378, 90, 88, 43, 117, 19, 8};
				_expected = 99901;
				_received = _obj.height(vector <int>(bricks, bricks+sizeof(bricks)/sizeof(int))); break;
			}
			case 5:
			{
				int bricks[] = {4, 20, 2893, 50089, 5068, 1, 1654, 460, 2, 2, 4481, 1907, 10, 20321, 1904, 2031, 288665, 2455, 31027, 190, 541, 811, 8903, 15, 1675, 51, 15505, 8, 5, 58594, 11, 383, 172, 142};
				_expected = 105667;
				_received = _obj.height(vector <int>(bricks, bricks+sizeof(bricks)/sizeof(int))); break;
			}
			/*case 6:
			{
				int bricks[] = ;
				_expected = ;
				_received = _obj.height(vector <int>(bricks, bricks+sizeof(bricks)/sizeof(int))); break;
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
