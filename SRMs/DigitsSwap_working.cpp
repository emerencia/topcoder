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
const int tt = 2;
// 
// END CUT HERE

class DigitsSwap {
 public:
  string product(const string& x, const string& y) {
    vector<int> r(105,0);
    for (int i=x.size()-1;i>=0;i--) {
      int adig = x[i]-'0';
      int azer = x.size()-i-1;
      for (int j=y.size()-1;j>=0;j--) {
        int bdig = y[j]-'0';
        int bzer = y.size()-j-1;
        int res = adig*bdig;
        int pos = bzer+azer;
        while (res) {
          r[pos]+=res%10;
          int dpos = pos;
          while (r[dpos] >= 10) {
            r[dpos+1]+=r[dpos]/10;
            r[dpos]%=10;
            dpos++;
          }
          pos++;
          res/=10;
        }
      }
    }
    string rs;
    bool seennonzero = false;
    for (int i=r.size()-1;i>=0;i--) {
      if (!seennonzero && r[i] == 0) continue;
      seennonzero = true;
      rs = rs + string(1,r[i]+'0');
    }
    return rs;
  }
  string maxprod(string x, string y, int swaps) {
    int swapsleft = swaps;
    bool allequal = true;
    bool seeneq = false;
    for (int i=0;i<x.size();i++) {
      if (x[i] == y[i]) {
        seeneq = true;
        continue;
      }
      if (!swapsleft) continue;
      if (allequal) {
        if (x[i] > y[i]) {
          swap(x[i],y[i]);
          swapsleft--;
        }
      } else {
        if (x[i] < y[i]) {
          swap(x[i],y[i]);
          swapsleft--;
        }
      }
      allequal = false;
    }
    if (swapsleft%2 && !seeneq && swapsleft%x.size() != 0)
      swap(x[x.size()-1],y[y.size()-1]);
    cout << endl;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    return product(x,y);
  }
  string maximalProduct(string x, string y, int swaps) {
    string a = maxprod(x,y,swaps);
    string b = maxprod(y,x,swaps);
    if (a.size() != b.size()) return (a.size() < b.size() ? b : a);
    return max(a,b);
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
		cout << "Testing DigitsSwap (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1394473017;
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
		DigitsSwap _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string x = "9954312";
				string y = "4341138";
				int swaps = 1;
				_expected = "46278912087056";
				_received = _obj.maximalProduct(x, y, swaps); break;
			}
			case 1:
			{
				string x = "4531";
				string y = "1332";
				int swaps = 0;
				_expected = "6035292";
				_received = _obj.maximalProduct(x, y, swaps); break;
			}
			case 2:
			{
				string x = "260661849";
				string y = "337882913";
				int swaps = 4;
				_expected = "88578661588126537";
				_received = _obj.maximalProduct(x, y, swaps); break;
			}
			case 3:
			{
				string x = "2872876342876443222";
				string y = "2309482482304823423";
				int swaps = 5;
				_expected = "6669566046086333877050194232995188906";
				_received = _obj.maximalProduct(x, y, swaps); break;
			}
			case 4:
			{
				string x = "940948";
				string y = "124551";
				int swaps = 4893846;
				_expected = "133434353148";
				_received = _obj.maximalProduct(x, y, swaps); break;
			}
			case 5:
			{
				string x = "56710852";
				string y = "18058360";
				int swaps = 1;
				_expected = "1050671725722720";
				_received = _obj.maximalProduct(x, y, swaps); break;
			}
			case 6:
			{
				string x = "9";
				string y = "1";
				int swaps = 1000000000;
				_expected = "9";
				_received = _obj.maximalProduct(x, y, swaps); break;
			}
			case 7:
			{
				string x = "22122";
				string y = "12211";
				int swaps = 3;
				_expected = "270240642";
				_received = _obj.maximalProduct(x, y, swaps); break;
			}
			case 8:
			{
				string x = "4614232";
				string y = "8168576";
				int swaps = 1;
				_expected = "37866921973632";
				_received = _obj.maximalProduct(x, y, swaps); break;
			}
			/*case 9:
			{
				string x = ;
				string y = ;
				int swaps = ;
				_expected = ;
				_received = _obj.maximalProduct(x, y, swaps); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
