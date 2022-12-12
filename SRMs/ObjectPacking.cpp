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

class ObjectPacking {
 public:
  int smallBox(int objWidth, int objLength, vector <int> boxWidth, vector <int> boxLength) {
    int mn = INT_MAX;
    if (objWidth < objLength) swap(objWidth,objLength);
    for (int i=0;i<boxWidth.size();i++) {
      if (boxWidth[i] < boxLength[i]) swap(boxWidth[i],boxLength[i]);
      if (boxWidth[i] >= objWidth && boxLength[i] >= objLength)
        mn = min(mn,boxWidth[i]*boxLength[i]);
    }
    return mn == INT_MAX ? -1 : mn;
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
		cout << "Testing ObjectPacking (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395894428;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ObjectPacking _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int objWidth = 7;
				int objLength = 3;
				int boxWidth[] = {3};
				int boxLength[] = {7};
				_expected = 21;
				_received = _obj.smallBox(objWidth, objLength, vector <int>(boxWidth, boxWidth+sizeof(boxWidth)/sizeof(int)), vector <int>(boxLength, boxLength+sizeof(boxLength)/sizeof(int))); break;
			}
			case 1:
			{
				int objWidth = 5;
				int objLength = 8;
				int boxWidth[] = {6,9,3};
				int boxLength[] = {7,4,5};
				_expected = -1;
				_received = _obj.smallBox(objWidth, objLength, vector <int>(boxWidth, boxWidth+sizeof(boxWidth)/sizeof(int)), vector <int>(boxLength, boxLength+sizeof(boxLength)/sizeof(int))); break;
			}
			case 2:
			{
				int objWidth = 17;
				int objLength = 5;
				int boxWidth[] = {19,10,12,40};
				int boxLength[] = {12,20,15,5};
				_expected = 200;
				_received = _obj.smallBox(objWidth, objLength, vector <int>(boxWidth, boxWidth+sizeof(boxWidth)/sizeof(int)), vector <int>(boxLength, boxLength+sizeof(boxLength)/sizeof(int))); break;
			}
			case 3:
			{
				int objWidth = 20;
				int objLength = 44;
				int boxWidth[] = {36,42,18,37,33,5,30,10,29,9,11,16,48,50,34,44,33,12,31,41};
				int boxLength[] = {42,45,46,24,23,21,21,8,26,25,48,12,10,45,18,6,12,22,42,45};
				_expected = 1845;
				_received = _obj.smallBox(objWidth, objLength, vector <int>(boxWidth, boxWidth+sizeof(boxWidth)/sizeof(int)), vector <int>(boxLength, boxLength+sizeof(boxLength)/sizeof(int))); break;
			}
			case 4:
			{
				int objWidth = 1;
				int objLength = 10;
				int boxWidth[] = {9,1,10};
				int boxLength[] = {10,6,4};
				_expected = 40;
				_received = _obj.smallBox(objWidth, objLength, vector <int>(boxWidth, boxWidth+sizeof(boxWidth)/sizeof(int)), vector <int>(boxLength, boxLength+sizeof(boxLength)/sizeof(int))); break;
			}
			case 5:
			{
				int objWidth = 5;
				int objLength = 4;
				int boxWidth[] = {2,3,3,3,3};
				int boxLength[] = {2,7,7,4,2};
				_expected = -1;
				_received = _obj.smallBox(objWidth, objLength, vector <int>(boxWidth, boxWidth+sizeof(boxWidth)/sizeof(int)), vector <int>(boxLength, boxLength+sizeof(boxLength)/sizeof(int))); break;
			}
			case 6:
			{
				int objWidth = 3;
				int objLength = 3;
				int boxWidth[] = {2,3,3,3,2};
				int boxLength[] = {3,1,3,3,2};
				_expected = 9;
				_received = _obj.smallBox(objWidth, objLength, vector <int>(boxWidth, boxWidth+sizeof(boxWidth)/sizeof(int)), vector <int>(boxLength, boxLength+sizeof(boxLength)/sizeof(int))); break;
			}
			/*case 7:
			{
				int objWidth = ;
				int objLength = ;
				int boxWidth[] = ;
				int boxLength[] = ;
				_expected = ;
				_received = _obj.smallBox(objWidth, objLength, vector <int>(boxWidth, boxWidth+sizeof(boxWidth)/sizeof(int)), vector <int>(boxLength, boxLength+sizeof(boxLength)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int objWidth = ;
				int objLength = ;
				int boxWidth[] = ;
				int boxLength[] = ;
				_expected = ;
				_received = _obj.smallBox(objWidth, objLength, vector <int>(boxWidth, boxWidth+sizeof(boxWidth)/sizeof(int)), vector <int>(boxLength, boxLength+sizeof(boxLength)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int objWidth = ;
				int objLength = ;
				int boxWidth[] = ;
				int boxLength[] = ;
				_expected = ;
				_received = _obj.smallBox(objWidth, objLength, vector <int>(boxWidth, boxWidth+sizeof(boxWidth)/sizeof(int)), vector <int>(boxLength, boxLength+sizeof(boxLength)/sizeof(int))); break;
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
