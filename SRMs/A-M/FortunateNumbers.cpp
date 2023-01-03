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

class FortunateNumbers {
 public:
  int getFortunate(vector <int> a, vector <int> b, vector <int> c) {
    set<int> d;
    for (int i=0;i<a.size();i++)
      for (int j=0;j<b.size();j++)
        for (int k=0;k<c.size();k++) {
          int n = a[i]+b[j]+c[k];
          int m = n;
          bool good = true;
          while (m) {
            if (m%10 != 5 && m%10 != 8) good = false;
            m/=10;
          }
          if (good) d.insert(n);
        }
    return d.size();
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
		cout << "Testing FortunateNumbers (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397135389;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		FortunateNumbers _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = { 1, 10, 100 };
				int b[] = { 3, 53 };
				int c[] = { 4, 54 };
				_expected = 2;
				_received = _obj.getFortunate(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 1:
			{
				int a[] = { 47 };
				int b[] = { 500 };
				int c[] = { 33 };
				_expected = 0;
				_received = _obj.getFortunate(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 2:
			{
				int a[] = { 100, 1, 10, 100, 1, 1 };
				int b[] = { 3, 53, 53, 53, 53, 53, 53 };
				int c[] = { 4, 54, 4, 54, 4, 54 };
				_expected = 2;
				_received = _obj.getFortunate(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 3:
			{
				int a[] = { 500, 800 };
				int b[] = { 50, 80 };
				int c[] = { 5, 8 };
				_expected = 8;
				_received = _obj.getFortunate(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = { 30000, 26264 };
				int b[] = { 30000, 29294 };
				int c[] = { 30000, 29594 };
				_expected = 3;
				_received = _obj.getFortunate(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			/*case 5:
			{
				int a[] = ;
				int b[] = ;
				int c[] = ;
				_expected = ;
				_received = _obj.getFortunate(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int a[] = ;
				int b[] = ;
				int c[] = ;
				_expected = ;
				_received = _obj.getFortunate(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				int b[] = ;
				int c[] = ;
				_expected = ;
				_received = _obj.getFortunate(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(3);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
