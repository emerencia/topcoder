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

class MostCommonLetters {
 public:
  string listMostCommon(vector <string> text) {
    vector<int> counts(26,0);
    int mx = 0;
    string s = accumulate(text.begin(),text.end(),string(""));
    for (int i=0;i<s.size();i++)
      if (s[i] != ' ')
        mx = max(mx,++counts[s[i]-'a']);
    string r;
    for (int i=0;i<26;i++)
      if (counts[i] == mx)
        r+=(char)('a'+i);
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
	if(tt!=-1){char* b[2];b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}	if (argc == 1) 
	{
		cout << "Testing MostCommonLetters (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390590256;
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
		MostCommonLetters _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string text[] = {"abc a"};
				_expected = "a";
				_received = _obj.listMostCommon(vector <string>(text, text+sizeof(text)/sizeof(string))); break;
			}
			case 1:
			{
				string text[] = {"abc", "ab"};
				_expected = "ab";
				_received = _obj.listMostCommon(vector <string>(text, text+sizeof(text)/sizeof(string))); break;
			}
			case 2:
			{
				string text[] = {"qwerty", "abc", "qwe", "a"};
				_expected = "aeqw";
				_received = _obj.listMostCommon(vector <string>(text, text+sizeof(text)/sizeof(string))); break;
			}
			case 3:
			{
				string text[] = {"english is a west germanic language originating",
				                 "in england and is the first language for most",
				                 "people in the united kingdom the united",
				                 "states canada australia new zealand ireland",
				                 "and the anglophone caribbean it is used",
				                 "extensively as a second language and as an",
				                 "official language throughout the world",
				                 "especially in commonwealth countries and in",
				                 "many international organizations"};
				_expected = "a";
				_received = _obj.listMostCommon(vector <string>(text, text+sizeof(text)/sizeof(string))); break;
			}
			case 4:
			{
				string text[] = {"amanda forsaken bloomer meditated gauging knolls",
				                 "betas neurons integrative expender commonalities",
				                 "latins antidotes crutched bandwidths begetting",
				                 "prompting dog association athenians christian ires",
				                 "pompousness percolating figured bagatelles bursted",
				                 "ninth boyfriends longingly muddlers prudence puns",
				                 "groove deliberators charter collectively yorks",
				                 "daringly antithesis inaptness aerosol carolinas",
				                 "payoffs chumps chirps gentler inexpressive morales"};
				_expected = "e";
				_received = _obj.listMostCommon(vector <string>(text, text+sizeof(text)/sizeof(string))); break;
			}
			/*case 5:
			{
				string text[] = ;
				_expected = ;
				_received = _obj.listMostCommon(vector <string>(text, text+sizeof(text)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string text[] = ;
				_expected = ;
				_received = _obj.listMostCommon(vector <string>(text, text+sizeof(text)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string text[] = ;
				_expected = ;
				_received = _obj.listMostCommon(vector <string>(text, text+sizeof(text)/sizeof(string))); break;
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
