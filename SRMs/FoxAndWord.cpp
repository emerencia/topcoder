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

class FoxAndWord {
 public:
  int howManyPairs(vector <string> words) {
    int r = 0;
    for (int i=0;i<words.size();i++)
      for (int j=i+1;j<words.size();j++) {
        if (words[i].size() != words[j].size()) continue;
        int good = false;
        for (int k=1;k<words[i].size();k++)
          if (words[i] == words[j].substr(k)+words[j].substr(0,k)) {
            good = true;
            break;
          }
        r+=good;
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
	if(tt!=-1){char* b[2];b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}	if (argc == 1) 
	{
		cout << "Testing FoxAndWord (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394218772;
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
		FoxAndWord _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string words[] = {"tokyo", "kyoto"};
				_expected = 1;
				_received = _obj.howManyPairs(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 1:
			{
				string words[] = {"aaaaa", "bbbbb"};
				_expected = 0;
				_received = _obj.howManyPairs(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 2:
			{
				string words[] = {"ababab","bababa","aaabbb"};
				_expected = 1;
				_received = _obj.howManyPairs(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 3:
			{
				string words[] = {"eel", "ele", "lee"};
				_expected = 3;
				_received = _obj.howManyPairs(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 4:
			{
				string words[] = {"aaa", "aab", "aba", "abb", "baa", "bab", "bba", "bbb"};
				_expected = 6;
				_received = _obj.howManyPairs(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 5:
			{
				string words[] = {"top","coder"};
				_expected = 0;
				_received = _obj.howManyPairs(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			/*case 6:
			{
				string words[] = ;
				_expected = ;
				_received = _obj.howManyPairs(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string words[] = ;
				_expected = ;
				_received = _obj.howManyPairs(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string words[] = ;
				_expected = ;
				_received = _obj.howManyPairs(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
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
