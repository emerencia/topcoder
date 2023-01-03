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

class WinningProbability {
 public:
  double probability(int prevWins, int prevLosses, int gamesLeft, int mustWin) {
    double r = 0;
    int c = 0;
    for (double i=0;i<=1;i+=0.01) {
      for (int j=mustWin;j<= gamesLeft;j++) {
        ++c;
        r += pow(i,prevWins)*pow(1-i,prevLosses)*pow(i,j)*pow(i,gamesLeft-j);
      }
    }
    r/=c;
    return 1-r;
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
		cout << "Testing WinningProbability (750.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1401736038;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 750.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		WinningProbability _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int prevWins = 2;
				int prevLosses = 0;
				int gamesLeft = 1;
				int mustWin = 1;
				_expected = 0.75;
				_received = _obj.probability(prevWins, prevLosses, gamesLeft, mustWin); break;
			}
			case 1:
			{
				int prevWins = 0;
				int prevLosses = 3;
				int gamesLeft = 4;
				int mustWin = 4;
				_expected = 0.0142857142857;
				_received = _obj.probability(prevWins, prevLosses, gamesLeft, mustWin); break;
			}
			case 2:
			{
				int prevWins = 20;
				int prevLosses = 3;
				int gamesLeft = 5;
				int mustWin = 1;
				_expected = 0.9995284409077;
				_received = _obj.probability(prevWins, prevLosses, gamesLeft, mustWin); break;
			}
			case 3:
			{
				int prevWins = 0;
				int prevLosses = 20;
				int gamesLeft = 1;
				int mustWin = 1;
				_expected = 0.0454545454545;
				_received = _obj.probability(prevWins, prevLosses, gamesLeft, mustWin); break;
			}
			case 4:
			{
				int prevWins = 0;
				int prevLosses = 0;
				int gamesLeft = 1;
				int mustWin = 1;
				_expected = 0.5;
				_received = _obj.probability(prevWins, prevLosses, gamesLeft, mustWin); break;
			}
			/*case 5:
			{
				int prevWins = ;
				int prevLosses = ;
				int gamesLeft = ;
				int mustWin = ;
				_expected = ;
				_received = _obj.probability(prevWins, prevLosses, gamesLeft, mustWin); break;
			}*/
			/*case 6:
			{
				int prevWins = ;
				int prevLosses = ;
				int gamesLeft = ;
				int mustWin = ;
				_expected = ;
				_received = _obj.probability(prevWins, prevLosses, gamesLeft, mustWin); break;
			}*/
			/*case 7:
			{
				int prevWins = ;
				int prevLosses = ;
				int gamesLeft = ;
				int mustWin = ;
				_expected = ;
				_received = _obj.probability(prevWins, prevLosses, gamesLeft, mustWin); break;
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
