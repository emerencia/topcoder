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
int g[51][51];

class CellRemoval {
 public:
  int cellsLeft(vector <int> parent, int deletedCell) {
    int zygote = 0;
    memset(g,0,sizeof(g));
    for (int i=0;i<parent.size();i++) {
      if (parent[i] == -1) {
        zygote = i;
        continue;
      }
      g[parent[i]][i] = 1;
    }
    if (deletedCell == zygote) return 0;
    for (int i=0;i<parent.size();i++)
      g[deletedCell][i] = 0;
    queue<int> q;
    q.push(zygote);
    int r = 0;
    while (!q.empty()) {
      int p = q.front(); q.pop();
      int c = 0;
      for (int i=0;i<parent.size();i++)
        if (g[p][i] && i != deletedCell) {
          c++;
          q.push(i);
        }
      if (!c) ++r;
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
		cout << "Testing CellRemoval (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394121010;
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
		CellRemoval _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int parent[] = {-1,0,0,1,1};
				int deletedCell = 2;
				_expected = 2;
				_received = _obj.cellsLeft(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), deletedCell); break;
			}
			case 1:
			{
				int parent[] = {-1,0,0,1,1};
				int deletedCell = 1;
				_expected = 1;
				_received = _obj.cellsLeft(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), deletedCell); break;
			}
			case 2:
			{
				int parent[] = {-1,0,0,1,1};
				int deletedCell = 0;
				_expected = 0;
				_received = _obj.cellsLeft(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), deletedCell); break;
			}
			case 3:
			{
				int parent[] = {-1,0,0,2,2,4,4,6,6};
				int deletedCell = 4;
				_expected = 2;
				_received = _obj.cellsLeft(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), deletedCell); break;
			}
			case 4:
			{
				int parent[] = {26,2,32,36,40,19,43,24,30,13,21,14,24,21,19,4,30,10,44,12,7,32,17,43,
				                35,18,7,36,10,16,5,38,35,4,13,-1,16,26,1,12,2,5,18,40,1,17,38,44,14};
				int deletedCell = 24;
				_expected = 14;
				_received = _obj.cellsLeft(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), deletedCell); break;
			}
			/*case 5:
			{
				int parent[] = ;
				int deletedCell = ;
				_expected = ;
				_received = _obj.cellsLeft(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), deletedCell); break;
			}*/
			/*case 6:
			{
				int parent[] = ;
				int deletedCell = ;
				_expected = ;
				_received = _obj.cellsLeft(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), deletedCell); break;
			}*/
			/*case 7:
			{
				int parent[] = ;
				int deletedCell = ;
				_expected = ;
				_received = _obj.cellsLeft(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), deletedCell); break;
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
