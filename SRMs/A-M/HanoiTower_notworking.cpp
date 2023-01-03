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
    string a, b, c;
    int k;
    State(string a, string b, string c, int k) : a(a), b(b), c(c), k(k) {};
    State() : a(""),b(""),c(""),k(0) {};
    bool operator<(const State& o) const {
      if (a != o.a) return a<o.a;
      if (b != o.b) return b<o.b;
      if (c != o.c) return c<o.c;
      return k < o.k;
    }
    bool operator==(const State& o) const {
      return (a == o.a && b == o.b && c == o.c);
    }
  };
  map<State,int> mem;
  set<State> used;
  State endstate;
  int rec(string a, string b, string c, int k) {
    cout << used.size() << " " << mem.size() << endl;
    State s(a,b,c,k);
    if (s == endstate) return 0;
    if (mem.count(s)) return mem[s];
    if (used.count(s)) return INF;
    used.insert(s);
    int r = INF;
    if (a.size()) {
      r = min(r,1+rec(a.substr(0,a.size()-1),b+a[a.size()-1],c,1+k));
      r = min(r,1+rec(a.substr(0,a.size()-1),b,c+a[a.size()-1],1+k));
    }
    if (b.size()) {
      r = min(r,1+rec(a+b[b.size()-1],b.substr(0,b.size()-1),c,1+k));
      r = min(r,1+rec(a,b.substr(0,b.size()-1),c+b[b.size()-1],1+k));
    }
    if (c.size()) {
      r = min(r,1+rec(a+c[c.size()-1],b,c.substr(0,c.size()-1),1+k));
      r = min(r,1+rec(a,b+c[c.size()-1],c.substr(0,c.size()-1),1+k));
    }
    used.erase(s);
    return r = mem[s];
  }
  int moves(string pegA, string pegB, string pegC) {
    mem.clear();
    used.clear();
    int acount = 0, bcount = 0, ccount = 0;
    string s = pegA+pegB+pegC;
    for (int i=0;i<s.size();i++) {
      acount+=s[i] == 'A';
      bcount+=s[i] == 'B';
      ccount+=s[i] == 'C';
    }
    
    endstate = State(string(acount,'A'),string(bcount,'B'),string(ccount,'C'),0);
    return rec(pegA,pegB,pegC,0);
    
    
    /*
    endstate = State(pegA,pegB,pegC);
    return rec(string(acount,'A'),string(bcount,'B'),string(ccount,'C'));
    */
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
