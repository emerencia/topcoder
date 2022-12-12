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

class Nisoku {
 public:
  double theMax(vector <double> cards) {
    sort(cards.begin(),cards.end());
    int l = 0;
    while (l+2 < cards.size()) {
      double mxinc = 1e100;
      int iinc = -1;
      for (int i=l+1;i<cards.size();i++) {
        double tinc = max(cards[l]*cards[i],cards[l]+cards[i]);
        if (tinc < mxinc) {
          mxinc = tinc;
          iinc  = i;
        }
      }
      if (iinc == -1) cout << "error!" << endl;
      for (int i=iinc;i+1<cards.size();i++)
        cards[i] = cards[i+1];
      cards[cards.size()-1] = mxinc;
      sort(cards.begin()+l+1,cards.end());
      l++;
    }
    return max(cards[l]*cards[l+1],cards[l]+cards[l+1]);
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
		cout << "Testing Nisoku (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1401567369;
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
		Nisoku _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				double cards[] = {5, 8};
				_expected = 40.0;
				_received = _obj.theMax(vector <double>(cards, cards+sizeof(cards)/sizeof(double))); break;
			}
			case 1:
			{
				double cards[] = {1.5, 1.8};
				_expected = 3.3;
				_received = _obj.theMax(vector <double>(cards, cards+sizeof(cards)/sizeof(double))); break;
			}
			case 2:
			{
				double cards[] = {8.26, 7.54, 3.2567};
				_expected = 202.82857868;
				_received = _obj.theMax(vector <double>(cards, cards+sizeof(cards)/sizeof(double))); break;
			}
			case 3:
			{
				double cards[] = {1.5, 1.7, 1.6, 1.5};
				_expected = 9.920000000000002;
				_received = _obj.theMax(vector <double>(cards, cards+sizeof(cards)/sizeof(double))); break;
			}
			case 4:
			{
				double cards[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 
				                 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 
				                 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 
				                 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 
				                 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
				_expected = 1.0E50;
				_received = _obj.theMax(vector <double>(cards, cards+sizeof(cards)/sizeof(double))); break;
			}
			/*case 5:
			{
				double cards[] = ;
				_expected = ;
				_received = _obj.theMax(vector <double>(cards, cards+sizeof(cards)/sizeof(double))); break;
			}*/
			/*case 6:
			{
				double cards[] = ;
				_expected = ;
				_received = _obj.theMax(vector <double>(cards, cards+sizeof(cards)/sizeof(double))); break;
			}*/
			/*case 7:
			{
				double cards[] = ;
				_expected = ;
				_received = _obj.theMax(vector <double>(cards, cards+sizeof(cards)/sizeof(double))); break;
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
