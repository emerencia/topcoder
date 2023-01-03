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

class MallSecurity {
 public:
  vector<int> numStations;
  vector<vector<bool> > gg;
  int getPosition(int floor, int station) {
    // assume 1-indexed arguments
    floor--; station--;
    int r = station;
    for (int i=0;i<floor;i++)
      r+= numStations[i];
    return r;
  }
  int max_indep_set(int numStationsTot, int block) {    
    vector<int> leftpoints;
    vector<int> rightpoints;
    int subset = 0;
    for (int i=0;i<numStations.size();i++) {
      if (i == block) continue;
      subset = 1-subset;
      for (int j=0;j<numStations[i];j++) {
        if (subset%2) rightpoints.push_back(getPosition(i+1,j+1));
        else leftpoints.push_back(getPosition(i+1,j+1));
      }
    }
    Network* f = new Network(numStationsTot);
    int nl = leftpoints.size();
    int nr = rightpoints.size();
    for (int i=0;i<nl;i++)
      f->addEdge(f->src,i,1);
    for (int i=0;i<nr;i++)
      f->addEdge(nl+i,f->dest,1);
    for (int i=0;i<leftpoints.size();i++)
      for (int j=0;j<rightpoints.size();j++)
        if (gg[leftpoints[i]][rightpoints[j]])
          f->addEdge(i,nl+j,1);
    int cost,flow;
    f->minCostMaxFlow(cost,flow);
    delete f;
    return numStationsTot-flow;
  }
  int maxGuards(int N, vector <string> escDescription) {
    string s = accumulate(escDescription.begin(),escDescription.end(),string(""));
    vector<string> escs;
    int start = N;
    start = 0;
    while (s.find(',',start) != string::npos) {
      escs.push_back(s.substr(start,s.find(',',start)-start));
      start = s.find(',',start)+1;
    }
    escs.push_back(s.substr(start,s.find(',',start)-start));
    numStations = vector<int>(N,0);
    for (int i=0;i<escs.size();i++) {
      stringstream d(escs[i]);
      int a,b,c;
      d >> a >> b >> c;
      if (c == N) {
        numStations[c-1] = max(numStations[c-1],a);
        numStations[0] = max(numStations[0],b);
      } else {
        numStations[c-1] = max(numStations[c-1],a);
        numStations[c] = max(numStations[c],b);
      }
    }
    int numStationsTot = accumulate(numStations.begin(),numStations.end(),0);
    bool superexists = false;
    gg = vector<vector<bool> >(numStationsTot,vector<bool>(numStationsTot,false));
    for (int i=0;i<escs.size();i++) {
      stringstream d(escs[i]);
      int a,b,c;
      d >> a >> b >> c;
      int gpos1,gpos2;
      if (c == N) {
        superexists = true;
        gpos1 = getPosition(1,b);
        gpos2 = getPosition(N,a);
      } else {
        gpos1 = getPosition(c,a);
        gpos2 = getPosition(c+1,b);
      }
      gg[gpos1][gpos2] = 1;
      gg[gpos2][gpos1] = 1;
    }
    if (superexists && N%2) {
      int r = 0;
      for (int block=0;block<N;block++) {
        r = max(r,max_indep_set(numStationsTot-numStations[block],block));
      }
      return r;
    }
    return max_indep_set(numStationsTot,-1);
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
		cout << "Testing MallSecurity (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1407634538;
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
		MallSecurity _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 10;
				string escDescription[] = {"1 1 1,1 1 2,1 1 3,1 1 4,1 1 5,1 1 6,1 1 7,1 1 8,1 ", 
				                           "1 9,1 1 10"};
				_expected = 5;
				_received = _obj.maxGuards(N, vector <string>(escDescription, escDescription+sizeof(escDescription)/sizeof(string))); break;
			}
			case 1:
			{
				int N = 11;
				string escDescription[] = {"1 1 1,1 1 2,1 1 3,1 1 4,1 1 5,1 1 6,1 1 7,1 1 8,1 ", 
				                           "1 9,1 1 10"};
				_expected = 6;
				_received = _obj.maxGuards(N, vector <string>(escDescription, escDescription+sizeof(escDescription)/sizeof(string))); break;
			}
			case 2:
			{
				int N = 10;
				string escDescription[] = {"1 1 7,1 2 9,2 1", 
				                           " 8,1 2 6,1 1 8,1 2 3,1 2 2,2 ", 
				                           "2 4,1 1 1,2 1 2,3 2 3,1 1 5,2 1 1,4 ", 
				                           "1 7,1 1 10,3 2 5,1 2 5,3 3 1,", 
				                           "3 2 8,3 1 2,1 1 3,4 4 2,2", 
				                           " 4 6,4 2 5,2 3 3,6 4 1,5 2 8,1 3 6,1 3 7,", 
				                           "4 3 8,1 3 8,5 2 3,4 2 8,2 6 7,1 3 9,", 
				                           "1 1 4,6 1 1,2 3 1,5 1 5,6 1 8,5 ", 
				                           "2 2,3 2 10,3 3 9,1 5 2,4 1 1,1 5 10"};
				_expected = 25;
				_received = _obj.maxGuards(N, vector <string>(escDescription, escDescription+sizeof(escDescription)/sizeof(string))); break;
			}
			case 3:
			{
				int N = 11;
				string escDescription[] = {"6 8 11,6 9 4,9 4 10,7 3 2,3 5 8,5 8 10,8 5 3,2 4 2", ",9 4 1,6 1 7,3 8 11,3 7 9,1 3 11,8 4 5,9 5 4,7 9 2", ",2 9 4,3 1 8,9 1 4,9 5 11,9 1 1,8 7 6,7 3 10,4 1 8", ",7 5 2,8 8 4,2 5 4,8 5 2,8 7 9,2 2 2,7 9 4,1 2 6,7", " 4 7,1 3 7,8 8 10,3 2 2,3 1 4,6 5 10,4 2 1,5 1 5,7", " 5 3,5 3 2,7 4 9,7 1 3,8 9 2,5 1 3,9 7 9,1 4 8,2 4", " 8,2 2 7,9 6 10,6 6 5,3 5 4,1 9 9,6 1 8,7 2 6,9 4 ", "11,2 6 2,6 3 2,2 2 4,5 9 8,3 7 6,7 1 11,8 4 6,2 1 ", "7,1 3 1,2 1 6,2 1 5,6 9 1,2 7 2,8 8 5,9 8 10,9 9 6", ",3 4 7,7 1 6,4 2 10,9 6 2,4 5 7,1 7 7,1 9 2,4 4 5,", "5 1 6,6 4 11,2 4 6,7 3 8,1 6 5,7 7 11,4 4 2,6 2 2,", "9 6 3,5 4 5,9 6 4,1 1 1,8 6 6,2 1 8,9 7 4,8 1 1,5 ", "4 4,1 2 8,5 8 3,7 7 9,6 6 3,5 8 11,6 7 3,8 2 2,3 9", " 8,2 7 5,9 5 2,4 6 8,1 4 6,9 2 4,2 8 8,8 2 10,5 5 ", "9,2 9 10,9 5 9,1 7 11,2 5 2,9 5 1,9 6 5,7 8 8,8 9 ", "8,3 3 1,9 6 7,6 3 8,1 1 8,6 6 7,1 8 11,4 1 4,5 9 4", ",5 2 6,3 6 3,9 6 1,6 ", "5 6,1 3 9,8 3 9,3 7 11,4 4 8,2 1 1,6 3 3,2 4 4,9 7", " 7,5 6 3,3 4 6,4 8 5,4 6 4,4 6 11,6 3 4,1 5 2,3 6 ", "9,7 3 3,2 9 8,6 6 6,2 7 7,2 5 9,8 8 11,9 5 5,2 7 4", ",2 4 9,3 3 9,3 3 11,3 5 7,3 2 1,6 6 9,8 5 10,3 4 8", ",3 6 10,4 1 2,1 5 6,4 1 6,3 4 3,6 8 9,5 8 5,4 3 5,", "6 2 11,5 6 7,9 9 11,1 9 5,8 3 8,3 4 5,8 4 9,8 5 7,", "8 9 6,7 9 1,3 4 1,7 1 4,7 7 1,8 2 3,6 7 5,6 9 11,1", " 8 3,4 9 8,2 1 10,4 2 8,6 6 8,3 3 8,8 4 4,5 8 1,5 ", "3 9,8 2 4,1 4 5,7 9 8,4 5 4,1 7 6,3 9 6,3 2 6,2 5 ", "8,6 3 7,6 5 5,5 3 7,7 9 11,4 5 8,8 4 3,7 4 11,5 9 ", "5,2 6 8,5 6 8,8 7 3,5 7 3,5 2 3,8 2 9,3 7 3,8 3 5,", "6 5 2,8 4 1,5 4 8,8 9 3,1 7 9,5 3 8,7 2 5,8 6 9,7 ", "3 6,5 9 1,1 4 2,6 3 1,2 9 11,5 9 2,6 8 5,3 8 7,5 9", " 6,4 1 3,8 5 5,3 2 4,3 5 5,9 7 3,9 4 5,8 8 3,1 9 8", ",2 4 10,7 6 10,2 9 6,3 4 9,2 6 10,5 6 4,9 7 11,7 8", " 9,7 4 4,5 8 6,6 5 1,5 5 5,9 2 9,8 9 9,1 4 9,5 6 9", ",2 3 3,8 8 9,3 3 10,1 9 3,6 9 5,9 8 8,1 7 10,5 4 9"};
				_expected = 47;
				_received = _obj.maxGuards(N, vector <string>(escDescription, escDescription+sizeof(escDescription)/sizeof(string))); break;
			}
			/*case 4:
			{
				int N = ;
				string escDescription[] = ;
				_expected = ;
				_received = _obj.maxGuards(N, vector <string>(escDescription, escDescription+sizeof(escDescription)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				int N = ;
				string escDescription[] = ;
				_expected = ;
				_received = _obj.maxGuards(N, vector <string>(escDescription, escDescription+sizeof(escDescription)/sizeof(string))); break;
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
