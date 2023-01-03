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
typedef pair<double,LL> PDLL;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE

class CutSticks {
 public:
  int C,K,mincutstomake;
  vector<double> cuts;
  vector<int> sticks;
  double rec(int idx, LL cutsmadesofar, vector<PDLL>& pieces) {
    if (idx == cuts.size()) {
      if (cutsmadesofar >= K && cutsmadesofar-(int)sticks.size() <= C) {
        vector<PDLL> p2 = pieces;
        sort(p2.rbegin(),p2.rend());
        LL c = 0;
        for (int i=0;i<p2.size();i++) {
          c+=p2[i].second;
          if (c >= cutsmadesofar) return p2[i].first;
        }
        return 0;
      }
      return -INT_MAX;
    }
    int approxcuts = cuts[idx];
    double r = 0;
    for (int i=max(1,approxcuts-2);i<=approxcuts+2;i++) {
      pieces[idx] = PDLL(double(sticks[idx])/i,i);
      r = max(r,rec(idx+1,cutsmadesofar+i,pieces));
      pieces[idx] = PDLL(0,0);
    }
    return r;
  }
  double maxKth(vector <int> sticks, int C, int K) {
    this->C = C;
    this->K = K;
    mincutstomake = K-sticks.size();
    if (mincutstomake <= 0) {
      sort(sticks.rbegin(),sticks.rend());
      return sticks[K-1];
    }
    cuts.clear();
    LL totlen = accumulate(sticks.begin(),sticks.end(),0LL);
    sort(sticks.rbegin(),sticks.rend());
    this->sticks = sticks;
    for (int i=0;i<sticks.size();i++)
      cuts.push_back(double((LL)sticks[i]*mincutstomake)/totlen);
    vector<PDLL> p(sticks.size(),PDLL(0,0));
    return rec(0,0,p);
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
		cout << "Testing CutSticks (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1399124116;
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
		CutSticks _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int sticks[] = {5, 8};
				int C = 1;
				int K = 1;
				_expected = 8.0;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}
			case 1:
			{
				int sticks[] = {5, 8};
				int C = 1;
				int K = 2;
				_expected = 5.0;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}
			case 2:
			{
				int sticks[] = {5, 8};
				int C = 1;
				int K = 3;
				_expected = 4.0;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}
			case 3:
			{
				int sticks[] = {1000000000, 1000000000, 1};
				int C = 2;
				int K = 5;
				_expected = 1.0;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}
			case 4:
			{
				int sticks[] = {76, 594, 17, 6984, 26, 57, 9, 876, 5816, 73, 969, 527, 49};
				int C = 789;
				int K = 456;
				_expected = 34.92;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}
			/*case 5:
			{
				int sticks[] = ;
				int C = ;
				int K = ;
				_expected = ;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}*/
			/*case 6:
			{
				int sticks[] = ;
				int C = ;
				int K = ;
				_expected = ;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}*/
			/*case 7:
			{
				int sticks[] = ;
				int C = ;
				int K = ;
				_expected = ;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(3);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
