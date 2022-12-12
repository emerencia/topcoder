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
const int MAX = 362880;
int mem[MAX+1];

class ColorfulStrings {
 public:
  int n,k;
  string ans;
  string s;
  void rec(int idx) {
    if (idx == n) {
      k--;
      if (k == 0) ans = s;
      return;
    }
    for (int c='0';c<='9';c++) {
      s+=c;
      int t = 1;
      bool ok = true;
      for (int i=idx;i>=0;i--) {
        t*=s[i]-'0';
        if (t > MAX || mem[t]) ok = false;
        if (t <= MAX) mem[t]++;
      }
      if (ok) rec(idx+1);
      t = 1;
      for (int i=idx;i>=0;i--) {
        t*=s[i]-'0';
        if (t <= MAX) mem[t]--;
      }
      s=s.substr(0,s.size()-1);
    }
  }
  string getKth(int n, int k) {
    if (n > 10) return "";
    this->n = n;
    this->k = k;
    memset(mem,0,sizeof(mem));
    ans = "";
    s = "";
    rec(0);
    return ans;
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
		cout << "Testing ColorfulStrings (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1401738557;
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
		ColorfulStrings _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				int k = 4;
				_expected = "238";
				_received = _obj.getKth(n, k); break;
			}
			case 1:
			{
				int n = 4;
				int k = 2000;
				_expected = "";
				_received = _obj.getKth(n, k); break;
			}
			case 2:
			{
				int n = 5;
				int k = 1;
				_expected = "23457";
				_received = _obj.getKth(n, k); break;
			}
			case 3:
			{
				int n = 2;
				int k = 22;
				_expected = "52";
				_received = _obj.getKth(n, k); break;
			}
			case 4:
			{
				int n = 6;
				int k = 464;
				_expected = "257936";
				_received = _obj.getKth(n, k); break;
			}
			case 5:
			{
				int n = 1;
				int k = 1;
				_expected = "0";
				_received = _obj.getKth(n, k); break;
			}
			/*case 6:
			{
				int n = 8;
				int k = 971488;
				_expected = "98746253";
				_received = _obj.getKth(n, k); break;
			}*/
			/*case 7:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.getKth(n, k); break;
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
