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
int g[51][51];

class MaxMinTreeGame {
 public:
  vector<int> costs;
  vector<int> edges;
  vector<bool> isdiscardednode;
  int dfsmincost(int cur, int prev) {
    int mincost = costs[cur];
    for (int i=0;i<costs.size();i++) {
      if (!g[cur][i] || i == prev || isdiscardednode[i]) continue;
      mincost = min(mincost,dfsmincost(i,cur));
    }
    return mincost;
  }
  int dfsmaxcost(int cur, int prev) {
    int maxcost = costs[cur];
    for (int i=0;i<costs.size();i++) {
      if (!g[cur][i] || i == prev || isdiscardednode[i]) continue;
      maxcost = max(maxcost,dfsmaxcost(i,cur));
    }
    return maxcost;
  }
  void dfsinvalidate(int cur, int prev) {
    isdiscardednode[cur] = true;
    for (int i=0;i<costs.size();i++) {
      if (!g[cur][i] || i == prev || isdiscardednode[i]) continue;
      dfsinvalidate(i,cur);
    }
  }
  int recmin() {
    int goodnodes = 0;
    int mincost = INT_MAX;
    for (int i=0;i<isdiscardednode.size();i++)
      if (!isdiscardednode[i]) {
        ++goodnodes;
        mincost = min(mincost,costs[i]);
      }
    if (goodnodes <= 2) return mincost;
    double curmin = INT_MAX;
    int node1 = -1,node2 = -1;
    for (int i=0;i<edges.size();i++) {
      int nodea = i+1;
      int nodeb = edges[i];
      if (isdiscardednode[nodea] || isdiscardednode[nodeb]) continue;
      double t = dfsmaxcost(nodea,nodeb);
      if (t < curmin) {
        curmin = t;
        node1 = nodea;
        node2 = nodeb;
      }
      t = dfsmaxcost(nodeb,nodea);
      if (t < curmin) {
        curmin = t;
        node1 = nodeb;
        node2 = nodea;
      }
    }
    if (node1 == -1) {
      cout << "You did something wrong1" << endl;
      return 0;
    }
    dfsinvalidate(node2,node1);
    return recmax();
  }
  int recmax() {
    int goodnodes = 0;
    int maxcost = 0;
    for (int i=0;i<isdiscardednode.size();i++)
      if (!isdiscardednode[i]) {
        ++goodnodes;
        maxcost = max(maxcost,costs[i]);
      }
    if (goodnodes <= 2) return maxcost;
    double curmax = -1;
    int node1 = -1,node2 = -1;
    for (int i=0;i<edges.size();i++) {
      int nodea = i+1;
      int nodeb = edges[i];
      if (isdiscardednode[nodea] || isdiscardednode[nodeb]) continue;
      double t = dfsmincost(nodea,nodeb);
      if (t > curmax) {
        curmax = t;
        node1 = nodea;
        node2 = nodeb;
      }
      t = dfsmincost(nodeb,nodea);
      if (t > curmax) {
        curmax = t;
        node1 = nodeb;
        node2 = nodea;
      }
    }
    if (node1 == -1) {
      cout << "You did something wrong2" << endl;
      return 0;
    }
    dfsinvalidate(node2,node1); // invalidate the other side
    return recmin();
  }
  int findend(vector <int> edges, vector <int> costs) {
    memset(g,0,sizeof(g));
    this->edges = edges;
    this->costs = costs;
    for (int i=0;i<edges.size();i++) {
      g[i+1][edges[i]] = 1;
      g[edges[i]][i+1] = 1;
    }
    isdiscardednode = vector<bool>(costs.size(),false);
    return recmax();
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
		cout << "Testing MaxMinTreeGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393338588;
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
		MaxMinTreeGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int edges[] = {0};
				int costs[] = {4,6};
				_expected = 6;
				_received = _obj.findend(vector <int>(edges, edges+sizeof(edges)/sizeof(int)), vector <int>(costs, costs+sizeof(costs)/sizeof(int))); break;
			}
			case 1:
			{
				int edges[] = {0,1};
				int costs[] = {4,6,5};
				_expected = 5;
				_received = _obj.findend(vector <int>(edges, edges+sizeof(edges)/sizeof(int)), vector <int>(costs, costs+sizeof(costs)/sizeof(int))); break;
			}
			case 2:
			{
				int edges[] = {0,1,2,3};
				int costs[] = {0,1,0,1,0};
				_expected = 0;
				_received = _obj.findend(vector <int>(edges, edges+sizeof(edges)/sizeof(int)), vector <int>(costs, costs+sizeof(costs)/sizeof(int))); break;
			}
			case 3:
			{
				int edges[] = {0,0,0};
				int costs[] = {5,1,2,3};
				_expected = 3;
				_received = _obj.findend(vector <int>(edges, edges+sizeof(edges)/sizeof(int)), vector <int>(costs, costs+sizeof(costs)/sizeof(int))); break;
			}
			case 4:
			{
				int edges[] = {0,0};
				int costs[] = {3,2,5};
				_expected = 5;
				_received = _obj.findend(vector <int>(edges, edges+sizeof(edges)/sizeof(int)), vector <int>(costs, costs+sizeof(costs)/sizeof(int))); break;
			}
			/*case 5:
			{
				int edges[] = ;
				int costs[] = ;
				_expected = ;
				_received = _obj.findend(vector <int>(edges, edges+sizeof(edges)/sizeof(int)), vector <int>(costs, costs+sizeof(costs)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int edges[] = ;
				int costs[] = ;
				_expected = ;
				_received = _obj.findend(vector <int>(edges, edges+sizeof(edges)/sizeof(int)), vector <int>(costs, costs+sizeof(costs)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int edges[] = ;
				int costs[] = ;
				_expected = ;
				_received = _obj.findend(vector <int>(edges, edges+sizeof(edges)/sizeof(int)), vector <int>(costs, costs+sizeof(costs)/sizeof(int))); break;
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
