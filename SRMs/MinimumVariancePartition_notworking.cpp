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
const int tt = 5;
// 
// END CUT HERE

class MinimumVariancePartition {
 public:
  void getnext(vector<int>& separators) {
    bool good = false;
    int idxinc = 0;
    for (int i=1;i+1<separators.size();i++) {
      if (separators[i]+1 != separators[i+1]) {
        good = true;
        idxinc = i;
        break;
      }
    }
    if (good) {
      for (int i=1;i<idxinc;i++)
        separators[i] = i;
      separators[idxinc]++;
    }
  }
  double minDev(vector <int> mixedSamples, int k) {
    sort(mixedSamples.begin(),mixedSamples.end());
    int n = mixedSamples.size();
    vector<vector<double> > variance(n+1,vector<double>(n+1,0.0));
    for (int i=0;i<n;i++)
      for (int j=i+1;j<=n;j++) {
        int c = j-i;
        int sum = accumulate(mixedSamples.begin()+i,mixedSamples.begin()+j,0);
        double mean = double(sum)/c;
        double vr = 0;
        for (int k=i;k<j;k++)
          vr += (mixedSamples[k]-mean)*(mixedSamples[k]-mean);
        variance[i][j] = vr/c;
      }
    vector<int> separators(k+1,0);
    for (int i=0;i<separators.size();i++)
      separators[i] = i;
    separators[separators.size()-1] = n;
    bool changed = true;
    double mn = 1e100;
    while (changed) {
      double varsum = 0;
      for (int i=0;i+1<separators.size();i++)
        varsum += variance[separators[i]][separators[i+1]];
      mn = min(mn,varsum);
      vector<int> lastseparators = separators;
      getnext(separators);
      changed = (lastseparators != separators);
    }
    return mn;
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
			/*case 6:
			{
				int mixedSamples[] = ;
				int k = ;
				_expected = ;
				_received = _obj.minDev(vector <int>(mixedSamples, mixedSamples+sizeof(mixedSamples)/sizeof(int)), k); break;
			}*/
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
