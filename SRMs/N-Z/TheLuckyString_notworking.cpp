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

class TheLuckyString {
 public:
  int count(string s) {
    sort(s.begin(),s.end());
    vector<int> p;
    for (int i=0;i<s.size();i++)
      p.push_back(i);
    int r = 0;
    do {
      int good = true;
      for (int i=1;i<s.size();i++)
        if (s[p[i]] == s[p[i-1]]) {
          good = false;
          break;
        }
      r+=good;
    } while (next_permutation(p.begin(),p.end()));
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
		cout << "Testing TheLuckyString (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393348367;
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
		TheLuckyString _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "ab";
				_expected = 2;
				_received = _obj.count(s); break;
			}
			case 1:
			{
				string s = "aaab";
				_expected = 0;
				_received = _obj.count(s); break;
			}
			case 2:
			{
				string s = "aabbbaa";
				_expected = 1;
				_received = _obj.count(s); break;
			}
			case 3:
			{
				string s = "abcdefghij";
				_expected = 3628800;
				_received = _obj.count(s); break;
			}
			/*case 4:
			{
				string s = ;
				_expected = ;
				_received = _obj.count(s); break;
			}*/
			/*case 5:
			{
				string s = ;
				_expected = ;
				_received = _obj.count(s); break;
			}*/
			/*case 6:
			{
				string s = ;
				_expected = ;
				_received = _obj.count(s); break;
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
