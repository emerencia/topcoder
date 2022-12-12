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

class EllysDirectoryListing {
 public:
  vector <string> getFiles(vector <string> files) {
    vector<string> r = files;
    if ((r.back() == "." || r.back() == "..") && 
        (r[r.size()-2] == "." || r[r.size()-2] == "..")) return r;
    for (int i=0;i<r.size();i++) {
      if (r[i] == "." || r[i] == "..") {
        swap(r[i],r.back());
        break;
      }
    }
    if ((r.back() == "." || r.back() == "..") && 
        (r[r.size()-2] == "." || r[r.size()-2] == "..")) return r;
    for (int i=0;i<r.size();i++) {
      if (r[i] == "." || r[i] == "..") {
        swap(r[i],r[r.size()-2]);
        break;
      }
    }
    return r;
  }
  

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
