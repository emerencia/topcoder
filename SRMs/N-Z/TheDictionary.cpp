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
const LL kMax = 1e9;

class TheDictionary {
 public:
  int n,m,k;
  long long bico(LL n, LL k) {
    if (k < 0 || k > n) return 0;
    if (k > n-k) k = n-k;
    long long r = 1;
    for (LL i = 0;i<k;i++) {
      r = (n-i)*r/(i+1);
      if (r > kMax) return kMax+1;
    }
    return r;
  }
  string rec(int idx, int lower, int aused) {
    if (idx == n+m) {
      if (lower != k-1) cout << "lower not k-1: " << lower << " " << k-1 << endl;
      return "";
    }
    if (aused == n) return "z"+rec(idx+1,lower,aused);
    if (idx-aused == m) return "a"+rec(idx+1,lower,aused+1);
    LL nlower = (LL)lower + bico(n+m-idx-1,n-aused-1);
    if (nlower > k-1) return "a"+rec(idx+1,lower,aused+1);
    return "z"+rec(idx+1,nlower,aused);
  }
  string find(int n, int m, int k) {
    this->n = n;
    this->m = m;
    this-> k = k;
    int max = bico(n+m,m);
    if (k > max) return "";
    return rec(0,0,0);   
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
		cout << "Testing TheDictionary (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393350889;
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
		TheDictionary _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int m = 2;
				int k = 2;
				_expected = "azaz";
				_received = _obj.find(n, m, k); break;
			}
			case 1:
			{
				int n = 2;
				int m = 2;
				int k = 6;
				_expected = "zzaa";
				_received = _obj.find(n, m, k); break;
			}
			case 2:
			{
				int n = 10;
				int m = 10;
				int k = 1000000000;
				_expected = "";
				_received = _obj.find(n, m, k); break;
			}
			case 3:
			{
				int n = 7;
				int m = 4;
				int k = 47;
				_expected = "aaazazaazaz";
				_received = _obj.find(n, m, k); break;
			}
			case 4:
			{
				int n = 100;
				int m = 100;
				int k = 1000000000;
				_expected = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaazzzzzzzzzzzzzzazzazzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzazzzzzzzzzzzzzzzzzzzzzzazzzzzazzzzzzzzzzzzazzzz";
				_received = _obj.find(n, m, k); break;
			}
			/*case 5:
			{
				int n = ;
				int m = ;
				int k = ;
				_expected = ;
				_received = _obj.find(n, m, k); break;
			}*/
			/*case 6:
			{
				int n = ;
				int m = ;
				int k = ;
				_expected = ;
				_received = _obj.find(n, m, k); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
