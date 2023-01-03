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
LL mem[1<<15][101];

class WickedTeacher {
 public:
  vector<int> modnumbers;
  vector<string> numbers;
  vector<int> bases;
  int K;
  LL gcd(LL a, LL b) {
    if (b == 0) return a;
    return gcd(b,a%b);
  }
  LL rec(int state, int mod) {
    LL& r = mem[state][mod];
    if (r != -1) return r;
    if (state == (1<<modnumbers.size())-1) return r = (mod ? 0 : 1);
    LL t = 0;
    for (int i=0;i<modnumbers.size();i++) {
      if (state&(1<<i)) continue;
      t+=rec(state|(1<<i),(mod*bases[numbers[i].size()]+modnumbers[i])%K);
    }
    return r = t;
  }
  long long factorial(long long x) {
    long long c = 1;
    for (long long i=1;i<=x;i++)
      c = (c*i);
    return c;
  }
  string cheatProbability(vector <string> numbers, int K) {
    this->K = K;
    this->numbers = numbers;
    int maxlen = 0;
    for (int i=0;i<numbers.size();i++)
      maxlen = max(maxlen,(int)numbers[i].size());
    bases = vector<int>(maxlen+1,0);
    int base = 1;
    for (int i=0;i<=maxlen;i++) {
      bases[i] = base;
      (base*=10)%=K;
    }
    modnumbers.clear();
    for (int i=0;i<numbers.size();i++) {
      int num = 0;
      int base = 1;
      for (int j=numbers[i].size()-1;j>=0;j--) {
        (num +=base*(numbers[i][j]-'0'))%=K;
        (base*=10)%=K;
      }
      modnumbers.push_back(num);
    }
    memset(mem,-1,sizeof(mem));
    LL numerator = rec(0,0);
    if (!numerator) return "0/1";
    LL denominator = factorial(numbers.size());
    LL g = gcd(numerator,denominator);
    stringstream a;
    a << numerator/g << "/" << denominator/g;
    return a.str();
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
	if(tt!=-1){char* b[2];b[1]=(char*)string(1,'0'+tt).c_str();b[0]=argv[0];argc=2;argv=b;}	if (argc == 1) 
	{
		cout << "Testing WickedTeacher (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395245444;
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
		WickedTeacher _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string numbers[] = {"3","2","1"};
				int K = 2;
				_expected = "1/3";
				_received = _obj.cheatProbability(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), K); break;
			}
			case 1:
			{
				string numbers[] = {"10","100","1000","10000","100000"};
				int K = 10;
				_expected = "1/1";
				_received = _obj.cheatProbability(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), K); break;
			}
			case 2:
			{
				string numbers[] = {"11","101","1001","10001","100001"};
				int K = 10;
				_expected = "0/1";
				_received = _obj.cheatProbability(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), K); break;
			}
			case 3:
			{
				string numbers[] = {"13","10129414190271203","102","102666818896","1216","1217","1218","101278001","1000021412678412681"};
				int K = 21;
				_expected = "5183/36288";
				_received = _obj.cheatProbability(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), K); break;
			}
			case 4:
			{
				string numbers[] = {"181174833", "9818015", "22078586658314", "34992439", "49822", "8254715466", "1434642685", "4910101", "2472512804", "25", "2231146327", "91604", "484", "54274182", "95189465"};
				int K = 91;
				_expected = "898596781/81729648000";
				_received = _obj.cheatProbability(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), K); break;
			}
			/*case 5:
			{
				string numbers[] = ;
				int K = ;
				_expected = ;
				_received = _obj.cheatProbability(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), K); break;
			}*/
			/*case 6:
			{
				string numbers[] = ;
				int K = ;
				_expected = ;
				_received = _obj.cheatProbability(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), K); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
