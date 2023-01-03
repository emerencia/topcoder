#include <string>
#include <sstream>
using namespace std;

class Substitute {
  public:
  int getValue(string key, string code) {
    string r("");
    for (int i = 0;i < code.length();++i) {
      if (key.find(code.at(i)) != -1) {
        if (key.find(code.at(i)) == 9) { r += '0'; }
        else { 
          char c = '0'+ (key.find(code.at(i))+1);
          r+=c;
        }
      }
    }
    int rr;
    stringstream(r) >> rr;
    return rr;
  }
};
