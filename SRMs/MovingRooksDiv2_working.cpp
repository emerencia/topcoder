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

class MovingRooksDiv2 {
 public:
  set<vector<int> > tried;
  void rec(vector<int>& Y) {
    tried.insert(Y);
    for (int i = 0;i<Y.size();i++)
      for (int j = i+1;j<Y.size();j++) {
        if (Y[i] < Y[j]) continue;
        swap(Y[i],Y[j]);
        if (!tried.count(Y))
          rec(Y);
        swap(Y[i],Y[j]);
      }
  }
  string move(vector <int> Y1, vector <int> Y2) {
    tried.clear();
    rec(Y1);
    return tried.count(Y2) ? "Possible" : "Impossible";
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
		cout << "Testing MovingRooksDiv2 (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1435055275;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MovingRooksDiv2 _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int Y1[] = {0};
				int Y2[] = {0};
				_expected = "Possible";
				_received = _obj.move(vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
			}
			case 1:
			{
				int Y1[] = {1,0};
				int Y2[] = {0,1};
				_expected = "Possible";
				_received = _obj.move(vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
			}
			case 2:
			{
				int Y1[] = {0,1};
				int Y2[] = {1,0};
				_expected = "Impossible";
				_received = _obj.move(vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
			}
			case 3:
			{
				int Y1[] = {3,1,2,0};
				int Y2[] = {0,2,1,3};
				_expected = "Possible";
				_received = _obj.move(vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
			}
			case 4:
			{
				int Y1[] = {3,1,2,0};
				int Y2[] = {3,2,0,1};
				_expected = "Impossible";
				_received = _obj.move(vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
			}
			/*case 5:
			{
				int Y1[] = ;
				int Y2[] = ;
				_expected = ;
				_received = _obj.move(vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int Y1[] = ;
				int Y2[] = ;
				_expected = ;
				_received = _obj.move(vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int Y1[] = ;
				int Y2[] = ;
				_expected = ;
				_received = _obj.move(vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
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
