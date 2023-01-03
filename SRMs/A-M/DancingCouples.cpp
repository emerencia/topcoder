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
bool g[11][11];
int mem[11][11][1<<11];

class DancingCouples {
 public:
  int nl;
  int nr;
  bool bpm(int l,vector<int>& leftof,vector<bool>& seenl, vector<bool>& seenr) {
    if (seenl[l]) return false;
    seenl[l] = true;
    for (int r=0;r<nr;r++) {
      if (seenr[r] || !g[l][r]) continue;
      seenr[r] = true;
      if (leftof[r] == -1 || bpm(leftof[r],leftof,seenl,seenr)) {
        leftof[r] = l;
        return true;
      }
    }
    return false;
  }
  int calc() {
    vector<int> leftof(nr,-1);
    int r = 0;
    for (int l=0;l<nl;l++) {
      vector<bool> seenl(nl,0);
      vector<bool> seenr(nr,0);
      r+= bpm(l,leftof,seenl,seenr);
    }
    return r;
  }
  int rec(int idx, int pairsleft, int taken) {
    int& r = mem[idx][pairsleft][taken];
    if (r != -1) return r;
    if (pairsleft == 0) return r = 1;
    if (idx == nl) return r = 0;
    int t = rec(idx+1,pairsleft,taken);  // don't take current
    for (int i=0;i<nr;i++) {
      if (taken&(1<<i) || !(g[idx][i])) continue;
      t+=rec(idx+1,pairsleft-1,taken | (1<<i));
    }
    return r = t;
  }
  int countPairs(vector <string> canDance, int K) {
    memset(mem,-1,sizeof(mem));
    nl = canDance.size();
    nr = canDance[0].size();
    for (int i=0;i<nl;i++)
      for (int j=0;j<nr;j++)
        g[i][j] = canDance[i][j] == 'Y';
    int n = calc();
    if (K > n) return 0;
    return rec(0,K,0);
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
		cout << "Testing DancingCouples (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390592470;
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
		DancingCouples _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string canDance[] = {"YYYY", 
				                     "YYYY",
				                     "YYYY"};
				int K = 3;
				_expected = 24;
				_received = _obj.countPairs(vector <string>(canDance, canDance+sizeof(canDance)/sizeof(string)), K); break;
			}
			case 1:
			{
				string canDance[] = {"YYNN", 
				                     "NYYN", 
				                     "NNYY"};
				int K = 3;
				_expected = 4;
				_received = _obj.countPairs(vector <string>(canDance, canDance+sizeof(canDance)/sizeof(string)), K); break;
			}
			case 2:
			{
				string canDance[] = {"YY", 
				                     "YY", 
				                     "YY"};
				int K = 3;
				_expected = 0;
				_received = _obj.countPairs(vector <string>(canDance, canDance+sizeof(canDance)/sizeof(string)), K); break;
			}
			case 3:
			{
				string canDance[] = {"YYNNNN",
				                     "NYYNNN",
				                     "NNYYNN",
				                     "NNNYYN",
				                     "NNNNYY",
				                     "YNNNNY"};
				int K = 3;
				_expected = 112;
				_received = _obj.countPairs(vector <string>(canDance, canDance+sizeof(canDance)/sizeof(string)), K); break;
			}
			/*case 4:
			{
				string canDance[] = ;
				int K = ;
				_expected = ;
				_received = _obj.countPairs(vector <string>(canDance, canDance+sizeof(canDance)/sizeof(string)), K); break;
			}*/
			/*case 5:
			{
				string canDance[] = ;
				int K = ;
				_expected = ;
				_received = _obj.countPairs(vector <string>(canDance, canDance+sizeof(canDance)/sizeof(string)), K); break;
			}*/
			/*case 6:
			{
				string canDance[] = ;
				int K = ;
				_expected = ;
				_received = _obj.countPairs(vector <string>(canDance, canDance+sizeof(canDance)/sizeof(string)), K); break;
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
