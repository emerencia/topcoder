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

class Archery {
 public:
  double expectedPoints(int N, vector <int> ringPoints) {
    double r = N;
    r = 0;
    double tot = 0;
    for (int i=0;i<ringPoints.size();i++) {
      double area = M_PI*(i+1)*(i+1) - (i == 0 ? 0 : M_PI*i*i);
      r+= ringPoints[i]*area;
      tot += area;
    }
    return r/tot;
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
		cout << "Testing Archery (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1401135454;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Archery _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 1;
				int ringPoints[] = {10, 0};
				_expected = 2.5;
				_received = _obj.expectedPoints(N, vector <int>(ringPoints, ringPoints+sizeof(ringPoints)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 3;
				int ringPoints[] = {1, 1, 1, 1};
				_expected = 1.0;
				_received = _obj.expectedPoints(N, vector <int>(ringPoints, ringPoints+sizeof(ringPoints)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 4;
				int ringPoints[] = {100, 0, 100, 0, 100};
				_expected = 60.0;
				_received = _obj.expectedPoints(N, vector <int>(ringPoints, ringPoints+sizeof(ringPoints)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 9;
				int ringPoints[] = {69, 50, 79, 16, 52, 71, 17, 96, 56, 32};
				_expected = 51.96;
				_received = _obj.expectedPoints(N, vector <int>(ringPoints, ringPoints+sizeof(ringPoints)/sizeof(int))); break;
			}
			/*case 4:
			{
				int N = ;
				int ringPoints[] = ;
				_expected = ;
				_received = _obj.expectedPoints(N, vector <int>(ringPoints, ringPoints+sizeof(ringPoints)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int N = ;
				int ringPoints[] = ;
				_expected = ;
				_received = _obj.expectedPoints(N, vector <int>(ringPoints, ringPoints+sizeof(ringPoints)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int N = ;
				int ringPoints[] = ;
				_expected = ;
				_received = _obj.expectedPoints(N, vector <int>(ringPoints, ringPoints+sizeof(ringPoints)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(3);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
