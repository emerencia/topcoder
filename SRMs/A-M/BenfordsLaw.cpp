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

class BenfordsLaw {
 public:
  int questionableDigit(vector <int> transactions, int threshold) {
    for (int i=1;i<10;i++) {
      int cnt = 0;
      int found = 0;
      for (int j=0;j<transactions.size();j++) {
        int n = transactions[j];
        while (n/10) {
          n/=10;
        }
        if (n == i) found++;
        cnt++;
      }
      double foundp = double(found)/cnt;
      double exp = log10(1+1.0/i);
      if (foundp < 1.0/threshold*exp || foundp > threshold*exp)
        return i;
    }
    return -1;
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
		cout << "Testing BenfordsLaw (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397833644;
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
		BenfordsLaw _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int transactions[] = { 5236,7290,200,1907,3336,9182,17,4209,8746,7932,
				                       6375,909,2189,3977,2389,2500,1239,3448,6380,4812 };
				int threshold = 2;
				_expected = 1;
				_received = _obj.questionableDigit(vector <int>(transactions, transactions+sizeof(transactions)/sizeof(int)), threshold); break;
			}
			case 1:
			{
				int transactions[] = { 1,10,100,2,20,200,2000,3,30,300 };
				int threshold = 2;
				_expected = 2;
				_received = _obj.questionableDigit(vector <int>(transactions, transactions+sizeof(transactions)/sizeof(int)), threshold); break;
			}
			case 2:
			{
				int transactions[] = { 9,87,765,6543,54321,43219,321987,21987,1987,345,234,123 };
				int threshold = 2;
				_expected = -1;
				_received = _obj.questionableDigit(vector <int>(transactions, transactions+sizeof(transactions)/sizeof(int)), threshold); break;
			}
			case 3:
			{
				int transactions[] = { 1,2,3,4,5,6,7,8,7,6,5,4,3,2,1 };
				int threshold = 8;
				_expected = 9;
				_received = _obj.questionableDigit(vector <int>(transactions, transactions+sizeof(transactions)/sizeof(int)), threshold); break;
			}
			case 4:
			{
				int transactions[] = { 987,234,1234,234873487,876,234562,17,
				                       7575734,5555,4210,678234,3999,8123 };
				int threshold = 3;
				_expected = 8;
				_received = _obj.questionableDigit(vector <int>(transactions, transactions+sizeof(transactions)/sizeof(int)), threshold); break;
			}
			/*case 5:
			{
				int transactions[] = ;
				int threshold = ;
				_expected = ;
				_received = _obj.questionableDigit(vector <int>(transactions, transactions+sizeof(transactions)/sizeof(int)), threshold); break;
			}*/
			/*case 6:
			{
				int transactions[] = ;
				int threshold = ;
				_expected = ;
				_received = _obj.questionableDigit(vector <int>(transactions, transactions+sizeof(transactions)/sizeof(int)), threshold); break;
			}*/
			/*case 7:
			{
				int transactions[] = ;
				int threshold = ;
				_expected = ;
				_received = _obj.questionableDigit(vector <int>(transactions, transactions+sizeof(transactions)/sizeof(int)), threshold); break;
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
