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

class Palindromize {
 public:
  bool ispalindrome(const string& s) {
    for (int i=0;i<s.size()/2;i++)
      if (s[i] != s[s.size()-1-i])
        return false;
    return true;
  }
  string minAdds(string s) {
    for (int i=0;i<s.size();i++)
      if (ispalindrome(s.substr(i))) {
        string a = s.substr(0,i);
        reverse(a.begin(),a.end());
        return s+a;
      }
    string r = s;
    reverse(r.begin(),r.end());
    return s+r;
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
	char* b[2];
	if(tt!=-1){b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing Palindromize (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396911966;
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
		Palindromize _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "add";
				_expected = "adda";
				_received = _obj.minAdds(s); break;
			}
			case 1:
			{
				string s = "cigartragic";
				_expected = "cigartragic";
				_received = _obj.minAdds(s); break;
			}
			case 2:
			{
				string s = "redocpot";
				_expected = "redocpotopcoder";
				_received = _obj.minAdds(s); break;
			}
			case 3:
			{
				string s = "acaba";
				_expected = "acabaca";
				_received = _obj.minAdds(s); break;
			}
			case 4:
			{
				string s = "abczyxyz";
				_expected = "abczyxyzcba";
				_received = _obj.minAdds(s); break;
			}
			/*case 5:
			{
				string s = ;
				_expected = ;
				_received = _obj.minAdds(s); break;
			}*/
			/*case 6:
			{
				string s = ;
				_expected = ;
				_received = _obj.minAdds(s); break;
			}*/
			/*case 7:
			{
				string s = ;
				_expected = ;
				_received = _obj.minAdds(s); break;
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
