#include <vector>
#include <cmath>
using namespace std;

class PseudoPrimeTest {
  public:
  long mymodpower_aux(int b,int power,int q) {
    if (power == 0) { return 1%q; }
    if (power == 1) { return b%q; }
    long res = mymodpower_aux(b,power/2,q);
    res = (res*res)%q;
    if (power%2 == 1) {
      res = (res*b)%q;
    }
    return res;
  }
    
  long mymodpower(int b,int power,int q) {
    return mymodpower_aux(b,power,q);
  }
  int firstFail(int q) {
    for (int b = 2;b<q;++b) {
      long remain = mymodpower(b,q-1,q);
      if (remain != 1) { return b; }
    }
    return q;
  }
};
