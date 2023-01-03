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

class BinSearchFirstMatch {
 public:
  int find(vector <int> X, int elem) {
    // X is sorted in ascending order
    // return index of first occurrence or -1 if elem not found
    int l = 0, r = X.size()-1;
    while (l != r) {
      int m = (l+r) >> 1;
      if (X[m] >= elem) r = m;
      else l = m+1;
    }
    if (X[l] != elem) return -1;
    return l;
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
		cout << "Testing BinSearchFirstMatch (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1411058347;
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
		BinSearchFirstMatch _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int X[] = {0,1,2,3,3,3,4,6,6,9,9,9,10};
        int elem = 4;
				_expected = 6;
				_received = _obj.find(vector <int>(X, X+sizeof(X)/sizeof(int)), elem); break;
			}
			case 1:
			{
        int X[] = {0,0,1,2,3,3,3,4,6,6,9,9,9,10};
        int elem = 5;
				_expected = -1;
				_received = _obj.find(vector <int>(X, X+sizeof(X)/sizeof(int)), elem); break;
			}
			case 2:
			{
        int X[] = {0,1,2,3,3,3,4,6,6,9,9,9,10};
        int elem = -1;
				_expected = -1;
				_received = _obj.find(vector <int>(X, X+sizeof(X)/sizeof(int)), elem); break;
			}
			case 3:
			{
        int X[] = {0,1,2,3,3,3,4,6,6,9,9,9,10};
        int elem = 12;
				_expected = -1;
				_received = _obj.find(vector <int>(X, X+sizeof(X)/sizeof(int)), elem); break;
			}
			case 4:
			{
        int X[] = {0,1,2,3,3,3,4,6,6,9,9,9,10};
        int elem = 0;
				_expected = 0;
				_received = _obj.find(vector <int>(X, X+sizeof(X)/sizeof(int)), elem); break;
			}
			case 5:
			{
        int X[] = {0,0,1,2,3,3,3,4,6,6,9,9,9,10};
        int elem = 0;
				_expected = 0;
				_received = _obj.find(vector <int>(X, X+sizeof(X)/sizeof(int)), elem); break;
			}
			case 6:
			{
        int X[] = {0,1,2,3,3,3,4,6,6,9,9,9,10};
        int elem = 10;
				_expected = 12;
				_received = _obj.find(vector <int>(X, X+sizeof(X)/sizeof(int)), elem); break;
			}
      case 7:
      {
        int X[] = {0,1,2,3,3,3,4,6,6,9,9,9,10,10,10};
        int elem = 3;
        _expected = 3;
        _received = _obj.find(vector <int>(X, X+sizeof(X)/sizeof(int)), elem); break;
      }
      case 8:
      {
        int X[] = {0,1,2,3,3,3,4,6,6,9,9,9,10};
        int elem = 9;
        _expected = 9;
        _received = _obj.find(vector <int>(X, X+sizeof(X)/sizeof(int)), elem); break;
      }
      case 9:
      {
        int X[] = {0,1,2,3,3,3,4,6,6,9,9,9,10};
        int elem = 6;
        _expected = 7;
        _received = _obj.find(vector <int>(X, X+sizeof(X)/sizeof(int)), elem); break;
      }
      case 10:
      {
        int X[] = {0,1,2,3,3,3,4,6,6,9,9,9,10};
        int elem = 1;
        _expected = 1;
        _received = _obj.find(vector <int>(X, X+sizeof(X)/sizeof(int)), elem); break;
      }
      case 11:
      {
        int X[] = {0,0,1,2,3,3,3,4,6,6,9,9,9,10};
        int elem = -2;
        _expected = -1;
        _received = _obj.find(vector <int>(X, X+sizeof(X)/sizeof(int)), elem); break;
      }
      case 12:
      {
        int X[] = {0,1,2,3,3,3,4,6,6,9,9,9,10};
        int elem = 7;
        _expected = -1;
        _received = _obj.find(vector <int>(X, X+sizeof(X)/sizeof(int)), elem); break;
      }
      case 13:
      {
        int X[] = {0,1,2,3,3,3,4,6,6,9,9,9,10};
        int elem = 8;
        _expected = -1;
        _received = _obj.find(vector <int>(X, X+sizeof(X)/sizeof(int)), elem); break;
      }
      case 14:
      {
        int X[] = {0,1,2,3,3,3,4,6,6,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
        int elem = 10;
        _expected = 12;
        _received = _obj.find(vector <int>(X, X+sizeof(X)/sizeof(int)), elem); break;
      }
      case 15:
      {
        int X[] = {0,1,2,3,3,3,4,6,6,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
        int elem = 0;
        _expected = 0;
        _received = _obj.find(vector <int>(X, X+sizeof(X)/sizeof(int)), elem); break;
      }
      case 16:
      {
        int X[] = {0, 1, 1, 1, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 5, 6, 6, 6, 6, 7, 7, 7, 8, 8, 9, 9, 9, 9, 9, 10, 11, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13, 14, 14, 14, 14, 14, 15, 15};
        int elem = 14;
        _expected = 43;
        _received = _obj.find(vector <int>(X, X+sizeof(X)/sizeof(int)), elem); break;
      }
      case 17:
      {
        int X[] = {0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 4, 4, 5, 5, 5, 6, 6, 6, 6, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 10, 11, 11, 11, 12, 13, 13, 13, 13, 13, 14, 14, 14, 15, 15, 15};
        int elem = 2;
        _expected = 6;
        _received = _obj.find(vector <int>(X, X+sizeof(X)/sizeof(int)), elem); break;
      }
      case 18:
      {
        int X[] = {0, 0, 0, 0, 1, 1, 1, 1, 2, 3, 3, 3, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 7, 7, 7, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 10, 11, 11, 11, 12, 12, 12, 13, 13, 13, 13, 14, 15};
        int elem = 5;
        _expected = 14;
        _received = _obj.find(vector <int>(X, X+sizeof(X)/sizeof(int)), elem); break;
      }
      case 19:
      {
        int X[] = {0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 4, 4, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 9, 9, 9, 10, 11, 11, 11, 11, 11, 12, 12, 13, 13, 13, 13, 13, 15, 15, 15, 15, 15, 15};
        int elem = 4;
        _expected = 15;
        _received = _obj.find(vector <int>(X, X+sizeof(X)/sizeof(int)), elem); break;
      }
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
