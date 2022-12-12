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

class TheMoviesLevelOneDivTwo {
 public:
  int find(int n, int m, vector <int> row, vector <int> seat) {
    vector<vector<int> > seats(n,vector<int>(m,0));
    for (int i=0;i<row.size();i++)
      seats[row[i]-1][seat[i]-1] = 1;
    int r = 0;
    for (int i=0;i<seats.size();i++)
      for (int j=0;j+1<seats[0].size();j++)
        if (seats[i][j] == 0 && seats[i][j+1] == 0)
          r++;
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
	string a = tt == -1 ? "0" : string(1,'0'+tt);
	char* b[2] = {argv[0],(char*)a.c_str()};
	if(tt!=-1){argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing TheMoviesLevelOneDivTwo (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1408025810;
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
		TheMoviesLevelOneDivTwo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int m = 3;
				int row[] = {1, 2};
				int seat[] = {2, 3};
				_expected = 1;
				_received = _obj.find(n, m, vector <int>(row, row+sizeof(row)/sizeof(int)), vector <int>(seat, seat+sizeof(seat)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 2;
				int m = 3;
				int row[] = {1, 1, 1, 2, 2, 2};
				int seat[] = {1, 2, 3, 1, 2, 3};
				_expected = 0;
				_received = _obj.find(n, m, vector <int>(row, row+sizeof(row)/sizeof(int)), vector <int>(seat, seat+sizeof(seat)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 4;
				int m = 7;
				int row[] = {1};
				int seat[] = {1};
				_expected = 23;
				_received = _obj.find(n, m, vector <int>(row, row+sizeof(row)/sizeof(int)), vector <int>(seat, seat+sizeof(seat)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 10;
				int m = 8;
				int row[] = {1, 9, 6, 10, 6, 7, 9, 3, 9, 2};
				int seat[] = {7, 7, 3, 3, 7, 1, 5, 1, 6, 2};
				_expected = 54;
				_received = _obj.find(n, m, vector <int>(row, row+sizeof(row)/sizeof(int)), vector <int>(seat, seat+sizeof(seat)/sizeof(int))); break;
			}
			/*case 4:
			{
				int n = ;
				int m = ;
				int row[] = ;
				int seat[] = ;
				_expected = ;
				_received = _obj.find(n, m, vector <int>(row, row+sizeof(row)/sizeof(int)), vector <int>(seat, seat+sizeof(seat)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int n = ;
				int m = ;
				int row[] = ;
				int seat[] = ;
				_expected = ;
				_received = _obj.find(n, m, vector <int>(row, row+sizeof(row)/sizeof(int)), vector <int>(seat, seat+sizeof(seat)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int m = ;
				int row[] = ;
				int seat[] = ;
				_expected = ;
				_received = _obj.find(n, m, vector <int>(row, row+sizeof(row)/sizeof(int)), vector <int>(seat, seat+sizeof(seat)/sizeof(int))); break;
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
