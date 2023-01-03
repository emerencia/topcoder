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
int mem[31][31];
const int INF = 1e6;

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

class GoodCompanyDivOne {
 public:
  vector<int> superior,training;
  int rec(int idx, int p) {
    int& r = mem[idx][p];
    if (r != -1) return r;
    if (idx == superior.size()) return r = 0;
    // get people in segment
    vector<int> indices(1,idx);
    for (int i=0;i<superior.size();i++)
      if (superior[i] == idx)
        indices.push_back(i);
    vector<vector<int> > costs(indices.size(),vector<int>(training.size(),0));
    // calculate costs for current object
    // given that it already has a skill p
    costs[0][p] = INF;
    for (int i=0;i<training.size();i++) {
      if (i == p) continue;
      costs[0][i] = training[i];
      costs[0][p] = min(costs[0][p],training[i]); // minimum training that isn't p
    }
    // calculate costs for other objects
    for (int i=1;i<indices.size();i++)
      for (int j=0;j<training.size();j++)
        costs[i][j] = rec(indices[i],j);
    // is it then simply i+j?
    Network* f = new Network(indices.size()+training.size());
    int o = indices.size();
    for (int i=0;i<indices.size();i++)
      f->addEdge(f->src,i,1);
    for (int i=0;i<training.size();i++)
      f->addEdge(o+i,f->dest,1);
    for (int i=0;i<indices.size();i++)
      for (int j=0;j<training.size();j++)
        f->addEdge(i,o+j,1,costs[i][j]);
    int cost,flow;
    f->minCostMaxFlow(cost,flow);
    delete f;
    int t = 0;
    if (flow != indices.size())
      t = INF;
    else
      t = cost + training[p];
    return r = t;
  }
  int minimumCost(vector <int> superior, vector <int> training) {
    sort(training.begin(),training.end());
    this->superior = superior;
    this->training = training;
    vector<int> counts(superior.size(),1);
    for (int i=0;i<superior.size();i++)
      if (superior[i] != -1)
        counts[superior[i]]++;
    sort(counts.rbegin(),counts.rend());
    if (counts[0] > training.size())
      return -1;
    int m = INT_MAX;
    memset(mem,-1,sizeof(mem));
    for (int i=0;i<training.size();i++)
      m = min(m,rec(0,i));
    return m;
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
		cout << "Testing GoodCompanyDivOne (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1400535348;
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
		GoodCompanyDivOne _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int superior[] = {-1};
				int training[] = {1, 2};
				_expected = 3;
				_received = _obj.minimumCost(vector <int>(superior, superior+sizeof(superior)/sizeof(int)), vector <int>(training, training+sizeof(training)/sizeof(int))); break;
			}
			case 1:
			{
				int superior[] = {-1, 0, 0};
				int training[] = {1, 2, 3};
				_expected = 10;
				_received = _obj.minimumCost(vector <int>(superior, superior+sizeof(superior)/sizeof(int)), vector <int>(training, training+sizeof(training)/sizeof(int))); break;
			}
			case 2:
			{
				int superior[] = {-1, 0, 0, 0};
				int training[] = {1, 2, 3};
				_expected = -1;
				_received = _obj.minimumCost(vector <int>(superior, superior+sizeof(superior)/sizeof(int)), vector <int>(training, training+sizeof(training)/sizeof(int))); break;
			}
			case 3:
			{
				int superior[] = {-1, 0, 0, 2, 2, 2, 1, 1, 6, 0, 5, 4, 11, 10, 3, 6, 11, 7, 0, 2, 13, 14, 2, 10, 9, 11, 22, 10, 3};
				int training[] = {4, 2, 6, 6, 8, 3, 3, 1, 1, 5, 8, 6, 8, 2, 4};
				_expected = 71;
				_received = _obj.minimumCost(vector <int>(superior, superior+sizeof(superior)/sizeof(int)), vector <int>(training, training+sizeof(training)/sizeof(int))); break;
			}
			/*case 4:
			{
				int superior[] = ;
				int training[] = ;
				_expected = ;
				_received = _obj.minimumCost(vector <int>(superior, superior+sizeof(superior)/sizeof(int)), vector <int>(training, training+sizeof(training)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int superior[] = ;
				int training[] = ;
				_expected = ;
				_received = _obj.minimumCost(vector <int>(superior, superior+sizeof(superior)/sizeof(int)), vector <int>(training, training+sizeof(training)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int superior[] = ;
				int training[] = ;
				_expected = ;
				_received = _obj.minimumCost(vector <int>(superior, superior+sizeof(superior)/sizeof(int)), vector <int>(training, training+sizeof(training)/sizeof(int))); break;
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
