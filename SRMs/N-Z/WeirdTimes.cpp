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
// start: 21:40
// done: 22:22
// done debugging: 22:41
// END CUT HERE
LL mem[25][51];

class WeirdTimes {
 public:
  vector<int> minuteValues;
  LL rec(int minhour, int idx) {
    LL& r = mem[minhour][idx];
    if (r != -1) return r;
    if (idx == minuteValues.size())
      return r = 1;
    LL t = 0;
    if (minhour > 23) return r = 0;
    for (int hour=minhour;hour<24;hour++) {
      int nextminhour = hour;
      if (idx+1 != minuteValues.size() && minuteValues[idx] >= minuteValues[idx+1])
        nextminhour++;
      t += rec(nextminhour,idx+1);
    }
    return r = t;
  }
  vector <int> hourValues(vector <int> minuteValues, int k) {
    this->minuteValues = minuteValues;
    memset(mem,-1,sizeof(mem));
    LL K = k-1;
    cout << rec(0,0) << endl;
    int minhour = 0;
    vector<int> r(minuteValues.size());
    for (int i=0;i<minuteValues.size();i++) {
      LL option = 0;
      for (int hour = minhour;hour<24;hour++) {
        int ghour = hour;
        if (i+1 != minuteValues.size() && minuteValues[i] >= minuteValues[i+1])
          ++ghour;
        LL added = rec(ghour,i+1);
        if (added == 0) return vector<int>(1,-1);
        if (option+added > K) {
          r[i] = hour;
          minhour = hour;
          K-=option;
          break;
        }
        option += added;
      }
      if (i+1 != minuteValues.size() && minuteValues[i] >= minuteValues[i+1])
        minhour++;
    }
    if (K != 0) return vector<int>(1,-1);
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
	string a = tt == -1 ? "0" : string(1,'0'+tt);
	char* b[2] = {argv[0],(char*)a.c_str()};
	if(tt!=-1){argc=2;argv=b;}
	if (argc == 1) 
	{
		cout << "Testing WeirdTimes (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1406662806;
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
		WeirdTimes _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int minuteValues[] = {22, 11, 33};
				int K = 3;
				int __expected[] = {0, 1, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.hourValues(vector <int>(minuteValues, minuteValues+sizeof(minuteValues)/sizeof(int)), K); break;
			}
			case 1:
			{
				int minuteValues[] = {10};
				int K = 2;
				int __expected[] = {1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.hourValues(vector <int>(minuteValues, minuteValues+sizeof(minuteValues)/sizeof(int)), K); break;
			}
			case 2:
			{
				int minuteValues[] = {2, 1};
				int K = 20;
				int __expected[] = {0, 20 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.hourValues(vector <int>(minuteValues, minuteValues+sizeof(minuteValues)/sizeof(int)), K); break;
			}
			case 3:
			{
				int minuteValues[] = {1, 2};
				int K = 20;
				int __expected[] = {0, 19 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.hourValues(vector <int>(minuteValues, minuteValues+sizeof(minuteValues)/sizeof(int)), K); break;
			}
			case 4:
			{
				int minuteValues[] = {25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 15, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
				int K = 1;
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.hourValues(vector <int>(minuteValues, minuteValues+sizeof(minuteValues)/sizeof(int)), K); break;
			}
			case 5:
			{
				int minuteValues[] = {45, 12, 0, 3, 2, 7, 4, 9, 23, 6, 17, 33};
				int K = 12345;
				int __expected[] = {0, 1, 2, 2, 3, 3, 4, 5, 12, 13, 18, 18 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.hourValues(vector <int>(minuteValues, minuteValues+sizeof(minuteValues)/sizeof(int)), K); break;
			}
			case 6:
			{
				int minuteValues[] = {43, 58};
				int K = 318;
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.hourValues(vector <int>(minuteValues, minuteValues+sizeof(minuteValues)/sizeof(int)), K); break;
			}
			case 7:
			{
				int minuteValues[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49};
				int K = 50;
				int __expected[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.hourValues(vector <int>(minuteValues, minuteValues+sizeof(minuteValues)/sizeof(int)), K); break;
			}
			/*case 8:
			{
				int minuteValues[] = ;
				int K = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.hourValues(vector <int>(minuteValues, minuteValues+sizeof(minuteValues)/sizeof(int)), K); break;
			}*/
			/*case 9:
			{
				int minuteValues[] = ;
				int K = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.hourValues(vector <int>(minuteValues, minuteValues+sizeof(minuteValues)/sizeof(int)), K); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
