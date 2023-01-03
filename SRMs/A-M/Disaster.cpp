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
double dp[2][26];

class Disaster {
 public:
  double expected(double b, vector <string> roads) {
    vector<vector<double> > g(roads.size(),vector<double>(roads.size(),0));
    for (int i=0;i<roads.size();i++) {
      stringstream a(roads[i]);
      int j = 0;
      while (!a.eof()) {
        double c;
        a >> c;
        g[i][j] = c;
        j++;
      }
    }
    fill(&dp[0][0],&dp[2][0],0.0);
    int cur = 0,next = 1;
    dp[cur][0] = 1;
    double r = 0;
    for (int d=0;d<g.size();d++) {
      //fill(&dp[next][0],&dp[next][26],0.0); // will only change the result if it's 
      for (int i=0;i<g.size();i++)            // better than the previous thing
        for (int j=0;j<g.size();j++)
          dp[next][j] = max(dp[next][j],dp[cur][i]*g[i][j]);
      double load = 1.0/(b*(d+1));
      r = max(r,pow(1-b*load,d)*dp[cur][1]*load);
      swap(cur,next);
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
	string a = tt == -1 ? "0" : string(1,'0'+tt);
	char* b[2] = {argv[0],(char*)a.c_str()};
	if(tt!=-1){argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing Disaster (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1407870559;
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
		Disaster _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				double b = 1.0;
				string roads[] = {"1 0 1","0 1 0","1 .9 1"};
				_expected = 0.13333333333333336;
				_received = _obj.expected(b, vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			case 1:
			{
				double b = 0.5;
				string roads[] = {"1 0 1 0","0 1 0 0","0 0 1 0","1 .9 1 1"};
				_expected = 0.0;
				_received = _obj.expected(b, vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			case 2:
			{
				double b = .8;
				string roads[] =  {"1 .8 .6","1 1 1","1 1 1"};
				_expected = 0.25;
				_received = _obj.expected(b, vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			case 3:
			{
				double b = 0.3821629815565936;
				string roads[] = {"1 0 .65 0 .17 0 .38 .37 .20 0 .05 .66 .87 .10", ".91 1 0 .54 .02 0 .39 .79 0 .12 .39 .31 .71 .67", ".68 .19 1 0 .58 0 .95 0 .58 .83 .88 .35 0 0", ".72 .41 .51 1 .18 0 0 0 .54 0 0 .84 .79 .94", ".48 0 .43 .26 1 0 1 0 .36 .49 .23 0 0 .54", "0 .95 .16 0 0 1 .05 0 .24 0 .74 0 .77 0", "0 0 .29 0 .15 0 1 .92 .67 0 .82 0 0 .54", ".70 .45 0 .55 .85 .74 .37 1 0 .41 0 0 0 0", ".78 .81 .84 .32 0 0 0 .44 1 0 .12 .32 0 .95", "0 .83 0 0 .68 .83 .33 0 .75 1 .74 .49 .51 0", ".41 .11 .70 .77 .21 .82 .55 0 0 .65 1 0 .07 0", "0 0 .07 .63 .46 0 .59 .32 .87 .28 .01 1 .60 .63", ".70 .16 .14 .06 .33 .94 .78 0 .26 .34 .87 .84 1 0", ".76 .64 .46 .19 .99 .13 .36 .68 .26 .65 .90 0 0 1"};
				_expected = 0.21441042308375896;
				_received = _obj.expected(b, vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}
			/*case 4:
			{
				double b = ;
				string roads[] = ;
				_expected = ;
				_received = _obj.expected(b, vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				double b = ;
				string roads[] = ;
				_expected = ;
				_received = _obj.expected(b, vector <string>(roads, roads+sizeof(roads)/sizeof(string))); break;
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
