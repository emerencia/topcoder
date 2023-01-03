#include <string>
using namespace std;

class NoOrderOfOperations {

  public:
  int evaluate(string expr) {
    int r = 0;
    int op = -1;
    for (int i =0;i<expr.length();++i) {
      if (i%2 == 0) {
        // number
        int num = expr.at(i)-'0';
        switch (op) {
        case -1:
          r = num;
          break;
        case 0:
          r *= num;
          break;
        case 1:
          r -= num;
          break;
        case 2:
          r += num;
        }
      } else {
        if (expr.at(i) == '*') {
          op = 0;
        } else if (expr.at(i) == '-') {
          op = 1;
        } else if (expr.at(i) == '+') {
          op = 2;
        }
      }
    }
    return r;
  }
};
