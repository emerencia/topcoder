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
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

class SpidersOnTheGrid {
 public:
  int find(vector <string> A) {
    vector<vector<int> > spiders(A.size(),vector<int>(A[0].size(),1));
    map<char,int> directions;
    directions['W'] = 0;
    directions['N'] = 1;
    directions['E'] = 2;
    directions['S'] = 3;
    for (int i=0;i<A.size();i++)
      for (int j=0;j<A[0].size();j++) {
        int ni = i+dx[directions[A[i][j]]];
        int nj = j+dy[directions[A[i][j]]];
        spiders[i][j]--;
        if (ni >= 0 && ni < A.size() && nj >= 0 && nj < A[0].size())
          spiders[ni][nj]++;
      }
    int free = 0;
    for (int i=0;i<A.size();i++)
      for (int j=0;j<A[0].size();j++)
        free += spiders[i][j] == 0;
    return free;
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
		cout << "Testing SpidersOnTheGrid (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398953330;
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
		SpidersOnTheGrid _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string A[] = {"EW","NN"};
				_expected = 2;
				_received = _obj.find(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}
			case 1:
			{
				string A[] = {"EEEEEEEEEEEEEEEEEEEEEEEEEEEEEW"};
				_expected = 1;
				_received = _obj.find(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}
			case 2:
			{
				string A[] = {"EW"};
				_expected = 0;
				_received = _obj.find(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}
			case 3:
			{
				string A[] = {"ESW","ENW"};
				_expected = 4;
				_received = _obj.find(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}
			case 4:
			{
				string A[] = {"E"};
				_expected = 1;
				_received = _obj.find(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}
			/*case 5:
			{
				string A[] = ;
				_expected = ;
				_received = _obj.find(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string A[] = ;
				_expected = ;
				_received = _obj.find(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string A[] = ;
				_expected = ;
				_received = _obj.find(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
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
