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

class TorusSailingEasy {
 public:
	int gcd(int a, int b) {
		if (!b) return a;
		return gcd(b,a%b);
	}
	int lcm(int a,int b) {
		int g = gcd(a,b);
		return (a/g)*b;
	}
	int number_of_steps(int N, int M, int goalX, int goalY) {
		int x = 0, y = 0;
		int c = 0;
		do {
			c++;
			x=(x+1)%N;
			y=(y+1)%M;
			if (x == goalX && y == goalY) return c;
		} while (x != 0 || y != 0);
		return -1;
	}
  double expectedTime(int N, int M, int goalX, int goalY) {
		int numsteps = number_of_steps(N,M,goalX,goalY);
		if (numsteps == -1) return -1.0;
		int maxsteps = lcm(N,M);
		numsteps %= maxsteps;
		vector<double> expected(maxsteps,0);
		expected[0] = 1;
		for (int k=0;k<10000;k++) {
			vector<double> newex(maxsteps,0);
			for (int i=0;i<maxsteps;i++) {
				newex[(i-1+maxsteps)%maxsteps] += 0.5*expected[i];
				newex[(i+1)%maxsteps] += 0.5*expected[i];
			}
			swap(expected,newex);
		}
		for (int i=0;i<maxsteps;i++)
			cout << i << ": " << expected[i] << endl;
		return 1.0/expected[numsteps];
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
		cout << "Testing TorusSailingEasy (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1425327686;
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
		TorusSailingEasy _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int M = 2;
				int goalX = 1;
				int goalY = 1;
				_expected = 1.0;
				_received = _obj.expectedTime(N, M, goalX, goalY); break;
			}
			case 1:
			{
				int N = 2;
				int M = 2;
				int goalX = 0;
				int goalY = 1;
				_expected = -1.0;
				_received = _obj.expectedTime(N, M, goalX, goalY); break;
			}
			case 2:
			{
				int N = 3;
				int M = 3;
				int goalX = 1;
				int goalY = 1;
				_expected = 2.0;
				_received = _obj.expectedTime(N, M, goalX, goalY); break;
			}
			case 3:
			{
				int N = 4;
				int M = 6;
				int goalX = 1;
				int goalY = 3;
				_expected = 27.0;
				_received = _obj.expectedTime(N, M, goalX, goalY); break;
			}
			/*case 4:
			{
				int N = ;
				int M = ;
				int goalX = ;
				int goalY = ;
				_expected = ;
				_received = _obj.expectedTime(N, M, goalX, goalY); break;
			}*/
			/*case 5:
			{
				int N = ;
				int M = ;
				int goalX = ;
				int goalY = ;
				_expected = ;
				_received = _obj.expectedTime(N, M, goalX, goalY); break;
			}*/
			/*case 6:
			{
				int N = ;
				int M = ;
				int goalX = ;
				int goalY = ;
				_expected = ;
				_received = _obj.expectedTime(N, M, goalX, goalY); break;
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
