#line 89 "ImprovingStatistics.cpp"
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
class ImprovingStatistics {
	public:
	int howManyGames(int played, int won) {
	  int perc = won*100.0/played;
	  cout << perc << endl;
	  if (perc >= 99) return -1;
      double a = ceil((played*(perc+1) - 100*won)*1.0/(99 - perc));
      return int(a);
	}
};


// Powered by FileEdit


// Powered by FileEdit


// Powered by FileEdit


// Powered by FileEdit


// Powered by FileEdit
