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

class MicroStrings {
 public:
  string makeMicroString(int A, int D) {
    stringstream r;
    for (int i=A;i>=0;i-=D)
      r << i;
    return r.str();
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
		cout << "Testing MicroStrings (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1423601827;
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
		MicroStrings _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 12;
				int D = 5;
				_expected = "1272";
				_received = _obj.makeMicroString(A, D); break;
			}
			case 1:
			{
				int A = 3;
				int D = 2;
				_expected = "31";
				_received = _obj.makeMicroString(A, D); break;
			}
			case 2:
			{
				int A = 31;
				int D = 40;
				_expected = "31";
				_received = _obj.makeMicroString(A, D); break;
			}
			case 3:
			{
				int A = 30;
				int D = 6;
				_expected = "3024181260";
				_received = _obj.makeMicroString(A, D); break;
			}
			/*case 4:
			{
				int A = ;
				int D = ;
				_expected = ;
				_received = _obj.makeMicroString(A, D); break;
			}*/
			/*case 5:
			{
				int A = ;
				int D = ;
				_expected = ;
				_received = _obj.makeMicroString(A, D); break;
			}*/
			/*case 6:
			{
				int A = ;
				int D = ;
				_expected = ;
				_received = _obj.makeMicroString(A, D); break;
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
