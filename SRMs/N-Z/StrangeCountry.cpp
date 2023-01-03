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

class StrangeCountry {
 public:
  vector<int> seen;
  vector<string> g;
  void dfs(int cur) {
    for (int i=0;i<g.size();i++) {
      if (g[cur][i] == 'Y' && seen[i] == -1) {
        seen[i] = seen[cur];
        dfs(i);
      }
    }
  }
  int transform(vector <string> g) {
    // number of edges doesn't change
    int nredges = 0;
    for (int i=0;i<g.size();i++)
      for (int j=i+1;j<g.size();j++)
        nredges += g[i][j] == 'Y';
    if (nredges < g.size()-1) return -1;
    // also check if there are any cities not connected
    // they will never be connected since the degree doesn't change
    for (int i=0;i<g.size();i++) {
      int c = 0;
      for (int j=0;j<g.size();j++)
        c+=g[i][j] == 'Y';
      if (!c) return -1;
    }
    this->g = g;
    seen = vector<int>(g.size(),-1);
    int c = 0;
    for (int i=0;i<g.size();i++) {
      if (seen[i] != -1) continue;
      seen[i] = c++;
      dfs(i);
    }
    return c-1;
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
		cout << "Testing StrangeCountry (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395980425;
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
		StrangeCountry _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string g[] = {"NY",
				              "YN"};
				_expected = 0;
				_received = _obj.transform(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			case 1:
			{
				string g[] = {"NYYNN",
				              "YNYNN",
				              "YYNNN",
				              "NNNNY",
				              "NNNYN"};
				_expected = 1;
				_received = _obj.transform(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			case 2:
			{
				string g[] = {"NYYNNNN",
				              "YNYNNNN",
				              "YYNNNNN",
				              "NNNNYYN",
				              "NNNYNYY",
				              "NNNYYNY",
				              "NNNNYYN"};
				_expected = 1;
				_received = _obj.transform(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			case 3:
			{
				string g[] = {"NYNYNNNNNNNN",
				              "YNYNNNNNNNNN",
				              "NYNYYNNNNNNN",
				              "YNYNNNNNNNNN",
				              "NNYNNYYNNNNN",
				              "NNNNYNYNNNNN",
				              "NNNNYYNNNNNN",
				              "NNNNNNNNYYNN",
				              "NNNNNNNYNYNN",
				              "NNNNNNNYYNNN",
				              "NNNNNNNNNNNY",
				              "NNNNNNNNNNYN"};
				_expected = 2;
				_received = _obj.transform(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			case 4:
			{
				string g[] = {"NYNNNN",
				              "YNYNNN",
				              "NYNYNN",
				              "NNYNNN",
				              "NNNNNY",
				              "NNNNYN"};
				_expected = -1;
				_received = _obj.transform(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			case 5:
			{
				string g[] = {"NYNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYNN", "YNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNN", "NNNNNNNNNNNNNYNNNNNNNNNNNNNNYNNNNNNNNNNNNNNN", "YNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYNN", "NNNNNNNNNYNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNN", "NNNNNNNNYNNNYNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNY", "NNNNNNNNNNNNNYNNNNNNNYNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNYNNNNNNNNNNNNNNNYYNNNNNYNNNNNNNNNNN", "NNNNNNYNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNYNNNYNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNYNNNNNNNNY", "NNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNYNNNNNN", "NNNNNNNNNNYNNNNYNNNNNNNNNNNNNNNNNNYNNNNNNNNY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNYN", "NNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNYNNNNNNNNNNNNNNNNNYNNNNNNYNYNNNNN", "NNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNNNNNNNNN", "NNNNNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNYNNNYYNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNYNNNYNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNYNNNNNNYNNNNNNNNNNNNN", "NNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNYNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNYNNNYNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNYN", "NNNNNNNNNNNNYNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNYNNNNNNNN", "NNNNNNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNYNNNNN", "NNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNYNNNNNNN", "YYNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNN", "YYNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNYNN", "YYNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNN", "NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNYNNNNNNNNNNNN", "NNNNNNNNNNYNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNN"};
				_expected = -1;
				_received = _obj.transform(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			/*case 6:
			{
				string g[] = ;
				_expected = ;
				_received = _obj.transform(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string g[] = ;
				_expected = ;
				_received = _obj.transform(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
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
