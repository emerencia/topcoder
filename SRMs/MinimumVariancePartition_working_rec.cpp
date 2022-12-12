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
bool seen[51][1001][51];
double mem[51][1001][51];
double variance[51][51];

class MinimumVariancePartition {
 public:
  int n;
  double rec(int idx, int lastone, int kleft) {
    double& r = mem[idx][lastone][kleft];
    if (seen[idx][lastone][kleft]) return r;
    seen[idx][lastone][kleft] = 1;
    if (idx == n) {
      if (kleft != 1) return r = 1e100;
      return r = variance[lastone][idx];
    }
    double t = 1e100;
    if (kleft > 1)
      t = variance[lastone][idx]+rec(idx+1,idx,kleft-1);
    t = min(t,rec(idx+1,lastone,kleft));
    return r = t;
  }
  double minDev(vector <int> mixedSamples, int k) {
    sort(mixedSamples.begin(),mixedSamples.end());
    n = mixedSamples.size();
    for (int i=0;i<n;i++)
      for (int j=i+1;j<=n;j++) {
        int c = j-i;
        int sum = accumulate(mixedSamples.begin()+i,mixedSamples.begin()+j,0);
        double mean = double(sum)/c;
        double vr = 0;
        for (int l=i;l<j;l++)
          vr += (mixedSamples[l]-mean)*(mixedSamples[l]-mean);
        variance[i][j] = vr/c;
      }
    memset(seen,0,sizeof(seen));
    return rec(0,0,k);
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
		cout << "Testing MinimumVariancePartition (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396913704;
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
		MinimumVariancePartition _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int mixedSamples[] = {3,4,7,10};
				int k = 1;
				_expected = 7.5;
				_received = _obj.minDev(vector <int>(mixedSamples, mixedSamples+sizeof(mixedSamples)/sizeof(int)), k); break;
			}
			case 1:
			{
				int mixedSamples[] = {1000,500,1,500};
				int k = 3;
				_expected = 0.0;
				_received = _obj.minDev(vector <int>(mixedSamples, mixedSamples+sizeof(mixedSamples)/sizeof(int)), k); break;
			}
			case 2:
			{
				int mixedSamples[] = {54,653,876,2,75};
				int k = 5;
				_expected = 0.0;
				_received = _obj.minDev(vector <int>(mixedSamples, mixedSamples+sizeof(mixedSamples)/sizeof(int)), k); break;
			}
			case 3:
			{
				int mixedSamples[] = {42,234,10,1,123,545,436,453,74,85,34,999};
				int k = 5;
				_expected = 1700.7397959183672;
				_received = _obj.minDev(vector <int>(mixedSamples, mixedSamples+sizeof(mixedSamples)/sizeof(int)), k); break;
			}
			case 4:
			{
				int mixedSamples[] = {923,456,12,12,542,234,11,12,10,9};
				int k = 4;
				_expected = 1850.3333333333333;
				_received = _obj.minDev(vector <int>(mixedSamples, mixedSamples+sizeof(mixedSamples)/sizeof(int)), k); break;
			}
			case 5:
			{
				int mixedSamples[] = {934, 633, 269, 511, 435, 554, 784, 338, 932, 183, 551, 881, 520, 682, 855, 384, 715, 623, 808, 18, 661, 610, 478, 897, 670, 564, 775, 280, 638, 533, 746, 767, 69, 265, 491, 176, 731, 530, 253, 774, 768, 924, 496, 449, 2, 437, 534, 236, 734, 102};
				int k = 10;
				_expected = 3986.2832171436066;
				_received = _obj.minDev(vector <int>(mixedSamples, mixedSamples+sizeof(mixedSamples)/sizeof(int)), k); break;
			}
			case 6:
			{
				int mixedSamples[] = {197, 611, 410, 779, 203, 15, 727, 446, 992, 722, 439, 296, 201, 820, 416, 272, 89, 146, 687, 203, 598, 65, 865, 945, 446, 783, 581, 270, 960, 22, 970, 698, 456, 706, 14, 901, 371, 688, 914, 925, 551, 15, 326, 620, 842, 82, 594, 99, 827, 660};
				int k = 21;
				_expected = 757.3225;
				_received = _obj.minDev(vector <int>(mixedSamples, mixedSamples+sizeof(mixedSamples)/sizeof(int)), k); break;
			}
			/*case 7:
			{
				int mixedSamples[] = ;
				int k = ;
				_expected = ;
				_received = _obj.minDev(vector <int>(mixedSamples, mixedSamples+sizeof(mixedSamples)/sizeof(int)), k); break;
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
