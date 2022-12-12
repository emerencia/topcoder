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
typedef pair<int,int> PII;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE
map<string,double> mem;

class CrazyBot {
 public:
  int n;
  int east;
  int west;
  int north;
  int south;
  bool hascycle(const string& s) {
    int x = 0;
    int y = 0;
    set<PII> seen;
    seen.insert(PII(x,y));
    for (int i=0;i<s.size();i++) {
      if (s[i] == 'N') x++;
      if (s[i] == 'S') x--;
      if (s[i] == 'E') y++;
      if (s[i] == 'W') y--;
      if (seen.count(PII(x,y))) return true;
      seen.insert(PII(x,y));
    }
    return false;
  }
  double pathprob(const string& s) {
    if (!hascycle(s)) return 0;
    double probs = 0;
    for (int i=0;i<2;i++)
      for (int j=0;j<2;j++) {
        double prob = 1;
        for (int k=0;k<s.size();k++) {
          if (s[k] == 'N') prob *= (i == 0 ? north : south);
          if (s[k] == 'S') prob *= (i == 0 ? south : north);
          if (s[k] == 'W') prob *= (j == 0 ? west : east);
          if (s[k] == 'E') prob *= (j == 0 ? east : west);
        }
        probs+=prob/100.0;
      }
    return probs;
  }
  double rec(string& sofar) {
    if (mem.count(sofar)) return mem[sofar];
    if (sofar.size() == n)
      return mem[sofar] = pathprob(sofar);
    double t = 0;
    sofar+="E";
    t += rec(sofar);
    sofar.resize(sofar.size()-1);
    sofar+="N";
    t += rec(sofar);
    sofar.resize(sofar.size()-1);
    if (sofar.find('N') != string::npos) {
      sofar+="S";
      t += rec(sofar);
      sofar.resize(sofar.size()-1);
      sofar+="W";
      t += rec(sofar);
      sofar.resize(sofar.size()-1);
    }
    return mem[sofar] = t;
  }
  double getProbability(int n, int east, int west, int south, int north) {
    mem.clear();
    this->n = n;
    this->east = east;
    this->west = west;
    this->south = south;
    this->north = north;
    string a;
    return 1-rec(a);
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

int main(int argc, char* argv[])
{
	if(tt!=-1){char* b[2];b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}	if (argc == 1) 
	{
		cout << "Testing CrazyBot (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392819246;
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
		CrazyBot _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 1;
				int east = 25;
				int west = 25;
				int south = 25;
				int north = 25;
				_expected = 1.0;
				_received = _obj.getProbability(n, east, west, south, north); break;
			}
			case 1:
			{
				int n = 2;
				int east = 25;
				int west = 25;
				int south = 25;
				int north = 25;
				_expected = 0.75;
				_received = _obj.getProbability(n, east, west, south, north); break;
			}
			case 2:
			{
				int n = 7;
				int east = 50;
				int west = 0;
				int south = 0;
				int north = 50;
				_expected = 1.0;
				_received = _obj.getProbability(n, east, west, south, north); break;
			}
			case 3:
			{
				int n = 14;
				int east = 50;
				int west = 50;
				int south = 0;
				int north = 0;
				_expected = 1.220703125E-4;
				_received = _obj.getProbability(n, east, west, south, north); break;
			}
			case 4:
			{
				int n = 14;
				int east = 25;
				int west = 25;
				int south = 25;
				int north = 25;
				_expected = 0.008845493197441101;
				_received = _obj.getProbability(n, east, west, south, north); break;
			}
			/*case 5:
			{
				int n = ;
				int east = ;
				int west = ;
				int south = ;
				int north = ;
				_expected = ;
				_received = _obj.getProbability(n, east, west, south, north); break;
			}*/
			/*case 6:
			{
				int n = ;
				int east = ;
				int west = ;
				int south = ;
				int north = ;
				_expected = ;
				_received = _obj.getProbability(n, east, west, south, north); break;
			}*/
			/*case 7:
			{
				int n = ;
				int east = ;
				int west = ;
				int south = ;
				int north = ;
				_expected = ;
				_received = _obj.getProbability(n, east, west, south, north); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
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
