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
int stringtoint(string a) {
  stringstream b(a);
  int c;
  b >> c;
  return c;
}
//bool seen[52][12];
//double mem[52][12];

class RandomFA {
 public:
  vector<vector<int> > rulesa, rulesb, rulesc;
  int finalState;
  double cnt;
  LL tot;
  double rec2(const string& s, int state, int idx) {
    if (idx == s.size()) return state == finalState;
    if (state == 51) return state == finalState;
    double r = 0;
    if (s[idx] == 'a') {
      for (int i=0;i<rulesa[state].size();i++)
        if (rulesa[state][i])
          r+=rulesa[state][i]/100.0*rec2(s,i,idx+1);
    } else if (s[idx] == 'b') {
      for (int i=0;i<rulesb[state].size();i++)
        if (rulesb[state][i])
          r+=rulesb[state][i]/100.0*rec2(s,i,idx+1);
    } else {
      for (int i=0;i<rulesc[state].size();i++)
        if (rulesc[state][i])
          r+=rulesc[state][i]/100.0*rec2(s,i,idx+1);
    }
    return r;
  }
  void rec(string sofar, int togo) {
    cnt += rec2(sofar,0,0);
    tot++;
    if (!togo) return;
    rec(sofar+'a',togo-1);
    rec(sofar+'b',togo-1);
    rec(sofar+'c',togo-1);
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
    this->rulesa = convrules(rulesa);
    this->rulesb = convrules(rulesb);
    this->rulesc = convrules(rulesc);
    finalState = finalState == 999 ? 51 : finalState;
    this->finalState = finalState;
    string a;
    cnt = 0;
    tot = 0;
    rec(a, maxLength);
    return double(cnt)/tot;
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
			/*case 6:
			{
				string rulesa[] = ;
				string rulesb[] = ;
				string rulesc[] = ;
				int finalState = ;
				int maxLength = ;
				_expected = ;
				_received = _obj.getProbability(vector <string>(rulesa, rulesa+sizeof(rulesa)/sizeof(string)), vector <string>(rulesb, rulesb+sizeof(rulesb)/sizeof(string)), vector <string>(rulesc, rulesc+sizeof(rulesc)/sizeof(string)), finalState, maxLength); break;
			}*/
			/*case 7:
			{
				string rulesa[] = ;
				string rulesb[] = ;
				string rulesc[] = ;
				int finalState = ;
				int maxLength = ;
				_expected = ;
				_received = _obj.getProbability(vector <string>(rulesa, rulesa+sizeof(rulesa)/sizeof(string)), vector <string>(rulesb, rulesb+sizeof(rulesb)/sizeof(string)), vector <string>(rulesc, rulesc+sizeof(rulesc)/sizeof(string)), finalState, maxLength); break;
			}*/
			/*case 8:
			{
				string rulesa[] = ;
				string rulesb[] = ;
				string rulesc[] = ;
				int finalState = ;
				int maxLength = ;
				_expected = ;
				_received = _obj.getProbability(vector <string>(rulesa, rulesa+sizeof(rulesa)/sizeof(string)), vector <string>(rulesb, rulesb+sizeof(rulesb)/sizeof(string)), vector <string>(rulesc, rulesc+sizeof(rulesc)/sizeof(string)), finalState, maxLength); break;
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
