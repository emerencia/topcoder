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
const int tt = -1;
// 
// END CUT HERE

class ORSolitaireDiv2 {
 public:
  int getMinimum(vector <int> numbers, int goal) {
    int mn = INT_MAX;
    int goalsub = 0;
    for (int i=0;i<numbers.size();i++)
      if ((goal&numbers[i]) == numbers[i])
        goalsub |= numbers[i];
    if (goalsub != goal) return 0;
    for (int i=30;i>=0;i--) {
      if (!(goal&(1<<i))) continue;
      int tmn = 0;
      for (int j=0;j<numbers.size();j++)
        if (numbers[j]&(1<<i) && (goal&numbers[j]) == numbers[j])
          tmn++;
      mn = min(mn,tmn);
    }
    return mn;
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
		cout << "Testing ORSolitaireDiv2 (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390840124;
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
		ORSolitaireDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int numbers[] = {1, 2, 4};
				int goal = 7;
				_expected = 1;
				_received = _obj.getMinimum(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), goal); break;
			}
			case 1:
			{
				int numbers[] = {1, 2, 4, 7, 8};
				int goal = 7;
				_expected = 2;
				_received = _obj.getMinimum(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), goal); break;
			}
			case 2:
			{
				int numbers[] = {12571295, 2174218, 2015120};
				int goal = 1;
				_expected = 0;
				_received = _obj.getMinimum(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), goal); break;
			}
			case 3:
			{
				int numbers[] = {5, 2, 4, 52, 62, 9, 8, 3, 1, 11, 6};
				int goal = 11;
				_expected = 3;
				_received = _obj.getMinimum(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), goal); break;
			}
			case 4:
			{
				int numbers[] = {503, 505, 152, 435, 491, 512, 1023, 355, 510, 500, 502, 255, 63, 508, 509, 511, 60, 250, 254, 346};
				int goal = 510;
				_expected = 5;
				_received = _obj.getMinimum(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), goal); break;
			}
			/*case 5:
			{
				int numbers[] = ;
				int goal = ;
				_expected = ;
				_received = _obj.getMinimum(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), goal); break;
			}*/
			/*case 6:
			{
				int numbers[] = ;
				int goal = ;
				_expected = ;
				_received = _obj.getMinimum(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), goal); break;
			}*/
			/*case 7:
			{
				int numbers[] = ;
				int goal = ;
				_expected = ;
				_received = _obj.getMinimum(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), goal); break;
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
