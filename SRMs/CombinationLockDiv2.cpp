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
// 18:59 started on this
// 19:19 done with thinking
// 19:36 implemented idea
// 19:48 fixed tests except for one
// END CUT HERE
int mem[51][450][2];

class CombinationLockDiv2 {
 public:
  vector<int> d;
  vector<int> to_vec(const string& s) {
    vector<int> r;
    for (int i=0;i<s.size();i++)
      r.push_back(s[i]-'0');
    return r;
  };
  vector<int> diff_vec(const vector<int>& s, const vector<int>& t) {
    vector<int> r;
    for (int i=0;i<s.size();i++)
      r.push_back((s[i]-t[i]+10)%10);
    return r;
  }
  int rec(int idx, int x, int up) {
    int& r = mem[idx][x][up];
    if (r != -1) return r;
    if (idx == d.size()) return r = 0;
    int t = INT_MAX;
    for (int nup=0;nup<2;nup++)
      for (int j=0;j<450;j++) {
        if (nup == 0 && (d[idx] + 9*j)%10 != 0) continue;
        if (nup != 0 && (d[idx] + j)%10 != 0) continue;
        if (nup != up) t = min(t,j+rec(idx+1,j,nup));
        else t = min(t,max(j-x,0)+rec(idx+1,j,nup));
      }
    return r = t;
  }
  int minimumMoves(string S, string T) {
    vector<int> s = to_vec(S);
    vector<int> t = to_vec(T);
    d = diff_vec(s,t);
    memset(mem,-1,sizeof(mem));
    return rec(0,0,0);
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
		cout << "Testing CombinationLockDiv2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1411577993;
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
		CombinationLockDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "123";
				string T = "112";
				_expected = 1;
				_received = _obj.minimumMoves(S, T); break;
			}
			case 1:
			{
				string S = "1";
				string T = "7";
				_expected = 4;
				_received = _obj.minimumMoves(S, T); break;
			}
			case 2:
			{
				string S = "607";
				string T = "607";
				_expected = 0;
				_received = _obj.minimumMoves(S, T); break;
			}
			case 3:
			{
				string S = "1234";
				string T = "4567";
				_expected = 3;
				_received = _obj.minimumMoves(S, T); break;
			}
			case 4:
			{
				string S = "020";
				string T = "909";
				_expected = 2;
				_received = _obj.minimumMoves(S, T); break;
			}
			case 5:
			{
				string S = "4423232218340";
				string T = "6290421476245";
				_expected = 18;
				_received = _obj.minimumMoves(S, T); break;
			}
			/*case 6:
			{
				string S = ;
				string T = ;
				_expected = ;
				_received = _obj.minimumMoves(S, T); break;
			}*/
			/*case 7:
			{
				string S = ;
				string T = ;
				_expected = ;
				_received = _obj.minimumMoves(S, T); break;
			}*/
			/*case 8:
			{
				string S = ;
				string T = ;
				_expected = ;
				_received = _obj.minimumMoves(S, T); break;
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
