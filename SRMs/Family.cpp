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

class Family {
 public:
  string isFamily(vector <int> parent1, vector <int> parent2) {
    int segment_count = 0;
    vector<int> segment(100,-1);
    for (int i = 0; i < parent1.size(); i++) {
      if (parent1[i] >= i || parent2[i] >= i)
        return "Impossible";
      if (parent1[i] == -1)
        continue;
      int p1 = parent1[i];
      int p2 = parent2[i];
      if (segment[p1] == -1 && segment[p2] == -1) {
        // both new, assign to new segment
        segment[p1] = segment_count++;
        segment[p2] = segment_count++;
      } else if (segment[p1] == -1) {
        // assign p1 to the opposite segment of p2
        segment[p1] = (segment[p2]^1);
      } else if (segment[p2] == -1) {
        // assign p2 to the opposite segment of p1
        segment[p2] = segment[p1]^1;
      } else {
        // same segment:
        if (segment[p1] == segment[p2])
          return "Impossible";
        if ((segment[p1]^1) == segment[p2])
          continue;
        // different segment: rename one of the segments
        // rename p2 to p1
        int seg2 = segment[p2];
        for (int j = 0;j < segment.size();j++) {
          if (segment[j] == seg2) {
            segment[j] = (segment[p1]^1);
          } else if (segment[j] == (seg2^1)) {
            segment[j] = segment[p1];
          }
        }
      }
    }
    return "Possible";
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
		cout << "Testing Family (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1435840813;
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
		Family _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int parent1[] = {-1,-1,0};
				int parent2[] = {-1,-1,1};
				_expected = "Possible";
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
			}
			case 1:
			{
				int parent1[] = {-1,-1,-1,-1,-1};
				int parent2[] = {-1,-1,-1,-1,-1};
				_expected = "Possible";
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
			}
			case 2:
			{
				int parent1[] = {-1,-1,0,0,1};
				int parent2[] = {-1,-1,1,2,2};
				_expected = "Impossible";
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
			}
			case 3:
			{
				int parent1[] = {-1,-1,-1,-1,1,-1,0,5,6,-1,0,3,8,6};
				int parent2[] = {-1,-1,-1,-1,3,-1,4,6,5,-1,5,4,6,1};
				_expected = "Possible";
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
			}
			case 4:
			{
				int parent1[] = {-1,-1,-1,2,2,-1,5,6,4,6,2,1,8,0,2,4,6,9,-1,16,-1,11};
				int parent2[] = {-1,-1,-1,1,0,-1,1,4,2,0,4,8,2,3,0,5,14,14,-1,7,-1,13};
				_expected = "Impossible";
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
			}
			case 5:
			{ //                0  1 2 3 4 5 6  7 8 9
        //            2   M  F
        //                M  F
        //                M  F   F
        //                M  F + F -
        //                M  F F F M
        //                   X X
				int parent1[] = {-1,-1,0,0,0,2,3,-1,2,6};
				int parent2[] = {-1,-1,1,1,3,4,4,-1,1,2};
				_expected = "Impossible";
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
			}
			/*case 6:
			{
				int parent1[] = ;
				int parent2[] = ;
				_expected = ;
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int parent1[] = ;
				int parent2[] = ;
				_expected = ;
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
