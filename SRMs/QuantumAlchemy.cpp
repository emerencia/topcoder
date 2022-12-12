#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <set>
#include <utility>
using namespace std;

class QuantumAlchemy {
 public:
  int minSteps(string initial, vector <string> reactions) {
    vector<string> reacts(26,"");
    for (int i=0;i<reactions.size();i++) {
      reacts[reactions[i][reactions[i].size()-1]-'A'] = reactions[i].substr(0,reactions[i].size()-3);
    }
    vector<int> have(26,0);
    vector<int> need(26,0);
    need[23]=1;
    for (int i=0;i<initial.size();i++)
      have[initial[i]-'A']++;
    for (int step=0;step<200;step++) {
      for (int i=0;i<need.size();i++)
        if (need[i] > have[i] && reacts[i] == "") return -1;
      bool f = true;
      for (int i=0;i<need.size();i++) {
        if (need[i] > have[i]) {
          need[i]--;
          string ing = reacts[i];
          for (int j=0;j<ing.size();j++) {
            need[ing[j]-'A']++;
          }
          f = false;
          break;
        }
      }
      if (f) return step;
    }
    return -1;
  }
  

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
