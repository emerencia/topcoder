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
const int tt = -1;
// 
// END CUT HERE

class ShipLoading {
 public:
  vector<int> getweights(vector<string> boxes) {
    string s = accumulate(boxes.begin(),boxes.end(),string(""));
    stringstream a(s);
    vector<int> r;
    while (!a.eof()) {
      int c;
      a >> c;
      r.push_back(c);
    }
    return r;
  }
  int minimumTime(vector <int> cranes, vector <string> boxes) {
    vector<int> weights = getweights(boxes);
    sort(weights.begin(),weights.end());
    sort(cranes.begin(),cranes.end());
    if (weights.back() > cranes.back()) return -1;
    int mx = 0;
    for (int i=0;i<weights.size();i++) {
      int j = 0;
      for (;j<cranes.size();j++)
        if (cranes[j] >= weights[i])
          break;
      int nrcranes = cranes.size()-j;
      int nrboxes = weights.size()-i;
      mx = max(mx,(nrboxes+nrcranes-1)/nrcranes);
    }
    return mx;
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
		cout << "Testing ShipLoading (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390405771;
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
		ShipLoading _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int cranes[] = {6,8,9};
				string boxes[] = {"2 5 2 4 7"};
				_expected = 2;
				_received = _obj.minimumTime(vector <int>(cranes, cranes+sizeof(cranes)/sizeof(int)), vector <string>(boxes, boxes+sizeof(boxes)/sizeof(string))); break;
			}
			case 1:
			{
				int cranes[] = {19,20};
				string boxes[] = {"14 12 16 19 16 1 5"};
				_expected = 4;
				_received = _obj.minimumTime(vector <int>(cranes, cranes+sizeof(cranes)/sizeof(int)), vector <string>(boxes, boxes+sizeof(boxes)/sizeof(string))); break;
			}
			case 2:
			{
				int cranes[] = {23,32,25,28};
				string boxes[] = {"5 27 10 16 24 20 2 32 18 7"};
				_expected = 3;
				_received = _obj.minimumTime(vector <int>(cranes, cranes+sizeof(cranes)/sizeof(int)), vector <string>(boxes, boxes+sizeof(boxes)/sizeof(string))); break;
			}
			case 3:
			{
				int cranes[] = {11,17,5,2,20,7,5,5,20,7};
				string boxes[] = {"18 18 15 15 17"};
				_expected = 2;
				_received = _obj.minimumTime(vector <int>(cranes, cranes+sizeof(cranes)/sizeof(int)), vector <string>(boxes, boxes+sizeof(boxes)/sizeof(string))); break;
			}
			case 4:
			{
				int cranes[] = {56,114,979,120,120,87,480};
				string boxes[] = {"221 882 504 358 642 674 212 679 203 279 632 799 79","6 502 275 823 372 594 482 343"};
				_expected = 12;
				_received = _obj.minimumTime(vector <int>(cranes, cranes+sizeof(cranes)/sizeof(int)), vector <string>(boxes, boxes+sizeof(boxes)/sizeof(string))); break;
			}
			/*case 5:
			{
				int cranes[] = ;
				string boxes[] = ;
				_expected = ;
				_received = _obj.minimumTime(vector <int>(cranes, cranes+sizeof(cranes)/sizeof(int)), vector <string>(boxes, boxes+sizeof(boxes)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int cranes[] = ;
				string boxes[] = ;
				_expected = ;
				_received = _obj.minimumTime(vector <int>(cranes, cranes+sizeof(cranes)/sizeof(int)), vector <string>(boxes, boxes+sizeof(boxes)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				int cranes[] = ;
				string boxes[] = ;
				_expected = ;
				_received = _obj.minimumTime(vector <int>(cranes, cranes+sizeof(cranes)/sizeof(int)), vector <string>(boxes, boxes+sizeof(boxes)/sizeof(string))); break;
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
