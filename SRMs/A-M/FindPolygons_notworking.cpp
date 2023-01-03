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
const int tt = 3;
// 
// END CUT HERE

class FindPolygons {
 public:
  double minimumPolygon(int L) {
    if (L%2 || L < 4) return -1;
    vector<int> intsqrt(L*L/2+1,0);
    for (int i=1;i*i<intsqrt.size();i++)
      intsqrt[i*i] = i;
    int mn = L+1;
    for (int i=1;i*i<intsqrt.size();i++)
      for (int j=i;i*i+j*j<intsqrt.size();j++) {
        if (intsqrt[j*j-i*i] && i+j+intsqrt[j*j-i*i] == L) {
          //cout << ".. " << i << " " << j << " " << intsqrt[j*j-i*i] << endl;
          mn = min(mn,j-min(intsqrt[j*j-i*i],i));
          continue;
        }
        if (!intsqrt[i*i+j*j] || i+j+intsqrt[i*i+j*j] != L) continue;
        cout << i << " " << j << " " << intsqrt[i*i+j*j] << endl;
        mn = min(mn,intsqrt[i*i+j*j]-i);
      }
    if (mn != L+1) return mn;
    if (L%4 == 0) return 0;
    return 1;
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
		cout << "Testing FindPolygons (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1389796101;
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
		FindPolygons _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int L = 4;
				_expected = 0.0;
				_received = _obj.minimumPolygon(L); break;
			}
			case 1:
			{
				int L = 5;
				_expected = -1.0;
				_received = _obj.minimumPolygon(L); break;
			}
			case 2:
			{
				int L = 12;
				_expected = 2.0;
				_received = _obj.minimumPolygon(L); break;
			}
			case 3:
			{
				int L = 4984;
				_expected = 819.0;
				_received = _obj.minimumPolygon(L); break;
			}
			/*case 4:
			{
				int L = ;
				_expected = ;
				_received = _obj.minimumPolygon(L); break;
			}*/
			/*case 5:
			{
				int L = ;
				_expected = ;
				_received = _obj.minimumPolygon(L); break;
			}*/
			/*case 6:
			{
				int L = ;
				_expected = ;
				_received = _obj.minimumPolygon(L); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
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
