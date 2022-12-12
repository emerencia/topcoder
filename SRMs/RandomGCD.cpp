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
const int kMod = 1e9+7;

class RandomGCD {
 public:
  vector<int> members;
  vector<bool> used;
  int K;
  int N;
  LL ans;
  int gcd(int a,int b) {
    if (b == 0) return a;
    return gcd(b,a%b);
  }
  long long factorial(long long x) {
    long long c = 1;
    for (long long i=1;i<=x;i++)
      c = (c*i)%kMod;
    return c;
  }
  LL rec(int g, int idx) {
    LL r = 0;
    //bool added = false;
    for (int i=idx;i<used.size();i++) {
      if (used[i]) continue;
      int gg = g;
      bool good = true;
      if (gg == 0) {
        gg = members[i];
      } else {
        gg = gcd(gg,members[i]);
        good = (gg == K);
      }
      if (!good) continue;
      //added = true;
      used[i] = true;
      (r+=rec(gg,i+1))%=kMod;
      used[i] = false;
      break;
    }
    LL t = 0;
    if (g == K) {
      int cnt = 0;
      for (int i=0;i<used.size();i++) {
        cnt+=used[i];
        //if (used[i]) cout << members[i] << endl;
      }
      //cout << cnt << endl;
      //cout << endl;
      t = factorial(cnt);
      for (int i=0;i<max(0,N-cnt);i++)
        (t*=cnt)%=kMod;
    }
    return r+t;
  }
  int countTuples(int N, int K, int low, int high) {
    this->K = K;
    this->N = N;
    members.clear();
    LL cnt = 0;
    for (LL i=low;i<=high;i++) {
      if (i%K == 0) {
        members.push_back(i);
        cnt++;
      }
    }
    used = vector<bool>(members.size(),false);
    LL r = 0;
    for (int i=0;i<members.size();i++) {
      used[i] = true;
      (r+=rec(members[i],i+1))%=kMod;
      used[i] = false;
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
		cout << "Testing RandomGCD (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395414352;
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
		RandomGCD _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int K = 2;
				int low = 2;
				int high = 4;
				_expected = 3;
				_received = _obj.countTuples(N, K, low, high); break;
			}
			case 1:
			{
				int N = 2;
				int K = 100;
				int low = 2;
				int high = 4;
				_expected = 0;
				_received = _obj.countTuples(N, K, low, high); break;
			}
			case 2:
			{
				int N = 1;
				int K = 5;
				int low = 5;
				int high = 5;
				_expected = 1;
				_received = _obj.countTuples(N, K, low, high); break;
			}
			case 3:
			{
				int N = 73824;
				int K = 17347;
				int low = 9293482;
				int high = 9313482;
				_expected = 0;
				_received = _obj.countTuples(N, K, low, high); break;
			}
			case 4:
			{
				int N = 222;
				int K = 222;
				int low = 222;
				int high = 22222;
				_expected = 339886855;
				_received = _obj.countTuples(N, K, low, high); break;
			}
			/*case 5:
			{
				int N = ;
				int K = ;
				int low = ;
				int high = ;
				_expected = ;
				_received = _obj.countTuples(N, K, low, high); break;
			}*/
			/*case 6:
			{
				int N = ;
				int K = ;
				int low = ;
				int high = ;
				_expected = ;
				_received = _obj.countTuples(N, K, low, high); break;
			}*/
			/*case 7:
			{
				int N = ;
				int K = ;
				int low = ;
				int high = ;
				_expected = ;
				_received = _obj.countTuples(N, K, low, high); break;
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
