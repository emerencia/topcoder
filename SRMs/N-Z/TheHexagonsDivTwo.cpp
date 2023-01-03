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
int modnumbers[10];
LL mem[8][10][10][10];

class TheHexagonsDivTwo {
 public:
  int n,k;
  LL rec(int idx, int final, int prev, int first) {
    LL& r = mem[idx][final][prev][first];
    //if (r != -1) return r;
    if (idx == 7) return r = 1;
    LL t = 0;
    int finale = final;
    for (int i=0;i<k;i++) {
      if (idx == 1) finale = i;
      if (i == prev || i == first) continue;
      if (idx == 6 && i == finale) continue;
      if (!modnumbers[i]) continue;
      int fac = modnumbers[i];
      modnumbers[i]--;
      t += fac*rec(idx+1,finale,i,first);
      modnumbers[i]++;
    }
    return r = t;
  }
  long long count(int n, int k) {
    this->n = n;
    this->k = k;
    memset(modnumbers,0,sizeof(modnumbers));
    for (int i=1;i<=n;i++)
      modnumbers[i%k]++;
    LL r = 0;
    memset(mem,-1,sizeof(mem));
    for (int i=0;i<k;i++) {
      int fac = modnumbers[i];
      if (!fac) continue;
      modnumbers[i]--;
      r+=fac*rec(1,0,i,i);
      modnumbers[i]++;
    }
    return r ? r/6 : 0;
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
		cout << "Testing TheHexagonsDivTwo (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1399388091;
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
		TheHexagonsDivTwo _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 7;
				int k = 3;
				_expected = 0LL;
				_received = _obj.count(n, k); break;
			}
			case 1:
			{
				int n = 8;
				int k = 3;
				_expected = 24LL;
				_received = _obj.count(n, k); break;
			}
			case 2:
			{
				int n = 8;
				int k = 4;
				_expected = 256LL;
				_received = _obj.count(n, k); break;
			}
			case 3:
			{
				int n = 20;
				int k = 5;
				_expected = 4692480LL;
				_received = _obj.count(n, k); break;
			}
			/*case 4:
			{
				int n = ;
				int k = ;
				_expected = LL;
				_received = _obj.count(n, k); break;
			}*/
			/*case 5:
			{
				int n = ;
				int k = ;
				_expected = LL;
				_received = _obj.count(n, k); break;
			}*/
			/*case 6:
			{
				int n = ;
				int k = ;
				_expected = LL;
				_received = _obj.count(n, k); break;
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
