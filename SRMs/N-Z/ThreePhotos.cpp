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
int cube[51][51][51];

class ThreePhotos {
 public:
  int removeCubes(vector <string> A, vector <string> B, vector <string> C) {
    int N = A.size();
    memset(cube,1,sizeof(cube));
    int removed = 0;
    for (int x=0;x<N;x++)
      for (int y=0;y<N;y++)
         for (int z=0;z<N;z++)
           if (A[x][y] == 'N' || B[x][z] == 'N' || C[y][z] == 'N') {
             removed++;
             cube[x][y][z] = 0;
           }
    for (int x=0;x<N;x++)
      for (int z=0;z<N;z++)
        if (B[x][z] == 'Y') {
          bool good = false;
          for (int y=0;y<N;y++)
            if (cube[x][y][z]) {
              good = true;
              break;
            }
          if (!good) return -1;
        }
    for (int y=0;y<N;y++)
      for (int z=0;z<N;z++)
        if (C[y][z] == 'Y') {
          bool good = false;
          for (int x=0;x<N;x++)
            if (cube[x][y][z]) {
              good = true;
              break;
            }
          if (!good) return -1;
        }
    for (int x=0;x<N;x++)
      for (int y=0;y<N;y++)
        if (A[x][y] == 'Y') {
          bool good = false;
          for (int z=0;z<N;z++)
            if (cube[x][y][z]) {
              good = true;
              break;
            }
          if (!good) return -1;
        }
    return removed;
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
		cout << "Testing ThreePhotos (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390401534;
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
		ThreePhotos _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string A[] = {"YY","YY"};
				string B[] = {"YY","YY"};
				string C[] = {"YY","YY"};
				_expected = 0;
				_received = _obj.removeCubes(vector <string>(A, A+sizeof(A)/sizeof(string)), vector <string>(B, B+sizeof(B)/sizeof(string)), vector <string>(C, C+sizeof(C)/sizeof(string))); break;
			}
			case 1:
			{
				string A[] = {"NNN","NNN","NNN"};
				string B[] = {"NNN","NNN","NNN"};
				string C[] = {"NNN","NNN","NNN"};
				_expected = 27;
				_received = _obj.removeCubes(vector <string>(A, A+sizeof(A)/sizeof(string)), vector <string>(B, B+sizeof(B)/sizeof(string)), vector <string>(C, C+sizeof(C)/sizeof(string))); break;
			}
			case 2:
			{
				string A[] = {"NNNNN","NNNNN","NNNNN","YYNNN","NNNNN"};
				string B[] = {"NNNNN","NNNNN","NNNNN","NNYNY","NNNNN"};
				string C[] = {"NNYNN","NNNNY","NNNNN","NNNNN","NNNNN"};
				_expected = 123;
				_received = _obj.removeCubes(vector <string>(A, A+sizeof(A)/sizeof(string)), vector <string>(B, B+sizeof(B)/sizeof(string)), vector <string>(C, C+sizeof(C)/sizeof(string))); break;
			}
			case 3:
			{
				string A[] = {"YY","YY"};
				string B[] = {"YY","YY"};
				string C[] = {"YN","YN"};
				_expected = -1;
				_received = _obj.removeCubes(vector <string>(A, A+sizeof(A)/sizeof(string)), vector <string>(B, B+sizeof(B)/sizeof(string)), vector <string>(C, C+sizeof(C)/sizeof(string))); break;
			}
			/*case 4:
			{
				string A[] = ;
				string B[] = ;
				string C[] = ;
				_expected = ;
				_received = _obj.removeCubes(vector <string>(A, A+sizeof(A)/sizeof(string)), vector <string>(B, B+sizeof(B)/sizeof(string)), vector <string>(C, C+sizeof(C)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string A[] = ;
				string B[] = ;
				string C[] = ;
				_expected = ;
				_received = _obj.removeCubes(vector <string>(A, A+sizeof(A)/sizeof(string)), vector <string>(B, B+sizeof(B)/sizeof(string)), vector <string>(C, C+sizeof(C)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string A[] = ;
				string B[] = ;
				string C[] = ;
				_expected = ;
				_received = _obj.removeCubes(vector <string>(A, A+sizeof(A)/sizeof(string)), vector <string>(B, B+sizeof(B)/sizeof(string)), vector <string>(C, C+sizeof(C)/sizeof(string))); break;
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
