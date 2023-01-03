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

struct Network {
  static const int maxn = 1e5+5;
  static const int maxm = 1e5+5;
  static const int oo = 1e9;
  static const int inf = 1e6;
  int node, nedge, src, dest;
  int head[maxn], point[maxm], next[maxm], flow[maxm], capa[maxm], cost[maxm];
  int dist[maxn], expand[maxn], prev[maxn], edge[maxn];
  bool changed[maxn];
  Network(int size) {
    node = size+2;
    src = size;
    dest = size+1;
    nedge = 0;
    for (int i=0;i<node;i++) head[i] = -1;
  }
  void addEdge(int u, int v, int c, int w = 0) {
    point[nedge] = v;
    capa[nedge] = c;
    cost[nedge] = +w;
    flow[nedge] = 0;
    next[nedge] = head[u];
    head[u] = (nedge++);
    point[nedge] = u;
    capa[nedge] = 0;
    cost[nedge] = -w;
    flow[nedge] = 0;
    next[nedge] = head[v];
    head[v] = (nedge++);
  }
  void minCostMaxFlow(int &mcost, int &mflow) {
    mflow = mcost = 0;
    while (1) {
      for (int i = 0; i < node; i++) {
        dist[i] = oo;
        prev[i] = -1;
        changed[i] = false;
      }
      dist[src] = 0;
      changed[src] = true;
      expand[src] = oo;
      while (1) {
        bool ok = true;
        for (int i = 0; i < node; i++)
          if (changed[i]) {
            changed[i] = false;
            for (int k = head[i]; k >= 0; k = next[k])
              if (flow[k] < capa[k] && dist[i] + cost[k] < dist[point[k]]) {
                dist[point[k]] = dist[i] + cost[k];
                changed[point[k]] = true;
                prev[point[k]] = i;
                edge[point[k]] = k;
                expand[point[k]] = min(expand[i], capa[k] - flow[k]);
                ok = false;
              }
          }
        if (ok) break;
      }
      if (prev[dest] < 0) break;
      int d = expand[dest];
      mflow += d;
      mcost += d * dist[dest];
      for (int k = dest; k != src; k = prev[k]) {
        flow[edge[k]] += d;
        flow[edge[k]^1] -= d;
      }
    }
  }
};

class ColorfulCoinsEasy {
 public:
  string isPossible(vector <int> values) {
    int max_divisor = 1;
    for (int i=0;i+1<values.size();i++)
      max_divisor = max(max_divisor, (values[i+1]/values[i]) -1);
    Network* f = new Network(values.size()+max_divisor);
    for (int i=0;i<values.size();i++)
      f->addEdge(f->src,i,1);
    for (int i=0;i<max_divisor;i++)
      f->addEdge(i+values.size(),f->dest,1);
    for (int i=0;i<values.size();i++) {
      int maxdiv = 0;
      if (i+1 == values.size())
        maxdiv = values.size()+1;
      else
       maxdiv = (values[i+1]/values[i]) -1;
      for (int j = 1; j <= maxdiv; j++)
        f->addEdge(i,values.size()+j-1,1);
    }
    int cost,flow;
    f->minCostMaxFlow(cost,flow);
    delete f;
    return flow >= values.size() ? "Possible" : "Impossible";
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
		cout << "Testing ColorfulCoinsEasy (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1428507256;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ColorfulCoinsEasy _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int values[] = {1};
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 1:
			{
				int values[] = {1, 3};
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 2:
			{
				int values[] = {1, 2, 4};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 3:
			{
				int values[] = {1, 5, 15, 90};
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 4:
			{
				int values[] = {1, 4, 20, 60, 180, 1440, 5760};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 5:
			{
				int values[] = {1, 7, 21, 105, 630, 3150, 18900};
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 6:
			{
				int values[] = {1, 10, 30, 300, 900, 9000, 18000};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 7:
			{
				int values[] = {1, 2, 10, 40, 200, 1000, 4000, 20000};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			/*case 8:
			{
				int values[] = ;
				_expected = ;
				_received = _obj.isPossible(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int values[] = ;
				_expected = ;
				_received = _obj.isPossible(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}*/
			/*case 10:
			{
				int values[] = ;
				_expected = ;
				_received = _obj.isPossible(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
