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

class BouncingBalls {
 public:
  double expectedBounces(vector <int> x, int T) {
    vector<PII> balls;
    LL r = 0;
    for (int i=0;i<x.size();i++) {
      balls.push_back(PII(-1,x[i]));
      balls.push_back(PII(1,x[i]));
    }
    for (int i=0;i<T;i++) {
      // first calc new positions
      // then do calculations
      vector<PII> nballs;
      for (int i=0;i<balls.size();i++)
        nballs.push_back(PII(balls[i].first,balls[i].second+balls[i].first));
      balls = nballs;
      map<int,int> collisions;
      for (int i=0;i<balls.size();i++)
        if (balls[i].first == -1)
          collisions[balls[i].second]++;
      for (int i=0;i<balls.size();i++) {
        if (balls[i].first != 1) continue;
        if (collisions[balls[i].second]) {
          ++r;
          collisions[balls[i].second]--;
        } else if (collisions[balls[i].second-1]) {
          ++r;
          collisions[balls[i].second-1]--;
        }
      }
    }
    return r/4.0;
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
		cout << "Testing BouncingBalls (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1399466556;
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
		BouncingBalls _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {5, 8};
				int T = 2;
				_expected = 0.25;
				_received = _obj.expectedBounces(vector <int>(x, x+sizeof(x)/sizeof(int)), T); break;
			}
			case 1:
			{
				int x[] = {5, 8};
				int T = 1;
				_expected = 0.0;
				_received = _obj.expectedBounces(vector <int>(x, x+sizeof(x)/sizeof(int)), T); break;
			}
			case 2:
			{
				int x[] = {91, 857, 692, 54, 8679, 83, 792, 86, 9537, 913, 64, 592};
				int T = 458;
				_expected = 11.5;
				_received = _obj.expectedBounces(vector <int>(x, x+sizeof(x)/sizeof(int)), T); break;
			}
			case 3:
			{
				int x[] = {75432};
				int T = 386;
				_expected = 0.0;
				_received = _obj.expectedBounces(vector <int>(x, x+sizeof(x)/sizeof(int)), T); break;
			}
			case 4:
			{
				int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
				int T = 3;
				_expected = 12.75;
				_received = _obj.expectedBounces(vector <int>(x, x+sizeof(x)/sizeof(int)), T); break;
			}
			/*case 5:
			{
				int x[] = ;
				int T = ;
				_expected = ;
				_received = _obj.expectedBounces(vector <int>(x, x+sizeof(x)/sizeof(int)), T); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int T = ;
				_expected = ;
				_received = _obj.expectedBounces(vector <int>(x, x+sizeof(x)/sizeof(int)), T); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				int T = ;
				_expected = ;
				_received = _obj.expectedBounces(vector <int>(x, x+sizeof(x)/sizeof(int)), T); break;
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
