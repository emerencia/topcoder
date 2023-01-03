#include <string>
#include <iostream>
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
typedef pair<PII,LL> PILL;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE
map<PILL,LL> mem;

class AlienAndHamburgers {
 public:
  vector<LL> tastes;
  long long rec(int idx,LL tottaste, int tottypes) {
    if (idx == tastes.size()) {
      return tottaste*tottypes;
    }
    if (mem.count(PILL(PII(idx,tottypes),tottaste)))
      return mem[PILL(PII(idx,tottypes),tottaste)];
    return mem[PILL(PII(idx,tottypes),tottaste)] = max(rec(idx+1,tottaste,tottypes),
               rec(idx+1,tottaste+tastes[idx],tottypes+1));
  }
  int getNumber(vector <int> type, vector <int> taste) {
    vector<LL> typetot(101,INT_MAX);
    for (int i=0;i<typetot.size();i++) {
      long long maxel = -INT_MAX;
      for (int j=0;j<type.size();j++) {
        if (type[j] != i) continue;
        if (taste[j] >= 0) {
          if (typetot[i] == INT_MAX) typetot[i] = taste[j];
          else typetot[i] += taste[j];
        } else {
          maxel = max(maxel,(LL)taste[j]);
        }
      }
      if (typetot[i] == INT_MAX && maxel != -INT_MAX)
        typetot[i] = maxel;
    }
    LL tottaste = 0;
    int tottypes = 0;
    tastes.clear();
    for (int i=0;i<typetot.size();i++)
      if (typetot[i] != INT_MAX && typetot[i] >= 0) {
        tottypes++;
        tottaste+=typetot[i];
      } else if (typetot[i] != INT_MAX) {
        tastes.push_back(typetot[i]);
      }
    return rec(0,tottaste,tottypes);
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
		cout << "Testing AlienAndHamburgers (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390305602;
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
		AlienAndHamburgers _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int type[] = {1, 2};
				int taste[] = {4, 7};
				_expected = 22;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}
			case 1:
			{
				int type[] = {1, 1};
				int taste[] = {-1, -1};
				_expected = 0;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}
			case 2:
			{
				int type[] = {1, 2, 3};
				int taste[] = {7, 4, -1};
				_expected = 30;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}
			case 3:
			{
				int type[] = {1, 2, 3, 2, 3, 1, 3, 2, 3, 1, 1, 1};
				int taste[] = {1, 7, -2, 3, -4, -1, 3, 1, 3, -5, -1, 0};
				_expected = 54;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}
			case 4:
			{
				int type[] = {30, 20, 10};
				int taste[] = {100000, -100000, 100000};
				_expected = 400000;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}
			case 5:
			{
				int type[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50 };
				int taste[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15, -16, -17, -18, -19, -20, -21, -22, -23, 24, -25, -26, -27, -28, -29, -30, -31, -32, -33, -34, -35, -36, -37, -38, -39, -40, -41, -42, -43, -44, -45, -46, -47, -48, -49, -50 };
				_expected = 72;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}
			/*case 6:
			{
				int type[] = ;
				int taste[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int type[] = ;
				int taste[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
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
