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
typedef pair<PII,int> PIII;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE

class TreesDivision {
 public:
  int cross_prod(const PIII& p, const PIII& from, const PIII& to) {
    int d = (to.first.first-from.first.first)*(p.first.second -from.first.second) -
    (to.first.second-from.first.second)*(p.first.first - from.first.first);
    //return d>=0;
    return d;
  }
  int minDifference(vector <int> x, vector <int> y, vector <int> income) {
    vector<PIII> lines;
    int n = x.size();
    for (int i=0;i<n;i++)
      lines.push_back(PIII(PII(x[i],y[i]),income[i]));
    LL mndiff = INT_MAX;
    for (int i=0;i<n;i++) {
      PIII from = lines[i];
      for (int j=i+1;j<n;j++) {
        PIII to = lines[j];
        LL priced = 0;
        bool good = true;
        LL pricea = from.second;
        LL priceb = to.second;
        int dim = 0;
        if (abs(to.first.second-from.first.second) > 
            abs(to.first.first-from.first.first))
            dim = 1;
        for (int k=0;k<n;k++) {
          if (k == i || k == j) continue;
          int d = cross_prod(lines[k],from,to);
          if (d == 0) {
            if (dim == 0) {
              LL da = to.first.first-from.first.first;
              LL dc = lines[k].first.first-from.first.first;
              if ((da > 0 && dc < 0) || (da < 0 && dc > 0)) {
                pricea+=lines[k].second;
              } else if (abs(dc) < abs(da)) {
                good = false;
                break;
              } else {
                priceb+=lines[k].second;
              }
            } else {
              LL da = to.first.second-from.first.second;
              LL dc = lines[k].first.second-from.first.second;
              if ((da > 0 && dc < 0) || (da < 0 && dc > 0)) {
                pricea+=lines[k].second;
              } else if (abs(dc) < abs(da)) {
                good = false;
                break;
              } else {
                priceb+=lines[k].second;
              }
            }
            continue;
          }
          if (d < 0) priced += lines[k].second;
          else priced -= lines[k].second;
        }
        if (!good) continue;
        priced = abs(priced);
        if (pricea > priceb) swap(pricea,priceb);
        if (priced > pricea+priceb)
          mndiff = min(mndiff,priced-pricea-priceb);
        else
          mndiff = min(mndiff,min(abs(priced-pricea-priceb),
                                  abs(priced-priceb+pricea)));
      }
    }
    return mndiff;
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
		cout << "Testing TreesDivision (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393857633;
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
		TreesDivision _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {1,2};
				int y[] = {2,3};
				int income[] = {10,20};
				_expected = 10;
				_received = _obj.minDifference(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(income, income+sizeof(income)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {0,1,2,3};
				int y[] = {1,1,1,1};
				int income[] = {1,1,1,1};
				_expected = 0;
				_received = _obj.minDifference(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(income, income+sizeof(income)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {0,0,0,0,0};
				int y[] = {1,2,3,4,5};
				int income[] = {1,2,3,4,1000};
				_expected = 990;
				_received = _obj.minDifference(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(income, income+sizeof(income)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {0,0,1,1};
				int y[] = {0,1,1,0};
				int income[] = {1,2,4,8};
				_expected = 1;
				_received = _obj.minDifference(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(income, income+sizeof(income)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {4,2,4,2,3,6,3,5};
				int y[] = {1,2,4,3,3,2,4,5};
				int income[] = {4,5,2,6,7,4,2,4};
				_expected = 2;
				_received = _obj.minDifference(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(income, income+sizeof(income)/sizeof(int))); break;
			}
			case 5:
			{
				int x[] = {1,2,3};
				int y[] = {3,2,1};
				int income[] = {1,1000000,1};
				_expected = 1000000;
				_received = _obj.minDifference(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(income, income+sizeof(income)/sizeof(int))); break;
			}
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				int income[] = ;
				_expected = ;
				_received = _obj.minDifference(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(income, income+sizeof(income)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				int y[] = ;
				int income[] = ;
				_expected = ;
				_received = _obj.minDifference(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(income, income+sizeof(income)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int x[] = ;
				int y[] = ;
				int income[] = ;
				_expected = ;
				_received = _obj.minDifference(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(income, income+sizeof(income)/sizeof(int))); break;
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
