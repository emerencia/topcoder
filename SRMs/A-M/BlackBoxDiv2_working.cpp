#include <string>
#include <iostream>
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
const int kMod = 1e9+7;
const int kSize = 2501;

int fact[kSize];
int inv[kSize];
long long pw(int a, int b) {
  int x = 1, step = 1 << 30;
  while (step > 0) {
    x = (long long)x * x % kMod;
    if (step & b) x = (long long)x * a % kMod;
    step >>= 1;
  }
  return x;
}
long long bico(int n, int k) {
  if (n < 0 || k < 0 || k > n) return 0;
  int x = fact[n];
  int y = inv[k];
  int z = inv[n - k];
  return (long long)x * y % kMod * z % kMod;
}

LL mem[51][2501];
class BlackBoxDiv2 {
 public:
  int totrows;
  int totcols;
  LL rec(int rowsleft, int colsleft) {
    LL& r = mem[rowsleft][colsleft];
    if (r != -1) return r;
    if (rowsleft == 0) {
      return r = (colsleft == 0);
    }
    LL t = 0;
    for (int i=0;i<=colsleft;i++) {
      (t+=((((pw(2,totcols-colsleft)-(i == 0))*bico(colsleft,i))%kMod)*rec(rowsleft-1,colsleft-i))%kMod)%=kMod;
    }
    return r = t;
  }
  int count(string front, string side) {
    fact[0] = 1;
    for (int i = 1; i < kSize; i++) fact[i] = (long long)fact[i - 1] * i % kMod;
    inv[0] = 1;
    for (int i = 1; i < kSize; i++) inv[i] = pw(fact[i], kMod - 2);
    memset(mem,-1,sizeof(mem));
    totrows = 0;
    for (int i=0;i<front.size();i++)
      totrows+=front[i] == 'B';
    totcols = 0;
    for (int i=0;i<side.size();i++)
      totcols+=side[i] == 'B';
    if (totrows == 0 && totcols) return 0;
    if (totrows == 0 && totcols == 0) return 1;
    return rec(totrows,totcols);
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
		cout << "Testing BlackBoxDiv2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391904605;
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
		BlackBoxDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string front = "BB";
				string side = "BB";
				_expected = 7;
				_received = _obj.count(front, side); break;
			}
			case 1:
			{
				string front = "...";
				string side = ".....";
				_expected = 1;
				_received = _obj.count(front, side); break;
			}
			case 2:
			{
				string front = "...";
				string side = "BBB";
				_expected = 0;
				_received = _obj.count(front, side); break;
			}
			case 3:
			{
				string front = "...BB.B....";
				string side = "B.B.B.B.B";
				_expected = 16081;
				_received = _obj.count(front, side); break;
			}
			case 4:
			{
				string front = "BBBBB.BBBBBBBBB.BBBBBBB.BBBB.B.BB..BB.B.BBBBBBBBBB";
				string side = ".B.BBB..BBBBBB.BBBB.B...BBBB.BB.BBBBBBBBBB.....BBB";
				_expected = 771030153;
				_received = _obj.count(front, side); break;
			}
			/*case 5:
			{
				string front = ;
				string side = ;
				_expected = ;
				_received = _obj.count(front, side); break;
			}*/
			/*case 6:
			{
				string front = ;
				string side = ;
				_expected = ;
				_received = _obj.count(front, side); break;
			}*/
			/*case 7:
			{
				string front = ;
				string side = ;
				_expected = ;
				_received = _obj.count(front, side); break;
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
