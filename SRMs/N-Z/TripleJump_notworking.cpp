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
const int tt = 0;
// 
// END CUT HERE

class TripleJump {
 public:
  vector <double> getProbabilities(int lower, int upper, int first, vector <int> opponents) {
    vector<int> myscores(3001,0);
    int tot = 0;
    for (int i=lower;i<=upper;i++)
      for (int j=lower;j<=upper;j++) {
        tot++;
        myscores[first+i+j]++;
      }
    sort(opponents.rbegin(),opponents.rend());
    vector<double> r;
    int t = 0;
    for (int i=3000;i>=opponents[0];i--)
      t+=myscores[i];
    r.push_back(double(t)/tot);
    for (int i=1;i<opponents.size();i++) {
      // jump between 
      t = 0;
      for (int j=opponents[i];j<opponents[i-1];j++)
        t+=myscores[j];
      r.push_back(double(t)/tot);
    }
    t = 0;
    for (int i=opponents.back()-1;i>=0;i--)
      t+=myscores[i];
    r.push_back(double(t)/tot);
    for (int i=0;i<10;i++)
      cout << i << ": " << myscores[i] << endl;
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
		cout << "Testing TripleJump (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391462886;
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
		TripleJump _obj;
		vector <double> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int lower = 1;
				int upper = 2;
				int first = 1;
				int opponents[] = {1,2,3,4};
				double __expected[] = {0.5, 0.5, 0.0, 0.0, 0.0 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getProbabilities(lower, upper, first, vector <int>(opponents, opponents+sizeof(opponents)/sizeof(int))); break;
			}
			case 1:
			{
				int lower = 3;
				int upper = 7;
				int first = 5;
				int opponents[] = {9,9,19,19,19};
				double __expected[] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getProbabilities(lower, upper, first, vector <int>(opponents, opponents+sizeof(opponents)/sizeof(int))); break;
			}
			case 2:
			{
				int lower = 1;
				int upper = 10;
				int first = 1;
				int opponents[] = {5};
				double __expected[] = {0.9753086419753086, 0.024691358024691357 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getProbabilities(lower, upper, first, vector <int>(opponents, opponents+sizeof(opponents)/sizeof(int))); break;
			}
			case 3:
			{
				int lower = 1;
				int upper = 10;
				int first = 5;
				int opponents[] = {1,2,3,5,10,11,12,19};
				double __expected[] = {0.22222222222222227, 0.6234567901234567, 0.05555555555555558, 0.043209876543209846, 0.05555555555555558, 0.0, 0.0, 0.0, 0.0 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getProbabilities(lower, upper, first, vector <int>(opponents, opponents+sizeof(opponents)/sizeof(int))); break;
			}
			/*case 4:
			{
				int lower = ;
				int upper = ;
				int first = ;
				int opponents[] = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getProbabilities(lower, upper, first, vector <int>(opponents, opponents+sizeof(opponents)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int lower = ;
				int upper = ;
				int first = ;
				int opponents[] = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getProbabilities(lower, upper, first, vector <int>(opponents, opponents+sizeof(opponents)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int lower = ;
				int upper = ;
				int first = ;
				int opponents[] = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getProbabilities(lower, upper, first, vector <int>(opponents, opponents+sizeof(opponents)/sizeof(int))); break;
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
