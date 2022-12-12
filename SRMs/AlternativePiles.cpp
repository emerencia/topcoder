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
int mem[5001][51][51];
const int kMod = 1e9+7;

class AlternativePiles {
 public:
  string C;
  int M;
  int rec(int idx, int nr_colored_red, int balance) {
    // balance is R-G
    int& r = mem[idx][nr_colored_red][balance];
    if (r != -1) return r;
   if (idx == C.size()) {
      if (balance == 0 && nr_colored_red == 0) return r = 1;
      return r = 0;
    }
    if (C[idx] == 'R') {
      if (balance == M) return r = 0;
      return r = rec(idx+1, (nr_colored_red+1)%M, balance + 1);
    } else if (C[idx] == 'G') {
      if (balance == 0) return r = 0;
      return r = rec(idx+1, nr_colored_red, balance - 1);
    } else if (C[idx] == 'B') {
      return r = rec(idx+1, nr_colored_red, balance);
    } else { // C[idx] == 'W'
      LL t = rec(idx+1, nr_colored_red, balance);
      if (balance < M)
        (t += rec(idx+1, (nr_colored_red+1)%M, balance + 1))%=kMod;
      if (balance > 0)
        (t += rec(idx+1, nr_colored_red, balance - 1))%=kMod;
      return r = t;
    }
  }
  int count(string C, int M) {
    this->C = C;
    this->M = M;
    memset(mem,-1,sizeof(mem));
    return rec(0,0,0);
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
		cout << "Testing AlternativePiles (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1427738966;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 950.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AlternativePiles _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string C = "WRGWWRGW";
				int M = 2;
				_expected = 3;
				_received = _obj.count(C, M); break;
			}
			case 1:
			{
				string C = "RRGG";
				int M = 1;
				_expected = 0;
				_received = _obj.count(C, M); break;
			}
			case 2:
			{
				string C = "BBBB";
				int M = 5;
				_expected = 1;
				_received = _obj.count(C, M); break;
			}
			case 3:
			{
				string C = "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW";
				int M = 50;
				_expected = 265470435;
				_received = _obj.count(C, M); break;
			}
			case 4:
			{
				string C = "WRWRGWWGWWWRWBWRWGWWRWBWWRGWBWGRGWWGWGRWGRWBRWBW";
				int M = 7;
				_expected = 7400348;
				_received = _obj.count(C, M); break;
			}
			/*case 5:
			{
				string C = ;
				int M = ;
				_expected = ;
				_received = _obj.count(C, M); break;
			}*/
			/*case 6:
			{
				string C = ;
				int M = ;
				_expected = ;
				_received = _obj.count(C, M); break;
			}*/
			/*case 7:
			{
				string C = ;
				int M = ;
				_expected = ;
				_received = _obj.count(C, M); break;
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
