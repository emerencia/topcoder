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
class FoxAndCity {
 public:
  int minimalCost(vector <string> linked, vector <int> want) {
    int n = linked.size();
    // add sink, source
    int TRUE  = n*n;
    int FALSE = n*n+1;
    // add edges
    NetworkFlow* g = new NetworkFlow(n*n+2);
    int INF = 1000000;
    for (int i=0;i<n;i++) {
      int firstnode = i*n;
      int lastnode = firstnode+n-1;
      if (i == 0)
        g->addEdge(FALSE,firstnode,0);  // only city 0 is allowed to have
      else                              // distance 0
        g->addEdge(FALSE,firstnode,INF);
      g->addEdge(lastnode,TRUE,INF);    // cannot remove last edge
      for (int j=1;j<n;j++) {
        int from = firstnode+j-1;
        int to = from+1;
        int weight = INF;
        if (i != 0) { // truth edges cannot be removed because the distance
                      // of city 0 HAS to be zero, which means for every
                      // distance j, dist[0] <= j
          weight = (want[i] - j)*(want[i] - j);
        }
        g->addEdge(from,to,weight);
      }
      for (int j=0;j<n;j++) { // side edges
        if (linked[i][j] == 'N') continue;
        for (int k = 1;k<n;k++)
          g->addEdge(i*n+k,j*n+k-1,INF); // cannot be removed
      }
    }
    return g->maxFlow(FALSE,TRUE);
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
