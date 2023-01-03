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
map<PILL,bool> mem;

class LCMSetEasy {
 public:
  int x;
  vector<int> S;
  LL gcd(LL a, LL b) {
    if (b == 0) return a;
    return gcd(b,a%b);
  }
  LL lcm(LL a, LL b) {
    return (a/gcd(a,b))*b;
  }
  bool rec(int idx, LL lm) {
    PILL p = PILL(idx,lm);
    if (idx == S.size()) return lm == x;
    if (mem.count(p)) return mem[p];
    bool t = false;
    if (x%S[idx] == 0) {
      LL nlm = lcm(lm,S[idx]);
      if (nlm <= x) t = rec(idx+1,nlm);
    }
    if (!t) return mem[p] = rec(idx+1,lm);
    return mem[p] = true;
  }
  string include(vector <int> S, int x) {
    this->x = x;
    this->S = S;
    mem.clear();
    return (rec(0,1) ? "Possible" : "Impossible");
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
		cout << "Testing LCMSetEasy (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395431424;
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
		LCMSetEasy _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int S[] = {2,3,4,5};
				int x = 20;
				_expected = "Possible";
				_received = _obj.include(vector <int>(S, S+sizeof(S)/sizeof(int)), x); break;
			}
			case 1:
			{
				int S[] = {2,3,4};
				int x = 611;
				_expected = "Impossible";
				_received = _obj.include(vector <int>(S, S+sizeof(S)/sizeof(int)), x); break;
			}
			case 2:
			{
				int S[] = {2,3,4};
				int x = 12;
				_expected = "Possible";
				_received = _obj.include(vector <int>(S, S+sizeof(S)/sizeof(int)), x); break;
			}
			case 3:
			{
				int S[] = {1,2,3,4,5,6,7,8,9,10};
				int x = 24;
				_expected = "Possible";
				_received = _obj.include(vector <int>(S, S+sizeof(S)/sizeof(int)), x); break;
			}
			case 4:
			{
				int S[] = {100,200,300,400,500,600};
				int x = 2000;
				_expected = "Possible";
				_received = _obj.include(vector <int>(S, S+sizeof(S)/sizeof(int)), x); break;
			}
			case 5:
			{
				int S[] = {100,200,300,400,500,600};
				int x = 8000;
				_expected = "Impossible";
				_received = _obj.include(vector <int>(S, S+sizeof(S)/sizeof(int)), x); break;
			}
			case 6:
			{
				int S[] = {1000000000,999999999,999999998};
				int x = 999999999;
				_expected = "Possible";
				_received = _obj.include(vector <int>(S, S+sizeof(S)/sizeof(int)), x); break;
			}
			case 7:
			{
				int S[] = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 14};
				int x = 1000000000;
				_expected = "Impossible";
				_received = _obj.include(vector <int>(S, S+sizeof(S)/sizeof(int)), x); break;
			}
			case 8:
			{
				int S[] = {1,2,3,4,6,8,12,24,5,10,15,20,30,40,60,120,36,72,360,180,18,9,90,720,1440,144,288};
				int x = 2880;
				_expected = "Possible";
				_received = _obj.include(vector <int>(S, S+sizeof(S)/sizeof(int)), x); break;
			}
			/*case 9:
			{
				int S[] = ;
				int x = ;
				_expected = ;
				_received = _obj.include(vector <int>(S, S+sizeof(S)/sizeof(int)), x); break;
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
