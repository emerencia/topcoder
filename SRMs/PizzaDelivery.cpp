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
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

class PizzaDelivery {
 public:
  vector<string> terrain;
  vector<int> dists;
  int is_possible(char a, char b) {
    if (a == '$' || b == '$') return 2;
    if (a == 'X' || b == 'X') return 2;
    if (abs((int)a-(int)b) == 0) return 1;
    if (abs((int)a-(int)b) == 1) return 3;
    return 0;
  }
  int deliverAll(vector <string> terrain) {
    this->terrain = terrain;
    int sx = 0, sy = 0;
    for (int i=0;i<terrain.size();i++)
      for (int j=0;j<terrain[0].size();j++)
        if (terrain[i][j] == 'X') {
          sx = i;
          sy = j;
        }
    vector<vector<int> > seen(terrain.size(),vector<int>(terrain[0].size(),-1));
    queue<PII> q;
    queue<int> q2;
    q.push(PII(sx,sy));
    q2.push(0);
    seen[sx][sy] = 0;
    while (!q.empty()) {
      PII p = q.front();
      q.pop();
      int cost = q2.front();
      q2.pop();
      if (cost != seen[p.first][p.second]) continue;
      for (int k=0;k<4;k++) {
        int ni = p.first+dx[k];
        int nj = p.second+dy[k];
        if (ni >= 0 && ni < terrain.size() && nj >= 0 && nj < terrain[0].size()) {
          int dist = is_possible(terrain[p.first][p.second],terrain[ni][nj]);
          if (dist && (seen[ni][nj] == -1 || seen[ni][nj] > cost+dist)) {
            seen[ni][nj] = cost+dist;
            q.push(PII(ni,nj));
            q2.push(cost+dist);
          }
        }
      }
    }
    dists.clear();
    for (int i=0;i<terrain.size();i++) {
      for (int j=0;j<terrain[0].size();j++) {
        if (terrain[i][j] != '$') continue;
        if (seen[i][j] == -1) return -1;
        dists.push_back(seen[i][j]);
      }
    }
    sort(dists.begin(),dists.end());
    if (dists.size() == 0) return 0;
    if (dists.size() == 1) return dists[0];
    vector<int> sdists(1<<dists.size());
    for (int i=0;i<(1<<dists.size());i++) {
      int tottime = 0;
      int lasttime = 0;
      for (int k=0;k<dists.size();k++) {
        if (i&(1<<k)) {
          tottime += 2*dists[k];
          lasttime = dists[k];
        }
      }
      if (lasttime) tottime -= lasttime;
      sdists[i] = tottime;
    }
    int r = INT_MAX;
    for (int i=0;i<(1<<dists.size());i++) {
      int ni = ((1<<dists.size())-1)&(~i);
      r = min(r,max(sdists[i],sdists[ni]));
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
	char* b[2];
	if(tt!=-1){b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing PizzaDelivery (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397744017;
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
		PizzaDelivery _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string terrain[] = {"3442211",
				                    "34$221X",
				                    "3442211"};
				_expected = 8;
				_received = _obj.deliverAll(vector <string>(terrain, terrain+sizeof(terrain)/sizeof(string))); break;
			}
			case 1:
			{
				string terrain[] = {"001000$",
				                    "$010X0$",
				                    "0010000"};
				_expected = 13;
				_received = _obj.deliverAll(vector <string>(terrain, terrain+sizeof(terrain)/sizeof(string))); break;
			}
			case 2:
			{
				string terrain[] = {"001000$",
				                    "$010X0$",
				                    "0010000",
				                    "2232222",
				                    "2222222",
				                    "111$111"};
				_expected = -1;
				_received = _obj.deliverAll(vector <string>(terrain, terrain+sizeof(terrain)/sizeof(string))); break;
			}
			case 3:
			{
				string terrain[] = {"001000$",
				                    "$010X0$",
				                    "0010000",
				                    "1232222",
				                    "2222222",
				                    "111$111"};
				_expected = 28;
				_received = _obj.deliverAll(vector <string>(terrain, terrain+sizeof(terrain)/sizeof(string))); break;
			}
			case 4:
			{
				string terrain[] = {"X$$",
				                    "$$$"};
				_expected = 14;
				_received = _obj.deliverAll(vector <string>(terrain, terrain+sizeof(terrain)/sizeof(string))); break;
			}
			case 5:
			{
				string terrain[] = {"5433321123442201000000001100223222221134433323554", "0013333323555677788877755446766766554555455533334", "1123335545445676667788787766678999987665566666766", "9999977767766777777555556655555554565444534444555", "8665678786543312221233333100000012211223322333200", "33210000000000$0010122221233332332122000000000000", "311112231112111113345445779988X886887777788898999", "3232201100234344443444423355788999888766666667889", "3343322234565544335766765444445554667999998787777", "4555542000012333455445554468999978888877899988887", "5544445555566776666678777777877555566533353344444", "3333333334544333444311012344467765655444443222333", "3333334566578766788664455332232222243322223322344", "0111110000112233355554557777677888877654310120133", "120000102212$565554433333222222222433333444554321", "5455555553335566545553323222233233433333322222011", "4433343344322222000011112222344532223333555556666", "4566764444423320010000110112333433346799999898986", "666022222223442244434544555444665556776666433$466", "8998766667777767777766665566665466642356668776668", "776766779889999$98899999889988$887899999977777654", "6665543445665334555666666667544434444545311112$44", "6664678889999999$$8978777998877888899986665566787", "7678998899988878998999788999899999998879998888777", "6666667789999999999998755555554455444545555432334", "3201133334446665676666677756667766664454332223344", "3333344453311334433344667777653334454566899777778", "6777789886667877755444444444442132344566788878988"};
				_expected = 1202;
				_received = _obj.deliverAll(vector <string>(terrain, terrain+sizeof(terrain)/sizeof(string))); break;
			}
			/*case 6:
			{
				string terrain[] = ;
				_expected = ;
				_received = _obj.deliverAll(vector <string>(terrain, terrain+sizeof(terrain)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string terrain[] = ;
				_expected = ;
				_received = _obj.deliverAll(vector <string>(terrain, terrain+sizeof(terrain)/sizeof(string))); break;
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
