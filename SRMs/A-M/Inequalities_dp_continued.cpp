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
int dp[2][1003][1003];

class Inequalities {
 public:
  int maximumSubset(vector <string> inequalities) {
    vector<PSI> ineqs;
    for (int i=0;i<inequalities.size();i++) {
      stringstream a(inequalities[i]);
      string s;
      a >> s;
      a >> s;
      int num;
      a >> num;
      ineqs.push_back(PSI(s,num));
    }
    memset(dp,0,sizeof(dp));
    int cur = 0, next = 1;
    for (int idx=inequalities.size();idx>=0;idx--) {
      for (int mn = -1;mn <= 1001;mn++)
        for (int mx = mn;mx <= 1001;mx++) {
          int& r = dp[next][mn+1][mx+1];
          if (mn+1 == mx) { r = -1e6; continue; }
          if (idx == inequalities.size()) { r = 0; continue; }
          string s = ineqs[idx].first;
          int num = ineqs[idx].second;
          int t = dp[cur][mn+1][mx+1];
          if (mn == mx) {
            if (s == "=") t = num == mn ? max(t,1+dp[cur][mn+1][mn+1]) : t;
            if (s == "<") t = mn < num ? max(t,1+dp[cur][mn+1][mn+1]) : t;
            if (s == "<=") t = mn <= num ? max(t,1+dp[cur][mn+1][mn+1]) : t;
            if (s == ">=") t = mn >= num ? max(t,1+dp[cur][mn+1][mn+1]) : t;
            if (s == ">") t = mn > num ? max(t,1+dp[cur][mn+1][mn+1]) : t;
          } else {
            if (s == "=" && num > mn && num < mx) t = max(t,1+dp[cur][num+1][num+1]);
            if (s == "<" && mn < min(num,mx)) t = max(t,1+dp[cur][mn+1][min(num,mx)+1]);
            if (s == "<=" && mn < min(num+1,mx)) t = max(t,1+dp[cur][mn+1][min(num+1,mx)+1]);
            if (s == ">" && max(num,mn)< mx) t = max(t,1+dp[cur][max(num,mn)+1][mx+1]);
            if (s == ">=" && max(num-1,mn) < mx) t = max(t,1+dp[cur][max(num-1,mn)+1][mx+1]);
          }
          r = t;
        }
      swap(cur,next);
    }
    return dp[cur][0][1002];
  }
};

// BEGIN CUT HER
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
		cout << "Testing Inequalities (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1399559321;
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
		Inequalities _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string inequalities[] = {"X <= 12","X = 13","X > 9","X < 10","X >= 14"};
				_expected = 3;
				_received = _obj.maximumSubset(vector <string>(inequalities, inequalities+sizeof(inequalities)/sizeof(string))); break;
			}
			case 1:
			{
				string inequalities[] = {"X < 0","X <= 0"};
				_expected = 2;
				_received = _obj.maximumSubset(vector <string>(inequalities, inequalities+sizeof(inequalities)/sizeof(string))); break;
			}
			case 2:
			{
				string inequalities[] = {"X = 1","X = 2","X = 3","X > 0"};
				_expected = 2;
				_received = _obj.maximumSubset(vector <string>(inequalities, inequalities+sizeof(inequalities)/sizeof(string))); break;
			}
			case 3:
			{
				string inequalities[] = {"X <= 521","X >= 521","X = 521","X > 902","X > 12","X <= 1000"};
				_expected = 5;
				_received = _obj.maximumSubset(vector <string>(inequalities, inequalities+sizeof(inequalities)/sizeof(string))); break;
			}
			case 4:
			{
				string inequalities[] = {"X < 10", "X >= 10"};
				_expected = 1;
				_received = _obj.maximumSubset(vector <string>(inequalities, inequalities+sizeof(inequalities)/sizeof(string))); break;
			}
			/*case 5:
			{
				string inequalities[] = ;
				_expected = ;
				_received = _obj.maximumSubset(vector <string>(inequalities, inequalities+sizeof(inequalities)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string inequalities[] = ;
				_expected = ;
				_received = _obj.maximumSubset(vector <string>(inequalities, inequalities+sizeof(inequalities)/sizeof(string))); break;
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
