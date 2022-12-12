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
const int kMod = 1234567891;
int g[17][17];
LL mem[1<<16][17];

class TheCardLineDivTwo {
 public:
  int n;
  int color(char c) {
    if (c == 'S' || c == 'C') return 1;
    return 0;
  }
  LL rec(int used, int last) {
    LL& r = mem[used][last];
    if (r != -1) return r;
    if (used == (1<<n)-1) return r = 1;
    LL t = 0;
    for (int i=0;i<n;i++) {
      if (used&(1<<i) || (last != n+1 && !g[last][i])) continue;
      (t+=rec(used|(1<<i),i))%=kMod;
    }
    return r = t;
  }
  int count(vector <string> cards) {
    n = cards.size();
    memset(g,0,sizeof(g));
    for (int i=0;i<cards.size();i++) {
      int c = 0;
      for (int j=0;j<cards.size();j++) {
        bool compatible = (cards[i][0] == cards[j][0] ||
                           color(cards[i][1]) == color(cards[j][1]));
        c+=compatible;
        g[i][j] = compatible;
        g[j][i] = compatible;
      }
      if (!c) return 0;
    }
    memset(mem,-1,sizeof(mem));
    return rec(0,n+1);
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
		cout << "Testing TheCardLineDivTwo (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396533827;
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
		TheCardLineDivTwo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string cards[] = {"KH", "QD", "KC"};
				_expected = 2;
				_received = _obj.count(vector <string>(cards, cards+sizeof(cards)/sizeof(string))); break;
			}
			case 1:
			{
				string cards[] = {"JS", "JC", "JD", "JH"};
				_expected = 24;
				_received = _obj.count(vector <string>(cards, cards+sizeof(cards)/sizeof(string))); break;
			}
			case 2:
			{
				string cards[] = {"2S", "3C", "4C", "5S", "6C", "7S", "8S", "9H"};
				_expected = 0;
				_received = _obj.count(vector <string>(cards, cards+sizeof(cards)/sizeof(string))); break;
			}
			case 3:
			{
				string cards[] = {"KD", "KC", "AD", "7C", "AH", "9C", "4H", "4S", "AS"};
				_expected = 2416;
				_received = _obj.count(vector <string>(cards, cards+sizeof(cards)/sizeof(string))); break;
			}
			case 4:
			{
				string cards[] = {"8S"};
				_expected = 1;
				_received = _obj.count(vector <string>(cards, cards+sizeof(cards)/sizeof(string))); break;
			}
			/*case 5:
			{
				string cards[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(cards, cards+sizeof(cards)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string cards[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(cards, cards+sizeof(cards)/sizeof(string))); break;
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
