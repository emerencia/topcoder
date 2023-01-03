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

class EmployManager {
 public:
  struct Manpair {
    int i;
    int j;
    int value;
    bool operator<(const Manpair& o) const {
      return value < o.value;
    }
  };

  int maximumEarnings(vector <int> value, vector <string> earning) {
    int n = value.size();
    int r = 0;
    for (int i=0;i<earning.size();i++)
      for (int j=i+1;j<earning.size();j++)
        r-= earning[i][j]-'0';
    vector<bool> hired(n,false);
    for (int i=0;i<n;i++) {
      if (value[i] != 0) continue;
      hired[i] = true;
      for (int k=0;k<n;k++) {
        if (k > i) r+= earning[i][k]-'0';
        if (i > k) r+= earning[k][i]-'0';
      }
    }
    vector<vector<int> > pairvalues(n,vector<int>(n,0));
    for (int i=0;i<n;i++)
      for (int j=i+1;j<n;j++) {
        int c = 0;
        for (int k=0;k<n;k++) {
          if (k > i) c+= earning[i][k]-'0';
          if (j > k) c+= earning[k][j]-'0';
        }
        c-=value[i];
        c-=value[j];
        pairvalues[i][j] = c;
      }
    while (true) {
      vector<Manpair> pairs;
      for (int i=0;i<earning.size();i++) {
        if (hired[i]) continue;
        for (int j=i+1;j<earning.size();j++) {
          if (hired[j]) continue;
          pairs.push_back((Manpair){i,j,pairvalues[i][j]});
        }
      }
      sort(pairs.rbegin(),pairs.rend());
      if (!pairs.size()) break;
      if (pairs[0].value < 0) break;
      r += pairs[0].value;
      hired[pairs[0].i] = true;
      hired[pairs[0].j] = true;
    }
    return max(r,-1);
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
	char* b[2];
	if(tt!=-1){b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing EmployManager (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1400343632;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 950.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		EmployManager _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int value[] = {1, 1};
				string earning[] = {"02", "20"};
				_expected = 0;
				_received = _obj.maximumEarnings(vector <int>(value, value+sizeof(value)/sizeof(int)), vector <string>(earning, earning+sizeof(earning)/sizeof(string))); break;
			}
			case 1:
			{
				int value[] = {2, 2};
				string earning[] = {"01", "10"};
				_expected = -1;
				_received = _obj.maximumEarnings(vector <int>(value, value+sizeof(value)/sizeof(int)), vector <string>(earning, earning+sizeof(earning)/sizeof(string))); break;
			}
			case 2:
			{
				int value[] = {1, 2, 3, 4};
				string earning[] = {"0121", "1021", "2201", "1110"};
				_expected = -1;
				_received = _obj.maximumEarnings(vector <int>(value, value+sizeof(value)/sizeof(int)), vector <string>(earning, earning+sizeof(earning)/sizeof(string))); break;
			}
			case 3:
			{
				int value[] = {2, 2, 0, 1, 4, 0, 1, 0, 0, 4};
				string earning[] = {"0100451253",  "1010518123",  "0102989242",  "0020093171",  "4590045480",  "5189400676",  "1893500826",  "2121468008",  "5247872007",  "3321066870"};
				_expected = 156;
				_received = _obj.maximumEarnings(vector <int>(value, value+sizeof(value)/sizeof(int)), vector <string>(earning, earning+sizeof(earning)/sizeof(string))); break;
			}
			/*case 4:
			{
				int value[] = ;
				string earning[] = ;
				_expected = ;
				_received = _obj.maximumEarnings(vector <int>(value, value+sizeof(value)/sizeof(int)), vector <string>(earning, earning+sizeof(earning)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				int value[] = ;
				string earning[] = ;
				_expected = ;
				_received = _obj.maximumEarnings(vector <int>(value, value+sizeof(value)/sizeof(int)), vector <string>(earning, earning+sizeof(earning)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int value[] = ;
				string earning[] = ;
				_expected = ;
				_received = _obj.maximumEarnings(vector <int>(value, value+sizeof(value)/sizeof(int)), vector <string>(earning, earning+sizeof(earning)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(3);
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
