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
typedef long long LL;
typedef pair<int, int> PII;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE

class PowerOfThree {
 public:

  bool isthreepower(int x) {
    while (x) {
      if (x % 3) return false;
      x /= 3;
    }
    return true;
  }

  string ableToGet(int x, int y) {
    // to save us the issue of dealing with the % operation being flawed with
    // negative numbers, we can just use some symmetry, 
    // (x,y) is reachable if and only if (-x,y), (-x,-y) and (x,-y) are.
    x = abs(x);
    y = abs(y);
    while (x != 0 || y != 0) {
      // one of x,y must be a multiple of 3, the other shouldn't.
      // x and y are sums of powers of 3:
      // x = 3^1 + 3^2 + 3^4
      // y = 3^3 + 3^5
      // at every step, all powers lower by 1
      // so in the next step:
      // x = 3^0 + 3^1 + 3^3
      // y = 3^2 + 3^4
      // in every step one of the powers has to become zero
      // so that we know we don't skip steps
      // the one that became zero is 1 or 2 mod 3 the other is 0 mod 3
      // done
      if ((x % 3 == 0) && (y % 3 != 0)) {
        // If y % 3 == 2, the result is y/3 + 1 or (y+1) / 3.
        if (y % 3 == 2) {
          y = (y + 1) / 3;
        } else {
          y = (y - 1) / 3;
        }
        x /= 3;
      } else if ((y % 3 == 0) && (x % 3 != 0)) {
        if (x % 3 == 2) {
          x = (x + 1) / 3;
        } else {
          x = (x - 1) / 3;
        }
        y /= 3;
      } else {
        return "Impossible";
      }
    }
    return "Possible";
  }
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
  if (tt != -1) {
    char* b[2];
    b[1] = (char*) string(1, '0' + tt).c_str();
    b[0] = argv[0];
    argc = 2;
    argv = b;
  }
  if (argc == 1) {
    cout << "Testing PowerOfThree (250.0 points)" << endl << endl;
    for (int i = 0; i < 20; i++) {
      ostringstream s;
      s << argv[0] << " " << i;
      int exitCode = system(s.str().c_str());
      if (exitCode)
        cout << "#" << i << ": Runtime Error" << endl;
    }
    int T = time(NULL) - 1390304172;
    double PT = T / 60.0, TT = 75.0;
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout << endl;
    cout << "Time  : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score : " << 250.0 * (.3 + (.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
  } else {
    int _tc;
    istringstream(argv[1]) >> _tc;
    PowerOfThree _obj;
    string _expected, _received;
    time_t _start = clock();
    switch (_tc) {
      case 0:
      {
        int x = 1;
        int y = 3;
        _expected = "Possible";
        _received = _obj.ableToGet(x, y);
        break;
      }
      case 1:
      {
        int x = 0;
        int y = 2;
        _expected = "Possible";
        _received = _obj.ableToGet(x, y);
        break;
      }
      case 2:
      {
        int x = 1;
        int y = 9;
        _expected = "Impossible";
        _received = _obj.ableToGet(x, y);
        break;
      }
      case 3:
      {
        int x = 3;
        int y = 0;
        _expected = "Impossible";
        _received = _obj.ableToGet(x, y);
        break;
      }
      case 4:
      {
        int x = 1;
        int y = 1;
        _expected = "Impossible";
        _received = _obj.ableToGet(x, y);
        break;
      }
      case 5:
      {
        int x = -6890;
        int y = 18252;
        _expected = "Possible";
        _received = _obj.ableToGet(x, y);
        break;
      }
      case 6:
      {
        int x = 1000000000;
        int y = -1000000000;
        _expected = "Impossible";
        _received = _obj.ableToGet(x, y);
        break;
      }
      case 7:
      {
        int x = 0;
        int y = 0;
        _expected = "Possible";
        _received = _obj.ableToGet(x, y);
        break;
      }
        /*case 8:
        {
          int x = ;
          int y = ;
          _expected = ;
          _received = _obj.ableToGet(x, y); break;
        }*/
        /*case 9:
        {
          int x = ;
          int y = ;
          _expected = ;
          _received = _obj.ableToGet(x, y); break;
        }*/
        /*case 10:
        {
          int x = ;
          int y = ;
          _expected = ;
          _received = _obj.ableToGet(x, y); break;
        }*/
      default: return 0;
    }
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    double _elapsed = (double) (clock() - _start) / CLOCKS_PER_SEC;
    if (_received == _expected)
      cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
    else {
      cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
      cout << "           Expected: " << "\"" << _expected << "\"" << endl;
      cout << "           Received: " << "\"" << _received << "\"" << endl;
    }
  }
}

// END CUT HERE
