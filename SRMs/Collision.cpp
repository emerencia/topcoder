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

class Collision {
 public:
  double probmorethanone1(vector<int> assignments, int ids) {
    // can repeat same values
    int sumass = accumulate(assignments.begin(),assignments.end(),0);
    double r = 1;
    for (int i = 1;i<sumass;i++) {
      r*= double(ids-i)/ids;
    }
    return 1-r;
  }
  double probmorethanone2(vector<int> assignments, int ids) {
    // cannot repeat same values
    double r = 1;
    int sumass = 0;
    for (int i=0;i<assignments.size();i++) {
      for (int j=0;j<assignments[i];j++)
        r*= double(ids-sumass-j)/(ids-j);
      sumass += assignments[i];
    }
    return 1-r;
  }
  double probability(vector <int> assignments, int ids) {
    int sumass = accumulate(assignments.begin(),assignments.end(),0);
    if (sumass > ids) return 0;
    return probmorethanone1(assignments,ids)-
           probmorethanone2(assignments,ids);
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
		cout << "Testing Collision (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397299492;
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
		Collision _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int assignments[] = {20,20};
				int ids = 1000;
				_expected = 0.2113618990410422;
				_received = _obj.probability(vector <int>(assignments, assignments+sizeof(assignments)/sizeof(int)), ids); break;
			}
			case 1:
			{
				int assignments[] = {123,456};
				int ids = 123456;
				_expected = 0.3769052883184334;
				_received = _obj.probability(vector <int>(assignments, assignments+sizeof(assignments)/sizeof(int)), ids); break;
			}
			case 2:
			{
				int assignments[] = {10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};
				int ids = 2147483647;
				_expected = 0.0069090268185510555;
				_received = _obj.probability(vector <int>(assignments, assignments+sizeof(assignments)/sizeof(int)), ids); break;
			}
			case 3:
			{
				int assignments[] = {1005,1005};
				int ids = 1000;
				_expected = 0.0;
				_received = _obj.probability(vector <int>(assignments, assignments+sizeof(assignments)/sizeof(int)), ids); break;
			}
			case 4:
			{
				int assignments[] = {1000,0};
				int ids = 1000;
				_expected = 1.0;
				_received = _obj.probability(vector <int>(assignments, assignments+sizeof(assignments)/sizeof(int)), ids); break;
			}
			/*case 5:
			{
				int assignments[] = ;
				int ids = ;
				_expected = ;
				_received = _obj.probability(vector <int>(assignments, assignments+sizeof(assignments)/sizeof(int)), ids); break;
			}*/
			/*case 6:
			{
				int assignments[] = ;
				int ids = ;
				_expected = ;
				_received = _obj.probability(vector <int>(assignments, assignments+sizeof(assignments)/sizeof(int)), ids); break;
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
