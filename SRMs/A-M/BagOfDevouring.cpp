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
double mem[1<<16];
int seen[1<<16];

class BagOfDevouring {
 public:
  vector<int> values, weights;
  double rec(int removed, int totalweight) {
    double& r = mem[removed];
    if (seen[removed]) return r;
    seen[removed] = 1;
    if (removed == (1<<(values.size()))-1) return r = 0;
    double rmax = 0;
    for (int i=0;i<values.size();i++) {
      if (removed&(1<<i)) continue;
      double t = values[i];
      int nremoved = removed|(1<<i);
      int ntotalweight = totalweight-weights[i];
      for (int j=0;j<values.size();j++) {
        if (nremoved&(1<<j)) continue;
        t += double(weights[j])/(ntotalweight+100)*
             rec(nremoved|(1<<j),
                 ntotalweight-weights[j]);
      }
      t+= 100.0/(ntotalweight+100)*rec(nremoved,ntotalweight);
      rmax = max(rmax,t);
    }
    return r = rmax;
  }
  double expectedYield(vector <int> values, vector <int> weights) {
    memset(seen,0,sizeof(seen));
    this->values = values;
    this->weights = weights;
    int totalweight = accumulate(weights.begin(),weights.end(),0);
    return rec(0,totalweight);
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
		cout << "Testing BagOfDevouring (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398197551;
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
		BagOfDevouring _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int values[] = {100,100};
				int weights[] = {100,100};
				_expected = 150.0;
				_received = _obj.expectedYield(vector <int>(values, values+sizeof(values)/sizeof(int)), vector <int>(weights, weights+sizeof(weights)/sizeof(int))); break;
			}
			case 1:
			{
				int values[] = {100,200,300};
				int weights[] = {100,200,300};
				_expected = 462.5;
				_received = _obj.expectedYield(vector <int>(values, values+sizeof(values)/sizeof(int)), vector <int>(weights, weights+sizeof(weights)/sizeof(int))); break;
			}
			case 2:
			{
				int values[] = {100,200,300};
				int weights[] = {300,200,100};
				_expected = 470.8333333333333;
				_received = _obj.expectedYield(vector <int>(values, values+sizeof(values)/sizeof(int)), vector <int>(weights, weights+sizeof(weights)/sizeof(int))); break;
			}
			case 3:
			{
				int values[] = {};
				int weights[] = {};
				_expected = 0.0;
				_received = _obj.expectedYield(vector <int>(values, values+sizeof(values)/sizeof(int)), vector <int>(weights, weights+sizeof(weights)/sizeof(int))); break;
			}
			case 4:
			{
				int values[] = {10,100,150,250,500,750,1000,2500,5000,7500,10000};
				int weights[] = {100,200,300,400,500,1000,2000,1500,3000,6000,4000};
				_expected = 20622.364509064962;
				_received = _obj.expectedYield(vector <int>(values, values+sizeof(values)/sizeof(int)), vector <int>(weights, weights+sizeof(weights)/sizeof(int))); break;
			}
			case 5:
			{
				int values[] = {7810, 4740, 8990, 9520, 1850};
				int weights[] = {8600, 4700, 800, 2100, 6600};
				_expected = 24670.9859615711;
				_received = _obj.expectedYield(vector <int>(values, values+sizeof(values)/sizeof(int)), vector <int>(weights, weights+sizeof(weights)/sizeof(int))); break;
			}
			/*case 6:
			{
				int values[] = ;
				int weights[] = ;
				_expected = ;
				_received = _obj.expectedYield(vector <int>(values, values+sizeof(values)/sizeof(int)), vector <int>(weights, weights+sizeof(weights)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int values[] = ;
				int weights[] = ;
				_expected = ;
				_received = _obj.expectedYield(vector <int>(values, values+sizeof(values)/sizeof(int)), vector <int>(weights, weights+sizeof(weights)/sizeof(int))); break;
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
