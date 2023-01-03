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

class TaroString {
 public:
  string getAnswer(string S) {
    // my solution: simulation
    // other solution: for any two letters in cat, make sure that they are in the correct order
    // this works as long as you assert that cat is in there.
    // other solution: go through the string in order, add to a string anything that is in CAT,
    // and check if you get CAT at the end.
    int state = 0;
    int ccount = 0,acount = 0,tcount = 0;
    for (int i=0;i<S.size();i++) {
      if (S[i] == 'C') {
        ++ccount;
        if (ccount == 2) return "Impossible";
      }
      if (S[i] == 'A') {
        ++acount;
        if (acount == 2) return "Impossible";
      }
      if (S[i] == 'T') {
        ++tcount;
        if (tcount == 2) return "Impossible";
      }
      if (state == 0 && S[i] == 'C') {
        state = 1;
      } else if (state == 1 && S[i] == 'A') {
        state = 2;
      } else if (state == 2 && S[i] == 'T') {
        state = 3;
      }
    }
    if (state == 3) return "Possible";
    return "Impossible";
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
		cout << "Testing TaroString (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1423263920;
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
		TaroString _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "XCYAZTX";
				_expected = "Possible";
				_received = _obj.getAnswer(S); break;
			}
			case 1:
			{
				string S = "CTA";
				_expected = "Impossible";
				_received = _obj.getAnswer(S); break;
			}
			case 2:
			{
				string S = "ACBBAT";
				_expected = "Impossible";
				_received = _obj.getAnswer(S); break;
			}
			case 3:
			{
				string S = "SGHDJHFIOPUFUHCHIOJBHAUINUIT";
				_expected = "Possible";
				_received = _obj.getAnswer(S); break;
			}
			case 4:
			{
				string S = "CCCATT";
				_expected = "Impossible";
				_received = _obj.getAnswer(S); break;
			}
			/*case 5:
			{
				string S = ;
				_expected = ;
				_received = _obj.getAnswer(S); break;
			}*/
			/*case 6:
			{
				string S = ;
				_expected = ;
				_received = _obj.getAnswer(S); break;
			}*/
			/*case 7:
			{
				string S = ;
				_expected = ;
				_received = _obj.getAnswer(S); break;
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
