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
typedef pair<int,int> PII;
typedef long long LL;
// BEGIN CUT HERE
const int toTest = -1;
// 00:54 reading
// 01:10 start imp
// 01:38 done imp (44 min)
// 02:14 done fixes (another 36 min)
// END CUT HERE

int dx[] = {0,-1,1,0};
int dy[] = {-1,0,0,1};

const int maxn=100000+5; 
const int maxm=100000+5; 
const int oo=1000000000; 

int node,nedge,src,dest; 
int head[maxn],point[maxm],next[maxm],flow[maxm],capa[maxm],cost[maxm]; 
int dist[maxn],expand[maxn],prev[maxn],edge[maxn]; 
bool changed[maxn]; 

void init(int _node,int _src,int _dest) 
{ 
  node=_node; 
  src=_src; 
  dest=_dest; 
  nedge=0; 
  for (int i=0;i<node;i++) head[i]=-1; 
} 
void addedge(int u,int v,int c,int w) 
{ 
  point[nedge]=v,capa[nedge]=c,cost[nedge]=+w,flow[nedge]=0,next[nedge]=head[u],head[u]=(nedge++); 
  point[nedge]=u,capa[nedge]=0,cost[nedge]=-w,flow[nedge]=0,next[nedge]=head[v],head[v]=(nedge++); 
} 
void ford(int &mflow,int &mcost) 
{ 
  mflow=mcost=0; 
  while (1) 
  { 
    for (int i=0;i<node;i++) dist[i]=oo,prev[i]=-1,changed[i]=false; 
    dist[src]=0; 
    changed[src]=true; 
    expand[src]=oo; 
    while (1) 
    { 
      bool ok=true; 
      for (int i=0;i<node;i++) if (changed[i]) 
      { 
        changed[i]=false; 
        for (int k=head[i];k>=0;k=next[k]) 
          if (flow[k]<capa[k] && dist[i]+cost[k]<dist[point[k]]) 
          { 
            dist[point[k]]=dist[i]+cost[k]; 
            changed[point[k]]=true; 
            prev[point[k]]=i; 
            edge[point[k]]=k; 
            expand[point[k]]=min(expand[i],capa[k]-flow[k]); 
            ok=false; 
          } 
      } 
      if (ok) break; 
    } 
    if (prev[dest]<0) break; 
    int d=expand[dest]; 
    mflow+=d; 
    mcost+=d*dist[dest]; 
    for (int k=dest;k!=src;k=prev[k]) 
    { 
      flow[edge[k]]+=d; 
      flow[edge[k]^1]-=d; 
    } 
  } 
}

class FoxAndGo3 {
 public:
  vector<vector<bool> > g;
  int maxEmptyCells(vector <string> board) {
    int n = board.size();
    vector<vector<int> > indices(n,vector<int>(n,0));
    int whitecount = 0;
    int emptycount = 0;
    for (int i=0;i<n;i++)
      for (int j=0;j<n;j++) {
        if (board[i][j] == '.') {
          indices[i][j] = emptycount++;
        } else if (board[i][j] == 'o') {
          indices[i][j] = whitecount++;
        }
      }
    g = vector<vector<bool> >(whitecount,vector<bool>(emptycount,false));
    
    //NetworkFlow* f = new NetworkFlow(whitecount+emptycount+2);
    int SOURCE = whitecount+emptycount;
    int SINK = whitecount+emptycount+1;
    init(whitecount+emptycount+2,SOURCE,SINK);
    for (int i=0;i<whitecount;i++) {
      //f->addEdge(SOURCE,i,1);
      addedge(SOURCE,i,1,0);
    }
    for (int i=0;i<emptycount;i++) {
      // f->addEdge(i+whitecount,SINK,1);
      addedge(i+whitecount,SINK,1,0);
    }
    for (int i=0;i<n;i++)
      for (int j=0;j<n;j++) {
        if (board[i][j] != 'o') continue;
        for (int k=0;k<4;k++) {
          int ni = i+dx[k];
          int nj = j+dy[k];
          if (ni >= 0 && ni < n && nj >= 0 && nj < n && board[ni][nj] == '.') {
            //f->addEdge(indices[i][j],whitecount+indices[ni][nj],100000);
            addedge(indices[i][j],whitecount+indices[ni][nj],1,1);
            //g[indices[i][j]][indices[ni][nj]] = 1;
          }
        }
      }
    //return whitecount+emptycount-f->maxFlow(SOURCE,SINK);
    int c1,c2;
    ford(c1,c2);
    return whitecount+emptycount-c1;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"o.o",
 ".o.",
 "o.o"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, maxEmptyCells(Arg0)); }
	void test_case_1() { string Arr0[] = {"...",
 ".o.",
 "..."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, maxEmptyCells(Arg0)); }
	void test_case_2() { string Arr0[] = {"xxxxx",
 "xxoxx",
 "xo.ox",
 "xxoxx",
 "xxxxx"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, maxEmptyCells(Arg0)); }
	void test_case_3() { string Arr0[] = {".xox.",
 ".o.ox",
 "x.o.o",
 "ox.ox",
 ".ox.."}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(3, Arg1, maxEmptyCells(Arg0)); }
	void test_case_4() { string Arr0[] = {"o.o.o",
 ".ox..",
 "oxxxo",
 "..x..",
 "o.o.o"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(4, Arg1, maxEmptyCells(Arg0)); }
	void test_case_5() { string Arr0[] = {"...",
 "...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(5, Arg1, maxEmptyCells(Arg0)); }
  void test_case_6() { string Arr0[] = {".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o", "oxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxo.o.", ".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.oxo", "oxo.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.", ".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.oxo", "oxo.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.", ".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.oxo", "oxo.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.", ".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.oxo", "oxo.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.", ".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.oxo", "oxo.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.", ".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.oxo", "oxo.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.", ".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.oxo", "oxo.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.", ".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.oxo", "oxo.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.", ".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.oxo", "oxo.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.", ".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.oxo", "oxo.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.", ".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.oxo", "oxo.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.", ".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.oxo", "oxo.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.", ".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.oxo", "oxo.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.", ".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.oxo", "oxo.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.", ".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.oxo", "oxo.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.", ".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.oxo", "oxo.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.", ".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.oxo", "oxo.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.", ".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.oxo", "oxo.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.", ".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.oxo", "oxo.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.", ".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.oxo", "oxo.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.", ".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.oxo", "oxo.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.", ".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.oxo", "oxo.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.", ".o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.oxo", "oxo.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.", ".oxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxo", "o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o.o."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1250; verify_case(6, Arg1, maxEmptyCells(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  FoxAndGo3 ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
