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
// 13:11
// END CUT HERE
bool seen[10][21][10][4][1<<3];
double mem[10][21][10][4][1<<3];

class BaseballLineup {
 public:
  struct Player {
    double outs;
    double walks;
    double singles;
    double doubles;
    double triples;
    double homeruns;
    Player(string ss) {
      stringstream a(ss);
      int o,w,s,d,t,h;
      a >> o >> w >> s >> d >> t >> h;
      outs = o/1000.0;
      walks = w/1000.0;
      singles = s/1000.0;
      doubles = d/1000.0;
      triples = t/1000.0;
      homeruns = h/1000.0;
    }
  };
  vector<Player> players;
  vector<Player> getplayers(const vector<string>& stats) {
    vector<Player> r;
    for (int i=0;i<stats.size();i++)
      r.push_back(Player(stats[i]));
    return r;
  }
  double rec(int inningsleft, int playersleftininning, int idx, int outs, int bases) {
    double& r = mem[inningsleft][playersleftininning][idx][outs][bases];
    if (seen[inningsleft][playersleftininning][idx][outs][bases]) return r;
    seen[inningsleft][playersleftininning][idx][outs][bases] = 1;
    if (!inningsleft && (!playersleftininning || outs == 3))
      return r = 0;
    if (!playersleftininning || outs == 3)
      return r = rec(inningsleft-1,20,idx,0,0);
    double t = 0;
    // out
    t+=players[idx].outs*rec(inningsleft,playersleftininning-1,(idx+1)%9,outs+1,bases);
    // walk
    int k = 0;
    int cnt = bases == 7;
    while (bases&(1<<k)) ++k;
    int newbases = 0;
    if (k >= 3) newbases = 7;
    else newbases = bases|(1<<k);
    t+=players[idx].walks*(cnt+rec(inningsleft,playersleftininning-1,(idx+1)%9,outs,newbases));
    // single
    cnt = ((bases>>1)&1) + ((bases>>2)&1);
    newbases = 1;
    if (bases&(1<<0)) newbases |= 2;
    t+=players[idx].singles*(cnt+rec(inningsleft,playersleftininning-1,(idx+1)%9,outs,newbases));
    // double
    cnt = ((bases>>0)&1) + ((bases>>1)&1) + ((bases>>2)&1);
    newbases = 2;
    t+=players[idx].doubles*(cnt+rec(inningsleft,playersleftininning-1,(idx+1)%9,outs,newbases));
    // triple
    cnt = ((bases>>0)&1) + ((bases>>1)&1) + ((bases>>2)&1);
    newbases = 4;
    t+=players[idx].triples*(cnt+rec(inningsleft,playersleftininning-1,(idx+1)%9,outs,newbases));
    // home run
    cnt = ((bases>>0)&1) + ((bases>>1)&1) + ((bases>>2)&1) + 1;
    newbases = 0;
    t+=players[idx].homeruns*(cnt+rec(inningsleft,playersleftininning-1,(idx+1)%9,outs,newbases));
    return r = t;
  }
  double expectedRuns(vector <string> stats) {
    players = getplayers(stats);
    memset(seen,0,sizeof(seen));
    return rec(8,20,0,0,0);
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
		cout << "Testing BaseballLineup (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398510352;
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
		BaseballLineup _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string stats[] = {"652 77 185 53 13 20",
				                  "649 58 213 74 1 5",
				                  "646 107 141 37 0 69",
				                  "650 100 159 55 1 35",
				                  "683 64 160 49 3 41",
				                  "663 76 184 43 2 32",
				                  "712 80 111 63 0 34",
				                  "693 99 135 48 2 23",
				                  "824 16 112 16 0 32"};
				_expected = 4.799858944836131;
				_received = _obj.expectedRuns(vector <string>(stats, stats+sizeof(stats)/sizeof(string))); break;
			}
			case 1:
			{
				string stats[] = {"1 0 0 0 0 999",
				                  "1 0 0 0 0 999",
				                  "1 0 0 0 0 999",
				                  "1 0 0 0 0 999",
				                  "1 0 0 0 0 999",
				                  "1 0 0 0 0 999",
				                  "1 0 0 0 0 999",
				                  "1 0 0 0 0 999",
				                  "1 0 0 0 0 999"};
				_expected = 179.81995685471114;
				_received = _obj.expectedRuns(vector <string>(stats, stats+sizeof(stats)/sizeof(string))); break;
			}
			case 2:
			{
				string stats[] = {"0 0 1000 0 0 0",
				                  "0 0 1000 0 0 0",
				                  "0 0 1000 0 0 0",
				                  "0 0 1000 0 0 0",
				                  "0 0 1000 0 0 0",
				                  "0 0 1000 0 0 0",
				                  "0 0 1000 0 0 0",
				                  "0 0 1000 0 0 0",
				                  "0 0 1000 0 0 0"};
				_expected = 162.0;
				_received = _obj.expectedRuns(vector <string>(stats, stats+sizeof(stats)/sizeof(string))); break;
			}
			case 3:
			{
				string stats[] = {"0 0 1000 0 0 0",
				                  "0 0 0 1000 0 0",
				                  "0 0 1000 0 0 0",
				                  "0 0 0 1000 0 0",
				                  "0 0 1000 0 0 0",
				                  "0 0 0 1000 0 0",
				                  "0 0 1000 0 0 0",
				                  "0 0 0 1000 0 0",
				                  "1000 0 0 0 0 0"};
				_expected = 151.0;
				_received = _obj.expectedRuns(vector <string>(stats, stats+sizeof(stats)/sizeof(string))); break;
			}
			/*case 4:
			{
				string stats[] = ;
				_expected = ;
				_received = _obj.expectedRuns(vector <string>(stats, stats+sizeof(stats)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string stats[] = ;
				_expected = ;
				_received = _obj.expectedRuns(vector <string>(stats, stats+sizeof(stats)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string stats[] = ;
				_expected = ;
				_received = _obj.expectedRuns(vector <string>(stats, stats+sizeof(stats)/sizeof(string))); break;
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
