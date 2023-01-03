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

class KnockoutTourney {
 public:
  int meetRival(int N, int you, int rival) {
    you--;
    rival--;
    if (you > rival) swap(you,rival);
    vector<int> p;
    for (int i=0;i<N;i++)
      p.push_back(i);
    int c = 1;
    while (true) {
      vector<int> nextp;
      for (int i=1;i<p.size();i+=2) {
        if ((p[i-1] == you && p[i] == rival) ||
            (p[i-1] == rival && p[i] == you)) return c;
        if (p[i-1] == you || p[i] == you) nextp.push_back(you);
        else if (p[i-1] == rival || p[i] == rival) nextp.push_back(rival);
        else nextp.push_back(p[i]);
      }
      if (p.size()%2) nextp.push_back(p.back());
      p = nextp;
      ++c;
    }
    return -1;
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
		cout << "Testing KnockoutTourney (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393009384;
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
		KnockoutTourney _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 16;
				int you = 1;
				int rival = 2;
				_expected = 1;
				_received = _obj.meetRival(N, you, rival); break;
			}
			case 1:
			{
				int N = 16;
				int you = 8;
				int rival = 9;
				_expected = 4;
				_received = _obj.meetRival(N, you, rival); break;
			}
			case 2:
			{
				int N = 1000;
				int you = 20;
				int rival = 31;
				_expected = 4;
				_received = _obj.meetRival(N, you, rival); break;
			}
			case 3:
			{
				int N = 65536;
				int you = 1000;
				int rival = 35000;
				_expected = 16;
				_received = _obj.meetRival(N, you, rival); break;
			}
			case 4:
			{
				int N = 60000;
				int you = 101;
				int rival = 891;
				_expected = 10;
				_received = _obj.meetRival(N, you, rival); break;
			}
			/*case 5:
			{
				int N = ;
				int you = ;
				int rival = ;
				_expected = ;
				_received = _obj.meetRival(N, you, rival); break;
			}*/
			/*case 6:
			{
				int N = ;
				int you = ;
				int rival = ;
				_expected = ;
				_received = _obj.meetRival(N, you, rival); break;
			}*/
			/*case 7:
			{
				int N = ;
				int you = ;
				int rival = ;
				_expected = ;
				_received = _obj.meetRival(N, you, rival); break;
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
