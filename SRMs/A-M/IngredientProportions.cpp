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
LL g[11][11];

class IngredientProportions {
 public:
  LL gcd(LL a,LL b) {
    if (b == 0) return a;
    return gcd(b,a%b);
  }
  vector <int> getMasses(vector <string> proportions) {
    memset(g,0,sizeof(g));
    int n = proportions.size()+1;
    LL lc = 1;
    for (int i=0;i<proportions.size();i++) {
      int from = proportions[i][1]-'0';
      int to = proportions[i][8]-'0';
      int fromr = proportions[i][13]-'0';
      int tor = proportions[i][15]-'0';
      int gc = gcd(fromr,tor);
      fromr/=gc;
      tor/=gc;
      lc*=fromr*tor;
      g[from][to] = fromr;
      g[to][from] = tor;
    }
    for (int k=0;k<n;k++)
     for (int i=0;i<n;i++)
       for (int j=0;j<n;j++)
         if (g[i][k] && g[k][j] && !g[i][j] && i != j)
           g[i][j] = g[i][k]*g[k][j];
    vector<LL> r(n,0);
    r[0] = lc;
    for (int i=0;i<n;i++) {
      if (!g[0][i]) continue;
      r[i]=(r[0]/g[0][i])*g[i][0];
    }
    LL gc = r[0];
    for (int i=1;i<n;i++)
      gc = gcd(gc,r[i]);
    for (int i=0;i<n;i++)
      r[i]/=gc;
    vector<int> res;
    for (int i=0;i<r.size();i++)
      res.push_back(r[i]);
    return res;
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
		cout << "Testing IngredientProportions (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393440967;
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
		IngredientProportions _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string proportions[] = {"#0 and #1 as 6:4"};
				int __expected[] = {3, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMasses(vector <string>(proportions, proportions+sizeof(proportions)/sizeof(string))); break;
			}
			case 1:
			{
				string proportions[] = {"#0 and #1 as 9:8","#1 and #2 as 9:8"};
				int __expected[] = {81, 72, 64 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMasses(vector <string>(proportions, proportions+sizeof(proportions)/sizeof(string))); break;
			}
			case 2:
			{
				string proportions[] = {"#4 and #0 as 1:1", "#4 and #1 as 3:1", "#4 and #2 as 5:1", "#4 and #3 as 7:1"};
				int __expected[] = {105, 35, 21, 15, 105 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMasses(vector <string>(proportions, proportions+sizeof(proportions)/sizeof(string))); break;
			}
			case 3:
			{
				string proportions[] = {"#2 and #3 as 6:8", "#0 and #1 as 9:3", "#3 and #0 as 7:5"};
				int __expected[] = {60, 20, 63, 84 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMasses(vector <string>(proportions, proportions+sizeof(proportions)/sizeof(string))); break;
			}
			case 4:
			{
				string proportions[] = {"#1 and #4 as 1:9", "#0 and #1 as 1:9", "#9 and #6 as 8:3", "#2 and #6 as 2:8", "#5 and #8 as 5:1", "#8 and #7 as 5:1", "#3 and #4 as 1:6", "#9 and #3 as 6:1", "#3 and #5 as 1:7"};
				int __expected[] = {800, 7200, 6075, 10800, 64800, 75600, 24300, 3024, 15120, 64800};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMasses(vector <string>(proportions, proportions+sizeof(proportions)/sizeof(string))); break;
			}
			/*case 5:
			{
				string proportions[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMasses(vector <string>(proportions, proportions+sizeof(proportions)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string proportions[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMasses(vector <string>(proportions, proportions+sizeof(proportions)/sizeof(string))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
