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

class ArithmeticProgression {
 public:
  double minCommonDifference(int a0, vector <int> seq) {
    if (!seq.size()) return 0;
    double mn = 1e7;
    for (int i=0;i<seq.size();i++) {
      double fc = double(seq[i]-a0)/(i+1);
      if (fc >= mn || fc < 0) continue;
      bool good = true;
      for (int j=0;j<seq.size();j++)
        if (floor(a0+fc*(j+1)) != seq[j]) {
          good = false;
          break;
        }
      if (good)
        mn = fc;
    }
    return (mn == 1e7 ? -1 : mn);
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
		cout << "Testing ArithmeticProgression (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390320793;
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
		ArithmeticProgression _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a0 = 0;
				int seq[] = {6, 13, 20, 27};
				_expected = 6.75;
				_received = _obj.minCommonDifference(a0, vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 1:
			{
				int a0 = 1;
				int seq[] = {2, 3, 4, 5, 6};
				_expected = 1.0;
				_received = _obj.minCommonDifference(a0, vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 2:
			{
				int a0 = 3;
				int seq[] = {};
				_expected = 0.0;
				_received = _obj.minCommonDifference(a0, vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 3:
			{
				int a0 = 3;
				int seq[] = {3, 3, 3, 3, 4};
				_expected = 0.2;
				_received = _obj.minCommonDifference(a0, vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 4:
			{
				int a0 = 1;
				int seq[] = {-3};
				_expected = -1.0;
				_received = _obj.minCommonDifference(a0, vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 5:
			{
				int a0 = 0;
				int seq[] = {6, 14};
				_expected = -1.0;
				_received = _obj.minCommonDifference(a0, vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			/*case 6:
			{
				int a0 = ;
				int seq[] = ;
				_expected = ;
				_received = _obj.minCommonDifference(a0, vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int a0 = ;
				int seq[] = ;
				_expected = ;
				_received = _obj.minCommonDifference(a0, vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int a0 = ;
				int seq[] = ;
				_expected = ;
				_received = _obj.minCommonDifference(a0, vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
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
