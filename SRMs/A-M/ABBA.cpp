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
int mem[1001][1001][2];

class ABBA {
 public:
  string target, initial;
  int rec(int l, int ri, int flipped) {
    if (l < 0 || ri < 0 || l >= target.size() || ri >= target.size()) return false;
    int& r = mem[l][ri][flipped];
    if (r != -1) return r;
    if (ri - l + 1 < (int)initial.size()) return r = 0;
    string cur = target.substr(l,ri-l+1);
    if (flipped) reverse(cur.begin(),cur.end());
    if (ri - l + 1 == (int)initial.size()) {
      return r = (initial == cur);
    }
    // try left and right
    bool t = false;
    if (cur[cur.size()-1] == 'A')
      t |= rec(flipped ? l+1 : l, flipped ? ri : ri-1, flipped);
    if (cur[cur.size()-1] == 'B')
      t |= rec(flipped ? l+1 : l, flipped ? ri : ri-1, 1-flipped);
    return r = t;
  }
  string canObtain(string initial, string target) {
    this->target = target;
    this->initial = initial;
    memset(mem,-1,sizeof(mem));
    return rec(0,target.size()-1,0) ? "Possible" : "Impossible";
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
		cout << "Testing ABBA (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1438442305;
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
		ABBA _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string initial = "B";
				string target = "ABBA";
				_expected = "Possible";
				_received = _obj.canObtain(initial, target); break;
			}
			case 1:
			{
				string initial = "AB";
				string target = "ABB";
				_expected = "Impossible";
				_received = _obj.canObtain(initial, target); break;
			}
			case 2:
			{
				string initial = "BBAB";
				string target = "ABABABABB";
				_expected = "Impossible";
				_received = _obj.canObtain(initial, target); break;
			}
			case 3:
			{
				string initial = "BBBBABABBBBBBA";
				string target = "BBBBABABBABBBBBBABABBBBBBBBABAABBBAA";
				_expected = "Possible";
				_received = _obj.canObtain(initial, target); break;
			}
			case 4:
			{
				string initial = "A";
				string target = "BB";
				_expected = "Impossible";
				_received = _obj.canObtain(initial, target); break;
			}
			/*case 5:
			{
				string initial = ;
				string target = ;
				_expected = ;
				_received = _obj.canObtain(initial, target); break;
			}*/
			/*case 6:
			{
				string initial = ;
				string target = ;
				_expected = ;
				_received = _obj.canObtain(initial, target); break;
			}*/
			/*case 7:
			{
				string initial = ;
				string target = ;
				_expected = ;
				_received = _obj.canObtain(initial, target); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
