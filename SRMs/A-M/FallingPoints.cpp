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

class FallingPoints {
 public:
  vector <double> getHeights(vector <int> X, int R) {
    vector<double> y;
    y.push_back(0);
    for (int i=1;i<X.size();i++) {
      double highest = 0;
    //for (int j=0;j<i;j++) {
      for (int j=i-1;j<i;j++) {
        if (abs(X[i]-X[j]) <= R) {
          // calc highest as dist
          double increase = sqrt(R*R-(X[i]-X[j])*(X[i]-X[j]));
          highest = max(highest,y[j]+increase);
        }
      }
      y.push_back(highest);
    }
    return y;
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
		cout << "Testing FallingPoints (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393515442;
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
		FallingPoints _obj;
		vector <double> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int X[] = {0};
				int R = 10;
				double __expected[] = {0.0 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getHeights(vector <int>(X, X+sizeof(X)/sizeof(int)), R); break;
			}
			case 1:
			{
				int X[] = {1,100};
				int R = 10;
				double __expected[] = {0.0, 0.0 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getHeights(vector <int>(X, X+sizeof(X)/sizeof(int)), R); break;
			}
			case 2:
			{
				int X[] = {0,9};
				int R = 10;
				double __expected[] = {0.0, 4.358898943540674 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getHeights(vector <int>(X, X+sizeof(X)/sizeof(int)), R); break;
			}
			case 3:
			{
				int X[] = {0,9,19};
				int R = 10;
				double __expected[] = {0.0, 4.358898943540674, 4.358898943540674 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getHeights(vector <int>(X, X+sizeof(X)/sizeof(int)), R); break;
			}
			case 4:
			{
				int X[] = {13, 6, 0, 42, 51, 23, 33};
				int R = 10;
				double __expected[] = {0.0, 7.14142842854285, 15.14142842854285, 0.0, 4.358898943540674, 0.0, 0.0};
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getHeights(vector <int>(X, X+sizeof(X)/sizeof(int)), R); break;
			}
			/*case 5:
			{
				int X[] = ;
				int R = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getHeights(vector <int>(X, X+sizeof(X)/sizeof(int)), R); break;
			}*/
			/*case 6:
			{
				int X[] = ;
				int R = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getHeights(vector <int>(X, X+sizeof(X)/sizeof(int)), R); break;
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
