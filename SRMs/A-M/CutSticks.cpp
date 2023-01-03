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
typedef pair<double,LL> PDLL;
// BEGIN CUT HERE
const int tt = -1;
// 
// END CUT HERE

class CutSticks {
 public:
  LL count(double m, int C, const vector<int>& sticks) {
    int c = 0;
    int r = 0;
    for (int i=0;i<sticks.size();i++) {
      if (sticks[i] >= m) {
        int cuts = int(sticks[i]/m)-1;
        if (c+cuts <= C) {
          r+=cuts+1;
          c+=cuts;
        } else {
          r+= C-c+1;
          c = C;
        }
      }
    }
    return r;
  }
  double maxKth(vector <int> sticks, int C, int K) {
    double l = 0;
    double r = 1e9;
    for (int i=0;i<100;i++) {
      double m = (l+r)/2.0;
      if (count(m,C,sticks) >= K) l = m;
      else r = m;
    }
    return r;
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
		cout << "Testing CutSticks (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1399124116;
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
		CutSticks _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int sticks[] = {5, 8};
				int C = 1;
				int K = 1;
				_expected = 8.0;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}
			case 1:
			{
				int sticks[] = {5, 8};
				int C = 1;
				int K = 2;
				_expected = 5.0;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}
			case 2:
			{
				int sticks[] = {5, 8};
				int C = 1;
				int K = 3;
				_expected = 4.0;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}
			case 3:
			{
				int sticks[] = {1000000000, 1000000000, 1};
				int C = 2;
				int K = 5;
				_expected = 1.0;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}
			case 4:
			{
				int sticks[] = {76, 594, 17, 6984, 26, 57, 9, 876, 5816, 73, 969, 527, 49};
				int C = 789;
				int K = 456;
				_expected = 34.92;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}
			case 5:
			{
				int sticks[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
;
				int C = 1000000000;
				int K = 1000000009;
				_expected = 2.7999998992000305E-8;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}
			case 6:
			{
				int sticks[] = {10000, 1};
				int C = 1;
				int K = 2;
				_expected = 5000.0;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}
			case 7:
			{
				int sticks[] = {509963490, 519424026, 182661095, 621022436, 780316997, 755081160, 728191132, 694475319, 526378498, 710034005, 783700347, 333365967, 149730767, 501459936, 803401887, 254870905, 810552852, 575059668, 836594998, 22909507, 114835010, 730505067, 289256895, 251371139, 940287194, 664357333, 763120839, 586443581, 798266871, 229915076, 697139228, 128089949, 345543953, 96594732, 272083089, 590041046, 516896170, 581608285, 523326913, 622382610, 116129426, 989436386, 364332, 595745994, 845170068};
				int C = 58610317;
				int K = 2080;
				_expected = 1.1120658789473686E7;
				_received = _obj.maxKth(vector <int>(sticks, sticks+sizeof(sticks)/sizeof(int)), C, K); break;
			}
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
