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
typedef pair<PII,int> PIII;
// BEGIN CUT HERE
const int tt = -1;
// start at midnight for real
// 00:34 done
// 00:53 done with debugging and correct submission
// END CUT HERE
const int INF = 1e6;
int seen[51][51];
int mem[1<<16][17];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

class Gifts {
 public:
  int kingx, kingy, queenx, queeny;
  vector<PII> gifts;
  vector<string> city;
  vector<int> kingdist;
  vector<int> queendist;
  vector<vector<int> > giftdist;
  int bitcount(int n) {
    int r = 0;
    for (int i=n;i;i&=i-1) ++r;
    return r;
  }
  int bfs(int i1, int j1, int i2, int j2) {
    fill(&seen[0][0],&seen[51][0],INF);
    seen[i1][j1] = 0;
    queue<PIII> q;
    q.push(PIII(PII(i1,j1),0));
    while (!q.empty()) {
      PIII pp = q.front(); q.pop();
      PII p = pp.first;
      int dist = pp.second;
      if (dist != seen[p.first][p.second]) continue;
      for (int k=0;k<4;k++) {
        int ni = p.first+dx[k];
        int nj = p.second+dy[k];
        if (ni >= 0 && ni < city.size() && nj >= 0 && nj < city[0].size() 
            && city[ni][nj] != '#' && dist+1 < seen[ni][nj]) {
          seen[ni][nj] = dist+1;
          q.push(PIII(PII(ni,nj),dist+1));
        }
      }
    }
    return seen[i2][j2];
  }
  int maxGifts(vector <string> city, int T) {
    if (T >= INF) T = INF-1;
    this->city = city;
    memset(seen,0,sizeof(seen));
    gifts.clear();
    for (int i=0;i<city.size();i++)
      for (int j=0;j<city[0].size();j++) {
        if (city[i][j] == 'K') {
          kingx = i;
          kingy = j;
        } else if (city[i][j] == 'Q') {
          queenx = i;
          queeny = j;
        } else if (city[i][j] == 'G') {
          gifts.push_back(PII(i,j));
        }
      }
    // calculate king and queen distances
    kingdist.clear();
    queendist.clear();
    for (int i=0;i<gifts.size();i++) {
      kingdist.push_back(bfs(kingx,kingy,gifts[i].first,gifts[i].second));
      queendist.push_back(bfs(gifts[i].first,gifts[i].second,queenx,queeny));
    }
    // calculate distances between gifts
    giftdist = vector<vector<int> >(gifts.size(),vector<int>(gifts.size(),INF));
    for (int i=0;i<gifts.size();i++) {
      giftdist[i][i] = 0;
      for (int j=i+1;j<gifts.size();j++) {
        int dist = bfs(gifts[i].first,gifts[i].second,gifts[j].first,gifts[j].second);
        giftdist[i][j] = dist;
        giftdist[j][i] = dist;
      }
    }
    // calc mindist
    memset(mem,-1,sizeof(mem));
    int n = gifts.size();
    int r = 0;
    for (int i=0;i<n;i++) {
      mem[1<<i][i] = kingdist[i];
      if (1 > r && 2*queendist[i]+kingdist[i] <= T)
        r = 1;
    }
    for (int i=0;i<(1<<n);i++) {
      for (int j=0;j<n;j++) {
        if (!(i&(1<<j)) || mem[i][j] == -1) continue;
        for (int k=0;k<n;k++) {
          if (i&(1<<k)) continue;
          int ntime = (bitcount(i)+1)*giftdist[j][k] + mem[i][j];
          if (mem[i|(1<<k)][k] == -1 || mem[i|(1<<k)][k] > ntime) {
            mem[i|(1<<k)][k] = ntime;
            int nrgifts = bitcount(i|(1<<k));
            if (nrgifts > r && (nrgifts+1)*queendist[k]+ntime <= T)
              r = nrgifts;
          }
        }
      }
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
	string a = tt == -1 ? "0" : string(1,'0'+tt);
	char* b[2] = {argv[0],(char*)a.c_str()};
	if(tt!=-1){argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing Gifts (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1407531571;
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
		Gifts _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string city[] = {"#######",
				                 "#K.G.Q#",
				                 "#######"};
				int T = 6;
				_expected = 1;
				_received = _obj.maxGifts(vector <string>(city, city+sizeof(city)/sizeof(string)), T); break;
			}
			case 1:
			{
				string city[] = {"#######",
				                 "#K.G.Q#",
				                 "#######"};
				int T = 4;
				_expected = 0;
				_received = _obj.maxGifts(vector <string>(city, city+sizeof(city)/sizeof(string)), T); break;
			}
			case 2:
			{
				string city[] = {"#######",
				                 "#K.Q.G#",
				                 "#######"};
				int T = 6;
				_expected = 0;
				_received = _obj.maxGifts(vector <string>(city, city+sizeof(city)/sizeof(string)), T); break;
			}
			case 3:
			{
				string city[] = {"#######",
				                 "#K.Q.G#",
				                 "#######"};
				int T = 8;
				_expected = 1;
				_received = _obj.maxGifts(vector <string>(city, city+sizeof(city)/sizeof(string)), T); break;
			}
			case 4:
			{
				string city[] = {"#######",
				                 "#K.QGG#",
				                 "#######"};
				int T = 9;
				_expected = 2;
				_received = _obj.maxGifts(vector <string>(city, city+sizeof(city)/sizeof(string)), T); break;
			}
			case 5:
			{
				string city[] = {"#....G#", 
				                 "###G###", 
				                 "#K...Q#", 
				                 "###.###", 
				                 "#G..GG#"};
				int T = 50;
				_expected = 4;
				_received = _obj.maxGifts(vector <string>(city, city+sizeof(city)/sizeof(string)), T); break;
			}
			/*case 6:
			{
				string city[] = ;
				int T = ;
				_expected = ;
				_received = _obj.maxGifts(vector <string>(city, city+sizeof(city)/sizeof(string)), T); break;
			}*/
			/*case 7:
			{
				string city[] = ;
				int T = ;
				_expected = ;
				_received = _obj.maxGifts(vector <string>(city, city+sizeof(city)/sizeof(string)), T); break;
			}*/
			/*case 8:
			{
				string city[] = ;
				int T = ;
				_expected = ;
				_received = _obj.maxGifts(vector <string>(city, city+sizeof(city)/sizeof(string)), T); break;
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
