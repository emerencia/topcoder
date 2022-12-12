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

class AgeEncoding {
 public:
  double inbase(double base, string candles) {
    double fac = 1;
    double r = 0;
    for (int i=candles.size()-1;i>=0;i--) {
      if (candles[i] == '1')
        r += fac;
      fac *= base;
    }
    return r;
  }
  double getRadix(int age, string candlesLine) {
    string candles;
    for (int i=0;i<candlesLine.size();i++)
      if (candlesLine[i] == '1') {
        candles = candlesLine.substr(i);
        break;
      }
    if (candles.size() == 0) return -1;
    if (candles.size() == 1) return age == 1 ? -2 : -1;
    if (age == 1 && candles.size() > 1 && candles[candles.size()-1] == '1') return -1;
    double l = 0;
    double r = 100;
    for (int i=0;i<200;i++) {
      double m = (l+r)/2;
      if (inbase(m,candles) >= age)
        r = m;
      else
        l = m;
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
	string a = tt == -1 ? "0" : string(1,'0'+tt);
	char* b[2] = {argv[0],(char*)a.c_str()};
	if(tt!=-1){argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing AgeEncoding (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1401136017;
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
		AgeEncoding _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int age = 10;
				string candlesLine = "00010";
				_expected = 10.0;
				_received = _obj.getRadix(age, candlesLine); break;
			}
			case 1:
			{
				int age = 21;
				string candlesLine = "10101";
				_expected = 2.0;
				_received = _obj.getRadix(age, candlesLine); break;
			}
			case 2:
			{
				int age = 6;
				string candlesLine = "10100";
				_expected = 1.414213562373095;
				_received = _obj.getRadix(age, candlesLine); break;
			}
			case 3:
			{
				int age = 21;
				string candlesLine = "10111111110111101111111100111111110111111111111100";
				_expected = 0.9685012944510603;
				_received = _obj.getRadix(age, candlesLine); break;
			}
			case 4:
			{
				int age = 16;
				string candlesLine = "1";
				_expected = -1.0;
				_received = _obj.getRadix(age, candlesLine); break;
			}
			case 5:
			{
				int age = 1;
				string candlesLine = "1";
				_expected = -2.0;
				_received = _obj.getRadix(age, candlesLine); break;
			}
			case 6:
			{
				int age = 1;
				string candlesLine = "001000";
				_expected = 1.0;
				_received = _obj.getRadix(age, candlesLine); break;
			}
			/*case 7:
			{
				int age = ;
				string candlesLine = ;
				_expected = ;
				_received = _obj.getRadix(age, candlesLine); break;
			}*/
			/*case 8:
			{
				int age = ;
				string candlesLine = ;
				_expected = ;
				_received = _obj.getRadix(age, candlesLine); break;
			}*/
			/*case 9:
			{
				int age = ;
				string candlesLine = ;
				_expected = ;
				_received = _obj.getRadix(age, candlesLine); break;
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
