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
const int tt = 3;
// 
// END CUT HERE

struct State {
  int idx;
  int nrleft;
  int l1;
  int l2;
  int r1;
  int r2;
  State(int idx, int nrleft, int l1, int l2,int r1, int r2) : idx(idx), nrleft(nrleft), l1(l1), l2(l2), r1(r1), r2(r2) {}
  bool operator<(const State& o) const {
    if (idx != o.idx) return idx < o.idx;
    if (nrleft != o.nrleft) return nrleft < o.nrleft;
    if (l1 != o.l1) return l1 < o.l1;
    if (l2 != o.l2) return l2 < o.l2;
    if (r1 != o.r1) return r1 < o.r1;
    return r2 < o.r2;
  }
};
map<State,LL> mem;

class PilingRectsDiv1 {
 public:
  vector<int> X;
  vector<int> Y;
  LL rec(int idx, int nrleft, int l1, int l2, int r1, int r2) {
    if (l1 > r1 || (l1 == r1 && l2 > r2)) {
      swap(l1,r1);
      swap(l2,r2);
      nrleft = idx-nrleft;
    }
    State s(idx,nrleft,l1,l2,r1,r2);
    if (mem.count(s)) return mem[s];
    if (idx == X.size()) {
      if (nrleft != X.size()/2) {
        return mem[s] = -100000;
      }
      return mem[s] = (LL)l1*l2 + (LL)r1*r2;
    }
    LL r = -1000000;
    if (nrleft < X.size()/2)
      r = rec(idx+1,nrleft+1,min(l1,X[idx]),min(l2,Y[idx]),r1,r2);
    if (idx-nrleft < X.size()/2)
      r = max(r,rec(idx+1,nrleft,l1,l2,min(r1,X[idx]),min(r2,Y[idx])));
    return mem[s] = r;
  }
  long long getmax(int N, vector <int> XS, vector <int> YS, int XA, int XB, int XC, int YA, int YB, int YC) {
    mem.clear();
    X = vector<int>(2*N);
    Y = vector<int>(2*N); 
    for (int i=0;i<XS.size();i++) {
      X[i] = XS[i];
      Y[i] = YS[i];
    }
    for (int i=XS.size();i<2*N;i++) {
      X[i] = (X[i-1] * XA + XB) % XC + 1;
      Y[i] = (Y[i-1] * YA + YB) % YC + 1;
    }
    // X always <= Y
    for (int i=0;i<X.size();i++)
      if (X[i] > Y[i])
        swap(X[i],Y[i]);
    return rec(0,0,INT_MAX,INT_MAX,INT_MAX,INT_MAX);
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
		cout << "Testing PilingRectsDiv1 (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392409262;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PilingRectsDiv1 _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int XS[] = {1,2,3,4};
				int YS[] = {10,5,3,5};
				int XA = 0;
				int XB = 0;
				int XC = 1;
				int YA = 0;
				int YB = 0;
				int YC = 1;
				_expected = 14LL;
				_received = _obj.getmax(N, vector <int>(XS, XS+sizeof(XS)/sizeof(int)), vector <int>(YS, YS+sizeof(YS)/sizeof(int)), XA, XB, XC, YA, YB, YC); break;
			}
			case 1:
			{
				int N = 2;
				int XS[] = {7,7};
				int YS[] = {4,4};
				int XA = 9;
				int XB = 0;
				int XC = 10;
				int YA = 2;
				int YB = 7;
				int YC = 9;
				_expected = 56LL;
				_received = _obj.getmax(N, vector <int>(XS, XS+sizeof(XS)/sizeof(int)), vector <int>(YS, YS+sizeof(YS)/sizeof(int)), XA, XB, XC, YA, YB, YC); break;
			}
			case 2:
			{
				int N = 3;
				int XS[] = {5,6,9,10,4,7};
				int YS[] = {9,5,8,6,8,7};
				int XA = 0;
				int XB = 0;
				int XC = 1;
				int YA = 0;
				int YB = 0;
				int YC = 1;
				_expected = 69LL;
				_received = _obj.getmax(N, vector <int>(XS, XS+sizeof(XS)/sizeof(int)), vector <int>(YS, YS+sizeof(YS)/sizeof(int)), XA, XB, XC, YA, YB, YC); break;
			}
			case 3:
			{
				int N = 10000;
				int XS[] = {1000000000};
				int YS[] = {1000000000};
				int XA = 93827162;
				int XB = 91238127;
				int XC = 98231267;
				int YA = 92138287;
				int YB = 98563732;
				int YC = 99381279;
				_expected = 1240119561532788LL;
				_received = _obj.getmax(N, vector <int>(XS, XS+sizeof(XS)/sizeof(int)), vector <int>(YS, YS+sizeof(YS)/sizeof(int)), XA, XB, XC, YA, YB, YC); break;
			}
			case 4:
			{
				int N = 5;
				int XS[] = {375,571,973,896,460,930,583,530,657,590};
				int YS[] = {284,37,994,699,941,745,166,884,270,708};
				int XA = 428;
				int XB = 1000;
				int XC = 788;
				int YA = 851;
				int YB = 125;
				int YC = 894;
				_expected = 420515LL;
				_received = _obj.getmax(N, vector <int>(XS, XS+sizeof(XS)/sizeof(int)), vector <int>(YS, YS+sizeof(YS)/sizeof(int)), XA, XB, XC, YA, YB, YC); break;
			}
			case 5:
			{
				int N = 34734;
				int XS[] = {898,579,465,665,875,391,583,901,326,133,656,562,701,707,492,617,455,441,382,952,689,656,334,877,120,318,497,25,569,962,845,562,632,898,882,498,595,889,382,507,791,548,810,606,105,869,569,970,322,974};
				int YS[] = {83,18,492,27,339,622,851,915,464,347,287,210,282,166,976,167,968,769,14,383,454,983,319,165,185,315,795,851,124,287,846,745,19,639,894,828,540,420,147,452,501,670,466,554,166,1,446,808,508,172};
				int XA = 569;
				int XB = 185;
				int XC = 285;
				int YA = 741;
				int YB = 304;
				int YC = 296;
				_expected = 10050LL;
				_received = _obj.getmax(N, vector <int>(XS, XS+sizeof(XS)/sizeof(int)), vector <int>(YS, YS+sizeof(YS)/sizeof(int)), XA, XB, XC, YA, YB, YC); break;
			}
			/*case 6:
			{
				int N = ;
				int XS[] = ;
				int YS[] = ;
				int XA = ;
				int XB = ;
				int XC = ;
				int YA = ;
				int YB = ;
				int YC = ;
				_expected = LL;
				_received = _obj.getmax(N, vector <int>(XS, XS+sizeof(XS)/sizeof(int)), vector <int>(YS, YS+sizeof(YS)/sizeof(int)), XA, XB, XC, YA, YB, YC); break;
			}*/
			/*case 7:
			{
				int N = ;
				int XS[] = ;
				int YS[] = ;
				int XA = ;
				int XB = ;
				int XC = ;
				int YA = ;
				int YB = ;
				int YC = ;
				_expected = LL;
				_received = _obj.getmax(N, vector <int>(XS, XS+sizeof(XS)/sizeof(int)), vector <int>(YS, YS+sizeof(YS)/sizeof(int)), XA, XB, XC, YA, YB, YC); break;
			}*/
			/*case 8:
			{
				int N = ;
				int XS[] = ;
				int YS[] = ;
				int XA = ;
				int XB = ;
				int XC = ;
				int YA = ;
				int YB = ;
				int YC = ;
				_expected = LL;
				_received = _obj.getmax(N, vector <int>(XS, XS+sizeof(XS)/sizeof(int)), vector <int>(YS, YS+sizeof(YS)/sizeof(int)), XA, XB, XC, YA, YB, YC); break;
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
