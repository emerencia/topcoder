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

class IQTest {
 public:
  string nextNumber(vector <int> previous) {
    if (previous.size() == 1) return "AMBIGUITY";
    if (previous.size() == 2 && previous[0] == previous[1]) {
      stringstream s;
      s<< previous[0];
      return s.str();
    }
    if (previous.size() == 2 && previous[0] != previous[1]) {
      return "AMBIGUITY";
    }
    set<int> r;
    for (int a=-200;a<=200;a++) {
      int b = previous[1]-a*previous[0];
      bool good = true;
      for (int i=1;i<previous.size();i++)
        if (previous[i-1]*a+b != previous[i]) {
          good = false;
          break;
        }
      if (good) r.insert(a*previous.back()+b);
    }
    if (!r.size()) return "BUG";
    if (r.size() > 1) return "AMBIGUITY";
    int r2 = *(r.begin());
    stringstream s;
    s << r2;
    return s.str();
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
		cout << "Testing IQTest (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397951675;
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
		IQTest _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int previous[] = {1, 2, 3, 4, 5};
				_expected = "6";
				_received = _obj.nextNumber(vector <int>(previous, previous+sizeof(previous)/sizeof(int))); break;
			}
			case 1:
			{
				int previous[] = {3, 6, 12, 24, 48};
				_expected = "96";
				_received = _obj.nextNumber(vector <int>(previous, previous+sizeof(previous)/sizeof(int))); break;
			}
			case 2:
			{
				int previous[] = {1, 4, 13, 40};
				_expected = "121";
				_received = _obj.nextNumber(vector <int>(previous, previous+sizeof(previous)/sizeof(int))); break;
			}
			case 3:
			{
				int previous[] = {0};
				_expected = "AMBIGUITY";
				_received = _obj.nextNumber(vector <int>(previous, previous+sizeof(previous)/sizeof(int))); break;
			}
			case 4:
			{
				int previous[] = {-1, 2};
				_expected = "AMBIGUITY";
				_received = _obj.nextNumber(vector <int>(previous, previous+sizeof(previous)/sizeof(int))); break;
			}
			case 5:
			{
				int previous[] = {57, 57};
				_expected = "57";
				_received = _obj.nextNumber(vector <int>(previous, previous+sizeof(previous)/sizeof(int))); break;
			}
			case 6:
			{
				int previous[] = {16, -8, 4, -2};
				_expected = "BUG";
				_received = _obj.nextNumber(vector <int>(previous, previous+sizeof(previous)/sizeof(int))); break;
			}
			case 7:
			{
				int previous[] = {6, 5, 4, 3, 1};
				_expected = "BUG";
				_received = _obj.nextNumber(vector <int>(previous, previous+sizeof(previous)/sizeof(int))); break;
			}
			case 8:
			{
				int previous[] = {-12, 12, -36, 60};
				_expected = "-132";
				_received = _obj.nextNumber(vector <int>(previous, previous+sizeof(previous)/sizeof(int))); break;
			}
			case 9:
			{
				int previous[] = {-100, -99, 99};
				_expected = "39303";
				_received = _obj.nextNumber(vector <int>(previous, previous+sizeof(previous)/sizeof(int))); break;
			}
			/*case 10:
			{
				int previous[] = ;
				_expected = ;
				_received = _obj.nextNumber(vector <int>(previous, previous+sizeof(previous)/sizeof(int))); break;
			}*/
			/*case 11:
			{
				int previous[] = ;
				_expected = ;
				_received = _obj.nextNumber(vector <int>(previous, previous+sizeof(previous)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
