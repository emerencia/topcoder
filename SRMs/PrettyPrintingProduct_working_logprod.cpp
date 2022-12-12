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
const LL kMod = 1e12;

class PrettyPrintingProduct {
 public:
  string prettyPrint(int A, int B) {
    // last part of expression
    LL product = 1;
    int twos = 0;
    int fives = 0;
    for (int i=A;i<=B;i++) {
      int cur = i;
      while (cur%2 == 0) {
        cur /= 2;
        twos++;
      }
      while (cur%5 == 0) {
        cur /= 5;
        fives++;
      }
      (product *= cur)%=kMod;
    }
    int tens = min(twos,fives);
    for (int i=0;i<twos-tens;i++) {
      (product *= 2)%=kMod;
    }
    for (int i=0;i<fives-tens;i++) {
      (product *= 5)%=kMod;
    }
    double logproduct = 0;
    for (int i=A;i<=B;i++)
      logproduct += log10(i);
    int nrdigitsd = floor(logproduct)+1-tens;
    if (nrdigitsd > 10) {
      stringstream s;
      s << (LL)pow(10,logproduct-floor(logproduct)+4);
      s << "..." << setfill('0') << setw(5) << product%100000 << " * 10^" << tens;
      return s.str();
    } else {
      stringstream s;
      s << product << " * 10^" << tens;
      return s.str();
    }
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
		cout << "Testing PrettyPrintingProduct (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392215762;
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
		PrettyPrintingProduct _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 1;
				int B = 10;
				_expected = "36288 * 10^2";
				_received = _obj.prettyPrint(A, B); break;
			}
			case 1:
			{
				int A = 7;
				int B = 7;
				_expected = "7 * 10^0";
				_received = _obj.prettyPrint(A, B); break;
			}
			case 2:
			{
				int A = 211;
				int B = 214;
				_expected = "2038974024 * 10^0";
				_received = _obj.prettyPrint(A, B); break;
			}
			case 3:
			{
				int A = 411;
				int B = 414;
				_expected = "28952...24024 * 10^0";
				_received = _obj.prettyPrint(A, B); break;
			}
			case 4:
			{
				int A = 412;
				int B = 415;
				_expected = "2923450236 * 10^1";
				_received = _obj.prettyPrint(A, B); break;
			}
			case 5:
			{
				int A = 47;
				int B = 4700;
				_expected = "14806...28928 * 10^1163";
				_received = _obj.prettyPrint(A, B); break;
			}
			case 6:
			{
				int A = 1;
				int B = 19;
				_expected = "12164...08832 * 10^3";
				_received = _obj.prettyPrint(A, B); break;
			}
			case 7:
			{
				int A = 13;
				int B = 25;
				_expected = "32382...26624 * 10^4";
				_received = _obj.prettyPrint(A, B); break;
			}
			/*case 8:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.prettyPrint(A, B); break;
			}*/
			/*case 9:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.prettyPrint(A, B); break;
			}*/
			/*case 10:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.prettyPrint(A, B); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
