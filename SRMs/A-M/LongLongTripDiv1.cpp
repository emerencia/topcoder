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

class LongLongTripDiv1 {
 public:
  string isAble(int N, vector <int> A, vector <int> B, vector <int> D, long long T) {
    // at least calculate the shortest path and see if it is not shorter than that
    vector<vector<int> > g(N,vector<int>(N,0));
    for (int i=0;i<A.size();i++) {
      g[A[i]][B[i]] = D[i];
      g[B[i]][A[i]] = D[i];
    }
    // floyd-warshall
    for (int k=0;k<N;k++)
      for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
          if (g[i][k] && g[k][j] && (!g[i][j] || g[i][k]+g[k][j] < g[i][j]))
            g[i][j] = g[i][k]+g[k][j];
    if (g[0][N-1] == 0 || g[0][N-1] > T)
      return "Impossible";
    return "lol";
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
		cout << "Testing LongLongTripDiv1 (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1426879783;
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
		LongLongTripDiv1 _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int A[] = {0,0,1};
				int B[] = {2,1,2};
				int D[] = {7,6,5};
				long long T = 11LL;
				_expected = "Possible";
				_received = _obj.isAble(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int)), T); break;
			}
			case 1:
			{
				int N = 3;
				int A[] = {0,0,1};
				int B[] = {2,1,2};
				int D[] = {7,6,5};
				long long T = 25LL;
				_expected = "Possible";
				_received = _obj.isAble(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int)), T); break;
			}
			case 2:
			{
				int N = 2;
				int A[] = {0};
				int B[] = {1};
				int D[] = {1};
				long long T = 9LL;
				_expected = "Possible";
				_received = _obj.isAble(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int)), T); break;
			}
			case 3:
			{
				int N = 2;
				int A[] = {1};
				int B[] = {0};
				int D[] = {1};
				long long T = 1000000000000000000LL;
				_expected = "Impossible";
				_received = _obj.isAble(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int)), T); break;
			}
			case 4:
			{
				int N = 4;
				int A[] = {0,0,1};
				int B[] = {2,1,2};
				int D[] = {10,10,10};
				long long T = 1000LL;
				_expected = "Impossible";
				_received = _obj.isAble(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int)), T); break;
			}
			case 5:
			{
				int N = 9;
				int A[] = {4,8,5,8,3,6,2,6,7,6,6};
				int B[] = {2,7,1,5,1,3,1,1,5,4,2};
				int D[] = {6580,8822,1968,673,1394,9337,5486,1746,5229,4092,195};
				long long T = 937186357646035002LL;
				_expected = "Impossible";
				_received = _obj.isAble(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int)), T); break;
			}
			/*case 6:
			{
				int N = ;
				int A[] = ;
				int B[] = ;
				int D[] = ;
				long long T = LL;
				_expected = ;
				_received = _obj.isAble(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int)), T); break;
			}*/
			/*case 7:
			{
				int N = ;
				int A[] = ;
				int B[] = ;
				int D[] = ;
				long long T = LL;
				_expected = ;
				_received = _obj.isAble(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int)), T); break;
			}*/
			/*case 8:
			{
				int N = ;
				int A[] = ;
				int B[] = ;
				int D[] = ;
				long long T = LL;
				_expected = ;
				_received = _obj.isAble(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int)), T); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
