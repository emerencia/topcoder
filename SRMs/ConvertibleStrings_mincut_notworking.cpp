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
// 01:47-02:03
// END CUT HERE

int g[9][9];

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

class ConvertibleStrings {
 public:
  int leastRemovals(string A, string B) {
    memset(g,0,sizeof(g));
    for (int i=0;i<A.size();i++)
      g[A[i]-'A'][B[i]-'A']++;
    int n = 9;
    int FALSE = 2*n;
    int TRUE = 2*n+1;
    int INF = 1000000;
    NetworkFlow* f = new NetworkFlow(2*n+2);
    string ua = A;
    sort(ua.begin(),ua.end());
    ua.resize(unique(ua.begin(),ua.end())-ua.begin());
    string ub = B;
    sort(ub.begin(),ub.end());
    ub.resize(unique(ub.begin(),ub.end())-ub.begin());
    for (int i=0;i<ua.size();i++)
      f->addEdge(FALSE,ua[i]-'A',INF);
    for (int i=0;i<ub.size();i++)
      f->addEdge(n+ub[i]-'A',TRUE,INF);
    for (int i=0;i<9;i++)
      for (int j=0;j<9;j++) {
        if (!g[i][j]) continue;
        f->addEdge(i,j+n,1);
      }
    return f->maxFlow(FALSE,TRUE);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "DD"; string Arg1 = "FF"; int Arg2 = 0; verify_case(0, Arg2, leastRemovals(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "AAAA"; string Arg1 = "ABCD"; int Arg2 = 3; verify_case(1, Arg2, leastRemovals(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "AAIAIA"; string Arg1 = "BCDBEE"; int Arg2 = 3; verify_case(2, Arg2, leastRemovals(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ABACDCECDCDAAABBFBEHBDFDDHHD"; string Arg1 = "GBGCDCECDCHAAIBBFHEBBDFHHHHE"; int Arg2 = 9; verify_case(3, Arg2, leastRemovals(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ConvertibleStrings ___test;
  ___test.run_test(toTest);
}
// END CUT HERE
