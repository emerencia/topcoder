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
// done at 55 min 22 sec
// END CUT HERE

int mem[1<<14][9][15];
class PalindromeMatrix {
 public:
  int N;
  int M;
  int rc;
  vector<string> A;
  int bitcount(int n) {
    int r = 0;
    for (int i=n;i;i&=i-1) ++r;
    return r;
  }
  int rec(int mask,int idx, int rleft) {
    int& r = mem[mask][idx][rleft];
    if (r != -1) return r;
    if (idx == N/2) {
      if (rleft) return r = 100000;
      return r = 0;
    }
    int t = 100000;
    vector<int> c(4,0);
    for (int i=0;i<M/2;i++) {
      { // none at all
        if (mask&(1<<i)) {
          c[0]+=A[N-idx-1][i] != A[idx][i];
        }
        if (mask&(1<<(M-i-1))) {
          c[0]+=A[N-idx-1][M-i-1] != A[idx][M-i-1];
        }
      }
      { // only top one
        int cb = (A[idx][i] == '0')+(A[idx][M-i-1] == '0');
        int tc = 2;
        if (mask&(1<<i)) {
          tc++;
          cb+=(A[N-idx-1][i] == '0');
        }
        if (mask&(1<<(M-i-1))) {
          tc++;
          cb+=(A[N-idx-1][M-i-1] == '0');
        }
        c[1]+=min(cb,tc-cb);
      }
      { // only bottom one
        int cb = (A[N-idx-1][i] == '0')+(A[N-idx-1][M-i-1] == '0');
        int tc = 2;
        if (mask&(1<<i)) {
          tc++;
          cb+=(A[idx][i] == '0');
        }
        if (mask&(1<<(M-i-1))) {
          tc++;
          cb+=(A[idx][M-i-1] == '0');
        }
        c[2]+=min(cb,tc-cb);
      }
      { // both
        if (mask&(1<<i) || mask&(1<<(M-i-1))) { // parentheses needed? probably not
          // all need to be the same
          int cb=(A[idx][i] == '0')+
             (A[N-idx-1][i] == '0')+
             (A[idx][M-i-1] == '0')+
             (A[N-idx-1][M-i-1] == '0');
          c[3]+=min(cb,4-cb);
        } else {
          // the rows can be different
          c[3]+=(A[idx][i] != A[idx][M-i-1])+
                (A[N-idx-1][i] != A[N-idx-1][M-i-1]);
        }
      }
    }
    t = min(t,c[0]+rec(mask,idx+1,rleft));
    if (rleft) {
      t = min(t,c[1]+rec(mask,idx+1,rleft-1));
      t = min(t,c[2]+rec(mask,idx+1,rleft-1));
    }
    if (rleft > 1) {
      t = min(t,c[3]+rec(mask,idx+1,rleft-2));
    }
    return r = t;
  }
  int minChange(vector <string> A, int rowCount, int columnCount) {
    if (rowCount == 0 && columnCount == 0) return 0;
    memset(mem,-1,sizeof(mem));
    this->A = A;
    N = A.size();
    M = A[0].size();
    int mn = INT_MAX;
    for (int i=0;i<(1<<M);i++) {
      if (bitcount(i) != columnCount) continue;
      mn = min(mn,rec(i,0,rowCount));
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
		cout << "Testing PalindromeMatrix (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390929089;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PalindromeMatrix _obj;
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
				int columnCount = 3;
				_expected = 8;
				_received = _obj.minChange(vector <string>(A, A+sizeof(A)/sizeof(string)), rowCount, columnCount); break;
			}
			case 5:
			{
				string A[] = {"000000000000"
				             ,"011101110111"
				             ,"010001010101"
				             ,"010001010101"
				             ,"011101010101"
				             ,"010101010101"
				             ,"010101010101"
				             ,"011101110111"
				             ,"000000000000"
				             ,"000000000000"};
				int rowCount = 5;
				int columnCount = 9;
				_expected = 14;
				_received = _obj.minChange(vector <string>(A, A+sizeof(A)/sizeof(string)), rowCount, columnCount); break;
			}
			case 6:
			{
				string A[] = {"11111101001110"
				             ,"11000111111111"
				             ,"00010101111001"
				             ,"10110000111111"
				             ,"10000011010010"
				             ,"10001101101101"
				             ,"00101010000001"
				             ,"10111010100100"
				             ,"11010011110111"
				             ,"11100010110110"
				             ,"00100101010100"
				             ,"01001011001000"
				             ,"01010001111010"
				             ,"10100000010011"};
				int rowCount = 6;
				int columnCount = 8;
				_expected = 31;
				_received = _obj.minChange(vector <string>(A, A+sizeof(A)/sizeof(string)), rowCount, columnCount); break;
			}
			/*case 7:
			{
				string A[] = ;
				int rowCount = ;
				int columnCount = ;
				_expected = ;
				_received = _obj.minChange(vector <string>(A, A+sizeof(A)/sizeof(string)), rowCount, columnCount); break;
			}*/
			/*case 8:
			{
				string A[] = ;
				int rowCount = ;
				int columnCount = ;
				_expected = ;
				_received = _obj.minChange(vector <string>(A, A+sizeof(A)/sizeof(string)), rowCount, columnCount); break;
			}*/
			/*case 9:
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
