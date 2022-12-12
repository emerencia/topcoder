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
string digits[] = {
  "###...#.###.###.#.#.###.###.###.###.###",
  "#.#...#...#...#.#.#.#...#.....#.#.#.#.#",
  "#.#...#.###.###.###.###.###...#.###.###",
  "#.#...#.#.....#...#...#.#.#...#.#.#...#",
  "###...#.###.###...#.###.###...#.###.###"};

class FloorIndicator {
 public:
  pair<double,bool> calc(const vector<string>& dig) {
    int t = 0;
    int c = 0;
    for (int i=0;i<10;i++) {
      bool good = true;
      for (int j=0;j<3;j++)
        for (int k=0;k<5;k++)
          if (dig[k][j] == '#' && digits[k][j+i*4] == '.')
            good = false;
      if (good) {
        t+=i;
        c++;
      }
    }
    if (!c) return pair<double,bool>(0,false);
    return pair<double,bool>((double)t/c,true);
  }
  double averageFloor(int N, vector <string> indicator) {
    int n = (indicator[0].size()+3)/4;
    double r = 0;
    for (int i = 0;i<n;i++) {
      vector<string> dig;
      for (int j=0;j<5;j++)
        dig.push_back(indicator[j].substr(i*4,3));
      pair<double,bool> a = calc(dig);
      if (!a.second) return -1;
      r+=pow(10,N-i-1)*a.first;
    }
    return r;
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
		cout << "Testing FloorIndicator (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392406094;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		FloorIndicator _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 1;
				string indicator[] = {"###",
				                      "#.#",
				                      "###",
				                      "#.#",
				                      "###"};
				_expected = 8.0;
				_received = _obj.averageFloor(N, vector <string>(indicator, indicator+sizeof(indicator)/sizeof(string))); break;
			}
			case 1:
			{
				int N = 2;
				string indicator[] = {"###.###",
				                      "#.#.#.#",
				                      "#.#.###",
				                      "#.#...#",
				                      "###.###"};
				_expected = 48.5;
				_received = _obj.averageFloor(N, vector <string>(indicator, indicator+sizeof(indicator)/sizeof(string))); break;
			}
			case 2:
			{
				int N = 2;
				string indicator[] = {".......",
				                      ".......",
				                      ".......",
				                      ".......",
				                      "......."};
				_expected = 49.5;
				_received = _obj.averageFloor(N, vector <string>(indicator, indicator+sizeof(indicator)/sizeof(string))); break;
			}
			case 3:
			{
				int N = 1;
				string indicator[] = {"...",
				                      ".#.",
				                      "...",
				                      "...",
				                      "..."};
				_expected = -1.0;
				_received = _obj.averageFloor(N, vector <string>(indicator, indicator+sizeof(indicator)/sizeof(string))); break;
			}
			/*case 4:
			{
				int N = ;
				string indicator[] = ;
				_expected = ;
				_received = _obj.averageFloor(N, vector <string>(indicator, indicator+sizeof(indicator)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				int N = ;
				string indicator[] = ;
				_expected = ;
				_received = _obj.averageFloor(N, vector <string>(indicator, indicator+sizeof(indicator)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int N = ;
				string indicator[] = ;
				_expected = ;
				_received = _obj.averageFloor(N, vector <string>(indicator, indicator+sizeof(indicator)/sizeof(string))); break;
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
