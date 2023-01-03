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

class NumberNeighbours {
 public:
  int numPairs(vector <int> numbers) {
    int r = 0;
    for (int i=0;i<numbers.size();i++) {
      stringstream a;
      a << numbers[i];
      string s = a.str();
      s.resize(remove(s.begin(),s.end(),'0')-s.begin());
      sort(s.begin(),s.end());
      for (int j=i+1;j<numbers.size();j++) {
        stringstream b;
        b << numbers[j];
        string t = b.str();
        t.resize(remove(t.begin(),t.end(),'0')-t.begin());
        sort(t.begin(),t.end());
        if (s == t) ++r;
      }
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
		cout << "Testing NumberNeighbours (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1401829204;
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
		NumberNeighbours _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int numbers[] = {10, 1, 100, 20, 2, 3};
				_expected = 4;
				_received = _obj.numPairs(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 1:
			{
				int numbers[] = {204, 42, 40020, 200};
				_expected = 3;
				_received = _obj.numPairs(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 2:
			{
				int numbers[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
				_expected = 21;
				_received = _obj.numPairs(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 3:
			{
				int numbers[] = {3, 33, 333, 3333};
				_expected = 0;
				_received = _obj.numPairs(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 4:
			{
				int numbers[] = {1024, 4021, 204, 303, 33, 603, 36, 55, 505};
				_expected = 4;
				_received = _obj.numPairs(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			/*case 5:
			{
				int numbers[] = ;
				_expected = ;
				_received = _obj.numPairs(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int numbers[] = ;
				_expected = ;
				_received = _obj.numPairs(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int numbers[] = ;
				_expected = ;
				_received = _obj.numPairs(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
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
