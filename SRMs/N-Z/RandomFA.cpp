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
int stringtoint(string a) {
  stringstream b(a);
  int c;
  b >> c;
  return c;
}

double mem[11][52];
bool seen[11][52];

class RandomFA {
 public:
  vector<vector<vector<int> > > rules;
  int finalState;
  double rec(int togo, int state) {
    double& r = mem[togo][state];
    if (seen[togo][state]) return r;
    seen[togo][state] = 1;
    if (!togo) return r = state == finalState;
    if (state == 51) return r = (state == finalState ? pow(3,togo) : 0);
    double t = 0;
    for (int i = 0;i<rules.size();i++)
      for (int j=0;j<rules[i][state].size();j++)
        if (rules[i][state][j])
          t+=rules[i][state][j]/100.0*rec(togo-1,j);
    return r = t;
  }
  vector<vector<int> > convrules(vector<string> rules) {
    vector<vector<int> > r;
    for (int i=0;i<rules.size();i++) {
      int unseenprob = 100;
      vector<int> st(52,0);
      stringstream a(rules[i]);
      while (!a.eof()) {
        string s;
        a >> s;
        if (!s.size()) continue;
        int state = stringtoint(s.substr(0,s.find(":")));
        int prob = stringtoint(s.substr(s.find(":")+1));
        unseenprob-=prob;
        st[state] = prob;
      }
      st[51] = unseenprob;
      r.push_back(st);
    }
    return r;
  }
  double getProbability(vector <string> rulesa, vector <string> rulesb, vector <string> rulesc, int finalState, int maxLength) {
    rules.clear();
    rules.push_back(convrules(rulesa));
    rules.push_back(convrules(rulesb));
    rules.push_back(convrules(rulesc));
    finalState = finalState == 999 ? 51 : finalState;
    this->finalState = finalState;
    memset(seen,0,sizeof(seen));
    int tot = 0;
    double ex = 0;
    for (int i=0;i<=maxLength;i++) {
      ex += rec(i,0);
      tot+=pow(3,i);
    }
    return ex/tot;
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
		cout << "Testing RandomFA (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398255812;
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
		RandomFA _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string rulesa[] = {"0:100"};
				string rulesb[] = {""};
				string rulesc[] = {""};
				int finalState = 999;
				int maxLength = 1;
				_expected = 0.5;
				_received = _obj.getProbability(vector <string>(rulesa, rulesa+sizeof(rulesa)/sizeof(string)), vector <string>(rulesb, rulesb+sizeof(rulesb)/sizeof(string)), vector <string>(rulesc, rulesc+sizeof(rulesc)/sizeof(string)), finalState, maxLength); break;
			}
			case 1:
			{
				string rulesa[] = {"1:100","0:100"};
				string rulesb[] = {"1:100","0:100"};
				string rulesc[] = {"1:100","0:100"};
				int finalState = 1;
				int maxLength = 3;
				_expected = 0.75;
				_received = _obj.getProbability(vector <string>(rulesa, rulesa+sizeof(rulesa)/sizeof(string)), vector <string>(rulesb, rulesb+sizeof(rulesb)/sizeof(string)), vector <string>(rulesc, rulesc+sizeof(rulesc)/sizeof(string)), finalState, maxLength); break;
			}
			case 2:
			{
				string rulesa[] = {"1:25 2:25 3:25 4:25","0:100","0:100","0:100","0:100"};
				string rulesb[] = {"","","","",""};
				string rulesc[] = {"","","","",""};
				int finalState = 3;
				int maxLength = 5;
				_expected = 0.0020604395604395605;
				_received = _obj.getProbability(vector <string>(rulesa, rulesa+sizeof(rulesa)/sizeof(string)), vector <string>(rulesb, rulesb+sizeof(rulesb)/sizeof(string)), vector <string>(rulesc, rulesc+sizeof(rulesc)/sizeof(string)), finalState, maxLength); break;
			}
			case 3:
			{
				string rulesa[] = {"1:25 2:25 3:25 4:25","0:100","0:100","0:100","0:100"};
				string rulesb[] = {"","","","",""};
				string rulesc[] = {"","","","",""};
				int finalState = 999;
				int maxLength = 5;
				_expected = 0.9835164835164837;
				_received = _obj.getProbability(vector <string>(rulesa, rulesa+sizeof(rulesa)/sizeof(string)), vector <string>(rulesb, rulesb+sizeof(rulesb)/sizeof(string)), vector <string>(rulesc, rulesc+sizeof(rulesc)/sizeof(string)), finalState, maxLength); break;
			}
			case 4:
			{
				string rulesa[] = {"2:9 0:7 3:4 1:2 5:35","2:9 0:7 3:4 1:2 5:35",
				                   "2:9 0:7 3:4 1:2 5:35","2:9 0:7 3:4 1:2 5:35",
				                   "2:9 0:7 3:4 1:2 5:35","2:9 0:7 3:4 1:2 5:35"};
				string rulesb[] = {"0:10 4:7 5:1","0:10 4:7 5:1","0:10 4:7 5:1",
				                   "0:10 4:7 5:1","0:10 4:7 5:1","3:79 2:10"};
				string rulesc[] = {"1:100","2:100","3:100","4:100","5:100","0:100"};
				int finalState = 3;
				int maxLength = 10;
				_expected = 0.002676338903044717;
				_received = _obj.getProbability(vector <string>(rulesa, rulesa+sizeof(rulesa)/sizeof(string)), vector <string>(rulesb, rulesb+sizeof(rulesb)/sizeof(string)), vector <string>(rulesc, rulesc+sizeof(rulesc)/sizeof(string)), finalState, maxLength); break;
			}
			case 5:
			{
				string rulesa[] = {"2:9 0:7 3:4 1:2 5:35","2:9 0:7 3:4 1:2 5:35",
				                   "2:9 0:7 3:4 1:2 5:35","2:9 0:7 3:4 1:2 5:35",
				                   "2:9 0:7 3:4 1:2 5:35","2:9 0:7 3:4 1:2 5:35"};
				string rulesb[] = {"0:10 4:7 5:1","0:10 4:7 5:1","0:10 4:7 5:1",
				                   "0:10 4:7 5:1","0:10 4:7 5:1","3:79 2:10"};
				string rulesc[] = {"1:100","2:100","3:100","4:100","5:100","0:100"};
				int finalState = 3;
				int maxLength = 0;
				_expected = 0.0;
				_received = _obj.getProbability(vector <string>(rulesa, rulesa+sizeof(rulesa)/sizeof(string)), vector <string>(rulesb, rulesb+sizeof(rulesb)/sizeof(string)), vector <string>(rulesc, rulesc+sizeof(rulesc)/sizeof(string)), finalState, maxLength); break;
			}
			case 6:
			{
				string rulesa[] = {"7:57 6:14 4:28", "5:95 3:3", "0:42 2:44 6:7 7:5", "6:17 0:19 2:57 7:2", "2:12 3:15 1:19 5:10 4:28 0:8 6:3", "3:45 0:1 1:10 5:9 7:19 4:11 2:1", "5:77 7:14 1:4 3:2", "2:82 5:2 6:12 3:2 0:1 4:1"};
				string rulesb[] = {"6:28 5:27 7:44", "7:21 0:57 5:17 6:5", "7:92 1:5 5:3", "2:55 6:16 0:10 1:5 3:5 4:5", "3:50 5:48 2:2", "7:56 2:41 5:3", "4:42 3:47 5:2 0:5", "2:78 1:3 4:2 3:16 5:1"};
				string rulesc[] = {"1:33 7:20 6:14 3:11 2:10 4:4 0:2", "3:34 6:60 1:1 4:1", "2:63 6:12 3:1 1:2 7:11 0:8 4:3", "1:100", "0:62 7:23 4:1 2:1 3:8 6:1", "5:86 1:11 2:1", "1:51 2:49", "1:40 7:12 2:37 6:6 5:1"};
				int finalState = 2;
				int maxLength = 10;
				_expected = 0.25958382771289973;
				_received = _obj.getProbability(vector <string>(rulesa, rulesa+sizeof(rulesa)/sizeof(string)), vector <string>(rulesb, rulesb+sizeof(rulesb)/sizeof(string)), vector <string>(rulesc, rulesc+sizeof(rulesc)/sizeof(string)), finalState, maxLength); break;
			}
			case 7:
			{
				string rulesa[] = {"1:25 2:25 3:25 4:25", "0:100", "0:100", "0:100", "0:100"};
				string rulesb[] = {"", "", "", "", ""};
				string rulesc[] = {"", "", "", "", ""};
				int finalState = 3;
				int maxLength = 5;
				_expected = 0.0020604395604395605;
				_received = _obj.getProbability(vector <string>(rulesa, rulesa+sizeof(rulesa)/sizeof(string)), vector <string>(rulesb, rulesb+sizeof(rulesb)/sizeof(string)), vector <string>(rulesc, rulesc+sizeof(rulesc)/sizeof(string)), finalState, maxLength); break;
			}
			case 8:
			{
				string rulesa[] = {"6:6 1:31 4:6 2:21 5:34 7:2", "3:21 5:27 6:27 2:2 4:13 0:2 1:6", "4:17 0:1 1:4 5:14 3:10 6:3 2:27 7:15", "7:34 3:15 2:49 4:1 5:1", "2:1 3:25 5:47 0:2 6:15 4:7 7:1", "7:33 0:40 3:26 2:1", "1:11 7:32 2:6 5:6 4:23 3:2 6:14 0:5", "2:17 1:36 5:13 0:13 6:16 4:5"};
;
				string rulesb[] = {"6:30 7:26 4:40 1:2 0:2", "7:24 3:10 5:27 1:14 0:13 2:5 6:3 4:4", "6:16 5:14 2:34 3:13 0:13 4:10", "1:19 7:16 3:29 5:29 0:5", "5:20 7:12 3:34 0:1 1:29 2:1", "6:24 5:43 1:24 0:3 7:1", "4:4 1:37 5:30 2:11 3:16 6:1", "7:14 4:13 1:19 6:41 0:2 2:8"};
				string rulesc[] = {"5:45 3:19 6:28 2:8", "6:50 5:44 7:5 2:1", "2:34 5:8 6:21 7:23 1:1 3:7 4:6", "2:28 1:14 0:38 5:1 4:11 3:2", "5:3 0:2 7:49 4:44 1:1", "5:21 7:31 2:23 3:4 6:13 4:2 1:5", "7:10 4:7 2:11 5:6 3:4 0:44 1:9 6:9", "0:31 7:2 6:21 3:28 4:7 2:3 5:4 1:3"};
				int finalState = 3;
				int maxLength = 10;
				_expected = 0.09407353249308015;
				_received = _obj.getProbability(vector <string>(rulesa, rulesa+sizeof(rulesa)/sizeof(string)), vector <string>(rulesb, rulesb+sizeof(rulesb)/sizeof(string)), vector <string>(rulesc, rulesc+sizeof(rulesc)/sizeof(string)), finalState, maxLength); break;
			}
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
