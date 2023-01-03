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

class MaxTriangle {
 public:
  bool issquare(int n) {
    int sq = sqrt(n);
    return sq*sq == n;
  }
  double triangleArea(double x1, double y1, double x2, double y2, double x3, double y3) {
    x1 -= x3; y1 -= y3; x2 -= x3; y2 -= y3;
    return (x1 * y2 - x2 * y1) / 2;
  }
  double calculateArea(int A, int B) {
    vector<PII> asides, bsides;
    for (int i=0;i*i<=A;i++)
      if (issquare(A-i*i))
        asides.push_back(PII(i,sqrt(A-i*i)));
    for (int i=0;i*i<=B;i++)
      if (issquare(B-i*i))
        bsides.push_back(PII(i,sqrt(B-i*i)));
    double r = -1;
    for (int i=0;i<asides.size();i++)
      for (int j=0;j<bsides.size();j++)
        r = max(r,triangleArea(asides[i].first,-asides[i].second,
            bsides[j].first,bsides[j].second,0,0));
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
		cout << "Testing MaxTriangle (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396907644;
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
		MaxTriangle _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 1;
				int B = 1;
				_expected = 0.5;
				_received = _obj.calculateArea(A, B); break;
			}
			case 1:
			{
				int A = 3;
				int B = 7;
				_expected = -1.0;
				_received = _obj.calculateArea(A, B); break;
			}
			case 2:
			{
				int A = 41;
				int B = 85;
				_expected = 29.5;
				_received = _obj.calculateArea(A, B); break;
			}
			/*case 3:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.calculateArea(A, B); break;
			}*/
			/*case 4:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.calculateArea(A, B); break;
			}*/
			/*case 5:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.calculateArea(A, B); break;
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
