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

class ColoringRectangle {
 public:
  int chooseDisks(int width, int height, vector <int> red, vector <int> blue) {
    int r = INT_MAX;
    sort(red.rbegin(),red.rend());
    sort(blue.rbegin(),blue.rend());
    vector<vector<int> > disks;
    disks.push_back(red);
    disks.push_back(blue);
    for (int start=0;start<2;start++) {
      int c = 0;
      double dist = 0;
      int cur = start;
      vector<int> idx(2,0);
      while (dist < width && idx[cur] < disks[cur].size()) {
        ++c;
        if (disks[cur][idx[cur]] >= height)
          dist += sqrt(disks[cur][idx[cur]]*disks[cur][idx[cur]]-height*height);
        else break;
        idx[cur]++;
        cur = 1-cur;
      }
      if (dist < width) continue;
      r = min(r,c);
    }
    return r == INT_MAX ? -1 : r;
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
		cout << "Testing ColoringRectangle (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1400856920;
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
		ColoringRectangle _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int width = 11;
				int height = 3;
				int red[] = {5,5};
				int blue[] = {2,5};
				_expected = 3;
				_received = _obj.chooseDisks(width, height, vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 1:
			{
				int width = 30;
				int height = 5;
				int red[] = {4,10,7,8,10};
				int blue[] = {5,6,11,7,5};
				_expected = 4;
				_received = _obj.chooseDisks(width, height, vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 2:
			{
				int width = 16;
				int height = 4;
				int red[] = {6,5,7};
				int blue[] = {5};
				_expected = -1;
				_received = _obj.chooseDisks(width, height, vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 3:
			{
				int width = 4;
				int height = 4;
				int red[] = {5};
				int blue[] = {6};
				_expected = 1;
				_received = _obj.chooseDisks(width, height, vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 4:
			{
				int width = 6;
				int height = 2;
				int red[] = {6,6};
				int blue[] = {2};
				_expected = 3;
				_received = _obj.chooseDisks(width, height, vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			/*case 5:
			{
				int width = ;
				int height = ;
				int red[] = ;
				int blue[] = ;
				_expected = ;
				_received = _obj.chooseDisks(width, height, vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int width = ;
				int height = ;
				int red[] = ;
				int blue[] = ;
				_expected = ;
				_received = _obj.chooseDisks(width, height, vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int width = ;
				int height = ;
				int red[] = ;
				int blue[] = ;
				_expected = ;
				_received = _obj.chooseDisks(width, height, vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
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
