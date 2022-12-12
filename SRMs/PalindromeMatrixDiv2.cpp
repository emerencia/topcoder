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

class PalindromeMatrixDiv2 {
 public:
  int bitcount(int n) {
    int r = 0;
    for (int i=n;i;i&=i-1) ++r;
    return r;
  }
  int minChange(vector <string> A, int rowCount, int columnCount) {
    if (rowCount == 0 && columnCount == 0) return 0;
    int N = A.size();
    int M = A[0].size();
    int mn = INT_MAX;
    for (int i=0;i<(1<<N);i++) {
      if (bitcount(i) != rowCount) continue;
      for (int j=0;j<(1<<M);j++) {
        if (bitcount(j) != columnCount) continue;
        int tmn = 0;
        for (int k=0;k<N/2;k++) {
          for (int l=0;l<M/2;l++) {
            if (!((i>>k)&1) && !((i>>(N-k-1))&1) && !((j>>l)&1) && !((j>>(M-l-1))&1)) continue;
            if (!((j>>l)&1) && !((j>>(M-l-1))&1)) {
              if ((i>>k)&1) tmn+=A[k][l] != A[k][M-l-1];
              if ((i>>(N-k-1))&1) tmn+=A[N-k-1][l] != A[N-k-1][M-l-1];
              continue;
            }
            if (!((i>>k)&1) && !((i>>(N-k-1))&1)) {
              if ((j>>l)&1) tmn+=A[k][l] != A[N-k-1][l];
              if ((j>>(M-l-1))&1) tmn+=A[k][M-l-1] != A[N-k-1][M-l-1];
              continue;
            }
            if (((j&(1<<l)) && (j&(1<<(M-l-1)))) ||
                ((i&(1<<k)) && (i&(1<<(N-k-1))))) {             
              int zc = (A[k][l] == '0')+
                       (A[N-k-1][l] == '0')+
                       (A[k][M-l-1] == '0')+
                       (A[N-k-1][M-l-1] == '0');
              tmn += min(zc,4-zc);
            } else {
              int zc = 0;
              if ((i&(1<<k)) || (j&(1<<l))) zc+= (A[k][l] == '0');
              if ((i&(1<<k)) || (j&(1<<(M-l-1)))) zc+= (A[k][M-l-1] == '0');
              if ((i&(1<<(N-k-1))) || (j&(1<<l))) zc+= (A[N-k-1][l] == '0');
              if ((i&(1<<(N-k-1))) || (j&(1<<(M-l-1)))) zc+= (A[N-k-1][M-l-1] == '0');
              tmn += min(zc,3-zc);
            }
          }
        }
        mn = min(mn,tmn);
      }
    }
    return mn;
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
			case 5:
			{
				string A[] = {"0101"
				             ,"0101"
                     ,"0101"
                     ,"0101"};
				int rowCount = 2;
				int columnCount = 2;
				_expected = 4;
				_received = _obj.minChange(vector <string>(A, A+sizeof(A)/sizeof(string)), rowCount, columnCount); break;
			}
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
