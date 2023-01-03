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
int di[] = {0,1,0,-1};
int dj[] = {1,0,-1,0};

class SpiralWalking {
 public:
  int totalPoints(vector <string> levelMap) {
    vector<vector<bool> > visited(levelMap.size(),vector<bool>(levelMap[0].size(),false));
    int allvisit = levelMap.size()*levelMap[0].size();
    int i = 0;
    int j = 0;
    int dir = 0;
    visited[i][j] = true;
    int r = 0;
    bool hadtoturn = false;
    for (int k=1;k<allvisit;k++) {
      int ni = i+di[dir];
      int nj = j+dj[dir];
      hadtoturn = false;
      while (ni < 0 || ni >= levelMap.size() || nj < 0 ||
             nj >= levelMap[0].size() || visited[ni][nj]) {
        dir = (dir+1)%4;
        ni = i+di[dir];
        nj = j+dj[dir];
        hadtoturn = true;
      }
      visited[ni][nj] = true;
      if (!hadtoturn) {
        //cout << i << " " << j << endl;
        r+=levelMap[i][j]-'0';
      }
      i = ni;
      j = nj;
    }
    r+=levelMap[i][j]-'0';
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
  if(tt!=-1){char* b[2];b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing SpiralWalking (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1389726665;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SpiralWalking _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string levelMap[] = {"111",
				                     "111",
				                     "111"};
				_expected = 5;
				_received = _obj.totalPoints(vector <string>(levelMap, levelMap+sizeof(levelMap)/sizeof(string))); break;
			}
			case 1:
			{
				string levelMap[] = {"101",
				                     "110"};
				_expected = 3;
				_received = _obj.totalPoints(vector <string>(levelMap, levelMap+sizeof(levelMap)/sizeof(string))); break;
			}
			case 2:
			{
				string levelMap[] = {"00",
				                     "10"};
				_expected = 1;
				_received = _obj.totalPoints(vector <string>(levelMap, levelMap+sizeof(levelMap)/sizeof(string))); break;
			}
			case 3:
			{
				string levelMap[] = {"86850",
				                     "76439",
				                     "15863",
				                     "24568",
				                     "45679",
				                     "71452",
				                     "05483"};
				_expected = 142;
				_received = _obj.totalPoints(vector <string>(levelMap, levelMap+sizeof(levelMap)/sizeof(string))); break;
			}
			/*case 4:
			{
				string levelMap[] = ;
				_expected = ;
				_received = _obj.totalPoints(vector <string>(levelMap, levelMap+sizeof(levelMap)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string levelMap[] = ;
				_expected = ;
				_received = _obj.totalPoints(vector <string>(levelMap, levelMap+sizeof(levelMap)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string levelMap[] = ;
				_expected = ;
				_received = _obj.totalPoints(vector <string>(levelMap, levelMap+sizeof(levelMap)/sizeof(string))); break;
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
