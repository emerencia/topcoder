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

class ImportantTasks {
 public:
  int maximalCost(vector <int> complexity, vector <int> computers) {
    sort(computers.rbegin(),computers.rend());
    sort(complexity.rbegin(),complexity.rend());
    vector<int> taken(complexity.size(),false);
    int r = 0;
    for (int i=0;i<computers.size();i++)
      for (int j=0;j<complexity.size();j++) {
        if (taken[j] || complexity[j] > computers[i]) continue;
        taken[j] = true;
        r++;
        break;
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
		cout << "Testing ImportantTasks (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396388115;
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
		ImportantTasks _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int complexity[] = {1,2,3};
				int computers[] = {2,2,2};
				_expected = 2;
				_received = _obj.maximalCost(vector <int>(complexity, complexity+sizeof(complexity)/sizeof(int)), vector <int>(computers, computers+sizeof(computers)/sizeof(int))); break;
			}
			case 1:
			{
				int complexity[] = {1,2,3};
				int computers[] = {3};
				_expected = 1;
				_received = _obj.maximalCost(vector <int>(complexity, complexity+sizeof(complexity)/sizeof(int)), vector <int>(computers, computers+sizeof(computers)/sizeof(int))); break;
			}
			case 2:
			{
				int complexity[] = {3,5,1,7};
				int computers[] = {9,4,1,1,1};
				_expected = 3;
				_received = _obj.maximalCost(vector <int>(complexity, complexity+sizeof(complexity)/sizeof(int)), vector <int>(computers, computers+sizeof(computers)/sizeof(int))); break;
			}
			case 3:
			{
				int complexity[] = {5,2,7,8,6,4,2,10,2,3};
				int computers[] = {4,1,3,6,2,10,11,1,1,3,4,2};
				_expected = 8;
				_received = _obj.maximalCost(vector <int>(complexity, complexity+sizeof(complexity)/sizeof(int)), vector <int>(computers, computers+sizeof(computers)/sizeof(int))); break;
			}
			case 4:
			{
				int complexity[] = {100};
				int computers[] = {100,100};
				_expected = 1;
				_received = _obj.maximalCost(vector <int>(complexity, complexity+sizeof(complexity)/sizeof(int)), vector <int>(computers, computers+sizeof(computers)/sizeof(int))); break;
			}
			/*case 5:
			{
				int complexity[] = ;
				int computers[] = ;
				_expected = ;
				_received = _obj.maximalCost(vector <int>(complexity, complexity+sizeof(complexity)/sizeof(int)), vector <int>(computers, computers+sizeof(computers)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int complexity[] = ;
				int computers[] = ;
				_expected = ;
				_received = _obj.maximalCost(vector <int>(complexity, complexity+sizeof(complexity)/sizeof(int)), vector <int>(computers, computers+sizeof(computers)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int complexity[] = ;
				int computers[] = ;
				_expected = ;
				_received = _obj.maximalCost(vector <int>(complexity, complexity+sizeof(complexity)/sizeof(int)), vector <int>(computers, computers+sizeof(computers)/sizeof(int))); break;
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
