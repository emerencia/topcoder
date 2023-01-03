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
bool seen[2400][2400];
double mem[2400][2400];

class Volleyball {
 public:
  double probWinServe;
  double rec(int totalscore, int sscore) {
    double& r = mem[totalscore][sscore];
    if (seen[totalscore][sscore]) return r;
    seen[totalscore][sscore] = 1;
    int rscore = totalscore-sscore;
    if (sscore >= 15 && sscore > rscore && sscore-rscore >= 2)
      return r = 1;
    if (rscore >= 15 && rscore > sscore && rscore-sscore >= 2)
      return r = 0;
    if (totalscore == 2399) return r = probWinServe;
    return r = probWinServe*rec(totalscore+1,sscore+1)+
               (1-probWinServe)*(1-rec(totalscore+1,rscore+1));
  }
  double win(int sScore, int rScore, double probWinServe) {
    this->probWinServe = probWinServe;
    memset(seen,0,sizeof(seen));
    return rec(sScore+rScore,sScore);
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
		cout << "Testing Volleyball (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397737604;
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
		Volleyball _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int sScore = 13;
				int rScore = 13;
				double probWinServe = .5;
				_expected = 0.5;
				_received = _obj.win(sScore, rScore, probWinServe); break;
			}
			case 1:
			{
				int sScore = 1;
				int rScore = 14;
				double probWinServe = 0.01;
				_expected = 3.355704697986578E-27;
				_received = _obj.win(sScore, rScore, probWinServe); break;
			}
			case 2:
			{
				int sScore = 8;
				int rScore = 12;
				double probWinServe = 0.4;
				_expected = 0.046377890909090946;
				_received = _obj.win(sScore, rScore, probWinServe); break;
			}
			case 3:
			{
				int sScore = 4;
				int rScore = 3;
				double probWinServe = 0.01;
				_expected = 0.6662085066547871;
				_received = _obj.win(sScore, rScore, probWinServe); break;
			}
			/*case 4:
			{
				int sScore = ;
				int rScore = ;
				double probWinServe = ;
				_expected = ;
				_received = _obj.win(sScore, rScore, probWinServe); break;
			}*/
			/*case 5:
			{
				int sScore = ;
				int rScore = ;
				double probWinServe = ;
				_expected = ;
				_received = _obj.win(sScore, rScore, probWinServe); break;
			}*/
			/*case 6:
			{
				int sScore = ;
				int rScore = ;
				double probWinServe = ;
				_expected = ;
				_received = _obj.win(sScore, rScore, probWinServe); break;
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
