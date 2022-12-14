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

class TheMoviesLevelTwoDivTwo {
 public:
  vector <int> find(vector <int> length, vector <int> scary) {
    vector<int> p;
    for (int i=0;i<length.size();i++)
      p.push_back(i);
    int maxcount = -2;
    vector<int> r;
    do {
      double scaredness = 74.5;
      for (int i=0;i<p.size();i++) {
        scaredness -= scary[p[i]];
        if (scaredness < 0) {
          if (i-1 > maxcount) {
            maxcount = i-1;
            r = p;
          }
          break;
        }
        scaredness += 47;
        scaredness -= length[p[i]] - scary[p[i]];
        if (scaredness < 0) {
          if (i-1 > maxcount) {
            maxcount = i-1;
            r = p;
          }
          break;
        }
        if (i > maxcount) {
          maxcount = i;
          r = p;
        }
      }
    } while (next_permutation(p.begin(),p.end()));
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
		cout << "Testing TheMoviesLevelTwoDivTwo (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1408648761;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TheMoviesLevelTwoDivTwo _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int length[] = {100, 50};
				int scary[] = {1, 1};
				int __expected[] = {0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <int>(length, length+sizeof(length)/sizeof(int)), vector <int>(scary, scary+sizeof(scary)/sizeof(int))); break;
			}
			case 1:
			{
				int length[] = {100, 50};
				int scary[] = {1, 49};
				int __expected[] = {1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <int>(length, length+sizeof(length)/sizeof(int)), vector <int>(scary, scary+sizeof(scary)/sizeof(int))); break;
			}
			case 2:
			{
				int length[] = {100, 100, 100, 100};
				int scary[] = {77, 76, 75, 74};
				int __expected[] = {3, 0, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <int>(length, length+sizeof(length)/sizeof(int)), vector <int>(scary, scary+sizeof(scary)/sizeof(int))); break;
			}
			case 3:
			{
				int length[] = {100};
				int scary[] = {99};
				int __expected[] = {0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <int>(length, length+sizeof(length)/sizeof(int)), vector <int>(scary, scary+sizeof(scary)/sizeof(int))); break;
			}
			/*case 4:
			{
				int length[] = ;
				int scary[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <int>(length, length+sizeof(length)/sizeof(int)), vector <int>(scary, scary+sizeof(scary)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int length[] = ;
				int scary[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <int>(length, length+sizeof(length)/sizeof(int)), vector <int>(scary, scary+sizeof(scary)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int length[] = ;
				int scary[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <int>(length, length+sizeof(length)/sizeof(int)), vector <int>(scary, scary+sizeof(scary)/sizeof(int))); break;
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
