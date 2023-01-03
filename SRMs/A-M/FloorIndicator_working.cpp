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

class FloorIndicator {
 public:
  vector<int> getnumbers(const vector<string>& indicator) {
    int n = (indicator[0].size()+3)/4;
    vector<int> r;
    for (int i=0;i<n;i++) {
      int start = i*4;
      int mask = 0;
      for (int k=start;k<start+3;k++)
        for (int j=0;j<5;j++)
          if (indicator[j][k] == '#')
            mask |= (1<<((k-start)*5+j));
      r.push_back(mask);
    }
    return r;
  }
  double averageFloor(int N, vector <string> indicator) {
    N = N;
    vector<int> numbers = getnumbers(indicator);
    vector<int> digits(10,0);
    digits[0] = (1 << 0)+(1 << 1)+(1 << 2)+(1 << 3)+(1 << 4)+
                (1 << 5)+(1 << 9)+
                (1 << 10)+(1 << 11)+(1 << 12)+(1 << 13)+(1 << 14);
    digits[1] = (1 << 10)+(1 << 11)+(1 << 12)+(1 << 13)+(1 << 14);
    digits[2] = (1 << 0)+(1 << 2)+(1 << 3)+(1 << 4)+
        (1 << 5)+(1 << 7)+(1 << 9)+
        (1 << 10)+(1 << 11)+(1 << 12)+(1 << 14);
    digits[3] = (1 << 0)+(1 << 2)+(1 << 4)+
        (1 << 5)+(1 << 7)+(1 << 9)+
        (1 << 10)+(1 << 11)+(1 << 12)+(1 << 13)+(1 << 14);
    digits[4] = (1 << 0)+(1 << 1)+(1 << 2)+
        (1 << 7)+
        (1 << 10)+(1 << 11)+(1 << 12)+(1 << 13)+(1 << 14);
    digits[5] = (1 << 0)+(1 << 1)+(1 << 2)+(1 << 4)+
        (1 << 5)+(1 << 7)+(1 << 9)+
        (1 << 10)+(1 << 12)+(1 << 13)+(1 << 14);
    digits[6] = (1 << 0)+(1 << 1)+(1 << 2)+(1 << 3)+(1 << 4)+
        (1 << 5)+(1 << 7)+(1 << 9)+
        (1 << 10)+(1 << 12)+(1 << 13)+(1 << 14);
    digits[7] = (1 << 0)+
        (1 << 5)+
        (1 << 10)+(1 << 11)+(1 << 12)+(1 << 13)+(1 << 14);
    digits[8] = (1 << 0)+(1 << 1)+(1 << 2)+(1 << 3)+(1 << 4)+
        (1 << 5)+(1 << 7)+(1 << 9)+
        (1 << 10)+(1 << 11)+(1 << 12)+(1 << 13)+(1 << 14);
    digits[9] = (1 << 0)+(1 << 1)+(1 << 2)+(1 << 4)+
        (1 << 5)+(1 << 7)+(1 << 9)+
        (1 << 10)+(1 << 11)+(1 << 12)+(1 << 13)+(1 << 14);
    double r = 0;
    int factor = 1;
    for (int i=numbers.size()-1;i>=0;i--) {
      int c = 0;
      int t = 0;
      for (int j=0;j<digits.size();j++)
        if ((digits[j]&numbers[i]) == numbers[i]) {
          c++;
          t+=j;
        }
      if (!c) return -1;
      double averagedig = (double)t/c;
      r += averagedig*factor;
      factor *= 10;
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
