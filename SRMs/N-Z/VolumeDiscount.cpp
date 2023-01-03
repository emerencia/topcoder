#include <string>
#include <vector>
#include <sstream>
using namespace std;

class VolumeDiscount {
  public:
  int bestDeal(vector <string> priceList, int quantity) {
    int bd = -1;
    for (int i =0;i<priceList.size();++i) {
      stringstream a(priceList[i]);
      int amoun,price;
      a >> amoun >> price;
      int count = quantity/amoun;
      if (quantity%amoun != 0) {
        count+= 1;
      }
      int tots = count*price;
      if (bd == -1 || tots < bd) {
        bd = tots;
      }
    }
    return bd;
  }
};
