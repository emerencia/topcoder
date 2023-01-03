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
typedef pair<int,LL> PILL;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE
map<PILL,LL> mem;

class PowersOfTwo {
 public:
  vector<LL> powers;
  LL rec(int idx, LL used) { 
    // if you have it always use it
    // if you don't, see if you  can make it
    if (idx < 0) return 1;
    PILL p = PILL(idx,used);
    if (mem.count(p)) return mem[p];
    LL sofar = 0; 
    LL nused = used; 
    for (int i=0;i<powers.size();i++) { 
      if (used&(1LL<<i)) continue;
      if (powers[i] == (1LL<<idx))
        return mem[p] = 2LL*rec(idx-1,used);
      if (sofar+powers[i] <= (1LL<<idx)) {
        sofar+=powers[i]; 
        nused|=(1LL<<i);
      }
    }
    LL t = 0;
    if (sofar == (1LL<<idx))
      t+= rec(idx-1,nused);
    t+= rec(idx-1,used); 
    return mem[p] = t;
  }
  long long count(vector<long long> powers) {
    sort(powers.rbegin(),powers.rend());
    this->powers = powers;
    mem.clear();
    return rec(62,0);
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
		cout << "Testing PowersOfTwo (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395428051;
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
		PowersOfTwo _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long powers[] = {1,2};
				_expected = 4LL;
				_received = _obj.count(vector<long long>(powers, powers+sizeof(powers)/sizeof(long long))); break;
			}
			case 1:
			{
				long long powers[] = {1,1,1,1};
				_expected = 5LL;
				_received = _obj.count(vector<long long>(powers, powers+sizeof(powers)/sizeof(long long))); break;
			}
			case 2:
			{
				long long powers[] = {1,2,2,2,4,4,16};
				_expected = 32LL;
				_received = _obj.count(vector<long long>(powers, powers+sizeof(powers)/sizeof(long long))); break;
			}
			case 3:
			{
				long long powers[] = {1,32,1,16,32};
				_expected = 18LL;
				_received = _obj.count(vector<long long>(powers, powers+sizeof(powers)/sizeof(long long))); break;
			}
			case 4:
			{
				long long powers[] = {1048576,1073741824,549755813888,70368744177664,4398046511104,262144,1048576,2097152,8796093022208,
				                      1048576,1048576,35184372088832,2097152,256,256,256,262144,1048576,1048576,70368744177664,262144,1048576};
				_expected = 18432LL;
				_received = _obj.count(vector<long long>(powers, powers+sizeof(powers)/sizeof(long long))); break;
			}
			case 5:
			{
				long long powers[] = {1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624, 1125899906842624};
				_expected = 51LL;
				_received = _obj.count(vector<long long>(powers, powers+sizeof(powers)/sizeof(long long))); break;
			}
			case 6:
			{
   long long powers[] = {4LL, 512LL, 34359738368LL, 68719476736LL, 512LL, 35184372088832LL, 4294967296LL, 281474976710656LL, 1048576LL, 2048LL, 64LL, 2048LL, 281474976710656LL, 68719476736LL, 64LL, 4294967296LL, 512LL, 512LL, 512LL, 33554432LL, 512LL, 8589934592LL, 512LL, 2LL, 1048576LL, 4294967296LL, 512LL, 32LL, 34359738368LL, 64LL, 8192LL, 70368744177664LL, 2147483648LL, 1048576LL, 281474976710656LL, 512LL, 4294967296LL, 2048LL, 512LL};
				_expected = 15654912LL;
				_received = _obj.count(vector<long long>(powers, powers+sizeof(powers)/sizeof(long long))); break;
			}
			/*case 7:
			{
				long long powers[] = ;
				_expected = LL;
				_received = _obj.count(vector<long long>(powers, powers+sizeof(powers)/sizeof(long long))); break;
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
