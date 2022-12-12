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

class CardsCheating {
 public:
  map<int,int> desired;
  int n;
  bool isdesired(const vector<int>& a) {
    for (int i=0;i<n;i++)
      if (desired[a[i]] != i%3)
        return false;
    return true;
  }
  int numberOfShuffles(vector <int> cards, vector <int> shuffle) {
    desired.clear();
    n = cards.size();
    for (int i=0;i<n;i++)
      desired[i]=cards[i];
    vector<int> first;
    for (int i=0;i<n;i++)
      first.push_back(i);
    if (isdesired(first)) return 0;
    int r = 1;
    vector<int> current = first;
    do {
      vector<int> next(n,-1);
      for (int i=0;i<n;i++)
        next[shuffle[i]] = current[i];
      swap(next,current);
      if (isdesired(current)) return r;
      r++;
    } while (current != first);
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
		cout << "Testing CardsCheating (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390403146;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CardsCheating _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int cards[] = {0,1,2,0,1,2};
				int shuffle[] = {1,4,0,3,2,5};
				_expected = 0;
				_received = _obj.numberOfShuffles(vector <int>(cards, cards+sizeof(cards)/sizeof(int)), vector <int>(shuffle, shuffle+sizeof(shuffle)/sizeof(int))); break;
			}
			case 1:
			{
				int cards[] = {2,0,1};
				int shuffle[] = {1,2,0};
				_expected = 2;
				_received = _obj.numberOfShuffles(vector <int>(cards, cards+sizeof(cards)/sizeof(int)), vector <int>(shuffle, shuffle+sizeof(shuffle)/sizeof(int))); break;
			}
			case 2:
			{
				int cards[] = {1,1,2,0,2,0,1,0,2,2,1,0};
				int shuffle[] = {5,0,9,7,1,8,3,10,4,11,6,2};
				_expected = 59;
				_received = _obj.numberOfShuffles(vector <int>(cards, cards+sizeof(cards)/sizeof(int)), vector <int>(shuffle, shuffle+sizeof(shuffle)/sizeof(int))); break;
			}
			case 3:
			{
				int cards[] = {1,0,2};
				int shuffle[] = {0,2,1};
				_expected = -1;
				_received = _obj.numberOfShuffles(vector <int>(cards, cards+sizeof(cards)/sizeof(int)), vector <int>(shuffle, shuffle+sizeof(shuffle)/sizeof(int))); break;
			}
			/*case 4:
			{
				int cards[] = ;
				int shuffle[] = ;
				_expected = ;
				_received = _obj.numberOfShuffles(vector <int>(cards, cards+sizeof(cards)/sizeof(int)), vector <int>(shuffle, shuffle+sizeof(shuffle)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int cards[] = ;
				int shuffle[] = ;
				_expected = ;
				_received = _obj.numberOfShuffles(vector <int>(cards, cards+sizeof(cards)/sizeof(int)), vector <int>(shuffle, shuffle+sizeof(shuffle)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int cards[] = ;
				int shuffle[] = ;
				_expected = ;
				_received = _obj.numberOfShuffles(vector <int>(cards, cards+sizeof(cards)/sizeof(int)), vector <int>(shuffle, shuffle+sizeof(shuffle)/sizeof(int))); break;
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
