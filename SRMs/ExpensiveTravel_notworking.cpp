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
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

class ExpensiveTravel {
 public:
  // the problem is probably that it is suboptimal to count in time only
  // since sometimes a solution with higher number count can lead to the same
  // thing in less steps or something.
  int minTime(vector <string> m, int startRow, int startCol, int endRow, int endCol) {
    startRow--; startCol--; endRow--; endCol--;
    if (m[startRow][startCol] == '1') return -1;
    vector<vector<int> > seen(m.size(),vector<int>(m[0].size(),-1));
    queue<PII> q;
    queue<int> qc;
    q.push(PII(startRow,startCol));
    qc.push(2520/(m[startRow][startCol]-'0'));
    seen[startRow][startCol] = 2520/(m[startRow][startCol]-'0');
    while (!q.empty()) {
      PII p = q.front();
      q.pop();
      int cost = qc.front();
      qc.pop();
      if (cost != seen[p.first][p.second]) continue;
      for (int k=0;k<4;k++) {
        int ni = p.first+dx[k];
        int nj = p.second+dy[k];
        if (ni >= 0 && ni < m.size() && nj >= 0 && nj < m[0].size() && m[ni][nj] != '1') {
          int newcost = cost + 2520/(m[ni][nj]-'0');
          if (newcost%2520 == 0)
            newcost += 2520/(m[ni][nj]-'0') + 2520/(m[p.first][p.second]-'0');
          else if (newcost/2520 > cost/2520)
            newcost += 2520-(cost%2520);
          if (seen[ni][nj] == -1 || newcost < seen[ni][nj]) {
            seen[ni][nj] = newcost;
            q.push(PII(ni,nj));
            qc.push(newcost);
          }
        }
      }
    }
    return seen[endRow][endCol] == -1 ? -1 : 1+(seen[endRow][endCol])/2520;
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
		cout << "Testing ExpensiveTravel (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396976192;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ExpensiveTravel _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string m[] = {"22334"};
				int startRow = 1;
				int startCol = 1;
				int endRow = 1;
				int endCol = 5;
				_expected = 3;
				_received = _obj.minTime(vector <string>(m, m+sizeof(m)/sizeof(string)), startRow, startCol, endRow, endCol); break;
			}
			case 1:
			{
				string m[] = {"55",
				              "52",
				              "55"};
				int startRow = 1;
				int startCol = 2;
				int endRow = 3;
				int endCol = 2;
				_expected = 1;
				_received = _obj.minTime(vector <string>(m, m+sizeof(m)/sizeof(string)), startRow, startCol, endRow, endCol); break;
			}
			case 2:
			{
				string m[] = {"251",
				              "212",
				              "122"};
				int startRow = 1;
				int startCol = 1;
				int endRow = 3;
				int endCol = 3;
				_expected = -1;
				_received = _obj.minTime(vector <string>(m, m+sizeof(m)/sizeof(string)), startRow, startCol, endRow, endCol); break;
			}
			case 3:
			{
				string m[] = {"452232",
				              "287979",
				              "219872",
				              "928234",
				              "767676"};
				int startRow = 1;
				int startCol = 6;
				int endRow = 3;
				int endCol = 1;
				_expected = 3;
				_received = _obj.minTime(vector <string>(m, m+sizeof(m)/sizeof(string)), startRow, startCol, endRow, endCol); break;
			}
			case 4:
			{
				string m[] = {"11"};
				int startRow = 1;
				int startCol = 1;
				int endRow = 1;
				int endCol = 2;
				_expected = -1;
				_received = _obj.minTime(vector <string>(m, m+sizeof(m)/sizeof(string)), startRow, startCol, endRow, endCol); break;
			}
			case 5:
			{
				string m[] = {"123456789987654321"};
				int startRow = 1;
				int startCol = 2;
				int endRow = 1;
				int endCol = 16;
				_expected = 5;
				_received = _obj.minTime(vector <string>(m, m+sizeof(m)/sizeof(string)), startRow, startCol, endRow, endCol); break;
			}
			/*case 6:
			{
				string m[] = ;
				int startRow = ;
				int startCol = ;
				int endRow = ;
				int endCol = ;
				_expected = ;
				_received = _obj.minTime(vector <string>(m, m+sizeof(m)/sizeof(string)), startRow, startCol, endRow, endCol); break;
			}*/
			/*case 7:
			{
				string m[] = ;
				int startRow = ;
				int startCol = ;
				int endRow = ;
				int endCol = ;
				_expected = ;
				_received = _obj.minTime(vector <string>(m, m+sizeof(m)/sizeof(string)), startRow, startCol, endRow, endCol); break;
			}*/
			/*case 8:
			{
				string m[] = ;
				int startRow = ;
				int startCol = ;
				int endRow = ;
				int endCol = ;
				_expected = ;
				_received = _obj.minTime(vector <string>(m, m+sizeof(m)/sizeof(string)), startRow, startCol, endRow, endCol); break;
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
