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
// 00:19 start
// 01:06 end
// END CUT HERE
LL mem[1<<10][51][101];

class TaroCards {
 public:
  vector<int> cardback;
  LL rec(int mask, int idx, int k) {
    LL& r = mem[mask][idx][k];
    if (r != -1) return r;
    if (idx == cardback.size()) return r = 1;
    LL t = 0;
    int kdec = 0;
    int newmask = mask;
    if (idx > 9 || !(mask&(1<<idx))) kdec++;
    if (idx <= 9 && !(mask&(1<<idx))) newmask |= (1<<idx);
    if (!(newmask&(1<<cardback[idx]))) {
      kdec++;
      newmask |= (1<<cardback[idx]);
    }
    if (k-kdec >= 0)
      t+=rec(newmask,idx+1,k-kdec);
    t+=rec(mask,idx+1,k);
    return r=t;
  }
  long long getNumber(vector <int> first, vector <int> second, int K) {
    memset(mem,-1,sizeof(mem));
    cardback = vector<int>(first.size());
    for (int i=0;i<first.size();i++)
      cardback[first[i]-1] = second[i]-1;
    return rec(0,0,K);
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
		cout << "Testing TaroCards (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1423264740;
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
		TaroCards _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int first[] = {1, 2};
				int second[] = {2, 3};
				int K = 2;
				_expected = 3LL;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(second, second+sizeof(second)/sizeof(int)), K); break;
			}
			case 1:
			{
				int first[] = {3, 1, 2};
				int second[] = {1, 1, 1};
				int K = 3;
				_expected = 8LL;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(second, second+sizeof(second)/sizeof(int)), K); break;
			}
			case 2:
			{
				int first[] = {4, 2, 1, 3};
				int second[] = {1, 2, 3, 4};
				int K = 5;
				_expected = 16LL;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(second, second+sizeof(second)/sizeof(int)), K); break;
			}
			case 3:
			{
				int first[] = {1, 2, 3, 4, 5, 6, 7};
				int second[] = {2, 1, 10, 9, 3, 2, 2};
				int K = 3;
				_expected = 17LL;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(second, second+sizeof(second)/sizeof(int)), K); break;
			}
			case 4:
			{
				int first[] = {1};
				int second[] = {2};
				int K = 1;
				_expected = 1LL;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(second, second+sizeof(second)/sizeof(int)), K); break;
			}
			case 5:
			{
				int first[] = {6, 20, 1, 11, 19, 14, 2, 8, 15, 21, 9, 10, 4, 16, 12, 17, 13, 22, 7, 18, 3, 5};
				int second[] = {4, 5, 10, 7, 6, 2, 1, 10, 10, 7, 9, 4, 5, 9, 5, 10, 10, 3, 6, 6, 4, 4};
				int K = 14;
				_expected = 2239000LL;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(second, second+sizeof(second)/sizeof(int)), K); break;
			}
			case 6:
			{
				int first[] = {6, 1, 11, 7, 8, 12, 2, 15, 21, 17, 23, 13, 9, 5, 24, 10, 18, 14, 22, 19, 16, 20, 3, 4};
				int second[] = {2, 6, 9, 7, 2, 3, 5, 3, 6, 9, 7, 3, 7, 6, 4, 10, 3, 5, 7, 2, 9, 3, 2, 2};
				int K = 4;
				_expected = 615LL;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(second, second+sizeof(second)/sizeof(int)), K); break;
			}
			/*case 7:
			{
				int first[] = ;
				int second[] = ;
				int K = ;
				_expected = LL;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(second, second+sizeof(second)/sizeof(int)), K); break;
			}*/
			/*case 8:
			{
				int first[] = ;
				int second[] = ;
				int K = ;
				_expected = LL;
				_received = _obj.getNumber(vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(second, second+sizeof(second)/sizeof(int)), K); break;
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
