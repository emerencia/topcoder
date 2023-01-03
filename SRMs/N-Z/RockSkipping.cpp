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

class RockSkipping {
 public:
  double probability(string pads, int maxDist) {
    vector<double> p(10001,0);
    p[0] = 100;
    for (int i=0;i<maxDist;i++) {
      vector<double> t(10001,0);
      for (int j=0;j<10001;j++) {
        double fac = p[j]/(maxDist-i);
        for (int k=1;k<=maxDist-i && k+j < 10001;k++)
          if (pads[(k+j)%pads.size()] != 'X')
            t[k+j]+=fac;
      }
      swap(t,p);
    }
    double r = 0;
    for (int i=0;i<10001;i++)
      r+=p[i];
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
		cout << "Testing RockSkipping (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397733236;
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
		RockSkipping _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string pads = ".";
				int maxDist = 100;
				_expected = 100.0;
				_received = _obj.probability(pads, maxDist); break;
			}
			case 1:
			{
				string pads = "...X";
				int maxDist = 2;
				_expected = 50.0;
				_received = _obj.probability(pads, maxDist); break;
			}
			case 2:
			{
				string pads = "........................X";
				int maxDist = 50;
				_expected = 11.60725450562586;
				_received = _obj.probability(pads, maxDist); break;
			}
			case 3:
			{
				string pads = "...X......XXXX...XX.X..X...XX...";
				int maxDist = 48;
				_expected = 5.408479511004734E-8;
				_received = _obj.probability(pads, maxDist); break;
			}
			/*case 4:
			{
				string pads = ;
				int maxDist = ;
				_expected = ;
				_received = _obj.probability(pads, maxDist); break;
			}*/
			/*case 5:
			{
				string pads = ;
				int maxDist = ;
				_expected = ;
				_received = _obj.probability(pads, maxDist); break;
			}*/
			/*case 6:
			{
				string pads = ;
				int maxDist = ;
				_expected = ;
				_received = _obj.probability(pads, maxDist); break;
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
