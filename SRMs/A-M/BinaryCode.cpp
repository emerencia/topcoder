#include <vector>
#include <string>
#include <sstream>

class BinaryCode {
  public:
  std::vector<std::string> decode (std::string message) {
    std::vector<std::string> r;
    
    int p[50];
    p[0] = 0;
    if (message.at(0)-'0' > 1) { r.push_back("NONE");}
    else {
    bool goodflag = true;
    std::string strr = "0";
    for (int i = 0;i+1 < message.length();++i) {
      int qi = message.at(i)-'0';
      p[i+1] = qi;
      p[i+1] -= p[i];
      if (i > 0) {
        p[i+1] -= p[i-1];
      }
      if (p[i+1] != 0 && p[i+1] != 1) {
        r.push_back("NONE");
        goodflag = false;
        break;
      }
      strr += p[i+1]+'0';
    }
    if (goodflag) {
      int lasttwop = p[message.length()-1];
      if (message.length() > 1) {
        lasttwop += p[message.length()-2];
      }
      if (message.at(message.length()-1)-'0' != lasttwop) {
        r.push_back("NONE");
      } else { r.push_back(strr); }
    }
    }
    
    int pp[50];
    pp[0] = 1;
    if (message.at(0)-'0' > 2) { r.push_back("NONE");}
    else {
    bool goodflag = true;
    std::string strr = "1";
    for (int i = 0;i+1 < message.length();++i) {
      int qi = message.at(i)-'0';
      pp[i+1] = qi;
      pp[i+1] -= pp[i];
      if (i > 0) {
        pp[i+1] -= pp[i-1];
      }
      if (pp[i+1] != 0 && pp[i+1] != 1) {
        r.push_back("NONE");
        goodflag = false;
        break;
      }
      strr += pp[i+1]+'0';
    }
    if (goodflag) {
      int lasttwop = pp[message.length()-1];
      if (message.length() > 1) {
        lasttwop += pp[message.length()-2];
      }
      if (message.at(message.length()-1)-'0' != lasttwop) {
        r.push_back("NONE");
      } else { r.push_back(strr); }
    }
    }
    return r;
  }
};
