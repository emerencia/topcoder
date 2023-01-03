#include <vector>
#include <string>
#include <iostream>

using namespace std;

class QueenInterference {
  public:
  static long long ai;
  int myrand(int up) {
    int r = (ai % up)+1;
    ai = ( 16807 * ai ) % 2147483647;
    return r;
  }
  vector<string> getboard(vector<int> q) {
    vector<string> b;
    for (int i=0;i<q.size();++i) { b.push_back(string(q.size(),'.')); }
    for (int i=0;i<q.size();++i) {
      b[q[i]][i] = 'X';
    }
    return b;
  }
  void printboard(vector<int> q) {
    vector<string> b = getboard(q);
    for (int i=0;i<b.size();++i) {
      for (int j=0;j<b.size();++j) {
        cout << b[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }
  vector<int> reachable_queens(vector<int> q) {
    vector<int> rq;
    vector< vector<int> > r = reachability(q);
    for (int i=0;i<q.size();++i) {
      rq.push_back(r[q[i]][i]);
    }
    return rq;
  }
  vector< vector<int> > reachability(vector<int> q) {
    vector< vector<int> > r;
    vector<int> a(q.size(),0);
    for (int i=0;i<q.size();++i) { r.push_back(a); }
    for (int i=0;i<q.size();++i) {
      // mark right updir
      for (int row=q[i]-1,col=i+1;row >=0 && col <q.size();row--,col++) { r[row][col]++; }
      // mark left updir
      for (int row=q[i]-1,col=i-1;row >=0 && col >=0;row--,col--) { r[row][col]++; }
      // mark rightdir
      for (int row=q[i],col=i+1;col<q.size();++col) { r[row][col]++; }
      // mark leftdir
      for (int row=q[i],col=i-1;col>=0;--col) { r[row][col]++; }
      // mark right downdir
      for (int row=q[i]+1,col=i+1;row<q.size() && col < q.size();++row,++col) { r[row][col]++; }
      // mark left downdir
      for (int row=q[i]+1,col=i-1;row<q.size() && col >= 0;++row,--col) { r[row][col]++; }
    }
    return r;
  }
  bool at_least_two_queens_interfere(vector<int> q) {
    vector<string> b = getboard(q);
    for (int i=0;i<q.size();++i) {
      // check updir
      for (int j =i+1,row=q[i]-1;j<q.size() && row >= 0;++j,row--) {
        if (b[row][j] == 'X') { return true; }
      }
      // check rightdir
      for (int j =i+1;j<q.size();++j) {
        if (b[q[i]][j] == 'X') { return true; }
      }
      // check downdir
      for (int j=i+1,row=q[i]+1;j<q.size() && row < q.size();++j,++row) {
        if (b[row][j] == 'X') { return true; }
      }
    }
    return false;
  }
  vector<int> alteration_step(vector<int> q) {
    vector<int> nq = q;
    
    // compute T the number of columns containing reachable queens
    vector<int> rq = reachable_queens(q);
    int t = 0;
    for (int i=0;i<rq.size();++i) {
      if (rq[i] > 0) {
        t++;
      }
    }
    // choose K between 1 and T inclusive
    int k = myrand(t);
    /*
    cout << "t: " << t << endl;
    cout << "reachability: " << endl;
    vector< vector<int> > rr = reachability(q);
    for (int i=0;i<rr.size();++i) {
      for (int j=0;j<rr[i].size();++j) {
        cout << rr[i][j] << " ";
      }
      cout << endl;
    }
    cout << "K: " << k << endl;
    */
    // let c denote the kth column that contains a reachable queen
    int c = 0;
    for (int i=0;i<rq.size();++i) {
      if (rq[i] > 0) {
        c++;
        if (c == k) {
          c = i;
          break;
        }
      }
    }
    
    // for each of the n positions in column c, compute how many queens from other columns can currently reach that position
    vector< vector<int> > r = reachability(q);
    vector<int> ri;
    for (int i=0;i<r.size();++i) {
      ri.push_back(r[i][c]);
    }
    
    // move the queen in column c to the position in column c reachable by the fewest number of queens
    vector<int> minposi;
    int minpos=-1;
    for (int i=0;i<ri.size();++i) {
      if (minpos == -1 || ri[i] < minpos) {
        minposi.clear();
        minposi.push_back(i);
        minpos = ri[i];
      } else if (minpos == ri[i]) {
        minposi.push_back(i);
      }
    }
    // if multiple positions are tied, continue to step 5
    int minposii = 0;
    if (minposi.size() > 1) {
      // compute p, the number of positions that tied in step 4
      int p = minposi.size();
      // choose a random number q between 1 and p inclusive.
      int qq = myrand(p)-1;
      minposii = qq;
    }
    
    nq[c] = minposi[minposii];
    return nq;
  }
  int numSteps(int n) {
    ai = 1;
    vector<int> q;
    for (int i=0;i<n;++i) {
      q.push_back(myrand(n)-1);
    }
    int cnt = 0;
    while (at_least_two_queens_interfere(q)) {
      cout << "after step " << cnt << ":"<< endl;
      printboard(q);
      q = alteration_step(q);
      cnt++;
    }
    return cnt;
  }
};

long long QueenInterference::ai = 1;
