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
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE
const int INF = 1000000;

class HanoiTower {
 public:
  struct State {
    vector<string> s;
    State(string a, string b, string c) {
      s.clear();
      s.push_back(a);
      s.push_back(b);
      s.push_back(c);
    };
    State() {
      s.clear();
      for (int i=0;i<3;i++)
        s.push_back("");
    };
    bool operator<(const State& o) const {
      for (int i=0;i<3;i++)
        if (s[i] != o.s[i])
          return s[i]<o.s[i];
      return false;
    }
    bool operator==(const State& o) const {
      for (int i=0;i<3;i++)
        if (s[i] != o.s[i])
          return false;
      return true;
    }
    int size(int idx) {
      return s[idx].size();
    }
    State move(int from, int to) {
      State r = *this;
      r.s[to] += s[from][s[from].size()-1];
      r.s[from] = s[from].substr(0,s[from].size()-1);
      return r;
    }
  };
  int moves(string pegA, string pegB, string pegC) {
    int acount = 0, bcount = 0, ccount = 0;
    string s = pegA+pegB+pegC;
    for (int i=0;i<s.size();i++) {
      acount+=s[i] == 'A';
      bcount+=s[i] == 'B';
      ccount+=s[i] == 'C';
    }
    State startstate = State(pegA,pegB,pegC);
    State endstate = State(string(acount,'A'),string(bcount,'B'),string(ccount,'C'));
    if (startstate == endstate) return 0;
    set<State> seenleft, seenright;
    queue<State> queueleft, queueright;
    seenleft.insert(startstate);
    seenright.insert(endstate);
    queueleft.push(startstate);
    queueright.push(endstate);
    for (int r=1;;r++) {
      queue<State> newqueue;
      while (!queueleft.empty()) {
        State cur = queueleft.front();
        queueleft.pop();
        for (int from=0;from<3;from++) {
          if (!cur.size(from)) continue;
          for (int to=0;to<3;to++) {
            if (from == to) continue;
            State newstate = cur.move(from,to);
            if (seenright.count(newstate)) return r;
            if (seenleft.count(newstate)) continue;
            seenleft.insert(newstate);
            newqueue.push(newstate);
          }
        }
      }
      swap(seenleft,seenright);
      queueleft = queueright;
      queueright = newqueue;
    }
    return -1;
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
		cout << "Testing HanoiTower (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396298899;
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
		HanoiTower _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string pegA = "A";
				string pegB = "AA";
				string pegC = "AA";
				_expected = 4;
				_received = _obj.moves(pegA, pegB, pegC); break;
			}
			case 1:
			{
				string pegA = "B";
				string pegB = "C";
				string pegC = "A";
				_expected = 5;
				_received = _obj.moves(pegA, pegB, pegC); break;
			}
			case 2:
			{
				string pegA = "CBA";
				string pegB = "";
				string pegC = "";
				_expected = 5;
				_received = _obj.moves(pegA, pegB, pegC); break;
			}
			case 3:
			{
				string pegA = "BBBBBBBBBA";
				string pegB = "";
				string pegC = "";
				_expected = 11;
				_received = _obj.moves(pegA, pegB, pegC); break;
			}
			case 4:
			{
				string pegA = "CBACBACBAA";
				string pegB = "";
				string pegC = "";
				_expected = 19;
				_received = _obj.moves(pegA, pegB, pegC); break;
			}
			/*case 5:
			{
				string pegA = ;
				string pegB = ;
				string pegC = ;
				_expected = ;
				_received = _obj.moves(pegA, pegB, pegC); break;
			}*/
			/*case 6:
			{
				string pegA = ;
				string pegB = ;
				string pegC = ;
				_expected = ;
				_received = _obj.moves(pegA, pegB, pegC); break;
			}*/
			/*case 7:
			{
				string pegA = ;
				string pegB = ;
				string pegC = ;
				_expected = ;
				_received = _obj.moves(pegA, pegB, pegC); break;
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
