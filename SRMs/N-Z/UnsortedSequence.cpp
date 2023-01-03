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
using namespace std;

class UnsortedSequence {
 public:
  vector <int> getUnsorted(vector <int> s) {
    sort(s.begin(),s.end());
    vector<int> r = s;
    int d=s.back();
    int di = s.size()-1;
    for (int i=s.size()-2;i>=0;i--) {
      if (s[i] == d) di--;
      else if (s[i] < d) {
        swap(r[i],r[di]);
        return r;
      }
    }
    return vector<int>();
  }
  

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
