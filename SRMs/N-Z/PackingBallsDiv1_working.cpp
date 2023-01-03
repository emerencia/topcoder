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

class PackingBallsDiv1 {
 public:
  vector<int> X;
  int minPacks(int K, int A, int B, int C, int D) {
    X.clear();
    X.push_back(A);
    for (int i=1;i<K;i++)
      X.push_back(((LL)X[i-1] * B + C) % D + 1);
    int packages = 0;
    for (int i=0;i<X.size();i++)
      if (X[i] > K) {
        int amount = X[i]/K;
        packages += amount;
        X[i]%= K;
      }
    sort(X.begin(),X.end());
    // calculate v variety sets, each variety set will include
    // all balls that are not zero yet
    // the number of ball classes that are bigger than a variety set
    // will one one more normal set to cover the of their balls
    int extra = 1000000;
    int lasti = 0;
    for (int i=0;i<X.size();i++) {
      if (X[i] != 0) break;
      lasti = i;
    }
    for (int i=0;i<=K;i++) { // i is the number of variety packs
      int extrahere = i;
      int l = lasti, r = X.size()-1;
      while (l != r) {
        int m = (l+r)>>1;
        if (X[m] <= i) l = m+1;
        else r = m;
      }
      if (X[l] > i) extrahere += X.size() - l;
      lasti = l;
      extra = min(extra,extrahere);
    }
    return packages+extra;
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
		cout << "Testing PackingBallsDiv1 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1416608852;
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
		PackingBallsDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int K = 3;
				int A = 4;
				int B = 2;
				int C = 5;
				int D = 6;
				_expected = 4;
				_received = _obj.minPacks(K, A, B, C, D); break;
			}
			case 1:
			{
				int K = 1;
				int A = 58;
				int B = 23;
				int C = 39;
				int D = 93;
				_expected = 58;
				_received = _obj.minPacks(K, A, B, C, D); break;
			}
			case 2:
			{
				int K = 23;
				int A = 10988;
				int B = 5573;
				int C = 4384;
				int D = 100007;
				_expected = 47743;
				_received = _obj.minPacks(K, A, B, C, D); break;
			}
			case 3:
			{
				int K = 100000;
				int A = 123456789;
				int B = 234567890;
				int C = 345678901;
				int D = 1000000000;
				_expected = 331988732;
				_received = _obj.minPacks(K, A, B, C, D); break;
			}
			case 4:
			{
				int K = 100000;
				int A = 131;
				int B = 234567890;
				int C = 345678901;
				int D = 555;
				_expected = 447;
				_received = _obj.minPacks(K, A, B, C, D); break;
			}
			/*case 5:
			{
				int K = ;
				int A = ;
				int B = ;
				int C = ;
				int D = ;
				_expected = ;
				_received = _obj.minPacks(K, A, B, C, D); break;
			}*/
			/*case 6:
			{
				int K = ;
				int A = ;
				int B = ;
				int C = ;
				int D = ;
				_expected = ;
				_received = _obj.minPacks(K, A, B, C, D); break;
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
