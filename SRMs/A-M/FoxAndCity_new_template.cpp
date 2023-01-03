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
// 15:00-15:12-15:38
// END CUT HERE

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
void addedge(int u,int v,int c,int w=0) 
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


class FoxAndCity {
 public:
  int minimalCost(vector <string> linked, vector <int> want) {
    int n = linked.size();
    // add sink, source
    int TRUE  = n*n;
    int FALSE = n*n+1;
    // add edges
    //NetworkFlow* g = new NetworkFlow(n*n+2);
    init(n*n+2,FALSE,TRUE);
    int INF = 1000000;
    for (int i=0;i<n;i++) {
      int firstnode = i*n;
      int lastnode = firstnode+n-1;
      if (i == 0)
        //g->addEdge(FALSE,firstnode,0);  // only city 0 is allowed to have
        addedge(FALSE,firstnode,0);
      else // distance 0
        //g->addEdge(FALSE,firstnode,INF);
        addedge(FALSE,firstnode,INF);
      //g->addEdge(lastnode,TRUE,INF);    // cannot remove last edge
      addedge(lastnode,TRUE,INF);    // cannot remove last edge
      for (int j=1;j<n;j++) {
        int from = firstnode+j-1;
        int to = from+1;
        int weight = INF;
        if (i != 0) { // truth edges cannot be removed because the distance
                      // of city 0 HAS to be zero, which means for every
                      // distance j, dist[0] <= j
          weight = (want[i] - j)*(want[i] - j);
        }
        //g->addEdge(from,to,weight);
        addedge(from,to,weight);
      }
      for (int j=0;j<n;j++) { // side edges
        if (linked[i][j] == 'N') continue;
        for (int k = 1;k<n;k++)
          //g->addEdge(i*n+k,j*n+k-1,INF); // cannot be removed
          addedge(i*n+k,j*n+k-1,INF);
      }
    }
    //return g->maxFlow(FALSE,TRUE);
    int c1,c2;
    ford(c1,c2);
    return c1;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN",
 "YNY",
 "NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"NYNN",
 "YNYN",
 "NYNY",
 "NNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 3, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(1, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"NYNNNY",
 "YNYNNN",
 "NYNYNN",
 "NNYNYN",
 "NNNYNY",
 "YNNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 2, 2, 2, 2, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"NYY","YNN","YNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"NYNNNN",
 "YNYNNN",
 "NYNYYY",
 "NNYNYY",
 "NNYYNY",
 "NNYYYN"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3, 0, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(4, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"NYNNNN",
 "YNYNNN",
 "NYNYYY",
 "NNYNYY",
 "NNYYNY",
 "NNYYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 4, 0, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(5, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"NYNYYYYYYYY","YNYNNYYNYYY","NYNNNYYNYYN","YNNNYYYYYYY","YNNYNYYYNYY","YYYYYNNYYNY","YYYYYNNNYYY","YNNYYYNNNYY","YYYYNYYNNNY","YYYYYNYYNNY","YYNYYYYYYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,0,0,5,1,3,0,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 28; verify_case(6, Arg2, minimalCost(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  FoxAndCity ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
