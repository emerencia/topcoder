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

class MagicalStringDiv1 {
 public:
  int getLongest(string S) {
    int r = 0;
    for (int i=0;i<=S.size();i++) {
      int goodcountl = 0;
      for (int j=0;j<i;j++)
        if (S[j] == '>') ++goodcountl;
      int goodcountr = 0;
      for (int j=i;j<S.size();j++)
        if (S[j] == '<') ++goodcountr;
      int halfsize = min(goodcountl,goodcountr);
      r = max(r,2*halfsize);
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
	string a = tt == -1 ? "0" : string(1,'0'+tt);
	char* b[2] = {argv[0],(char*)a.c_str()};
	if(tt!=-1){argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing MagicalStringDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1416606854;
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
		MagicalStringDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "<><><<>";
				_expected = 4;
				_received = _obj.getLongest(S); break;
			}
			case 1:
			{
				string S = ">>><<<";
				_expected = 6;
				_received = _obj.getLongest(S); break;
			}
			case 2:
			{
				string S = "<<<>>>";
				_expected = 0;
				_received = _obj.getLongest(S); break;
			}
			case 3:
			{
				string S = "<<<<><>>><>>><>><>><>>><<<<>><>>>>><<>>>>><><<<<>>";
				_expected = 24;
				_received = _obj.getLongest(S); break;
			}
			/*case 4:
			{
				string S = ;
				_expected = ;
				_received = _obj.getLongest(S); break;
			}*/
			/*case 5:
			{
				string S = ;
				_expected = ;
				_received = _obj.getLongest(S); break;
			}*/
			/*case 6:
			{
				string S = ;
				_expected = ;
				_received = _obj.getLongest(S); break;
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
