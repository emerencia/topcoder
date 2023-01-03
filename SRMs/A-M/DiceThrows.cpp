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

class DiceThrows {
 public:
  vector<double> rec(int n, vector<int>& sides) {
    vector<double> r(20001,-1);
    r[0] = 1;
    for (int i=0;i<n;i++) {
      vector<double> t(r.size(),-1);
      for (int j=0;j<20001;j++) {
        if (r[j]+1 > 1e-9) {
          double fac = 1.0/sides.size();
          for (int k=0;k<sides.size();k++) {
            if (j+sides[k] >= 20001) continue;
            if (t[j+sides[k]]+1 > 1e-9) t[j+sides[k]] += fac*r[j];
            else t[j+sides[k]] = fac*r[j];
          }
        }
      }
      swap(r,t);
    }
    return r;
  }
  double winProbability(int numDiceA, vector <int> sidesA, int numDiceB, vector <int> sidesB) {
    vector<double> ra = rec(numDiceA,sidesA);
    vector<double> rb = rec(numDiceB,sidesB);
    double r = 0;
    double bprob = 1;
    for (int i=20000;i>=0;i--) {
      if (rb[i]+1 > 1e-9) bprob -= rb[i];
      if (ra[i]+1 > 1e-9)
        r+= ra[i]*bprob;
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
		cout << "Testing DiceThrows (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397655564;
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
		DiceThrows _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int numDiceA = 1;
				int sidesA[] = {1,2,3,4,5,6};
				int numDiceB = 1;
				int sidesB[] = {1,2,3,4,5,6};
				_expected = 0.41666666666666663;
				_received = _obj.winProbability(numDiceA, vector <int>(sidesA, sidesA+sizeof(sidesA)/sizeof(int)), numDiceB, vector <int>(sidesB, sidesB+sizeof(sidesB)/sizeof(int))); break;
			}
			case 1:
			{
				int numDiceA = 200;
				int sidesA[] = {1,3,8,18,45,100};
				int numDiceB = 200;
				int sidesB[] = {1,4,10,21,53,100};
				_expected = 0.25240407058279035;
				_received = _obj.winProbability(numDiceA, vector <int>(sidesA, sidesA+sizeof(sidesA)/sizeof(int)), numDiceB, vector <int>(sidesB, sidesB+sizeof(sidesB)/sizeof(int))); break;
			}
			case 2:
			{
				int numDiceA = 2;
				int sidesA[] = {1,1,1,2,2,2};
				int numDiceB = 3;
				int sidesB[] = {1,1,1,1,1,1};
				_expected = 0.25;
				_received = _obj.winProbability(numDiceA, vector <int>(sidesA, sidesA+sizeof(sidesA)/sizeof(int)), numDiceB, vector <int>(sidesB, sidesB+sizeof(sidesB)/sizeof(int))); break;
			}
			case 3:
			{
				int numDiceA = 200;
				int sidesA[] = {6,5,4,3,2,1};
				int numDiceB = 200;
				int sidesB[] = {3,4,6,5,1,2};
				_expected = 0.49416239842107595;
				_received = _obj.winProbability(numDiceA, vector <int>(sidesA, sidesA+sizeof(sidesA)/sizeof(int)), numDiceB, vector <int>(sidesB, sidesB+sizeof(sidesB)/sizeof(int))); break;
			}
			case 4:
			{
				int numDiceA = 100;
				int sidesA[] = {1,1,1,1,1,2};
				int numDiceB = 199;
				int sidesB[] = {1,1,1,1,1,1};
				_expected = 1.5306467074865068E-78;
				_received = _obj.winProbability(numDiceA, vector <int>(sidesA, sidesA+sizeof(sidesA)/sizeof(int)), numDiceB, vector <int>(sidesB, sidesB+sizeof(sidesB)/sizeof(int))); break;
			}
			/*case 5:
			{
				int numDiceA = ;
				int sidesA[] = ;
				int numDiceB = ;
				int sidesB[] = ;
				_expected = ;
				_received = _obj.winProbability(numDiceA, vector <int>(sidesA, sidesA+sizeof(sidesA)/sizeof(int)), numDiceB, vector <int>(sidesB, sidesB+sizeof(sidesB)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int numDiceA = ;
				int sidesA[] = ;
				int numDiceB = ;
				int sidesB[] = ;
				_expected = ;
				_received = _obj.winProbability(numDiceA, vector <int>(sidesA, sidesA+sizeof(sidesA)/sizeof(int)), numDiceB, vector <int>(sidesB, sidesB+sizeof(sidesB)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int numDiceA = ;
				int sidesA[] = ;
				int numDiceB = ;
				int sidesB[] = ;
				_expected = ;
				_received = _obj.winProbability(numDiceA, vector <int>(sidesA, sidesA+sizeof(sidesA)/sizeof(int)), numDiceB, vector <int>(sidesB, sidesB+sizeof(sidesB)/sizeof(int))); break;
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
