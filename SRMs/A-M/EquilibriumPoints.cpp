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

class EquilibriumPoints {
 public:
  double find_equilibrium(double l, double r, int leftside, const vector<int>& x, const vector<int>& m) {
    double pivot = l;
    double oldpivot = r;
    while (l < r) {
      pivot = (l+r)/2;
      if (abs(oldpivot-pivot) < 1e-9) break;
      double weight = 0;
      for (int i=0;i<leftside;i++)
        weight += m[i]/((pivot-x[i])*(pivot-x[i]));
      for (int i=leftside;i<x.size();i++)
        weight -= m[i]/((x[i]-pivot)*(x[i]-pivot));
      if (weight > 0) {
        l = pivot;
      } else {
        r = pivot;
      }
      oldpivot = pivot;
    }
    return pivot;
  }
  vector <double> getPoints(vector <int> x, vector <int> m) {
    vector<double> r;
    for (int i=0;i+1<x.size();i++)
      r.push_back(find_equilibrium(x[i],x[i+1],i+1,x,m));
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
	if(tt!=-1){char* b[2];b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}	if (argc == 1) 
	{
		cout << "Testing EquilibriumPoints (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392219530;
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
		EquilibriumPoints _obj;
		vector <double> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {1, 2};
				int m[] = {1, 1};
				double __expected[] = {1.5 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getPoints(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {1, 2};
				int m[] = {1, 1000};
				double __expected[] = {1.0306534300317156 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getPoints(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {1, 2, 3};
				int m[] = {1, 2, 1};
				double __expected[] = {1.4060952084922507, 2.5939047915077493 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getPoints(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {2, 3, 5, 7};
				int m[] = {3, 2, 7, 5};
				double __expected[] = {2.532859446114924, 3.7271944335152813, 6.099953640852538 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getPoints(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			/*case 4:
			{
				int x[] = ;
				int m[] = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getPoints(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int x[] = ;
				int m[] = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getPoints(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int m[] = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getPoints(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		bool _passed = _expected.size() == _received.size();
		for (unsigned i = 0; i < _received.size(); i++)
			_passed = _passed && (abs(_expected[i]-_received[i]) < 1e-9 || (_received[i] > min(_expected[i]*(1.0-1e-9), _expected[i]*(1.0+1e-9)) && _received[i] < max(_expected[i]*(1.0-1e-9), _expected[i]*(1.0+1e-9))));
		if (_passed)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
