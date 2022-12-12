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

class NotTwo {
 public:
  int maxStones(int width, int height) {
    int r = 0;
    r+=(((width/2)*(height/2)));
    r+=((((width+1)/2)*(height/2)));
    r+=(((width/2)*((height+1)/2)));
    r+=(((width+1)/2)*((height+1)/2));
    return (r+1)/2;
    /*
    vector<vector<int> > a(width,vector<int>(height,0));
    int r = 0;
    for (int i=0;i<width;i++)
      for (int j=0;j<height;j++) {
        if (i-2 >= 0 && a[i-2][j]) continue;
        if (j-2 >= 0 && a[i][j-2]) continue;
        a[i][j] = 1;
        r++;
      }
    return r;
    */
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
		cout << "Testing NotTwo (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397842288;
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
		NotTwo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int width = 3;
				int height = 2;
				_expected = 4;
				_received = _obj.maxStones(width, height); break;
			}
			case 1:
			{
				int width = 3;
				int height = 3;
				_expected = 5;
				_received = _obj.maxStones(width, height); break;
			}
			case 2:
			{
				int width = 8;
				int height = 5;
				_expected = 20;
				_received = _obj.maxStones(width, height); break;
			}
			/*case 3:
			{
				int width = ;
				int height = ;
				_expected = ;
				_received = _obj.maxStones(width, height); break;
			}*/
			/*case 4:
			{
				int width = ;
				int height = ;
				_expected = ;
				_received = _obj.maxStones(width, height); break;
			}*/
			/*case 5:
			{
				int width = ;
				int height = ;
				_expected = ;
				_received = _obj.maxStones(width, height); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
