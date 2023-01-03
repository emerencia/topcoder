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

class BadNeighbors {
 public:
  int maxDonations(vector <int> donations) {
    if (donations.size() == 2) return max(donations[0],donations[1]);
    int dp[2][2][41];
    memset(dp,0,sizeof(dp));
    int n = donations.size();
    dp[0][0][0] = 0;
    dp[0][1][0] = donations[0];
    dp[1][0][0] = donations[n-1];
    dp[1][1][0] = donations[n-1];
    for (int k=0;k<2;k++)
      for (int i=0;i+1<n;i++)
        for (int j=0;j<i;j++) {
          dp[k][0][i] = max(dp[k][0][i],max(dp[k][0][j],dp[k][1][j]));
          if (k == 1 && i+2 == n) continue;
          if (j+1 != i) {
            dp[k][1][i] = max(dp[k][1][i],donations[i]+max(dp[k][1][j],dp[k][0][j]));
          } else {
            dp[k][1][i] = max(dp[k][1][i],donations[i]+dp[k][0][j]);
          }
        }
    return max(max(dp[0][0][n-2],dp[0][1][n-2]),max(dp[1][0][n-2],dp[1][1][n-2]));
  }
  

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
