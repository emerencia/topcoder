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
double EPS = 1e-9;

class RandomFights {
 public:
  int n;
  vector<int> getArray(vector<int>& X) {
    vector<int> R(n);
    int j = 0;
    int m = X.size();
    for (int i=0;i<n;i++) {
      R[i] = X[j];
      int s = (j+1)%m;
      X[j] = ((X[j]^X[s])+13)%49999;
      j = s;
    }
    return R;
  }
  double expectedNrOfPoints(vector <int> A, vector <int> B, int n) {
    this->n = n;
    vector<int> Ar = getArray(A);
    vector<int> Br = getArray(B);
    LL score = 0;
    sort(Ar.begin(),Ar.end());
    sort(Br.begin(),Br.end());
    int bi = 0;
    LL sumb = 0;
    LL sumbsq = 0;
    for (int i=0;i<Ar.size();i++) {
      while (bi < Br.size() && Ar[i] > Br[bi]) {
        sumbsq += (LL)Br[bi]*Br[bi];
        sumb += Br[bi++];
      }
      score += (LL)bi*Ar[i]*Ar[i] + sumbsq - 2LL*Ar[i]*sumb;
    }
    int ai = 0;
    LL suma = 0;
    LL sumasq = 0;
    for (int i=0;i<Br.size();i++) {
      while (ai < Ar.size() && Br[i] > Ar[ai]) {
        sumasq += (LL)Ar[ai]*Ar[ai];
        suma += Ar[ai++];
      }
      score -= (LL)ai*Br[i]*Br[i] + sumasq - 2LL*Br[i]*suma;
    }
    return double(score)/n;
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
		cout << "Testing RandomFights (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397049908;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 950.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RandomFights _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {6};
				int B[] = {4};
				int n = 1;
				_expected = 4.0;
				_received = _obj.expectedNrOfPoints(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), n); break;
			}
			case 1:
			{
				int A[] = {1,7};
				int B[] = {3,5};
				int n = 2;
				_expected = 0.0;
				_received = _obj.expectedNrOfPoints(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), n); break;
			}
			case 2:
			{
				int A[] = {3,7};
				int B[] = {1,5};
				int n = 2;
				_expected = 20.0;
				_received = _obj.expectedNrOfPoints(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), n); break;
			}
			case 3:
			{
				int A[] = {45,35,236,2342,5543,21,32,2,6,23,24,23,41,1};
				int B[] = {2345,45,2345,345};
				int n = 50;
				_expected = 1.2721986164E8;
				_received = _obj.expectedNrOfPoints(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), n); break;
			}
			case 4:
			{
				int A[] = {34,3245,2534,53,53,46,346,246,346,2,624,624,6,245,6324,6542,624,6};
				int B[] = {345,234,523,4624,6,2456,345,634,634,7,3457,376,34,6234,62,523,52,35,32};
				int n = 7;
				_expected = -9713701.714285715;
				_received = _obj.expectedNrOfPoints(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), n); break;
			}
			case 5:
			{
				int A[] = {1,2,3,4};
				int B[] = {1,2,3,4};
				int n = 50000;
				_expected = 0.0;
				_received = _obj.expectedNrOfPoints(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), n); break;
			}
			case 6:
			{
				int A[] = {25832, 32711, 1780, 29957, 23097, 4619, 46201, 5138, 5372, 37779, 39501, 3080, 32090, 41322, 11592, 46982, 34128, 6754, 5787, 19084, 24425, 215, 36529, 18645, 34704, 40115, 34250, 22098, 27000, 939, 22517, 47023, 26616, 16270, 48033, 3231, 34296, 5213, 24447, 3151, 44386, 44157, 30260, 10410, 41961, 29234};
				int B[] = {18671, 23054, 39089, 45596, 27664, 47508, 46482, 22208, 37526, 48442, 27290, 19555, 40412, 42744, 41555, 31044, 27437, 30755, 21304, 20311, 21710, 11167, 19806, 44430, 41904, 37160, 40058, 17637, 27404, 42854, 23060, 46274, 38358, 38872, 45933, 25363, 26841, 41610, 33415, 5075};
				int n = 43406;
				_expected = 1.2778477372164968E12;
				_received = _obj.expectedNrOfPoints(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), n); break;
			}
			/*case 7:
			{
				int A[] = ;
				int B[] = ;
				int n = ;
				_expected = ;
				_received = _obj.expectedNrOfPoints(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), n); break;
			}*/
			/*case 8:
			{
				int A[] = ;
				int B[] = ;
				int n = ;
				_expected = ;
				_received = _obj.expectedNrOfPoints(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), n); break;
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
