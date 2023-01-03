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
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE
bool g[201][201];
int seen[201];
int parent[201];

void reset(int n) {
  for (int i=0;i<=n;i++)
    parent[i]=i;
}
int find(int u) {
  if (u==parent[u])
    return u;
  else
    return parent[u]=find(parent[u]);
}
void merge(int a,int b) {
  int pa=find(a);
  int pb=find(b);
  if (pa != pb)
    parent[pa]=pb;
}

class CactusCount {
 public:
  int timesarrivedat;
  void dfs(int cur, int start, int prev, const vector<int>& nodes, const vector<bool>& valid) {
    if (cur == start) { 
      timesarrivedat++;
      return;
    }
    if (seen[cur]) return;
    seen[cur] = 1;
    for (int i=0;i<nodes.size();i++) {
      if (!valid[i] || !g[nodes[cur]][nodes[i]] || i == prev) continue;
      dfs(i,start,cur,nodes,valid);
    }
  }
  bool isvertexcactus(const vector<int>& nodes) {
    if (nodes.size() < 4) return 1;
    vector<int> degree(nodes.size(),-1);
    vector<bool> valid(nodes.size(),true);
    
    while (true) {
      vector<int> newdegree(nodes.size(),-1);
      for (int i=0;i<nodes.size();i++) {
        int c = 0;
        for (int j=0;j<nodes.size();j++) {
          if (!valid[j]) continue;
          c+=g[nodes[i]][nodes[j]];
        }
        newdegree[i] = c;
      }
      for (int i=0;i<valid.size();i++)
        valid[i] = newdegree[i] >= 2;
      if (newdegree == degree) break;
      degree.swap(newdegree);
    }
    
    for (int i=0;i<valid.size();i++) {
      if (!valid[i]) continue;
      memset(seen,0,sizeof(seen));
      timesarrivedat = 0;
      for (int j=0;j<valid.size();j++) {
        if (!valid[j] || !g[nodes[i]][nodes[j]] || seen[j]) continue;
        dfs(j,i,i,nodes,valid);
      }
      if (timesarrivedat > 1) return false;
    }
    return true;
  }
  int countCacti(int n, vector <string> edges) {
    if (edges.size() == 0) return n;
    memset(g,0,sizeof(g));
    string e = accumulate(edges.begin(),edges.end(),string(""));
    e+=',';
    string con;
    reset(n);
    for (int i=0;i<e.size();i++) {
      if (e[i] != ',') {
        con+= e[i];
        continue;
      }
      stringstream a(con);
      int b,c;
      a >> b >> c;
      g[b-1][c-1] = 1; 
      g[c-1][b-1] = 1;
      merge(b-1,c-1);
      con.clear();
    }
    map<int,vector<int> > components;
    for (int i=0;i<n;i++) {
      int component = find(i);
      if (!components.count(component))
         components[component] = vector<int>();       
      components[component].push_back(i);
    }
    //cout << "connected components: " << components.size();
    int r = 0;
    for (map<int,vector<int> >::iterator i = components.begin();i!=components.end();i++)
      r+=isvertexcactus(i->second);
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
	if(tt!=-1){char* b[2];b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}	if (argc == 1) 
	{
		cout << "Testing CactusCount (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392056512;
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
		CactusCount _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				string edges[] = {"1 2,1 3,2 3"};
				_expected = 1;
				_received = _obj.countCacti(n, vector <string>(edges, edges+sizeof(edges)/sizeof(string))); break;
			}
			case 1:
			{
				int n = 10;
				string edges[] = {};
				_expected = 10;
				_received = _obj.countCacti(n, vector <string>(edges, edges+sizeof(edges)/sizeof(string))); break;
			}
			case 2:
			{
				int n = 5;
				string edges[] = {"1 2,3 4,4 5"};
				_expected = 2;
				_received = _obj.countCacti(n, vector <string>(edges, edges+sizeof(edges)/sizeof(string))); break;
			}
			case 3:
			{
				int n = 17;
				string edges[] = {"1 2,2 3,3 4,4 5,5 3,1 3,6 7,7 8,6 8,8 9,9 1",
				                  "0,10 11,11 9,12 13,14 15,15 16,16 17,14 17,14 16"};
				_expected = 2;
				_received = _obj.countCacti(n, vector <string>(edges, edges+sizeof(edges)/sizeof(string))); break;
			}
			/*case 4:
			{
				int n = ;
				string edges[] = ;
				_expected = ;
				_received = _obj.countCacti(n, vector <string>(edges, edges+sizeof(edges)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				int n = ;
				string edges[] = ;
				_expected = ;
				_received = _obj.countCacti(n, vector <string>(edges, edges+sizeof(edges)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int n = ;
				string edges[] = ;
				_expected = ;
				_received = _obj.countCacti(n, vector <string>(edges, edges+sizeof(edges)/sizeof(string))); break;
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
