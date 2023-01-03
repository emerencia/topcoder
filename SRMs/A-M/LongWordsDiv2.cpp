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

class LongWordsDiv2 {
 public:
  string find(string word) {
    // check for condition 2
    for (int i=0;i+1 < word.size();i++)
      if (word[i] == word[i+1])
        return "Dislikes";
    // check for rule 3
    for (int i = 0;i<26;i++) {
      char c = 'A' + i;
      int firstpos = word.find(c);
      if (firstpos == string::npos) continue;
      set<char> forbidden;
      set<char> seen;
      int seencount = 1;
      for (int j = firstpos+1;j < word.size();j++) {
        if (word[j] == c) {
          seencount++;
          if (seencount == 4) return "Dislikes";
          for (set<char>::iterator k = seen.begin();k!=seen.end();k++)
            forbidden.insert(*k);
          seen.clear();
        } else {
          if (forbidden.count(word[j])) return "Dislikes";
          seen.insert(word[j]);
        }
      }
    }
    return "Likes";
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
		cout << "Testing LongWordsDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1433953893;
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
		LongWordsDiv2 _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string word = "AAA";
				_expected = "Dislikes";
				_received = _obj.find(word); break;
			}
			case 1:
			{
				string word = "ABCBA";
				_expected = "Likes";
				_received = _obj.find(word); break;
			}
			case 2:
			{
				string word = "ABCBAC";
				_expected = "Dislikes";
				_received = _obj.find(word); break;
			}
			case 3:
			{
				string word = "TOPCODER";
				_expected = "Likes";
				_received = _obj.find(word); break;
			}
			case 4:
			{
				string word = "VAMOSGIMNASIA";
				_expected = "Dislikes";
				_received = _obj.find(word); break;
			}
			case 5:
			{
				string word = "SINGLEROUNDMATCH";
				_expected = "Likes";
				_received = _obj.find(word); break;
			}
			case 6:
			{
				string word = "DALELOBO";
				_expected = "Likes";
				_received = _obj.find(word); break;
			}
			/*case 7:
			{
				string word = ;
				_expected = ;
				_received = _obj.find(word); break;
			}*/
			/*case 8:
			{
				string word = ;
				_expected = ;
				_received = _obj.find(word); break;
			}*/
			/*case 9:
			{
				string word = ;
				_expected = ;
				_received = _obj.find(word); break;
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
