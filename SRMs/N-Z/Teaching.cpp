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

class Teaching {
 public:
  vector<int> binarywords;
  int K;
  int bitcount(int n) {
    int r = 0;
    for (int i=n;i;i&=i-1) ++r;
    return r;
  }
  int rec(int idx, int known) {
    if (idx == 26) {
      int c = 0;
      for (int i=0;i<binarywords.size();i++)
        if ((known&binarywords[i]) == binarywords[i]) ++c;
      return c;
    }
    if (known&(1<<idx)) return rec(idx+1,known);
    int r = rec(idx+1,known);
    if (bitcount(known) < K)
      r = max(r,rec(idx+1,known|(1<<idx)));
    return r;
  }
  int count(vector <string> words, int K) {
    if (K < 5) return 0;
    this->K = K;
    binarywords.clear();
    for (int i=0;i<words.size();i++) {
      int word = 0;
      for (int j=0;j<words[i].size();j++)
        word |= (1<<(words[i][j]-'a'));
      binarywords.push_back(word);
    }
    string always = "acnti";
    int start = 0;
    for (int i=0;i<always.size();i++)
      start |= (1<<(always[i]-'a'));
    return rec(0,start);
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
		cout << "Testing Teaching (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393337538;
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
		Teaching _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string words[] = {"antarctica","antahellotica","antacartica"};
				int K = 6;
				_expected = 2;
				_received = _obj.count(vector <string>(words, words+sizeof(words)/sizeof(string)), K); break;
			}
			case 1:
			{
				string words[] = {"antaxxxxxxxtica","antarctica"};
				int K = 3;
				_expected = 0;
				_received = _obj.count(vector <string>(words, words+sizeof(words)/sizeof(string)), K); break;
			}
			case 2:
			{
				string words[] = {"antabtica","antaxtica","antadtica","antaetica","antaftica",
				                  "antagtica","antahtica","antajtica","antaktica"};
				int K = 8;
				_expected = 3;
				_received = _obj.count(vector <string>(words, words+sizeof(words)/sizeof(string)), K); break;
			}
			/*case 3:
			{
				string words[] = ;
				int K = ;
				_expected = ;
				_received = _obj.count(vector <string>(words, words+sizeof(words)/sizeof(string)), K); break;
			}*/
			/*case 4:
			{
				string words[] = ;
				int K = ;
				_expected = ;
				_received = _obj.count(vector <string>(words, words+sizeof(words)/sizeof(string)), K); break;
			}*/
			/*case 5:
			{
				string words[] = ;
				int K = ;
				_expected = ;
				_received = _obj.count(vector <string>(words, words+sizeof(words)/sizeof(string)), K); break;
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
