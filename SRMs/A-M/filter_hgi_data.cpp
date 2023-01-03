#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
  ifstream a("/Users/ando/Documents/autovar/data_in.txt");
  double ll = 0;
  int noobs = 0;
  int nopar = 0;
  while (a.good()) {
    string c;
    a >> c;
    if (c == "log-likelihood") {
      a >> ll;
    } else if (c == "observations") {
      a >> noobs;
    } else if (c == "parameters") {
      a >> nopar;
    }
  }
  a.close();
  if (ll == 0 || noobs == 0 || nopar == 0)
    cout << "warning: one of the parameters was empty: " << ll << noobs << nopar << endl;
  double bic = -2*ll + log(noobs)*nopar;
  cout << fixed << setprecision(3) << bic << "\\\\" << endl;
}
