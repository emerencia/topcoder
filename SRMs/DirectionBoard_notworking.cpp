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
const int tt = 4;
// 
// END CUT HERE
int g[16][16];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

class DirectionBoard {
 public:
  int getMinimum(vector <string> board) {
    for (int i=0;i<board.size();i++)
      for (int j=0;j<board[0].size();j++) {
        if (board[i][j] == 'R') g[i][j] = 2;
        if (board[i][j] == 'D') g[i][j] = 3;
        if (board[i][j] == 'L') g[i][j] = 0;
        if (board[i][j] == 'U') g[i][j] = 1;
      }
    vector<vector<int> > inc(board.size(),vector<int>(board[0].size(),0));
    int r = 0;
    for (int i=0;i<board.size();i++)
      for (int j=0;j<board[0].size();j++) {
        int incoming = 0;
        for (int k=0;k<4;k++) {
          int ni = (i+dx[k]+board.size())%board.size();
          int nj = (j+dy[k]+board[0].size())%board[0].size();
          if (g[ni][nj] == k) {
            //cout << ni << " " << nj << " points to " << i << " " << j << endl;
            incoming++;
          }
        }
        inc[i][j] = incoming;
        if (!incoming) r+=2;
    }
    
    cout << endl;
    for (int i=0;i<board.size();i++) {
      for (int j=0;j<board[0].size();j++)
        cout << inc[i][j] << " ";
      cout << endl;
    }
    cout << endl;    
    
    for (int i=0;i<board.size();i++)
      for (int j=0;j<board[0].size();j++) {
        if (inc[i][j] != 0) continue;
        bool seen0 = false;
        for (int k=0;k<4;k++) {
          int ni = (i-dx[k]+board.size())%board.size();
          int nj = (j-dy[k]+board[0].size())%board[0].size();
          if (inc[ni][nj] == 0) seen0 = true;
          if (inc[ni][nj] >= 2 && g[i][j] == k) seen2 = true;
        }
    for (int i=0;i<board.size();i++)
      for (int j=0;j<board[0].size();j++) {
        if (inc[i][j] == 0) continue;
        bool seen2 = false;
        bool seen0 = false;
        for (int k=0;k<4;k++) {
          int ni = (i-dx[k]+board.size())%board.size();
          int nj = (j-dy[k]+board[0].size())%board[0].size();
          if (inc[ni][nj] == 0) seen0 = true;
          if (inc[ni][nj] >= 2 && g[i][j] == k) seen2 = true;
        }
        if (seen2 && seen0) {
          cout << i << " " << j << " " << g[i][j] << endl;
          r--;
          for (int k=0;k<4;k++) {
            int ni = (i-dx[k]+board.size())%board.size();
            int nj = (j-dy[k]+board[0].size())%board[0].size();
            if (seen0 && inc[ni][nj] == 0) { seen0 = false; inc[ni][nj] = 1; }
            if (seen2 && inc[ni][nj] >= 2 && g[i][j] == k) { seen2 = false; inc[ni][nj]--; }
          }
        }
      }
    
    
    cout << endl;
    for (int i=0;i<board.size();i++) {
      for (int j=0;j<board[0].size();j++)
        cout << inc[i][j] << " ";
      cout << endl;
    }
    cout << endl;  
    
    
    /*
    for (int i=0;i<board.size();i++)
      for (int j=0;j<board[0].size();j++) {
        if (inc[i][j]) continue;
        bool seen0 = false;
        int ni = i;
        int nj = j;
        for (int k=0;k<4;k++) {
          ni = (i+dx[k])%board.size();
          nj = (j+dy[k])%board[0].size();
          if (inc[ni][nj] == 0) { seen0 = true; break; }
        }
        if (seen0) {
          inc[ni][nj] = 1;
          inc[i][j] = 1;
        }
      }
    */

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
		cout << "Testing DirectionBoard (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396732089;
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
		DirectionBoard _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"RRRD",
				                  "URDD",
				                  "UULD",
				                  "ULLL"};
				_expected = 0;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"RRRD",
				                  "URLL",
				                  "LRRR"};
				_expected = 2;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"RRD",
				                  "URD",
				                  "ULL"};
				_expected = 2;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"ULRLRD",
				                  "UDDLRR"};
				_expected = 4;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"UDLRLDLD",
				                  "DLDLLDLR",
				                  "LLLLLDLD",
				                  "UUURRRDD"};
				_expected = 9;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {"UDUDUUDUDUDUDUR",
				                  "LLLLDUUDRDLUDRU",
				                  "DLLDLDURDURUDDL",
				                  "UDUDUUDUDUDUDUR",
				                  "LLLLDUUDRDLUDRU",
				                  "DLLDLDURDURUDDL",
				                  "UDUDUUDUDUDUDUR",
				                  "LLLLDUUUDDLUDRU",
				                  "DLLDLDURDURUDDL",
				                  "UDUDUUDUDUDUDUR",
				                  "LLLLDUUDRDLUDRU",
				                  "DLLDLDURDURUDDL",
				                  "UDUDUUDUDUDUDUR",
				                  "LLLLDUUDRDLUDRU",
				                  "RRRDLDURDURUDDR"};
				_expected = 73;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 6:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
