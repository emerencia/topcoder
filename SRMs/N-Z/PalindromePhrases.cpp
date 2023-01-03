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
// done at 18:42
// END CUT HERE
LL mem[1<<13][2][14][14];

class PalindromePhrases {
 public:
  vector<string> words;
  vector<bool> palindromicwords;
  bool isPalindrome(const string& s) {
    for (int i=0;i<s.size()/2;i++)
      if (s[i] != s[s.size()-i-1]) 
        return false;
    return true; 
  }
  bool reverseeq(const string& a, const string& b) {
    if (a.size() != b.size()) return false;
    for (int i=0;i<a.size();i++)
      if (a[i] != b[b.size()-i-1])
        return false;
    return true;
  }
  LL rec(int state, int cur, int curpos, int curidx) {
    LL& r = mem[state][cur][curpos][curidx];
    if (r != -1) return r;
    LL t = 0;
    if (cur == 0) {
      // current elem is left
      string s = words[curidx].substr(curpos);
      t+= isPalindrome(s);
      for (int i=0;i<words.size();i++) {
        if (state&(1<<i)) continue;
        int sizediff = abs((int)s.size()-(int)words[i].size());
        if (s.size() <= words[i].size()) {
          // continue with word on right
          if (reverseeq(s,words[i].substr(sizediff))) {
            t+=rec(state|(1<<i),1,sizediff,i);
          }
        } else {
          // continue with word on left 
          int offset = words[i].size();
          if (reverseeq(s.substr(0,offset),words[i])) {
            t+=rec(state|(1<<i),0,offset+curpos,curidx);
          }
        }
      }
    } else {
      // current elem is right;
      string s = words[curidx].substr(0,curpos);
      t+=isPalindrome(s);
      for (int i=0;i<words.size();i++) {
        if (state&(1<<i)) continue;
        int sizediff = abs((int)s.size()-(int)words[i].size());
        if (s.size() <= words[i].size()) {
          // continue on left
          int offset = s.size();
          if (reverseeq(s,words[i].substr(0,offset))) {
            t+=rec(state|(1<<i),0,offset,i);
          }
        } else {
          // continue with right
          if (reverseeq(words[i],s.substr(sizediff))) {
            t+=rec(state|(1<<i),1,sizediff,curidx);
          }
        }
      }
    }
    return r = t;
  }
  long long getAmount(vector <string> words) {
    this->words = words;
    palindromicwords = vector<bool>(words.size(),false);
    for (int i=0;i<words.size();i++)
      palindromicwords[i] = isPalindrome(words[i]);
    memset(mem,-1,sizeof(mem));
    LL r = rec(0,1,0,0)-1;
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
		cout << "Testing PalindromePhrases (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395075525;
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
		PalindromePhrases _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string words[] = {"a","ba"};
				_expected = 2LL;
				_received = _obj.getAmount(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 1:
			{
				string words[] = {"ab","bcd","efg"};
				_expected = 0LL;
				_received = _obj.getAmount(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 2:
			{
				string words[] = {"a", "bba", "abb"};
				_expected = 7LL;
				_received = _obj.getAmount(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 3:
			{
				string words[] = {"aabccc", "ccbbca", "a", "acaabb", "aaa", "aab", "c", "babb", "aacaa", "b"};
				_expected = 47LL;
				_received = _obj.getAmount(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 4:
			{
				string words[] = {"a", "b", "aa", "ab", "ba", "bb", "aaa", "aab", "aba", "abb", "baa", "bab", "bba"};
				_expected = 1081925LL;
				_received = _obj.getAmount(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 5:
			{
				string words[] = {"aaaaaaaaaaa", "aaa", "aaaaaaaaaa", "aaaaaaaaa", "a", "aaaaaaa", "aaaaaaaa", "aaaaaa", "aaaaa", "aaaaaaaaaaaa", "aaaa", "aa", "aaaaaaaaaaaaa"};
				_expected = 16926797485LL;
				_received = _obj.getAmount(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			} 
			/*case 6:
			{
				string words[] = ;
				_expected = LL;
				_received = _obj.getAmount(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
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
