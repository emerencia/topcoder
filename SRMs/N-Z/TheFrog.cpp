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

class TheFrog {
 public:
  vector<int> L;
  vector<int> R;
  vector<PII> intervals;
  int D;
  void addjumps(double s, vector<double>& jumps) {
    for (int k=1;s/k>=1;k++)
      jumps.push_back(s/k);
  }
  bool can(double j) {
    for (int i=0;i<L.size();i++) {
      int start = L[i]/j+1e-9;
      int end = R[i]/j-1e-9;
      if (start < end) return false;
    }
    return true;
  }
  double getMinimum(int D, vector <int> L, vector <int> R) {
    this->L = L;
    this->R = R;
    this->D = D;
    intervals.clear();
    vector<double> jumps;
    for (int i=0;i<L.size();i++) {
      intervals.push_back(PII(L[i],R[i]));
      addjumps(R[i],jumps);
    }
    sort(intervals.begin(),intervals.end());
    sort(jumps.begin(),jumps.end());
    for (int i=0;i<jumps.size();i++)
      if ((i == 0 || jumps[i]-jumps[i-1] > 1e-9) && can(jumps[i]))
        return jumps[i];
    return D;
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
		cout << "Testing TheFrog (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396726212;
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
		TheFrog _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int D = 16;
				int L[] = {2};
				int R[] = {7};
				_expected = 7.0;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 1:
			{
				int D = 25;
				int L[] = {11, 3};
				int R[] = {21, 7};
				_expected = 10.5;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 2:
			{
				int D = 100;
				int L[] = {0};
				int R[] = {100};
				_expected = 100.0;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 3:
			{
				int D = 100;
				int L[] = {0, 50};
				int R[] = {50, 100};
				_expected = 50.0;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 4:
			{
				int D = 30000;
				int L[] = {17, 25281, 5775, 2825, 14040};
				int R[] = {55, 26000, 5791, 3150, 14092};
				_expected = 787.8787878787879;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 5:
			{
				int D = 444;
				int L[] = {336, 402, 233, 397, 153, 297};
				int R[] = {340, 405, 237, 399, 156, 300};
				_expected = 5.4;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 6:
			{
				int D = 30000;
				int L[] = {0, 20100, 20101};
				int R[] = {1, 20101, 20103};
				_expected = 2.0000995024875623;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 7:
			{
				int D = 9853;
				int L[] = {6525, 3235, 3796, 8375};
				int R[] = {6529, 3236, 3800, 8379};
				_expected = 4.166666666666667;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
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
