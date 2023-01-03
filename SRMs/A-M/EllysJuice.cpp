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

class EllysJuice {
 public:
  struct State {
    string player;
    double drink;
    bool operator<(const State& o) const {
      return drink > o.drink;
    }
  };
  vector <string> getWinners(vector <string> players) {
    set<string> winners;
    vector<int> p(players.size());
    for (int i=0;i<players.size();i++) p[i] = i;
    do {
      vector<double> amount(2,1);
      map<string,double> drank;
      for (int i=0;i<players.size();i++) {
        string player = players[p[i]];
        double cur = amount[i%2]/2;
        amount[i%2]-=cur;
        drank[player] += cur;
      }
      vector<State> r;
      for (map<string,double>::iterator i = drank.begin();i!=drank.end();i++)
        r.push_back((State){i->first,i->second});
      sort(r.begin(),r.end());
      if (r.size() == 1 || r[0].drink > r[1].drink)
        winners.insert(r[0].player);
    } while(next_permutation(p.begin(),p.end()));
    vector<string> r(winners.begin(),winners.end());
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
	char* b[2];
	if(tt!=-1){b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing EllysJuice (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397307725;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		EllysJuice _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string players[] = { "elly", "kriss", "stancho", "elly", "stancho" };
				string __expected[] = {"elly", "stancho" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getWinners(vector <string>(players, players+sizeof(players)/sizeof(string))); break;
			}
			case 1:
			{
				string players[] = {"torb", "elly", "stancho", "kriss"};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getWinners(vector <string>(players, players+sizeof(players)/sizeof(string))); break;
			}
			case 2:
			{
				string players[] = {"elly", "elly", "elly", "elly", "elly"};
				string __expected[] = {"elly" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getWinners(vector <string>(players, players+sizeof(players)/sizeof(string))); break;
			}
			case 3:
			{
				string players[] = { "ariadne", "elly", "ariadne", "stancho", "stancho", "kriss", "stancho", "elly" };
				string __expected[] = {"ariadne", "elly", "stancho" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getWinners(vector <string>(players, players+sizeof(players)/sizeof(string))); break;
			}
			/*case 4:
			{
				string players[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getWinners(vector <string>(players, players+sizeof(players)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string players[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getWinners(vector <string>(players, players+sizeof(players)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string players[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getWinners(vector <string>(players, players+sizeof(players)/sizeof(string))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
