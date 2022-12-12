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

class GradingSystem {
 public:
  int fairness(vector <int> scores, vector <int> grades) {
    int cur = scores.size();
    cur = INT_MAX;
    vector<int> one;
    for (int i=grades.size()-1;i>=0;i--) {
      cur = min(cur,grades[i]);
      one.push_back(cur);
    }
    vector<int> two;
    cur = 0;
    for (int i=0;i<grades.size();i++) {
      cur = max(cur,grades[i]);
      two.push_back(cur);
    }
    return abs(accumulate(one.begin(),one.end(),0)-
               accumulate(two.begin(),two.end(),0));
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
		cout << "Testing GradingSystem (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395786677;
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
		GradingSystem _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int scores[] = {60,80,80};
				int grades[] = {3,8,6};
				_expected = 4;
				_received = _obj.fairness(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), vector <int>(grades, grades+sizeof(grades)/sizeof(int))); break;
			}
			case 1:
			{
				int scores[] = {0,25,50,75,100};
				int grades[] = {0,1,3,6,8};
				_expected = 0;
				_received = _obj.fairness(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), vector <int>(grades, grades+sizeof(grades)/sizeof(int))); break;
			}
			case 2:
			{
				int scores[] = {0,25,50,75,100};
				int grades[] = {8,6,3,1,0};
				_expected = 40;
				_received = _obj.fairness(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), vector <int>(grades, grades+sizeof(grades)/sizeof(int))); break;
			}
			/*case 3:
			{
				int scores[] = ;
				int grades[] = ;
				_expected = ;
				_received = _obj.fairness(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), vector <int>(grades, grades+sizeof(grades)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int scores[] = ;
				int grades[] = ;
				_expected = ;
				_received = _obj.fairness(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), vector <int>(grades, grades+sizeof(grades)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int scores[] = ;
				int grades[] = ;
				_expected = ;
				_received = _obj.fairness(vector <int>(scores, scores+sizeof(scores)/sizeof(int)), vector <int>(grades, grades+sizeof(grades)/sizeof(int))); break;
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
