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
int g[16][16];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

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

class DirectionBoard {
 public:
  int getMinimum(vector <string> board) {
    int n = board.size();
    int m = board[0].size();
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++) {
        if (board[i][j] == 'R') g[i][j] = 0;
        if (board[i][j] == 'D') g[i][j] = 1;
        if (board[i][j] == 'L') g[i][j] = 2;
        if (board[i][j] == 'U') g[i][j] = 3;
      }
    Network* f = new Network(2*n*m);
    // it works like this:
    // in the valid matrix result, each cell has one incoming
    // and one outgoing edge.
    // thus, we have a network of double the nodes, where
    // each cell appears twice, once as a receiver, and once
    // as an originator of an edge
    // And there's your bipartite matching.
    // each originator is linked to all its receivers with
    // a flow of 1 and at the cost of 1 unless it is already
    // pointing that way
    // Since the flow is 1 everywhere, it is really about the min cost,
    // the minimum number of edges you can add.
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++) {
        f->addEdge(f->src,i*m+j,1);
        f->addEdge(n*m+i*m+j,f->dest,1);
      }
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++) {
        for (int k=0;k<4;k++) {
          int ni = (i+dx[k]+n)%n;
          int nj = (j+dy[k]+m)%m;
          f->addEdge(i*m+j,n*m+ni*m+nj,1,g[i][j] == k ? 0 : 1);
        }
      }
    int cost,flow;
    f->minCostMaxFlow(cost,flow);
    return cost;
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
		cout << "Testing DirectionBoard (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396732089;
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
		DirectionBoard _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"RRRD",
				                  "URDD",
				                  "UULD",
				                  "ULLL"};
				_expected = 0;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"RRRD",
				                  "URLL",
				                  "LRRR"};
				_expected = 2;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"RRD",
				                  "URD",
				                  "ULL"};
				_expected = 2;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"ULRLRD",
				                  "UDDLRR"};
				_expected = 4;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"UDLRLDLD",
				                  "DLDLLDLR",
				                  "LLLLLDLD",
				                  "UUURRRDD"};
				_expected = 9;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {"UDUDUUDUDUDUDUR",
				                  "LLLLDUUDRDLUDRU",
				                  "DLLDLDURDURUDDL",
				                  "UDUDUUDUDUDUDUR",
				                  "LLLLDUUDRDLUDRU",
				                  "DLLDLDURDURUDDL",
				                  "UDUDUUDUDUDUDUR",
				                  "LLLLDUUUDDLUDRU",
				                  "DLLDLDURDURUDDL",
				                  "UDUDUUDUDUDUDUR",
				                  "LLLLDUUDRDLUDRU",
				                  "DLLDLDURDURUDDL",
				                  "UDUDUUDUDUDUDUR",
				                  "LLLLDUUDRDLUDRU",
				                  "RRRDLDURDURUDDR"};
				_expected = 73;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 6:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
