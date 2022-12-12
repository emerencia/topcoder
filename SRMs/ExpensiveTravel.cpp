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
  struct Pqitem {
    int i, j, cost;
    bool operator<(const Pqitem& o) const {
      return cost > o.cost;
    }
  };
  int minTime(vector <string> m, int startRow, int startCol, int endRow, int endCol) {
    startRow--; startCol--; endRow--; endCol--;
    if (m[startRow][startCol] == '1') return -1;
    vector<vector<bool> > seen(m.size(),vector<bool>(m[0].size(),false));
    priority_queue<Pqitem> q;
    q.push((Pqitem){startRow,startCol,2521+2520/(m[startRow][startCol]-'0')});
    while (!q.empty()) {
      Pqitem p = q.top();
      q.pop();
      if (seen[p.i][p.j]) continue;
      if (p.i == endRow && p.j == endCol) return p.cost/2521;
      seen[p.i][p.j] = true;
      for (int k=0;k<4;k++) {
        int ni = p.i+dx[k];
        int nj = p.j+dy[k];
        if (ni >= 0 && ni < m.size() && nj >= 0 && nj < m[0].size() &&
            m[ni][nj] != '1' && !seen[ni][nj]) {
          int newcost = p.cost + 2520/(m[ni][nj]-'0');
          if (newcost/2521 > p.cost/2521)
            newcost = (newcost/2521)*2521+
                 2520/(m[ni][nj]-'0') + 
                 2520/(m[p.i][p.j]-'0');
          q.push((Pqitem){ni,nj,newcost});
        }
      }
    }
    return -1;
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
			case 6:
			{
				string m[] = {"22222222222222222222222222222222222222222222222222", "11111111111111111111111111111111111111111111111112", "22222222222222222222222222222222222212222212222222", "21111111111111111111111111111111111212111212111111", "21222122212222222222222212222222221212221212122222", "21212121212121111111111212111111121211121212121112", "21212221222122122212221212122222221222121212121222", "21211111111111121212121212121111111122221212121211", "21222222222222221222121212122222222211111212121222", "21111111111111111111121212111111111212222212121112", "22222222222222222222221222122222221212111112221222", "11111111111111111111111111121111121212111111111211", "22222222222222222222222222122222122212122222221222", "21111111111111111111111112111112111112121111121112", "21222122222222222222222212222212222212122222122222", "21212121111111111111111211111211111212111112111111", "21212121222222222222221222221222221212222212222222", "21212121211111111111111111121111121211111211111112", "21212121222222222222222222122222121212221222222212", "21212121211111111111111112111112121212122111111212", "21212121112222222222222222222212121212112222221212", "21212121122111111111111111111112121222111111121212", "21212121221222222222222222222222122111222222121212", "21212121211211111111111111111111112191211112121212", "21212121212212222222222222222222222991222212121212", "21212121212122111111111111111111111111111212121212", "21212121212121222222222222222222222222221212121212", "21212121212121211111111111111111111111121212121212", "21212121212121212221222112221222222222121212121212", "21212121212121212121212122121211111112121212121212", "21212121212121212122212221122212222212121212121212", "21212121212121212111111111111112111212121212121212", "21212121212121212222222222221222191222121212121212", "21212121212121211111111111121211191111121212121212", "21212121212121222222222222221222222112221212121212", "21212121212122111111111111111111112122111212121212", "21212121212212222222222222222222212121222212121212", "21212121211221111111111111111111212121211112121212", "21212121222122222222222222222221212121212222121212", "21212121112111111111111111111121212121212111121212", "21212121222212221222122212222121212121212222221212", "21212121121222122212221222112121212121221111111212", "21212121111111111111111111122121212122122212221212", "21212122222222222222222222221121212112211212121212", "21212111111111111111111111112221212211221212121212", "21212122222222222222222222222111221222121212121212", "21212121111111111111111111111222122112121212121212", "21212122222222222222222222222212112212121212122212", "21212111111111111111111111111112121212122212111112", "22212222222222222222222222222222221222111112222222"};
				int startRow = 1;
				int startCol = 1;
				int endRow = 17;
				int endCol = 22;
				_expected = 1283;
				_received = _obj.minTime(vector <string>(m, m+sizeof(m)/sizeof(string)), startRow, startCol, endRow, endCol); break;
			}
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
