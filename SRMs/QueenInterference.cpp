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

class QueenInterference {
 public:
  LL a;
  int random(int up) {
    return (randg()%up)+1;
  }
  int randg() {
    if (!a) return a = 1;
    return a = (16807*a)%2147483647;
  }
  bool reachable(int c1, int r1, int c2, int r2) {
    return r1 == r2 || abs(r1-r2) == abs(c1-c2);
  }
  vector<int> reachablequeencolumns(const vector<int>& board) {
    set<int> r;
    for (int i=0;i<board.size();i++)
      for (int k=i+1;k<board.size();k++)
        if (reachable(i,board[i],k,board[k])) {
          r.insert(i);
          r.insert(k);
        }
    vector<int> r2(r.begin(),r.end());
    return r2;
  }
  void alterationstep(vector<int>& board, int col) {
    vector<PII> otherqueens;
    for (int row=0;row<board.size();row++) {
      int reachcount = 0;
      for (int i=0;i<board.size();i++) {
        if (i == col) continue;
        reachcount+=reachable(col,row,i,board[i]);
      }
      otherqueens.push_back(PII(reachcount,row));
    }
    sort(otherqueens.begin(),otherqueens.end());
    int samecount = 1;
    for (int i=1;i<otherqueens.size();i++)
      if (otherqueens[i].first == otherqueens[0].first)
        ++samecount;
      else break;
    int torow = otherqueens[0].second;
    if (samecount != 1) {
      int p = random(samecount)-1;
      torow = otherqueens[p].second;
    }
    board[col] = torow;
  }
  int numSteps(int n) {
    a = 0;
    vector<int> board;
    for (int i=0;i<n;i++) {
      board.push_back(random(n)-1);
    }
    vector<int> rc = reachablequeencolumns(board);
    int r = 0;
    while (rc.size()) {
      ++r;
      int col = rc[random(rc.size())-1];
      alterationstep(board,col);
      rc = reachablequeencolumns(board);
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
		cout << "Testing QueenInterference (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397830668;
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
		QueenInterference _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 5;
				_expected = 4;
				_received = _obj.numSteps(n); break;
			}
			case 1:
			{
				int n = 7;
				_expected = 6;
				_received = _obj.numSteps(n); break;
			}
			case 2:
			{
				int n = 19;
				_expected = 475;
				_received = _obj.numSteps(n); break;
			}
			/*case 3:
			{
				int n = ;
				_expected = ;
				_received = _obj.numSteps(n); break;
			}*/
			/*case 4:
			{
				int n = ;
				_expected = ;
				_received = _obj.numSteps(n); break;
			}*/
			/*case 5:
			{
				int n = ;
				_expected = ;
				_received = _obj.numSteps(n); break;
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
