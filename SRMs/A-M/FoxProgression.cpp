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

class FoxProgression {
 public:
  int theCount(vector <int> seq) {
    if (seq.size() == 1) return -1;
    int ar = -2000;
    int se = -2000;
    for (int i=1;i<seq.size();i++) {
      if ((ar == -2000 || ar == seq[i]/seq[i-1]) && seq[i]%seq[i-1] == 0 && seq[i]/seq[i-1] != 0)
        ar = seq[i]/seq[i-1];
      else
        ar = -1000;
      if (se == -2000 || se == seq[i]-seq[i-1])
        se = seq[i]-seq[i-1];
      else
        se = -1000;
    }
    int r = 2;
    int next = -1000;
    if (se == -1000 || se == -2000) r--;
    else next = seq.back()+se;
    if (ar == -1000 || ar == -2000) r--;
    if (ar != -1000 && ar != -2000 && next == seq.back()*ar) return 1;
    return r;
  }
  

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
