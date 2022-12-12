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
#include <cstring>
using namespace std;

int dx[] = {0,1,1,0,-1,-1};
int dy[] = {-1,-1,0,1,1,0};

typedef pair<int,int> PII;

class HexagonalBoard {
 public:
  int minColors(vector <string> board) {
    int mx = 0;
    for (int i=0;i<board.size();i++)
      for (int j=0;j<board[0].size();j++) {
        if (board[i][j] == '-') continue;
        queue<PII> q;
        mx = max(mx,1);
        vector<vector<int> > seen(board.size(),vector<int>(board[0].size(),-1));
        seen[i][j] = 1;
        q.push(PII(i,j));
        while (!q.empty()) {
          PII p = q.front();
          q.pop();
          for (int k=0;k<6;k++) {
          if (p.first+dx[k] >= 0 && p.first+dx[k] < board.size() && p.second+dy[k] >= 0 && p.second+dy[k] < board[0].size() && board[p.first+dx[k]][p.second+dy[k]] == 'X') {
            PII o(p.first+dx[k],p.second+dy[k]);
            if (seen[o.first][o.second] == -1) {
              mx = 2;
              seen[o.first][o.second] = 1-seen[p.first][p.second];
              q.push(o);
            } else if (seen[o.first][o.second] == seen[p.first][p.second]) {
              return 3;
            }
          }
        }
       
        }
      }
    return mx;
  }
  

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
