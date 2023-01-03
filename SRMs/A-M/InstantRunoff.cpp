#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class InstantRunoff {
  public:
  string outcome(string candidates,vector<string> ballots) {
    if (candidates.length() == 0) { return ""; }
    int winsize = (ballots.size()/2)+1;
    int minnumfirsts = -1;
    vector<int> remidxs;
    for (int i=0;i<candidates.length();++i) {
      char candidate = candidates.at(i);
      int numfirst = 0;
      for (int j=0;j<ballots.size();++j) {
        if (ballots[j].find(candidate) == 0) {
          numfirst++;
        }
      }
      if (numfirst >= winsize) { return string(1,candidate); }
      if (minnumfirsts == -1 || numfirst < minnumfirsts) {
        minnumfirsts = numfirst;
        remidxs.clear();
        remidxs.push_back(i);
      } else if (numfirst == minnumfirsts) {
        remidxs.push_back(i);
      }
    }
    if (remidxs.size() == 0) { return ""; }
    //cout << "interm" << endl;
    string newcandidate(candidates);
    for (int i=0;i<remidxs.size();++i) {
      char candidate = candidates.at(remidxs[i]);
      newcandidate.erase(remove(newcandidate.begin(), newcandidate.end(), candidate), newcandidate.end());
      for (int i =0;i<ballots.size();++i) {
        ballots[i].erase(remove(ballots[i].begin(), ballots[i].end(), candidate), ballots[i].end());
      }
    }
    //cout << newcandidate << endl;
    return outcome(newcandidate,ballots);
  }
};
