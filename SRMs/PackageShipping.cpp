#include <string>
#include <iostream>
#include <iomanip>
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
typedef pair<string,int> PSI;

// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE
const int INF = 1e6;

class PackageShipping {
 public:
  struct Cost {
    static LL packageCost;
    LL acc;
    double p;
    Cost(LL acc, double p) : acc(acc), p(p) {}
    Cost() {}
    double calccost() const {
      return acc+p*packageCost;
    }
    bool operator<(const Cost& o) const {
      return calccost() > o.calccost();
    }
    /*
    bool operator>(const Cost& o) const {
      return !(*this < o || *this == o);
    }
    bool operator==(const Cost& o) const {
      if (acc != o.acc) return false;
      return abs(p-o.p) < 1e-9;
    }
    bool operator!=(const Cost& o) const {
      return !(*this == o);
    }
    */
  };
  typedef pair<Cost,PSI> CPSI;
  struct Route {
    string origin;
    string destination;
    int time;
    int cost;
    double prob;
  };
  vector<Route> getroutes(const vector<string>& routes) {
    vector<Route> r;
    for (int i=0;i<routes.size();i++) {
      stringstream a(routes[i]);
      string o,d;
      int t,c;
      double p;
      a >> o >> d >> t >> c >> p;
      p/=100;
      r.push_back((Route){o,d,t,c,p});
    }
    return r;
  }
  double ship(vector <string> routes, string origin, string destination, int time, int packageCost) {
    Cost::packageCost = packageCost;
    vector<Route> rts = getroutes(routes);
    set<PSI> seen;
    priority_queue<CPSI> q;
    q.push(CPSI(Cost(0,0),PSI(origin,0)));
    while (!q.empty()) {
      CPSI p2 = q.top();
      q.pop();
      Cost cst = p2.first;
      PSI p = p2.second;
      if (seen.count(p)) continue;
      if (p.first == destination)
        return cst.calccost();
      seen.insert(p);
      for (int i=0;i<rts.size();i++) {
        if (rts[i].origin != p.first) continue;
        int t = p.second+rts[i].time;
        if (t > time) continue;
        PSI pp(rts[i].destination,t);
        if (seen.count(pp)) continue;
        Cost c(cst.acc+rts[i].cost,1-(1-cst.p)*(1-rts[i].prob));
        q.push(CPSI(c,pp));
      }
    }
    return 0;
  }
};
LL PackageShipping::Cost::packageCost = 0;

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	char* b[2];
	if(tt!=-1){b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing PackageShipping (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398351744;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PackageShipping _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string routes[] = {"SANFRAN CHICAGO 20 3 0.4",
				                   "SANFRAN MEMPHIS 30 5 1.0",
				                   "CHICAGO NEWYORK 15 2 2.0",
				                   "MEMPHIS NEWYORK 8 6 0.1"};
				string origin = "SANFRAN";
				string destination = "NEWYORK";
				int time = 100;
				int packageCost = 100;
				_expected = 7.392000000000005;
				_received = _obj.ship(vector <string>(routes, routes+sizeof(routes)/sizeof(string)), origin, destination, time, packageCost); break;
			}
			case 1:
			{
				string routes[] = {"SANFRAN CHICAGO 20 3 0.4",
				                   "SANFRAN MEMPHIS 30 5 1.0",
				                   "CHICAGO NEWYORK 15 2 2.0",
				                   "MEMPHIS NEWYORK 8 6 0.1"};
				string origin = "SANFRAN";
				string destination = "NEWYORK";
				int time = 100;
				int packageCost = 10000;
				_expected = 120.90000000000055;
				_received = _obj.ship(vector <string>(routes, routes+sizeof(routes)/sizeof(string)), origin, destination, time, packageCost); break;
			}
			case 2:
			{
				string routes[] = {"SANFRAN CHICAGO 20 3 0.4",
				                   "SANFRAN MEMPHIS 30 5 1.0",
				                   "CHICAGO NEWYORK 15 2 2.0",
				                   "MEMPHIS NEWYORK 8 6 0.1"};
				string origin = "SANFRAN";
				string destination = "NEWYORK";
				int time = 36;
				int packageCost = 10000;
				_expected = 244.20000000000053;
				_received = _obj.ship(vector <string>(routes, routes+sizeof(routes)/sizeof(string)), origin, destination, time, packageCost); break;
			}
			/*case 3:
			{
				string routes[] = ;
				string origin = ;
				string destination = ;
				int time = ;
				int packageCost = ;
				_expected = ;
				_received = _obj.ship(vector <string>(routes, routes+sizeof(routes)/sizeof(string)), origin, destination, time, packageCost); break;
			}*/
			/*case 4:
			{
				string routes[] = ;
				string origin = ;
				string destination = ;
				int time = ;
				int packageCost = ;
				_expected = ;
				_received = _obj.ship(vector <string>(routes, routes+sizeof(routes)/sizeof(string)), origin, destination, time, packageCost); break;
			}*/
			/*case 5:
			{
				string routes[] = ;
				string origin = ;
				string destination = ;
				int time = ;
				int packageCost = ;
				_expected = ;
				_received = _obj.ship(vector <string>(routes, routes+sizeof(routes)/sizeof(string)), origin, destination, time, packageCost); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(3);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
