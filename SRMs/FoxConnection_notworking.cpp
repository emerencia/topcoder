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
int g[51][51];
int mem[52][52];

class FoxConnection {
 public:
  string haveFox;
  int N;
  int dfsfoxcount(int cur, int prev) {
    //int& r = mem[cur][prev];
    //if (r != -1) return r;
    int r = haveFox[cur] == 'Y';
    for (int i=0;i<N;i++)
      if (g[cur][i] && i != prev)
        r+=dfsfoxcount(i,cur);
    return r;
  }
  PII dfsdisttofurthestfox(int cur, int prev) {
    PII r((haveFox[cur] == 'Y' ? 0 : -1000000),cur);
    for (int i=0;i<N;i++)
      if (g[cur][i] && i != prev && dfsfoxcount(i,cur)) {
        PII p = dfsdisttofurthestfox(i,cur);
        r = max(r,PII(1+p.first,p.second));
      }
    return r;
  }
  int minimalDistance(vector <int> A, vector <int> B, string haveFox) {
    this->haveFox = haveFox;
    memset(g,0,sizeof(g));
    memset(mem,-1,sizeof(mem));
    N = A.size()+1;
    for (int i=0;i<A.size();i++) {
      g[A[i]-1][B[i]-1] = 1;
      g[B[i]-1][A[i]-1] = 1;
    }
    int r = 0;
    for (int i=0;i<N;i++) {
      if (haveFox[i] == 'Y') continue;
      PII mn = PII(INT_MAX,i);
      int brancheswithfoxes = 0;
      for (int j=0;j<N;j++) {
        if (!g[i][j]) continue;
        int foxcountbranch = dfsfoxcount(j,i);
        if (foxcountbranch) {
          brancheswithfoxes++;
          mn = min(mn,dfsdisttofurthestfox(j,i));
        }
      }
      if (brancheswithfoxes >= 2) {
        cout << i << " " << mn.second << " " << haveFox[mn.second] << endl;
        haveFox[mn.second] = 'N';
        haveFox[i] = 'Y';
        r += 1+mn.first;
        i = -1;
      }
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
		cout << "Testing FoxConnection (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396049948;
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
		FoxConnection _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {1,2,3};
				int B[] = {2,3,4};
				string haveFox = "YNNY";
				_expected = 2;
				_received = _obj.minimalDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), haveFox); break;
			}
			case 1:
			{
				int A[] = {1,1,1,1};
				int B[] = {2,3,4,5};
				string haveFox = "NYYYY";
				_expected = 1;
				_received = _obj.minimalDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), haveFox); break;
			}
			case 2:
			{
				int A[] = {1,3,4,5,4};
				int B[] = {2,2,2,4,6};
				string haveFox = "YNYNYY";
				_expected = 2;
				_received = _obj.minimalDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), haveFox); break;
			}
			case 3:
			{
				int A[] = {1,2,3,4,5,6,7,8,9};
				int B[] = {2,3,4,5,6,7,8,9,10};
				string haveFox = "YNNNYNYNNY";
				_expected = 7;
				_received = _obj.minimalDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), haveFox); break;
			}
			case 4:
			{
				int A[] = {1,2,3,4,3,6,8,7};
				int B[] = {2,3,4,5,6,8,9,6};
				string haveFox = "YNNYYNYYY";
				_expected = 3;
				_received = _obj.minimalDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), haveFox); break;
			}
			case 5:
			{
				int A[] = {1};
				int B[] = {2};
				string haveFox = "NY";
				_expected = 0;
				_received = _obj.minimalDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), haveFox); break;
			}
			case 6:
			{
				int A[] = {1};
				int B[] = {2};
				string haveFox = "NN";
				_expected = 0;
				_received = _obj.minimalDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), haveFox); break;
			}
			case 7:
			{
				int A[] = {7, 19, 4, 18, 5, 16, 3, 22, 15, 8, 10, 1, 2, 17, 12, 21, 9, 20, 13, 14, 6, 11};
				int B[] = {23, 7, 23, 23, 4, 19, 4, 18, 3, 16, 16, 10, 10, 15, 8, 1, 21, 17, 17, 13, 14, 14};
				string haveFox = "NYNYYNYNYNYNYYYYNNNYYYN";
				_expected = 12;
				_received = _obj.minimalDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), haveFox); break;
			}
			/*case 8:
			{
				int A[] = ;
				int B[] = ;
				string haveFox = ;
				_expected = ;
				_received = _obj.minimalDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), haveFox); break;
			}*/
			/*case 9:
			{
				int A[] = ;
				int B[] = ;
				string haveFox = ;
				_expected = ;
				_received = _obj.minimalDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), haveFox); break;
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
