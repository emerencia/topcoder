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

struct NetworkFlow {
  typedef long long Weight;
  struct Edge {
    int to;
    Weight cap;
    Weight flow;
    unsigned next;
    Edge(int to, int cap, unsigned next = 0) : to(to), cap(cap), flow(0), next(next) {}
    inline Weight res() const { return cap - flow; }
  };
  int V;
  vector<unsigned> G;
  Weight totalFlow;
  vector<Edge> edges;
  NetworkFlow(int V) : V(V), G(V, ~0), totalFlow(0) {}
  void addEdge(int a, int b, int cab, int cba = 0) {
    edges.push_back(Edge(b,cab,G[a]));
    G[a] = edges.size()-1;
    edges.push_back(Edge(a,cba,G[b]));
    G[b] = edges.size()-1;
  }
  Weight pushFlow(int S, int T) {
    queue<int> q;
    q.push(S);
    vector<unsigned> pred(V,-1);
    while (!q.empty() && pred[T] == -1) {
      int u = q.front();
      q.pop();
      for (unsigned i = G[u]; i != ~0; i = edges[i].next) {
        Edge& e = edges[i];
        int v = e.to;
        if (e.res() > 0 && pred[v] == ~0 && v != S) {
          pred[v] = i;
          q.push(v);
        }
      }
    }
    if (pred[T] == -1) return 0;
    Weight amt = numeric_limits<Weight>::max();
    for (int v = T, u; pred[v] != ~0; v = u) {
      Edge& e = edges[pred[v]];
      Edge& rev = edges[pred[v] ^ 1];
      amt = min(amt,e.res());
      u = rev.to;
    }
    for (int v = T, u; pred[v] != ~0; v = u) {
      Edge& e = edges[pred[v]];
      Edge& rev = edges[pred[v] ^ 1];
      e.flow += amt;
      rev.flow -= amt;
      u = rev.to;
    }
    return amt;
  }
  Weight maxFlow(int S, int T) {
    totalFlow = 0;
    while(Weight f = pushFlow(S,T))
      totalFlow += f;
    return totalFlow;
  }
};

class DirectionBoard {
 public:
  int getMinimum(vector <string> board) {
    int n = board.size();
    int m = board[0].size();
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++) {
        if (board[i][j] == 'R') g[i][j] = 2;
        if (board[i][j] == 'D') g[i][j] = 3;
        if (board[i][j] == 'L') g[i][j] = 0;
        if (board[i][j] == 'U') g[i][j] = 1;
      }
    int TRUE = 2*n*m;
    int FALSE = TRUE+1;
    NetworkFlow* f = new NetworkFlow(FALSE+1);
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++) {
        f->addEdge(FALSE,i*m+j,1000000);
        f->addEdge(n*m+i*m+j,TRUE,1000000);
      }
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++) {
        for (int k=0;k<4;k++) {
          int ni = (i-dx[k]+n)%n;
          int nj = (j-dy[k]+m)%m;
          f->addEdge(i*m+j,n*m+ni*m+nj,g[i][j] == k ? 1000000  : 1);
        }
      }
    return f->maxFlow(FALSE,TRUE);
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
