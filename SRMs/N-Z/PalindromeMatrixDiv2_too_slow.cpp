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
typedef pair<vector<string>,PII> PVI;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE
map<PVI,int> mem;
map<vector<string>,bool> mem2;

class PalindromeMatrixDiv2 {
 public:
  int rc;
  int cc;
  bool isvalid(const vector<string>& A) {
    if (mem2.count(A)) return mem2[A];
    int rp = 0;
    for (int i=0;i<A.size();i++) {
      bool good = true;
      for (int j=0;j<A[0].size();j++)
        if (A[i][j] != A[i][A[0].size()-j-1]) {
          good = false;
          break;
        }
      if (good) ++rp;
    }
    int cp = 0;
    for (int i=0;i<A[0].size();i++) {
      bool good = true;
      for (int j=0;j<A.size();j++)
        if (A[j][i] != A[A.size()-j-1][i]) {
          good = false;
          break;
        }
      if (good) ++cp;
    }
    return mem2[A] = (rp >= rc && cp >= cc);
  }
  int rec(vector<string>& A, int ridx, int cidx) {
    if (mem.count(PVI(A,PII(ridx,cidx)))) return mem[PVI(A,PII(ridx,cidx))];
    if (ridx == A.size() && cidx == A[0].size()) {  
      if (isvalid(A))
        return mem[PVI(A,PII(ridx,cidx))] = 0;
      return mem[PVI(A,PII(ridx,cidx))] = 100000;
    }
    int nridx = ridx;
    int ncidx = cidx;
    if (cidx == A[0].size()-1) {
      nridx++;
      if (nridx == A.size())
        ncidx++;
      else
        ncidx = 0;
    } else {
      ncidx++;
    }
    int t = rec(A,nridx,ncidx);
    A[ridx][cidx] = (A[ridx][cidx] == '0' ? '1' : '0');
    t = min(t,1+rec(A,nridx,ncidx));
    A[ridx][cidx] = (A[ridx][cidx] == '0' ? '1' : '0');
    return mem[PVI(A,PII(ridx,cidx))] = t;
  }
  int minChange(vector <string> A, int rowCount, int columnCount) {
    this->rc = rowCount;
    this->cc = columnCount;
    mem.clear();
    mem2.clear();
    return rec(A,0,0);
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
		cout << "Testing PalindromeMatrixDiv2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390840894;
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
		PalindromeMatrixDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string A[] = {"0000"
				             ,"1000"
				             ,"1100"
				             ,"1110"};
				int rowCount = 2;
				int columnCount = 2;
				_expected = 1;
				_received = _obj.minChange(vector <string>(A, A+sizeof(A)/sizeof(string)), rowCount, columnCount); break;
			}
			case 1:
			{
				string A[] = {"0000"
				             ,"1000"
				             ,"1100"
				             ,"1110"};
				int rowCount = 3;
				int columnCount = 2;
				_expected = 3;
				_received = _obj.minChange(vector <string>(A, A+sizeof(A)/sizeof(string)), rowCount, columnCount); break;
			}
			case 2:
			{
				string A[] = {"01"
				             ,"10"};
				int rowCount = 1;
				int columnCount = 1;
				_expected = 1;
				_received = _obj.minChange(vector <string>(A, A+sizeof(A)/sizeof(string)), rowCount, columnCount); break;
			}
			case 3:
			{
				string A[] = {"1110"
				             ,"0001"};
				int rowCount = 0;
				int columnCount = 0;
				_expected = 0;
				_received = _obj.minChange(vector <string>(A, A+sizeof(A)/sizeof(string)), rowCount, columnCount); break;
			}
			case 4:
			{
				string A[] = {"01010101"
				             ,"01010101"
				             ,"01010101"
				             ,"01010101"
				             ,"01010101"
				             ,"01010101"
				             ,"01010101"
				             ,"01010101"};
				int rowCount = 2;
				int columnCount = 2;
				_expected = 8;
				_received = _obj.minChange(vector <string>(A, A+sizeof(A)/sizeof(string)), rowCount, columnCount); break;
			}
			/*case 5:
			{
				string A[] = ;
				int rowCount = ;
				int columnCount = ;
				_expected = ;
				_received = _obj.minChange(vector <string>(A, A+sizeof(A)/sizeof(string)), rowCount, columnCount); break;
			}*/
			/*case 6:
			{
				string A[] = ;
				int rowCount = ;
				int columnCount = ;
				_expected = ;
				_received = _obj.minChange(vector <string>(A, A+sizeof(A)/sizeof(string)), rowCount, columnCount); break;
			}*/
			/*case 7:
			{
				string A[] = ;
				int rowCount = ;
				int columnCount = ;
				_expected = ;
				_received = _obj.minChange(vector <string>(A, A+sizeof(A)/sizeof(string)), rowCount, columnCount); break;
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
