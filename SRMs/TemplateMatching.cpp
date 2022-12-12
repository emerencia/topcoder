#include <string>
#include <iostream>
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
string pref;
string suf;
class TemplateMatching {
 public:
  struct Match {
    string s;
    int prefi;
    int sufi;
    Match(string s) : s(s), prefi(0), sufi(0) {
      // set prefi sufi
      for (int i=0;i<pref.size();i++)
        if (pref.substr(i) == s.substr(0,pref.size()-i)) {
          prefi = pref.size()-i;
          break;
        }
      for (int i=1;i<=suf.size();i++)
        if (i <= s.size() && suf.substr(0,i) == s.substr(s.size()-i))
          sufi = i;
    }
    bool operator<(const Match& o) const {
      if (prefi+sufi != o.prefi+o.sufi)
        return prefi+sufi > o.prefi+o.sufi;
      if (prefi != o.prefi)
        return prefi > o.prefi;
      return s < o.s;
    }
  };
  string bestMatch(string text, string prefix, string suffix) {
    pref = prefix;
    suf = suffix;
    vector<Match> a;
    for (int i=0;i<text.size();i++)
      for (int j=i+1;j<=text.size();j++)
        a.push_back(Match(text.substr(i,j-i)));
    sort(a.begin(),a.end());
    return a[0].s;
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
		cout << "Testing TemplateMatching (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390939777;
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
		TemplateMatching _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string text = "something";
				string prefix = "awesome";
				string suffix = "ingenious";
				_expected = "something";
				_received = _obj.bestMatch(text, prefix, suffix); break;
			}
			case 1:
			{
				string text = "havka";
				string prefix = "eto";
				string suffix = "papstvo";
				_expected = "a";
				_received = _obj.bestMatch(text, prefix, suffix); break;
			}
			case 2:
			{
				string text = "abracadabra";
				string prefix = "habrahabr";
				string suffix = "bracket";
				_expected = "abrac";
				_received = _obj.bestMatch(text, prefix, suffix); break;
			}
			case 3:
			{
				string text = "mississippi";
				string prefix = "promise";
				string suffix = "piccolo";
				_expected = "ippi";
				_received = _obj.bestMatch(text, prefix, suffix); break;
			}
			case 4:
			{
				string text = "a a a a a a";
				string prefix = "a a";
				string suffix = "a";
				_expected = "a a";
				_received = _obj.bestMatch(text, prefix, suffix); break;
			}
			case 5:
			{
				string text = "ab";
				string prefix = "b";
				string suffix = "a";
				_expected = "b";
				_received = _obj.bestMatch(text, prefix, suffix); break;
			}
			/*case 6:
			{
				string text = ;
				string prefix = ;
				string suffix = ;
				_expected = ;
				_received = _obj.bestMatch(text, prefix, suffix); break;
			}*/
			/*case 7:
			{
				string text = ;
				string prefix = ;
				string suffix = ;
				_expected = ;
				_received = _obj.bestMatch(text, prefix, suffix); break;
			}*/
			/*case 8:
			{
				string text = ;
				string prefix = ;
				string suffix = ;
				_expected = ;
				_received = _obj.bestMatch(text, prefix, suffix); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
