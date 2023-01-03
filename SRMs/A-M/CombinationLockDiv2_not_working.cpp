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

class CombinationLockDiv2 {
 public:
  vector<int> to_vec(const string& s) {
    vector<int> r;
    for (int i=0;i<s.size();i++)
      r.push_back(s[i]-'0');
    return r;
  };
  void rotate_by(vector<int>& v, int d) {
    for (int i=0;i<v.size();i++)
      v[i]+=d;
  }
  vector<int> diff_vec(const vector<int>& s, const vector<int>& t) {
    vector<int> r;
    for (int i=0;i<s.size();i++) {
      if (abs(t[i] - s[i]) <= abs(10 - (t[i] - s[i])))
        r.push_back(t[i]-s[i]);
      else r.push_back(10 - (t[i] - s[i]));
    }
    return r;
  }
  vector<int> diff_vec2(const vector<int>& s, const vector<int>& t) {
    vector<int> r;
    for (int i=0;i<s.size();i++)
      r.push_back(t[i] <= s[i] ? t[i] - s[i] : (s[i] - t[i])-10);
    return r;
  }
  int min_moves_to_eq2(vector<int> s, vector<int> t) {
    vector<int> d = diff_vec2(s,t);
    int r = 0;
    bool changed = true;
    while (changed) {
      changed =false;
      int si = -1;
      int state = 0;
      for (int i = 0; i < d.size(); i++) {
        if (state == 0) {
          if (d[i] == 0) continue;
          changed = true;
          si = i;
          if (d[i] > 0) state = 1;
          else state = 2;
        } else if (state == 1) {
          if (d[i] > 0) continue;
          for (int j = si; j < i; j++)
            d[j]--;
          r++;
          i = -1;
          si = -1;
          state = 0;
        } else {
          if (d[i] < 0) continue;
          for (int j = si; j < i; j++)
            d[j]++;
          r++;
          i = -1;
          si = -1;
          state = 0;
        }
      }
      if (si != -1) {
        if (state == 1) {
          for (int i=si;i<d.size();i++)
            d[i]--;
          r++;
        } else { // assume state == 2
          if (state != 2) cout << "error: state is not 2" << endl;
          for (int i=si;i<d.size();i++)
            d[i]++;
          r++;
        }
      }
    }
    return r;
  }
  int min_moves_to_eq(vector<int> s, vector<int> t) {
    // make everything positive
    vector<int> d = diff_vec(s,t);
    int r = 0;
    bool changed = true;
    while (changed) {
      changed =false;
      int si = -1;
      int state = 0;
      for (int i = 0; i < d.size(); i++) {
        if (state == 0) {
          if (d[i] == 0) continue;
          changed = true;
          si = i;
          if (d[i] > 0) state = 1;
          else state = 2;
        } else if (state == 1) {
          if (d[i] > 0) continue;
          for (int j = si; j < i; j++)
            d[j]--;
          r++;
          i = -1;
          si = -1;
          state = 0;
        } else {
          if (d[i] < 0) continue;
          for (int j = si; j < i; j++)
            d[j]++;
          r++;
          i = -1;
          si = -1;
          state = 0;
        }
      }
      if (si != -1) {
        if (state == 1) {
          for (int i=si;i<d.size();i++)
            d[i]--;
          r++;
        } else { // assume state == 2
          if (state != 2) cout << "error: state is not 2" << endl;
          for (int i=si;i<d.size();i++)
            d[i]++;
          r++;
        }
      }
    }
    return r;
  }
  int minimumMoves(string S, string T) {
    int r = INT_MAX;
    vector<int> s = to_vec(S);
    vector<int> t = to_vec(T);
    vector<int> sr = s;
    for (int i=0;i<10;i++) {
      rotate_by(s,1);
      r = min(r,min_moves_to_eq(s,t)+min(10-i-1,i+1));
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
