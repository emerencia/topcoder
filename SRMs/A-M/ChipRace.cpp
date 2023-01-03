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

class ChipRace {
 public:
  vector<double> r;
  vector<int> chips;
  LL c;
  void rec(int togo, int tot, double prob) {
    c++;
    if (!togo) return;
    for (int i=0;i<chips.size();i++) {
      if (!chips[i]) continue;
      double p = double(chips[i]*prob)/tot;
      r[i]+=p;
      int t = chips[i];
      chips[i] = 0;
      rec(togo-1,tot-t,p);
      chips[i] = t;
    }
  }
  vector <double> chances(vector <int> chips) {
    // all possible ways that the chips can be handed out
    // is done by backtracking
    this->chips = chips;
    c = 0;
    int tot = accumulate(chips.begin(),chips.end(),0);
    int handedout = round(tot/5.0);
    r = vector<double>(chips.size());
    rec(handedout, tot, 1);
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
		cout << "Testing ChipRace (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397834154;
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
		ChipRace _obj;
		vector <double> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int chips[] = { 1, 1 };
				double __expected[] = { 0.0,  0.0 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.chances(vector <int>(chips, chips+sizeof(chips)/sizeof(int))); break;
			}
			case 1:
			{
				int chips[] = { 1, 2 };
				double __expected[] = { 0.3333333333333333,  0.6666666666666666 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.chances(vector <int>(chips, chips+sizeof(chips)/sizeof(int))); break;
			}
			case 2:
			{
				int chips[] = { 3, 2, 3 };
				double __expected[] = { 0.725,  0.55,  0.725 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.chances(vector <int>(chips, chips+sizeof(chips)/sizeof(int))); break;
			}
			case 3:
			{
				int chips[] = { 0, 1, 2, 3, 4 };
				double __expected[] = { 0.0,  0.23452380952380952,  0.4412698412698413,  0.6083333333333334,  0.7158730158730159 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.chances(vector <int>(chips, chips+sizeof(chips)/sizeof(int))); break;
			}
			case 4:
			{
				int chips[] =  { 0, 1, 1, 0, 0, 0, 0, 1, 1, 0 };
				double __expected[] = { 0.0,  0.25,  0.25,  0.0,  0.0,  0.0,  0.0,  0.25,  0.25,  0.0 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.chances(vector <int>(chips, chips+sizeof(chips)/sizeof(int))); break;
			}
			case 5:
			{
				int chips[] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
				double __expected[] = {0.7999999999999999, 0.7999999999999999, 0.7999999999999999, 0.7999999999999999, 0.7999999999999999, 0.7999999999999999, 0.7999999999999999, 0.7999999999999999, 0.7999999999999999, 0.7999999999999999};
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.chances(vector <int>(chips, chips+sizeof(chips)/sizeof(int))); break;
			}
			/*case 6:
			{
				int chips[] = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.chances(vector <int>(chips, chips+sizeof(chips)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int chips[] = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.chances(vector <int>(chips, chips+sizeof(chips)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(3);
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
