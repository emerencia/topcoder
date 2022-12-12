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
int mem[11][11][2][2];

class DistinctDigits {
 public:
  int n;
  vector<int> lown;
  vector<int> hign;
  int rec(int idx, int prev, bool smallerthanhigh, bool biggerthanlow) {
    int& r = mem[idx][prev][smallerthanhigh][biggerthanlow];
    if (r != -1) return r;
    if (idx == n) return r = 1;
    int t = 0;
    if (smallerthanhigh && biggerthanlow) {
      for (int i=0;i<=prev;i++)
        t+=rec(idx+1,i,smallerthanhigh,biggerthanlow);
    } else if (smallerthanhigh) {
      // not biggerthanlow so equaltolow
      if (lown[idx] <= prev)
        t+=rec(idx+1,lown[idx],smallerthanhigh,biggerthanlow);
      for (int i=lown[idx]+1;i<=prev;i++)
        t+=rec(idx+1,i,smallerthanhigh,true);
    } else if (biggerthanlow) {
      // not smallerthanhigh so equaltohigh
      for (int i=0;i<=min(prev,hign[idx]);i++)
        t+=rec(idx+1,i,(i!=hign[idx]),biggerthanlow);
    } else {
      for (int i=lown[idx];i<=min(hign[idx],prev);i++)
        t+=rec(idx+1,i,(i!=hign[idx]),(i!=lown[idx]));
    }
    return r = t;
  }
  vector<int> vectornumber(int n) {
    vector<int> r;
    r.push_back(n%10);
    while (n/10) {
      n/=10;
      r.push_back(n%10);
    }
    reverse(r.begin(),r.end());
    return r;
  }
  int count(int low, int high) {
    lown = vectornumber(low);
    hign = vectornumber(high);
    int r = 0;
    for (int i=lown.size();i<=hign.size();i++) {
      n = i;
      memset(mem,-1,sizeof(mem));
      int sval = (hign.size() == i ? hign[0] : 9);
      bool sth = (hign.size() != i);
      bool btl = (lown.size() != i || lown[0] < sval);
      r+=rec(0,9,sth,btl);
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
	if(tt!=-1){char* b[2];b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}	if (argc == 1) 
	{
		cout << "Testing DistinctDigits (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393012479;
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
		DistinctDigits _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int low = 1;
				int high = 20;
				_expected = 20;
				_received = _obj.count(low, high); break;
			}
			case 1:
			{
				int low = 1;
				int high = 30;
				_expected = 29;
				_received = _obj.count(low, high); break;
			}
			case 2:
			{
				int low = 151;
				int high = 309;
				_expected = 98;
				_received = _obj.count(low, high); break;
			}
			case 3:
			{
				int low = 1;
				int high = 15000;
				_expected = 1641;
				_received = _obj.count(low, high); break;
			}
			case 4:
			{
				int low = 153697;
				int high = 154689;
				_expected = 318;
				_received = _obj.count(low, high); break;
			}
			case 5:
			{
				int low = 1000;
				int high = 10000000;
				_expected = 19159;
				_received = _obj.count(low, high); break;
			}
			/*case 6:
			{
				int low = ;
				int high = ;
				_expected = ;
				_received = _obj.count(low, high); break;
			}*/
			/*case 7:
			{
				int low = ;
				int high = ;
				_expected = ;
				_received = _obj.count(low, high); break;
			}*/
			/*case 8:
			{
				int low = ;
				int high = ;
				_expected = ;
				_received = _obj.count(low, high); break;
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
