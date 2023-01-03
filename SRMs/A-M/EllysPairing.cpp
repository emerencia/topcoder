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

class EllysPairing {
 public:
  void update(int& best, int& cnt, int val) {
    if (cnt == 0) {
      best = val;
      cnt = 1;
    } else {
      if (best == val) cnt++;
      else cnt--;
    }
  }
  int getMax(int M, vector <int> count, vector <int> first, vector <int> mult, vector <int> add) {
    int best = -1;
    int cnt = 0;
    for (int i=0;i<count.size();i++) {
      int val = first[i];
      update(best, cnt, val);
      for (int j = 0; j + 1 < count[i]; j++) {
        val = (val * mult[i] + add[i]) & (M - 1);
        update(best, cnt, val);
      }
    }
    cnt = 0;
    for (int i=0;i<count.size();i++) {
      int val = first[i];
      if (val == best) cnt++;
      for (int j = 0; j + 1 < count[i]; j++) {
        val = (val * mult[i] + add[i]) & (M - 1);
        if (val == best) cnt++;
      }
    }
    int n = accumulate(count.begin(),count.end(),0);
    return n/2 - max(0,cnt-(n+1)/2);
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
		cout << "Testing EllysPairing (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1410455862;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		EllysPairing _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int M = 16;
				int count[] = {4, 7};
				int first[] = {5, 3};
				int mult[] = {2, 3};
				int add[] = {1, 0};
				_expected = 5;
				_received = _obj.getMax(M, vector <int>(count, count+sizeof(count)/sizeof(int)), vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(mult, mult+sizeof(mult)/sizeof(int)), vector <int>(add, add+sizeof(add)/sizeof(int))); break;
			}
			case 1:
			{
				int M = 8;
				int count[] = {6, 4, 3};
				int first[] = {0, 3, 2};
				int mult[] = {3, 7, 5};
				int add[] = {0, 3, 2};
				_expected = 5;
				_received = _obj.getMax(M, vector <int>(count, count+sizeof(count)/sizeof(int)), vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(mult, mult+sizeof(mult)/sizeof(int)), vector <int>(add, add+sizeof(add)/sizeof(int))); break;
			}
			case 2:
			{
				int M = 128;
				int count[] = {42, 13, 666, 17, 1337, 42, 1};
				int first[] = {18, 76, 3, 122, 0, 11, 11};
				int mult[] = {33, 17, 54, 90, 41, 122, 20};
				int add[] = {66, 15, 10, 121, 122, 1, 30};
				_expected = 1059;
				_received = _obj.getMax(M, vector <int>(count, count+sizeof(count)/sizeof(int)), vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(mult, mult+sizeof(mult)/sizeof(int)), vector <int>(add, add+sizeof(add)/sizeof(int))); break;
			}
			case 3:
			{
				int M = 1048576;
				int count[] = {4242, 42, 9872, 13, 666, 21983, 17, 1337, 42, 1};
				int first[] = {19, 18, 76, 42, 3, 112, 0, 11, 11, 12};
				int mult[] = {27, 33, 10, 8, 17, 9362, 90, 41, 122, 20};
				int add[] = {98, 101, 66, 15, 10, 144, 3, 1, 5, 1};
				_expected = 16232;
				_received = _obj.getMax(M, vector <int>(count, count+sizeof(count)/sizeof(int)), vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(mult, mult+sizeof(mult)/sizeof(int)), vector <int>(add, add+sizeof(add)/sizeof(int))); break;
			}
			case 4:
			{
				int M = 1073741824;
				int count[] = {894602, 946569, 887230, 856152, 962583, 949356, 904847, 829100, 842183, 958440,
				               811081, 864078, 809209, 938727, 949135, 892809, 816528, 961237, 979142, 890922};
				int first[] = {844085078, 898937259, 243490172, 887804102, 187696417, 156820442, 237600210, 618812924, 153000239, 912364033,
				               254936966, 650298774, 982988140, 649258331, 566444626, 201481721, 492943390, 1061953081, 492672963, 960519711};
				int mult[] = {1036482037, 583219072, 819168094, 253755052, 548208982, 401830167, 638626082, 43642932, 123607749, 485521178,
				              860368129, 30334704, 219771462, 733375600, 130839219, 415503960, 294132484, 1044831462, 256910484, 198852170};
				int add[] = {889169006, 604831366, 967292994, 980686280, 844875791, 1027687492, 357734882, 295879743, 48284748, 421729100,
				             1049536313, 327207332, 948053446, 271229570, 664579359, 795815285, 842856528, 876662975, 675611938, 634229925};
				_expected = 8971965;
				_received = _obj.getMax(M, vector <int>(count, count+sizeof(count)/sizeof(int)), vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(mult, mult+sizeof(mult)/sizeof(int)), vector <int>(add, add+sizeof(add)/sizeof(int))); break;
			}
			/*case 5:
			{
				int M = ;
				int count[] = ;
				int first[] = ;
				int mult[] = ;
				int add[] = ;
				_expected = ;
				_received = _obj.getMax(M, vector <int>(count, count+sizeof(count)/sizeof(int)), vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(mult, mult+sizeof(mult)/sizeof(int)), vector <int>(add, add+sizeof(add)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int M = ;
				int count[] = ;
				int first[] = ;
				int mult[] = ;
				int add[] = ;
				_expected = ;
				_received = _obj.getMax(M, vector <int>(count, count+sizeof(count)/sizeof(int)), vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(mult, mult+sizeof(mult)/sizeof(int)), vector <int>(add, add+sizeof(add)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int M = ;
				int count[] = ;
				int first[] = ;
				int mult[] = ;
				int add[] = ;
				_expected = ;
				_received = _obj.getMax(M, vector <int>(count, count+sizeof(count)/sizeof(int)), vector <int>(first, first+sizeof(first)/sizeof(int)), vector <int>(mult, mult+sizeof(mult)/sizeof(int)), vector <int>(add, add+sizeof(add)/sizeof(int))); break;
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
