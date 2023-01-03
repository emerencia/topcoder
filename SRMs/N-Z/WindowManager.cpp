#include <string>
#include <vector>
#include <sstream>
using namespace std;

class WindowManager {
  public:
  vector<string> screen(int height, int width, vector<string> windows) {
  
    // initialize empty screen
    vector<string> s;
    for (int i=0;i<height;++i) {
      s.push_back(string(width,' '));
    }
    
    // draw windows
    for (int i = 0;i<windows.size();++i) {
      int tlv,tlh,vs,hs;
      char fill;
      string ffill;
      stringstream a(windows[i]);
      a >> tlv;
      a >> tlh;
      a >> vs;
      a >> hs;
      a >> ffill;
      fill = ffill.at(0);
      for (int vi=0;vi<height;++vi) {
        int cv = vi - tlv;
        for (int hi=0;hi<width;++hi) {
          int ch = hi - tlh;
          if (cv >= 0 && cv < vs && ch >= 0 && ch < hs) {
            char c = fill;
            if (cv == 0 || cv+1 == vs) { c = '-'; }
            if (ch == 0 || ch+1 == hs) { c = '|'; }
            if ((cv == 0 || cv+1 == vs) && (ch == 0 || ch+1 == hs)) { c = '+'; }
            s.at(vi).at(hi) = c;
          }
        }
      }    
    }
    return s;
  }
};
