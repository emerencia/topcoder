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

int mem[51][2501];

class SentenceDecomposition {
 public:
  string sentence;
  vector<string> vw;
  int calcscore(string to, string from) {
    string nto = to;
    string nfrom = from;
    sort(nto.begin(),nto.end());
    sort(nfrom.begin(),nfrom.end());
    if (nto != nfrom) return -1;
    int r = 0;
    for (int i=0;i<to.size();i++)
      r+= from[i] != to[i];
    return r;
  }
  int rec(int idx, int cost) {
    int& r = mem[idx][cost];
    if (r != -1) return r;
    if (idx == sentence.size()) 
      return r = cost;
    int t = INT_MAX;
    for (int i=0;i<vw.size();i++) {
      if (idx+vw[i].size() > sentence.size()) continue;
      int sco = calcscore(sentence.substr(idx,vw[i].size()),vw[i]);
      if (sco == -1) continue;
      int rp = rec(idx+vw[i].size(),cost+sco);
      if (rp != INT_MAX)
        t = min(t,rp);
    }
    return r = t;
  }
  int decompose(string sentence, vector <string> validWords) {
    memset(mem,-1,sizeof(mem));
    this->sentence = sentence;
    this->vw = validWords;
    int r = rec(0,0);
    return (r == INT_MAX ? -1 : r);
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
		cout << "Testing SentenceDecomposition (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1389904704;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SentenceDecomposition _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string sentence = "neotowheret";
				string validWords[] = {"one", "two", "three", "there"};
				_expected = 8;
				_received = _obj.decompose(sentence, vector <string>(validWords, validWords+sizeof(validWords)/sizeof(string))); break;
			}
			case 1:
			{
				string sentence = "abba";
				string validWords[] = {"ab", "ac", "ad"};
				_expected = 2;
				_received = _obj.decompose(sentence, vector <string>(validWords, validWords+sizeof(validWords)/sizeof(string))); break;
			}
			case 2:
			{
				string sentence = "thisismeaningless";
				string validWords[] = {"this", "is", "meaningful"};
				_expected = -1;
				_received = _obj.decompose(sentence, vector <string>(validWords, validWords+sizeof(validWords)/sizeof(string))); break;
			}
			case 3:
			{
				string sentence = "ommwreehisymkiml";
				string validWords[] = {"we", "were", "here", "my", "is", "mom", "here", "si", "milk", "where", "si"};
				_expected = 10;
				_received = _obj.decompose(sentence, vector <string>(validWords, validWords+sizeof(validWords)/sizeof(string))); break;
			}
			case 4:
			{
				string sentence = "ogodtsneeencs";
				string validWords[] = {"go", "good", "do", "sentences", "tense", "scen"};
				_expected = 8;
				_received = _obj.decompose(sentence, vector <string>(validWords, validWords+sizeof(validWords)/sizeof(string))); break;
			}
			case 5:
			{
				string sentence = "sepawaterords";
				string validWords[] = {"separate","words"};
				_expected = -1;
				_received = _obj.decompose(sentence, vector <string>(validWords, validWords+sizeof(validWords)/sizeof(string))); break;
			}
			/*case 6:
			{
				string sentence = ;
				string validWords[] = ;
				_expected = ;
				_received = _obj.decompose(sentence, vector <string>(validWords, validWords+sizeof(validWords)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string sentence = ;
				string validWords[] = ;
				_expected = ;
				_received = _obj.decompose(sentence, vector <string>(validWords, validWords+sizeof(validWords)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string sentence = ;
				string validWords[] = ;
				_expected = ;
				_received = _obj.decompose(sentence, vector <string>(validWords, validWords+sizeof(validWords)/sizeof(string))); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
