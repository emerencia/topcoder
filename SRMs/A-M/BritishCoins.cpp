#include <vector>

using namespace std;
class BritishCoins {
  public:
  
  vector<int> coins(int pence) {
    vector<int> r;
    r.push_back(pence/(12*20));
    pence = pence%(12*20);
    r.push_back(pence/(12));
    pence = pence%(12);
    r.push_back(pence);
    return r;
  }
};
