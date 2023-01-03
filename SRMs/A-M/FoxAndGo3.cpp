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
    NetworkFlow* f = new NetworkFlow(whitecount+emptycount+2);
    int SOURCE = whitecount+emptycount;
    int SINK = whitecount+emptycount+1;
    for (int i=0;i<whitecount;i++)
      f->addEdge(SOURCE,i,1);
    for (int i=0;i<emptycount;i++)
      f->addEdge(i+whitecount,SINK,1);
    for (int i=0;i<n;i++)
      for (int j=0;j<n;j++) {
        if (board[i][j] != 'o') continue;
        for (int k=0;k<4;k++) {
          int ni = i+dx[k];
          int nj = j+dy[k];
          if (ni >= 0 && ni < n && nj >= 0 && nj < n && board[ni][nj] == '.') {
            f->addEdge(indices[i][j],whitecount+indices[ni][nj],100000);
            //g[indices[i][j]][indices[ni][nj]] = 1;
          }
        }
      }
    return whitecount+emptycount-f->maxFlow(SOURCE,SINK);
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
