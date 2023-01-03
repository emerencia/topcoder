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
int mem[3002][3002];

class EmoticonsDiv2 {
 public:
  int smiles;
  int rec(int done, int onclipboard) {
    int& r = mem[done][onclipboard];
    if (r != -1) return r;
    if (done > smiles) return r = 100000;
    if (done == smiles) return r = 0;
    int t = INT_MAX;
    if (onclipboard)
      t = 1+rec(done+onclipboard,onclipboard);
    t = min(t,2+rec(done+done,done));
    return r = t;
  }
  int printSmiles(int smiles) {
    this->smiles = smiles;
    memset(mem,-1,sizeof(mem));
    return rec(1,0);
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
		cout << "Testing EmoticonsDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395427049;
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
		EmoticonsDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int smiles = 2;
				_expected = 2;
				_received = _obj.printSmiles(smiles); break;
			}
			case 1:
			{
				int smiles = 6;
				_expected = 5;
				_received = _obj.printSmiles(smiles); break;
			}
			case 2:
			{
				int smiles = 11;
				_expected = 11;
				_received = _obj.printSmiles(smiles); break;
			}
			case 3:
			{
				int smiles = 16;
				_expected = 8;
				_received = _obj.printSmiles(smiles); break;
			}
			case 4:
			{
				int smiles = 1000;
				_expected = 21;
				_received = _obj.printSmiles(smiles); break;
			}
			/*case 5:
			{
				int smiles = ;
				_expected = ;
				_received = _obj.printSmiles(smiles); break;
			}*/
			/*case 6:
			{
				int smiles = ;
				_expected = ;
				_received = _obj.printSmiles(smiles); break;
			}*/
			/*case 7:
			{
				int smiles = ;
				_expected = ;
				_received = _obj.printSmiles(smiles); break;
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
