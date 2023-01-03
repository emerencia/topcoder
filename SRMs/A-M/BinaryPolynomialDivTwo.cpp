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

class BinaryPolynomialDivTwo {
 public:
  int countRoots(vector <int> a) {
    int r = 0;
    for (int i=0;i<a.size();i++) r= (r+a[i])%2;
    int b = 0;
    if (r == 0) b++;
    if (a.size() == 0 || a[0] == 0) b++;
    return b;
  }
  

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
