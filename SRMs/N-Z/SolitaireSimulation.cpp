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

class SolitaireSimulation {
 public:
  int periodLength(vector <int> heaps) {
    sort(heaps.begin(),heaps.end());
    vector<int> cheaps = heaps;
    int c = 1;
    map<vector<int>,int> seen;
    seen[heaps]=0;
    while (true) {
      vector<int> nheaps;
      for (int i=0;i<cheaps.size();i++)
        if (cheaps[i] > 1)
          nheaps.push_back(cheaps[i]-1);
      nheaps.push_back(cheaps.size());
      sort(nheaps.begin(),nheaps.end());
      cheaps.swap(nheaps);
      if (seen.count(cheaps)) 
        return c-seen[cheaps];
      seen[cheaps] = c;
      c++;
    }
    return -1;
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
		cout << "Testing SolitaireSimulation (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392218140;
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
		SolitaireSimulation _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int heaps[] = {3,1,3};
				_expected = 4;
				_received = _obj.periodLength(vector <int>(heaps, heaps+sizeof(heaps)/sizeof(int))); break;
			}
			case 1:
			{
				int heaps[] = {1,4};
				_expected = 3;
				_received = _obj.periodLength(vector <int>(heaps, heaps+sizeof(heaps)/sizeof(int))); break;
			}
			case 2:
			{
				int heaps[] = {1};
				_expected = 1;
				_received = _obj.periodLength(vector <int>(heaps, heaps+sizeof(heaps)/sizeof(int))); break;
			}
			case 3:
			{
				int heaps[] = {4,3,2,1};
				_expected = 1;
				_received = _obj.periodLength(vector <int>(heaps, heaps+sizeof(heaps)/sizeof(int))); break;
			}
			case 4:
			{
				int heaps[] = {3,3,3,3};
				_expected = 5;
				_received = _obj.periodLength(vector <int>(heaps, heaps+sizeof(heaps)/sizeof(int))); break;
			}
			/*case 5:
			{
				int heaps[] = ;
				_expected = ;
				_received = _obj.periodLength(vector <int>(heaps, heaps+sizeof(heaps)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int heaps[] = ;
				_expected = ;
				_received = _obj.periodLength(vector <int>(heaps, heaps+sizeof(heaps)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int heaps[] = ;
				_expected = ;
				_received = _obj.periodLength(vector <int>(heaps, heaps+sizeof(heaps)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
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
