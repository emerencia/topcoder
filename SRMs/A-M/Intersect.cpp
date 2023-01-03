#include <vector>
#include <cmath>
using namespace std;

class Intersect {
  public:
  
  int area(vector<int> x, vector<int> y) {
    int rxmin = min(x[0],x[1]);
    int rxmax = max(x[0],x[1]);
    int rymin = min(y[0],y[1]);
    int rymax = max(y[0],y[1]);
    for (int i = 2;i <x.size();i+=2) {
       int nxmin = min(x[i],x[i+1]);
       int nxmax = max(x[i],x[i+1]);
       int nymin = min(y[i],y[i+1]);
       int nymax = max(y[i],y[i+1]);
       rxmin = max(nxmin,rxmin);
       rxmax = min(nxmax,rxmax);
       rymin = max(nymin,rymin);
       rymax = min(nymax,rymax);
       if (rxmax <= rxmin || rymax <= rymin) { return 0;}
    }
    return (rxmax-rxmin)*(rymax-rymin);
  }

};
