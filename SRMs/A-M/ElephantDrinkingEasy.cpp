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

class ElephantDrinkingEasy {
 public:
  vector<string> map;
  int n;
  int bitcount(int n) {
    int r = 0;
    for (int i=n;i;i&=i-1) ++r;
    return r;
  }
  int rec(int used) {
    int r = 0;
    for (int i=0;i<n;i++) {
      // for each row try to get left most and rightmost
      for (int j=0;j<n;j++) {
        if (used&(1<<(n*i+j))) break;
        if (map[i][j] != 'Y') continue;
        r++;
        used|=(1<<(n*i+j));
        break;
      }
      for (int j=n-1;j>=0;j--) {
        if (used&(1<<(n*i+j))) break;
        if (map[i][j] != 'Y') continue;
        r++;
        used|=(1<<(n*i+j));
        break;
      }
    }
    return r;
  }
  int maxElephants(vector <string> map) {
    this->map = map;
    n = map.size();
    int r = 0;
    for (int i=0;i<(1<<(2*n));i++) {
      int used = 0;
      bool good = true;
      for (int j=0;j<2*n;j++) {
        if (!(i&(1<<j))) continue;
        int si = (j < n ? 0 : n-1);
        int sj = j%n;
        if (j < n) {
          bool haswater = false;
          while (si >= 0 && si < n && sj >= 0 && sj < n) {
            if (used&(1<<(si*n+sj))) {
              good = false;
              break;
            }
            used |= (1<<(si*n+sj));
            if (map[si][sj] == 'Y') { 
              haswater = true;
              break;
            }
            si++;
          }
          if (!haswater) good = false;
          if (!good) break;
        } else {
          bool haswater = false;
          while (si >= 0 && si < n && sj >= 0 && sj < n) {
            if (used&(1<<(si*n+sj))) {
              good = false;
              break;
            }
            used |= (1<<(si*n+sj));
            if (map[si][sj] == 'Y') {
              haswater = true;
              break;
            }
            si--;
          }
          if (!haswater) good = false;
          if (!good) break;
        }
      }
      if (good)
        r = max(r,bitcount(i)+rec(used));
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
		cout << "Testing ElephantDrinkingEasy (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395432562;
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
		ElephantDrinkingEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string map[] = {"NNNNN",
				                "NNYYN",
				                "NYNNN",
				                "NNYNN",
				                "NNNNN"};
				_expected = 4;
				_received = _obj.maxElephants(vector <string>(map, map+sizeof(map)/sizeof(string))); break;
			}
			case 1:
			{
				string map[] = {"YYY",
				                "YYY",
				                "YYY"};
				_expected = 8;
				_received = _obj.maxElephants(vector <string>(map, map+sizeof(map)/sizeof(string))); break;
			}
			case 2:
			{
				string map[] =  {"YNYN",
				                 "NNYY",
				                 "YYNN",
				                 "YYYY"};
				_expected = 10;
				_received = _obj.maxElephants(vector <string>(map, map+sizeof(map)/sizeof(string))); break;
			}
			case 3:
			{
				string map[] =  {"YNYN",
				                 "YNYY",
				                 "YYNN",
				                 "YYYY"};
				_expected = 10;
				_received = _obj.maxElephants(vector <string>(map, map+sizeof(map)/sizeof(string))); break;
			}
			case 4:
			{
				string map[] = {"YYNYN",
				                "NYNNY",
				                "YNYNN",
				                "YYNYY",
				                "YYNNN"};
				_expected = 12;
				_received = _obj.maxElephants(vector <string>(map, map+sizeof(map)/sizeof(string))); break;
			}
			case 5:
			{
				string map[] = {"YYNYN",
				                "NYNYY",
				                "YNYYN",
				                "YYNYY",
				                "YYNNN"};
				_expected = 13;
				_received = _obj.maxElephants(vector <string>(map, map+sizeof(map)/sizeof(string))); break;
			}
			case 6:
			{
				string map[] = {"NN",
				                "NN"};
				_expected = 0;
				_received = _obj.maxElephants(vector <string>(map, map+sizeof(map)/sizeof(string))); break;
			}
			case 7:
			{
				string map[] = {"YYYYN", "YYNYY", "YYYNY", "YYNYY", "YYYYY"};
				_expected = 15;
				_received = _obj.maxElephants(vector <string>(map, map+sizeof(map)/sizeof(string))); break;
			}
			/*case 8:
			{
				string map[] = ;
				_expected = ;
				_received = _obj.maxElephants(vector <string>(map, map+sizeof(map)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				string map[] = ;
				_expected = ;
				_received = _obj.maxElephants(vector <string>(map, map+sizeof(map)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
