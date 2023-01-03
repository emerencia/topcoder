#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <iostream>
// backtrackign since we can save money up
// best deal so far...

using namespace std;

class StockHistory {
  public:
  int maximumEarnings(int initialInvestment, int monthlyContribution, vector<string> stockPrices) {
    vector<int> endprices;
    stringstream aa(stockPrices[stockPrices.size()-1]);
    int spp;
    while (aa >> spp) { endprices.push_back(spp); }
    double beststockratio=0.0;
    int beststockprice = 0;
    int beststocki = 0;
    double earnings= 0.0;
    vector<double> stockbought;
    for(int i=0;i<endprices.size();++i) { stockbought.push_back(0.0); }
    for(int i=stockPrices.size()-1;i>=0;--i) {
      stringstream a(stockPrices[i]);
      int sp = 0;
      int j =0;
      while(a >> sp) {
        int endprice = endprices[j];
        double stockratio = double(endprice)/sp;
        if (stockratio > beststockratio) {
          // change best stock
          beststockratio = stockratio;
          beststockprice = sp;
          beststocki = j;
        }
        j++;
      }
      if (beststockratio > 1.0) {
        // buy best stock
        int amount = 0;
        if (i == 0) { amount = initialInvestment; }
        else { amount = monthlyContribution; }
        cout << "earnings-= " << amount << endl;
        earnings -= double(amount);
        stockbought[beststocki] += double(amount)/beststockprice;
      }
    }
    for (int i=0;i<endprices.size();++i) {
      cout << "earnings+= " << stockbought[i]*endprices[i] << endl;
      earnings += stockbought[i]*endprices[i];
    }
    return int(round(earnings));
  }
};
